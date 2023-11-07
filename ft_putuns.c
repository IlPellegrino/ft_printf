/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:39:46 by nromito           #+#    #+#             */
/*   Updated: 2023/11/07 17:39:00 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int nb)
{
	char	digit;
	long	i;

	i = nb;
	digit = 48 + (i % 10);
	if (i >= 10)
		ft_putuns(i / 10);
	write(1, &digit, 1);
	return (1);
}
