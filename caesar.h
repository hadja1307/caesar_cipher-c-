#include <vector> //library used for dynamic table
#include <fstream> //library used to read and write to files

using namespace std;

class Lettertype {
	
public:
	char letter;
	int count;
}; 
//class , which will be used in all fucntions that needs it
// Class has a default of Private
//CLASS can be used and OO
// 

class Caesar {
public:
	Caesar();				//default constructor, sets shift data to 0

   
	void print_characterFrequency(Lettertype* arrayout, int my_size); //protytyep to cprint the frequency of each character
	void decrypt(int key, ifstream& inputFile, ofstream& outputFile); //prototype for decrypt function , decypt uses the key found in max index to decrypt string

	//could be in private, hence user will not need it
	
	Lettertype* character_count(vector <char> array, int size); //prototype to find occcurence of a letter in table called characterFrequency
	



};

int  max_index(Lettertype* array, int size);//function prototype 
bool is_upper(char input_char);
char to_upper(char input_char);
int keyCalculator(char LanguageFrequentCharacter, char mostFrequentCharacter); //prtototype to find key for character
bool is_alpha(char input_char); //function prototype need to be in caesar.h later on
void read_decrypted_file(string  outputFile); //read decrypt file prototype


bool is_alphabet(char input_char); //function prototype for is_alphabet
void print_vector(vector <char> arrayout); //prototype of print_vector function, whch will print the vector passed as an argument in the funcntion

//void test();
//vector, type of table i.e. char and name of table for dynamic tbales
vector <char> read_file(string inputFile);//prototype to read a file function return dynamic table 


//char key_option_user(char* array, int size); //PROTOTYPE FOR KEY OPTIONFROMT THE USER - commented, not sure it works
bool is_upper(char input_char);
char to_upper(char input_char);
int keyCalculator(char LanguageFrequentCharacter, char mostFrequentCharacter); //prtototype to find key for character
bool is_alpha(char input_char); //function prototype need to be in caesar.h later on
int  max_index(Lettertype* array, int size) ;//function prototype 
//void print_array(int* array, int size);//prints array character to the user

void read_decrypted_file(string  outputFile);
bool is_alphabet(char input_char); //function prototype for is_alphabet
void print_vector(vector <char> arrayout); //prototype of print_vector function, whch will print the vector passed as an argument in the funcntion
void decrypt(int key, ifstream & inputFile, ofstream & outputFile); //prototype for decrypt function 
//void test();
//vector, type of table i.e. char and name of table for dynamic tbales
vector <char> read_file(string inputFile);//prototype to read a file function return dynamic table 
Lettertype* character_count(vector <char> array, int size); //prototype to find occcurence of a letter in table called characterFrequency
void print_characterFrequency(Lettertype* arrayout, int my_size); //protytyep to cprint the frequency of each character

