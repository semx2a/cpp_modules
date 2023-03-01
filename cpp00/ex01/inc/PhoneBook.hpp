/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:41 by seozcan           #+#    #+#             */
/*   Updated: 2023/02/16 21:44:48 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contacts.hpp"

class PhoneBook {
	
public:
	PhoneBook (void);
	~PhoneBook (void);
	
	void		createContact (void);
	Contacts	*getContact (int index);

	static int	getNbInst (void);

private:

	static int	_nbInst;
	Contacts 	_form[8];
};

#endif
