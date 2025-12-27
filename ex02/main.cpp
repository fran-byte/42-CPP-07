/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:02:06 by frromero          #+#    #+#             */
/*   Updated: 2025/12/27 13:09:36 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

void my_tests()
{
    std::cout << "\n=== MY TESTS ===\n"
              << std::endl;

    std::cout << "1. Empty constructor: empty" << std::endl;
    Array<int> empty;
    std::cout << "   Size: " << empty.size() << std::endl;

    std::cout << std::endl
              << "2. Constructor with size 5:" << std::endl;
    Array<int> five(5);
    std::cout << "   Size: " << five.size() << std::endl;

    std::cout << std::endl
              << "3. Write and read elements:" << std::endl;
    five[0] = 42;
    five[1] = 21;
    five[4] = 84;
    std::cout << "   five[0] = " << five[0] << std::endl;
    std::cout << "   five[1] = " << five[1] << std::endl;
    std::cout << "   five[4] = " << five[4] << std::endl;

    std::cout << std::endl
              << "4. Copy constructor (deep copy test):"
              << std::endl;
    Array<int> copy(five);
    std::cout << "   Original[0] = " << five[0] << std::endl;
    std::cout << "   Copy[0] = " << copy[0] << std::endl;

    std::cout << std::endl
              << "5. Assignment operator:" << std::endl;
    Array<int> assigned;
    assigned = five;
    std::cout << "   Original[4] = " << five[4] << std::endl;
    std::cout << "   Assigned[4] = " << assigned[4] << std::endl;

    std::cout << std::endl
              << "6. Const array access:" << std::endl;
    const Array<int> const_array(five);
    std::cout << "   const_array[1] = " << const_array[1] << std::endl;
    std::cout << "   Size of const_array: " << const_array.size() << std::endl;
    // const_array[1] = 777; // This should NOT compile

    std::cout << std::endl
              << "7. Out of bounds exception tests:" << std::endl;

    std::cout << "   Trying five[5] (index = size): "; // Five index 0 to 4
    std::cout << std::endl
              << "8. Default initialization test (must be zeros):" << std::endl;

    int *dirty = new int[10];
    for (int i = 0; i < 10; i++)
        dirty[i] = 999; // basura
    delete[] dirty;

    Array<int> defaultInit(10);
    std::cout << "   ";
    for (unsigned int i = 0; i < defaultInit.size(); i++)
    {
        std::cout << defaultInit[i];
        if (i < defaultInit.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    try
    {
        five[5] = 0;
        std::cout << "ERROR: Should have thrown exception!" << std::endl; // in not OK
    }
    catch (const std::exception &e)
    {
        std::cout << "OK: Exception caught: " << e.what() << std::endl; // is ok
    }

    std::cout << "   Trying five[-1] (negative index): ";
    try
    {
        five[-1] = 0;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "OK: Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

int main(int, char **)
{

    my_tests();

    std::cout << "=== RUNNING ORIGINAL SUBJECT TESTS ===" << std::endl;

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror;
    return 0;
}