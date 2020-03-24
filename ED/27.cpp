#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include "bintree_eda.h"

using namespace std;

template <typename T>
bintree<T> reconstruir(vector<T> & pre, int & preIndex, int i, int j, int size){

	if(preIndex >= size || i > j) return {};
	T elem = pre[preIndex++];

	if(i == j) return {bintree<T>(), elem, bintree<T>()};

	int x;
	for( x = i; x <= j; ++x)
		if(pre[x] > elem)
			break;
	auto l = reconstruir(pre, preIndex, preIndex, x-1, size);
	auto r = reconstruir(pre, preIndex, x, j, size);

	return {l, elem, r};
}

int main(){
	while(cin && !cin.eof()){
		vector<int> in, pre;
		int a;
		while(cin >> a){
			pre.push_back(a);
			if(cin.get() == '\n') break;
		}
		//for(int i: pre) cout << i << " ";
		//cout << endl;
		int preIndex = 0;
		auto s = reconstruir(pre, preIndex, 0, pre.size()-1, pre.size());
		auto v = s.postorder();
		for(auto i: v) cout << i << " ";
		cout << endl;
	}
	return 0;
}
