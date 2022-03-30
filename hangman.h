/************************************************************
*	File Name:		hangman.h                               *
*	Author:       Mohammed Alturki                          *
*	Date Created:           10/26/2020                      *
*	Purpose:  Header file for Hangman game					*
************************************************************/

#ifndef _HANGMAN_H
#define _HANGMAN_H

#include <iostream>
#include <cstring> 
#include <fstream>

using namespace std;

/*  Function prototypes */
void printLettersGuessed(bool* , char*);
void printWord(char *, char *);
void printStage(int);
 
#endif