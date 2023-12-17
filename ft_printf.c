/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:32:10 by nromito           #+#    #+#             */
/*   Updated: 2023/12/17 16:02:17 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_cases(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_putaddr(va_arg(args, uintptr_t), "0123456789abcdef", 0);
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int), 0);
	if (c == 'u')
		len += ft_putuns(va_arg(args, unsigned int), 0);
	if (c == 'x')
		len += ft_put_x(va_arg(args, unsigned int), "0123456789abcdef", 0);
	if (c == 'X')
		len += ft_put_x(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
	if (c == '%')
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		len;

	len = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_cases(args, s[i]);
			i++;
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

// int	main()
// {
// 	// unsigned int s = -9;
// 	int i = ft_printf(" %x ", -1);
// 	printf("%d\n", i);
// 	int j = printf(" %x ", -1);
// 	printf("%d\n", j);
// 	return (0);
// }