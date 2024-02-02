/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:59 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 11:37:28 by seozcan          ###   ########.fr       */
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
	T y = x + 1;
	std::cout << y << std::endl;
}


int main (void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	char c[5] = {'a', 'd', 'g', 'j', 'm'};
	float f[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	
	std::cout << "print array:" << std::endl;
	iter(arr, 5, print);
	std::cout << "shift array:" << std::endl;
	iter(arr, 5, shift);

	std::cout << "print chars:" << std::endl;
	iter(c, 5, print);
	std::cout << "shift chars:" << std::endl;
	iter(c, 5, shift);

	std::cout << "print floats:" << std::endl;
	iter(f, 5, print);
	std::cout << "shift floats:" << std::endl;
	iter(f, 5, shift);

	return (0);
}