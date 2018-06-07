

## Geting started
install google test librairies and cmake

```
sudo apt-get install libgtest-dev
sudo apt-get install cmake
sudo apt install libboost-all-dev
```

Complie Gtest into a useable librairy
```
cd /usr/src/gtest
sudo apt-get install g++
sudo cmake CMakeLists.txt
sudo make
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```


To install websocketpp, go back to the main directory and do
```
git clone git://github.com/zaphoyd/websocketpp.git
$ cd websocketpp
$ cmake .
$ sudo make install
$ cd ..
```

To compile the game, go in the "back" directory and excecute
```
mkdir build
./compile.sh
./build/main
```

To compile the unitests, go into the "test" directory and excecute
```
./compile_test.sh
./build/runTests
```
