//Date:     4/21/2022
//Author:   Will Arthur
//Tools:    Mackbook Pro, G++, Pico
//Purpose:  Print hello world with first and last name wrapped in '*'

#include <iostream>
#include <string>

using namespace std;

void printCenter(int, string);

int main()
{
    string name = "Will Arthur";
    string hi = "Hello World";
    
    cout << string(35, '*') << endl;
    printCenter(35, hi);
    printCenter(35, name);
    cout << string(35, '*') << endl;
    
}

void printCenter(int line, string word)
{
    cout << "**" << string(((line - 4) - word.size()) / 2, ' ') << word << string(((line - 4) - word.size()) / 2, ' ') << "**\n";
}


