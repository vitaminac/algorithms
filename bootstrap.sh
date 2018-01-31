sudo apt-get update
sudo apt-get install -y build-essential g++ gdb gdbserver git cmake
git clone https://github.com/Kitware/CMake.git
cd CMake
git checkout release
mkdir out
cd out
cmake ../
make
sudo make install
sudo rm -r -dir -f CMake
wget https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.bz2
tar --bzip2 -xf ~/boost_1_66_0.tar.bz2
rm boost_1_66_0.tar.bz2
cd boost_1_66_0/
sudo ./b2 install
cd ../
sudo rm -f -r -d boost_1_66_0/