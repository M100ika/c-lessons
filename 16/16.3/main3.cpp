#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    cout << "Task 16.3!\n_________________\n";
    cout << "Enter an expression in the format <number1><operator><number2>: ";
    string buffer;
    getline(cin, buffer);
    stringstream buffer_stream(buffer);
    double num1, num2, result;
    char operation;
    buffer_stream >> num1 >> operation >> num2;
    bool flag = true;

    switch (operation)
    {
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
        result = num1 / num2;
        break;
    
    default:
        cerr << "Error: invalid input";
        flag = false;
        break;
    }
    if (flag)
        cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
    return 0;
}