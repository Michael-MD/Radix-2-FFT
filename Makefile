a.out: test.o fft.o
	g++ test.o fft.o -o a.out

fft.o: rad2FFT.c fft.h
	g++ -c rad2FFT.c -o fft.o

test.o: test.c
	g++ -c test.c

clean:
	rm *.o test