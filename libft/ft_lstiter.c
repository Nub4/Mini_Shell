/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:40:26 by minummin          #+#    #+#             */
/*   Updated: 2021/04/03 14:40:28 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_2(t_v *v)
{
	while (v)
	{
		if (v->str)
			printf("%s\n", v->str);
		v = v->next;
	}
}