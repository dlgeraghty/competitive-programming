#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "bintree_eda.h"

using namespace std;

template <typename T>
bintree<T> reconstruir(vector<T> & pre, vector<T> &in, int i, int j, int & preIndex){

	if(i > j) return {};
	T elem = pre[preIndex++];

	if(i == j) return {bintree<T>(), elem, bintree<T>()};

	int it = find(in.begin(), in.end(), elem)-in.begin();

	auto l = reconstruir(pre, in, i, it-1, preIndex);
	auto r = reconstruir(pre, in, it+1, j, preIndex);

	return {l, elem, r} ;
}

int main(){
	while(cin && !cin.eof()){
		vector<int> in, pre;
		int a;
		while(cin >> a){
			pre.push_back(a);
			if(cin.get() == '\n') break;
		}
		while(cin >> a){
			in.push_back(a);
			if(cin.get() == '\n') break;
		}
		//for(int i: pre) cout << i << " ";
		//cout << endl;
		//for(int i: in) cout << i << " ";
		//cout << endl;
		int preIndex = 0;
		auto s = reconstruir(pre, in, 0, pre.size()-1, preIndex);
		auto v = s.postorder();
		for(auto i: v) cout << i << " ";
		cout << endl;
	}
	return 0;
}
