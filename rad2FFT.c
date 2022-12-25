#include <cmath>
#define TWOPI 2*acos(-1)

#include <iostream>
using namespace std;

float Er, Ei, Or, Oi, coswk, sinwk;
float eOr, eOi;
int l;

#define complexMult(cr, ci, ar, ai, br, bi) { \
	cr = ar * br - ai * bi;					\
	ci = ar * bi + ai * br;					\
}

unsigned int ReverseBits(unsigned int i, int s) {
	 int rev = 0;
    // traversing bits of 'num' from the right 
    while (s--)
    { 
        rev <<= 1;
        if (i & 1 == 1) 
            rev ^= 1;
        i >>= 1;
    }

    return rev;
}

void bitReversedShuffle(float xr[], float xi[], int N, int s) {
	float tmp;
	unsigned int j;
	for (unsigned int i = 0; i < N; i++) {
		j = ReverseBits(i, s);

		if ( i < j ) {
			tmp = xr[j];
			xr[j] = xr[i];
			xr[i] = tmp;

			tmp = xi[j];
			xi[j] = xi[i];
			xi[i] = tmp;
		}
	}
}

void rad2FFT(float xr[], float xi[], unsigned int N) {
	unsigned short log2N = 0;
	unsigned int m, m2;
	float w, wr, wi, wm, wmr, wmi;
	float tmp;
	int p, l;


	// finding power of length
	for ( unsigned int j = N; (j = j >> 1) >= 1; log2N++ );
	
	bitReversedShuffle(xr, xi, N, log2N);
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

				complexMult(eOr, eOi, wr, wi, Or, Oi)

				l = k + j;
				xr[l] = Er + eOr;
				xi[l] = Ei + eOi;

				p = l + m2;
				xr[p] = Er - eOr;
				xi[p] = Ei - eOi;

				complexMult(tmp, wi, wr, wi, wmr, wmi)
				wr = tmp;

			}
		}

	}
	

}

void irad2FFT(float Xr[], float Xi[], unsigned int N) {
	// conjugate
	for ( int i = 0; i < N; i++ ) Xi[i] *= -1;
	rad2FFT(Xr, Xi, N);
	// conjugate
	for ( int i = 0; i < N; i++ ) Xi[i] *= -1;
	// normalize
	for ( int i = 0; i < N; i++ ) {
		Xr[i] /= N;
		Xi[i] /= N;
	}
}
