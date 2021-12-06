#pragma once

typedef struct {
    char bytes[4];
} IPAddress;

typedef enum {
    LEGACY_TCP,
} Protocol;

typedef struct {
    int port;
    IPAddress address;
    Protocol protocol;
} Channel;