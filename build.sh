function createDirIfNotExist() {
  directory=$1
  [ -d "$directory" ] || mkdir -p "$directory"
}

createDirIfNotExist "build"

cd build

echo "Current working directory: $(pwd)"

cmake ..

cmake --build .

echo "Done building, executing binary.."

./Cake ${1:-3.14}
