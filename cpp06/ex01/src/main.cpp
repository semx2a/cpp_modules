/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:28:43 by seozcan           #+#    #+#             */
/*   Updated: 2023/08/30 19:04:59 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

int main(void) {
	
	Data 		*data = new Data;
	Serializer 	s;

	data->s = "Hello, World!";
	data->c = 'a';
	data->i = 42;
	data->f = 42.42f;

	std::cout << "Data1 content::" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "s = " << data->s << std::endl;
	std::cout << "c = " << data->c << std::endl;
	std::cout << "i = " << data->i << std::endl;
	std::cout << "f = " << data->f << std::endl;
	
	uintptr_t	*ptr = s.serialize(data);
	Data 		*data2 = s.deserialize(ptr);
	
	std::cout << std::endl << "Data2 content::" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "s = " << data2->s << std::endl;
	std::cout << "c = " << data2->c << std::endl;
	std::cout << "i = " << data2->i << std::endl;
	std::cout << "f = " << data2->f << std::endl;
		
	return 0;
}