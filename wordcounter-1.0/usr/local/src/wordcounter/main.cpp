#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;
/**
 * Функция для подсчета количества слов в строке
 * @param str входная строка
 * @return количество слов
 */
int countWords(const string& str) {
    int wordCount = 0;
    bool inWord = false;
    for (char c : str) {
        if (isspace(c)) {
            inWord = false;
        }
        else {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        }
    }
    return wordCount;
}
/**
 * Проверка, что строка не превышает максимальную длину
 * и содержит только допустимые символы
 */
bool validateInput(const string& str) {
    const size_t MAX_LENGTH = 1000;
    if (str.length() > MAX_LENGTH) {
        cout << "Err! To much symbols" << endl;
        return false;
    }
    if (str.empty()) {
        cout << "Err! The string is empty" << endl;
        return false;
    }
    return true;
}
int main() {
    string input;
    cout << "Count words in line" << endl;
    cout << "Enter line: ";
    // Безопасное чтение строки
    getline(cin, input);
    if (cin.fail()) {
        cout << "Err!" << endl;
        return 1;
    }
    if (!validateInput(input)) {
        return 1;
    }
    // Подсчет слов
    int words = countWords(input);
    cout << "Words in line: " << words << endl;
    return 0;
}