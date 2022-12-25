#include <cmath>
#define TWOPI 2*acos(-1)

#include <iostream>
using namespace std;

float Er, Ei, Or, Oi, coswk, sinwk;
float eOr, eOi;
int l;


void rad2FFT(float xr[], float xi[], unsigned int N) {
	unsigned short log2N = 0;
	unsigned int m, m2;
	float w, wr, wi, wm, wmr, wmi;
	float temp;
	int p, l;

	for ( unsigned int j = N; (j = j >> 1) >= 1; log2N++ );

	for ( unsigned short s = 0; s < log2N; s++ )
	{
		m = 2 << s;
		m2 = m / 2;
		wm = - TWOPI / m;
		wmr = cos(wm);
		wmi = sin(wm);

		for ( unsigned int k = 0; k < N; k+=m )
		{
			wr = 1.;
			wi = 0.;
			for ( unsigned int j = 0; j < m2; j++ )
			{
				Er = xr[k + j];
				Ei = xi[k + j];
				Or = xr[k + j + m2];
				Oi = xi[k + j + m2];

				eOr = wr * Or - wi * Oi;
				eOi = wr * Oi + wi * Or;

				l = k + j;
				xr[l] = Er + eOr;
				xi[l] = Ei + eOi;

				p = l + m2;
				xr[p] = Er - eOr;
				xi[p] = Ei - eOi;

				temp = wr;
				wr = wr * wmr - wi * wmi;
				wi = temp * wmi + wi * wmr;

			}
		}

	}
	

}