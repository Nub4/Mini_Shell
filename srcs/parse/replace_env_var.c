#include "../../includes/minishell.h"

char	*ft_replace_3(char *tmp_end, char *lol,
		char *tmp_middle, char *tmp_begin)
{
	char	*word;
	int		res;

	res = check_spechar(tmp_end[0]);
	if (res == 1 || *lol == '?')
	{
		word = ft_strjoin2(tmp_begin, tmp_middle);
		word = ft_strjoin2(word, tmp_end);
		free(tmp_end);
		if (*lol == '?')
			free(tmp_middle);
		return (word);
	}
	else if (res == 4)
	{
		tmp_end++;
		return (tmp_end);
	}
	else
		return (tmp_end);
}

char	*ft_replace_2(char *word, t_v *v, int j, t_ls *data)
{
	char	*temp;
	char	*tmp_middle;
	char	*tmp_end;

	if (*data->lol == '?')
	{
		tmp_middle = ft_itoa(data->statuscode);
		tmp_end = ft_substr(word, j + 1, ft_strlen(word));
	}
	else
	{
		tmp_middle = NULL;
		while (v->next)
		{
			temp = ft_strstr_reverse(v->str, "=");
			if (ft_strncmp(data->lol, temp, data->i) == 0)
				tmp_middle = ft_strstr_2(v->str, "=");
			free(temp);
			v = v->next;
		}
		tmp_end = ft_substr(word, j, ft_strlen(word));
	}
	return (ft_replace_3(tmp_end, data->lol, tmp_middle, data->tmp_begin));
}

char	*ft_replace(char *word, t_v *v, int j, t_ls *data)
{
	int	n;

	data->i = 0;
	data->lol = word;
	if (!data->lol)
		ft_error(data, &v);
	n = j + 1;
	data->tmp_begin = ft_substr(word, 0, j);
	while (--n >= 0)
		data->lol++;
	if (ft_isalpha(word[++j]) == 1)
	{
		data->i++;
		while (ft_isalnum(word[++j]) == 1)
			data->i++;
	}
	return (ft_replace_2(word, v, j, data));
}

int	change_variable(t_ls *data, t_v *v, int j, int i)
{
	char	*tmp;

	tmp = ft_replace(data->words2[i], v, j, data);
	free_string(&data->words2[i]);
	data->words2[i] = tmp;
	return (0);
}

void	replace_env_var(t_ls *data, t_v *v)
{
	int		i;
	int		j;
	int		q;
	int		dq;

	i = -1;
	while (data->words2[++i])
	{
		j = -1;
		q = 0;
		dq = 0;
		while (data->words2[i][++j])
		{
			if (data->words2[i][0] == '~' && (data->words2[i][1] == '/'
				|| data->words2[i][1] == '\0'))
				j = change_home(data, i, v);
			if (data->words2[i][j] == '$' && data->words2[i][j + 1] != '\0'
					&& q == 0)
				if (!prev_bslash(data->words2[i], j, q))
					j = change_variable(data, v, j, i);
			q_dq_index(data->words2[i], j, &q, &dq);
		}
	}
}
