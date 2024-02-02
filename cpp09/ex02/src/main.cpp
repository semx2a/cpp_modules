/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:31:42 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/11 18:11:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main(int ac, char **av) {
	
	if (ac < 2 || av[1][0] == '\0') {
		
		std::cout << "Usage: ./PmergeMe [list of numbers]" << std::endl;
		return 1;
	}
	
	try {
		PmergeMe PMM(ac, av);
		PMM.sort();
		PMM.isSorted(VECTOR);
		PMM.isSorted(LIST);
		std::cout << PMM;
	}
	catch (std::runtime_error &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
    
    return 0;
}


