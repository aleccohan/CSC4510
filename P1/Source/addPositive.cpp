#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]){
	int a, b;
	cout << "Enter 2 Numbers to add:" << endl;
	cin >> a >> b;
	cout << a << " + " << b << " = " << (abs(a)+abs(b));
	return 0;
}