/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:39:46 by nromito           #+#    #+#             */
/*   Updated: 2023/11/10 22:23:49 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(uintptr_t nb, char *base, int count)
{
	if (!nb)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	if (count == 0)
		count += write(1, "0x", 2);
	if (nb >= 16)
		count = ft_putaddr(nb / 16, base, count);
	count += write(1, &base[nb % 16], 1);
	return (count);
}
