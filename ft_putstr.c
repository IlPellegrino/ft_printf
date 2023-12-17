/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:18:15 by nromito           #+#    #+#             */
/*   Updated: 2023/12/17 15:38:34 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		s = "(null)";
	str = malloc((sizeof(char) * (ft_strlen(s)) + 1));
	if (!str)
		return (0);
	ft_strcpy(str, s);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free (str);
	return (i);
}
