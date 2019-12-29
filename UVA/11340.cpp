#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){


	int N;
	cin >> N;
	while(N--){
		int K;
		cin >> K;
		vector<double> table(256,0);
		for(int i = 0; i < K; i++){
			char c;
			cin >> c;
			int money;
			cin >> money;
			table[(int) c] = money;
		}
		unsigned int M;
		cin >> M;
		long double sum = 0;
		string s;
		cin.ignore();
		for(int i = 0; i < M; i++){
			getline(cin, s);
			//cout << s << endl;
			for(int j = 0; j < s.size(); j++)
				sum += table[(int) s[j]];
		}
		if(sum == 0) cout << "0.00$" << endl;
		else cout << sum/100 << "$" << endl;
	}

	return 0;
}
