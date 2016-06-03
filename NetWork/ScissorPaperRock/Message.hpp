#ifndef _SCISSORPAPERROCK_MESSAGE_
#define _SCISSORPAPERROCK_MESSAGE_

#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

enum MsgType{
    LOGIN,
    LOGOUT,
    INFO,
    OPENROUND,
    JOINROUND,
    QUITROUND,
    CAST, // -------- client side -------

    STATUS, // server side

    UNKNOWN
};

struct Msg
{
    using len_t = uint32_t;
    using type_t = uint32_t;
    static const size_t HeadLen = sizeof(len_t) + sizeof(type_t);

    len_t len; // not include this word
    type_t type;
    char data[0];
};

void decodeMsg(Msg* msg);
char* encodeMsg(MsgType type, size_t dataLen, const char* data);

#endif // _SCISSORPAPERROCK_MESSAGE_