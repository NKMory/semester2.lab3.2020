#include<iostream>

int a, b, c;
double function(int j)
{
    j = j > 10 ? 10 : j < -10 ? -10 : j;
    return a * sin(b * j) + (2 / c);
}

int main()
{
    std::cout << "Your function is \"a * sin(b * j) + (2 / c)\"" << std::endl;
    std::cout << "Enter a, b and c: " << std::endl;
    std::cin >> a >> b >> c;
    if (c == 0)
    {
        std::cout << "Wrong number: you can't divide by zero. Restart the program to try again";
        return -1;
    }

    int taskNumber = 0;
    std::cout << "Choose task 1-3" << std::endl;
    std::cout << "Task 1: evaluating the function with a given value" << std::endl;
    std::cout << "Task 2: finding a bigger value of the function" << std::endl;
    std::cout << "Task 3: evaluating functions between two given values" << std::endl;
    std::cin >> taskNumber;

    switch (taskNumber)
    {
        case 1:
        {
            int value;
            std::cout << "Enter the value: " << std::endl;
            std::cin >> value;
            std::cout << "f(" << value << ") = " << function(value) << std::endl;

            break;
        }

        case 2:
        {
            int firstValue, secondValue;
            std::cout << "Enter the first value: " << std::endl;
            std::cin >> firstValue;
            std::cout << "Enter the second value: " << std::endl;
            std::cin >> secondValue;
            std::cout << "The biggest value of the function is " 
                << fmax(function(firstValue), function(secondValue)) << std::endl;

            break;
        }

        case 3:
        {
            int firstValue, secondValue, stepValue;
            std::cout << "Enter value of the step: " << std::endl;
            std::cin >> stepValue;
            std::cout << "Enter the first value: " << std::endl;
            std::cin >> firstValue;
            std::cout << "Enter the second value: " << std::endl;
            std::cin >> secondValue;
            for (int counter = 0; (firstValue + stepValue * counter) < secondValue; ++counter) {
                std::cout << "f( x1 + " << counter << " * step) = " 
                    << function(firstValue + stepValue * counter) << std::endl;
            }
            std::cout << "f( x2 ) = " << function(secondValue) << std::endl;

            break;
        }
    }

    return 0;
}