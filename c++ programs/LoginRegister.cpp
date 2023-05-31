#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main()
{

    int choice;


    cout << "\t\t\t        Welcome to the Login Page                 \n\n\n";

    cout << "\t\t\t_________            Menu              ___________\n\n\n";

    cout << "                                                         \n\n";

    cout << "\t\t\t| Press 1 to LOGIN                         |" << endl;
    cout << "\t\t\t| Press 2 to REGISTER                      |" << endl;
    cout << "\t\t\t| Press 3 if you forgot the PASSWORD       |" << endl;
    cout << "\t\t\t| Press 4 to EXIT                          |" << endl;

    cout << "\n\t\t\t  Please enter your choice : ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t Thank You!  \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t  Please Select from the options given above \n"
             << endl;
        main();
    }

    return 0;
}

void login()
{
    int count;
    string userId;
    string password;
    string id;
    string pass;

    system("cls");

    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USERNAME : ";
    cin >> userId;
    cout << "\t\t\t PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successfull \n Thanks for logging in !" << endl;
    }

    else
    {
        cout << "\n LOGIN ERROR \n Please check Your username and password\n";
        main();
    }
}

void registration()
{

    string ruserid;
    string rpassword;
    string rid;
    string rpass;

    system("cls");

    cout << "\t\t\t Enter the username : ";
    cin >> ruserid;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);

    f1 << ruserid << ' ' << rpassword << endl;

    system("cls");

    cout << "\n\t\t\t Registration is successfull! \n";

    main();
}

void forgot()
{

    int option;
    system("cls");

    cout << "\t\t\t You forgot the password? No worries \n";
    cout << " Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;

    cout << "\t\t\t Enter your choice : ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId;
        string sId;
        string spass;
        cout << "\n\t\t\t Enter the username which you remembered : ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }

        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your password is : " << spass;
            main();
        }

        else
        {
            cout << "\n\t Sorry! your account is not found \n";
            main();
        }
    }
    break;

    case 2:
    {
        main();
    }

    default:
        cout << "\t\t\t Wrong Choice ! Please try again " << endl;
        forgot();
        break;
    }
}