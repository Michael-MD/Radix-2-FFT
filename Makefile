a.out: test.o libfft.a
	g++ -o a.out test.o -L. -lfft

test.o: test.c
	g++ -c test.c



libfft.a: fftshift.o fft1.o fft2.o
	ar rcs libfft.a fftshift.o fft1.o fft2.o

fftshift.o: fftshift.c fft.h
	g++ -c fftshift.c -o fftshift.o

fft2.o: rad2FFT2.c fft.h
	g++ -c rad2FFT2.c -o fft2.o

fft1.o: rad2FFT.c fft.h
	g++ -c rad2FFT.c -o fft1.o


clean:
	rm *.o test *.out *.a