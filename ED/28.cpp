#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){

	int n;
	while(cin >> n && n != 0){
		map<string, int> m;
		string s, g;

		int i = n;
		cin.ignore();
		while(i--){
			getline(cin, s, '\n');
			getline(cin, g);
			int suma;
			if ( g == "CORRECTO")
				suma = 1;
			else suma = -1;
			if(m.count(s) == 0)
				m.insert(pair<string, int> (s, suma));
			else m[s] += suma;
		}
		for(auto x = m.begin(); x != m.end(); ++x)
			if(x->second != 0)
				cout << x->first << ", " << x->second << "\n";

		cout << "---\n";

	}


	return 0;
}

