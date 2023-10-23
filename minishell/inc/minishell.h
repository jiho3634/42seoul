/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:00:00 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/06 16:43:20 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WORD 1
# define PIPE 2
# define INPUT 3
# define OUTPUT 4
# define APPEND 5
# define HEREDOC 6
# define FT_ERROR 14 

# define FT_ECHO 7
# define CD 8
# define PWD 9
# define EXPORT 10
# define UNSET 11
# define ENV 12
# define EXIT 13

typedef struct s_env
{
	int				i;
	int				j;
	int				flag;
	char			quote;
	int				first;
	int				second;
	int				dollar_index;
	int				val_len;
	int				env_len;
	char			*temp;
	char			*env_ptr;
}	t_env;

typedef struct s_red
{
	struct s_red	*next;
	char			*file;
	char			*doc_no;
	char			*line;
	int				type;
	int				fd;
	int				ofd;
}	t_red;

typedef struct s_lst
{
	struct s_lst	*next;
	char			**cmd;
	char			**path;
	t_red			*red_in;
	t_red			*red_out;
	int				fpip[2];
	int				bpip[2];
	pid_t			pid;
	int				num;
}	t_lst;

typedef struct s_tok
{
	char			**arr;
	char			quote;
	int				flag;
}	t_tok;

typedef struct s_mini
{
	char			*line;
	char			**split;
	char			**envp;
	t_tok			tok;
	t_lst			*lst;
	t_env			env;
	int				stdin;
	int				stdout;
	struct termios	original;
	struct termios	new;
	int				lst_size;
}	t_mini;

extern int	g_global;

void	ft_print_lst(t_mini *mini, t_lst *lst);
void	ft_print_arr_of_str(char **arr);

/*		ft_parsing_sub.c		*/
int		ft_env(t_mini *mini, t_lst *lst);
int		ft_arrlen(char **arr);

/*		ft_doc_exp.c		*/
void	ft_heredoc_child(t_mini *mini, t_red *red);
int		ft_heredoc(t_mini *mini, t_red *red);
int		ft_doc(t_mini *mini, t_red *red);

/*		ft_getenv.c		*/
char	*ft_strchr(char *str, char chr);
char	*ft_getenv(t_mini *mini, char *str);

/*		ft_signal.c		*/
void	ft_handler_nl(int sig);
void	ft_handler_ctrl_back_slash(int sig);
void	ft_handler_sigint(int sig);
void	ft_handler_sigquit(int sig);
void	ft_signal(int sig, void (*new_handler)(int));
void	ft_set_term(t_mini *mini);

// 		ft_utils.c
void	ft_bzero(void *str, size_t size);
void	*ft_calloc(t_mini *mini, size_t count, size_t size);
char	*ft_put_itoa(t_mini *mini, int len, long long num);
char	*ft_set_itoa(t_mini *mini, int nbr);
int		ft_atoi(char *nptr);

// 		ft_str_utils.c
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_strcpy(t_mini *mini, char **dst, char *src, int len);
void	ft_arrcpy(t_mini *mini, char ***dst, char **src, int i);
char	*ft_strdup(t_mini *mini, char *s1, size_t len);

// 		ft_tok.c
int		ft_off_cmd(char *c, t_tok *tok);
int		ft_off_delimeter(char *c, t_tok *tok);
int		ft_off_quote(char *c, t_tok *tok);
int		ft_can_tok(char *c, t_tok *tok);
void	ft_tok(t_mini *mini, char *line, int i);

// 		ft_can_tok_utils.c
int		ft_is_space(char c);
int		ft_is_delimeter(char c);
int		ft_is_quote(char c, char quote);
int		ft_is_cmd(char c, char quote);
void	ft_check_next_quote(char *c, t_tok *tok);

// 		ft_syntax.c
int		ft_is_red(char *str);
int		ft_is_pipe(char c);
int		ft_syntax(t_mini *mini, t_tok tok, int i);

// 		ft_lst.c
int		ft_type_red(char *str);
int		ft_type(char *tok);
void	ft_hub(t_mini *mini, t_lst **lst, int i, int type);
t_lst	*ft_lst_init(t_mini *mini);
int		ft_lst(t_mini *mini);

// 		ft_lst_utils.c
int		ft_lst_size(t_lst *lst);
t_lst	*ft_lst_new(t_mini *mini);
t_lst	*ft_lst_last(t_lst *lst);
t_red	*ft_red_new(t_mini *mini, char **tok_arr, int idx, int type);
t_red	*ft_red_last(t_red *red);

// 		ft_add_to_cmd
void	ft_tok_is_cmd(t_mini *mini, t_lst *lst, int i);
int		ft_tok_is_arg(t_mini *mini, t_lst *lst, int i);
void	ft_add_to_cmd(t_mini *mini, t_lst *lst, int i);
void	ft_add_to_red(t_mini *mini, t_lst *lst, int i, int type);

/*		ft_env_sub.c		*/
int		ft_check_that_this_lst_is_empty_for_pipe(t_lst *lst);
void	ft_exp_cmd(t_mini *mini, t_lst *lst, int i);
void	ft_find_closed_quote_red(t_mini *mini, t_red *red);
int		ft_find_closed_quote(t_mini *mini, t_lst *lst);

