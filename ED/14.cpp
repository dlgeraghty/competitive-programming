#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

	string s;
	while(getline(cin, s)){
		int j = 0;
		int k = s.size();
		string parte1, parte2;
		while(j < k){
			parte1 += s[j];
			if(j + 1 < k)parte2 += s[j+1];
			j+=2;
		}
		reverse(parte2.begin(), parte2.end());
		parte1.append(parte2);
		//cout << parte1 << endl;
		string f;
		stack<char> pila;
		for(char s: parte1){
			if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U'){
				while(!pila.empty()){
					f+=pila.top();
					pila.pop();
				}
				f += s;
			}else{
				pila.push(s);
			}
		}
		while(!pila.empty()){
			f+=pila.top();
			pila.pop();
		}
		cout << f << endl;
	}


	return 0;
}

