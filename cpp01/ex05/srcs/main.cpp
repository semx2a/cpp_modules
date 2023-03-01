/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:53 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 20:04:57 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "../inc/Harl.hpp"

int	main() {
	
	Harl		Harl;
	void		(Harl::*ptr)( std::string level );

	std::cout << std::endl << "\033[1;33m[FUNCTION CALLS]\033[m" << std::endl;

	Harl.complain("DEBUG");
	Harl.complain("INFO");
	Harl.complain("WARNING");
	Harl.complain("ERROR");
	Harl.complain("");
	
	std::cout << std::endl << "\033[1;35m[FUNCTION POINTERS]\033[m" << std::endl;
	
	ptr = &Harl::complain;
	
	(Harl.*ptr)("DEBUG");
	(Harl.*ptr)("INFO");
	(Harl.*ptr)("WARNING");
	(Harl.*ptr)("ERROR");
	(Harl.*ptr)("");
	
	return 0;
}