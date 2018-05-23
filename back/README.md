LD
LD to next intersection -> uses LD
2nd best LD ->
full random or LD until a certain range then random

##Geting started
install google test librairies and cmake

```
sudo apt-get install libgtest-dev
sudo apt-get install cmake
```

Complie Gtest into a useable librairy
```
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```

To compile the game, go in the "back" directory and excecute
```
./compile.sh
./build/main
```

To compile the unitests, go into the "test" directory and excecute
```
./compile.sh
./build/runTests
```
