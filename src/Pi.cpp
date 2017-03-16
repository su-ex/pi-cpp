#include <iostream>
#include <iomanip>
#include <gmpxx.h>

int main() {
	mpq_class t(1);
	mpq_class sum(1103);
	mpz_class n(1);
	mpz_class faku(1);
	mpz_class pote(1);
	mpz_class inte;
	
	while (true) {
		//Thread 0:
		std::cout << std::setprecision(100000000) << mpf_class((mpq_class(9801, 2)*t)/sum,100000000) << std::endl;
		
		//Thread 1:
			//Thread 1.1:
			faku *= (4*n-3)*(4*n-2)*(4*n-1)*4;
			faku /= n*n*n;
			inte = (1103+26390*n++)*faku;
			//Thread 1.2:
			pote *= 24591257856;
		sum += inte/pote;
		
		
		//Thread 2:
		t = (t*t*2+1)/(t*4);
	}
	
	return 0;
}
