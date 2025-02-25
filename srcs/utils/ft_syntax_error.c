/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:30:23 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/30 15:56:11 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_syntax_error(char *str)
{
	if (*str != '+' && *str != '-' && !(*str >= '0' && *str <= '9'))
		return (1);
	if ((*str == '+' || *str == '-') && *(str + 1) == '\0')
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}
