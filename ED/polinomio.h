#include <bits/stdc++.h>

struct monomio{
	int coeficiente;
	int exponente;
};

class polinomio{
private:
	std::vector<monomio> v;
public:
	polinomio(){}

	void insert(int c, int e){
		//busqueda binaria del exponente en el vector
		//	si esta sumamos los coeficientes
		//	si no esta le "hacemos hueco" y lo metemos
		int l = 0;
		int r = v.size()-1;
		bool b = false;
		int m = 0;
		while(l <= r && !b){
			 m = (l + r) / 2;
			if(v[m].exponente == e)	b = true;
			if(v[m].exponente < e)	l = m+1;
			else	r = m-1;
		}
		if (b){
			v[m].coeficiente += c;
		}
		else{
			monomio o = {c, e};
			v.insert(v.begin() + m, o);
		}
	}

	int evaluate(int x){
		//recorrer el vector sustituyendo las x por el valor dado
		int r = 0;
		for(monomio m: v){
			int e = (int)pow((double)x, (double)m.exponente);
			r += m.coeficiente * e;
		}
		return r;
	}

	void read(std::istream & input = std::cin){
		int c, e;
		while(std::cin >> c >> e && !(c == 0 && e == 0)){
			insert(c, e);
		}
	}
};

inline std::istream & operator>>(std::istream & entrada, polinomio & p){
	p.read(entrada);
	return entrada;
}
