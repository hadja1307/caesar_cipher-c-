#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include <fstream> ///library used to read and write to files
///#include <ifstream>
///#include <ofstream>
#include <vector> ///for the dynamic table library, 
#include <math.h> ///library for abs, preven negative number
#include <stdlib.h>
#include "caesar.h"




using namespace std;

int main(int argc, char** argv[]) ///argc is the number of arguments , argv is the vector i.e the string of the array
{

    char Charchoice;
    int choice;
    int testChoice = 1;
    int again = 0;
    char use_suggest_key;
    int suggest_key;
    int user_key;
    char user_key_char;
    int key; ///declaration of variable key to store the key returned by max_index or user's own key
    int try_other_key = 0;

    system("cls"); /// clear screen 

    cout << "   /===========================================================\\" << endl;
    cout << "  |      Welcome to the world of Cesar cipher                   |" << endl;
    cout << "  |      Author : Hadja                                         |" << endl;
    cout << "  |      Version : 1.0                                          |" << endl;
    cout << "   \\===========================================================/" << endl << endl;


    string inputFile = "C:/Users/kadia/OneDrive/Desktop/c++/!assignment/inputfile.txt";  ///will be changed based on CLA argv
    string outputFile = "C:/Users/kadia/OneDrive/Desktop/c++/!assignment/outputfile.txt";  ///will be changed based on CLA argv

    vector <char> arrayout; ///declaration of tables 
    Lettertype* characterFrequency;
    int size;
    int maxindex; ///storing value of max index returned by max_index function

    ifstream readmyFile(inputFile);
    ///NEED TO CHANGE THIS LOOP , ASK USER TO GIVE EXTENSION OF FILE LOCATION FOR ENCRYPTED FILE AND DECRYPT,
     ///IF FILE EXTENSION GIVEN ISN'T VALID THEN PROMPT USER UNTIL CORRECT FILE EXTENSION IS ENTERED 
     ///IF CORRECT FILE IS ENTERED, THEN USE THAT LOCATION OF ENCRYPTED TEXT AND DECRYPT IT SEND IT TO A FILE

    Caesar caesar_main; ///calling of default constructor

    if (!readmyFile) {
        cout << "An error occured reading the input file" << endl;
        exit(1); ///closes the program if can't open the file to read it
    }
    ofstream writemyFile(outputFile);
    if (!writemyFile) {
        cout << "An error occured opening the output file" << endl;
        exit(1); ///closes the program if can't open to write to the file     }
    }

    arrayout = read_file(inputFile); ///the table arrayout will contain the results of the characters frequencies found in the function read file, characters without any numbers, spaces, symbols

    size = arrayout.size();
    print_vector(arrayout); /// prints the vector of characters returned by the read file function

 


    do {

        cout << "   *********   What do you want to do   ?        ***************" << endl << endl;
        cout << "   ==> 1. Analyse frequent characters               " << endl;
        cout << "   ==> 2. Decrypt  file                             " << endl;
        cout << "   ==> 3. Encrypt  file                             " << endl;
        cout << "   ==> 4. Exit de program                           " << endl;
        cin >> Charchoice;

        while (!isdigit(Charchoice)) { ///this loop will continue until the user enters a digit
            cout << "Wrong input : must be numeric and chosen from the proposed list Please, try again: ";
            cin >> Charchoice;
        }
        choice = (int)Charchoice - 48; ///convert a char into a int 


        if (choice == 1) {
            cout << " You chose Analyse frequent characters :  " << choice << endl;
            again = 1;

          /*
        The (.) Dot operator is a "Class Member Access Operator" , it is used to access public members of a class.
         Public members contain data members (variables) and member functions (class methods) of a class.
         */
            characterFrequency = caesar_main.character_count(arrayout, size); ///outputs the frequency of the characters in a table
            ///key = max_index(characterFrequency, size);
            /// caesar_main.character_count , caesar_main is used to access public member of the class Caesar, 
            /// caesar_main contains the methods (functions) of a class, character_count  

        } else if (choice == 2) {
            characterFrequency = caesar_main.character_count(arrayout, size); ///outputs the frequency of the characters in a table
            suggest_key = max_index(characterFrequency, size);
            cout << " Do you want to use the suggested key to decrypt, or use your own key? (y/n) : " << endl;
            cin >> use_suggest_key;
            if (use_suggest_key == 'y') {
                key = suggest_key;

            } else {

                cout << "plese enter your suggested key : " << endl;
                cin >> user_key_char;
                if (isdigit(user_key_char)) {
                    user_key = (int)user_key_char - 48; ///convert a char into int , using the user's input
                    key = user_key;
                } else {
                    cout << "An error occured, the key must be a numeric " << endl;
                    again = 1; ///gives the use choice to return back to the program and try again
                }

            }
            caesar_main.decrypt(key, readmyFile, writemyFile);

            cout << "your file is currently being decrypted..... Exit the Program to view your decypted text  " << endl;
            cout << "This is the location of the decrypted text :  " << outputFile << endl;
            cout << "End of Program " << endl;
           /// cout << "decrypted file located at : " << outputFile  << "Exit the program to view the file" << endl;
            again = 1; ///exit 1 will return to main menu
            /// AGAIN 1 WILL NOT WRITE TO PROGRAM UNTIL END OF THE DO WHILE STATEMENT
            /// The program should end after writing the decrypted text to a file
            /// PROBLEM ONLY WHEN I EXIT THE PROGRAM IT WRITES TO THE PROGRAM THE DECRYPTED TEXT - SOLUTION: USE AGAIN 0
            
            
            /*
            On selection of the key a sample of decrypted text should be provided
            allowing the user to decide whether to continue with the decryption process
            or choose another key.
            The program should end after writing the decrypted text to a file
            */

        } else if (choice == 3) {
            cout << "Encrypt option is not available at the moment" << endl;

            again = 1; /// again = 1 will return to program  menu
        } else if (choice == 4) {
            cout << "See you again next time, Bye" << endl;
            again = 0; ///again = 0 means the user can exit the program
        }
        else {
            cout << " Error : your choice is not valid .. :  " << endl;
            again = 1;
        }
    } while (again == 1);



    return 0;

}


