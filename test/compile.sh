#!/bin/bash

gcc -o test0 test/test0.c
gcc -o test1 test/test1.c
gcc -o test2 test/test2.c
gcc -o test3 test/test3.c
gcc -o test3_1 test/test3_1.c
gcc -o test4 test/test4.c
gcc -o test5 test/test5.c -L. -lft_malloc