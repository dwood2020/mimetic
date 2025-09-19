#include "mimetic/platform_support/cross_mmap.h"


#if defined(_WIN32) || defined(WIN32)

void* cross_mmap(void* addr, size_t length, int prot, int flags, int fd, size_t offset) {
    DWORD flProtect = 0;
    DWORD dwAccess  = 0;

    // Protection flags
    if (prot & PROT_WRITE) {
        flProtect = (prot & PROT_EXEC) ? PAGE_EXECUTE_READWRITE : PAGE_READWRITE;
        dwAccess  = (prot & PROT_EXEC) ? FILE_MAP_ALL_ACCESS : FILE_MAP_WRITE | FILE_MAP_READ;
    } else if (prot & PROT_READ) {
        flProtect = (prot & PROT_EXEC) ? PAGE_EXECUTE_READ : PAGE_READONLY;
        dwAccess  = FILE_MAP_READ;
    } else if (prot & PROT_EXEC) {
        flProtect = PAGE_EXECUTE;
        dwAccess  = FILE_MAP_EXECUTE;
    } else {
        flProtect = PAGE_NOACCESS;
        dwAccess  = 0;
    }

    // Anonymous mapping -> use system paging file
    HANDLE hFile = (flags & MAP_ANONYMOUS) ? INVALID_HANDLE_VALUE : (HANDLE)_get_osfhandle(fd);
    if (hFile == (HANDLE)-1) {
        return MAP_FAILED;
    }

    HANDLE hMap = CreateFileMapping(
        hFile,
        NULL,
        flProtect,
        (DWORD)((length + offset) >> 32),
        (DWORD)((length + offset) & 0xFFFFFFFF),
        NULL
    );

    if (hMap == NULL) {
        return MAP_FAILED;
    }

    void* map = MapViewOfFileEx(
        hMap,
        dwAccess,
        (DWORD)(offset >> 32),
        (DWORD)(offset & 0xFFFFFFFF),
        length,
        addr // hint (can be NULL)
    );

    CloseHandle(hMap);

    return (map == NULL) ? MAP_FAILED : map;
}

int cross_munmap(void* addr, size_t length) {
    (void)length; // Windows does not need length to unmap
    return UnmapViewOfFile(addr) ? 0 : -1;
}

#else // POSIX passthrough

void* cross_mmap(void* addr, size_t length, int prot, int flags, int fd, size_t offset) {
    return mmap(addr, length, prot, flags, fd, offset);
}

int cross_munmap(void* addr, size_t length) {
    return munmap(addr, length);
}

#endif
