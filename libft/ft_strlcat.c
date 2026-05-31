/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:09:41 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/29 14:39:05 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < destsize && dest[i] != '\0')
		i++;
	while (src[count] != '\0')
		count++;
	if (i >= destsize)
		return (destsize + count);
	while (src[j] != '\0' && (i + j + 1) < destsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest [i + j] = '\0';
	return (i + count);
}
/*
#include <string.h>
#include <stdio.h>

int main() {
    char dest[20] = "Hello";
    char src[] = "abcdefghijklmnopqrstuvwxyz";
    size_t result = ft_strlcat(dest, src, 70);
    printf("Cadena final: %s\n", dest);
    printf("Resultado: %zu\n", result);
    printf("dest: %s\n", dest);
    return 0;
}
*/