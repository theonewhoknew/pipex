#include "../inc/pipex.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void check(char **argv, t_data *data)
{	
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
	{
		ft_printf("bash: %s", data->infile_path);
		perror("");
		return ;
	}

}