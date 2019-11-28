#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;


int main(){
	char c;
	int i = 0;
	int v[200];
	memset(v, 0, sizeof(v));
	int biggest = 0;
	while(cin.get(c)){
		if(isalpha(c)){
			v[(int)c]++;
			if(v[(int)c] > biggest) biggest = v[(int)c];
		}
		if(c == '\n'){
			//cout << "[DEBUG][biggest] " << biggest << endl;
			for(int i = 0; i < 200; i++){
				if(v[i] == biggest){
					char s = i;
					cout << s;
				}
				//cout << v[i] << " ";
			}
			cout << " " << biggest << endl;
			biggest = 0;
			memset(v, 0, sizeof(v));
		}
	}
	
	
	return 0;
}
