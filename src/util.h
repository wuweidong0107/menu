#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>

/* Test for GCC < 2.96 */
#if __GNUC__ < 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ < 96))
#define __builtin_expect(x) (x)
#endif

#ifndef likely
#define likely(x)	__builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x)	__builtin_expect(!!(x), 0)
#endif

#define new0(type, count)               \
    (type *) ( {                        \
        size_t __n = (size_t)(count);   \
        size_t __s = sizeof(type);      \
        void *__p;                      \
        __p = util_malloc(__n * __s);   \
        memset(__p, 0, __n * __s);      \
        __p;                            \
    })
    
void *util_malloc(size_t size);

#endif