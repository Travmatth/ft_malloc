#include <stdio.h>
#include "../includes/malloc.h"

int		main(void) {
	malloc(1000);
	realloc(NULL, 1000);
	free(NULL);
}
