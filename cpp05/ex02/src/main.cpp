/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:07:20 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/24 14:53:23 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Display.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void	displayHeader(std::string color, std::string title) {

	std::stringstream	buf;

	buf << color << std::setfill(':') << std::setw(59); 
	buf << title << NO_COLOR << std::endl;

	std::cout << buf.str();
}

void	test(Bureaucrat& cog) {

	ShrubberyCreationForm	SCForm;
	RobotomyRequestForm		RRForm;
	PresidentialPardonForm	PPForm;
		
	displayHeader(BHIGREEN, "THE ADMINISTRATION IS INTRODUCING NEW FORMS::");
	std::clog << SCForm << std::endl;
	std::clog << RRForm << std::endl;
	std::clog << PPForm << std::endl;
	std::cout << std::endl;

	displayHeader(BHIORANGE, "HR IS MAKING SURE ALL EMPLOYEES ARE PRESENT::");
	std::clog << cog << std::endl;
	std::cout << std::endl;
	
	displayHeader(BHIBLUE, "THE BUREACRATS ARE SIGNING THE FORMS::");
	cog.signForm(SCForm);
	cog.signForm(RRForm);
	cog.signForm(PPForm);
	std::cout << std::endl;

	displayHeader(BHIBLUE, "THE BUREACRATS ARE TRYING TO EXECUTE THE FORMS::");
	cog.executeForm(SCForm);
	cog.executeForm(RRForm);
	cog.executeForm(PPForm);
	std::cout << std::endl;
}

int	main(int ac, char **av) {
	
	srand(time(NULL)); // initialize randm number generator
	
	if (ac >= 2 && ac <= 3) {
		
		try {
		
			if (ac == 2 && *av[1] != '\0') {
				
				Bureaucrat	cog(av[1]);
				test(cog);
			}
			else if (ac == 3 && *av[1] != '\0' && av[2]) {
				Bureaucrat cog(av[1], atoi(av[2]));
				test(cog);
			}
		}
		catch (std::exception &e) {
			displayHeader(BHIRED, "ERROR::");
			std::cerr << e.what() << std::endl;
		}
	}
	else {
		
		displayHeader(BHIRED, "ERROR::");
		std::cerr << "Usage: ./Bureaucrat [name] (optional)[{1..150}]" << std::endl;
	}

	return 0;
}
