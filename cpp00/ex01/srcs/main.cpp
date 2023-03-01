/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:47 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/17 18:08:30 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

char	ft_putnbr( int nb ) {
	
	if (nb >= 0 && nb < 10)
		return nb + '0';
	else if (nb < 0)
		return '0';
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return '0';
}

void	printLine( void ) {
		
	for (int x = 0; x < 45; x++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	
}

void	printTitle( void ) {
	
	for (int x = 0; x < 35; x++) {
		std::cout << ":";
	}
	
	std::cout << "CONTACTS::" << std::endl;
}

void	printFields( std::string *stab ) {
	
	std::cout << "|";

	for (int i = 0; i < 4 && stab[i].empty() == false; i++) {
		
		std::cout << std::setw(10);
		if (stab[i].length() > 10) {
			stab[i].resize(9);
			std::cout << stab[i] + ".";
		}
		else
			std::cout << stab[i];
		std::cout << "|";
	}
	std::cout << std::endl;
}

void setFields( PhoneBook *Repertoire, std::string *stab, int i ) {
		
		for (int j = 0; j < 4; j++) {
			
			stab[j].clear();
			if (j == 0)
				stab[j] = ft_putnbr(i + 1);
			else
				stab[j] = Repertoire->getContact(i)->getData(j - 1);
		}
}

void	whichContact( PhoneBook *Repertoire ) {
	
	std::string	input;
	int			index;

	std::cout << "Enter the desired contact index: ";
	std::getline (std::cin, input);
	std::cout << std::endl;

	if (input.empty() == false) {
		index = atoi(input.c_str());
		if (index <= 0 || index > Repertoire->getNbInst()) {
			std::cerr << "Please enter a valid index." << std::endl;
			std::cout << std::endl;
			return ;
		}
		index--;
		if (index < 8) {
			for (int i = 0; i < 5; i++) {
				
				std::cout << Repertoire->getContact(index)->getField(i) 
				<< Repertoire->getContact(index)->getData(i) << std::endl;	
			}
		}
	}
	std::cout << std::endl;
}

void	listContacts( PhoneBook *Repertoire ) {

	std::string stab[4] = {"Index",
							"First name",
							"Last name",   
							"Nickname"};
							
	std::cout << std::endl;

	printTitle();
	if (Repertoire->getNbInst() == 0) {
		std::cerr << "Please create a contact first." << std::endl;
		std::cout << std::endl;
		return ;
	}
	printLine();
	printFields(stab);
	printLine();
	
	for (int i = 0; i < Repertoire->getNbInst(); i++) {;
		setFields(Repertoire, stab, i);
		printFields(stab);
		printLine();
	}
	
	whichContact(Repertoire);
}

int	main( void ) {
 	
 	PhoneBook	Repertoire;
	std::string	arg;

	while (std::cout << "Enter your request (ADD|SEARCH|EXIT): "
			&& std::getline (std::cin, arg)) 
	{	
		if (!arg.compare("ADD"))
			Repertoire.createContact();
		else if (!arg.compare("SEARCH"))
			listContacts(&Repertoire);
		else if (!arg.compare("EXIT"))
			break ;
	}
	return 0;
}
