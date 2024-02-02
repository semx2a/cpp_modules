/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:10:58 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 12:55:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <algorithm>
# include <map>

# include <cstdlib>

# include "tools.hpp"
# include "print.hpp"

typedef std::map<std::string, float> t_map;

class BitcoinExchange {
	
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const);
		BitcoinExchange(BitcoinExchange const &);
		~BitcoinExchange();
		
		BitcoinExchange &	operator=(BitcoinExchange const &);
		
		std::string	getInputPath(void) const;
		std::string	getDatabasePath(void) const;
		t_map 		getDataBase(void) const;

		void		setInputPath(std::string const);
		void		setDatabasePath(std::string const);
		void		setDataBase(t_map const);
		
		void 	displayValuePrice(void);
		
			
	private:
		std::string			_inputPath;
		std::string			_databasePath;
		std::ifstream		_file;
		std::stringstream	_buffer;
		t_map				_dataBase;
		
		float			_getExchangeRate(std::string const);
		bool			_checkValue(float const);
		bool			_checkDate(std::string const);
		void			_makeMap();
		void			_openFile(std::string const &);
		void			_parseDatabase(std::string const &);
};

std::ostream & operator<<(std::ostream &, BitcoinExchange const &);

#endif