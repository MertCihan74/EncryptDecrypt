//************************************************************************
//***       STUDENT NAME: MERT CÝHAN BAYIR                             ***
//***       STUDENT NUMBER: B201202024                                 ***
//************************************************************************
#include<iostream>						//Adding libraries
#include<string>						//String library for getline etc.

using namespace std;

string message;							//String for message
string password;						//String for password
string fullpass = "";					//String for completing the password to message
string encryptR = "";					//String for getting encrypted message
string decryptR = "";					//String for getting decrypted message

string filledPassword(string message, string password) {			//String function for sync password to message
	for (int i = 0, j = 0; i < message.length(); i++) {				//For loop to the message length from 0
		if (message[i] == 32) {										//If-else statement for space character
			fullpass += 32;											//It puts a blank (in ascii table 32 means <spc>)
		}
		else {														//Else statement for other condition(not space character)
			if (j < password.length()) {							//One more if-else statement for syncing password to message
				fullpass += password[j];							//This operation writes to fullpass password
				j++;												//j+1
			}
			else {													//Else statement for filling the password to the message for example password is 3 letter but message is 7 letter then password is going to be 7 letter so it has to be repeat   
				j = 0;												//Equality for repeating
				fullpass += password[j];							//This operation writes to fullpass password
				j++;												//j+1
			}
		}
	}
	return fullpass;												//Function returns to fullpass
}																	//End of the function
void encrypt(string message, string fullpass) {									//Void function for calculating the encrypted message
	for (int i = 0; i < message.length(); i++) {								//For loop to the message length from 0
		if (message[i] == 32) 													//If-else statement for space character
			encryptR += " ";													//It puts a blank	
		else 																	//Else statement for other condition(not space character) 
			encryptR += (((int)message[i] + (int)fullpass[i]) % 26) + 65;		//Calculating encrypted message 
	}
	cout << "ENCRYPTED MESSAGE  : " << encryptR << endl;						//Printing the encrypted message
}																				//End of the function
void decrypt(string encryptR, string fullpass) {										//Void function for calculating the decrypted message
	for (int i = 0; i < encryptR.length(); i++) {										//For loop to the message length from 0
		if (encryptR[i] == 32)															//If-else statement for space character
			decryptR += " ";															//It puts a blank
		else																			//Else statement for other condition(not space character)
			decryptR += ((((int)encryptR[i] - (int)fullpass[i]) + 26) % 26) + 65;		//Calculating decrypted message
	}
	cout << "DECRYPTED MESSAGE  : " << decryptR << endl;								//Printing the encrypted message
}																						//End of the function
int main() {																	//Main function
	cout << "ENTER A PASSWORD...: "; getline(cin, password);					//Getting password
	cout << "ENTER A MESSAGE....: "; getline(cin, message);						//Getting message
	for (int i = 0; i < password.length(); i++) {								//For loop for changing password to uppercase format
		password[i] = toupper(password[i]);										//Uppercase operation
	}
	for (int i = 0; i < message.length(); i++) {								//For loop for changing message to uppercase format
		message[i] = toupper(message[i]);										//uppercase operation
	}
	cout << "------------------------------------\n";
	cout << "PASSWORD           : " << password << endl;						//Prints the password (uppercase format) entered by the user
	cout << "MESSAGE            : " << message << endl;							//Prints the message (uppercase format) entered by the user
	cout << "------------------------------------\n";
	filledPassword(message, password);											//Calling function for getting synced password
	encrypt(message, fullpass);													//Calling function for getting encrypted message
	decrypt(encryptR, fullpass);												//Calling function for getting decrypted message
	cout << "------------------------------------\n";
}																				//End of the function
