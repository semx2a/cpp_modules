/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:59:27 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/16 21:45:42 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
	
	std::clog << "PhoneBook successfully created." << std::endl;
	std::clog << std::endl;
	
	return ;
}

PhoneBook::~PhoneBook( void ) {

	std::clog << "PhoneBook successfully destroyed." << std::endl;
	std::clog << std::endl;
	
	return ;
}

Contacts	*PhoneBook::getContact( int index ) {

	return &this->_form[index];
}

int	PhoneBook::getNbInst( void ) {
	
	return PhoneBook::_nbInst;
}

void	PhoneBook::createContact( void ) {

	static int overflow_index = 0;
	
	if (PhoneBook::getNbInst() < 8) {

		this->_form[PhoneBook::getNbInst()].setFields();
		this->_form[PhoneBook::getNbInst()].setData();
		PhoneBook::_nbInst += 1;
	}
	else {

		if (overflow_index >= 8)
			this->_form[overflow_index % 8].setData();
		else
			this->_form[overflow_index].setData();
		overflow_index += 1;
	}	
}

int	PhoneBook::_nbInst = 0;