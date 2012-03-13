#include "PlayGenerator.h"
#include "misc/json/Jzon.h"
#include <iostream>

PlayGenerator::PlayGenerator(void)
{
	// Load in a file and parse it using cajun (with a string)

	Jzon::Object rootNode;
	Jzon::FileReader::ReadFile("../plays_format_description.json", rootNode);

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
				std::cout << "*Array*";
			else if (node.IsObject())
				std::cout << "*Object*";
				std::cout << std::endl;
		}
	}
}

PlayGenerator::~PlayGenerator(void)
{

}
