/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_loop_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:26:20 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/15 18:30:19 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	get_loop_start(t_pipd *pipd)
{
	if (pipd->has_here_doc == 1)
		pipd->k = 3;
	else if (pipd->has_infile == 0)
		pipd->k = 3;
	else
		pipd->k = 2;
}
