#include "../../includes/minishell.h"

int	tab_cnt(char **tab2)
{
	int	i;

	i = 0;
	while (tab2[i])
		i++;
	return (i);
}
