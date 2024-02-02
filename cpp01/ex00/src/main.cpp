/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:59:27 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/23 17:15:44 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main( void ) {

	Zombie	*tmp;
	
	tmp = newZombie("Heap");
	tmp->announce();
	
	randomChump("Stack");

	delete tmp;
	
	return 0;
}
