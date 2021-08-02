#include "../../includes/minishell.h"

static int	cmd_len(char *s, char c, int k)
{
	int	i;
	int	q;
	int	dq;

	i = 0;
	q = 0;
	dq = 0;
	while (s[k] && (s[k] != c || (s[k] == c && (q == 1 || dq == 1))
			|| (s[k] == c && q == 0 && prev_bslash(s, k, q))))
	{
		q_dq_index(s, k, &q, &dq);
		k++;
		i++;
	}
	return (i);
}

static void	ft_freee(char **s, int j)
{
	if (j > 0)
	{
		while (j >= 0)
		{
			free(s[j]);
			s[j--] = NULL;
		}
		free(s);
		s = NULL;
	}
}

static void	fill_str(char *s, char c, char **tab2, t_it *i)
{
	while (s[i->k] && (s[i->k] != c || (s[i->k] == c && (i->q == 1 || i->dq
					== 1)) || (s[i->k] == c && i->q == 0
				&& prev_bslash(s, i->k, i->q))))
	{
		tab2[i->j][i->i++] = s[i->k];
		q_dq_index(s, i->k++, &i->q, &i->dq);
	}
	tab2[i->j++][i->i] = '\0';
}

static char	**fill_tab(char *s, char c, char **tab2)
{
	t_it	i;

	init_zero(&i.j, &i.k);
	while (s[i.k])
	{
		i.i = 0;
		tab2[i.j] = malloc(sizeof(char) * (cmd_len(s, c, i.k) + 1));
		if (!tab2[i.j])
		{
			ft_freee(tab2, i.j);
			tab2 = NULL;
			return (tab2);
		}
		init_zero(&i.q, &i.dq);
		fill_str(s, c, tab2, &i);
		while (s[i.k] && s[i.k] == c)
			i.k++;
	}
	tab2[i.j] = 0;
	return (tab2);
}

char	**shell_split(char *s, char c)
{
	char	**tab2;

	tab2 = malloc(sizeof(char *) * (shell_split_cmd_cnt(s, c) + 1));
	if (!*s || !tab2)
		return (NULL);
	while (*s && *s == c)
		s++;
	tab2 = fill_tab(s, c, tab2);
	if (tab2 == NULL)
		return (NULL);
	return (tab2);
}
