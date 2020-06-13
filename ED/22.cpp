#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct par{
	int a;
	int b;
};

template <class T>
class bintree_ext : public bintree<T> {
   using Link = typename bintree<T>::Link;
public:
   bintree_ext() : bintree<T>() {}
   bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
   size_t altura() const {
      return altura(this->raiz);
   }
   size_t nodos() const{
	   return nodos(this->raiz);
   }
   size_t hojas(vector<int> & v) const{
	   return hojas(this->raiz, v);
   }
   par diametro() const{
	   return diametro(this->raiz);
   }
private:
   static size_t altura(Link r) {
      if (r == nullptr) {
         return 0;
      } else {
         return 1 + std::max(altura(r->left), altura(r->right));
      }
   }
   static size_t nodos(Link r){
	   if(r == nullptr)
		   return 0;
	   else
		   return 1 + nodos(r->left) + nodos(r->right);
   }
   static size_t hojas(Link r, vector<int> & w){
	   if(r == nullptr) return 0;
	   else if(r->left == NULL && r->right == NULL){
		   w.push_back(r->elem);
		   return 1;
		}
	   else return hojas(r->left, w) + hojas(r->right, w);
   }
   static par diametro(Link r){
	   int diam_iz, alt_iz, diam_dr, alt_dr, diam, alt;
	   if(r == nullptr) return {-1, 0};
	   else{
		   par iz = diametro(r->left);
		   diam_iz = iz.a;
		   alt_iz = iz.b;
		   par dr = diametro(r->right);
		   diam_dr = dr.a;
		   alt_dr = dr.b;
		   diam = max(max(diam_iz, diam_dr), alt_iz+alt_dr);
		   alt = 1 + max(alt_iz, alt_dr);
	   }
	   return {diam , alt};
   }


};

template <typename T>
bintree_ext<T> leerArbol_ext(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_ext(vacio);
      auto dr = leerArbol_ext(vacio);
      return {iz, raiz, dr};
   }
}

template <typename T>
par diametro(bintree<T> a){
	par iz, dr, s;
	if(a.empty()) return {-1, 0};
	else{
		iz = diametro(a.left());
		dr = diametro(a.right());
		s = {max(max(iz.a, dr.a), iz.b + dr.b), 1 + max(iz.b, dr.b)};
	}
	return s;
}

int main(){
	int in;
	cin >> in;
	while(in--){
		auto arbol = leerArbol_ext('.');
		//printf("%d %d %d\n" , arbol.nodos(), arbol.hojas(), arbol.altura());
		par s= diametro(arbol);
		printf("%d\n", s.a + 1);

	}
	return 0;
}
