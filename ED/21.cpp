#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

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
   size_t hojas() const{
	   return hojas(this->raiz );
   }
   T min()const {
	   return min(this->raiz);
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
   static size_t hojas(Link r){
	   if(r == nullptr) return 0;
	   else if(r->left == NULL && r->right == NULL)return 1;
	   else return hojas(r->left) + hojas(r->right);
   }
   static T min(Link r){
	   //es vacia
	   if( r == nullptr ) return (T)NULL;
	   T root = r->elem;
	   if(r->left != NULL){
		   T left = min(r->left);
		   if(left < root) root = left;
	   }
	   if(r->right != NULL){
		   T right = min(r->right);
		   if(right < root) root = right;
	   }
	   return root;
   }
};

template <typename T>
bintree_ext<T> leerArbol_ext(T vacio) {
   T raiz;
   cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_ext(vacio);
      auto dr = leerArbol_ext(vacio);
      return {iz, raiz, dr};
   }
}

template <typename T>
T mini(bintree<T> a){
	typename bintree<T>::const_iterator itr = a.begin();
	T min = *itr;
	for(itr = a.begin(); itr != a.end(); ++itr){
		if(*itr < min) min = *itr;
	}
	return min;
}

int main(){
	char c;
	while(cin >> c){
		if(c == 'N'){
			auto arbolc = leerArbol(-1);
			//printf("%d %d %d\n" , arbol.nodos(), arbol.hojas(), arbol.altura());
			int w = mini(arbolc);
			printf("%d\n", w);
		}
		else if(c == 'P'){
			bintree<string> arbolp = leerArbol(string("#"));
			string s;
			s = mini(arbolp);
			cout << s << endl;
		}
	}

	return 0;
}
