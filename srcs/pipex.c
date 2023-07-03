#include "../inc/pipex.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[], char **envp)
{
	t_data data;

	init_pipex(argc, argv, envp, &data);
	check(argv, &data);
	parse_cmds(argv, &data);
	execute(&data);
}