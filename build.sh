function createDirIfNotExist() {
  directory=$1
  [ -d "$directory" ] || mkdir -p "$directory"
}

createDirIfNotExist "path/to/dir"

