# Basic c++ Protobuf Example 

Project with a basic example on how to implement Protobufs in C++.

## Install

```bash
$ git clone URL
$ cd URL
$ git submodule update --init --recursive
```

Then install locally Protobuf:
```bash
$ cd protobuf
$ ./autogen.sh
$ #prefix will make Protobuf install locally:
$ ./configure --prefix=$(pwd)/.libs/ --disable-shared
$ make
$ cd ..
```

Build the example:
```bash
$ make
$ ./build/apps/main
```