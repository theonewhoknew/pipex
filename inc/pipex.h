#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_data
{	
	char *infile_path;
	int infile_fd;
	char *outfile_path;
	char outfile_fd;
	char **cmd_1;
	char *cmd1_fullpath;
	char *cmd2_fullpath;
	char **cmd_2;
	char **args_1;
	char **args_2;
	char **paths;
}				t_data;

void	init_pipex(int argc, char **argv, char **envp, t_data *data);
void	check(char **argv, t_data *data);
int		parse_cmds(char **argv, t_data *data);
void 	execute(t_data *data);

#endif