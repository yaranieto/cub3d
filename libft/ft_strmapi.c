/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:48:45 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/27 17:18:59 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	ft_function(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c - 'a' + 'A');
	return (c);
}

#include <stdio.h>

int main(void)
{
    char str[] = "hola";

    char *result = ft_strmapi(str, &ft_function);

    if (result)
	{
        printf("Cadena modificada: %s\n",result);
        free(result);
    } 
	else 
	{
        printf("Error en la función.\n");
    }

    return (0);
}
	*/