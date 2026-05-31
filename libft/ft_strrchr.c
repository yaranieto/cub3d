/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:47:41 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/28 18:32:59 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "hoala";
	char		*result1;
	char		*result2;

	result1 = ft_strrchr(str, 'a');
	result2 = ft_strrchr(str, 'z');
	printf("Result: %s\n", result1);
	printf("Result: %s", result2);
	return (0);
}
*/