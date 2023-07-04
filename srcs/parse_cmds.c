#include "../inc/pipex.h"
#include "../libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

static int look_for_cmd1(char *cmd, t_data *data)
{	
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		cmd_path = ft_strjoin("/", cmd);
		full_path = ft_strjoin(data->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{	
			data->cmd1_fullpath = full_path;
			return (0);
		}
		i++;
	}
	
}

static int look_for_cmd2(char *cmd, t_data *data)
{	
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		cmd_path = ft_strjoin("/", cmd);
		full_path = ft_strjoin(data->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{	
			data->cmd2_fullpath = full_path;
			return (0);
		}
		i++;	
	}
}

int parse_cmds(char **argv, t_data *data)
{
	if (look_for_cmd1(data->args_1[0], data) == 1)
		return (1);
	if (look_for_cmd2(data->args_2[0], data) == 1)
		return (1);
	return (0);
}