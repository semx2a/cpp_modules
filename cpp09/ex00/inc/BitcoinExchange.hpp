/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:10:58 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/06 23:46:14 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
	
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const);
		BitcoinExchange(BitcoinExchange const &);
		~BitcoinExchange();
		
		BitcoinExchange &	operator=(BitcoinExchange const &);

		void				setFilePath(std::string const);
		void				setData(std::string const);
		
		std::string const &	getFilePath(void) const;
		std::string const &	getData(void) const;
			
	private:
		std::string		_filePath;
		std::string		_data;
		std::map<std::string, int> ExchangeRate; 
};

std::ostream & operator<<(std::ostream &, BitcoinExchange const &);

#endif