

clang_debug:
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -B build -G Ninja

compile:
	cmake --build build -j 32

tests:
	ctest --test-dir build

clean:
	rm -rf build && rm -rf .cache
