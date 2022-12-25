#include "fft.h"

void fftshift(float xr[], float xi[], unsigned int N) {
	int N2 = (int) N / 2;
	float tmp;
	int nN2;
	for ( int n = 0; n < N2; n++ ) {
		tmp = xr[n];
		nN2 = n + N2;
		xr[n] = xr[nN2];
		xr[nN2] = tmp;

		tmp = xi[n];
		xi[n] = xi[nN2];
		xi[nN2] = tmp;
	}
}

void fftshift2(float **xr, float **xi, unsigned int Nx, unsigned int Ny) {
	for ( int nx = 0; nx < Nx; nx++ ) fftshift(xr[nx], xi[nx], Ny);


	float xrp[Ny], xip[Ny];
	for ( int ny = 0; ny < Ny; ny++ ) {
		for ( int nx = 0; nx < Nx; nx++ ) {
			xrp[nx] = xr[nx][ny];
			xip[nx] = xi[nx][ny];
		}

		fftshift(xrp, xip, Nx);

		for ( int nx = 0; nx < Nx; nx++ ) {
			xr[nx][ny] = xrp[nx];
			xi[nx][ny] = xip[nx];
		}
	}
}
