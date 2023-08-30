/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:39:46 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/28 18:05:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"


int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	
	ScalarConverter sc(av[1]);
	sc.convert();


/* 	(void)ac, (void)av;

	char c = 42.0f;
	int i = c;
	float f = c;
	double d = c;

	std::cout << "c = " << c << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "d = " << d << std::endl; */
	
	return (0);
}