/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:59 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/31 17:23:02 by seozcan          ###   ########.fr       */
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

int main (void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	std::cout << "print array:" << std::endl;
	iter(arr, 5, print);
	std::cout << std::endl << "shift array:" << std::endl;
	iter(arr, 5, shift);
	std::cout << std::endl << "print array:" << std::endl;
	iter(arr, 5, print);
	return (0);
}