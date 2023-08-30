/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:59 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/26 20:23:41 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/iter.hpp"

void 	print(int const &x)
{
	std::cout << x << std::endl;
}

int main (void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	iter(arr, 5, print);
	return (0);
}