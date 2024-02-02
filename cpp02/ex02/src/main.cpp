/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:45:36 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/03 12:29:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

int main(void) {
	
	Fixed 		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << "max is " << Fixed::max(a, b) << std::endl;
	std::cout << "min is " << Fixed::min(a, b) << std::endl << std::endl;


	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	
	return 0;
}