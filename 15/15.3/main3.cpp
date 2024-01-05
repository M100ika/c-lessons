#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& vec){
    cout << "{";
    for (int i = 0; i < vec.size(); ++i){
        cout << vec[i];
        if (i < vec.size()-1) cout << ",";
    }
    cout << "}";
}

bool checkCin(){
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void minusOne(vector<int>& vec){
    if (vec.size() < 5) {
        cerr << "There are not enough numbers to display the fifth in ascending order.\n";
    } else {
        sort(vec.begin(), vec.end());  
        cout << "The fifth number: " << vec[4] << " sorted: (";
        printVector(vec);
        cout << ")" << endl;  
    }
}

void vecRedactor(vector<int>& vec){
    while (true) {
        int choice;
        cin >> choice;
        if (!checkCin()){
            cerr << "Invalid input. Please enter the number: ";
            continue;
        }
        if (choice == -1) minusOne(vec);
        else if (choice == -2)
        {
            cout << "Exit.\n"; 
            break;
        }
        else vec.push_back(choice);
    }
}

int main() {
    cout << "Task 15.3.\n______________________\n";
    cout << "Enter numbers. If you enter -1, the fifth highest number will be displayed. -2 to exit.\n";
    vector<int> numbers;  
    vecRedactor(numbers);        
    return 0;
}