/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:40:09 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/25 16:11:45 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define ERR_ARGS	"Usage: ./Replace <filename> <string_to_replace> <replacement_string>"
#define ERR_IN		"Error: Could not open "
#define ERR_OUT		"Error: Could not create "
#define ERR_FILE	"Error: File is empty"

int	ft_error( std::string err_msg, std::string obj ) {
	
	std::cerr << err_msg;
	if (obj.size())
		std::cerr << obj;
	std::cerr << "." << std::endl;
	return 1;
}

std::string	ft_replace( std::string buf, char **av) {
	
	if (!*av[2])
		return buf;

	if (*av[2] && *av[3]) {
		
		std::string needle(av[2]);
		std::string exchange(av[3]);
	
		if (needle == exchange)
			return buf;
		
		std::size_t pos = 0;
		while (pos < buf.size()) {
			
			pos = buf.find(needle, pos);
			if (pos != buf.npos) {
				buf.erase(pos, needle.size());
				buf.insert(pos, exchange);
				pos += exchange.size();
			}
		}
	}
	else {
		std::string needle(av[2]);
				std::size_t pos = 0;
		while (pos < buf.size()) {
			
			pos = buf.find(needle, pos);
			if (pos != buf.npos)
				buf.erase(pos, needle.size());			
		}

	}

	return buf;
}

int	ft_outfile( std::string buf, char **av ) {
	
	std::ofstream	outfile;
	std::string		outfile_name;
	
	outfile_name.assign(av[1]);
	outfile_name.append(".replace");
	outfile.open(outfile_name.c_str(), std::ofstream::out | std::ofstream::trunc);
	
	if (!outfile.is_open())
		return ft_error(ERR_OUT, "");
		
	outfile << ft_replace(buf, av);
	outfile.close();
	
	return 0;
}

int	main(int ac, char **av) {

	std::ifstream	infile;

	if (ac != 4)
		return ft_error(ERR_ARGS, "");
		
	infile.open(av[1], std::ios::in);
	
	if (!infile.is_open())
		return ft_error (ERR_IN, av[1]);
		
	std::string buf((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();

	if (!buf.size())
		return ft_error(ERR_FILE, "");
		
	return ft_outfile(buf, av);
}