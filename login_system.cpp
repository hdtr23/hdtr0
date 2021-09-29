// Login and Register system
// Source: https://www.youtube.com/watch?v=I_aWPGCaaFA
// Made by: hdtr
// Learn Input and Output with C++

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

void menu(){
    cout << "\n***** Welcome to this site *****";
    cout << "\n1. Register\n2. Login\n";
}

bool isLoggedIn(){
    string username, password, usernameStored, passwordStored;

    cout << "\nUsername: " << setw(5); cin >> username;
    cout << "\nPassword: " << setw(5); cin >> password;

    ifstream read("D:\\workspace\\cplusplus\\hello_world\\hdtr0\\data\\" + username + ".txt");

    getline(read, usernameStored);
    getline(read, passwordStored);

    if(username == usernameStored && password == passwordStored){
        cout << "\nLogin Successfully!";
        return true;   
    } 
    else{ 
        cout << "\nLogin Failed!";
        return false;
        }
}

void Register(){
    string username, password;
    cout << "\nChoose your username: "; cin >> username;
    cout << "\nChoose your password: "; cin >> password;

    ofstream file;
    file.open("D:\\workspace\\cplusplus\\hello_world\\hdtr0\\data\\" + username +".txt");
    file << username << endl << password;
    file.close();
}

int main(){
    menu();
    int choice;
    cout << "\nEnter your choice: "; cin >> choice;

    switch (choice){
        case 1: 
            Register();
            main();
            break;
        case 2:
            isLoggedIn();
            break;
    }
    return 0;
}
   