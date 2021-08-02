#include "../../includes/minishell.h"

static int	error_check(t_ls *data, int i)
{
	if (i > 2)
	{
		if (i > 4)
			i = 4;
		ft_printf_fd(2, "minishell:  syntax error near unexpected token `");
		while (i-- > 2)
			printf(">");
		printf("'\n");
		data->statuscode = 2;
		return (1);
	}
	return (0);
}

int	too_many_redir_out(t_ls *data, char *s)
{
	int	i;
	int	j;
	int	q;
	int	dq;

	j = 0;
	q = 0;
	dq = 0;
	while (s[j])
	{
		i = 0;
		while (s[j] == '>' && q == 0 && dq == 0 && !prev_bslash(s, j, q))
		{
			i++;
			q_dq_index(s, j++, &q, &dq);
		}
		if (error_check(data, i))
			return (1);
		if (i == 0)
			q_dq_index(s, j++, &q, &dq);
	}
	return (0);
}

int	redir_out_at_start(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '>')
		return (1);
	return (0);
}

void	trim_filename(t_ls *data, t_v **v)
{
	char	*tmp;

	tmp = d_dq_trim_pad_str(data->ro.filename[0]);
	if (!tmp)
		ft_error(data, v);
	free(data->ro.filename[0]);
	data->ro.filename[0] = tmp;
	tmp = bslash_trim_str(data->ro.filename[0]);
	if (!tmp)
		ft_error(data, v);
	free(data->ro.filename[0]);
	data->ro.filename[0] = tmp;
}
