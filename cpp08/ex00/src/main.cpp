/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:07:56 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 14:23:35 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

#include <vector>
#include <list>
#include <map>
#include <deque>

#include <iostream>
#include <sstream>
#include <string>

#include <cstdlib>
#include <ctime>

#define RANDOM ((rand() % 15) + 1)
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
	std::cout << std::endl;
}

template <typename T>
void	printArr(T &arr, size_t size) {
	
	std::stringstream s;
	s << "Array: " << "size = " << size << std::endl;
	for (size_t i = 0; i < size; i++) {
		if (i == 0)
			s << '{';
		
		s << arr[i];
		
		if (i + 1 != size)
			s << ", ";
		else
			s << '}';
	}
	s << std::endl << "--------------------------" << std::endl;
	std::cout << s.str() << std::endl;
}

void	printList(std::list<int> &l) {
	
	
	std::stringstream s;
	s << "List: " << "size = " << l.size() << std::endl;
	size_t size = 0;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
		if (it == l.begin())
			s << '{';
		
		s << *it;
		
		if (size + 1 != l.size())
			s << ", ";
		else
			s << '}';
		size++;
	}
	s << std::endl << "--------------------------" << std::endl;
	std::cout << s.str() << std::endl;
}


int main() {

	std::vector<int> 	v;
	std::list<int> 		l;
	std::deque<int>		d;
	
	srand(time(NULL));
	
	for (int i = 0; i < 5; i++) {
		v.push_back(RANDOM);
		l.push_back(RANDOM);
		d.push_back(RANDOM);
	}

	printArr(v, v.size());

	printList(l);
	printArr(d, d.size());

	tryNcatch("vector", v, RANDOM);
	tryNcatch("list", l, RANDOM) ;
	tryNcatch("deque", d, RANDOM);
	
	return 0;
}