/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:48:59 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/30 17:14:13 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*is_int_min(void)
{
	char	*alpha;

	alpha = malloc(12 * sizeof(char));
	alpha[0] = '-';
	alpha[1] = '2';
	alpha[2] = '1';
	alpha[3] = '4';
	alpha[4] = '7';
	alpha[5] = '4';
	alpha[6] = '8';
	alpha[7] = '3';
	alpha[8] = '6';
	alpha[9] = '4';
	alpha[10] = '8';
	alpha[11] = '\0';
	return (alpha);
}

char	*ft_itoa(int n)
{
	size_t				i;
	unsigned int		is_negative;
	char				*alpha;

	if (n == -2147483648)
		return (is_int_min());
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	i = ft_len(n) + 1;
	alpha = malloc ((i - 1 + is_negative + 1) * sizeof(char));
	if (!alpha)
		return (NULL);
	alpha[i - 1 + is_negative] = '\0';
	while (--i > 0)
	{
		alpha[i - 1 + is_negative] = n % 10 + '0';
		n /= 10;
	}
	if (is_negative)
		alpha[0] = '-';
	return (alpha);
}
/*
#include <stdio.h>

int	main(void) 
{
    int num = -456136861;
    char *result = ft_itoa(num);
    printf("Resultado: %s\n", result);  
    free(result); 
    return 0;
}
*/
