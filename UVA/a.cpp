#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

	bool endofcases = false;
	bool endofblock = false;

	while(!endofcases){
		//read the data
		endofblock = false;
		vector<vector<int>> v;
		while(!endofblock){
			char p;
			char c;
			string useless;

			vector<int> w(255,0);
			for(int i = 0; i < 5; i++){
				cin >> c;
				if(c == 'e' || p == 'e'){
					endofblock = true;
					getline(cin, useless);
					break;
				}
				else if(c == '#' || p == '#'){
					endofblock = true;
					endofcases = true;
					break;
				}else if(c == '\n') break;
				else{
					cin.ignore();
					cin >> p;
					w[(int)c] = (int)p;
					cin.ignore();
				}
//				cout << "DEBUG[c][p] " << c << p << " ";
			}
//			cout << endl;
			v.push_back(w);

		}
/*
		for(auto i: v){
			for(auto x: i){
				if(x != 0) cout << (char)x << " ";
			}
			cout << endl;
		}
		cout << "--------------------------------------------" << endl;
*/

		//calculate:
		int min = INT_MAX;
		int min_index = -1;
		for(int i = 0; i < v.size()-1; i++){
				int current = 0;
			for(int j = 0; j < v[i].size(); j++){
				if(v[i][j] != 0 && current < min && i != j){
//					cout << "analizing the [i] [c] " << i << " " << v[i][j] << endl;
					for(int x = 0; x < v.size(); x++){
//						for(y = 0; y < v[x].size(); y++){
							if(v[i][j] != v[x][j] ){
//								cout << "holita" ;
								current++;
							}
//						}
					}
				}
			}
//			cout << "current " << current << endl;
			if(current < min ){
				min = current;
				min_index = i;
			}
		}
		if(min_index >= 0) cout << min_index + 1<< endl;
	}
        return 0;
}

