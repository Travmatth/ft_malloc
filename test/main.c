#include <stdio.h>
#include "../includes/malloc.h"

int		main(void) {
// #ifdef __DEBUG__
// 	printf("HERE");
// #else
// 	printf("NOT");
// #endif
	malloc(1000);
	realloc(NULL, 1000);
	free(NULL);
}
