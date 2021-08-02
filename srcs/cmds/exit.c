#include "../../includes/minishell.h"

int	ft_strisnum(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			return (0);
	return (1);
}

void	ft_exit_2(char **words, t_v **v, t_ls *data)
{
	int	tmp;

	if (words[1] && !words[2])
	{
		tmp = ft_atoi(words[1]);
		if (tmp > 255)
			tmp = tmp % 256;
		printf("exit\n");
		ft_free_all(data, v);
		exit(tmp);
	}
	else
	{
		printf("exit\n");
		ft_free_all(data, v);
		exit(0);
	}
}

void	ft_exit(char **words, t_v **v, t_ls *data)
{
	if (words[1] && words[2] && ft_strisnum(words[1]) == 1)
	{
		data->statuscode = 500;
		ft_printf_fd(2, "exit\nminishell: exit: too many arguments\n");
		return ;
	}
	if (words[1] && ft_strisnum(words[1]) == 0
		&& words[1][0] != '-' && words[1][0] != '+')
	{
		ft_printf_fd(2,
			"exit\nminishell: exit: %s: numeric argument required\n", words[1]);
		ft_free_all(data, v);
		exit(128);
	}
	ft_exit_2(words, v, data);
}
