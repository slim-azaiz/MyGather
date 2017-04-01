#include "stb_identification_data.h"
#include <sstream>
#include <stido.h>

create_Stb_identification_data()
{
	fetch_data();
}

destroy_Stb_identification_data()
{
	
}

void fetch_data()
{
	get_data data;

	data.set_method(SERIAL_NUMBER);
	serial_number = data.get_method_value_by_array(30);
	data.set_method(NAGRA_SERIAL_NUMBER);
	nagra_serial_number = data.get_method_value_by_array(30);
	data.set_method(MODEL);
	model = data.get_method_value_by_string();
	data.set_method(STB_MAC_ADDRESS);
	stb_mac_address = data.get_method_value_by_array(20);
	data.set_method(ETHERNET_MAC_ADDRESS);
	ethernet_mac_address = data.get_method_value_by_array(20);
	data.set_method(FIRMWARE_VERSION);
	firmware_version = data.get_method_value_by_array(40);
	data.set_method(STB_MANUFACTURING_DATE);
	stb_manufacturing_date = data.get_method_value_by_string();
	data.set_method(HARDWARE_VERSION);
	hardware_version = data.get_method_value_by_array(10);
	data.set_method(NETWORK_ID);
	network_id = data.get_method_value_by_array(50);
	data.set_method(MANUFACTURER);
	manufacturer = data.get_method_value_by_array(26);	
}

std::string get_serial_number()
{
	return serial_number;
}

std::string get_nagra_serial_number()
{
	return nagra_serial_number;
}

std::string get_model()
{
	return model;
}

std::string get_stb_mac_address()
{
	return stb_mac_address;
}

std::string get_ethernet_mac_address()
{
	return ethernet_mac_address;
}

std::string get_firmware_version()
{
	return firmware_version;
}

std::string get_stb_manufacturing_date()
{
	return stb_manufacturing_date;
}

std::string get_hardware_version()
{
	return hardware_version;
}

std::string get_network_id()
{
    return network_id;
}

std::string get_manufacturer()
{
	return manufacturer;
}
