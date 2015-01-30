// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMON_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMMON_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMMON_EXPORTS
#define COMMON_API __declspec(dllexport)
#else
#define COMMON_API __declspec(dllimport)
#endif



#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "AutoCutterException.h"
//#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"

class COMMON_API ConfigurationManager
{
public:

	std::string getValue(const char* pKey);
	std::string getValue(std::string& pKey);
	static ConfigurationManager* instance();

	static void create();
private:
	ConfigurationManager(void);
	ConfigurationManager(ConfigurationManager const&);
	ConfigurationManager& operator=(ConfigurationManager const&);


	static const std::string CONFIG_FILE;
	static ConfigurationManager* _configManager;

	std::string _content;
	rapidxml::xml_document<> _doc;
	rapidxml::xml_node<>* _rootNode;


};