/*		ft_find_closed_quote_sub.c		*/
void	ft_noname(t_mini *mini, t_lst *lst, int i, int *j);
void	ft_noname_red(t_mini *mini, t_red *red, int j);

/*		ft_exp_dq_sub.c		*/
int		ft_is_dollar_valid(char c);
void	ft_exp_change_val(t_mini *mini, t_env *env, char **line, int *j);
char	*ft_exp_behind_dollar(t_mini *mini, t_env *env, char **line);
int		ft_exp_cp_val(t_mini *mini, t_env *env, char **line, int *j);
char	*ft_exp_find_dollar(t_mini *mini, t_env *env, char **line);

/*		ft_exp_cmd_sub.c		*/
int		ft_exp_dq(t_mini *mini, char **line, int flag, int j);
void	ft_arr_to_arr(t_mini *mini, t_lst *lst, char **arr, int *idx);

/*		ft_delete_closed_quote.c		*/
void	ft_delete_closed_quote_red(t_mini *mini, t_red *lst);
void	ft_delete_closed_quote(t_mini *mini, t_lst *lst);

// 		ft_env_red.c
char	*ft_copy_behind_dollar_red(t_mini *mini, t_env *env, t_red *red);
int		ft_check_space_in_filename(char *filename);
void	ft_exp_change_val_red(t_mini *mini, t_red *red);
int		ft_copy_and_change_env_red(t_mini *mini, t_env *env, \
									t_red *red, int *j);
char	*ft_find_dollar_sign_red(t_mini *mini, t_red *red);

/*		ft_exec_sub.c		*/
void	ft_fork(t_mini *mini, t_lst *lst);
int		ft_is_single_cd_export_unset_exit(t_mini *mini);
void	ft_cd_export_unset_exit_in_parent_process(t_mini *mini);
void	ft_close_pipe(t_lst *lst);
void	ft_waitpid(t_lst *lst);

/*		ft_fork_sub.c		*/
void	ft_set_pipe(t_mini *mini, t_lst *lst);
void	ft_set_fd(t_mini *mini, t_lst *lst);
int		ft_is_built_in(char *cmd);
void	ft_execve(t_mini *mini, t_lst *lst);
void	ft_exec_built_in(t_mini *mini, t_lst *lst);

/*		ft_execve_sub		*/
int		ft_access(char *cmd, int *flag);
int		ft_is_cmd_filename(char *cmd);
void	ft_execve_absolute_path(t_lst *lst, int flag);
void	ft_execve_env_path(t_mini *mini, t_lst *lst, int flag, int i);

/*		ft_set_fd_sub		*/
void	ft_set_fd_in(t_mini *mini, t_red *red);
void	ft_set_fd_out(t_mini *mini, t_red *red);

// 		ft_exec_utils.c
void	ft_set_path(t_mini *mini, t_lst *lst);
char	*ft_strjoin(t_mini *mini, char *path, char *cmd);
void	ft_split(t_mini *mini, char *path, int j);

/*		ft_exec_heredoc		*/
void	ft_exp_change_val_heredoc(t_mini *mini, t_env *env, t_red *red, int *j);
char	*ft_exp_behind_dollar_heredoc(t_mini *mini, t_env *env, t_red *red);
int		ft_exp_cp_val_heredoc(t_mini *mini, t_env *env, t_red *red, int *i);
void	ft_exp_heredoc(t_mini *mini, t_red *red);
void	ft_heredoc_child(t_mini *mini, t_red *red);

// ft_built_in_cd.c
void	ft_copy_and_change_tilde(t_mini *mini, char **cmd, int i);
void	ft_tilde(t_mini *mini, char **cmd);
int		ft_home(t_mini *mini);
int		ft_is_dir(char *cmd);
int		ft_built_in_cd(t_mini *mini, t_lst *lst);

// ft_built_in_pwd.c
int		ft_built_in_pwd(void);

// ft_built_in_echo.c
int		ft_option_check(char *cmd, int *flag);
void	ft_built_in_echo(t_lst *lst);

// ft_built_in_env.c
void	ft_built_in_env(t_mini *mini);

// ft_built_in_exit.c
int		ft_built_in_exit(t_mini *mini, t_lst *lst);

// ft_built_in_export.c
int		ft_envcmp(t_mini *mini, char *cmd, int i);
int		ft_built_in_export(t_mini *mini, t_lst *lst);

// ft_built_in_unset.c
void	ft_delete_str_in_arr(t_mini *mini, char ***arr, int i);
int		ft_find_env_unset(t_mini *mini, char *cmd);
int		ft_built_in_unset(t_mini *mini, t_lst *lst);

/*		ft_reset.c		*/
void	ft_free(void **ptr);
void	ft_free_arr(char **arr);
void	ft_free_red(t_red *red);
void	ft_free_lst(t_mini *mini);
void	ft_free_env(t_mini *mini);

/*  	ft_err.c		*/
int		ft_syntax_error(t_mini *mini, char *msg, char *c);
void	ft_err_msg(char *cmd, char *msg1, char *msg2, int err);
void	ft_error_exit(t_mini *mini, char *cmd, char *msg1, char *msg2);
int		ft_reset(t_mini *mini);

#endif
