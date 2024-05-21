#include <iostream>
#include <stdexcept> // для використання std::invalid_argument
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    double num1, num2, result;
    char operation;

    // Введення першого числа
    cout << "Введіть перше число: ";
    cin >> num1;

    // Введення операції
    cout << "Введіть операцію (+, -, *, /): ";
    cin >> operation;

    // Введення другого числа
    cout << "Введіть друге число: ";
    cin >> num2;

    // Виконання арифметичної операції
    try {
        switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                throw invalid_argument("Помилка: ділення на нуль.");
            }
            result = num1 / num2;
            break;
        default:
            throw invalid_argument("Помилка: невідома операція.");
        }

        // Виведення результату
        cout << "Результат: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }

    // Виведення інформації про програму та автора
    cout << "Проект: Калькулятор для арифметичних операцій" << endl;
    cout << "Автор: Туна Деніз Мехметович" << endl;
    cout << "Завдання: Виконання операцій (+, -, *, /) над двома числами" << endl;

    return 0;
}
