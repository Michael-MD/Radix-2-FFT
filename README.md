# Radix-2 FFT
Small library for in-place bit reversed DIT DFT radix-2 FFT. Functions are provided for 1D and 2D FFTs as well as fftshift and fftshift2 which rearranges the components to place the 0 frequency term in the centre.

## FFT/iFFT
An example using the 1D transform is as follows:
```
int N = 4;

float xr[N] = {1,2,3,4};
float xi[N] = {5,6,7,8};

rad2FFT(xr,xi, N);
``` 
which is transforming sequence (1+5i, 2+6i, 3+7i, 4+8i). The inverse transform is given by 
```
irad2FFT(xr,xi, N);
```

The same is true for rad2FFT2 which has decloration

```
void rad2FFT2(float **xr, float **xi, unsigned int Nx, unsigned int Ny);
```
with inverse
```
irad2FFT2(xr,xi, Nx, Ny);
```


## FFF shift
Fftshift has header
```
void fftshift(float xr[], float xi[], unsigned int N);
```
