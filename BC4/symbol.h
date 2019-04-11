/* Author: I. Shore
 * Date: 02/27/19
 * Comments:
 *    This is the header file for the symbol table class
 *    and the helper class item.
 *
 *    Symbol is an implementation of a symbol table using
 *    an array of c++ standard lists with item as the
 *    elements.
 *
 *    The hash function uses PIM as the position importance multiplier
 *    This simply multiplies the value of the char by this number
 *    and its position in the word to create a numerical value for the word
 *
 *    PRIME is the number of buckets that the table has, and both
 *    PRIME and PIM can be changed to adjust the way that words are
 *    placed into the table.
 */
#ifndef SYMBOL_H
#define SYMBOL_H

#include <list>
#include <string>

using namespace std;

#define PRIME 211
#define PIM 3

class item{
   public:
       //variables
       string var;
       int val;
       
       //methods
       void updateVal(int newVal){val = newVal;}      

       item(){var="";};
       ~item(){};

       //overloaded = operator
       item& operator = (const item &other){
          this->var = other.var;
          this->val = other.val;
          return *this;
       }

       //overloaded == operator
       bool operator ==(const item &other){
          if(this->var == other.var && this->val == other.val)
             return true;
          else
             return false;
       }
   private:
       //variables
};

class symbol
{
   public:
      //variables

      //constructor
      symbol();
      ~symbol();

      //methods
      void dump();
      void remove(string var);
      
      item* lookup(string word);
      item* insert(string var);
      void stats();

   private:
      //variables
      list<item> *table;      

      //methods
      int hash(string word);
      item* table_lookup(string word,int pos);
           
};

#endif
