1. Create a build folder `build`. This is the place to store the build artifacts.

2. Inside the build folder, call `cmake ..`. This instructs CMake to use the `CMakeLists.txt` in the parent directory to create build files in the current directory.

3. Then use `cmake --build .` to tell CMake to actually build the binary files in the current directory.

