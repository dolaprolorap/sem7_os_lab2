cd ./lib
cmake -B build
cmake --build build
cmake --install build --prefix ../utils/lib

cd ../counter
cmake -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../bin
cmake --build build

cd ..
relative_path="./counter/bin"
absolute_path=$(readlink -f "$relative_path")
export PATH="$PATH:$absolute_path"

cd utils
cmake -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../bin
cmake --build build

./bin/main
