/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:48 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/29 17:00:50 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	i;
	char	*s;

	s = (char *)src;
	count = 0;
	i = 0;
	while (s[count] != '\0')
		count++;
	if (size == 0)
		return (count);
	while (s[i] != '\0' && i < (size - 1))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*src = "Hola mundo";
	char	dest[20];
	int		result;

	result = ft_strlcpy(dest, src, sizeof(dest));
	printf("Result:%d", result);
	return (0);
}
*/