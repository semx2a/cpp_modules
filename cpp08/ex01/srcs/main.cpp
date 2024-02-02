/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:40:29 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/06 11:36:57 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

#include <iostream>

#include <cstdlib>
#include <ctime>

#define RANDOM ((rand() % 1000000000000) + 1)

int main(int ac, char **av) {
	
	if (ac == 6) {
		Span sp = Span(ac - 1);
		try {
			sp.addNumber(atoi(av[1]));
			sp.addNumber(atoi(av[2]));
			sp.addNumber(atoi(av[3]));
			sp.addNumber(atoi(av[4]));
			sp.addNumber(atoi(av[5]));
			
			std::cout << sp << std::endl;
			std::cout << "shortest span: "<< sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "addNumber: " << e.what() << std::endl;
		}
	}
	else {
		srand(time(NULL));
		Span sp = Span(10000);
		try {
			for (int i = 0; i != 10000; i++)
				sp.addNumber(RANDOM);
					
			std::cout << sp << std::endl;
			std::cout << "shortest span: "<< sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "addNumber: "  << e.what() << std::endl;
		}
		Span improved = Span(5);
		int arr[] = {5, 3, 17, 9, 11};
		std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

		try {
			improved.addNumber(v.begin(), v.end());

			std::cout << improved << std::endl;
			std::cout << "shortest span: "<< improved.shortestSpan() << std::endl;
			std::cout << "longest span: " << improved.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "improved addNumber: " << e.what() << std::endl;
		}
		try {
			improved.addNumber(20); // throws an exception due to the span size being too small

			std::cout << improved << std::endl;
			std::cout << "shortest span: "<< improved.shortestSpan() << std::endl;
			std::cout << "longest span: " << improved.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "improved addNumber: " << e.what() << std::endl;
		}
	}	
	
	return 0;
}