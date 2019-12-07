#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

	int in;
	while(cin >> in && in != 0){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < in; i++){
		        int a, b;
			cin >> a >> b;
			if(a == n || b == m) cout << "divisa" << endl;
			else if(a > n){
				if(b > m) cout << "NE" << endl;
				else cout << "SE" << endl;
			}else if(a < n){
				if(b > m) cout << "NO" << endl;
				else cout << "SO" << endl;		
			}	
		}
	       			       
	}

	return 0;
}
