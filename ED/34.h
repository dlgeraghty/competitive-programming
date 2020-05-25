#pragma once
#include <unordered_map>
#include <string>
#include <list>

using namespace std;

#define clave first
#define valor second

class carnet_puntos{
	unordered_map<string, pair<int, list<string>::iterator>> carnet;
	unordered_map<int, list<string>> cuantos;

public:
	void nuevo(string dni){
		auto it = carnet.find(dni);
		if(it != carnet.end())
			throw domain_error("Conductor duplicado");
		else{
			carnet[dni] = {15, {}};
			auto & ip = cuantos[15];
			carnet[dni].second = ip.insert(ip.end(), dni);
		}
	}
	void quitar(string dni, int puntos){
		auto it = carnet.find(dni);
		if(it != carnet.end()){
			if(it->valor.first != 0){
				auto &p = it->valor.first;
				auto &ip = cuantos[p];
				ip.erase(it->valor.second);
				p -= puntos;
				if(p < 0) p = 0;
				it->valor.second = cuantos[p].insert(cuantos[p].end(), dni);
			}
		}else
			throw domain_error("Conductor inexistente");
	}
	void recuperar(string dni, int puntos){
		auto it = carnet.find(dni);
		if(it != carnet.end()){
			if(it->valor.first != 15){
				auto &p = it->valor.first;
				auto &ip = cuantos[p];
				ip.erase(it->valor.second);
				p += puntos;
				if(p > 15) p = 15;
				it->valor.second = cuantos[p].insert(cuantos[p].end(), dni);
			}
		}else
			throw domain_error("Conductor inexistente");
	}
	int consultar(string dni) {
		if(carnet.find(dni) != carnet.end()){
			return carnet[dni].first;
		}else
			throw domain_error("Conductor inexistente");
	}
	int cuantos_con_puntos(int puntos) {
		if(puntos >= 0 && puntos <= 15){
			return cuantos[puntos].size();
		}else
			throw domain_error("Puntos no validos");
	}

	list<string> lista_por_puntos(int puntos) {
		if(puntos >= 0 && puntos <= 15){
			return cuantos[puntos];
		}else
			throw domain_error("Puntos no validos");
	}
};




