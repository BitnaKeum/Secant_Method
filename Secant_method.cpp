#include <stdio.h>
#include <math.h>

// 주어진 함수
double f(double x) { 
	return x * x * x + 4 * x * x - 10; 
} 
// (a,f(a)),(b,f(b))를 지나는 직선의 x절편을 구하는 함수
double x_intercept(double a, double b) { 
	return b - f(b) * (b - a) / (f(b) - f(a)); 
}


int main()
{
	double an = 1.0, bn = 2.0;
	double TOL = 0.0005;
	int n = 20;

	double p_nminus1 = bn;	 // pn-1

	printf(" n       pn            f(pn)\n");

	for (int i = 2; i < n; i++)
	{
		double pn = x_intercept(an, bn);

		printf("%2d  %.10f  ", i, pn);
		if (f(pn) > 0)	printf(" ");	// 칸 맞춤
		printf("%.10f\n", f(pn));

		// 오차 : |pn - pn-1|
		double error = pn - p_nminus1;
		if (error < 0) error *= (-1); // 오차는 양수
		if (error < TOL) break;	  // 오차가 TOL 값보다 작으면 종료

		// pn-1과 pn에 대하여 구간 설정
		if (pn > p_nminus1) {
			an = p_nminus1;
			bn = pn;
		}
		else {
			an = pn;
			bn = p_nminus1;
		}

		p_nminus1 = pn;  // 다음에 pn+1을 구할 것이므로 pn은 pn-1이 됨
	}

	return 0;
}


