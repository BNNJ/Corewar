/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:48:35 by amanuel           #+#    #+#             */
/*   Updated: 2019/04/06 02:15:12 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_tablen(void **tab)
{
	int			i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}
