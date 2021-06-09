#include "Shop.h"

Shop::Shop(char* id, char* name, char* url, char* working_time_open, char* working_time_close)
{
	this->id = id;
	this->name = name;
	this->url = url;
	this->working_time_open = working_time_open;
	this->working_time_close = working_time_close;
	list<Item>* items = new list<Item>();
	this->items = *items;
}
Shop::~Shop() {}

char* Shop::get_id()
{
	return id;
}

char* Shop::get_name()
{
	return name;
}

char* Shop::get_url()
{
	return url;
}

char* Shop::get_working_time_open()
{
	return working_time_open;
}

 char* Shop::get_working_time_close()
 {
	 return working_time_open;
 }

list <Item> Shop::get_items()
{
	return items;
}

void Shop::add_item(Item item)
{
	this->items.push_back(item);
}

list <Item>* Shop::get_items_ptr()
{
	return &items;
}