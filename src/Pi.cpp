#include <iostream>
#include <iomanip>
#include <gmpxx.h>

int main() {
  //~ mpz_class x("7612058254738945");
  //~ mpz_class y("9263591128439081");

  //~ std::cout << x*y << "\n"
            //~ << x*y+1 << "\n"
            //~ << cmp(x*y, x*y*2) << "\n"
            //~ << cmp(x*y, x*y) << "\n"
            //~ << cmp(x*y*2, x*y) << "\n";
  
  //~ mpq_class q(1, 3);

  //~ std::cout << x*q << "\n"
            //~ << x*q+1 << "\n"
            //~ << (x*q)/2 << "\n";

	mpq_class a(1);
	mpq_class sum(0);
	int n = 0;
	mpq_class faku(1);
	
	while (true) {
		sum += faku * (1103 + 26390*mpz_class(n));
		if (n % 20 == 0) {
			mpq_class t(9801, 2);
			t /= a;
			t /= sum;
			std::cout << std::setprecision(1000000000) << mpf_class(t,100000000) << std::endl;
		}
		n++;
		faku *= (1-mpq_class(1, n*4)) * (1-mpq_class(1, n*2)) * (1-mpq_class(3, n*4));
		faku /= mpz_class(99)*99*99*99;
		//~ std::cout << faku << std::endl;
		a = a/2 + 1/a;
	}
	
	return 0;
}
