/*#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	//int		fd;
	char		*line;
	t_list		*lst;

	argc = 2;
	(void)argc;
	line = NULL;
	(void)argv;
	
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	close(fd);
	
	lst = ft_lstnew("aaa", 4);
	free(lst);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int  main(void)
{
	char  *line = NULL;
	int   fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	sleep(15);
	return (0);
}
