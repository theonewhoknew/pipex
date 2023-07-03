#include "../inc/pipex.h"
#include "unistd.h"

void execute(t_data *data)
{
	execve(data->cmd1_fullpath, data->args_1, NULL);
}