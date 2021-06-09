#pragma once
#include <mysql.h>
#include <map>
#include "Shop.h" 
#include <string>
using namespace std;

class SQL_Controller
{
private:
	MYSQL *conn;
	MYSQL *itemconn;
	MYSQL_RES *res;
	MYSQL_ROW row;
public:

	~SQL_Controller();

	bool Connection_to_DB();
	void Close_connection_to_DB();
	list<Shop> get_Shop_List();
	list<MYSQL_ROW> get_item_list_by_shop_ids(string shopIds);
	
};

