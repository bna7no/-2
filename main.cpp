#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    std::cout << "Enter the number of elements (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "The list is empty." << std::endl;
        return 0;
    }

    std::list<double> numbers;
    std::cout << "Enter " << n << " real numbers:" << std::endl;

    for (int i = 0; i < n; ++i) {
        double val;
        std::cin >> val;
        numbers.push_back(val);
    }

    // Перевірка умови: чи є хоча б один елемент < -3
    bool hasSmallElement = false;
    for (double x : numbers) {
        if (x < -3.0) {
            hasSmallElement = true;
            break;
        }
    }

    // Модифікація списку згідно з умовою
    if (hasSmallElement) {
        for (double& x : numbers) {
            if (x < 0) {
                x = std::pow(x, 2); // заміна від'ємних на квадрати
            }
        }
    }
    else {
        for (double& x : numbers) {
            x *= 0.1; // множення на 0.1, якщо немає елементів < -3
        }
    }

    // Виведення результату у зворотному порядку
    std::cout << "Result (in reverse order):" << std::endl;
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}