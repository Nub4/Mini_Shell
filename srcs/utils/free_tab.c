#include "../../includes/minishell.h"

void	free_tab(char ***tab2)
{
	int	i;

	i = -1;
	while (tab2[0][++i])
	{
		free(tab2[0][i]);
		tab2[0][i] = NULL;
	}
	free(tab2[0]);
	tab2[0] = NULL;
}
