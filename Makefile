CROSS_COMPILE=$(TOOLROOT)/bin/arm-TiVo-linux-gnueabi
CC=$(CROSS_COMPILE)-gcc

TR69= $(SANDBOX)/../sdt_sagemcom/TR69
CFLAGS += -g -W -Wall 
CFLAGS += -I$(TR69)/dbus 
CFLAGS += -I$(TR69)/sc-bus/include 

LDFLAGS += -L$(TR69)/libCommon 
LDFLAGS += -ldbus-1
LDFLAGS += -lsc_bus

EXEC=gather

all: $(EXEC)


gather:  get_data.o
		$(CC) $(CFLAGS) -o gather  get_data.o $(LDFLAGS) 

get_data.o: get_data.c get_data.h
		$(CC) -o get_data.o -c get_data.c $(CFLAGS) 

clean:
		rm -f *.o $(EXEC)
		        
