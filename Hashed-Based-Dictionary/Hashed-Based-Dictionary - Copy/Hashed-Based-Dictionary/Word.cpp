#include "Word.h"

int Word::key(string Word,int tablesize)
{
	int index =0;
	for (int i = 0; i < Word.length(); i++) {
		index = index + Word[i];
	}
	return index % tablesize;
}



Word::Word()
{
	Word(this->word, this->definition);
	

}

Word::Word(string W, string D)
{
	this->word = W;
	this->definition = D;
	this->next = nullptr;
	

}

string Word::getWord()
{
	return word;
}

string Word::getDefinition()
{
	return definition;
}

void Word::makeWord(string W)
{
	this->word = W;
}

void Word::makeDefinition(string D)
{
	this->definition = D;
}
