# tracking-students
Tracking Exercise

## Requirements
* C++ Compiler
* CMake
* OpenCV

## Setup
You first need to install OpenCV and all other requirements with your favorite package manager, e.g.
```sh
sudo apt-get install build-essential cmake libopencv-dev python3-opencv # Ubuntu
```
or
```sh
brew install llvm cmake opencv # MacOS
```

Download the code:
```sh
git clone git@github.com:titus-leistner/tracking-students.git
cd tracking-students/code
```

Then create a makefile or project for your favorite build system using CMake.
To create a makefile, run:
```sh
cmake .
```

If you're using a makefile, build and run on one of the video sequences:
```sh
make
./trackingEx ../seq1
```

Press [Space] to play the sequence.

## MacOS
On the Mac, OpenMP can cause problems. You need to install llvm (e.g. via homebrew)
```sh
brew install llvm
```
and use the modified CMakeLists.txt.mac
```sh
mv CMakeLists.txt.mac CMakeLists.txt
```
Change the version numbers in lines 22-25 of your new CMakeLists.txt to the installed llvm version.

Then
```
cmake .
```
should work just fine.
