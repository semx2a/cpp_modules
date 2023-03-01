/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:26:44 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/01 16:30:42 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "../inc/ClapTrap.hpp"

int	main(int ac, char **av) {

	ClapTrap	A("Alex");
	ClapTrap	B("Sam");

	if (ac != 3)
		return 1;
		
	A.setAttackDamage(atoi(av[1]));
	B.setAttackDamage(atoi(av[2]));	
	
	std::cout << A;
	std::cout << B;
	std::cout << std::endl;
	
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	
	std::cout << std::endl;
	B.beRepaired(2);
	
	std::cout << std::endl;
	B.attack(A.getName());
	A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	A.beRepaired(3);

	std::cout << std::endl;
	std::cout << A;
	std::cout << B;
	
	std::cout << std::endl;
	
	return 0;
}