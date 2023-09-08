/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:10:58 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/08 00:16:18 by seozcan          ###   ########.fr       */
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

		void	checkDate(void);
		void	checkValue(void);
		void	parseFile(void);
		void	displayValuePrice(void);
		
			
	private:
		std::string					_filePath;
		std::string					_data;
		std::ifstream				_file;
		std::map<std::string, int>	_ExchangeRate; 
};

std::ostream & operator<<(std::ostream &, BitcoinExchange const &);

#endif