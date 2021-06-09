#include "Shops_service.h"
bool Shops_service::fill_item_list_from_database(list<Shop>* inputShops)
{ 
	map <int, Shop*> shops_map;
	string shopIds;
	int counter = 0;

	for (Shop& shop : *inputShops) {
		shops_map.insert(make_pair(atoi(shop.get_id()), &shop));
		if (counter != 0)
			shopIds = shopIds + ',' + shop.get_id();
		else {
			shopIds = shop.get_id();
		}
		counter++;
	}

	list<MYSQL_ROW> items_res = sql_controller->get_item_list_by_shop_ids(shopIds);
	for (MYSQL_ROW item_row : items_res) {
		char* id = item_row[0];
		char* shop_id = item_row[1];
		char* name = item_row[2];
		char* description = item_row[3];
		char* price = item_row[4];
		Item* item = new Item(id, shop_id, name, description, price);
		Shop* shop = shops_map[atoi(shop_id)];
		shop->get_items_ptr()->push_back(*item);
	}

	return true;
}
// Return opened now shops with items from data base
list <Shop> Shops_service::get_opened()
{	
	list<Shop> shops = sql_controller->get_Shop_List();

	fill_item_list_from_database(&shops);
	return shops;
}
void Shops_service::set_sql_contorller(SQL_Controller* sql_controller)
{
	this->sql_controller = sql_controller;
}