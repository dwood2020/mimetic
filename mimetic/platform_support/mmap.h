#ifndef MIMETIC_PLATFORM_SUPPORT_MMAP
#define MIMETIC_PLATFORM_SUPPORT_MMAP

// Define POSIX mmap flags for compatibility
#ifndef PROT_READ
#define PROT_READ   0x1
#endif

#ifndef PROT_WRITE
#define PROT_WRITE  0x2
#endif

#ifndef PROT_EXEC
#define PROT_EXEC   0x4
#endif

#ifndef MAP_SHARED
#define MAP_SHARED  0x01
#endif

#ifndef MAP_PRIVATE
#define MAP_PRIVATE 0x02
#endif

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS 0x20
#endif

#ifndef MAP_FAILED
#define MAP_FAILED ((void*)-1)
#endif

#include <stddef.h> // size_t

namespace platform_support {

    void* mmap(void* addr, size_t length, int prot, int flags, int fd, size_t offset);
    int   munmap(void* addr, size_t length);
}


#endif /* MIMETIC_PLATFORM_SUPPORT_MMAP */
