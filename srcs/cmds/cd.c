#include "../../includes/minishell.h"

void	ft_newpwd(t_v *v, char *str)
{
	while (v)
	{
		if (ft_strncmp(v->str, "PWD", 3) == 0)
		{
			free(v->str);
			v->str = NULL;
			v->str = ft_strjoin("PWD=", str);
		}
		v = v->next;
	}
}

void	ft_oldpwd(t_v *v)
{
	char	*s;

	s = NULL;
	while (v)
	{
		if (ft_strncmp(v->str, "PWD", 3) == 0)
			s = ft_strdup(ft_strstr_2(v->str, "="));
		if (ft_strncmp(v->str, "OLDPWD", 6) == 0)
		{
			free(v->str);
			v->str = NULL;
			v->str = ft_strjoin("OLDPWD=", s);
		}
		v = v->next;
		if (s)
		{
			free(s);
			s = NULL;
		}
	}
}

void	ft_cd_init(t_ls *data, int *mark, int *i)
{
	data->oldpwd = 1;
	*mark = 0;
	*i = 0;
}

int	ft_cd(char **words, int cd, t_ls *data, t_v **v)
{
	int	i;
	int	mark;

	ft_cd_init(data, &mark, &i);
	while (words[i])
		i++;
	if (!words[1] || ft_strcmp_2(words[1], "~", 1) == 0)
	{
		data->statuscode = 0;
		ft_oldpwd(*v);
		chdir(getenv("HOME"));
		ft_newpwd(*v, getenv("HOME"));
		return (0);
	}
	else if ((!words[2] && chdir(words[1]) == -1) || i > 2)
	{
		mark = 1;
		data->statuscode = 500;
		ft_printf_fd(2, "minishell: cd: %s: %s\n", words[1], strerror(errno));
		if (cd == 0)
			return (2);
	}
	if (mark != 1)
		data->statuscode = 0;
	return (1);
}
