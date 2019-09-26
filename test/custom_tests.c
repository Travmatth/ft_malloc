// #include <stdio.h>
// #include <stdint.h>
// #include <string.h>
#include "../includes/malloc.h"

int	test_cpy() {
	int *arr = malloc(sizeof(int*))
		, *next = malloc(sizeof(int) * 5);

	arr = malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
	ft_memcpy(next, arr, sizeof(int) * 5);
	for (int i = 0; i < 5; i++) {
		if (next[i] != i) {
			return (1);
		}
	}
	return (0);
}

int test_take_next_free() {
	int *first = malloc(sizeof(int));
	*first = 42;
	int *second = malloc(sizeof(int));
	*second = 24;
	if (*first != 42 || *second != 24)
		return 1;
	free(first);
	int *third = malloc(sizeof(int));
	*third = 22;
	if (*first != 22 || *second != 24)
		return 1;
	return 0;
}

int	test_split_next_free() {
	size_t *first = malloc(sizeof(size_t));
	*first = 42;
	int *second = malloc(sizeof(int));
	*second = 24;
	if (*first != 42 || *second != 24)
		return 1;
	free(first);
	int *third = malloc(sizeof(int));
	*third = 22;
	if (*third != 22 || *second != 24)
		return 1;
	int *fourth = malloc(sizeof(int));
	*fourth = 99;
	if (*third != 22 || *fourth != 99 || *second != 24)
		return 1;
	return 0;
}

int	test_skip_next_free() {
	int *first = malloc(sizeof(int));
	*first = 42;
	int *second = malloc(sizeof(int));
	*second = 24;
	if (*first != 42 || *second != 24)
		return 1;
	free(first);
	size_t *third = malloc(sizeof(size_t));
	*third = 22;
	if (*third != 22 || *second != 24)
		return 1;
	return 0;
}

int		(*funcs[4])(void) = {
	test_cpy,
	test_take_next_free,
	test_split_next_free,
	test_skip_next_free,
};

int		main(void) {
	for (int i = 0; i < 6; i++) {
		if (funcs[i]()) {
			return 1;
		}
	}
	return 0;
}
