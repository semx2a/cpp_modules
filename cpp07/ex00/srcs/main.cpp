/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:13:19 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/01 13:30:03 by seozcan          ###   ########.fr       */
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

/* class Awesome {
	public:
	Awesome(void) : _n(0) {}
	Awesome(int n) : _n(n) {}
	Awesome &operator=(Awesome &a) {this->_n = a._n; return (*this);}
	bool operator==(Awesome const &a) const {return (this->_n == a._n);}
	bool operator!=(Awesome const &a) const {return (this->_n != a._n);}
	bool operator>(Awesome const &a) const {return (this->_n > a._n);}
	bool operator<(Awesome const &a) const {return (this->_n < a._n);}
	bool operator>=(Awesome const &a) const {return (this->_n >= a._n);}
	bool operator<=(Awesome const &a) const {return (this->_n <= a._n);}
	int getN(void) const {return (this->_n);}
	private:
	int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome const &a) {o << a.getN(); return (o);}

int main(void) {
	
	Awesome a(1), b(2);

	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << min(a, b) << std::endl;
	return 0;
}
 */

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