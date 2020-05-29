
#include <iostream>
#include <string>
#include "36.h"

bool resuelveCaso(){

	int n, x;
	string s, t;
	fecha f;

	cin >> n;
	if(!cin)
		return false;
	cin >> s;

	consultorio H;

	while(n--){
		try{
			if(s == "nuevoMedico"){
				cin >> s;
				H.nuevoMedico(s);
			}
			else if( s == "pideConsulta"){
				cin >> s >> t >> f;
				H.pideConsulta(s, t, f);
			}
			else if(s == "listaPacientes"){
				cin >> s >> x;
				vector<pair<string, fecha>> v = H.listaPacientes(s,x);
				printf("Doctor %s dia %d\n", s.c_str(), x);
				for(pair<string, fecha> i: v) 
					printf("%s %02d:%02d\n", i.first.c_str(), i.second.hora, i.second.minuto);

			}
			else if(s == "atiendeConsulta"){
				cin >> s;
				H.atiendeConsulta(s);
			}
			else if(s == "siguientePaciente"){
				cin >> s;
				string x = H.siguientePaciente(s);
				cout << "Siguiente paciente doctor " << s << '\n' << x << '\n';
			}
		}catch(domain_error e){
			cout << e.what() << '\n';
		}
		if(n > 0)cin >> s;
	}
	cout << "---\n";
	return true;
}

int main(){

	while(resuelveCaso());

	return 0;

}
