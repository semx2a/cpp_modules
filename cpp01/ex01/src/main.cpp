/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:59:27 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/27 18:44:51 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main( void ) {

	Zombie	*tmp;
	
	tmp = zombieHorde( 10, "Heap" );

	for (int i = 0; i < 10; i++) {
		
		tmp[i].announce();
	}

	delete [] tmp;
	
	return 0;
}
