# Correction:

## Test 1: DONE
We will start by checking that the compilation of the library generates the files requested in the subject, by modifying HOSTTYPE:
```
$> export HOSTTYPE = Testing
$> make re
...
ln -s libft_malloc_Testing.so libft_malloc.so
$> ls -l libft_malloc.so
libft_malloc.so -> libft_malloc_Testing.so
$>
```

The Makefile uses HOSTTYPE to set the libraire's name (libft_malloc_ $ HOSSTYPE.so) and creates a symbolic link libft_malloc.so pointing to libft_malloc_ $ HOSSTYPE.so?

## Test 2: DONE
Export functions
Check with nm that the library exports the functions malloc, free, realloc and show_alloc_mem.

```
$> nm libft_malloc.so
0000000000000000 T _free
0000000000000000 T _malloc
0000000000000000 T _realloc
0000000000000000 T _show_alloc_mem
U _mmap
U _munmap
U _getpagesize
U _write
U dyld_stub_binder
$>
```

The functions exported by the library are marked with a T, those used of a U (the addresses have been replaced by 0, they change from one library to another, just like the order of the lines).

Functionality tests
Start by making yourself a launch script that only changes the environment variables when it's time to run a test program. It should be named run.sh, and be executable:
```
$> cat run.sh
#!/Bin/sh
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
```

## Test 3:
Malloc test
We will make a first test program that does not malloc, in order to have a basis of comparison:
```
$> gcc -o test0 test0.c
$> /usr/bin/time -l ./test0
0.00 real 0.00 user 0.00 sys
491520 maximum resident set size
0 average shared memory size
0 average unshared data size
0 average unshared stack size
139 page reclaims
0 page faults
0 swaps
0 block input operations
0 block output operations
0 messages sent
0 messages received
0 signals received
0 voluntary context switches
1 involuntary context switches
$>
```

We will then add a malloc, and write in each allocation to ensure that the memory page is allocated in physical memory by the MMU.
The system really only allocates the memory of a page when written from inside, so even making a larger mmap than the malloc request does not change the "page reclaims".

## Test 4
```
$> gcc -o test1 test1.c
$> /usr/bin/time -l ./test1
0.00 real 0.00 user 0.00 sys
1544192 maximum resident set size
0 average shared memory size
0 average unshared data size
0 average unshared stack size
396 page reclaims
0 page faults
0 swaps
0 block input operations
0 block output operations
0 messages sent
0 messages received
0 signals received
0 voluntary context switches
1 involuntary context switches
$>
```

Our test1 program requested 1024 times 1024 bytes, so 1Mbyte.
We can see it by making the difference with the test0 program:
- or between the lines "maximum resident set size", we get a little more than 1Mbyte
- or between the lines reclaims page that will multiply by the value of getpagesize (3)

```
$>./run.sh /usr/bin/time -l ./test0 
0.01 real 0.00 user 0.00 sys 
708608 maximum resident set size 
0 average shared memory size 
0 average unshared data size 
0 average unshared stack size 
214 page reclaims 
0 page faults 
0 swaps 
0 block input operations 
1 block output operations 
0 messages sent 
0 messages received 
0 signals received 
0 voluntary context switches 
1 involuntary context switches 
$>./run.sh /usr/bin/time -l ./test1 
0.00 real 0.00 user 0.00 sys 
4902912 maximum resident set size 
0 average shared memory size 
0 average unshared data size 
0 average unshared stack size 
1238 page reclaims 
0 page faults 
0 swaps 
0 block input operations 
0 block output operations 
0 messages sent 
0 messages received 
0 signals received 
0 voluntary context switches 
2 involuntary context switches 
$>
```

We see in this example that this malloc used 1024 pages or 4MBytes to store 1Mbyte.

Count the number of pages used and adjust the score as follows:
- less than 255 pages, the reserved memory is insufficient: 0
- 1023 pages and more, the malloc works but consumes a minimum page with each allocation: 1
- between 513 pages and 1022 pages, the malloc works but the overhead is too important: 2
- between 313 pages and 512 pages, the malloc works but the overhead is very important: 3
- between 273 pages and 312 pages, the malloc works but the overhead is important: 4
- between 255 and 272 pages, the malloc works and the overhead is reasonable: 5

Pre-allocated zones
Check in the source code that the pre-allocated areas according to the different sizes of malloc can store at least 100 times the maximum size for this type of zone.
Also check that the size of the fields is a multiple of getpagesize ().

## Test 5
Free tests
We will simply add a free to our test program:

```
$> gcc -o test2 test2.c
```

We will compare the number of "reclaims" with the number of test0 and test1. If there are as many "reclaims" or more than test1, free does not work.

```
$> ./ run.sh /usr/bin/time -l ./test2
```

Does free works? (less "reclaims pages" than test1)

test2 has maximum 3 "page reclaims" in addition to test0?

## Test 6

Realloc test

```
$> gcc -o test3 test3.c
$> ./run.sh ./test3
Hello
Hello
$>
```

It works as in the example?

## Test 7
Realloc ++ test
In test3.c, change the body of the main function as follows:


It still works?

Error management
Test the special cases and errors.

```
$> gcc -o test4 test4.c
$> ./run/sh ./test4
Hello
```

In case of error, realloc should return NULL. Is "Bonjours" displayed as in the example?
If the program reacts unhealthily (segfault or others), the defense stops and you must select Crash at the top of the scale.

## Test 8
Show_alloc_mem test

```
$> gcc -o test5 test5.c -L. -lft_malloc
$> ./test5
```

The display corresponds to the subject and to the TINY / SMALL / LARGE distribution of the project?

## Test 9: Bonus
Competitive access
The project manages the competitive access of the threads thanks to the pthread library and the mutexes.

Count the applicable cases:
- a mutex prevents multiple threads from entering the malloc function simultaneously
- a mutex prevents multiple threads from simultaneously entering the free function
- a mutex prevents multiple threads from entering the realloc function simultaneously
- a mutex prevents multiple threads from simultaneously entering the show_alloc_mem function

Other bonus examples:
- During a free, the project "defragments" the free memory by grouping the concomitant free blocks into one
- Malloc has debug environment variables
- A function allows to dump hexa allocated zones
- A function makes it possible to display a history of the memory allocations made