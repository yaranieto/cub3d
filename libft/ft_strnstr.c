/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:24:57 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/29 12:58:02 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *text, const char *word, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	if (!(*word))
		return ((char *)text);
	if (len == 0)
		return (NULL);
	j = 0;
	while (text[j] && j < len)
	{
		i = 0;
		aux = j;
		while (word[i] && text[aux] == word[i] && aux < len)
		{
			aux++;
			i++;
		}
		if (!word[i])
			return ((char *)text + j);
		j++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *largestring = "gagagagatogagaga";
	const char *smallstring = "gato";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 10);
	printf("%s\n", ptr);

	const char *largestring1 = "gagagagatogagaga";
	const char *smallstring1 = "gato";
	char *ptr1;

	ptr1 = ft_strnstr(largestring1, smallstring1, 10);
	printf("%s\n", ptr1);
	return (0);
}
*/
