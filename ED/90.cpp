#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){

	int in;
	while(cin >> in){
		unordered_map<int,int> m;	//mapa para contar 
		vector<int> v;			//vector para llevar el orden
		int x;
		while(in--){
			cin >> x;
			if(m.find(x) == m.end()){
				v.push_back(x);
			}
			m[x]++;
		}

		for(auto i: v){
			cout << i << " " << m.at(i) << endl;
		}
		cout << "---" << endl;
	}
}
