#include <stdbool.h>
#include <getopt.h>

#include "../src/mainloop.h"
#include "../src/io.h"
#include "../src/shell.h"

static struct {
    bool interactive;
    int argc;
    char **argv;
    struct io *input;
    const struct shell_menu *menu;
} data;

static const struct option main_options [] = {
    {"help", no_argument, 0, 'h'},
};

void shell_init(int argc, char **argv)
{
    data.argc = argc;
    data.argv = argv;
    data.interactive = (argc == 0);
    mainloop_init();
}

bool shell_set_menu(const struct shell_menu *menu)
{
    if (!menu)
        return false;
    
    data.menu = menu;
    return true;
}

static int shell_exec(int argc, char *argv[])
{
    return true;
}

bool shell_attach(int fd)
{
    struct io *io;

    if (data.input)
        return false;
    
    io = io_new(fd);
    data.input = io;

    if (data.interactive) {

    } else {
        if (shell_exec(data.argc, data.argv) < 0) {
            return true;
        }
    }
    return true;
}