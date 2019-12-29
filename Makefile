TARGET = justePrix

GENERIC_CFLAGS = -Wall
MAKE = make
CXX = g++ -c 
LD = g++ -o

ifndef VERSION
VERSION = RELEASE
endif

ifeq (CHEAT, $(VERSION))
   CFLAGS = $(GENERIC_CFLAGS) -DCHEAT
else
   CFLAGS = $(GENERIC_CFLAGS)
endif

all: $(TARGET)

cheat:
	@$(MAKE) VERSION=CHEAT

$(TARGET): main.o justePrix.o  ihm.o joueur.o historique.o meilleurScore.o
	$(LD) $@ $^

main.o: main.cpp justePrix.h ihm.h joueur.h historique.h meilleurScore.h
	$(CXX) $< $(CFLAGS)

ihm.o: ihm.cpp ihm.h
	$(CXX) $< $(CFLAGS)

joueur.o: joueur.cpp joueur.h ihm.h
	$(CXX) $< $(CFLAGS)

justePrix.o: justePrix.cpp justePrix.h
	$(CXX) $< $(CFLAGS)
	
historique.o: historique.cpp historique.h
	$(CXX) $< $(CFLAGS)

meilleurScore.o: meilleurScore.cpp meilleurScore.h
	$(CXX) $< $(CFLAGS)

clean:
	rm -f $(TARGET) *.o *~

