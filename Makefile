OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized  -Wno-sign-compare -std=c++0x

program.exe: program.o Poblacion.o Individuo.o Par_Cromosomas.o
	g++ $(OPCIONS) -o program.exe program.o Poblacion.o Individuo.o Par_Cromosomas.o

program.o:  program.cc
	g++ -c program.cc $(OPCIONS)

Poblacion.o:  Poblacion.cc Poblacion.hh 
	g++ -c Poblacion.cc $(OPCIONS)

Individuo.o:  Individuo.cc Individuo.hh 
	g++ -c Individuo.cc $(OPCIONS)

Par_Cromosomas.o: Par_Cromosomas.cc Par_Cromosomas.hh
	g++ -c Par_Cromosomas.cc $(OPCIONS)

clean:
	rm -f *.o *.gch *.exe
