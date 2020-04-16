#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main(){

	int in;
	cin >> in;
	cin.ignore();
	while(in--){
		string s, t, z, o; int n;
		map<string, string> m,w;

		getline(cin, t);
		stringstream line(t);
		getline(cin, z);
		stringstream line2(z);
		//cout << t << endl << z << endl;
		while( line >> s >> o) m[s] = o;
		while( line2 >> s >> o) w[s] = o;

		vector<string> nuevos; vector<string> eliminados; vector<string> cambiado;
		for(auto itr = w.begin(); itr != w.end(); ++itr){
			if(m.find(itr->first) != m.end()){		//la clave del segundo diccionario esta en el primero
				if(m[itr->first] != itr->second)	//el valor de la clave igual es distinto
					cambiado.push_back(itr->first);
			}else						//la clave del segundo diccionario no esta en el primero
				nuevos.push_back(itr->first);
		}

		for(auto itr = m.begin(); itr != m.end(); ++itr){
			if(w.find(itr->first) == w.end())
				eliminados.push_back(itr->first);
		}

		if(nuevos.size() > 0) cout << "+ ";
		for(auto x: nuevos)
			cout << x << " ";
		if(nuevos.size() > 0) cout << endl;
		if(eliminados.size() > 0) cout << "- ";
		for(auto x: eliminados)
			cout << x << " ";
		if(eliminados.size() > 0) cout << endl;
		if(cambiado.size() > 0) cout << "* ";
		for(auto x: cambiado)
			cout << x << " ";
		if(cambiado.size() > 0) cout << endl;

		if(nuevos.size() == 0 && eliminados.size() == 0 && cambiado.size() == 0) cout << "Sin cambios" << endl;
		cout << "---" << endl;


	}

	return 0;
}

