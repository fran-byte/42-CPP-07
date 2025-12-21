/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:47:55 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 23:17:24 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int array[] = {100, 200, 300, 400, 500, 600};
    ::iter(array, 6, ::printed<int>);

    const char *arrayStr[] = {
        "one hundred",
        "two hundred",
        "three hundred",
        "four hundred",
        "five hundred",
        "six hundred"};
    ::iter(arrayStr, 6, ::printed<const char *>);

    return 0;
}