#include <stdlib.h>
#include "util.h"

void *util_malloc(size_t size)
{
    if(likely(size)) {
        void *ptr;
        ptr = malloc(size);
        if (ptr)
            return ptr;
        fprintf(stderr, "failed to allocate %zu bytes\n", size);
        abort();
    }
    return NULL;
}