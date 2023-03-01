/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:56:24 by pbergero          #+#    #+#             */
/*   Updated: 2023/02/25 13:59:49 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

typedef struct s_entity_counter{
	int	x;
	int	y;
	int	barrel;
	int	mage;
	int	ghost;
	int	demon;
	int	golem;

}	t_entity_counter;

#endif 