#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Word.h"
#include <fstream>
#include <vector>
#include <list>
 


#define TABLE_SIZE 101
using namespace std;


class Dictionary {

public:
	Dictionary();
	Dictionary(int tablesze);
	void insert(Word & word);
	bool contains(string  word);
	int findprime(int i);
	bool prime(int n);
	void run(Word & word);



	Word erase(string word);
	void rehash();
	

	



private:
	vector <list<Word>> table;
	int tablesize;
	int Wordsize;
	fstream file;
};