# build/debug.out: src/main.cpp src/rect.cpp src/barrel.cpp src/matrix.cpp src/MyString.cpp
# 	@mkdir -p build
# 	g++ -g -o build/debug.out src/main.cpp src/rect.cpp src/barrel.cpp src/matrix.cpp src/MyString.cpp

run: build/debug.out
	./build/debug.out

debug: build/debug.out
	gdb -q build/debug.out

build/rect.o: src/rect.cpp src/rect.hpp
	g++ -g -c -o build/rect.o src/rect.cpp

build/matrix.o: src/matrix.cpp src/matrix.hpp
	g++ -g -c -o build/matrix.o src/matrix.cpp

build/MyString.o: src/MyString.cpp src/MyString.hpp
	g++ -g -c -o build/MyString.o src/MyString.cpp

build/barrel.o: src/barrel.cpp src/barrel.hpp
	g++ -g -c -o build/barrel.o src/barrel.cpp

build/debug.out: build/rect.o build/MyString.o build/barrel.o src/main.cpp build/matrix.o
	g++ -g -o build/debug.out src/main.cpp build/rect.o build/MyString.o build/barrel.o build/matrix.o

valgrind: build/debug.out
	valgrind --leak-check=full --show-leak-kinds=all ./build/debug.out

build/test_rect_basic_methods.out: tests/test_rect_basic_methods.cpp build/rect.o
	g++ -g -o build/test_rect_basic_methods.out tests/test_rect_basic_methods.cpp build/rect.o

build/test_rect_properties.out: tests/test_rect_properties.cpp build/rect.o
	g++ -g -o build/test_rect_properties.out tests/test_rect_properties.cpp build/rect.o

build/test_rect_operations.out: tests/test_rect_operations.cpp build/rect.o
	g++ -g -o build/test_rect_operations.out tests/test_rect_operations.cpp build/rect.o

build/test_bounding_rect.out: tests/test_bounding_rect.cpp build/rect.o
	g++ -g -o build/test_bounding_rect.out tests/test_bounding_rect.cpp build/rect.o

test_rect: build/test_rect_basic_methods.out
	./build/test_rect_basic_methods.out

test_props: build/test_rect_properties.out
	./build/test_rect_properties.out

test_ops: build/test_rect_operations.out
	./build/test_rect_operations.out

test_bound: build/test_bounding_rect.out
	./build/test_bounding_rect.out

.PHONY: test_all

test_all: test_rect test_props test_ops test_bound
	@echo "-----------------------------------"
	@echo "ALL RECT TESTS COMPLETED SUCCESSFULLY"
	@echo "-----------------------------------"