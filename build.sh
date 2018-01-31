cd ~
rm -d -R build
mkdir build
cd build
cmake /vagrant
ctest
cat Testing/Temporary/LastTest.log
make
./HelloWorld
