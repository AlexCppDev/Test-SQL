#pragma once
class Item
{
private:
	char* id;
	char* name_of_item;
	char* description;
	char* price;
	char* shop_id;
public:
	char* get_id();
	char* get_price();
	char* get_name_of_item();
	char* get_description();

	~Item();

	Item(char* id,
		char* name_of_item,
		char* description,
		char* price,
		char* shop_id);
	
};

