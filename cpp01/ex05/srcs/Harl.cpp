/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:41:22 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/22 20:50:36 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <iomanip>

Harl::Harl( void ) {
	
	this->list[DEBUG].level = "DEBUG";
	this->list[INFO].level = "INFO";
	this->list[WARNING].level = "WARNING";
	this->list[ERROR].level = "ERROR";
	
	this->list[DEBUG].lvl_ptr = &Harl::debug;
	this->list[INFO].lvl_ptr = &Harl::info;
	this->list[WARNING].lvl_ptr = &Harl::warning;
	this->list[ERROR].lvl_ptr = &Harl::error;

	return ;
}

Harl::~Harl( void ) { 

	return ;
}

void	Harl::debug( void ) {
	
	std::cout << "\033[1m[DEBUG]\033[m ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" 
	<< std::endl;
	
	return ;
}

void	Harl::info( void ) {
	
	std::cout << "\033[1m[INFO]\033[m ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
	<< std::endl;
	
	return ;
}

void	Harl::warning( void ) {

	std::cout << "\033[1m[WARNING]\033[m ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." 
	<< std::endl;
	
	return ;
}

void	Harl::error( void ) {
	
	std::cout << "\033[1m[ERROR]\033[m ";
	std::cout << "This is unacceptable ! I want to speak to the manager now." 
	<< std::endl;

	return ;
}

void	Harl::complain( std::string level ) {

	for (int i = 0; i < 4; i++) {
		
		if (this->list[i].level == level)
			return (this->*list[i].lvl_ptr)();
	}
	std::cout << "\033[1m[UNDEFINED]\033[m ";
	std::cout << "Harl rants but you decide to ignore him." << std::endl;
	
	return ;
}