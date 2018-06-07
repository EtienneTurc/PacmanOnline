# IN104 PACMAN PROJECT

Author : Soline DUCOUSSO and Etienne TURC

## Introduction

A pacman game developped for IN104 class.
You can play at the adress : [http://pacman.data-ensta.fr](pacamn.data-ensta.fr)


## Getting started
This project uses websocketpp to connect server to client. Install websocketpp at the root of the project :
```
git clone git://github.com/zaphoyd/websocketpp.git
cd websocketpp
cmake .
sudo make install

```
You need g++ installed.
```
sudo apt-get install g++
```

To Execute the game, you need to compile it first. Then execute the main in the build directory.
```
cd your/path/pacman/back
mkdir build
./compile.sh
./build/main

```

#### Unit tests

This project comes with unit test, it uses Google Test library. Install and compile it to be able to use it. Copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder.

```
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

To execute the unit tests, compile them first. Then execute runTests.
```
cd your/path/pacamn/back/test
./compile_test.sh
./build/runTests
```
