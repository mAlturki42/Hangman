/************************************************************
*	File Name:		hangman.cpp                             *
*	Author:       Mohammed Alturki                          *
*	Date Created:           10/26/2020                      *
*	Purpose:  Game of Hangman								*
************************************************************/

#include <iostream>
#include <fstream>
#include "hangman.h" //including the header file

using namespace std;

int main()
{ 
    char word[21];
    char underScores[21];
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool userGuesses[26];
    char response;  //to store user choice to continue play or not
    bool runAgain = false; 
    bool wordGuessed = false; //flag to tell if user guessed
    bool alreadyGuessed = false;
    int stage = 0;
    int wordLength;
    char letter;
    bool letterFound = false; 
    int i;
    

    ifstream wordFile;
    //get word from wordbank file
    wordFile.open("wordBank.txt");
    if(!wordFile)  //checking if the file can't be accessed
    {
        cout << "Could not open file wordBank.txt." << endl;
    }
    else //if it can be accessed: 
    { 
        do
        {
            stage=0;
            letterFound = false;
            wordGuessed = false;
            //initialize userGuess array 
            for(i=0; i<26; i++){
                userGuesses[i] = false;
            }
        
            for(i=0; i<21; i++){
                underScores[i]='_';
            }

            //getWord 
            wordFile >> word;
            while(stage < 6 && wordGuessed == false)
            {
                
                printWord(word, underScores);
                printStage(stage);
                printLettersGuessed(userGuesses, alphabet);
                    
                
                do
                {
                    cout << "  WHAT LETTER DO YOU GUESS?  "; 
                    alreadyGuessed = false;
                    cin >> letter;
                    letter = toupper(letter); //the toupper function will make letter uppercase
                    
                    for(int i=0; i<26; i++)
                    {
                        if(letter == alphabet[i]) 
                        {
                            if(userGuesses[i]) //checking if the letter is already entered or not
                            {
                                alreadyGuessed = true;
                                cout << "You have already guessed this letter" << endl;
                            }
                        }
                    }
                } while(alreadyGuessed);

                for(i=0; i<26; i++)
                {
                    //if the guess is good update guess
                    if(letter == alphabet[i])
                    { 
                        userGuesses[i] = true;  
                    }
                }
                
                //if guess is correct tell the user 
                for(i=0; i<21; i++)
                {
                    if(letter == word[i])
                    {   
                        underScores[i]= word[i];
                        letterFound=true;
                        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> CORRECT! >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
                        cout << "  Press ENTER to continue.";
                        cin.ignore();
                        cin.get(); 
                    }
                }

                //if guess is wrong print wrong and print the stage 
                if(letterFound == false)
                { 
                    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  WRONG!  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl; 
                    cout << "  Press ENTER to continue.";
                    cin.ignore();
                    cin.get(); 
                    stage++;
                    printStage(stage);  
                }
                
                wordLength = strlen(word);

                //if guess is equal to word they won so exit
                if(strncmp(underScores,word,wordLength)==0)
                {
                    wordGuessed = true;
                    cout << endl << "                         YES!   THE WORD WAS: " << word << endl;
                    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> YOU WIN! >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
                    runAgain = false;
                }
                letterFound=false;
            }
            cout<<"\n\n Do you want to play HANGMAN again? (y/n) " << endl;
            cin>>response;

            // Checks if user response is 'N' or 'n' then stop
            if(response == 'N' || response == 'n')
            {
                runAgain=false;
                break;
            }
        }while(response == 'Y' || response == 'y'); // End of do - while loop

        
        wordFile.close(); //"wordBank.txt"

    }
    return 0;
}

