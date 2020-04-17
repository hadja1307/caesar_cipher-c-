#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include <fstream> //library used to read and write to files
#include <math.h>
#include "caesar.h"

#include <vector> //for the dynamic table library, 
//dynamic becasue we don't know the exact size of the table, 
//which can increase based on what we think and can decrease
using namespace std; //library used to limit the scope of variables in a program
char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
 //const char LanguageFrequentCharacter [26] = { ' e ', ' t ', ' a ', ' o ', ' i ' , ' n ' , ' r ' , ' h ' , ' l ' , ' d ' , ' c ' , ' u ' , ' m ', ' f ', ' p ', ' g ' , ' w ', ' y ' ,' b ' ,' v ' ,' k ' ,' x ' ,' j ' ,' q ' ,' z ' };
 //a list of keys should be provided to the user, for them to choose a key to decrypt the text
 // need to give a list of keys to the user, to allow them to choose a key 
 //language frequency char of [26] elelemt array uses all those letter as they are most used letters in english alphabet, to find the key
 const char LanguageFrequentCharacter = 'e'; //original, uses e to find the key

/* *******************************************************************
//Function to find the character in a table, will do the the following:
if the letter exists in the table, then return the position of the letter
if the letter isn't found, -1 will be returned
@param letterType * array
@param int size
@param char letter_To_search

*******************************************************************/
int find_character_in_table (letterType *array, int size, char letter_to_search)
{ 
	for (int i = 0; i < size; i++) {
		if (array[i].letter == letter_to_search) {
			return i;
			// if the letter exists in the table, then return the position of the letter
		} 
	}
	return -1; //if letter isn't found in the table then return -1
}

/* *******************************************************************
//Function to read files
if the file is open, then open the content in the file
if for some reason the file can't or isn't opening, then send a consol message
the while loop will run until one of the two statements is true, i.e. file opened successfully or file did not open successfully.
Once the file has successfully opened and is alphabetic, then upppercase all the characters and output the frequency of each character
else if the characters are not alphabetic characters such as !, ? " " , then do nothing.
@param string inputFile , takes the inputFile to read it

*******************************************************************/
vector <char> read_file(string inputFile ) {
	string myText_store;

	vector<char> arrayout; //declaring an empty dynamic table, to store the characterss tha are in the file
	char my_character;

	ifstream Myfile(inputFile); //declaring file to read it using ifstream
	if (Myfile) {
		//getline is used to read the file line by line
		//if statement is used to check if the file is open or not, if the file isn't open, error message is sent, 
		//if it is open, the while loop will run and display what is in the file
		 //the method in the while loop allows us to get the file, read the file and store the results. 
		
		while (Myfile.get(my_character)) //read each charater
		{
			/*
				//the If statement below tests if character is alphabetic, if it is alphabetic
				//then uppercases the letter then prints the frequency of it
				//reads each character in the file, it then , it stores it in the table arrayout ,
				 else if the character is not alphabetic then do nothing
				//arrayout is the name of the table, 
				//push_back is a function used to push elements into a vector from the back, value is inserted into the vector at the end
				*/
			if (is_alphabet(my_character))
			{
				
				arrayout.push_back(to_upper(my_character)); 
			}
		
			
			//must store the text in a table
			//then return the data of the table i.e. origin_table
			//use this then to order characters between highest and lowest
		}
		return arrayout;
	
	}
	else {
		cout << "Unfortunately, there has been a problem opening the file" << endl; //displayed if the file could not open

		Myfile.close(); // closes file 
	}
	
}

/* *******************************************************************
	checks if the input character on the function is  uppercase or not
	test @ a = false
	test @ A = true
	if it is uppercase, it will return true, else return false
	@param char input_char

*******************************************************************/
bool is_upper(char input_char)
{
	int temp;
	temp = (int)input_char; //casting input character to int , ascii value of input character

	if (temp >= 97 && temp <= 122) {
		return false;
	}
	else {
		return true;
	}
}

