#include <iostream>

using namespace std;


int main(){
	char c;
	int i = 0;
	while(cin.get(c)){
		if(c == '"')
			if(i == 1){
				cout << "''";
				i = 0;
			}
			else{
				cout << "``";
				i++;
			}

		else
			cout << c;		
		
	}
	return 0;
}
