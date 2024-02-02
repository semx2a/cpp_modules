/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:13:19 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 11:07:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "../inc/templates.hpp"

template <typename T>
void display(T lhs, T rhs) {
	
	std::stringstream s;
	
	s << "lhs = " << lhs << " rhs = " << rhs << std::endl;
	s << std::setfill('-') << std::setw(50) << "-" << std::endl;
	::swap(lhs, rhs);
	s << "swap(lhs, rhs) = "<< lhs << ", "<< rhs << std::endl;
	s << "min(lhs, rhs) = " << ::min(lhs, rhs) << std::endl;
	s << "max(lhs, rhs) = " << ::max(lhs, rhs) << std::endl;
	s << std::endl;

	std::cout << s.str();
}

int	main(void) {
	
	int a = 1, b = 2;
	float c = 1.1f, d = 2.2f;
	double e = 3.3, f = 3.4;
	std::string g = "strA", h = "strB";

	display(a, b);
	display(c, d);
	display(e, f);
	display(g, h);

	return (0);
}