/* *******************************************************************
	function to_upper, puts characters in uppercase if they are not
	it returns the uppercase character using ascii calculation
	test @ a = A
	test @ A = A
	test @ o = O
	test @ y = Y
	test @ z = Z
	test @ U = U
    //if the chracter input is in uppercase then don't do nothing return the character,
    //else subtract 32 from the ascii which will give you the uppercase of that character,
	//32 is the difference between a and A in ascii table for lowecase and uppercase characters
	@param char input_char
*******************************************************************/
char to_upper(char input_char)
{
	//if the chracter input is in uppercase then don't do nothing return the character,
	if (is_upper(input_char)) {

		return input_char;
	}
	else {

		return input_char - 32; //32 is the difference between A and a  and Z and z on the ascii table
	}



}

/* *******************************************************************
	checks if the input character on the function is alpha alphabetic or a number using isdigit
	test @ 4 = false
	test @ A = true
	if it is digit it will return false, else if the characters is alphabetic, it will return true,  
		 //isdigit test if character input is a digit it returns false, else it will return true
	@param char input_char
*******************************************************************/
bool is_alpha(char input_char)
{
	
	if (isdigit (input_char)) {
		return false;
	}
	else {
		return true;
	}
}

/* *******************************************************************
 is_alphabet function check if the character is in the alphabet using ascii value, 
returns true if it is, return false if it isn't
test @ A = true
test @ z = true
test @ P = true
test @ * = false
test @ " " = false
test @ ? = false
	@param char input_char
*******************************************************************/

bool is_alphabet(char input_char) 
{
	if ((input_char >= 97 && input_char <= 122) || (input_char >= 65 && input_char <= 90)) {
		return true;
	}
	else {
		return false;
	}
}



/* *******************************************************************
	the function max_index returns the - max index of the array list
	it uses the character frequency on max index to find a key to decrypt the string
	test @ 123459781 = max value is 9, which has an index of 5, so 5 is returned
	@param letterType * array
	@param int size

	array will contain the character and the frequencies in the array list
	index will contain the size of the letterType array, array count starts at 0
	int *array is a pointer (memory location)
	//size is better to use in array


*******************************************************************/
int  max_index(letterType* array, int size) {
	int max = 0;
	int index = 0;
	int i;
	int j = 0;
	int key;

	letterType* validCharacterFrequency;

	max = array[0].count;

	for (i = 0; i < size; i++) //determines the number of valid values in the array list of characters
	{
		if (array[i].count != -842150451) {
			j++;
		}
	}

	validCharacterFrequency = new letterType[j]; //dynamic memory allocation to store the results of valid character frequency
	j = 0; //reinitialise the value of j reset to 0
	for (i = 0; i < size; i++) //determines the number of valid values in the array list of characters
	{
		if (array[i].count != -842150451) {

			validCharacterFrequency[j].letter = array[i].letter;//copy the value of the character from previous table into new table
			validCharacterFrequency[j].count = array[i].count;//also copy the frequency of that letter from previous table to new table


			j++;
		}
	}
	//calculate the max index of the valid character frequency
	max = validCharacterFrequency[0].count;
	for (i = 0; i < j; i++) {

		if (validCharacterFrequency[i].count >= max) {
			index = i;
			max = validCharacterFrequency[i].count; //max changes and becomes the new current highest number of that character
		}
	}

	//key = keyCalculator(*LanguageFrequentCharacter, validCharacterFrequency[index].letter); 
	//*langfrequency to get a list of most used letters based on figure 1 in assignment

	key = keyCalculator(LanguageFrequentCharacter, validCharacterFrequency[index].letter);

	cout << "Language Most frequence character : " << LanguageFrequentCharacter << endl;
	cout << "Most frequent character in your file :  " << validCharacterFrequency[index].letter << endl;
	cout << "The key to decrypt : " << key << endl;

		
	//cout << "The key to decrypt : " << key << endl;
	//cout << "The key to decrypt : " << key << endl;
	//cout << "The key to decrypt : " << key << endl;

	return key; //becasue the alphabet start from 0 counting for the array
}

