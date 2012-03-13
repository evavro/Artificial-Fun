#include "Jzon.h"
#include <iostream>

int main() {
	Jzon::Object rootNode;
	Jzon::FileReader::ReadFile("../../plays_format_description.json", rootNode);

	if(rootNode.Get("plays").IsArray())
	{
		Jzon::Array &root = rootNode.Get("plays").AsArray();

		for(Jzon::Array::iterator it = root.begin(); it != root.end(); ++it)
		{
			std::string &name = (*it).first;
			Jzon::Node &node = (*it).second;

			std::cout << name << " = ";

			if(node.IsValue())
				std::cout << node.AsString();
			else if (node.IsArray())
				std::cout << "*Array* " << node.AsString();
			else if (node.IsObject())
				std::cout << "*Object* " << node.AsString();
				std::cout << std::endl;
		}
	}    

    return 0;
}
