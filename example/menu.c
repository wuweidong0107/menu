#include <stdio.h>

#include "../src/shell.h"

static void cmd_main1(int argc, char *argv[])
{
}

static const struct shell_menu main_menu = {
    .name = "main",
    .entries = {
        {"main1", NULL, cmd_main1, "main menu command 1"},
        {},
    },
};

int main(int argc, char *argv[])
{
    shell_init(argc, argv);
    shell_set_menu(&main_menu);
    shell_attach(fileno(stdin));
    return 0;
}