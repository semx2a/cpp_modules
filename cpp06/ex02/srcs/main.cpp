/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:09:20 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 19:34:29 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

Base * generate(void) {
	
	srand(time(NULL));
	int dice = ((rand() % 3) + 1);

	switch (dice) {
		case 1: {
			std::cout << "class A generated!" << std::endl;
			return new A();
		}
		case 2: {
			std::cout << "class B generated!" << std::endl;
			return new B();
		}
		case 3: {
			std::cout << "class C generated!" << std::endl;
			return new C();
		}
		default:
			return NULL;
	}
	
}

void identify(Base *p) {

	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer to class A identified!" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer to class B identified!" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer to class C identified!" << std::endl;
}

void identify(Base &p) {
	
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to class A identified!" << std::endl;
	}
	catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference to class B identified!" << std::endl;
	}
	catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference to class C identified!" << std::endl;
	}
	catch (std::exception &e) {}
}

int main (void) {

	
	Base *b = generate();
	identify(*b);	
	Base &b2 = *b;
	identify(b2);
	
	delete b;
	
	return 0;
}