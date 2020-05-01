#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

bool isAllUpperCase(string s){
	for(char c: s)
		if(!isupper(c)) return false;
	return true;
}

bool custom(const pair<string , int> &a, const pair<string, int> & b){
	if(a.second > b.second) return true;
	else if(a.second == b.second) return (a.first < b.first);
	else return false;
}

int main(){

	while(!cin.eof()){
		unordered_map<string, vector<string>>	m;	//deporte: {alumno1, alumno2...}
		unordered_map<string, string>		p;	//alumno: deporte

		string s;
		string key;

		cin >> s;
		if(!cin) exit(0);

		while(s != "_FIN_"){
			if(isAllUpperCase(s)){			//entonces es clave
				key = s;			//me guardo la clave en un "tmp", solo por comodidad
				m[key] = vector<string> ();	//creo la entrada en el mapa
//				cout << "Analizando: " << key << endl;
			}
			else{					//es valor
				if(p.count(s) != 0){		//si el alumno esta ya en el mapa
					if(p.at(s) != key){	//si se repite en otro deporte, tenemos que borrarlo
						auto itr = m.find(p.at(s));
//						cout << "el alumno " << s << " ya esta apuntado en el deporte: " << p.at(s) << endl;
						auto jtr = find(itr->second.begin(), itr->second.end(), s);
						if(jtr != itr->second.end()){
//							cout << "eimino" << endl;
							itr->second.erase(jtr);
						}
					}

				}else				//si el alumno no esta ya en el mapa
					m[key].push_back(s);	//anado una entrada al mapa deporte:{...}
				p[s] = key;			//anado una entrada al mapa alumo:deporte
			}
			cin >> s;
		}

//		for(auto itr = m.begin(); itr != m.end(); ++itr){
//			cout << itr->first << " " << itr->second.size() << endl;
//			for(string i: itr->second)
//				cout << i << " ";
//		}
		vector<pair<string, int>> res;
		for(auto itr = m.begin(); itr != m.end(); ++itr)
			res.push_back(make_pair(itr->first, itr->second.size()));

		sort(res.begin(), res.end(), custom);

		for(auto i: res)
			cout << i.first << " " << i.second << endl;

		cout << "---" << endl;
	}

	return 0;
}

