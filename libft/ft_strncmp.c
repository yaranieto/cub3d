/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:47 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/28 18:43:08 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	result1;
	int	result2;

	result1 = ft_strncmp("hola", "hola", 4);
	result2 = ft_strncmp("Mundo", "mundo", 1);
	printf ("Result: %d\n", result1);
	printf ("Result: %d", result2);
	return (0);
}
*/