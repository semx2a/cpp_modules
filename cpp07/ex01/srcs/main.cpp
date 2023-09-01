/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:59 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/01 14:07:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/iter.hpp"

template <typename T>
void 	print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void 	shift(T const &x)
{
	std::cout << (x << 1) << std::endl;
}

/* class Awesome {
	public:
	Awesome(void) : _n(42) { return;}
	int get(void) const {return (this->_n);}
	private:
	int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome const &a) {o << a.get(); return (o);}
 */
int main (void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	std::cout << "print array:" << std::endl;
	iter(arr, 5, print);
	std::cout << "shift array:" << std::endl;
	iter(arr, 5, shift);
	std::cout << "print array:" << std::endl;
	iter(arr, 5, print);

/* 	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	
	std::cout << "print array:" << std::endl;
	iter(tab, 5, print);
	std::cout << "print array:" << std::endl;
	iter(tab2, 5, print);
 */
	return (0);
}