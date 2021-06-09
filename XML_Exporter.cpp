#include "XML_Exporter.h"


void XML_Exporter::Export_to_file(list <Shop> shop,  char* File_Path_XML)
{
	std::ofstream outf(File_Path_XML);
	snprintf(buf, sizeof(buf), template_header);
	outf << buf << std::endl;

	for (Shop shop: shop)
	{	//Filling Shop tag	
		snprintf(buf, sizeof(buf), template_shop, shop.get_id(), shop.get_name(),shop.get_url(), shop.get_working_time_open(), shop.get_working_time_close());
		outf << buf << std::endl;
			
		for (Item itm_shop : shop.get_items())
		{	//Filling Item tag
			snprintf(buf, sizeof(buf), template_item, itm_shop.get_id(), itm_shop.get_name_of_item(), Tags_deleting::str_tags_delete(itm_shop.get_description()), itm_shop.get_price());
			outf << buf << std::endl;
		}
		//Close Shop tag
		snprintf(buf, sizeof(buf), template_shop_string_close);
		outf << buf << std::endl;
		
	}

}
XML_Exporter::~XML_Exporter() {
}