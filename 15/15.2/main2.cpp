#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

void findSumFastWay(const vector<int>& arr, const int checkRes, bool flag = true){ // Временная сложность данной функции O(n)  
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++){   // O(n) - мы проходим по элементам массива один раз
        int result = checkRes - arr[i];
        if (map.find(result) != map.end()){
            if (flag)
            cout << "Fast way function answer is: " << result << " " << arr[i] << endl;
            return;
        }
        map[arr[i]] = i;
    }
    cerr << "Digits not found!" << endl;
}

void findSumSimpleWay(const vector<int>& arr, const int checkRes, bool flag = true){ // О(n2) 
    for (int i = 0; i < arr.size(); ++i){ // O(n2) - мы проходим по элементам массива 2 раза
        for (int k = 0; k < arr.size(); ++k){
            if (arr[i]+arr[k] == checkRes){
                if (flag)
                cout << "Simple solution function answer is: " << arr[i] << " " << arr[k] << endl;
                return;
            }
        }
    }
    cerr << "Digits not found!" << endl;
}

void analyzing(const vector<int>& arr, const int checkRes){
    int i = 0;
    int w1 = 0;
    int w2 = 0;
    bool flag = false;
    while (i < 100000) {
        auto start1 = high_resolution_clock::now();
        findSumFastWay(arr, checkRes, flag);
        auto end1 = high_resolution_clock::now();
        auto t1 = duration_cast<microseconds>(end1 - start1).count();
        //cout << "Time taken by fast way function is: " << t1 << " microseconds." << endl;
        auto start2 = high_resolution_clock::now();
        findSumSimpleWay(arr, checkRes, flag);
        auto end2 = high_resolution_clock::now();
        auto t2 = duration_cast<microseconds>(end2 - start2).count();
        //cout << "Time taken by simple solution function is: " << t2 << " microseconds." << endl;
        if (t1 > t2) w2+=1; // Если время выполнения первой функции больше то победа второй функции
        else if (t1 < t2) w1+=1;
        i+=1;
    }
    cout << "Total wins of findSumFastWay function is: " << w1 << "\nTotal wins of findSumSimpleWay function is: " << w2;
}

int main(){
    cout << "Task 15.2!\n________________________\n";
    vector<int> array = {5, 11, 8, 10, 12, 1};
    int checkResult = 9;
    cout << "In this task, I implemented two functions with different time complexities to solve the given problem." << 
    "\nThe time complexity of the function findSumFastWay is O(n), while the time complexity of findSumSimpleWay is O(n2). " <<
    "\n\nYou can choose which function to use: \npress 1 for findSumFastWay \npress 2 for findSumSimpleWay. \npress 3 for analyzing." <<
    "\n\nAdditionally, I implemented a function for time analysis of these functions. " <<
    "\nThe program performs calculations 100,000 times and displays the total number of wins for the first and the second function. " <<
    "\nInterestingly, the function with the time complexity of O(n2) wins 50 times more often than the function with the time complexity of O(n). " <<
    "\nI suspect the issue might be with unordered_map." << endl;
    int choice;
    cin >> choice;
    if (choice == 1) findSumFastWay(array, checkResult);
    else if (choice == 2) findSumSimpleWay(array, checkResult);
    else if (choice == 3) analyzing(array,checkResult);
    else cerr << "Wrong! Bye";
    return 0;
}