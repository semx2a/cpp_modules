/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:07 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 15:07:40 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

#include <iostream>
#include <string>
using namespace std;



int main(int ac	, char **av) {

	if (ac != 2) {
		std::cout << "Usage: ./RPN \"arg\"" << std::endl;
		return (1);
	}
	
	RPN	rpn(av[1]);	

	return (0);
}