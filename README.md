# IN104 PACMAN PROJECT

Author : Soline DUCOUSSO and Etienne TURC

## Introduction

A pacman game developped for IN104 class.

You can play at the adress : [https://pacman.data-ensta.fr](pacman.data-ensta.fr)


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

Then, you access the graphic interface by opening your favorite browser (except outdated/trash ones such as IE) and look for the url :
```
file:///your/absolute/path/to/folder/pacman/views/index.html
```
And Enjoy !

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

### Setup server on remote host (not mandatory to run the project)

To setup the server on a remote host, please contact us.
