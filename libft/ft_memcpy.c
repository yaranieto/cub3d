/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:41:25 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/05/02 13:13:28 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	void	*src = "Hola mundo";
	char	str[20] = "Hola mundo";
	char	dest[20];
	size_t 	n;
	
	n = 5;
	ft_memcpy(dest, (char *)src, n);
	dest[n]= '\0';
	printf("Result:%s", dest);
	printf("\n");
	ft_memcpy(str + 2, str, 5); //overlap
	printf("Result:%s", str);
	return (0);
}
*/
