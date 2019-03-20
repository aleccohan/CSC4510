#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <list>
#include <cstdlib>
#include <time.h>

#include "symbol.h"

using namespace std;

/* This is a basic constructor
 * It simply allocates the space for the table
 */
symbol::symbol()
{
   table = new list<item>[PRIME];
}

/* This is a basic deconstructor 
 * It simply deallocates the space for the table
 */
symbol::~symbol()
{
   delete[] table;
}

/* This dumps out all the variables and values in the
 * symbol table
 */
void symbol::dump()
{
   for(int i=0;i<PRIME;i++){
      for(list<item>::iterator it=table[i].begin();it!=table[i].end();++it){
         cout << " " << (*it).val << " " << (*it).var << endl;
      }
   }
}

/* Function: insert(string, int)
 *
 * Pre-condition: This is a private function because it should only
 *    be called by the other member function lookup, since insert does
 *    not check if that word has already been inserted into the table
 *    you may end up with more than one entry for a word. I chose to not
 *    check for multiple entries in insert since lookup already did that
 *    and I opted for more effiency and assumed the implementer would
 *    use the code correctly
 *
 * Post-condition: The pointer to the new item
 *    will be returned and a default value of 0 will be placed into the
 *    item's val
 */
item* symbol::insert(string word,int hash_pos)
{
   cout << "Called insert with " << word << endl;
   item newItem = item();
   newItem.var = word;
   table[hash_pos].push_back(newItem);
   item * ref = table_lookup(word,hash_pos);
    ref->val = 0; 
   return ref;
}

/* This function has not been implemented as it is not
 * needed at this time, but later projects that involve scope rules
 * will need a remove function
 */
void symbol::remove(string var)
{
   int hash_num = hash(var);
   //table[hash_num].remove();
}

/* function: lookup(string)
 *
 * Pre-conditions: The only pre condition is that the table
 *    has been allocated through the constructor
 *
 * Post-conditions: If the word is already in the table
 *    a pointer will be returned to that item in the list
 *
 *    If the word is not already in the table than insert
 *    will be called, and the pointer that insert returns will be
 *    returned as well
 *
 * Comments: This function is the gateway to the main functionality
 *    of the class, it allocates and inserts new items when needed
 *    and returns pointers to items in the list.
 */
item* symbol::lookup(string word)
{
   int hash_num = hash(word);
   item *reference = table_lookup(word,hash_num);
   if(reference == NULL){
      //word is not in symbol table
      return insert(word,hash_num);
   }
   else{
      return reference;
   }
}

/*
 *
 */
void symbol::stats()
{
   dump();
}

/* Function: hash(word)
 *
 * Pre-condition: There are no pre conditions
 *
 * Post-condition: A numerical value will be returned for the
 *   word. Each word has a unique value indicated by the hash function
 *   but multiple words may share the same value. This situation is
 *   minimized, but still possible.
 */
int symbol::hash(string word)
{
   int val=0;
   //I'm going to convert the word or variable name
   //into a numerical value. A simple sum of the
   //values of the chars would result in many words
   //having the same value, for example tt and rs would
   //have the same value. Instead I will convert the word
   //into a numerical value taking into account the position
   //of the chars in each word. This will give a greater distribution
   //of the inputs into the real hash function that is simply
   //moding the value of the word by the prime.
   for(int i=0;i<word.length();i++){
      val += word[i] * (i+1) * PIM;
         
   }
   
   val %= PRIME;
   return val;
}

/* Function: table_lookup(string, int)
 *
 * Pre-conditions: The table
 *    has been allocated through the constructor
 *    and pos is the value that hash returned when called
 *    with the word
 *
 * Post-conditions: If the word was at the list indicated
 *    by the pos a pointer to that item is returned
 *    
 *    if the word is not in the list a NULL pointer
 *    is returned to indicate that the word is not
 *    in the table
 */
item* symbol::table_lookup(string word, int pos)
{
   for(list<item>::iterator it=table[pos].begin();it!=table[pos].end();++it){
      if((*it).var == word){
         item * pointer = &(*it);
         return pointer;
      }
   }
   //if we are here the word that was looked up was not in the list and
   //should be inserted
   return NULL;
}
