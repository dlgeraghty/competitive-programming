#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

int main(){


	int in;
	cin >> in;
	map<string, int> m;
	while(in--){
		string s;
		cin >> s;
		if(m.count(s)) m.at(s)++;
		else m.insert(pair<string, int>(s, 1));
		getline(cin, s);
	}
	map<string, int>::iterator itr;
	for(itr = m.begin(); itr != m.end(); itr++){
		cout << itr->first << " " << itr->second << endl;
	}

	return 0;
}
