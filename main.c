#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char		*line;

	argc = 2;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	//ft_putstr(line);
	//ft_putchar('\n');
	/*while (get_next_line(fd, &line))
	{
		ft_putchar('\n');
		ft_putstr(line);
		ft_putchar('\n');
	}*/
}
