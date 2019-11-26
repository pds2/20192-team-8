# Name of the project
PROJ_NAME=truco

# .cpp files
C_SOURCE=$(wildcard ./src/*.cpp) $(wildcard ./src/*/*.cpp)

# .hpp files
H_SOURCE=$(wildcard ./include/*.hpp) $(wildcard ./include/*/*.hpp)

# Object files
OBJ=$(subst .cpp,.o,$(subst src,objects,$(C_SOURCE)))

# Include Flag
INCDIRS= $(addprefix -I,$(shell find include -type d -print))

# Compiler and linker
CC=g++

# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic \

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) $^ -std=c++11 -o $@

./objects/%.o: ./src/%.cpp ./include/%.hpp
	$(CC) $< $(CC_FLAGS) ${INCDIRS} -std=c++11 -o $@

./objects/Truco.o: ./src/Truco.cpp $(H_SOURCE)
	$(CC) $< $(CC_FLAGS) ${INCDIRS} -std=c++11 -o $@

objFolder:
	@ mkdir -p $(subst include,objects,$(shell find include -type d -print))

clean:
	@ $(RM) objects

run: all
	@ ./$(PROJ_NAME)

.PHONY: all clean