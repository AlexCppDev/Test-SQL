#include "Constant_tags.h"
/*XML tags templates*/
const char* template_header = "<\? xml version = \"1.0\" encoding = \"UTF-8\" \?>";
const char* template_shop = "\
<shop id=\"%s\">\n \
	<name> %s </name>\n \
	<url> %s </url>\n \
	<working_time>\n \
		<open>%s</open>\n \
		<close>%s</close>\n \
	</working_time>\n \
	<offers>";

const char* template_item = "\
		<item id = \"%s\"> \n \
			<name>%s</name>\n \
			<description>%s</description>\n \
			<price>%s</price>\n \
		</item>";


const char* template_shop_string_close = "\
	</offers>\n\
</shop>";


