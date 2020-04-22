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
	   int nodes = 0, height = 0;
	   height = altura();
	   int expected_nodes = (int)(pow(2, height) + 0.5);
	   bool b = recorrer(this->raiz, nodes);
	   if(b){
		   //printf("nodos %d, altura %d, supuestos nodos: %d", nodes, height, expected_nodes-1);
		   if(nodes == expected_nodes-1) cout << "COMPLETO";
		   else cout << "SEMICOMPLETO";

	   }
	   else cout << "NADA";

   }
   int altura(){
	   return altura(this->raiz);
   }

private:

   bool recorrer(Link r, int & count){
	   if(r == nullptr) return true;

	   queue<Link> q;

	   q.push(r);

	   bool flag = false;

	   while(!q.empty()){

		   Link l = q.front();
		   count++;
		   q.pop();

		   if(l->left != nullptr){
			   if(flag) return false;
			   q.push(l->left);
		   }
		   else flag = true;

		   if(l->right != nullptr){
			   if(flag) return false;
			   q.push(l->right);
		   }
		   else flag = true;

	   }
	   return true;
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
		auto arbol = leerArbol_ext('.');
		arbol.recorrer();
		cout << endl;
	}
	return 0;
}
