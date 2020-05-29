#ifndef autoescuela_h
#define autoescuela_h

#include <string>
#include <unordered_map>
#include <set>

using namespace std;

using alumno = std::string;
using profesor = std::string;
using puntos = int;


class autoescuela{
	private: 
		unordered_map<profesor, set<alumno>> x;
		unordered_map<alumno, puntos> y;
		unordered_map<alumno, profesor> z;

	public:
		autoescuela(){
			x.clear();
			y.clear();
		}
		void alta(alumno a, profesor p){
			if(y.find(a) == y.end()){	//entonces no estaba matriculado
				y[a] = 0;		//le damos de alta en los puntos y le ponemos 0
				x[p].insert(a);		//le insertamos en la lista del profesor
				z[a] = p;		//le asignamos el profesor
			}else if(z[a] != p){		//si ya estaba matriculado es que quiere cambiar de profesor
				x[z[a]].erase(a);	//le quitamos de la lista del anterior profesor
				x[p].insert(a);		//le damos de alta en la cola del nuevo profesor
				z[a] = p;		//le actualizamos el profesor
			}
		}
		bool es_alumno(alumno a, profesor p){
			return x[p].find(a) != x[p].end();
		}
		int puntuacion(alumno a){
			if(y.find(a) != y.end()) return y[a];
			else throw domain_error("ERROR");
		}
		void actualizar(alumno a, puntos n){
			if(y.find(a) != y.end()) y[a]+=n;
			else throw domain_error("ERROR");
		}
		set<alumno> examen(profesor p, puntos n){
			set<alumno> s;
			for(alumno a: x[p])
				if(y[a] >= n) s.insert(a);
			return s;
		}
		void aprobar(alumno a){
			if(y.find(a) != y.end()) {
				y.erase(a);
				x[z[a]].erase(a);
				z.erase(a);
			}
			else throw domain_error("ERROR");
		}
};

#endif