/* *******************************************************************
 the function keyCalculator, takes the alphabet position of the letter
 it uses this position to calculate the difference between the two characters 
 i.e. e and l which gives a key of 7
test @ e position = 5
test @ l position = 12
key = 7
	@param char mostFrequentCharacter
	@param char LanguageFrequentCharacter
	if an alphabet character is uppercase , 
	then the postLanguage will give the position of i in the alphabet position i+1
	then the posFrequentChar will give the position of i in the alphabet position i+1
	abs will return the absolute value of the difference between the two characters.
	i.e. if you do 5-12 = -7, to prevent this negative number, abs is used
*******************************************************************/

int keyCalculator(char LanguageFrequentCharacter, char mostFrequentCharacter)
{
	int posLanguage = 0;
	int posFrequentChar = 0; 
	int key;
	for (int i = 0; i < 26; i++) {
		if (to_upper(alphabet[i]) == to_upper(LanguageFrequentCharacter)) {
			//convert all characters to uppercases before comparison
			posLanguage = i+1;
			//gives position of i in the alphabet position
		}

		if (to_upper(alphabet[i]) == to_upper(mostFrequentCharacter) ){
			posFrequentChar = i+1;
		}
		
	}
	key = abs(posLanguage - posFrequentChar); //returns absolute value of difference between the two characters in the alphabet without the negative
	return key;
}


//TEST IF USER WANTS TO DECRYPT FILE OR NOT, IF NOT THEN DO NOTHING, IF YEST DECRYPT FILE AND OUTPUT IT IN ANOTHER FILE



/* *******************************************************************
the function decrypt will decrypt the string using the encrypted inputFile, 
the key to decrypt it and then output the decrypted file into outputFile
	test @ 4 = false
	test @ A = true

	@param int key
	@param ofstream & outputFile
	@param ifstream & inputFile
*******************************************************************/
void decrypt(int key, ifstream& inputFile, ofstream& outputFile) {
	//changes the [ into b
	//changes the a into Z
	char mycharacter;
	while (inputFile.get(mycharacter)) //read file by each character 
	{
		if (is_alphabet(mycharacter)) // if the character is an Alphabet
		{

			//mycharacter = mycharacter - key; //Apply the shifts

			if (to_upper(mycharacter <= 'Z') || (to_upper(mycharacter <= 'A'))) {
				//mycharacter = mycharacter - 'Z' + 'A' - 1;
				mycharacter = (mycharacter - 90 - key) % 26 + 90;
				//used when the applied shift is negative
				// //decrypt uppercase characters
				//if a character is UPPERCASE, i.e. Z then subtract 90 from it and the key
				//then take the remainder of 26 add that to 90
				//90 is lowercase Z in ascii value
			}
			//ADDED ELSE IF STATEMENT
			else if (is_upper(mycharacter <= 'a') || (is_upper(mycharacter <= 'z'))) {
				mycharacter = (mycharacter - 122 - key) % 26 + 122;
				//decrypt lowecase characters
				//if a character isn't uppercase, i.e. a then subtract 122 from it and the key
				//then take the remainder of 26 add that to 122
				//122 is lowercase z in ascii value

			}


			outputFile << mycharacter;//write the decrypted character in the outputfile

		}

		else // if the character is not a alphabet (comma, space, !, ....)
		{
			outputFile << mycharacter; //write the non alphabetic character to the output file
		}


	}
}


	
	
