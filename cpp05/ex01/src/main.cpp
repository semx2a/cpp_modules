/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:07:20 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/Display.hpp"

void	displayHeader(std::string color, std::string title) {

	std::stringstream	buf;

	buf << color << std::setfill(':') << std::setw(59); 
	buf << title << RESET << std::endl;

	std::cout << buf.str();
}

void	test(Bureaucrat& cog, Form& form) {

	displayHeader(BHIGREEN, "THE ADMINISTRATION IS INTRODUCING A NEW FORM::");
	std::clog << form << std::endl;
	std::cout << std::endl;
	
	displayHeader(BHIORANGE, "THE MAILMAN HAS FORMS FOR YOU::");
	std::clog << cog << " receives a pile of forms to sign." << std::endl;
	std::cout << std::endl;
	
	displayHeader(BHIPURPLE, "BUREAUCRAT IS ATTEMPTING TO SIGN FORMS::");
	cog.signForm(form);
	std::cout << std::endl;
}

int	main(int ac, char **av) {
	
	srand(time(NULL)); // Random number generation initialization
	Bureaucrat	cog("Marvin");
	
	if (ac >= 1 && ac <= 4) {
		
		try {
		
			if (ac == 1) {
				Form	form;
				test(cog, form);
			}
			else if (ac == 2 && *av[1] != '\0') {
				Form	form(av[1]);
				test(cog, form);
			}
			else if (ac == 4 && *av[1] != '\0') {
				Form	form(av[1], atoi(av[2]), atoi(av[3]));
				test(cog, form);
			}
		}
		catch (std::exception &e) {
			displayHeader(BHIRED, "ERROR::");
			std::cerr << e.what() << std::endl;
		}
	}
	else  {

		displayHeader(BHIRED, "ERROR::");
		std::cerr << "Usage: ./Bureaucrat [name] (optional)[{1..150}] [{1..150}]" << std::endl;
	}	
	return 0;
}
