/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:07:20 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 16:23:41 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Display.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

void	displayHeader(std::string color, std::string title) {

	std::stringstream	buf;

	buf << color << std::setfill(':') << std::setw(59); 
	buf << title << NO_COLOR << std::endl;

	std::cout << buf.str();
}

int	main( void ) {
	
	srand(time(NULL)); // initialize randm number generator

	try {
		Intern	RandomIntern;
		
		AForm *	rrf = RandomIntern.makeForm("robotomy request", "Bender");
		AForm *	scf = RandomIntern.makeForm("shrubbery creation", "Bender");
		AForm *	ppf = RandomIntern.makeForm("presidential pardon", "Bender");
	//	AForm *	unknown = RandomIntern.makeForm("unknown", "Bender");

		std::cout << *rrf << std::endl;
		std::cout << *scf << std::endl;
		std::cout << *ppf << std::endl;
	//	std::cout << *unknown << std::endl;
	
		delete rrf;
		delete scf;
		delete ppf;
	}
	catch (std::exception &e) {

		std::cerr << e.what() << NO_COLOR << std::endl;
	}

	return 0;
}
