#include <iostream>

using namespace std;

int main() {
    char input;
    float force, mass, accel;
    //Intro Message
    cout << "Welcome to the Physics Calculator!" << endl;
    cout << "Please enter what you would like to calculate" << endl;
    cout << "Entering 'F' will calculate F = M * A" << endl;
    cout << "Entering 'A' will calculate A = F / M" << endl;
    cout << "Entering 'M' will calculate M = F / A" << endl;

    //Take in user input
    cin >> input;

    switch (input)
    {
        case 'F':
            cout << "Calculating Force" << endl;
            cout << "What is the mass?" << endl;
            cin >> mass;
            cout << "What is the acceleration?" << endl;
            cin >> accel;
            cout << "The Force is " << mass * accel << endl;
            break;

        case 'A':
            cout << "Calculating Acceleration" << endl;
            cout << "What is the force?" << endl;
            cin >> force;
            cout << "What is the mass?" << endl;
            cin >> mass;
            cout << "The Force is " << force / mass << endl;
            break;

        case 'M':
            cout << "Calculating Mass" << endl;
            cout << "What is the force?" << endl;
            cin >> force;
            cout << "What is the acceleration?" << endl;
            cin >> accel;
            cout << "The Force is " << force / accel << endl;
            break;

        default:
            cout << "Please choose either Force('F'), Acceleration('A'), or Mass('M')" << endl;
    }

    return 0;
}