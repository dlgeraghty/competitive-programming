#ifndef consultorio_h
#define consultorio_h

#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include "fecha.h"

using namespace std;

using medico = std::string;
using paciente = std::string;


class consultorio{
	unordered_map<medico, map<fecha, paciente>> c;

	public:
		void nuevoMedico(medico m){
			c.insert({m, {}});
		}
		void pideConsulta(paciente p,medico m,fecha f){
			auto it = c.find(m);
			if(it == c.end())
				throw domain_error("Medico no existente");
			else{
				auto ip = c[m].find(f);
				if(ip != c[m].end())
					throw domain_error("Fecha ocupada");
				else
					c[m][f] = p;
			}
		
		}
		string siguientePaciente(medico m){
			auto it = c.find(m);
			if(it == c.end())
				throw domain_error("Medico no existente");
			else{
				if(c[m].size() == 0)
					throw domain_error("No hay pacientes");
				else{
					auto ip = c[m];
					return ip.begin()->second;
				}
			}
		
		}
		void atiendeConsulta(medico m){
			auto it = c.find(m);
			if(it == c.end())
				throw domain_error("Medico no existente");
			else{
				if(c[m].size() == 0)
					throw domain_error("No hay pacientes");
				else{
					auto ip = c[m];
//					fecha f = ip.begin()->first;
					c[m].erase(ip.begin()->first);
				}
			}
		
		}
		vector<pair<string, fecha>> listaPacientes(medico m, int d){

			vector<pair<string, fecha>> s;
			
			auto it = c.find(m);
			if(it == c.end())
				throw domain_error("Medico no existente");
			else{
//				auto iq = c[m].lower_bound({d, 0, 0});
//				auto ip = c[m].find({d, (*iq).first.hora, (*iq).first.minuto});
				for(auto x = c[m].begin(); x != c[m].end(); ++x)
					if(x->first.dia == d)
						s.push_back({x->second, x->first});
			}
			return s;
		
		}


};
bool operator<(const fecha & a, const fecha & f){
	if(a.dia == f.dia && a.hora == f.hora) return a.minuto < f.minuto;
	else if(a.dia == f.dia) return a.hora < f.hora;
	else return a.dia < f.dia;
}

#endif
