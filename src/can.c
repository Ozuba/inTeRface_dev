#include "can.h"

int socket_can;
struct can_frame frame;

int initCan()
{
    socket_can = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    // Create a CAN socket
    if (socket_can < 0)
    {
        perror("Socket creation failed");
        return 1;
    }
    // Specify the CAN interface (e.g., "can0")
    struct ifreq ifr;
    strncpy(ifr.ifr_name, "vcan0", IFNAMSIZ - 1);
    if (ioctl(socket_can, SIOCGIFINDEX, &ifr) < 0)
    {
        perror("Failed to get interface index");
        close(socket_can);
        return 1;
    }

    struct sockaddr_can addr;
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(socket_can, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Socket bind failed");
        close(socket_can);
        return 1;
    }

       // Make the socket non-blocking
    int flags = fcntl(socket_can, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl F_GETFL failed");
        close(socket_can);
        return 1;
    }
    if (fcntl(socket_can, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl F_SETFL failed");
        close(socket_can);
        return 1;
    }
    printf("Listening for CAN messages on %s...\n", "can0");
}

void decodeCan()
{
    if(read(socket_can, &frame, sizeof(struct can_frame)) > 0){
    printf("Received CAN message: ID = 0x%X, Data = ", frame.can_id);
    for (int i = 0; i < frame.can_dlc; i++)
    {
        printf("0x%02X ", frame.data[i]);
    }
    printf("\n");
    }
}