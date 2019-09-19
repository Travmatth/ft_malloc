#include <stdlib.h>

void show_alloc_mem(void);

int main()
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
