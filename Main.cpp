#include <memory>
#include "XML_Exporter.h"
#include "SQL_controller.h"
#include "Shops_service.h"


int main(int argc, char* argv[])
{
	char File_Path_XML[14] = { "./XML_out.xml" };
	if (argv[0])
	{
		*argv = File_Path_XML;
	}
	
	SQL_Controller* sql_controller = new SQL_Controller();

	if (sql_controller->Connection_to_DB()) {
		
		Shops_service shop_srv;
		shop_srv.set_sql_contorller(sql_controller); 
		list<Shop> open_shops = shop_srv.get_opened();
		
		XML_Exporter exporter; 
		exporter.Export_to_file(open_shops, *argv); //Fill and export to XML 

		sql_controller->Close_connection_to_DB();
	}
	system("pause");
	return 0;
	
}
 