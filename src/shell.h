#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdbool.h>

typedef void (*shell_menu_cb_t)(int argc, char *argv[]);

struct shell_menu_entry {
    const char *cmd;
    const char *arg;
    shell_menu_cb_t func;
    const char *desc;
};

struct shell_menu {
    const char *name;
    const struct shell_menu_entry entries[];
};

void shell_init(void);
bool shell_set_menu(const struct shell_menu *menu);
bool shell_attach(int fd);

#endif