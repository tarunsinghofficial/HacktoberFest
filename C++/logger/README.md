How to build and run from the terminal:

1. mkdir build
2. cmake -G "Unix Makefiles" .. && make
3. ./Logger

Requirements:
cmake 3.16 or any version after
gcc or another compiler that supports C++23(you can downgrade the version in the CMakeLists.txt file in the root down to C++17)
