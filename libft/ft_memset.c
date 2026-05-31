/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:36 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/20 18:17:45 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_memset(void *a, int nb, size_t i)
{
	char	*b;

	b = (char *)a;
	while (i > 0)
	{
		*b = nb;
		b++;
		i--;
	}
	return (a);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[20] = "Hola";
	
	ft_memset(str, 'x', 2);
	printf("Result: %s", str);
	return (0);
}
*/
