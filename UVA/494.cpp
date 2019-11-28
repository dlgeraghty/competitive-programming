#include <iostream>
#include <ctype.h>

using namespace std;


int main(){
	char c;
	int i = 0;
	bool prevAlpha = false;
	while(cin.get(c)){
		if(!isalpha(c)){
			if(prevAlpha){i++; prevAlpha = false;}
			}
		else
			prevAlpha = true;
		if(c == '\n'){ cout << i << endl; i = 0;};
	}

	return 0;
}
