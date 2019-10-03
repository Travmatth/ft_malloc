# FT_MALLOC

## USE
## REQUIREMENTS
- [x] The library must be named libft_malloc_$HOSTTYPE.so.
- [x] Your Makefile will have to check the existence of the environment variable $HOSTTYPE. If it is empty or non-existant, to assign the following value:
```
‘uname -m‘_‘uname -s‘
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
```
- [x] Your Makefile will have to create a symbolic link libft_malloc.so pointing to libft_malloc_$HOSTTYPE.so so for example:
`libft_malloc.so -> libft_malloc_intel-mac.so`
- You are allowed a global variable to manage your allocations and one for the threadsafe.
This mini project is about writing a dynamic allocation memory management library. So that you can use it with some programs already in use without modifying them or recompiling, you must rewrite the following libc functions malloc(3), free(3) and realloc(3).
Your functions will be prototyped like the sytems ones:
```
#include <stdlib.h>
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
```
- The malloc() function allocates “size” bytes of memory and returns a pointer to the allocated memory.
- The realloc() function tries to change the size of the allocation pointed to by “ptr” to “size”, and returns “ptr”. If there is not enough room to enlarge the memory allocation pointed to by ptr, realloc() creates a new allocation, copies as much of the old data pointed to by “ptr” as will fit to the new allocation, frees the old allocation, and returns a pointer to the allocated memory.
- The free() function deallocates the memory allocation pointed to by “ptr”. If “ptr”is a NULL pointer, no operation is performed.
- If there is an error, the malloc() et realloc() functions return a NULL pointer.
- You must use the mmap(2) and munmap(2) syscall to claim and return the memory zones to the system.
- You must manage your own memory allocations for the internal functioning of your project without using the libc malloc function.
- With performance in mind, you must limit the number of calls to mmap(), but also to munmap(). You have to “pre-allocate” some memory zones to store your “small” and “medium” malloc.
- The size of these zones must be a multiple of getpagesize().
A rather UNIX project malloc
- Each zone must contain at least 100 allocations.
```
◦ “TINY” mallocs, from 1 to n bytes, will be stored in N bytes big zones.
◦ “SMALL” mallocs, from (n+1) to m bytes, will be stored in M bytes big zones.
◦ “LARGE” mallocs, fron (m+1) bytes and more, will be stored out of zone, which simply means with mmap(), they will be in a zone on their own.
```
- It’s up to you to define the size of n, m, N and M so that you find a good compromise between speed (saving on system recall) and saving memory. You also must write a function that allows visual on the state of the allocated memory zones. It needs to be prototyped as follows:
```
void show_alloc_mem();
The visual will be formatted by increasing addresses such as:
TINY : 0xA0000
0xA0020 - 0xA004A : 42 bytes
0xA006A - 0xA00BE : 84 bytes
SMALL : 0xAD000
0xAD020 - 0xADEAD : 3725 bytes
LARGE : 0xB0000
0xB0020 - 0xBBEEF : 48847 bytes
Total : 52698 bytes
```
## RESOURCES
- [glibc malloc internals](https://sourceware.org/glibc/wiki/MallocInternals)
- [glibc malloc concepts](https://developers.redhat.com/blog/2017/03/02/malloc-internals-and-you/)
- [malloc implementations](https://en.wikibooks.org/wiki/C_Programming/stdlib.h/malloc#Implementations)
- [what happens when you dont free after malloc?](https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc)
- [when you exit a c application, is the malloc ed memory automatically freed?](https://stackoverflow.com/questions/2213627/when-you-exit-a-c-application-is-the-malloc-ed-memory-automatically-freed)
- [what happens to the malloced memory when exit(1) is encountered?](https://stackoverflow.com/questions/10588014/what-happens-to-the-malloced-memory-when-exit1-is-encountered)
- [compiling a custom malloc](https://stackoverflow.com/questions/5822788/compiling-a-custom-malloc)
- [implementing malloc and free](https://medium.com/@andrestc/implementing-malloc-and-free-ba7e7704a473)
- [Building your own memory manager](https://developer.ibm.com/tutorials/au-memorymanager/)
- [malloc concepts & env vars](https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_chapter/libc_3.html)
- [mmap concepts & vars](https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_chapter/libc_13.html#SEC246)
- [dl & jemalloc implementations](https://blog.nsogroup.com/a-tale-of-two-mallocs-on-android-libc-allocators-part-1-dlmalloc/)
- [jemalloc details](http://jemalloc.net/jemalloc.3.html)
- [linux heap structure and the behaviour with malloc and free](https://stackoverflow.com/questions/10540845/linux-heap-structure-and-the-behaviour-with-malloc-and-free)
- [implementing your own malloc free with mmap and munmap](https://stackoverflow.com/questions/8475609/implementing-your-own-malloc-free-with-mmap-and-munmap)
- [Understanding the heap by breaking it](https://www.blackhat.com/presentations/bh-usa-07/Ferguson/Whitepaper/bh-usa-07-ferguson-WP.pdf)
- [how to write your own malloc and free](http://tharikasblogs.blogspot.com/p/how-to-write-your-own-malloc-and-free.html)
