#include "../malloc.h"

int		main() {
	size_t	num = 2;
	void	*ptr = (void*)&num;

	nomalloc_log(2, "");
	nomalloc_log(2, "simple");
	nomalloc_log(2, "pre%");
	nomalloc_log(2, "pre%d", (int)num);
	nomalloc_log(2, "pre%zu", num);
	nomalloc_log(2, "pre%p", ptr);
	nomalloc_log(2, "pre%dfoo", (int)num);
	return 0;
}
