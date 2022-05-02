FLAGS = -pedantic-errors -std=c++11

main.o: ./src/main.cpp
	g++ $(FLAGS) -c $<

initializing.o: ./src/initializing.cpp
	g++ $(FLAGS) -c $<

gaming.o: ./src/gaming.cpp
	g++ $(FLAGS) -c $<

Notakto: main.o initializing.o gaming.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f Notakto *.o Notakto.tgz

tar:
	tar -czvf Notakto.tgz *.cpp *.h



.PHONY: clean tar