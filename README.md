# Qt-dbhelper

## Documentation

[Documentation](https://github.com/Chukak/qt-dbhelper/wiki)

## How to compile

You need `g++` 7+ version or early version, which support `17` standart (`-std=c++17`) or you need `g++` version, which support minimum `11` standart (`-std=c++11`).

Also, Qt 5.9.5 version (at the moment) or newer. CMake version 3.0 or newer.

Run command(by default):
```bash
mkdir build && cd build
cmake ../
make
```

Run command(custom version):
```bash
mkdir build && cd build
cmake -DSTD_VERSION=11
make
```

Install headers (for example):
```bash
sudo mkdir /usr/include/qt-dbhelper
sudo ln -s include/* /usr/include/qt-dbhelper
```

Install lib (for example):
```bash
sudo ln -s qt-dbhelper.so /usr/lib
```

## Testing 

For testing this library using mysql (5.7) as example database. 
Also need `mysql` drivers for Qt: `apt-get install libqt5sql5-mysql`.

You need to create `mysql` user with `12345678` for testing. 
Create it using command `GRANT ALL PRIVILEGES ON *.* TO 'mysql'@'localhost' IDENTIFIED BY '12345678';`

For example check `.travis.yml` script.

Command:
```bash
mkdir build && cd build
cmake ../tests
make 
./qt-dbhelper-tests
```
