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
#include "../inc/Display.hpp"

void	displayHeader(std::string color, std::string title) {

	std::stringstream	buf;

	buf << color << std::setfill(':') << std::setw(59); 
	buf << title << RESET << std::endl;

	std::cout << buf.str();
}

void	test(Bureaucrat& cog) {

	displayHeader(BHIGREEN,"THE ADMINISTRATION IS HIRING NEW STAFF::");
	std::cout << cog;
	std::cout << std::endl << std::endl;

	displayHeader(BHIORANGE, "BUREAUCRAT ONBOARDING::");
	cog.upperEchelon();
	std::cout << cog << std::endl;
	cog.lowerEchelon();
	std::cout << std::endl;
	
	displayHeader(BHIPURPLE, "BUREAUCRAT PROMOTIONS::");
	std::cout << cog;
	std::cout << std::endl;
}

int	main(int ac, char **av) {
	
	srand(time(NULL)); // Random number generation initialization

	if (ac >= 2 && ac <= 3) {
		
		try {
			
			if (ac == 2 && *av[1] != '\0') {
					Bureaucrat cog(av[1]);
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
