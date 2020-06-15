OPTIONS = -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe:
	g++ -o program.exe *.hh *.cc $(OPTIONS)

clean:
	rm *.o
	rm *.exe

program.tar: Text.cc Autor.cc Cita.cc Cjt_Text.cc Cjt_Autor.cc Cjt_Cita.cc Frase.cc program.cc
	tar -cvf
