/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:47:54 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/01 14:29:30 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_hash(char *str, int size)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	result = 0;
	j = 1;
	while (str[i] != 0)
	{
		result = result + ((int)str[i] * j);
		i++;
		j = j + 2;
	}
	result = result % size;
	return (result);
}
