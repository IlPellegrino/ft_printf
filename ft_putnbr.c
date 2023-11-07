/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:37:51 by nromito           #+#    #+#             */
/*   Updated: 2023/11/07 19:21:47 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	digit;
	long	i;
	int		count;

	count = 0;
	i = nb;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	digit = 48 + (i % 10);
	if (i >= 10)
		ft_putnbr(i / 10);
	count += write(1, &digit, 1);
	return (count);
}
