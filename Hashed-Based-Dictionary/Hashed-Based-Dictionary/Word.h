#ifndef WORD_H
#define WORD_H




#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "json.hpp"


using namespace std;


class Word {
public:
	int key(string Word,int tablesize);
	Word();
	Word(string W, string D);
	string getWord();
	string getDefinition();
	void makeWord(string W);
	void makeDefinition(string D);



private:
	
	string word;
	string definition;
	Word *next;
	
};

#endif