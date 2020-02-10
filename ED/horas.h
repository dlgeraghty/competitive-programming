
#ifndef HORAS_H
#define HORAS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

class horas{
private:
	int HH;
	int MM;
	int SS;
	bool check(int h, int m, int s) const {
		return 0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60;
	}

public:
	horas(int h = 0, int m = 0, int s = 0){
		if(check(h, m, s)){
			HH = h; MM = m; SS = s;
		}else
			throw std::domain_error("hora invalida");
	}

	int hora() const { return HH; }
	int minuto() const { return MM; }
	int segundo() const { return SS; }

	bool operator<(horas const & h) const {
		return HH*3600 + MM*60 + SS < h.HH*3600 + h.MM*60 + h.SS;
	}
	int toSeconds(int h, int m, int s){
		return h*3600+m*60+s;
	}
	horas operator+(horas & h)  {
		int s = toSeconds(HH+h.HH, MM+h.MM, SS+h.SS);
		int hour = s / 3600;
		s%=3600;
		int min = s/60;
		s%=60;
		return {hour, min, s};
	}

	void read(std::istream & input = std::cin){
		int h,m,s;char c;
		input >> h >> c >> m >> c >> s;
		if(check(h, m, s)){
			HH = h; MM = m; SS = s;
		}else
			throw std::domain_error("hora invalida");

	}
	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << HH << ":"
		<< std::setfill('0') << std::setw(2) << MM << ":"
		<< std::setfill('0') << std::setw(2) << SS;

	}
};

inline std::ostream & operator<<(std::ostream & salida, horas const&h){
	h.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h){
	h.read(entrada);
	return entrada;
}

#endif
