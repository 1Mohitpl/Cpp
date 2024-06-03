#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Form {
    string userName, loginId, password;
    string searchEmail, searchPassword, searchName;
    fstream file;
public:
    void login();
    void signup();
    void forgetPassword();
};

Form obj;

int main() {
    char choice;

    while (true) {
        cout << "\n1- Sign-up";
        cout << "\n2- Login";
        cout << "\n3- Forget Password";
        cout << "\n4- Exit";

        cout << "\nEnter your Choice: ";
        cin >> choice;
        cin.ignore();  // to clear the newline character from the input buffer

        switch (choice) {
            case '1':
                obj.signup();
                break;
            case '2':
                obj.login();
                break;
            case '3':
                obj.forgetPassword();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid choice...!" << endl;
        }
    }
}

void Form::signup() {
    cout << "Enter your Name: ";
    getline(cin, userName);

    cout << "Enter your emailAddress: ";
    getline(cin, loginId);

    cout << "Enter your password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << userName << "*" << loginId << "*" << password << endl;
        file.close();
        cout << "Signup successful!" << endl;
    } else {
        cout << "Error opening file for signup!" << endl;
    }
}

void Form::login() {
    cout << "------------Login form ---------" << endl;
    cout << "Enter your user email: ";
    getline(cin, searchEmail);

    cout << "Enter your password: ";
    getline(cin, searchPassword);

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        bool found = false;
        while (getline(file, userName, '*') &&
               getline(file, loginId, '*') &&
               getline(file, password)) {
            if (loginId == searchEmail && password == searchPassword) {
                cout << "Account successfully logged in!" << endl;
                cout << "UserName: " << userName << endl;
                cout << "EmailId: " << loginId << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Invalid email or password!" << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for login!" << endl;
    }
}

void Form::forgetPassword() {
    cout << "Enter your emailAddress: ";
    getline(cin, searchEmail);

    cout << "Enter your User Name: ";
    getline(cin, searchName);

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        bool found = false;
        while (getline(file, userName, '*') &&
               getline(file, loginId, '*') &&
               getline(file, password)) {
            if (userName == searchName && loginId == searchEmail) {
                cout << "Account found!" << endl;
                cout << "Here is your Account Password: " << password << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Account not found!" << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for password recovery!" << endl;
    }
}
