#pragma once

#include <string.h>

namespace GanglionLib
{
#pragma pack(push, 1)
    struct GanglionData
    {
        unsigned char data[20];
        long timestamp;
        GanglionData (unsigned char *data, long timestamp)
        {
            memcpy (this->data, data, sizeof (unsigned char) * 20);
            this->timestamp = timestamp;
        }
        GanglionData ()
        {
        }
        GanglionData (const GanglionData &other)
        {
            timestamp = other.timestamp;
            memcpy (data, other.data, sizeof (unsigned char) * 20);
        }
    };
#pragma pack(pop)

    enum CustomExitCodes
    {
        STATUS_OK = 0,
        GANGLION_NOT_FOUND_ERROR = 1,
        GANGLION_IS_NOT_OPEN_ERROR = 2,
        GANGLION_ALREADY_PAIR_ERROR = 3,
        GANGLION_ALREADY_OPEN_ERROR = 4,
        SERVICE_NOT_FOUND_ERROR = 5,
        SEND_CHARACTERISTIC_NOT_FOUND_ERROR = 6,
        RECEIVE_CHARACTERISTIC_NOT_FOUND_ERROR = 7,
        DISCONNECT_CHARACTERISTIC_NOT_FOUND_ERROR = 8,
        TIMEOUT_ERROR = 9,
        STOP_ERROR = 10,
        FAILED_TO_SET_CALLBACK_ERROR = 11,
        FAILED_TO_UNSUBSCRIBE_ERROR = 12,
        GENERAL_ERROR = 13,
        NO_DATA_ERROR = 14,
        SYNC_ERROR = 15,
        NOT_IMPLEMENTED_ERROR = 16,
        INVALID_MAC_ADDR_ERROR = 17,
        PORT_OPEN_ERROR = 18
    };

    // void * is a legacy from dynamic library which was loaded via LoadLibrary\dlopen
    int initialize (void *param);
    int open_ganglion (void *param);
    int open_ganglion_mac_addr (void *param);
    int stop_stream (void *param);
    int start_stream (void *param);
    int close_ganglion (void *param);
    int get_data (void *param);
    int config_board (void *param);
    int release (void *param);
} // namespace GanglionLib
