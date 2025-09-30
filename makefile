# assignment name (generate executable with this name)
TARGET = proj4
TEST_TARGET = tester
# .cpp files that do not contain a main() function.
SOURCES = Vec.cpp App.cpp

CPP       = g++ --std=c++11 -c
CPPFLAGS   = -Wall -I. -g
LINKER   = g++ -o
LFLAGS   = -Wall

INCLUDES := $(wildcard *.h)
OBJECTS  := $(SOURCES:.cpp=.o)
rm       = rm -f

.PHONY: obj clean all

all: $(TARGET) $(TEST_TARGET)

$(TARGET): obj main.o
	$(LINKER) $(TARGET) $(LFLAGS) $(OBJECTS) main.o
	@echo "Linking complete!"

$(TEST_TARGET): obj tests.o
	$(LINKER) $(TEST_TARGET) $(LFLAGS) $(OBJECTS) tests.o
	@echo "Linking complete!"

obj: $(SOURCES) $(INCLUDES) tests.cpp main.cpp
	$(CPP) $(CPPFLAGS) $(SOURCES) tests.cpp main.cpp
	@echo "Compilation complete!"

clean:
	$(rm) $(TARGET) $(TEST_TARGET) $(OBJECTS) tests.o main.o
	@echo "Cleanup complete!"

