/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:39:46 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/04 15:55:32 by seozcan          ###   ########.fr       */
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

	return (0);
}