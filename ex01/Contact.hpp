/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:35:27 by amaury            #+#    #+#             */
/*   Updated: 2025/08/21 20:02:33 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
    public:
        Contact();
        void setName(std::string new_name);
        void setLastName(std::string new_last_name);
        void setNickname(std::string new_nickname);
        void setPhoneNumber(std::string new_phone_number);
        void setDarkestSecret(std::string new_darkest_secret);
        std::string getName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);
        void printContact(void); 
    private:
        std::string name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif