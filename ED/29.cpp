#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin >> n;
	while(n--){
		int in, a, prev_index, long_actual = 0, long_max = 0;
		cin >> in;
		unordered_map<int, int> m;
		for(int i = 0; i < in; i++){
//			cout << "mapa: " << endl;

//			for(auto x = m.begin(); x != m.end(); ++x)
//						cout << x->first << " " << x-> second << endl;
			cin >> a;
			if(m.count(a) > 0){
				prev_index = m.at(a);
//				printf("se repite: %d prev_index: %d\n", a, prev_index);
				long_max = max(long_actual, long_max);
				if( i - long_actual > prev_index)
					long_actual ++;
				else
					long_actual = i - prev_index;
			}else {
				long_actual++;
			}
			long_max = max(long_actual , long_max);
//			printf("evaluando %d con longitud actual: %d y longitud maxima: %d\n", a, long_actual, long_max);
			m[a] = i;
		}
//for(auto i = m.begin(); i != m.end(); ++i)
//			cout << i->first << " " << i-> second << endl;
		printf("%d\n", long_max);
	}

	return 0;
}

