#include "Item.h"

Item::Item(
	char* id,
	char* shop_id,
	char* name_of_item,
	char* description,
	char* price)
	
{
	this->id = id;
	this->name_of_item = name_of_item;
	this->description = description; 
	this->shop_id = shop_id;
	this->price = price;

}
Item::~Item() {}

char* Item::get_id()
{
	return id;
}

char* Item::get_price()
{
	return price;
}

char* Item::get_name_of_item()
{
	return  name_of_item;
}

char* Item::get_description()
{
	return description; 
}


