#include <iostream>
#include <sstream>
#include <string>

using namespace std;

enum note {
    DO = 1,
    RE = 2, 
    MI = 4,
    FA = 8,
    SOL =16,
    LA = 32, 
    SI = 64
};

int main(){
    cout << "Task 16.4!\n_________________\n";
    cout << "Enter 12 combinations of notes (from 1 to 7): \n";
    int melody[12];
    string input;
    for (int i = 0; i < 12; ++i){
        getline(cin, input);
        int noteComb = 0;
        for (char ch:input){
            int noteIndex = ch - '1';
            if (noteIndex >= 0 && noteIndex <= 6) {
                noteComb |= 1 << noteIndex;
              //  cout << i+1 << ": " << noteComb << endl;
            }
        }
        melody[i] = noteComb;
    }
    cout << "\nStart playing melody: \n";
    for (int notes : melody){
        if (notes & DO) cout << "DO ";
        if (notes & RE) cout << "RE ";
        if (notes & MI) cout << "MI ";
        if (notes & FA) cout << "FA ";
        if (notes & SOL) cout << "SOL ";
        if (notes & LA) cout << "LA ";
        if (notes & SI) cout << "SI ";
        cout << " ";
    }
}