/* *******************************************************************
	DOES NOT SHOW ON TERMINAL, DON'T THINK IT IS NEEDED
	print_analysis_array will print out the array, gives the user information as they go on 
	prints character array to the user 
	@param int * array
	@param int size
*******************************************************************/
void print_array(int *array,int size) {
	cout <<"-----------------------------------------------"<< endl;
	for (int i = 0; i <= size; i++)
	{
		cout << array[i]<< "| ";
	
	}
	cout << endl;
	cout << "-----------------------------------------------" << endl;

}

/* *******************************************************************
	print_vector  will print out the array, gives the user information as they go on 
	prints character array to the user 
	@param vector <char> arrayout
	test @ qwertyuiop = q|w|e|r|t|y|u|i|o|p|

	test @ abcdefghij = a|b|c|d|e|f|g|h|i|j|
*******************************************************************/
void print_vector(vector <char> arrayout)
{
	cout << "Encrypted text printing now" << endl << endl; //gives user information before encrypted text is displayed 
	for (int i = 0; i < arrayout.size(); i++)
		//arrayout.size used to limit the for loop
	{
		
		cout << arrayout[i] << " | " ; //output each character character with ' | ' 
		  
		
	}
	cout << endl << endl;
	cout << "Encrypted text All printed out now" << endl << endl;
	cout << " Below is the number of occurences for each character found on the text" << endl << endl;

}


/* *******************************************************************
	character_count counts the frequencies a specific letter appears 
	i do think it should use an array of 26 elelement to count the occurenc eof that letter in the alphabet
	the result of the count should be stored in the 25th element array, this will be used to analysize the array and from that workout what the key should be
		// i will take each character in the array, j will check the frequency of that character, 
		//max index and the function character_count will be used to find the most frequent character , order it from largest to smallest  and display it on the screen
*******************************************************************/

/*letterType character_count(letterType *array, int size) {

	int i;
	int j;
	const int sizeTwo = size ;
 //personalised type i.e. letterType, which will contain  the number of times the letter occures
	letterType  arrayout[sizeTwo]; // array of letter type = arrayout, each element of the array contains a letter and the frequencies of that letter

	int count_current = 0;
	char letter_to_search; // current letter to search

	// i will take each character in the array, j will check the frequency of that character, 
	for (i = 0; i < size; i++) // first for loop to set a fixed value and checks the number of times that letter appears
	{
		if (is_alphabet(array[i].letter)) //filters the alphabet letter, and do not take into account the letters that has already been red, they are marked as *
		{

			letter_to_search = array[i].letter;
			for (j = 0; j < size; j++) //ccounts the number of time a current value occurs
			{

				if (is_alphabet(array[j].letter)) // uses the function is_alphabet to check if current character alphabetic (in the alphabet)
				{
					//checks if the array[j] is equal to letter_to_search

					if (array[j].letter == letter_to_search)
					{
						count_current++; // if the character array[j] and letter_to_search is equal then increment the value of the current count
						array[j].letter = '*'; //marks as alread counted character

					}
				}

			}
			arrayout.letter = letter_to_search;
			arrayout.count = count_current;
			
			count_current = 0; // resets the value of count_current to 0
		}
	}
	return arrayout;
} */

/* *******************************************************************
 print character frequency outputs the frequencies of each character in the array  
by firstly reading the encrypted text in the file
	test @ aaaa ==> 4
	test @ helloworld = o==> 2 , l==> 3, h==> 1 , e==> 1, w==> 1 , r==> 1, d==> 1 
	@param letterType *arrayout
	@param int size
*******************************************************************/
void print_characterFrequency(letterType *arrayout, int size) // arrayout is an array of  a letterType and a paremeter of the size of the table
{
	int i;
	int j = 0;
	letterType * validCharacterFrequency;
	for (i = 0; i < size ; i++)
		
	{
		if (arrayout[i].count != -842150451) {
			cout << arrayout[i].letter << " ==> " << arrayout[i].count << endl;  //add the value of arrayout[i] to based on the letter found
			j++;

		}


	}
	
}

