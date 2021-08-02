#include "../../includes/minishell.h"

static void	init_int(int *i, int *j, int *q, int *dq)
{
	i[0] = 0;
	j[0] = 0;
	q[0] = 0;
	dq[0] = 0;
}

static void	incre_str(char *s, int *j)
{
	while (s[*j] && s[*j] == '>')
		j[0]++;
	while (s[*j] && s[*j] == ' ')
		j[0]++;
	if (s[*j] && s[*j] == '\'' && !prev_bslash(s, *j, 0))
	{
		j[0]++;
		while (s[*j] && s[*j] != '\'')
			j[0]++;
	}
	if (s[*j] && s[*j] == '\"' && !prev_bslash(s, *j, 0))
	{
		j[0]++;
		while (s[*j] && (s[*j] != '\"' || (s[*j] == '\"'
					&& prev_bslash(s, *j, 0))))
			j[0]++;
	}
	while (s[*j] && s[*j] != ' ')
		j[0]++;
}

static int	trim_len(char *s)
{
	int	i;
	int	j;
	int	q;
	int	dq;

	init_int(&i, &j, &q, &dq);
	while (s[j])
	{
		if (s[j] == '>' && q == 0 && dq == 0 && !prev_bslash(s, j, q))
			incre_str(s, &j);
		else
		{
			i++;
			j++;
		}
		q_dq_index(s, j, &q, &dq);
	}
	return (i);
}

void	redir_trim(t_ls *data, t_v **v, char *line)
{
	char	*tmp;
	int		i;
	int		j;
	int		q;
	int		dq;

	init_int(&i, &j, &q, &dq);
	tmp = malloc(sizeof(char) * (trim_len(line) + 1));
	if (!tmp)
		ft_error(data, v);
	while (line[j])
	{
		if (line[j] == '>' && q == 0 && dq == 0 && !prev_bslash(line, j, q))
			incre_str(line, &j);
		else
			tmp[i++] = line[j++];
		q_dq_index(line, j, &q, &dq);
	}
	tmp[i] = '\0';
	free(data->words3[0]);
	data->words3[0] = tmp;
}
