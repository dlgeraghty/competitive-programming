
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;


#include "horas.h"
#include "pelicula.h"


int main(){

        int n;
        while(cin >> n && n!= 0 ){
                vector<pelicula> peliculas(n);
                horas h1;
                horas h2;
                horas sum;
                string n;
                for(pelicula &h: peliculas){
                        cin >> h1 >> h2 >> n;
                        sum = h1+h2;
                }
        }


        return 0;
}
