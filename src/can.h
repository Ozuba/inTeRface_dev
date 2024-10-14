#ifndef CAN_H
#define CAN_H

#include <stdio.h>      // For printf and perror
#include <stdlib.h>     // For exit() and malloc()
#include <string.h>     // For strncpy()
#include <unistd.h>     // For close()
#include <sys/socket.h> // For socket()
#include <linux/can.h>  // For CAN-specific definitions
#include <linux/can/raw.h> // For CAN raw socket definitions
#include <net/if.h>     // For struct ifreq and interface management
#include <sys/ioctl.h>  // For ioctl()
#include <fcntl.h>      // For fcntl()

#include "TeR_DATABASES/ter.h" // For TeR structure 



int initCan();
void decodeCan();

#endif