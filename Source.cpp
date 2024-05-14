
#include <iostream>
#include "Header.h"
using namespace std;
int main() {
    HashTable obj;

    string currUser, Uname, follow, Unfollow;
    int num, n1, choice;
    string name, repo;
    cout << "Enter the number of members you want to register:  ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        string user, pswd;
        cout << "Enter the Username for the Member " << i + 1 << ": ";
        cin >> user;
        cout << "Enter Password for Member " << i + 1 << ": ";
        cin >> pswd;
        obj.registerUser(user, pswd);
    }

    cout << "Enter the no of logins: ";
    cin >> n1;

    for (int j = 0; j < n1; j++) {
        string user, pswd;
        cout << "Enter username to login " << j + 1 << ": ";
        cin >> user;
        cout << "Enter password to login " << j + 1 << ": ";
        cin >> pswd;
        obj.login(user, pswd);
    }

    cout << endl;
    while (true) {
        cout << "----- Menu -----" << endl;
        cout << "1. Create a new repository" << endl;
        cout << "2. View repository stats" << endl;
        cout << "3. Delete Repository " << endl;
        cout << "4. Follow a user" << endl;
        cout << "5. Unfollow a user" << endl;
        cout << "6. See followers list" << endl;
        cout << "7. Logout" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter your username: ";
            cin >> currUser;
            obj.createRepo(currUser);
            break;
        case 2:
            cout << "Enter the username to view repository stats: ";
            cin >> Uname;
            obj.viewRepo(Uname);
            break;
        case 3:
            cout << "Enter user name:";
            cin >> name;
            cout << "Enter repostory name:";
            cin >> repo;
            obj.deleteRepo(name, repo);
            cout << "Repository Deleted Successfully" << endl;
            break;
        case 4:
            cout << "Enter your username: ";
            cin >> currUser;
            cout << "Enter the username you want to follow: ";
            cin >> follow;
            obj.follow(currUser, follow);
            break;
        case 5:
            cout << "Enter your username: ";
            cin >> currUser;
            cout << "Enter the username you want to unfollow: ";
            cin >> Unfollow;
            obj.unfollow(currUser, Unfollow);
            break;
        case 6:
            cout << "Enter the username to see followers list: ";
            cin >> Uname;
            obj.showFollower(Uname);
            break;
        case 7:
            cout << "Log out" << endl;
            for (int j = 0; j < n1; j++) {
                string user;
                cout << "Enter username for logout " << j + 1 << ": ";
                cin >> user;
                obj.logout(user);
            }
            break;
        case 8:
            cout << "Exiting" << endl;
            return 0;
        default:
            cout << "Wrong Input" << endl;
        }
    }
    return 0;
}
