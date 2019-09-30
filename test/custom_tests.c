#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../malloc.h"

int	test_cpy() {
	int *arr = malloc(sizeof(int*))
		, *next = malloc(sizeof(int) * 5);

	arr = malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
	memcpy(next, arr, sizeof(int) * 5);
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
	if (*third != 22 || *second != 24)
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


int	test_free_large_single() {
	int		pid, ret, val = 0;

	if ((pid = fork()) == 0) {
		void	*large_alloc = malloc(4097);
		*(int*)large_alloc = 4;
		int		result_1 = *(int*)large_alloc + 4;
		free(large_alloc);
		int		result_2 = *(int*)large_alloc + 4;
		_exit(1);
	}
	while ((ret = waitpid(pid, &val, 0)) != pid)
	{
		if (ret != -1)
		{
			break ;
		}
		if (errno == EINTR)
			errno = 0;
	}
	if (WIFSIGNALED(val)) {
		printf("WIFSIGNALED: %d\n", WTERMSIG(val));
		return 0;
	}
	return 1;
}

int	test_coalesce_adjacent() {
	void	*alloc_1 = malloc(sizeof(int));
	size_t	ptr_1 = (size_t)alloc_1;
	void	*alloc_2 = malloc(sizeof(int));
	void	*alloc_3 = malloc(sizeof(int));
	free(alloc_1);
	free(alloc_2);
	void	*alloc_4 = malloc(sizeof(int));
	if ((size_t)alloc_4 == ptr_1) {
		return 0;
	}
	return 1;
}

int		(*funcs[6])(void) = {
	test_cpy,
	test_take_next_free,
	test_split_next_free,
	test_skip_next_free,
	test_free_large_single,
	test_coalesce_adjacent,
};

int		main(void) {
	// test_coalesce_adjacent();
	for (int i = 0; i < 6; i++) {
		if (funcs[i]()) {
			printf("Error: test %d failed\n", i);
			return 1;
		} else {
			printf("Test %d passed\n", i);
		}
	}
	return 0;
}
