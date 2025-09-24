
#include "mdio.h"
#include "mdioc++.h"
#include <assert.h>

int main(int argc, char *argv[]) {

    char *c = "eth0";
    uint16_t id = 1;

    int rc = mdio_open(c, id);
    assert(rc == 0);

//    rc = mdio_read(id, );
}