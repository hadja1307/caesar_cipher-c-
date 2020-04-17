#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include <fstream> //library used to read and write to files
//#include <ifstream>
//#include <ofstream>
#include <vector> //for the dynamic table library, 
#include <math.h> //library for abs, preven negative number
#include <stdlib.h>
#include "caesar.h"




using namespace std;
int main(int argc, char **argv[]) //argc is the number of arguments , argv is the vector i.e the string of the array
{
    int my_array[] = { 5, 2, 7, 3, 10, 1 }; // array list contains values 
    int length = 5; // 5 is the length of the array list
    char m_array[] = { 'h','e','l','l','o',' ','w','o','r','l','!','d' };
    string inputFile = "C:/Users/kadia/OneDrive/Desktop/c++/!assignment/inputfile.txt";  //will be changed based on CLA argv
    string outputFile = "C:/Users/kadia/OneDrive/Desktop/c++/!assignment/outputfile.txt";  //will be changed based on CLA argv

    vector <char> arrayout; //declaration of tables 
    letterType* characterFrequency;
    int size;
    int maxindex; //storing value of max index returned by max_index function
    int key; //declaration of variable key to store the key returned by max_index
    ifstream readmyFile(inputFile) ;
   //NEED TO CHANGE THIS LOOP , ASK USER TO GIVE EXTENSION OF FILE LOCATION FOR ENCRYPTED FILE AND DECRYPT,
    //IF FILE EXTENSION GIVEN ISN'T VALID THEN PROMPT USER UNTIL CORRECT FILE EXTENSION IS ENTERED 
    //IF CORRECT FILE IS ENTERED, THEN USE THAT LOCATION OF ENCRYPTED TEXT AND DECRYPT IT SEND IT TO A FILE
    
        
        if (!readmyFile) {
            cout << "An error occured reading the input file" << endl;
            exit(1); //closes the program if can't open the file to read it
        }
        ofstream writemyFile(outputFile);
        if (!writemyFile) {
            cout << "An error occured opening the output file" << endl;
            exit(1); //closes the program if can't open to write to the file     }
        }

        arrayout = read_file(inputFile); //the table arrayout will contain the results of the characters frequencies found in the function read file, characters without any numbers, spaces, symbols

        size = arrayout.size();
        print_vector(arrayout); // prints the vector of characters returned by the read file function

        characterFrequency = character_count(arrayout, size); //outputs the frequency of the characters in a table
        key = max_index(characterFrequency, size);


        decrypt(key, readmyFile, writemyFile);

              
    
    //print_characterFrequency(characterFrequency, size); //prints the output of the freuqncy of the charcter

   //cout << is_upper('A');
   //cout << to_upper('z');
   //cout << is_alpha(' ');
}


/* *******************************************************************
//Function to read files
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
    system("cls"); // clear screen 



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

