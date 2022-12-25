#include "fft.h"


void rad2FFT2(float **xr, float **xi, unsigned int Nx, unsigned int Ny) {
	for ( int nx = 0; nx < Nx; nx++ ) rad2FFT(xr[nx], xi[nx], Ny);


	float xrp[Ny], xip[Ny];
	for ( int ny = 0; ny < Ny; ny++ ) {
		for ( int nx = 0; nx < Nx; nx++ ) {
			xrp[nx] = xr[nx][ny];
			xip[nx] = xi[nx][ny];
		}

		rad2FFT(xrp, xip, Nx);

		for ( int nx = 0; nx < Nx; nx++ ) {
			xr[nx][ny] = xrp[nx];
			xi[nx][ny] = xip[nx];
		}
	}
}


void irad2FFT2(float **Xr, float **Xi, unsigned int Nx, unsigned int Ny) {
	for ( int nx = 0; nx < Nx; nx++ ) irad2FFT(Xr[nx], Xi[nx], Ny);


	float Xrp[Ny], Xip[Ny];
	for ( int ny = 0; ny < Ny; ny++ ) {
		for ( int nx = 0; nx < Nx; nx++ ) {
			Xrp[nx] = Xr[nx][ny];
			Xip[nx] = Xi[nx][ny];
		}

		irad2FFT(Xrp, Xip, Nx);

		for ( int nx = 0; nx < Nx; nx++ ) {
			Xr[nx][ny] = Xrp[nx];
			Xi[nx][ny] = Xip[nx];
		}
	}
}
