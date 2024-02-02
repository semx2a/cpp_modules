/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:10:51 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 12:57:09 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

#include "../inc/BitcoinExchange.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	btc(av[1]);
		btc.displayValuePrice();
	}
	catch (std::runtime_error &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
		
	return 0;
}