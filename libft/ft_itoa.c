/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 09:51:57 by minummin          #+#    #+#             */
/*   Updated: 2021/04/22 16:19:13 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*word;
	int		i;
	int		count;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_words(n);
	word = malloc(sizeof(char) * count + 1);
	if (!word)
		return (NULL);
	if (n < 0)
	{
		word[0] = '-';
		n = n * -1;
	}
	i = count;
	while (n > 0)
	{
		word[--i] = n % 10 + '0';
		n = n / 10;
	}
	word[count] = '\0';
	return (word);
}
