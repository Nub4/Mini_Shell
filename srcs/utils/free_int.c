#include "../../includes/minishell.h"

void	free_int(int **i)
{
	free(i[0]);
	i[0] = NULL;
}

void	free_tab_int(int ***i)
{
	int	j;

	j = 0;
	while (i[0][j])
		free(i[0][j++]);
	free(i[0]);
}
