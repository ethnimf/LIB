#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

typedef bool(*CheckSymbolsFunc)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "Russian");

    HINSTANCE hDynamicLib = LoadLibrary(L"lib.dll");
    if (!hDynamicLib) {
        cerr << "Не удалось загрузить библиотеку" << endl;
        return 1;
    }

    CheckSymbolsFunc checkSymbols = (CheckSymbolsFunc)GetProcAddress(hDynamicLib, "FindL");
    if (!checkSymbols) {
        cerr << "Функция не найдена в библиотеке" << endl;
        FreeLibrary(hDynamicLib);
        return 1;
    }

    string userInput, searchSymbols;
    do {
        cout << "Введите строку: ";
        getline(cin, userInput);
    } while (userInput.empty());

    cout << "Введите символы для поиска: ";
    cin >> searchSymbols;

    bool symbolsFound = checkSymbols(userInput.c_str(), searchSymbols.c_str());
    if (symbolsFound) {
        cout << "Символы найдены" << endl;
    }
    else {
        cout << "Символы не найдены" << endl;
    }

    FreeLibrary(hDynamicLib);
    return 0;
}
