/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:41:54 by amaury            #+#    #+#             */
/*   Updated: 2025/08/22 14:37:42 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setName(std::string new_name) { name = new_name; }
void Contact::setLastName(std::string new_last_name) { last_name = new_last_name; }
void Contact::setNickname(std::string new_nickname) { nickname = new_nickname; }
void Contact::setPhoneNumber(std::string new_phone_number) { phone_number = new_phone_number; }
void Contact::setDarkestSecret(std::string new_darkest_secret) { darkest_secret = new_darkest_secret; }

std::string Contact::getName(void) { return name; }
std::string Contact::getLastName(void) { return last_name; }
std::string Contact::getNickname(void) { return nickname;}
std::string Contact::getPhoneNumber(void) { return phone_number;}
std::string Contact::getDarkestSecret(void) { return darkest_secret; }

void Contact::printContact(void) {
    std::cout << "NAME : " << name << std::endl;
	std::cout << "LAST_NAME : " << last_name << std::endl;
	std::cout << "NICKNAME : " << nickname << std::endl;
	std::cout << "PHONE_NUMBER : " << phone_number << std::endl;
	std::cout << "DARKEST_SACRET : " << darkest_secret << std::endl;
    std::cout << std::endl;
}

Contact::Contact(void) {
    name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}