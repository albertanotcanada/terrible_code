CXX = g++
CXXFLAGS = -std=c++17 -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lcpr -ljsoncpp
TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

# Ensure dependencies are installed
check-deps:
	@echo "Checking dependencies..."
	@pkg-config --exists cpr || (echo "Error: cpr library not found!" && exit 1)
	@pkg-config --exists nlohmann_json || (echo "Error: nlohmann_json library not found!" && exit 1)

# Add a rule to run the program
run: $(TARGET)
	./$(TARGET)