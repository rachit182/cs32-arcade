# Variables
CC = g++ -std=c++17
EXECUTABLE = crossy_roads
SOURCES = src/crossy_roads.cpp
LIBS = -lGL -lGLU -lglut

# Build rule
$(EXECUTABLE): $(SOURCES)
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(LIBS)

# Clean rule
clean:
	rm -f $(EXECUTABLE)
