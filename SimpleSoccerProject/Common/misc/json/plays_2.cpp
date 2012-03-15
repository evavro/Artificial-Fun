#include "Jzon.h"
#include <iostream>

void parseNode(Jzon::Node & rootNode);
void parseObject(Jzon::Object & rootNode);
void parseArray(Jzon::Object & nodeArray, const std::string & nodeName);

int main()
{
        Jzon::Object rootNode;
        Jzon::FileReader::ReadFile("plays.json", rootNode);

		//parseNode(rootNode);
		
        /* for (Jzon::Object::iterator it = rootNode.begin(); it != rootNode.end(); ++it)
        {
                std::string name = (*it).first;
                Jzon::Node &node = (*it).second;
                        
                std::cout << name << " = ";
                if (node.IsValue()) {
                        std::cout << node.AsString();
                } else if (node.IsArray()) {
                        std::cout << "*Array*";
                } else if (node.IsObject()) {
                        std::cout << "*Object*";
				}
					
                std::cout << std::endl;
        }*/

		
		// handle plays
        if(rootNode.Get("plays").IsArray())
        {
			Jzon::Array &plays = rootNode.Get("plays").AsArray();

			// parse individual plays
			for(Jzon::Array::iterator it = plays.begin(); it != plays.end(); ++it)
			{
				Jzon::Object states = (*it).AsObject();
				
				// parse states
				for(Jzon::Object::iterator it = states.begin(); it != states.end(); ++it)
				{
					std::string name = (*it).first;
					Jzon::Node &node = (*it).second;
					
					std::cout << name << " = ";
                
					// CHECK FOR THE NAME OF THE NODE THAT WE'RE CURRENTLY LOOKING AT AND HANDLE THEM ACCORDINGLY
							
					// handle continues
					if (node.IsValue())
					{
						std::cout << node.AsString();
						
					// handle states
					} else if (node.IsArray()) {
						//parseNode(node);
						
						std::cout << "*Array!!!*";
						
						Jzon::Array &states = node.AsArray();
						
						// parse individual states -> parseState(Jzon::Array & nodes, Play & play)
						for(Jzon::Array::iterator it = states.begin(); it != states.end(); ++it)
						{
							// look for:
							// positions
							// trans
							
							//Jzon::Node & stateNode = (*it);
							
							std::cout << std::endl << "State..." << std::endl;
							
							// if "positions" -> parsePositionsAndTransitions(Jzon::Array & nodes, PlayState & playState)
							parseNode((*it));
						}
						
					// CORRUPTED FORMAT!
					} else if (node.IsObject()) {
						std::cout << "*Object!!!*";
					}
					
					std::cout << std::endl;
				}
			}
			
			//parseArray(rootNode, "plays"); // Works!
        } else {
			std::cout << "The beginning node must be a list of plays" << std::endl;
		}

        return 0;
}

void parseNode(Jzon::Node & rn)
{
	Jzon::Object rootNode = rn.AsObject();

	for(Jzon::Object::iterator it = rootNode.begin(); it != rootNode.end(); ++it)
    {
		std::string name = (*it).first;
		Jzon::Node &node = (*it).second;
                        
		std::cout << name << " = ";
                
		// CHECK FOR THE NAME OF THE NODE THAT WE'RE CURRENTLY LOOKING AT AND HANDLE THEM ACCORDINGLY
                
        if (node.IsValue()) {
			std::cout << node.AsString();
		} else if (node.IsArray()) {
			std::cout << "*Array*";
		} else if (node.IsObject()) {
			std::cout << "*Object*";
		}
					
		std::cout << std::endl;
	}
}

void parseObject(Jzon::Object & rootNode)
{
	for(Jzon::Object::iterator it = rootNode.begin(); it != rootNode.end(); ++it)
	{
		std::string name = (*it).first;
		Jzon::Node &node = (*it).second;
                        
		std::cout << name << " = ";

		if (node.IsValue()) {
			std::cout << node.AsString();
		} else if (node.IsArray()) {
			std::cout << "*Array*";

        } else if (node.IsObject()) {
            std::cout << "*Object*";

		}
					
		std::cout << std::endl;
	}
}

// Perform special operations 
void parseArray(Jzon::Object & rootNode, const std::string & nodeName)
{
	//Jzon::Array &nodeArray = rootNode.AsArray();
	
	if(rootNode.Get(nodeName).IsArray())
    {
		Jzon::Array &nodeArray = rootNode.Get(nodeName).AsArray();

		for (Jzon::Array::iterator it = nodeArray.begin(); it != nodeArray.end(); ++it)
		{
			//std::cout << (*it).AsString() << std::endl;

			if ((*it).IsValue()) {
				std::cout << "value" << std::endl;
			}

			if ((*it).IsObject()) {
				std::cout << "obj" << std::endl;
			}

			if ((*it).IsArray()) {
				std::cout << "arr" << std::endl;
			}
		}
	} else {
		std::cout << "Error, expected " << nodeName << std::endl;
	}
}
