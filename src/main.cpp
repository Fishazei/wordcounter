#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

/**
 * Проверка, является ли символ разделителем слов
 * Разделители: пробельные символы и знаки препинания
 */
bool isWordDelimiter(char c) {
    // Пробельные символы
    if (isspace(c)) return true;
    // Знаки препинания, которые могут быть разделителями
    const string punctuation = ".,!?;:-()\"'[]{}<>/\\|@#$%^&*+=~`";
    return punctuation.find(c) != string::npos;
}
/**
 * Проверка, является ли символ частью слова
 * Буквы, цифры и дефис внутри слова
 */
bool isWordChar(char c, bool isFirstChar, char prevChar) {
    // Буквы и цифры всегда часть слова
    if (isalnum(c)) return true;

    // Дефис и апостроф могут быть частью слова, если они внутри слова
    // и окружены буквами/цифрами
    if ((c == '-' || c == '\'') && !isFirstChar && isalnum(prevChar)) {
        return true;
    }

    return false;
}
/**
 * Функция для подсчета количества слов в строке
 * @param str входная строка
 * @return количество слов
 */
int countWords(const string& str) {
    int wordCount = 0;
    bool inWord = false;
    int wordLength = 0;
    char prevChar = '\0';

    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];

        if (isWordDelimiter(c)) {
            // Завершаем слово, если были внутри
            if (inWord) {
                wordCount++;
                inWord = false;
                wordLength = 0;
            }
            prevChar = c;
        }
        else if (isWordChar(c, wordLength == 0, prevChar)) {
            // Символ может быть частью слова
            if (!inWord) {
                inWord = true;
                wordLength = 1;
            }
            else {
                wordLength++;
            }
            prevChar = c;
        }
        else {
            // Символ не является частью слова
            if (inWord) {
                wordCount++;
                inWord = false;
                wordLength = 0;
            }
            prevChar = c;
        }
    }

    // Проверяем последнее слово
    if (inWord) {
        wordCount++;
    }

    return wordCount;
}
/**
 * Проверка входных данных
 */
bool validateInput(const string& str) {
    const size_t MAX_LENGTH = 1000;
    if (str.length() > MAX_LENGTH) {
        cout << "Err! Too many symbols" << endl;
        return false;
    }
    return true;
}
/*  */
int main(int argc, char* argv[]) {
    string input;
    // Проверяем аргументы командной строки
    if (argc > 1) {
        // Объединяем все аргументы в одну строку
        for (int i = 1; i < argc; ++i) {
            if (i > 1) input += " ";
            input += argv[i];
        }
    }
    else {
        // Интерактивный режим
        cout << "type line: ";
        getline(cin, input);
        if (cin.fail()) {
            cout << "Err! Input error" << endl;
            return 1;
        }
    }
    // Валидация строки
    if (!validateInput(input)) {
        return 1;
    }
    // Подсчет слов
    int words = countWords(input);
    cout << "Words in line: " << words << endl;
    return 0;
}
