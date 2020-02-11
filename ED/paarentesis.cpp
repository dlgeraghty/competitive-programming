#include<bits/stdc++.h>

using namespace std;

int main(){
        string in;
        while(getline(cin, in)){
                stack<char> s;
                bool b = true;
                for(int i = 0; i < in.size() && b; i++){
                        char c = in[i];
                        if(c == '(' || c == '{' || c == '['){
                                s.push(c);
                        }

                        if(c == ')'){
                                if(!s.empty() && s.top() == '(') s.pop();
				else{b = false; break;}
                        }
			else if( c == ']'){
				if(!s.empty() && s.top() == '[') s.pop();
				else{b = false; break;}
			}
			else if(c == '}'){
				if(!s.empty() && s.top() == '{') s.pop();
				else{b = false; break;}	
			}
                }
		if(b && s.empty()) cout << "SI" << endl;
		else cout << "NO" << endl;
        }
}

