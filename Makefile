INCLUDE := -I C:/libs/SDL2/include
LINK	:= -L C:/libs/SDL2/lib -lmingw32 -lSDL2main -lSDL2
SRC		:= $(wildcard src/*.c)
OBJ		:= $(patsubst src/%.c, %.o, $(SRC))

all: bin/release/snake clean

bin/release/snake: $(OBJ)
	gcc $^ -o $@ -s $(LINK)

bin/debug/snake: $(OBJ)
	gcc $^ -o $@ $(LINK)

%.o: src/%.c
	gcc -c -Wall -O3 $^ $(INCLUDE) -o $@

clean:
	rm *.o
