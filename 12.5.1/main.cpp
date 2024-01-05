#include <iostream>
#include <string>
using namespace std;

const int residents = 10;
const int apartment = 3;

void getLastName(string arr[], int size){
    for (int i = 0; i < size; ++i){
        getline(cin, arr[i]);
    }
};

int checkCin(){
    int number;
    cout << "To exit enter: -1." << endl;
    while(true){
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n') {}
            cout << "Invalid input. Please enter a number." << endl;
        }
        else {
            while (cin.get() != '\n') {}
        }
        if (number >= 1 && number <= 10) 
            return number;
        else if (number == -1) 
            return -1;
        else 
            cout << "Error! Wrong number. There are 10 apartments in the House." << endl;
            cout << "Try again" << endl;
    }
}

void numberOfApartment(string arr[], int size){
    int number;
    for (int i=0; i < size; ++i){
        cout << "Please enter apartment number " << endl;
        number = checkCin();
        if (number == -1) {
            cout << "Bye!" << endl;
            break;
        }
        cout << arr[number-1] << endl;
};
}

int main(){
    cout << "Please enter the names of 10 residents" << endl;
    string house[residents];
    getLastName(house, residents);
    numberOfApartment(house, apartment);
};