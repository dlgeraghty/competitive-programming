#include <iostream>
#include <string>
#include "stack_eda.h"

using namespace std;

struct s{
	string f;
	int d;
};

bool resuelvecaso(){

	int n;
	cin >> n;

	if(!cin) return false;

	string line;

	stack<s> q;

	while(n--){

		s x;
		cin >> x.f >> x.d;

		while(!q.empty() && q.top().d <= x.d) q.pop();
		if(!q.empty())
			printf("%s\n", q.top().f.c_str());
		else
			printf("NO HAY\n");
		q.push(x);
			
	}
	

	printf("---\n");
	return true;



}

int main(){
	while(resuelvecaso());

	return 0;
}
