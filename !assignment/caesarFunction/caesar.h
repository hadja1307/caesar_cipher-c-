#include <vector>
#include <fstream> //library used to read and write to files

using namespace std;

struct letterType {
	char letter;
	int count;
}; //CHANGE IT , GLOBAL VARIABLES NOT ALLOWED BASED ON STYLE GUIDE
//STRUCT global variable, which will be used in all fucntions that needs it
//struct and class are similar, the difference is that struct has a default of public memeber, whereas Class has a default of Private
//CLASS can be used and OO

//char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//const char LanguageFrequentCharacter = 'e' ; //

//char key_option_user(char* array, int size); //PROTOTYPE FOR KEY OPTIONFROMT THE USER - commented, not sure it works
bool is_upper(char input_char);
char to_upper(char input_char);
int keyCalculator(char LanguageFrequentCharacter, char mostFrequentCharacter); //prtototype to find key for character
bool is_alpha(char input_char); //function prototype need to be in caesar.h later on
int  max_index(letterType* array, int size) ;//function prototype 
void print_array(int* array, int size);//prints array character to the user

bool is_alphabet(char input_char); //function prototype for is_alphabet
void print_vector(vector <char> arrayout); //prototype of print_vector function, whch will print the vector passed as an argument in the funcntion
void decrypt(int key, ifstream & inputFile, ofstream & outputFile); //prototype for decrypt function 
//void test();
//vector, type of table i.e. char and name of table for dynamic tbales
vector <char> read_file(string inputFile);//prototype to read a file function return dynamic table 
letterType* character_count(vector <char> array, int size); //prototype to find occcurence of a letter in table called characterFrequency
void print_characterFrequency(letterType* arrayout, int my_size); //protytyep to cprint the frequency of each character

