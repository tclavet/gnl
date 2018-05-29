#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <stdlib.h>


int		main(int argc, char **argv)
{
	void	*test;
	size_t	size;
	t_list	*ttest;

	argc = 2;
	size = strlen(argv[0]);
	//ft_memalloc(size);
	test = ft_lstnew(argv[0], size);
	free(test);
}
