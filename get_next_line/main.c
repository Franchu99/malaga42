#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return 0;
}
