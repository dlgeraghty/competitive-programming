
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;


#include "horas.h"
#include "pelicula.h"


int main(){

        int n;
        while(cin >> n && n!= 0 ){
		vector<pelicula> peliculas;
		horas h;
		horas d;
		string s;
		for(int i = 0; i < n;i++){
			cin >> h >> d;
			getline(cin, s);
			peliculas.push_back(pelicula(h, d+h ,s));
		}
		sort(peliculas.begin(), peliculas.end());
		for(pelicula p:peliculas){
			cout << p;
		}
		cout << "---" << endl;
        }


        return 0;
}
