/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:49:36 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/29 13:12:36 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	if (start <= end)
		len = (size_t)(end - start + 1);
	else
		len = 0;
	return (ft_substr(s1, start, len));
}
/*
#include <stdio.h>

int main(void)
{
    char    ptr[50] = "*¡hola mundo!*";
    char    *result;

    result = ft_strtrim(ptr, "*¡");

    // Imprime el resultado
    if (result)
    {
        printf("Resultado: '%s'\n", result);
        free(result);
	}
}
*/