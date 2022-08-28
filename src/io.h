#ifndef __IO_H__
#define __IO_H__

#include <stdbool.h>

struct io;

struct io *io_new(int fd);
void io_destroy(struct io *io);

typedef bool (*io_callback_func_t)(struct io *io, void *user_data);

#endif