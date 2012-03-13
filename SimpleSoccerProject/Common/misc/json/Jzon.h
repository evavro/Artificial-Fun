/*
Copyright (c) 2011 Johannes H�ggqvist

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef Jzon_h__
#define Jzon_h__

#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <exception>

namespace Jzon
{
	class Node;
	class Value;
	class Object;
	class Array;
	typedef std::pair<std::string, Node&> NamedNode;
	typedef std::pair<std::string, Node*> NamedNodePtr;
	
	class TypeException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "A Node was used as the wrong type";
		}
	};
	class ValueException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "A Value was used as the wrong type";
		}
	};

	struct Format
	{
		bool newline;
		bool spacing;
		bool useTabs;
		unsigned int indentSize;
	};
	static const Format StandardFormat = { true, true, true, 0 };
	static const Format NoFormat = { false, false, false, 0 };

	class Node
	{
		friend class Object;
		friend class Array;

	public:
		enum Type
		{
			T_OBJECT,
			T_ARRAY,
			T_VALUE
		};

		Node();
		virtual ~Node();

		virtual Type GetType() const = 0;

		inline bool IsObject() const { return (GetType() == T_OBJECT); }
		inline bool IsArray() const { return (GetType() == T_ARRAY); }
		inline bool IsValue() const { return (GetType() == T_VALUE); }

		Object &AsObject();
		const Object &AsObject() const;
		Array &AsArray();
		const Array &AsArray() const;
		Value &AsValue();
		const Value &AsValue() const;

		virtual inline bool IsNull() const { return false; }
		virtual inline bool IsString() const { return false; }
		virtual inline bool IsInt() const { return false; }
		virtual inline bool IsDouble() const { return false; }
		virtual inline bool IsBool() const { return false; }

		virtual std::string AsString() const { throw TypeException(); }
		virtual int AsInt() const { throw TypeException(); }
		virtual double AsDouble() const { throw TypeException(); }
		virtual bool AsBool() const { throw TypeException(); }

		virtual unsigned int GetCount() const { return 0; }
		virtual Node &Get(const std::string &name) const { throw TypeException(); }
		virtual Node &Get(const std::string &name, Node &def) const { throw TypeException(); }
		virtual Node &Get(unsigned int index) const { throw TypeException(); }
		virtual Node &Get(unsigned int index, Node &def) const { throw TypeException(); }

		virtual std::string Write(const Format &format = NoFormat, unsigned int level = 0) const = 0;
		virtual void Read(const std::string &json) = 0;

		static Type DetermineType(const std::string &json);

	protected:
		virtual Node *GetCopy() const = 0;
	};

	class Value : public Node
	{
	public:
		enum ValueType
		{
			VT_NULL,
			VT_STRING,
			VT_INT,
			VT_DOUBLE,
			VT_BOOL
		};

		Value();
		Value(const Value &rhs);
		Value(const Node &rhs);
		Value(const std::string &value);
		Value(const char *value);
		Value(const int value);
		Value(const double value);
		Value(const bool value);
		virtual ~Value();

		virtual Type GetType() const;
		ValueType GetValueType() const;

		virtual inline bool IsNull() const { return (type == VT_NULL); }
		virtual inline bool IsString() const { return (type == VT_STRING); }
		virtual inline bool IsInt() const { return (type == VT_INT); }
		virtual inline bool IsDouble() const { return (type == VT_DOUBLE); }
		virtual inline bool IsBool() const { return (type == VT_BOOL); }

		virtual std::string AsString() const;
		virtual int AsInt() const;
		virtual double AsDouble() const;
		virtual bool AsBool() const;

		void SetNull();
		void Set(const Value &value);
		void Set(const std::string &value);
		void Set(const char *value);
		void Set(const int value);
		void Set(const double value);
		void Set(const bool value);

		Value &operator=(const Value &rhs);
		Value &operator=(const Node &rhs);
		Value &operator=(const std::string &rhs);
		Value &operator=(const char *rhs);
		Value &operator=(const int rhs);
		Value &operator=(const double rhs);
		Value &operator=(const bool rhs);

		bool operator==(const Value &other) const;
		bool operator!=(const Value &other) const;

		virtual std::string Write(const Format &format = NoFormat, unsigned int level = 0) const;
		virtual void Read(const std::string &json);

	protected:
		virtual Node *GetCopy() const;

	private:
		std::string EscapeString() const;
		std::string UnescapeString(const std::string &value) const;

		std::string valueStr;
		ValueType type;
	};

	static const Value null;

	class Object : public Node
	{
	public:
		class iterator : public std::iterator<std::input_iterator_tag, NamedNode>
		{
		public:
			iterator(NamedNodePtr *o) : p(o) {}
			iterator(const iterator &it) : p(it.p) {}

			iterator &operator++() { ++p; return *this; }
			iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }

			bool operator==(const iterator &rhs) { return p == rhs.p; }
			bool operator!=(const iterator &rhs) { return p != rhs.p; }

			NamedNode operator*() { return NamedNode(p->first, *p->second); }

		private:
			NamedNodePtr *p;
		};

		Object();
		Object(const Object &other);
		Object(const Node &other);
		virtual ~Object();

		virtual Type GetType() const;

		void Add(const std::string &name, Node &node);
		void Add(const std::string &name, Value node);
		void Remove(const std::string &name);
		void Clear();

		iterator begin();
		iterator end();

		virtual unsigned int GetCount() const;
		virtual Node &Get(const std::string &name) const;
		virtual Node &Get(const std::string &name, Node &def) const;

		virtual std::string Write(const Format &format = NoFormat, unsigned int level = 0) const;
		virtual void Read(const std::string &json);

	protected:
		virtual Node *GetCopy() const;

	private:
		typedef std::vector<NamedNodePtr> ChildList;
		ChildList children;
	};

	class Array : public Node
	{
	public:
		class iterator : public std::iterator<std::input_iterator_tag, Node>
		{
		public:
			iterator(Node **o) : p(o) {}
			iterator(const iterator &it) : p(it.p) {}

			iterator &operator++() { ++p; return *this; }
			iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }

			bool operator==(const iterator &rhs) { return p == rhs.p; }
			bool operator!=(const iterator &rhs) { return p != rhs.p; }

			Node &operator*() { return **p; }

		private:
			Node **p;
		};

		Array();
		Array(const Array &other);
		Array(const Node &other);
		virtual ~Array();

		virtual Type GetType() const;

		void Add(Node &node);
		void Add(Value node);
		void Remove(unsigned int index);
		void Clear();

		iterator begin();
		iterator end();

		virtual unsigned int GetCount() const;
		virtual Node &Get(unsigned int index) const;
		virtual Node &Get(unsigned int index, Node &def) const;

		virtual std::string Write(const Format &format = NoFormat, unsigned int level = 0) const;
		virtual void Read(const std::string &json);

	protected:
		virtual Node *GetCopy() const;

	private:
		typedef std::vector<Node*> ChildList;
		ChildList children;
	};

	class FileWriter
	{
	public:
		FileWriter();
		~FileWriter();

		static void WriteFile(const std::string &filename, Node &root, const Format &format = NoFormat);

		void Write(const std::string &filename, Node &root, const Format &format = NoFormat);
	};

	class FileReader
	{
	public:
		FileReader(const std::string &filename);
		~FileReader();

		static void ReadFile(const std::string &filename, Node &node);

		void Read(Node &node);

		Node::Type DetermineType();

	private:
		std::string json;
	};
}

#endif // Jzon_h__