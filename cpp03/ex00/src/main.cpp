/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:26:44 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 14:23:44 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "../inc/ClapTrap.hpp"

int	main(int ac, char **av) {

	if (ac != 3) { 
		
		std::cout << "usage: ./bin <attack damage points> <attack damage points>" << std::endl;
		return 1;
	}
	
	ClapTrap	A("Alex");
	ClapTrap	B("Sam");
	
	A.setAttackDamage(atoi(av[1]));
	B.setAttackDamage(atoi(av[2]));	
	
	std::cout << A;
	std::cout << B;
	std::cout << std::endl;
	
	A.attack(B.getName());
	if (A.getEnergyPoints() > 0) {
		
		B.takeDamage(A.getAttackDamage());
	}
	
	std::cout << std::endl;
	B.beRepaired(2);
	
	std::cout << std::endl;
	B.attack(A.getName());
	if (B.getEnergyPoints() > 0) {
		
		A.takeDamage(B.getAttackDamage());
	}

	std::cout << std::endl;
	A.beRepaired(3);

	std::cout << std::endl;
	std::cout << A;
	std::cout << B;
	
	std::cout << std::endl;
	
	return 0;
}