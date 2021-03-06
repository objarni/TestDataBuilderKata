#pragma once

typedef struct {
    char bytes[4];
} IPAddress;

typedef enum {
    LEGACY_TCP,
    LEGACY_UDP,
} Protocol;

typedef struct {
    int port;
    IPAddress address;
    Protocol protocol;
} Channel;