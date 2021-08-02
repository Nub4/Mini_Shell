#include "../../includes/minishell.h"

void	child_signal_handler(int signr)
{
	if (signr == SIGINT)
		signal(SIGINT, child_signal_handler);
}

void	main_signal_handler(int signr)
{
	if (signr == SIGINT)
	{
		if (g_sigint == 3)
			ft_printf_fd(1, "\n");
		else
			ft_printf_fd(1, "\n");
		g_sigint = 1;
		ft_print_prompt_3(g_sigint);
		g_sigint = 0;
	}
	else if (signr == SIGQUIT)
	{
		if (g_sigint == 3)
			ft_printf_fd(2, "Quit: %d\n", signr);
		else
			return ;
	}
}
