FLAGS = -pedantic-errors -std=c++11
2113gp.o: 2113gp.cpp 2113gp.h
	g++ $(FLAGS) -c $<
2113gp_main.o: 2113gp_main.cpp 2113gp.h
	g++ $(FLAGS) -c $<
linkgame: 2113gp.o 2113gp_main.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f linkgame 2113gp.o 2113gp_main.o linkgame.tgz
tar:
	tar -czvf linkgame.tgz *.cpp *.h
.PHONY: clean tar

