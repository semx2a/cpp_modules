/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:59:27 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/23 17:32:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void ) {

	std::string		Brain("HI THIS IS BRAIN");

	std::string*	stringPTR = &Brain;
	std::string&	stringREF = Brain;

	std::cout << "Brain\t\taddress: " << &Brain << "\t\tvalue: " << Brain << std::endl;
	std::cout << "stringREF\taddress: " << &stringREF << "\t\tvalue: " << stringREF << std::endl;
	std::cout << "stringPTR\taddress: " << stringPTR << "\t\tvalue: " << *stringPTR << std::endl;

	return 0;
}
