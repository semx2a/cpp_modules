/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:26:44 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/02 17:21:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(int ac, char **av) {

	ClapTrap	A("Alex");
	ClapTrap	B("Sam");
	ScavTrap	C("Serena");

	if (ac != 3)
		return 1;
		
	A.setAttackDamage(atoi(av[1]));
	B.setAttackDamage(atoi(av[2]));	
	
	std::cout << A;
	std::cout << B;
	std::cout << C;
	std::cout << std::endl;
	
	A.attack(B.getName());
	if (A.getEnergyPoints() > 0)
		B.takeDamage(A.getAttackDamage());
	
	std::cout << std::endl;
	B.beRepaired(2);
	
	std::cout << std::endl;
	B.attack(C.getName());
	if (B.getEnergyPoints() > 0)
		C.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	C.beRepaired(3);
	
	std::cout << std::endl;
	C.attack(A.getName());
	if (C.getEnergyPoints() > 0)
		A.takeDamage(C.getAttackDamage());

	std::cout << std::endl;
	A.beRepaired(3);
	
	std::cout << std::endl;
	C.guardGate();

	std::cout << std::endl;
	std::cout << A;
	std::cout << B;
	std::cout << C;
	
	std::cout << std::endl;
	
	return 0;
}