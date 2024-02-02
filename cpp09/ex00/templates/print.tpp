/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:44:00 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 16:28:02 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/print.hpp"

template <typename KeyType, typename ValueType>
void printMap(const std::map<KeyType, std::vector<ValueType> >& myMap) {

    typename std::map<KeyType, std::vector<ValueType> >::const_iterator it;
    
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        
        std::cout << RED << it->first << std::endl;
        
        std::cout << GREEN;
        printVector(it->second);
        std::cout << NO_COLOR << std::endl;
    }
}

template <typename KeyType, typename ValueType>
void printMap(const std::map<KeyType, ValueType>& myMap) {

    typename std::map<KeyType, ValueType>::const_iterator it;
    
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        
        std::cout << RED << it->first << std::endl;
        
        std::cout << GREEN;
        std::cout << it->second << std::endl;
        std::cout << NO_COLOR << std::endl;
    }
}
