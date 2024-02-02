/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:47:12 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 13:26:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

# include <vector>
# include <map>
# include <iostream>
# include <iomanip>

# include "display.hpp"

template <typename KeyType, typename ValueType>
void printMap(const std::map<KeyType, std::vector<ValueType> >& myMap);

template <typename KeyType, typename ValueType>
void printMap(const std::map<KeyType, ValueType>& myMap);

# include "../templates/print.tpp"

#endif
