/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:59:59 by nromito           #+#    #+#             */
/*   Updated: 2023/11/10 22:18:47 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(int nb, char *base, int count)
{
	if (!nb)
	{
		count += write(1, "0", 1);
		return (count);
	}
	if (nb >= 16)
		count = ft_putaddr(nb / 16, base, count);
	count += write(1, &base[nb % 16], 1);
	return (count);
}
