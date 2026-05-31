/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:12:04 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:27 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>

int	main (void)
{
	char	str1[20] = "Hola Mundo";
	size_t	i;
	
	ft_bzero(str1, 3);
	i = 0;
	while (i < 20)
	{
		if (str1[i] == '\0')
			printf("[\\0]");
		else
			printf("%c", str1[i]);
		i++;
	}
	return (0);
}
*/
