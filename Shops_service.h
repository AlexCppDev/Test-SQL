#pragma once
#include "SQL_controller.h"
class Shops_service
{
private:
	SQL_Controller *sql_controller;
	bool fill_item_list_from_database(list<Shop>* inputShops);
public:
	list <Shop> get_opened();
	void set_sql_contorller(SQL_Controller* sql_controller);
};

