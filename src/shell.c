#include <stdbool.h>

#include "../src/mainloop.h"
#include "../src/shell.h"

static struct {
    bool mode;          // 1: non interactive, 0: interactive
    const struct shell_menu *menu;
} data;

void shell_init(void)
{
    mainloop_init();
}

bool shell_set_menu(const struct shell_menu *menu)
{
    if (!menu)
        return false;
    
    data.menu = menu;
    
    return true;
}

bool shell_attach(int fd)
{
    // TODO
}