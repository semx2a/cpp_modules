/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:07:56 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/01 18:02:53 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

#include <vector>
#include <list>
#include <map>
#include <deque>

#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

extern "C" {
	#include <unistd.h>
}

#define RANDOM ((rand() % 100) + 1)
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <typename T>
void	tryNcatch(std::string str, T &container, int n) {
	
	try {
		std::cout << str << std::endl;
		std::cout << "Looking for " << n << std::endl;
		typename T::iterator it = easyfind(container, n);
		std::cout << GREEN << *it << " found !" << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main() {

	std::vector<int> 	v;
	std::list<int> 		l;
	std::deque<int>		d;
	


	srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		v.push_back(RANDOM);
		l.push_back(RANDOM);
		d.push_back(RANDOM);
	}

	while (1) {
		tryNcatch("vector", v, RANDOM);
		tryNcatch("list", l, RANDOM) ;
		tryNcatch("deque", d, RANDOM);
		sleep(1);
	}
	
	return 0;
}