/* *******************************************************************
///Function to read files
Criteria 1: The executable program should run from the command line
without modification using 2 command line arguments: an encrypted filename
and a filename to write the decrypted text to.
It should suggest a key to use from analysis of the text
and allow the user to enter or select a key.
On selection of the key a sample of decrypted text should be provided
allowing the user to decide whether to continue with the decryption process
or choose another key.
The program should end after writing the decrypted text to a file
*******************************************************************/

/*
int main()
{
    char charchoice;
    int choice;
    int testChoice = 1;
    int again = 0;
    system("cls"); /// clear screen
    cout << "   /===========================================================\\" << endl;
    cout << "  |      Welcome to the world of Cesar cipher                   |" << endl;
    cout << "  |      Author : Hadja                                         |" << endl;
    cout << "  |      Version : 1.0                                          |" << endl;
    cout << "   \\===========================================================/" << endl << endl;
    do
    {
        cout << "   *********   What do you want to do   ?        ***************" << endl << endl;
        cout << "   ==> 1. Analyse frequent characters               " << endl;
        cout << "   ==> 2. Decrypt  file                             " << endl;
        cout << "   ==> 3. Encrypt  file                             " << endl;
        cout << "   ==> 4. Exit de program                           " << endl;
        cin >> charchoice;
        while (!isdigit(charchoice))
        {
            cout << "Wrong input : must be numeric and chosen from the proposed list Please, try again: ";
            cin >> charchoice;
        }
        choice = (int)charchoice - 48;
        cout << "choice  : " << choice << endl;
        cout << "charchoice : " << charchoice << endl;
        if (choice == 1)
        {
            cout << " This is your choice :  " << choice << endl;
            testChoice = 0;
        }
        else if (choice == 2)
        {
            cout << " File decryption is not available in this version. Coming soon.. :  " << endl;
            testChoice = 1;
        }
        else if (choice == 3)
        {
            cout << " File encryption is not available in this version. Coming soon.. :  " << endl;
            testChoice = 1;
        }
        else if (choice == 4)
        {
            cout << " >>>>>>> Thank you and see you soon ..====>  " << endl;
            testChoice = 0;
        }
        else
        {
            cout << " Error : your choice is not valide .. :  " << endl;
            testChoice = 1;
        }
    } while (testChoice == 1);
}*/