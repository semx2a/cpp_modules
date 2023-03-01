/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:57:17 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/23 17:15:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* Crée un zombie, lui donne un nom 
et le fait se présenter. */	
void randomChump( std::string name ) {
	
	Zombie	Stack = Zombie(name);

	Stack.announce();
}
