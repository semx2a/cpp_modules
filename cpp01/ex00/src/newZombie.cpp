/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:55:46 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/16 18:57:40 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* Crée un zombie, lui donne un nom 
et le retourne afin qu’il puisse être utilisé
en dehors de la portée de la fonction */
Zombie* newZombie( std::string name ) {
	
	Zombie*	Heap = new Zombie(name);
	
	return  Heap;
}
