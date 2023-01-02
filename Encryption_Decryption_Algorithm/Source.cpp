#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

string RailFence_encrypt(string text, int key);
string RailFence_decrypt(string text, int key);



                                       // Different Choices Table
short int Encry_decry_choice() {
	short encry_decry_choice;

	cout << "1) Encrption\n2) Decryption\n\nEnter your choice in number:";
	cin >> encry_decry_choice;

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return(encry_decry_choice);
}
short int Method_choice() {

	cout << "\n\n#############################################################";
	cout << "\n\n1) Our Own Encryption Algorithm\n2) Already Defined Encryption Algorithms";
	cout << "\n\nEnter your choice:";
	short int method_choice;
	cin >> method_choice;


	
	return(method_choice);  // return(parameter);
}
short int predefined_algorithm() {

	cout << "\n\n###############################################################";
	int predefined_algorithm_choice;
	cout << "\n\n1) Ceaser Cipher\n2) ROT13\n3) Rail Fence\n\n";
	cout << "Enter your choice:";
	cin >> predefined_algorithm_choice;

	return(predefined_algorithm_choice);
}




											// Own Encryption Algorithm
void Our_own_encrypt_algorithm() {
	string text;
	string plain_text;
	string cipher_text;
	int key;

	cout << "\n\nEnter Plain Text to Encrypt:";
	cin.ignore();  
	getline(cin, plain_text);
	cout << "Enter Key between 1 and 100:";
	cin >> key;
	
	//if to check the key from 1 to 100
	if (key > 0 && key <= 100) {

		// Call the Rail Fence algorithm to encrypt the plain text and assign it to text
		text = RailFence_encrypt(plain_text, 12);


		// text.length()
		// using for loop to rev the string and to increment the key in each single character
		for (int i = text.length() - 1; i >= 0; i--) {
			char result = static_cast<int>(text[i]) + key;
			cipher_text = cipher_text + result;
		}

		cout << "\n\nThe Encrypted Text: " << cipher_text << endl;
	}
	else
		cout << "\nInvalid Key";
}


void Our_own_algorithm_decryption() {
	string plain_text;
	string text;
	string cipher_text;
	int key;

	cout << "\n\nEnter Cipher Text to Decrypt:";
	cin.ignore();
	getline(cin,cipher_text);
	cout << "Enter your Key between 1 and 100:";
	cin >> key;

	//if to check the key from 1 to 100
	if (key > 0 && key <= 100) {

		// using for loop to rev the string and to increment the key in each single character
		for (int i = cipher_text.length() - 1; i >= 0; i--) {
			char result = static_cast<int>(cipher_text[i]) - key;
			plain_text = plain_text + result;
		}

		// Call the Rail Fence algorithm to Decrypt to plain text and assign it to text
		text = RailFence_decrypt(plain_text, 12);

		cout << "\n\nThe Decrypted Text: " << text << endl;

	}
	else
		cout << "\nInvalid Key";
}


										// Ceaser cipher Encryption Algorithm
void Ceaser_cipher_encrypt() {
		string input;
		string result;
		short int key;

		cout << "\n\nEnter Plain to Encrypt:";
		cin.ignore();
		getline(cin, input);

		cout << "Enter your key from 1 to 25:";
		cin >> key;

		//if to check the key from 1 to 25
		// using for loop to increment the key in each single character
		if (key > 0 && key <= 25) {
			for (unsigned int i = 0; i < input.length(); i++) {

				// for upper case alphabet incrementation
				if (isupper(input[i])) {
					if (input[i] != ' ')
						result += char(int(input[i] + key - 65) % 26 + 65); // A = ascii(65)
					else
						result += input[i];
				}

				// for	lower case alphabet incrementation
				else {    // alphabet "a"
					if (input[i] != ' ')
						result += char(int(input[i] + key - 97) % 26 + 97);  // a = ascii(97)
					else
						result += input[i];
				}
			}
			cout << "\n\nThe Encrypted Text: " << result;
		}
		else
			cout << "\nInvalid Key";
}

void Ceaser_cipher_decrypt() {
	string input;
	string result;
	short int key;

	cout << "\n\nEnter Cipher Text To Decrypt:";
	cin.ignore();
	getline(cin, input);

	cout << "Enter your key from 1 to 25:";
	cin >> key;

		
		//if to check the key from 1 to 25
		// using for loop to increment the key in each single character
	if (key > 0 && key <= 25) {
		for (unsigned int i = 0; i < input.length(); i++) {

			// for upper case alphabet decrementation
			if (isupper(input[i])) {
				if (input[i] != ' ')
					result += char(int(input[i] - key + 26 - 65) % 26 + 65);
				else
					result += input[i];
			}

			// for lower case alphabet decrementation
			else {
				if (input[i] != ' ')
					result += char(int(input[i] - key + 26 - 97) % 26 + 97);
				else
					result += input[i];
			}
		}
	
		cout << "\n\nThe Decrypted Text: " << result;
	}
	else
		cout << "\nInvalid Key";
}


										// ROT13 Encryption Algorithm
void ROT13_encrypt() {
	string input;
	string result;

	cout << "\n\nEnter a Plain Text To Encrypt:";
	cin.ignore();
	getline(cin, input);

	const short key = 13;


	// using for loop to increment the key in each single character
	for (unsigned int i = 0; i < input.length(); i++) {

		// for upper case alphabet incrementation
		if (isupper(input[i])) {
			if (input[i] != ' ')
				result += char(int(input[i] + key - 65) % 26 + 65); // A = ascii(65)
			else
				result += input[i];
		}

		// for lower case alphabet incrementation
		else {
			if (input[i] != ' ')
				result += char(int(input[i] + key - 97) % 26 + 97); // a = ascii(97)
			else
				result += input[i];
		}
	}
	cout << "\n\nThe Encrypted TEXT: " << result << endl;
}

