/*
 * Add Correct Numbers
 * Name: Matthew Olker and Alec Cohan
 * Date: 1-22-2019
 * Class: CSC-4510
 * Location: molker/csc4510/P1/Source
 * This program takes in two integer inputs and returns the value of 
 * the sum of the absolute value of the integers
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]){
	int a, b;
	cout << "Enter 2 Numbers to add:" << endl;
	cin >> a >> b;
	cout << a << " + " << b << " = " << (a+b);
	return 0;
}