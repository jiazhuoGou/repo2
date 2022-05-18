CC = g++
CFLAGS=-std=c++17 -Wall -g
DEBUG =-DUSE_DEBUG
SOURCES =$(wildcard ./src/*.cpp)
INCLUDES = -I./include
OBJ = $(patsubst %.cpp, %.o, $(SOURCES)) # replace .cpp to .o
TARGET = app

#compile
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(DEBUG) -c $< -o $@

#links
$(TARGET):$(OBJ)
	@mkdir -p output
	$(CC) $(OBJ) $(LIB_PATH) $(LIB_NAMES) -o output/$(TARGET)$(VERSION)
	@rm -rf $(OBJ)

.PHONY:clean
clean:
	@echo "Remove linked and compiled files......"
	rm -rf $(OBJ) $(TARGET) output