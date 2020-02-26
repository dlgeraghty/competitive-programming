#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

struct accidente{
	string date;
	int v;
};

int main(){

	int in;
	while(cin >> in){
		char x;
		stack<accidente> s;
		for(int i = 0; i < in; i++){
			accidente f;
			cin >> f.date >>  f.v;
			while(!s.empty() && s.top().v <= f.v) s.pop();
				if( !s.empty()) cout << s.top().date;
				else cout << "NO HAY";
			cout << endl;
			s.push(f);
		}
	cout << "---" << endl;
	}
	return 0;
}

