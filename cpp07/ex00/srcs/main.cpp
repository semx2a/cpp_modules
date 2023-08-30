/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:13:19 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/26 20:20:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../inc/templates.hpp"

int	main(int ac, char **av) {

	if (ac != 3) {
		std::cout << "Usage: ./templates [a] [b]" << std::endl;
		return (1);
	}
	
	int a = atoi(av[1]), b = atoi(av[2]);

	std::cout << "a = " << a << " b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << " d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	
	return (0);
}