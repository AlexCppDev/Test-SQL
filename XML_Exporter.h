#pragma once
#include <fstream>
#include "Constant_tags.h"
#include "Shop.h"
#include "Tags_deleting.h"


class XML_Exporter
{
	char buf[1000];
public:
	void Export_to_file(list <Shop>,  char* File_Path_XML);
	~XML_Exporter();
};

