#include <iostream>
#include <limits>
#include <string>

using namespace std;

bool isNumber(const string& str, bool position = true){
    if (str.empty()) return false;
    size_t start = 0;
    if (position){
        start = (str[0] == '-') ? 1 : 0;
        if (str.size() == start) return false;
    }
    for (size_t i = start; i < str.size(); ++i){
        if(!isdigit(str[i])) return false;
    }
    return true;
}

bool checkString(string& str, bool position = true){
    getline(cin, str);
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    if (!isNumber(str, position))
    return false;

    return true;
}

int main(){
    cout << "Task 16.2!\n_____________________\n";
    cout << "Enter integer part of a number:";
    string integer;
    string fractional;
    
    if (!checkString(integer, true)){
        cerr << "Invalid input.";
        return 1;
    }
    cout << "Enter fractional part of a number:";
    if (!checkString(fractional, false)){
        cerr << "Invalid input.";
        return 1;
    }
    string result = integer + "." + fractional;
    double resultDouble = stod(result);
    cout << resultDouble;
    return 0;
}