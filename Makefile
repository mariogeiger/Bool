CC=g++
SRC=bool.h bool.cpp
EXT=

cal: cal.cpp $(SRC)
	$(CC) -o $@ $(SRC) $<$(EXT)
kar: kar.cpp $(SRC)
	$(CC) -o $@ $(SRC) $<$(EXT)
sim: sim.cpp $(SRC)
	$(CC) -o $@ $(SRC) $<$(EXT)
tab: tab.cpp $(SRC)
	$(CC) -o $@ $(SRC) $<$(EXT)
