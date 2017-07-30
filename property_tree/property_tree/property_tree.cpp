// property_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <exception>

//#include <boost\throw_exception.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\ini_parser.hpp>

namespace pt = boost::property_tree;

int main()
{
	pt::ptree tree;

	try {
		pt::read_ini("main.ini", tree);
	}
	catch (std::exception e) {
		std::cout << "File Not Found!" << std::endl;
		int pause;
		std::cin >> pause;

		return 0;
	}

	std::string host = tree.get<std::string>("database.host");

	int port = tree.get("database.port", 1234);

	std::cout << "Host " << host << " - Port " << port << std::endl;

	int pause;
	std::cin >> pause;

    return 0;
}

