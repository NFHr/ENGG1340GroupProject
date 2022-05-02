FLAGS = -pedantic-errors -std=c++11

main.o: main.cpp
	g++ $(FLAGS) -c $<

initializing.o: initializing.cpp
	g++ $(FLAGS) -c $<

gaming.o: gaming.cpp
	g++ $(FLAGS) -c $<

Notakto: main.o initializing.o gaming.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f Notakto *.o Notakto.tgz

tar:
	tar -czvf Notakto.tgz *.cpp *.h



.PHONY: clean tar