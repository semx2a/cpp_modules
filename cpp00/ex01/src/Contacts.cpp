/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:11:26 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/16 21:45:49 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

Contacts::Contacts( void ) {

	Contacts::_nbInst += 1;
	
	this->_index = Contacts::_nbInst;

	std::clog << "Contact sheet #" << this->getIndex() << " successfully initialized." << std::endl;
	std::clog << std::endl;

	return ;
}

Contacts::~Contacts( void ) {
	std::clog << "Contact sheet #" << this->getIndex() << " successfully destroyed." << std::endl;
	std::clog << std::endl;
	return ;
}

int	Contacts::getNbInst( void )  {
	
	return Contacts::_nbInst;
}

int	Contacts::getIndex( void ) const { 
	
	return this->_index;
}

std::string Contacts::getField( int index ) const {

	return this->_field[index];
}

std::string Contacts::getData( int index ) const {

	return this->_data[index];
}

void	Contacts::setFields( void ) {
	
	this->_field[0] = "First name : ";
	this->_field[1] = "Last name : ";
	this->_field[2] = "Nickname : ";
	this->_field[3] = "Phone number : ";
	this->_field[4] = "Darkest secret : ";
}

void	Contacts::setData( void ) {
	
	std::cout << std::endl;
	std::cout << "CONTACT #" << this->getIndex() << std::endl;
	
	std::cout << "Please fill-in the fields below." << std::endl;
	
	for (int i = 0; i < 5; i++) {
		
		while (std::cout << this->_field[i]
				&& std::getline (std::cin, this->_data[i])
				&& this->_data[i].empty() == true) {
			std::cout << this->_field[i] << " cannot be empty." << std::endl;
		}
	}
	
	std::cout << this->_data[FIRST_NAME] << " successfully added to your contact list." << std::endl;
	std::cout << std::endl;
}

int	Contacts::_nbInst = 0;
