/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/14 17:38:43 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	handle_unlink(t_pipd *pipd)
{
	if (pipd->has_infile == 0 && pipd->has_here_doc == 0)
		unlink(pipd->infile);
	if (pipd->has_here_doc == 1)
		unlink("temp");
}
