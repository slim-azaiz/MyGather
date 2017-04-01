#ifndef STB_IDENTIFICATION_DATA_H
#define STB_IDENTIFICATION_DATA_H

#include <string>
#include "get_data.h"

struct Stb_identification_data 
{
    std::string serial_number;
	std::string nagra_serial_number;
	std::string model;
	std::string stb_mac_address;
	std::string ethernet_mac_address;
	std::string firmware_version;
	std::string stb_manufacturing_date;
	std::string hardware_version;
	std::string network_id;
	std::string manufacturer;
    get_data data;
}


void create_Stb_identification_data();
void destroy_Stb_identification_data();
std::string get_serial_number();
std::string get_nagra_serial_number();
std::string get_model();
std::string get_stb_mac_address();
std::string get_ethernet_mac_address();
std::string get_firmware_version();
std::string get_stb_manufacturing_date();
std::string get_hardware_version();
std::string get_network_id();
std::string get_manufacturer(); 
void fetch_data();

};
#endif //STB_IDENTIFICATION_DATA_H
