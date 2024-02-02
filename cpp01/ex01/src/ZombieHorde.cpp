/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:50:20 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/27 18:44:07 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie*	Horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		Horde[i].setName(name);
	}

	return Horde;
}
