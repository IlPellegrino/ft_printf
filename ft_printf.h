/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:34:29 by nromito           #+#    #+#             */
/*   Updated: 2023/11/08 17:10:56 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

int			ft_printf(const char *s, ...);
int			ft_putnbr_base(int nbr, char *base);
int			ft_putchar(int c);
int			ft_putadrs(void *nb);
int			ft_putuns(unsigned int nb, int count);
int			ft_putnbr(int nb, int count);
int			ft_putstr(char *s);
char		*ft_strcpy(char *dest, char *src);
int			ft_itoa(int n);

#endif