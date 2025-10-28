CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
INCLUDEDIR = include
SRCDIR = src
TESTDIR = tests
EXAMPLEDIR = examples

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARY = libbiblioteczka.a

TESTS = $(wildcard $(TESTDIR)/*.cpp)
TEST_EXECUTABLES = $(TESTS:.cpp=)

EXAMPLES = $(wildcard $(EXAMPLEDIR)/*.cpp)
EXAMPLE_EXECUTABLES = $(EXAMPLES:.cpp=)

all: $(LIBRARY) tests examples

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -c $< -o $@

tests: $(TEST_EXECUTABLES)

$(TESTDIR)/%: $(TESTDIR)/%.cpp $(LIBRARY)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) $< -L. -lbiblioteczka -o $@

examples: $(EXAMPLE_EXECUTABLES)

$(EXAMPLEDIR)/%: $(EXAMPLEDIR)/%.cpp $(LIBRARY)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) $< -L. -lbiblioteczka -o $@

run-tests: tests
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $test..."; \
		./$test; \
	done

clean:
	rm -f $(OBJECTS) $(LIBRARY) $(TEST_EXECUTABLES) $(EXAMPLE_EXECUTABLES)

.PHONY: all tests examples run-tests clean