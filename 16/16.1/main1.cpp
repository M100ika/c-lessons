#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Task 16.2!\n_____________________\n";
    float speed = 0.0f;
    float delta;
    do{
        cout << "Enter spedd delta: ";
        cin >> delta;
        speed += delta;
        if (speed > 150.0f) speed = 150;
        else if (speed < 0.0f) speed = 0.0f;

        char speed_str[50];
        sprintf(speed_str, "%.1f", speed);
        cout << "Speed: " << speed_str << endl;
    } 
    while (speed > 0.01f);

    return 0;
}