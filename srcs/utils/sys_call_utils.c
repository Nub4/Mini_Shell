#include "../../includes/minishell.h"

int	print_err_child(t_ls *data)
{
	struct stat	stats;

	if (data->words2[0])
	{
		if (ft_strchr(data->words2[0], '/'))
		{
			if (!stat(data->words2[0], &stats))
			{
				ft_printf_fd(2,
					"minishell: %s: is a directory\n", data->words2[0]);
				return (1);
			}
			else
				ft_printf_fd(2,
					"minishell: %s: No such file or directory\n",
					data->words2[0]);
		}
		else
			ft_printf_fd(2,
				"minishell: %s: command not found\n", data->words2[0]);
	}
	return (0);
}
