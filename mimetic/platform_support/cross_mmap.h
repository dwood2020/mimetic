#ifndef CROSS_MMAP_H
#define CROSS_MMAP_H

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

#include <stddef.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void* cross_mmap(void* addr, size_t length, int prot, int flags, int fd, size_t offset);
int   cross_munmap(void* addr, size_t length);

#ifdef __cplusplus
}
#endif

#endif /* CROSS_MMAP_H */
