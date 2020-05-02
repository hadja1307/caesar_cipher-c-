#include <vector> ///library used for dynamic table
#include <fstream> ///library used to read and write to files

using namespace std;

class Lettertype {
	
public:
	char letter;
	int count;
}; 

/// Class has a default of Private

/// The main aim of OOP with the use of a class  is to bind together the data and 
/// the functions that operate on them so that no other part of the code can access this data except that function.

class Caesar {
public:
	Caesar();	///default constructor, sets shift data to 0

   
	void print_characterFrequency(Lettertype* arrayout, int my_size); ///protytype to cprint the frequency of each character
	void decrypt(int key, ifstream& inputFile, ofstream& outputFile); ///prototype for decrypt function , decypt uses the key found in max index to decrypt string

	///could be in private, hence user will not need it
	/// the user's input will only be needed for the decrypt and print character frequency for the caesar class
	
	Lettertype* character_count(vector <char> array, int size); ///prototype to find occcurence of a letter in table called characterFrequency
	



};

int  max_index(Lettertype* array, int size);
bool is_upper(char input_char);
char to_upper(char input_char);
int keyCalculator(char LanguageFrequentCharacter, char mostFrequentCharacter); 
bool is_alpha(char input_char); 
bool is_alphabet(char input_char); 
void print_vector(vector <char> arrayout); 

///void test();
///vector, type of table i.e. char and name of table for dynamic tbales
vector <char> read_file(string inputFile);///prototype to read a file function return dynamic table 

void read_decrypted_file(string  outputFile);
///char key_option_user(char* array, int size); ///PROTOTYPE FOR KEY OPTIONFROMT THE USER - commented, not sure it worksvoid read_decrypted_file(string  outputFile); //prototype to print the 50 characters of decrypted text to the user
bool is_upper(char input_char);
char to_upper(char input_char);
int keyCalculator(char LanguageFrequentCharacter, char mostFrequentCharacter); ///prtototype to find key for character
bool is_alpha(char input_char); ///function prototype need to be in caesar.h later on
int  max_index(Lettertype* array, int size) ;///function prototype 
///void print_array(int* array, int size);///prints array character to the user

bool is_alphabet(char input_char); ///function prototype for is_alphabet
void print_vector(vector <char> arrayout); ///prototype of print_vector function, whch will print the vector passed as an argument in the funcntion
void decrypt(int key, ifstream & inputFile, ofstream & outputFile);  
///void test();
///vector, type of table i.e. char and name of table for dynamic tbales
vector <char> read_file(string inputFile);///prototype to read a file function return dynamic table 
Lettertype* character_count(vector <char> array, int size); ///prototype to find occcurence of a letter in table called characterFrequency
void print_characterFrequency(Lettertype* arrayout, int my_size); 