/* *******************************************************************
	letterType character_cout function will return the array of the character and its size
	letterTpe will get the value of the vector 
	tests if the character does  not exists in the table of characterfrequency 
	then add the letter to the characterFrequency and then count 1
	//finds the character in the characterFrequency table, if it exist return it, else return -1

*******************************************************************/

letterType * character_count(vector <char> array, int size) {
	letterType* characterFrequency  = new letterType[size];  //dynamic memory allocation, using the keyword new 
	
	int index;
	int maxindex;
	for (int i = 0; i<size; i++)
	{
		//find_character_in_table will find the character in the characterFrequency table, if it exist return it else return -1
		index = find_character_in_table(characterFrequency, size, array[i]); 
						
		// index == -1 tests if the character does  not exists in the table of characterfrequency 
		//then add the letter to the characterFrequency and then count 1
		if (index == -1) 
		{
			characterFrequency[i].letter = array[i];
			characterFrequency[i].count = 1;
			 // j++ for character frequency
			
		}
		else {
			characterFrequency[index].count ++;  // increment the value of the frequency count of characterFrequency
			
		}	 
	}
	print_characterFrequency(characterFrequency, size);
	return characterFrequency;

	


}




/* *******************************************************************
//key_option_user is the function for the user to choose a key for decryption.
// may need to be called for keyCalculator

*******************************************************************/

/*
char key_option_user(char* array, int size) {
	//const char LanguageFrequentCharacter [26] = { ' e ', ' t ', ' a ', ' o ', ' i ' , ' n ' , ' r ' , ' h ' , ' l ' , ' d ' , ' c ' , ' u ' , ' m ', ' f ', ' p ', ' g ' , ' w ', ' y ' ,' b ' ,' v ' ,' k ' ,' x ' ,' j ' ,' q ' ,' z ' };
	char possible_keys [26] = { ' e ', ' t ', ' a ', ' o ', ' i ' , ' n ' , ' r ' , ' h ' , ' l ' , ' d ' , ' c ' , ' u ' , ' m ', ' f ', ' p ', ' g ' , ' w ', ' y ' ,' b ' ,' v ' ,' k ' ,' x ' ,' j ' ,' q ' ,' z ' };
	//

	char user_choice_key;
	cin >> user_choice_key;
	char i;

	
		cout << "Below is the list of keys" << endl;
		if ((user_choice_key == 'e') || (user_choice_key == 't') || (user_choice_key == 'a') || (user_choice_key == 'l')) {
			cout << "good choice of key" << endl;
			return user_choice_key;
			//decrypt(LanguageFrequentCharacter, keyCalculator);
		}
		
		else ((user_choice_key == NULL)) {
			cout << "your choice was empty" << endl;
		}


	
	}

	*/

/*
void m_character_count(char* array, int size) {

	int i;
	int j;
	int count_current = 0;
	char letter_to_search; // current letter to search

	// i will take each character in the array, j will check the frequency of that character, 
	for (i = 0; i < size; i++) // first for loop to set a fixed value and checks the number of times that letter appears
	{
		if (is_alphabet(array[i])) //filters the alphabet letter, and do not take into account the letters 
								   //that has already been red, they are marked as *
		{

			letter_to_search = array[i];
			for (j = 0; j < size; j++) //ccounts the number of time a current value occurs
			{

				if (is_alphabet(array[j])) // uses the function is_alphabet to check if current character alphabetic (in the alphabet)
				{
					//checks if the array[j] is equal to letter_to_search

					if (array[j] == letter_to_search)
					{
						count_current++; // if the character array[j] and letter_to_search is equal then increment the value of the current count
						array[j] = '*'; //marks as alread counted character

					}
				}

			}
			cout << "Letter : " << letter_to_search << " ==> " << count_current << " times" << endl;
			count_current = 0; // resets the value of count_current to 0
		}
	}
}

void test()
{
	char c1 = 'A';
		
		int key = 7;
		c1 = c1 - key;
		cout << (65 - c1) + 65;
}
*/