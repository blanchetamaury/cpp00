/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:10:20 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 15:26:22 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact add_phonebook(Contact contact)
{
	std::cout << "NAME : ";
	std::cin >> contact.name;
	std::cout << "LAST_NAME : ";
	std::cin >> contact.last_name;
	std::cout << "NICKNAME : ";
	std::cin >> contact.nickname;
	std::cout << "PHONE_NUMBER : ";
	std::cin >> contact.phone_number;
	std::cout << "DARKEST_SACRET : ";
	std::cin >> contact.darkest_secret;
	return (contact);
}

void	print_case(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i >= 9)
			break ;
		std::cout << str[i];
		i++;
	}
	if (i >= 9)
		std::cout << ".";
	else
	{
		while (i++ < 10)
			std::cout << " ";
	}
	std::cout << "|";
}

void print_contact(Contact contact)
{
	print_case(contact.name);
	print_case(contact.last_name);
	print_case(contact.nickname);
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	print_header_tab(void)
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	print_full_contact(Contact contact)
{
	std::cout << "NAME : " << contact.name << std::endl;
	std::cout << "LAST_NAME : " << contact.last_name << std::endl;
	std::cout << "NICKNAME : " << contact.nickname << std::endl;
	std::cout << "PHONE_NUMBER : " << contact.phone_number << std::endl;
	std::cout << "DARKEST_SACRET : " << contact.darkest_secret << std::endl;
}

int main(int argc, char **argv)
{
	std::string arg("");
	Phonebook book;
	int i;
	int	j;
	int	total;
	std::string index("");
	std::string str("12345678");

	(void)argv;
	if (argc > 1)
		return (0);
	i = 0;
	total = 0;
	while (1)
	{
		std::cout << "ACTION : ";
		std::cin >> arg;
		if (arg == "ADD")
		{
			if (i == 8)
				i = 0;
			book.tab[i] = add_phonebook(book.tab[i]);
			i++;
			total++;
		}
		if (arg == "SEARCH")
		{
			print_header_tab();
			j = 0;
			while (j < 8 && j < total)
			{
				std::cout << "|" << str[j] << "         |";
				print_contact(book.tab[j]);
				j++;
			}
			std::cout << "INDEX: ";
			std::cin >> index;
			j = 0;
			while (index[0] != str[j])
				j++;
			if (j < 8 && j < total && index[1] == '\0')
				print_full_contact(book.tab[j]);
			else
				std::cout << "ERROR: index not found" << std::endl;
		}
		if (arg == "EXIT")
			break ;
	}
}