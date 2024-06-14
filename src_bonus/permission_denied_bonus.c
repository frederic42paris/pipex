/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission_denied_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:11:38 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 13:28:34 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

void	permission_denied(t_pipd *pipd)
{
	if (access(pipd->outfile, F_OK) == 0 && access(pipd->outfile, W_OK) == -1)
		perror(pipd->outfile);
}