void ROT13_decrypt() {
	string input;
	string result;

	cout << "\n\nEnter a Cipher Text To Decrypt:";
	cin.ignore();
	getline(cin, input);

	unsigned short int key = 13;


	// using for loop to decrement the key in each single character
	for (unsigned int i = 0; i < input.length(); i++) {

		// For upper case alphabet decrementation
		if (isupper(input[i])) {
			if (input[i] != ' ')
				result += char(int(input[i] - key + 26 - 65) % 26 + 65);
			else
				result += input[i];
		}


		// For Lower case alphabet decrementation
		else {
			if (input[i] != ' ')
				result += char(int(input[i] - key + 26 - 97) % 26 + 97);
			else
				result += input[i];
		}
	}
	cout << "\n\nThe Decrypted TEXT: " << result << endl;
}


									// Rail Fence Encryption Algorithm

string RailFence_encrypt(string text, int key)
{
	// create the matrix to cipher plain text 
	// key = rows , length(text) = columns 
	char rail[100][1000];

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i = 0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	// to find the direction 
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i = 0; i < text.length(); i++)
	{
		// check the direction of flow 
		// reverse the direction if we've just 
		// filled the top or bottom rail 
		if (row == 0 || row == key - 1)
			dir_down = !dir_down;

		// fill the corresponding alphabet 
		rail[row][col++] = text[i];

		// find the next row using direction flag 
		dir_down ? row++ : row--;
	}

	//now we can construct the cipher using the rail matrix 
	string result;
	for (int i = 0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			if (rail[i][j] != '\n')
				result.push_back(rail[i][j]);

	return(result);
}


string RailFence_decrypt(string cipher, int key)
{
	// create the matrix to cipher plain text 
	// key = rows , length(text) = columns 
	char rail[100][1000];

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i = 0; i < key; i++)
		for (int j = 0; j < cipher.length(); j++)
			rail[i][j] = '\n';

	// to find the direction 
	bool dir_down;

	int row = 0, col = 0;

	// mark the places with '*' 
	for (int i = 0; i < cipher.length(); i++)
	{
		// check the direction of flow 
		if (row == 0)
			dir_down = true;
		if (row == key - 1)
			dir_down = false;

		// place the marker 
		rail[row][col++] = '*';

		// find the next row using direction flag 
		dir_down ? row++ : row--;
	}

	// now we can construct the fill the rail matrix 
	int index = 0;
	for (int i = 0; i<key; i++)
		for (int j = 0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];


	// now read the matrix in zig-zag manner to construct 
	// the resultant text 
	string result;

	row = 0, col = 0;
	for (int i = 0; i< cipher.length(); i++)
	{
		// check the direction of flow 
		if (row == 0)
			dir_down = true;
		if (row == key - 1)
			dir_down = false;

		// place the marker 
		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		// find the next row using direction flag 
		dir_down ? row++ : row--;
	}

	return(result);
}

void main() {
	char continue_choice;


	// do while loop start
	do {

		// initial encrypt or decrypt choice
		int initial_choice;
		initial_choice = Encry_decry_choice();

		// Encrypt Method choice
		if (initial_choice == 1) {
			int method_choice = Method_choice();

			// Our Own Encryption Algorithm Function Call
			if (method_choice == 1) {
				Our_own_encrypt_algorithm();
			}

			// Predefined Alogorithm
			else if (method_choice == 2) {
				int predefined_algorithm_choice = predefined_algorithm();

				// Ceaser Cipger Encryption Function Call
				if (predefined_algorithm_choice == 1) {
					Ceaser_cipher_encrypt();
				}

				// ROT13 Encryption Function Call
				else if (predefined_algorithm_choice == 2) {
					ROT13_encrypt();
				}

				// Rail Fence Encryption Frunction Call
				else if (predefined_algorithm_choice == 3) {

					cout << "\n\nEnter Plain Text to Encrypt:";
					string text;
					cin.ignore();
					getline(cin, text);

					cout << "Enter key from 1 to 15:";
					int key;
					cin >> key;

					if (key > 0 && key <= 15)
						cout << "\n\nThe Encrypted Text:" << RailFence_encrypt(text, key) << endl;
					else
						cout << "\nInvalid Key!!";
				}
			}

		}

		// Decrypt Method Choice
		else if (initial_choice == 2) {
			int method_choice = Method_choice();

			// Our Algorithm Decryption Function Call
			if (method_choice == 1) {
				Our_own_algorithm_decryption();
			}

			// Our Predefine Algorithm Decryption
			else if (method_choice == 2) {
				int predefined_algorithm_choice = predefined_algorithm();

				// Ceaser Cipher Decryption Function Call
				if (predefined_algorithm_choice == 1) {
					Ceaser_cipher_decrypt();
				}

				// ROT13 Decryption Function Call
				else if (predefined_algorithm_choice == 2) {
					ROT13_decrypt();
				}

				// Rail Fence Decryption Frunction Call
				else if (predefined_algorithm_choice == 3) {

					cout << "\n\nEnter Cipher text to Decrypt:";
					string text;
					cin.ignore();
					getline(cin, text);

					cout << "Enter key from 1 to 15:";
					int key;
					cin >> key;

					if (key > 0 && key <= 15)
						cout << "\n\nThe Decrypted Text:" << RailFence_decrypt(text, key) << endl;
					else
						cout << "\nInvalid Key!!";

				}
			}

		}
		cout << "\n\nDo you want to continue Y/n:";
		continue_choice = _getche();
		system("cls");
	}while(continue_choice == 'y' || continue_choice == 'Y');
	system("PAUSE");
}