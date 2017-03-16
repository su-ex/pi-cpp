#include <iostream>
#include <iomanip>
#include <gmpxx.h>

int main() {
	int n(1);
	mpz_class faku(1);
	mpz_class pote(9801);
	mpz_class inte;
	mpz_class sum(1103);
	mpq_class t(1);

	while (true) {
		//Thread 0:
		std::cout << std::setprecision(100000000) << mpf_class(mpq_class(pote, 2*sum)*t, 100000000) << std::endl;

		//Thread 1:
			//Thread 1.1:
			faku *= (4*n-3)*(4*n-2)*(4*n-1)*4;
			faku /= n*n*n;
			inte = (1103+26390*n++)*faku;
			//Thread 1.2:
			sum *= 24591257856_mpz;
			//Thread 1.3:
			pote *= 24591257856_mpz;
		sum += inte;

		//Thread 2:
		t = (t*t*2+1)/(t*4);
	}

	return 0;
}
