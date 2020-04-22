#include <iostream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

struct s{
	int c = 0;
	int n = 0;
};

template <class T>
class bintree_ext : public bintree<T> {
   using Link = typename bintree<T>::Link;
public:
   bintree_ext() : bintree<T>() {}
   bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

   s recorrer(){
	   return recorrer(this->raiz);
   }

private:

   s recorrer(Link r){
	   if(r == nullptr) return {0,0};

	   int n = 0;
	   s a, b;
	   a = recorrer(r->right);
	   b = recorrer(r->left);
	   int c;
	   if(a.c + b.c - r->elem >= 3) n = 1;
	   if(r->left == NULL && r->right == NULL )
		c = 1;
	   else
		c = a.c + b.c - r->elem;
	   if(c < 0) c = 0;
	   //printf("ola, soy un afluente %d y mi caudal es: %d y soy navegable %d\n", r->elem, c, n);
	   return {c , n + a.n + b.n };
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
		s res = arbol.recorrer();
		if(res.c >= 3) res.n--;
		printf("%d\n", res.n);
	}
	return 0;
}
