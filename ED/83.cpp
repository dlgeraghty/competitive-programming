#include <iostream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

struct s{
	int h = 0;
	int r = 0;
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

	   s a, b;
	   if(r->right != nullptr)a = recorrer(r->right);
	   if(r->left != nullptr) b = recorrer(r->left);

	   return {max(a.h , max(b.h, min(a.r, b.r)+1)), min(a.r, b.r) + 1};

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
		auto arbol = leerArbol_ext('.');
		s res = arbol.recorrer();
		printf("%d\n", res.h);
	}
	return 0;
}
