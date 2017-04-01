#include <string.h>
#include "dbus/dbus.h"
#include "sc_bus.h"
#include <stdio.h>

/*Get data results */
#define GET_DATA_OK									0
#define GET_DATA_ERROR								(-1)
/* DBUS Connection */
#define DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS			"com.sagemcom.stb.tr69datamodel"
#define DIAGNOSTIC_MENU_DBUS_PATH_DBUS				"/com/sagemcom/stb/tr69datamodel"
#define DIAGNOSTIC_MENU_DBUS_INTERFACE_MONITORING	"com.sagemcom.stb.tr69datamodel"
/* STB Identification parameters */
#define SERIAL_NUMBER								"getSerialNumber"
#define NAGRA_SERIAL_NUMBER							"get_STU_Number"
#define MODEL										"VELASQUEZ"
#define STB_MAC_ADDRESS								"getMACAddress_Diagnostic"
#define ETHERNET_MAC_ADDRESS						"getMACAddress_Diagnostic"
#define STB_MANUFACTURING_DATE						"TBD"
#define HARDWARE_VERSION							"getHardwareVersion"
#define NETWORK_ID									"getNetworkId"
#define MANUFACTURER								"getManufacturer"

/* Nvmem parameters */
#define TCD_MODE									"getTcdMode"
#define SI_MILTICAST_ADDRESS						"getSiMulticastAddress"
#define VM_INSTALLER_FREQUENCY						"getVmInstallerFrequency"
#define VM_INSTALLER_SYMBOLRATE						"getVmInstallerSymbolRate"
#define VM_INSTALLER_MODULATION						"getVmInstallerModulation"

/* Software parameters */
#define BOOTLOADER_VERSION							"getLoaderVersion"
#define TOTAL_SOFTWARE_UPDATES						"getDownload_counter"
#define DATE_TIME_LAST_STB_SOFTWARE					"get_Last_Download_Date"
#define TIVO_SOFTWARE_NAME							"get_SW_version"
/* Installation & Network addressing */

#define STB_SUBNET_MASK 							"getSubnetMask"
#define STB_IP_DEFAULT_GATEWAY 						"getDefaultGateway"
#define STB_MAC_ADDRESS 							"getMACAddress_Diagnostic"
#define FIRMWARE_VERSION 							"get_SW_version"
#define STB_ETHERNET_PORT_STATUS 					"TBD"
#define ETHERNET_MAC_ADDRESS 						"getMACAddress_Diagnostic"
#define TV_MANUFACTURER_MODEL 						"TBD"
#define STB_IP_ADDRESS 								"getIpAddress"
#define DNS_SERVER_II								"TBD"


/* Conditional_access parameters */
 #define NAGRA_SERIAL_NUMBER						"get_STU_Number"
 #define CA_PROVIDER_NAME                           "Nagravision"
 
/*Systeme_info parameters*/
 #define IR_INPUT_STATUS							"TBD"
 #define INTERNAL_TEMPERATURE						"getThermalManagement"
 #define CPU_UTILISATION							"TBD"
 #define HDMI_PORT_STATUS							"TBD"
 #define VIDEO_RESOLUTION							"TBD"
 #define VIDEO_ASPECT_RATIO							"TBD"
 #define VIDEO_FORMAT								"TBD"
 #define DIAGNOSTICS_PAGES_LANGUAGE					"TBD"
 #define AUDIO_SETUP								"TBD"
 #define STB_LIFE_TIME								"getLifeTime"
 #define TIME_SINCE_LAST_STB_BOOT_UP				"getStandbyTime"
 #define TOTAL_STB_POWER_OFF						"getStandbyCounter"
 #define RESET_TIME_SINCE_LAST_BOOT_UP				"resetTimeSinceLastBootUp"
 #define RESET_TOTAL_POWER_OFF						"resetTotalPowerOff"
 #define RESET_TOTAL_SOFTWARE_UPDATE				"resetTotalSoftwareUpdate"
 #define RESET_TOTAL_REBOOT							"resetTotalReboot"
 #define TOTAL_STB_REBOOT							"getbootcounter"
 /*Loader parameters*/
 #define BOOT_LOADER_CRC 							"TBD"
 /*Memory Map*/
#define ADDRESSING_MEMORY							"TBD"
#define MEMORY_BLOCK_STATUS							"TBD"
#define USED_MEMORY									"TBD"
#define TOTAL_MEMORY								"TBD"

#define MAX_MW_PARAM_SIZE							128

struct get_data
{
	char* method;
};
void create_get_data();
void destroy_get_data();
//void set_method(char* method);
//char* get_method_value_by_string();
//char* get_method_value_by_array(int length);


void create_get_data()
{	 
	if (sc_bus_init(SC_BUS_THREADED_IOLOOP, SC_BUS_TRACE_LEVEL_WARNING, NULL) < 0)
    {
        printf( "ERROR sc_bus_init"  );
    }

    if (sc_bus_declare_name(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS) < 0)
    {
        printf(  "ERROR sc_bus_declare_name"  );
    }
}

void destroy_get_data()
{
	sc_bus_undeclare_name(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS);
	sc_bus_exit();
}
/*
void set_method(char* mtd)
{
	method = mtd;
}

char* get_method_value_by_string()
{
	DBusMessage *msg;
	DBusMessage *reply;
	DBusMessageIter iter_base;
	char *param;
	dbus_bool_t result = FALSE;
	
	msg = dbus_message_new_method_call(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS, DIAGNOSTIC_MENU_DBUS_PATH_DBUS,DIAGNOSTIC_MENU_DBUS_INTERFACE_MONITORING, method.c_str());

	if (msg == NULL)
	{
		printf(  "dbus_message_new_method_call failed on no memory"  );
		return "";
	}
	
	if (sc_bus_method_call (msg, NULL, NULL, (void *)&reply) < 0)
	{
		printf(  "sc_bus_method_call for "  method  " failed"  );
		return "";
	}
	result = dbus_message_iter_init(reply, &iter_base);
	
	if(result == FALSE)
	{
		printf(  "dbus_message_iter_init for "  method  " failed"  );
		return "";
	}
	dbus_message_iter_get_basic(&iter_base, &param);
	dbus_message_unref (reply);
	printf(::string data(param);
	return data;
}

char* get_method_value_by_array(int length)
{
	DBusMessage *msg;
	DBusMessage *reply;
	DBusMessageIter iter_base,sub;
	char *param;
	
	msg = dbus_message_new_method_call(DIAGNOSTIC_MENU_DBUS_SERVICE_DBUS, DIAGNOSTIC_MENU_DBUS_PATH_DBUS,DIAGNOSTIC_MENU_DBUS_INTERFACE_MONITORING, method.c_str());

	if (msg == NULL)
	{
		printf(  "dbus_message_new_method_call failed on no memory"  );
		return "";
	}
	
	if (sc_bus_method_call (msg, NULL, NULL, (void *)&reply) < 0)
	{
		printf("sc_bus_method_call for "  " failed"  );
		return "";
	}
	dbus_message_iter_init(reply, &iter_base);

	if (dbus_message_iter_get_arg_type(&iter_base)==DBUS_TYPE_ARRAY)
	{
		dbus_message_iter_recurse (&iter_base, &sub);

		if (dbus_message_iter_get_arg_type(&sub)==DBUS_TYPE_BYTE)
		{
				dbus_message_iter_get_fixed_array (&sub, &param, &length);
				printf("%ss",string data(param));
				return data;
		}
	}
	return "";
}

*/

int main(){
    //get_data get_data;
    create_get_data();
    destroy_get_data();
    return 0;
}
