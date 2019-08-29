/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:17:00 by yocapell          #+#    #+#             */
/*   Updated: 2019/08/28 22:05:54 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_char
{
	char vide;
	char obstacle;
	char plein;
}				t_char;

typedef struct	s_check_read
{
	int nb_col;
	int nb_line;
	int nb_tot;
	int tmp;
}				t_check_read;

typedef struct	s_biggest_sqr
{
	int x;
	int y;
	int value;
}				t_biggest_sqr;

#endif
