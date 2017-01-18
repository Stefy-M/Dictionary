#include "Dictionary.h"

Dictionary::Dictionary()
{
	Dictionary(this->tablesize);
}

Dictionary::Dictionary(int tablesze)
{
	int x;
	Word _word;
	this->Wordsize = 0;
	this->file.open("dictionary.txt"); 
	this->tablesize = tablesze; 
	// temporary variables to store string
	string tempWord;
	string tempDef;
	char temp;
	table.resize(tablesze);
	
	while (!file.eof()) { // Stores word and definition from file into independent variables
		file >> temp;
		file >> temp;
		getline(file, tempWord, '"');
		file >> temp;
		getline(file, tempDef, '}');
		_word.makeWord(tempWord);
		_word.makeDefinition(tempDef);
		x = _word.key(tempWord,tablesze);
		insert(_word); // Inserts the new word into hashtable
	
	}
	run(_word); // runs program for user to enter an input
	
}

void Dictionary::insert(Word & word)
{
	int index = word.key(word.getWord(), this->tablesize); 
	list<Word> & temp = table[index];
	temp.push_back(word);
	++this->Wordsize;
	//Had to comment out couldnt get it to work
	/*if (Wordsize > this->tablesize) {
		rehash();
	}*/
	
}

bool Dictionary::contains(string w)
{
	
	Word temp;
	int index;
	index = temp.key(w, tablesize); // get hash value of given string
	if (table[index].size() == 0) // there are no elements in has table
		return false;
	else {
		list <Word>::iterator itr = table[index].begin(); //iterate until given string is found
		while (itr != table[index].end()) {
			if ((*itr).getWord() == w) {
				return true;
			}
			itr++;
		}
	}
	return false;
}

//Code taken from PA3 HW link
int Dictionary::findprime(int i)
{
	int nextprime = i;
	bool found = false;

	while (!found) {
		nextprime++;
		if (prime(nextprime)) {
			found = true;
		}
	}
	return nextprime;

}

bool Dictionary::prime(int n)
{
	for (int i = 2; i <= n / 2; i++) {
		if (n % 1 == 0)
			return true;
	}
	return false;
}

void Dictionary::run(Word & word)
{
	string input;
	

	cout << "(ALL CAPS) Enter Word: ";
	cin >> input;
	int index = word.key(input, tablesize);
	list <Word> ::iterator itr = table[index].begin();
	if (contains(input)) { // iterates until itr is pointing at the word containing the definition
		while (itr != table[index].end() && (*itr).getWord() != input)
			itr++;

	}
	else { // if word isnt in dictionary.txt file
		cout << "The word " << input << " does not exist in this dictionary..." <<endl;
		return;
	}
	cout <<"Defintion: "  << (*itr).getDefinition() << endl;
}

void Dictionary::rehash()
{
	vector<list<Word>*> newTable;
	Word temp;
	
	int oldsize = this->tablesize;
	int newsize = findprime(tablesize*2);
	newTable.resize(newsize); // tables need
	this->tablesize = newsize;
	for (int i = 0; i < oldsize; i++)
	{
		auto itr = table[i].begin(); // an auto variable iterator that starts at beginning
		while (itr != table[i].end()) { // itrerate through table until at end
			if ((*itr).getWord() != "") { // add all old data into new hastable
				string str = (*itr).getWord();
				int index = temp.key(str, tablesize);
				newTable[index]->push_back(*itr);
				itr++;

			}
		}
	}
	
	
	
	

}
