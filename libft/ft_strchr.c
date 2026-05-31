/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:27:51 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/29 16:49:01 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != (char)c)
		i++;
	if (ptr[i] == (char)c)
		return (&ptr[i]);
	else
		return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	result1;
	char	result2;

	result1 = ft_strchr("hola", 'a');
	result2 = ft_strchr("hola", 'z');
	printf("Result: %c\n", result1);
	printf("Result: %c", result2);
	return (0);
}
*/