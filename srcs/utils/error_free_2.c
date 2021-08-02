#include "../../includes/minishell.h"

static void	ft_error_a(t_ls *data)
{
	if (data->words)
		free_tab(&data->words);
	if (data->words1)
		free_tab(&data->words1);
	if (data->words2)
		free_tab(&data->words2);
	if (data->words3)
		free_tab(&data->words3);
	if (data->temp)
		free_string(&data->temp);
	if (data->line)
		free_string(&data->line);
	if (data->c_e)
		free_string(&data->c_e);
	if (data->p.pid)
		free_int(&data->p.pid);
	if (data->p.fd)
		free_tab_int(&data->p.fd);
}

static void	ft_error_b(t_ls *data)
{
	if (data->ro.fd)
		free_int(&data->ro.fd);
	if (data->ro.filename)
		free_tab(&data->ro.filename);
	if (data->ri.fd)
		free_int(&data->ri.fd);
	if (data->ri.filename)
		free_tab(&data->ri.filename);
	if (data->bt.tmp)
		free_string(&data->bt.tmp);
	if (data->bt.rtn)
		free_string(&data->bt.rtn);
	if (data->exp.words)
		free_tab(&data->exp.words);
	if (data->sys.path)
		free_tab(&data->sys.path);
	if (data->sys.temp)
		free_string(&data->sys.temp);
	if (data->sys.cmd)
		free_string(&data->sys.cmd);
	if (data->un.tmp)
		free_string(&data->un.tmp);
	if (data->un.temp)
		free_string(&data->un.temp);
}

void	ft_error(t_ls *data, t_v **v)
{
	ft_lstclear_2(v, ft_memdel);
	ft_error_a(data);
	ft_error_b(data);
	if (data->un2.tmp)
		free_string(&data->un2.tmp);
	if (data->un2.temp)
		free_string(&data->un2.temp);
	ft_printf_fd(2, "Error: %s\n", strerror(errno));
	if (errno == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_free_all(t_ls *data, t_v **v)
{
	ft_lstclear_2(v, ft_memdel);
	ft_error_a(data);
	ft_error_a(data);
	if (data->un2.tmp)
		free_string(&data->un2.tmp);
	if (data->un2.temp)
		free_string(&data->un2.temp);
}
