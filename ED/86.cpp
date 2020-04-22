#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include "bintree_eda.h"

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {
   using Link = typename bintree<T>::Link;
public:
   bintree_ext() : bintree<T>() {}
   bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

   void recorrer(){
	   int h = altura();
	   vector<bool> marcas(h, false);
	   recorrer(this->raiz, marcas, 0);
   }
   int altura(){
	   return altura(this->raiz);
   }

private:

   void recorrer(Link r, vector<bool> & marcas, int h){

	   if(r == nullptr) return ;

	   if(!marcas[h]){cout << r->elem << " " ;marcas[h] = true;}

	   recorrer(r->left, marcas, h + 1);
	   recorrer(r->right, marcas, h + 1);

   }

   int altura(Link r){
	   if(r == nullptr) return 0;

	   int a, b;
	   a = altura(r->right);
	   b = altura(r->left);

	   return max(a, b) + 1;
   }

};

template<typename T>
bintree_ext<T> leerArbol_ext(T vacio){
	T raiz;
	std::cin >> raiz;
	if(raiz == vacio){
		return {};
	}else{
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return {iz, raiz, dr};
	}
}

int main(){

	int c;
	cin >> c;
	while(c--){
		auto arbol = leerArbol_ext(-1);
		arbol.recorrer();
		cout << endl;
	}
	return 0;
}
