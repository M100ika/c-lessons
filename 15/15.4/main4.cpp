#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void printVector(const vector<int>& vec){
    cout << "{";
    for (int i = 0; i < vec.size(); ++i){
        cout << vec[i];
        if (i < vec.size()-1) cout << ", ";
    }
    cout << "}";
}

void sortByAlgorithm(vector<int>& vec){ // Функция для сортировки с помощью библиотеки algorithm
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
}

void sortByCmath(vector<int>& arr){ // Функция для сортировки с помощью библиотеки cmath
    for (int i = 0; i < arr.size(); ++i){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && abs(arr[j]) > abs(key)) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int moduleCustom(int val) {
    return val < 0 ? -val : val;
}

void sortCustom(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && moduleCustom(arr[j]) > moduleCustom(key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

bool checkCin(){
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main(){
    cout << "Task 15.4\n ______________________\n";
    cout << "Micheal, that's message for u. In this program I wrote 3 sort functions:\n1. By using algorithm;\n2. By using cmath;\n3. My solution without using libraries.\n";
    cout << "\n\nI'm sure, this task have a lot of different solution ways and tasks what where before too. I hope my solved tasks looks not so bad.\n";
    cout << "You can pick the function: \n1. By using algorithm;\n2. By using cmath;\n3. My solution without using libraries.\n-1. Exit.\n";
    while (true){
        int choice;
        cin >> choice;
        if(!checkCin()){
            cerr << "Invaliv input! Try again.\n";
            continue;
        }
        vector<int> numArr = {-100, -50, -5, 1, 10, 15};
        cout << "Array ";
        printVector(numArr);
        cout << " transforms to: ";
        switch (choice) {
            case 1:
                sortByAlgorithm(numArr);
                printVector(numArr);
                cout << "\nAlgorithm option selected.\n";
                break;
            case 2:
                sortByCmath(numArr);
                printVector(numArr);
                cout << "\nCmath option selected.\n";
                break;
            case 3:
                sortCustom(numArr);
                printVector(numArr);
                cout << "\nCustom solution selected.\n";
                break;
            case -1:
                cout << "nothing, cause your choice is exiting program))\n";
                return 0;
            default:
                cerr << "Choice not recognized. Please try again.\n";
                break;
        }
    }
}

