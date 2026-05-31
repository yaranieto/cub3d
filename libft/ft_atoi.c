/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:58 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/05/02 12:51:59 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	printf("%d\n", atoi("42"));
	printf("%d\n", atoi(" -456"));
	printf("%d\n", atoi("+42abc"));
	printf("%d\n", atoi("--+42"));
	printf("%d\n", atoi("2147483647"));
	printf("%d\n", atoi("-2147483648000222222222222222222"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi(" -456"));
	printf("%d\n", ft_atoi("+42abc"));
	printf("%d\n", ft_atoi("--+42"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-21474836480002222222222222222222222"));
	return (0);
}
*/
