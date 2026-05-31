/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:02:30 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/28 19:03:58 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*str2;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	str2 = (char *)malloc(sizeof(char) * (len + 1));
	if (str2 == NULL)
		return (NULL);
	else
	{
		while (str[i] != '\0')
		{
			str2[i] = str[i];
			i++;
		}
	}
	str2[i] = '\0';
	return (str2);
}

/*
#include <stdio.h>

int	main (void)
{
	char	*copy;
	char	*origin;
	
	origin = "Hola Mundo";
	copy = ft_strdup(origin);
	printf("Result: %s", copy);
	free(copy);
	return (0);
}
*/