# Variables
CC = g++
EXECUTABLE = crossy_roads
SOURCES = src/crossy_roads.cpp $(wildcard src/lib/*.cpp)
LIBS = -lGL -lGLU -lglut

# Build rule
$(EXECUTABLE): $(SOURCES)
    $(CC) -o $(EXECUTABLE) $(SOURCES) $(LIBS)

# Clean rule
clean:
    rm -f $(EXECUTABLE)
