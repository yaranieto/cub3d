/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:18:03 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/28 18:44:32 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	 main(void)
{
	void	*s = "hola1";
	int		c = 'h';
	size_t	n = 20;
	void	*result;
	
	result = ft_memchr(s, c, n);
	if(result != NULL)
		printf("Result:%c", *(char *)result);
	else
		printf("Not found");
	return (0);
}
*/