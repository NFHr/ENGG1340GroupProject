FLAGS = -pedantic-errors -std=c++11

all: Notakto

main.o: ./src/main.cpp
	g++ $(FLAGS) -c $<

initializing.o: ./src/initializing.cpp
	g++ $(FLAGS) -c $<

gaming.o: ./src/gaming.cpp
	g++ $(FLAGS) -c $<

boarding.o: ./src/boarding.cpp
	g++ $(FLAGS) -c $<

Notakto: main.o initializing.o gaming.o boarding.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f Notakto *.o Notakto.tgz

tar:
	tar -czvf Notakto.tgz *.cpp *.h



.PHONY: clean tar