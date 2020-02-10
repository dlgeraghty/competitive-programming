#ifndef COMPLEJO_H
#define COMPLEJO_H

#include<math.h>

template <typename T>
class complejo{
private:
	T a;
	T b;
public:
	complejo(T x, T y){
		a = x;
		b = y;
	}
	complejo operator+(complejo & c){
		return {(a+c.a), (b+c.b)};
	}
	complejo operator*(complejo & c){
		return {( a * c.a - b * c.b ), (a * c.b + c.a * b)};
	}
	float mod(){
		return std::sqrt(a*a + b*b);
	}
};

#endif
