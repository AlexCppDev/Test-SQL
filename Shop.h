#pragma once
#include <list>
#include <iostream>
#include "Item.h"

using std::list;


class Shop
{
private:
	char* id;
	char* name;
	char* url;
	char* working_time_open;
	char* working_time_close;
	list <Item> items;
public:

	Shop(char* id, char* name, char* url, char* working_time_open, char* working_time_close);
	~Shop();

	char* get_id();
	char* get_name();
	char* get_url();
	char* get_working_time_open();	
	char* get_working_time_close();
	list<Item> get_items();
	void add_item(Item item);

	list<Item>* get_items_ptr();
};

