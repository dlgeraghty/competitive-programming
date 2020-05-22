#pragma once
#include <unordered_map>
#include <string>

using namespace std;

#define clave first
#define valor second

class carnet_puntos{
	unordered_map<string, int> carnet;
	unordered_map<int, int> cuantos;

public:
	void nuevo(string dni){
		auto res = carnet.insert({dni, 15});
		if(!res.second)
			throw domain_error("Conductor duplicado");
		else
			cuantos[15]++;
	}
	void quitar(string dni, int puntos){
		if(carnet.find(dni) != carnet.end()){
			cuantos[carnet[dni]]--;
			carnet[dni] -= puntos;
			if(carnet[dni] < 0) carnet[dni] = 0;
			cuantos[carnet[dni]]++;
		}else
			throw domain_error("Conductor inexistente");
	}
	int consultar(string dni){
		if(carnet.find(dni) != carnet.end()){
			return carnet[dni];
		}else
			throw domain_error("Conductor inexistente");
	}
	int cuantos_con_puntos(int puntos){
		if(puntos >= 0 && puntos <= 15){
			return cuantos[puntos];
		}else
			throw domain_error("Puntos no validos");
	}
};




