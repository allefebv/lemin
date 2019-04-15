/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:58:24 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/15 14:19:57 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	**ft_bfs(t_room **room, t_lem lem)
{
	t_room		**shortest_path;
	t_room		*tmp_r;
	t_room		*tmp_r2;
	t_neighbor	*tmp_n;
	int			i;

	i = 0;
	while (i < lem.nb_room)
	{
		room[i]->visited = 0;
		i++;
	}
	tmp_r = lem.start_room;
	tmp_r->source = NULL;
	tmp_r2 = tmp_r;
	tmp_r2->visited = 1;
	ft_printf("\n\n");
	while (tmp_r2 != lem.end_room)
	{
		tmp_n = tmp_r->neighbor;
		while (tmp_n != NULL
				&& (((t_room*)tmp_n->room)->visited == 1 || tmp_n->flow == 1))
			tmp_n = tmp_n->next;
		while (tmp_n != NULL)
		{
			if(((t_room*)(tmp_n->room))->visited == 0 && tmp_n->flow != 1)
			{
				tmp_r2->next = tmp_n->room;
				tmp_r2 = tmp_r2->next;
				tmp_r2->visited = 1;
				tmp_r2->source = tmp_r;
				//ft_printf("tmp_r = %s /\\ tmp_r2 = %s /\\ tmp_r2_source = %s\n", tmp_r->name, tmp_r2->name, tmp_r2->source->name);
				tmp_r2->next = NULL;
			}
			tmp_n = tmp_n->next;
		}
		tmp_r = tmp_r->next;
		if (tmp_r == NULL)
			return (NULL);
		//ft_printf("tmp_r = %s /\\ tmp_r2 = %s\n", tmp_r->name, tmp_r2->name);
	}
	tmp_r = tmp_r2;
	i = 1;
	while (tmp_r2->source != NULL)
	{
		tmp_r2 = tmp_r2->source;
		i++;
	}
	shortest_path = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	shortest_path[i] = 0;
	i--;
	tmp_r2 = tmp_r;
	while (i >= 0)
	{
		shortest_path[i] = tmp_r2;
		tmp_r2 = tmp_r2->source;
		i--;
	}
	return (shortest_path);
}
