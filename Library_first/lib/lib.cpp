#include <string>

extern "C" __declspec(dllexport) bool FindL(const char* userInput, const char* searchSymbols) {
    std::string str(userInput);
    std::string chars(searchSymbols);

    for (char c : chars) {
        if (str.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}