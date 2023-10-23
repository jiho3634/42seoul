/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:42 by jihokim2          #+#    #+#             */
/*   Updated: 2023/10/08 12:11:31 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		g_global;

void	ft_init(t_mini *mini, int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	ft_bzero(mini, sizeof(t_mini));
	ft_arrcpy(mini, &mini->envp, envp, 0);
	ft_set_term(mini);
}

int	ft_line(t_mini *mini)
{
	int		i;

	if (!mini->line)
	{
		if (mini->lst)
		{
			ft_err_msg("syntax error", "unexpected end of file", NULL, 0);
			ft_reset(mini);
			return (FALSE);
		}
		write(1, "exit\n", 5);
		ft_error_exit(mini, 0, 0, 0);
	}
	i = 0;
	while (ft_is_space(mini->line[i]))
		i++;
	if (mini->line[i] == '\0')
	{
		add_history(mini->line);
		free(mini->line);
		mini->line = NULL;
		return (FALSE);
	}
	add_history(mini->line);
	return (TRUE);
}

int	ft_parsing(t_mini *mini)
{
	ft_tok(mini, mini->line, 0);
	free(mini->line);
	mini->line = NULL;
	if (ft_syntax(mini, mini->tok, 0))
	{
		ft_free_arr(mini->tok.arr);
		mini->tok.arr = NULL;
		return (FALSE);
	}
	ft_lst(mini);
	if (ft_env(mini, mini->lst) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	ft_exec(t_mini *mini)
{
	t_lst	*lst;

	lst = mini->lst;
	while (lst)
	{
		if (lst->red_in && ft_doc(mini, lst->red_in))
			return ;
		lst = lst->next;
	}
	lst = mini->lst;
	while (lst)
	{
		if (lst->next)
		{
			pipe(lst->bpip);
			lst->next->fpip[0] = lst->bpip[0];
			lst->next->fpip[1] = lst->bpip[1];
		}
		ft_fork(mini, lst);
		lst = lst->next;
	}
	ft_close_pipe(mini->lst);
	ft_waitpid(mini->lst);
	if (ft_is_single_cd_export_unset_exit(mini) == TRUE)
		ft_cd_export_unset_exit_in_parent_process(mini);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	ft_init(&mini, argc, argv, envp);
	while (1)
	{
		ft_signal(SIGQUIT, SIG_IGN);
		ft_signal(SIGINT, ft_handler_sigint);
		mini.line = readline("mysh$ ");
		if (ft_line(&mini) == FALSE)
			continue ;
		if (ft_parsing(&mini) == FALSE)
			continue ;
		ft_exec(&mini);
		ft_reset(&mini);
	}
}
