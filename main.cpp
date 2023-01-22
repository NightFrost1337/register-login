#include <iostream>
#include <Windows.h>
#include <ios>
#include <limits>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <urlmon.h>
#include <tchar.h>
#include <Wininet.h>
#include <filesystem>
#include <stdexcept>
#include <fstream>
#include <string>
#include <direct.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "urlmon.lib")

using namespace std;

int main()
{

    SetConsoleTitle(_T("Login and Register Form made by NightFrost"));
    _mkdir("C:/Login"); 

    fstream myfile;
    string line;
    ofstream outFile;
    string username;
    string password;


    string option;
    cout << "[1] Login\n";
    cout << "[2] Register\n";
    cin >> option;

    if (option == "1")
    {
        ifstream file1("C:/Login/username.txt");
        ifstream file2("C:/Login/mdp.txt");
        string content1;
        string content2;
        while (file1 >> content1) {
            while (file2 >> content2) {
                system("cls");
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;


                if (content1 == username && content2 == password)
                {
                    cout << "Login Success !\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                else if (content1 != username && content2 != password)
                {
                    cout << "Incorect Username or Password !!\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                else if (content1 != username && content2 == password)
                {
                    cout << "Incorect Username !\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                else if (content1 == username && content2 != password)
                {
                    cout << "Incorect Password !\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                else {
                    cout << "Incorect !\n";
                    Sleep(2000);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    if (option == "2")
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        outFile.open("c:/Login/username.txt");
        outFile << username << endl;
        outFile.close();

        outFile.open("C:/Login/password.txt");
        outFile << password << endl;
        outFile.close();
        system("cls");
        main();
    }


}
