cd ./lib
cmake -B build -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY=../bin
cd build
make
mkdir ../../utils/lib
cp ../bin/lib.a ../../utils/lib/

cd ../../counter
cmake -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../bin
cd build
make

cd ../..
relative_path="./counter/bin"
absolute_path=$(readlink -f "$relative_path")
export PATH="$PATH:$absolute_path"

cd ./utils
cmake -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../bin
cd build
make

cd ../bin
./main
