lr25-26.o: lr25-26.cpp
	g++ -c -o lr25-26.o lr25-26.cpp
lr25-26: lr25-26.o queued.o
	g++ -o lr25-26 lr25-26.o queued.h
queued.o: queued.h