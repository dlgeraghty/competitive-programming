#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include "bintree_eda.h"

using namespace std;

struct s{
	int s = 0;
	int p = INT_MAX;
};

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

template <class T>
class bintree_ext : public bintree<T> {
   using Link = typename bintree<T>::Link;
public:
   bintree_ext() : bintree<T>() {}
   bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

   void custom_preorder(){
	   s sol;
	   custom_preorder(this->raiz, sol, 0);
	   if(sol.s != 0)
		   cout << sol.s << " " << sol.p << endl;
	   else
		   cout << "NO HAY" << endl;
   }
private:
   void custom_preorder(Link r, s & sol, int h){
	   if(r == nullptr || isPrime(r->elem)) return;

	   if(r->elem % 7 == 0) if(h < sol.p) sol = {r->elem, h + 1};

	   if(r->right != NULL)custom_preorder(r->right, sol, h + 1);
	   if(r->left != NULL)custom_preorder(r->left, sol, h + 1);
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
int main(){
	int in;
	cin >> in;
	while(in--){
		auto arbol = leerArbol_ext(-1);
		arbol.custom_preorder();
	}
	return 0;
}
