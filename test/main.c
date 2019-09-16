#include <stdio.h>
#include "../includes/malloc.h"

int		main(void) {
	printf("Here\n");
	malloc(1000);
	realloc(NULL, 1000);
	free(NULL);
}
