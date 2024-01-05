#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findMaxSum(vector<int>& array){
    int maxSum = INT_MIN; // Начинаем с самого малого возможно значения
    int currentSum = 0;
    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i =0; i < array.size(); i++){
        currentSum += array[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    cout << "Maximum Sum: " << start << " " << end << endl;
}

int main(){
    cout << "Task 15.1!\n";
    cout << "____________________\n";
    vector<int> arrayInt = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    findMaxSum(arrayInt);

    return 0;
}