
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"
#include "mainloop.h"
#include "io.h"

struct io {
    int ref_count;
    int fd;
    uint32_t events;
    io_callback_func_t read_callback;
};

static void io_callback(int fd, uint32_t events, void *user_data)
{
    struct io *io = user_data;

    // ERROR
    if ((events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))) {

    }

    // READ
    if ((events & EPOLLIN) && io->read_callback) {

    }

    // WRITE
}

static void io_cleanup(void *user_data)
{

}

static struct io* io_ref(struct io *io)
{
    if (!io)
        return NULL;
    
    __sync_fetch_and_add(&io->ref_count, 1);

    return io;
}

static void io_unref(struct io *io)
{
    if (!io)
        return;

    if(__sync_sub_and_fetch(&io->ref_count, 1))
        return;
    
    free(io);
}

struct io *io_new(int fd)
{
    struct io *io;
    
    if(fd < 0)
        return NULL;
    
    io = new0(struct io, 1);
    io->fd = fd;
    io->events = 0;

    if (mainloop_add_fd(fd, io->events, io_callback, 
                            io, io_cleanup) < 0) {
        free(io);
        return NULL;
    }

    return io_ref(io);
}

void io_destroy(struct io *io)
{
    if(!io)
        return;

    mainloop_remove_fd(io->fd);
    io_unref(io);
}