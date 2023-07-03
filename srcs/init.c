#include "../inc/pipex.h"
#include "../libft/libft.h"

static void get_args(char **argv, t_data *data)
{
	data->args_1 = ft_split(argv[2], ' ');
	data->args_2 = ft_split(argv[3], ' ');
}

static void get_paths(char **envp, t_data *data)
{
	int i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	data->paths = ft_split(&envp[i][5], ':');
}

void init_pipex(int argc, char **argv, char **envp, t_data *data)
{
	data->infile_path = argv[1];
	get_args(argv, data);
	data->outfile_path = argv[4];
	get_paths(envp, data);
	
}