/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:40:20 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/25 16:42:59 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(num * size);
	i = 0;
	if (ptr == NULL)
		return (0);
	while (i < num * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	void	*mem;
	size_t	num = 5;
	size_t	size = 1;
	size_t	i;
	
	i = 0;
	mem = ft_calloc(num, size);
	while (i < num * size)
		{
			printf("Result: %d", ((char *)mem)[i]);
			printf("\n");
			i++;
		}
	free(mem);
	return (0);
}
*/
