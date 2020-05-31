#include <iostream>
#include <string>
#include <sstream>
#include "stack_eda.h"

using namespace std;

bool resuelvecaso(){

	string line;

	getline(cin, line, '\n');

	if(!cin) return false;

	stack<char> q;

	bool r = true;

	for(int i = 0; i < line.size(); i++){
		char c = line[i];
		if(c == '(' || c == '{' || c == '[') q.push(c);

		else if(c == ')' || c == '}' || c == ']'){ 
			if(q.empty()){
				r = false;
				break;
			}else{
				if(c == ')' && q.top() == '(')
					q.pop();

				else if(c == '}' && q.top() == '{')
					q.pop();

				else if(c == ']' && q.top() == '[')
					q.pop();
				else{
					r = false;
					break;
				}
			}
		}
	}


	if(r && q.empty()) printf("SI\n");
	else printf("NO\n");

	return true;

}

int main(){

	while(resuelvecaso());

	return 0;

}
