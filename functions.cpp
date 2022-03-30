/************************************************************
*	File Name:		functions.cpp                           *
*	Author:       Mohammed Alturki                          *
*	Date Created:           10/26/2020                      *
*	Purpose:  Function file for Hangman	Game		        *
************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/*	FUNCTION:  printStage
	This function prints out the diagram representing each
	stage of the game.  There are seven different diagrams.
*/
void printStage(int stage)
{
	switch(stage)
	{	
		case 0:   	
					cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;
		
		case 1:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 2:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 3:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 4:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 5:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |      \\      \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 6:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |    / \\      \n";
					cout << "     |              \n";
					cout << "     |   DEAD!      \n";
					cout << "  --------------    \n";
					break;	
	}
	cout << "\n\n";
}

//this function prints the word in underscores 
void printWord(char word[], char underScores[])
{
	int wordCount = strlen(word);
    cout << endl << "********************************************************************************" << endl << endl;
	cout << "word: ";

	for (int i=0; i<wordCount; i++)
    {
		cout << underScores[i] << " ";
	}
    cout << endl;
}

//this function prints the letter the user has guessed
void printLettersGuessed(bool userGuesses[], char alphabet[])
{
    cout << "LETTERS YOU HAVE ALREADY GUESSED: ";
    for(int i=0; i<26; i++)
    {
        if(userGuesses[i]==true)
        {
            cout << alphabet[i] << " ";
        }
         
    }
    cout << endl << endl << "--------------------------------------------------------------------------------" << endl;
}