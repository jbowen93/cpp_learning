#include <iostream>

using namespace std;

int main() {
    string name;
    int age;
    string username;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "How old are you?" << endl;
    cin >> age;
    cout << "What is your username?" << endl;
    cin >> username;
    cout << "Your name is " << name << ", your are " << age << " years old, and your username is " << username << endl;
    return 0;
}