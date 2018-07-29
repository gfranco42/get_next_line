#include <stdio.h>
#include <stdlib.h>

char*	function(char *line)
{
	line = malloc(3);
	line[0] = 'a';
	line[1] = 'b';
	line[2] = '\0';
	return (line);
}

int		main(int ac, char **av)
{
	char	*line = NULL;

	line = function(line);
	printf("%s\n", line);
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl	*begin_list = NULL;

	if (!begin_list)

}


typedef struct s_gnl
{
	int		fd;
	char	*rest;
	struct s_gnl *next;
}				t_gnl;

static char *rest = NULL;
