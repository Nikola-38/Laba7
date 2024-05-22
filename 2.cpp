#include <iostream>
#include <vector>

using namespace std;

// Функция для парсинга логического выражения
bool parseBoolExpr(const vector<char>& expression, size_t& i) {
    bool result = true; // Начальное значение для '&'
    char op = '&'; // Текущий оператор
    bool operand = false; // Текущее значение операнда

    while (i < expression.size()) {
        if (expression[i] == '(') {
            i++; // Пропускаем открывающую скобку
            bool subResult = parseBoolExpr(expression, i); // Рекурсивно вычисляем вложенное выражение
            if (op == '&') {
                result &= subResult;
            } else if (op == '|') {
                result |= subResult;
            } else if (op == '!') {
                result = !subResult;
            }
        } else if (expression[i] == ')') {
            i++; // Пропускаем закрывающую скобку
            return result;
        } else if (expression[i] == ',' || expression[i] == ' ') {
            i++; // Пропускаем разделитель или пробелы
        } else if (expression[i] == 't') {
            operand = true;
            i++;
        } else if (expression[i] == 'f') {
            operand = false;
            i++;
        } else if (expression[i] == '&') {
            op = '&';
            i++;
        } else if (expression[i] == '|') {
            op = '|';
            i++;
        } else if (expression[i] == '!') {
            op = '!';
            i++;
        }

        if (op == '&') {
            result &= operand;
        } else if (op == '|') {
            result |= operand;
        } else if (op == '!') {
            result = !operand;
        }
    }

    return result;
}

int main() {
    system("chcp 65001");
     vector<char> expression;
    char input;
    while (cin >> input && input != ')') {
        expression.push_back(input);
    }
    size_t i = 0;
    cout << boolalpha; // Выводить булевы значения как true/false
    cout << "Expression result: " << parseBoolExpr(expression, i) << endl;

    return 0;
}
