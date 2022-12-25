a.out: test.o fft1.o fft2.o fftshift.o
	g++ test.o fft1.o fft2.o fftshift.o -o a.out

fftshift.o: fftshift.c fft.h
	g++ -c fftshift.c -o fftshift.o

fft2.o: rad2FFT2.c fft.h
	g++ -c rad2FFT2.c -o fft2.o

fft1.o: rad2FFT.c fft.h
	g++ -c rad2FFT.c -o fft1.o

test.o: test.c
	g++ -c test.c

clean:
	rm *.o test