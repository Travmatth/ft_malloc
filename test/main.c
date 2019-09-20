#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../includes/malloc.h"

#define M (1024 * 1024)

int test_1()
{
	int *addr;

	for (int i = 0; i < 1024; i++)
	{
		addr = (int*)malloc(sizeof(int)*1024);
		addr[i] = 42;
		if (addr[i] != 42)
		{
			printf("Test 1: addr[%d] == %d", i, addr[i]);
			return (1);
		}
	}
	return (0);
}

int test_2()
{
	char *addr;

	for (int i = 0; i < 1024; i++)
	{
		addr = (char *)malloc(1024);
		addr[0] = 42;
		free(addr);
	}
	return (0);
}

void print(char *s)
{
	write(1, s, strlen(s));
}

int test_3()
{
	char *addr1;
	char *addr3;

	addr1 = (char*)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = realloc(addr1, 128*M);
	addr3[127*M] = 42;
	print(addr3);
	return (0);
}

int test_3_1()
{
	char *addr1;
	char *addr2;
	char *addr3;

	addr1 = (char*)malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = malloc(16 * M);
	addr3 = realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}

int	test_4()
{
	char *addr;

	addr = malloc(16);
	free(NULL);
	free(addr + 5);
	if (realloc(addr + 5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}

int test_5()
{
	void *addr;

	addr = malloc(16);
	addr = malloc(512);
	addr = malloc(1024);
	addr = malloc(1024 * 32);
	addr = malloc(1024 * 1024);
	addr = malloc(1024 * 1024 * 16);
	addr = malloc(1024 * 1024 * 128);

	show_alloc_mem();
	return (0);
}


int		main(void) {
	test_1();
	test_2();
	test_3();
	test_3_1();
	test_4();
	test_5();
	return 0;
}
