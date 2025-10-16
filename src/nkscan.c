#include <stdio.h>
#include <arpa/inet.h>
#include <stdbool.h>

#include "nkscan.h"

bool is_valid_ip(const char *ip) {
    unsigned char buf[sizeof(struct in6_addr)];
    if (inet_pton(AF_INET, ip, buf) == 1) return true;
    if (inet_pton(AF_INET6, ip, buf) == 1) return true;
    return false;
}

int nk_scan(const char *ip) {
    if (is_valid_ip(ip) == false) {
        printf("Not a valid ip...\n");
        return 1;
    }
    printf("ok ip\n");

    return 0;
}
