/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:41:16 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/12 10:11:38 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cerr << "error, no argument\n" << std::endl;
        return (1);
    }
    for (int i = 1; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            std::cout << (char)toupper(argv[i][j]);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}