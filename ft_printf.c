/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:32:10 by nromito           #+#    #+#             */
/*   Updated: 2023/11/02 18:35:22 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_cases(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_putadrs(va_arg(args, unsigned long long));
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len += ft_putuns(va_arg(args, unsigned int));
	if (c == 'x')
		len += ft_itoa_blow(va_arg(args, unsigned long long));
	if (c == 'X')
		len += ft_itoa_bup(va_arg(args, unsigned long long));
	if (c == '%')
	{
		write(1, '%', 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	va_list	args;
	int	len;

	len = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_cases(args, s[i + 1]);
			i++;
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
}

ciao %c o