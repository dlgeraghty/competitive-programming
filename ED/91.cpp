#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

void resolver(unordered_map<string, unordered_map<string, int>> const & m){
	int in, max, p;
	string titulo, pelimax;
	unordered_map<string, int> peliculas;	//para llevar la cuenta de las veces que sale una pelicula
	map<string, int> actores;	//para organizar los actores con su tiempo total
	cin >> in;

	max = 0;
	p = 0;
	
	while(in--){
		cin >> titulo;
		peliculas[titulo]++;
		if( peliculas.at(titulo) >= p){
		       pelimax = titulo;
		       p = peliculas.at(titulo);
		}
		//para todos los actores que han participado en esta pelicula, sumamos el tiempo en el mapa actores
		//tambien aprovechamos para averiguar cual es el tiempo maximo.
		for(auto map : m.at(titulo)){
			actores[map.first] += map.second;
			if(actores.at(map.first) > max) max = actores.at(map.first);
		}

	}

	printf("%d %s\n", p, pelimax.c_str()); 
	printf("%d ", max);
	for(auto map: actores)
		if(map.second == max)
			printf("%s ", map.first.c_str());



	printf("\n");
	
}


bool resuelvecaso(){
	
	int in, nactores, tiempo;
	string pelicula, actor;

	cin >> in;

	if(in == 0) return false;

	unordered_map<string, unordered_map<string, int>> m;
	for(int i = 0; i < in; i++){
		cin >> pelicula >> nactores;
		while(nactores--){
			cin >> actor >> tiempo;
			unordered_map<string, int> tmp;
			tmp[actor] = tiempo;
			//si existe la pelicula y esta el actor ya en ella:
			if(m.find(pelicula) != m.end() && m.at(pelicula).find(actor) != m.at(pelicula).end())
				m[pelicula][actor] += tiempo;
			//si la pelicula ya existe no la volvemos a meter:
			else if(m.find(pelicula) != m.end())
				m.at(pelicula).insert(tmp.begin(), tmp.end());
			//si la pelicula no existe la metemos y la inicializamos
			else
				m[pelicula] = tmp;
		}
//		printf("DEBUG %s\n", pelicula.c_str());
//		for(auto itr = m.at(pelicula).begin(); itr != m.at(pelicula).end(); ++itr)
//			cout << itr->first << " " << itr->second << endl;
//		cout << endl;
	}
	resolver(m);

	return true;


}

int main(){

	while(resuelvecaso());

	return 0;

}
