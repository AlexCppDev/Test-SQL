#include "SQL_controller.h"
using namespace std;


bool SQL_Controller::Connection_to_DB()
{
	conn = mysql_init(NULL);
	mysql_set_character_set(conn, "utf8");
	mysql_character_set_name(conn);
	if (conn == NULL)
	{
		// message, if descriptor not exist
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
		return false;
	}
	// Server connection
	if (!mysql_real_connect(conn, "localhost", "root", "root", "test", NULL, NULL, 0))
	{
		// Error msg 
		fprintf(stderr, "Error: can't connect to database %s\n", mysql_error(conn));
		return false;
	}
	else
	{
		// "Success!" descriptor
		fprintf(stdout, "Success connection!\n");
		return true;
	}
}

void  SQL_Controller::Close_connection_to_DB() {
	mysql_close(conn);
}

SQL_Controller::~SQL_Controller()
{
	mysql_server_end();
}

list<MYSQL_ROW> SQL_Controller::get_item_list_by_shop_ids(string shopIds)
{		
		list<MYSQL_ROW> res_list;

		string query = "SELECT  id, shop_id, name, description, price FROM items WHERE shop_id IN (" + shopIds + ");";
		mysql_query(conn, query.c_str());
		list<Item> *items = new list<Item>();
		Item* item=NULL;
		if (res = mysql_store_result(conn)) {
			while (row = mysql_fetch_row(res)) {
				res_list.push_back(row);
			}
		}
		return res_list;
	}


	list<Shop> SQL_Controller::get_Shop_List()
{
	mysql_query(conn, "SELECT id,name,url,working_time_open,working_time_close FROM shops WHERE NOW() between working_time_open and working_time_close;");	

	list<Shop> *shops = new list<Shop>();

	if (res = mysql_store_result(conn)) {
		while (row = mysql_fetch_row(res)) {
	
			char* id = row[0];
			char* name = row[1];
			char* url = row[2];
			char* working_time_open = row[3];
			char* working_time_close = row[4];
			Shop* shop = new Shop(id, name, url, working_time_open, working_time_close);
			shops->push_back(*shop);
			delete shop;
		}
		
	}
	return *shops;
	
}

