
#include "mdio.h"
#include "yt8521sh.hpp"
#include <assert.h>

int main(int argc, char *argv[]) {

    char *c = "eth0";
    uint16_t id = 3;
    uint16_t val = 0;

    int rc = mdio_open(c, id);
    assert(rc == 0);

    rc = mdio_read(id, 0x0, &val);
    assert(rc == 0);
    printf("reg:0x0 val:0x%02x\n", val);

    rc = mdio_read(id, 0x1, &val);
    assert(rc == 0);
    printf("reg:0x1 val:0x%02x\n", val);

    mdio_close(id);
    return 0;
}