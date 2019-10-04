#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../malloc.h"

int	test_single_malloc()
{
	int	*malloc_1 = (int*)malloc(sizeof(int));
	*malloc_1 = 4;
	return 0;
}

int	test_single_free()
{
	int	*malloc_1 = (int*)malloc(sizeof(int));
	*malloc_1 = 4;
	free(malloc_1);
	return 0;
}

int	test_malloc_requests_additional_bins()
{
	int		pid, ret, val = 0;

	if ((pid = fork()) == 0) {
		close(1);
		close(2);
		void *arr[32] = {0};

		for (int i = 0; i < 32; i++) {
			char *p = (char*)malloc(1024);
			*p = i;
			arr[i] = p;
		}
		char *p_1 = (char*)malloc(1024);
		free(p_1);
		p_1[0] = 'a';
		return 0;
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

int	test_free_doesnt_munmap_initial_bins()
{
	int		pid, ret, val = 0;

	if ((pid = fork()) == 0) {
		close(1);
		close(2);
		char *p = (char*)malloc(1024);
		free(p);
		*p = 'a';
		_exit(0);
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
		return 1;
	}
	return 0;
}

int	test_multi_malloc() {
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

int	test_free_large_single() {
	int		pid, ret, val = 0;

	if ((pid = fork()) == 0) {
		close(1);
		close(2);
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

int	test_free_only_alloced_chunks() {
	free((void*)8);
	void *ptr_1 = malloc(1);
	free(ptr_1);
	void *ptr_2 = malloc(513);
	free(ptr_2);
	void *ptr_3 = malloc(4097);
	free(ptr_3);
	return 0;
}

int	test_show_alloc_mem() {
	void *ptr_1_1 = malloc(1);
	void *ptr_1_2 = malloc(1);
	void *ptr_1_3 = malloc(1);

	void *ptr_2_1 = malloc(513);
	void *ptr_2_2 = malloc(513);
	void *ptr_2_3 = malloc(513);

	void *ptr_3_1 = malloc(4097);
	void *ptr_3_2 = malloc(4097);
	void *ptr_3_3 = malloc(4097);

	show_alloc_mem();
	return 0;
}

# define NUM_TESTS 12

int		(*funcs[NUM_TESTS])(void) = {
	test_single_malloc,
	test_single_free,
	test_malloc_requests_additional_bins,
	test_free_doesnt_munmap_initial_bins,
	test_multi_malloc,
	test_take_next_free,
	test_split_next_free,
	test_skip_next_free,
	test_free_large_single,
	test_coalesce_adjacent,
	test_free_only_alloced_chunks,
	test_show_alloc_mem,
};

int		main(void) {
	for (int i = 0; i < NUM_TESTS; i++) {
		if (funcs[i]()) {
			printf("Error: test %d failed\n", i);
			return 1;
		} else {
			printf("Test %d passed\n", i);
		}
	}
	return 0;
}
