#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>


using namespace std;

struct t{
	string a;
	int b;
	int c;
};

bool custom(const t &a, const t & b){
	if(a.b > b.b) return true;
	if(a.b == b.b && a.c < b.c) return true;
	if(a.b == b.b && a.c == b.c)
		return a.a < b.a;
	return false;
}

int main(){

	int in;
	cin >> in;
	while(in--){
		string equipo, problema,resultado;
		int tiempo;
		unordered_map<string, pair<int, int>> a;		//mapa de: equipo:{numero de problemas ac, tiempo } 
		unordered_map<string, unordered_map<string, int>> w;	//mapa de: equipo:{problema(no ac):numero de intentos...}
		unordered_map<string, unordered_set<string>>ac;		//mapa para tener los titulos de los problemas que resolvio cada equipo

		while(cin >> equipo && equipo != "FIN"){
			cin >> problema >> tiempo >> resultado;
			if(resultado == "AC"){				//si el resultado es correcto
				if(ac.find(equipo) != ac.end()){
					if(ac.at(equipo).find(problema) == ac.at(equipo).end()) {//miramos a ver si el que estamos evaluando esta o no entre ellos
						a[equipo].first++;			//anadimos uno al numero de problemas ac
						a[equipo].second += tiempo;		//anadimos el tiempo que le costo resolver el problema
						ac[equipo].insert(problema);		//anadimos el titulo del problema al equipo que lo resolvio
					}
				}
				else{
					a[equipo].first++;			//anadimos uno al numero de problemas ac
					a[equipo].second += tiempo;		//anadimos el tiempo que le costo resolver el problema
					ac[equipo].insert(problema);		//anadimos el titulo del problema al equipo que lo resolvio
				}
			}
			else{
				if(ac.find(equipo) != ac.end()){				//si el equipo ya tiene algun problema correcto	
					if(ac.at(equipo).find(problema) == ac.at(equipo).end()) //miramos a ver si el que estamos evaluando esta o no entre ellos
						w[equipo][problema]++;				//si no esta, podemos sumarlo a los w
				}								//pero si esta no lo sumamos
				else 
					w[equipo][problema]++;					//si el equipo no tiene resueltos, lo anadimos a los w por que puede que lo resuelva en el futuro

			}

		}
//		cout << "que problemas resolvio cada equipo:" << endl;
//		for(auto itr = ac.begin(); itr != ac.end(); ++itr){
//			cout << itr->first << endl;
//			unordered_set<string> s = itr->second;
//			for(string i: s)
//				cout << i << " ";
//			cout << endl;
//		}
//		cout << endl;
//
//		cout << "que problemas no resolvio cada equipo y cuantos intentos hizo " << endl;
//		for(auto itr = w.begin(); itr != w.end(); ++itr){
//			cout << itr->first << endl;
//			unordered_map<string, int> s = itr->second;
//			for(auto jtr = s.begin(); jtr != s.end(); ++jtr)
//				cout << jtr->first << " " << jtr->second << endl;
//			cout << endl;
//		}
			

		for(auto itr = w.begin(); itr != w.end(); ++itr){
			
			unordered_map<string, int> s = itr->second;
			for(auto jtr = s.begin(); jtr != s.end(); ++jtr)
				if(ac.find(itr->first) != ac.end()){
					if(ac.at(itr->first).find(jtr->first) != ac.at(itr->first).end())		//entonces tenemos un caso de un problema que tuvo intentos fallidos pero finalmente se resolvio
						a[itr->first].second += jtr->second * 20;
	//					cout << " el equipo " << itr->first << " al principio no consiguio resolver el problema " << jtr->first << " , pero finalmente si , despues de " << jtr->second << " intentos\n";
				}
				else			//si el equipo no resolvio ninguno lo tenemos que anadir al mapa con 0,0
					a[itr->first] = {0,0};


		}

		vector<t> v;
		for(auto itr = a.begin(); itr != a.end(); ++itr)
			v.push_back({itr->first, itr->second.first, itr->second.second});

		sort(v.begin(), v.end(), custom);

		for(t i : v)
			printf("%s %d %d\n", i.a.c_str(), i.b, i.c);
		
		printf("---\n");
	}
}
			



