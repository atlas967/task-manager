CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
TARGET   := task
SRCDIR   := src
SRCS     := $(SRCDIR)/main.cpp $(SRCDIR)/task_manager.cpp $(SRCDIR)/storage.cpp
OBJS     := $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
