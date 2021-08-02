#include "../../includes/minishell.h"

int	prev_bslash(char *s, int k, int q)
{
	int	i;

	i = 0;
	if (q == 1)
		return (0);
	while (--k >= 0 && s[k] == '\\')
		i++;
	return (i % 2);
}
