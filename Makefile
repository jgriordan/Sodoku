all:		main.o sodoku.o
		g++ main.o -o main
		g++ sodoku.o -o sodoku

main.o:		main.cpp
		g++ main.cpp -c

sodoku.o:	sodoku.cpp
		g++ sodoku.cpp -c

clean:
	rm *.o palindrome tenCardTest monkeySort BlackJack War
