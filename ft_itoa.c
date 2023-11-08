/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:28 by nromito           #+#    #+#             */
/*   Updated: 2023/11/07 21:18:40 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*recursive(long long i, long long j, char *digit)
{
	if (i < 0)
	{
		i = -i;
		digit[0] = '-';
	}
	if (i > 0)
	{
		digit[--j] = 48 + (i % 10);
		recursive((i / 10), j, digit);
	}
	write(1, &digit, 1);
	return (digit);
}

int	count_num(long long n)
{
	short	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_itoa(int n)
{
	char		*digit;
	long long	nb;
	long long	j;

	nb = n;
	j = count_num(nb);
	if (nb == 0 || nb == -0)
		return (0);
	digit = malloc(sizeof(char) * (j + 1));
	if (!digit)
		return (0);
	if (nb < 0)
	{
		nb = -nb;
		digit[0] = '-';
	}
	digit = recursive(nb, j, digit);
	digit[j] = '\0';
	return (j);
}
