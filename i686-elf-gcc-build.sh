#!/bin/bash

#
# Script to build the i686-elf GCC cross compiler
#

# ref: https://wiki.osdev.org/GCC_Cross-Compiler

# The cross compiler will be located here: `~/opt/cross`
# The InstructionOS src/Makefile depends on this location
# when compiling the kernel


# Exit immediately if a command exits with a non-zero status.
set -e



echo "This script will build the i686-elf GCC cross compiler"
echo "Continue?"
select yn in "Yes" "No"; do
    case $yn in
        Yes ) break;;
        No ) exit;;
    esac
done



echo "#"
echo "# Build GCC and binutils from source"
echo "#"


echo "--- Installing packages ---";
sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo


mkdir -p ~/Source && pushd ~/Source


echo "--- Downloading sources ---";
wget https://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.gz
wget https://ftp.gnu.org/gnu/binutils/binutils-2.41.tar.xz


echo "--- Extracting sources ---";
tar -xf gcc-13.2.0.tar.gz
tar -xf binutils-2.41.tar.xz


echo "--- Compiling binutils ---";
export PREFIX="$HOME/opt/gcc-13.2.0"
mkdir -p build-binutils && pushd build-binutils
../binutils-2.41/configure --prefix="$PREFIX" --disable-nls --disable-werror
make -j$(nproc)
make install
popd


echo "--- Downloading GCC prerequisites ---";
pushd gcc-13.2.0
./contrib/download_prerequisites
popd


echo "--- Compiling GCC ---";
mkdir -p build-gcc && pushd build-gcc
../gcc-13.2.0/configure --prefix="$PREFIX" --disable-nls --enable-languages=c,c++
make -j$(nproc)
make install
popd



echo "#"
echo "# Build the i686-elf GCC cross compiler"
echo "#"


# nb. assumes we are following on from above
export TARGET=i686-elf
export PREFIX="$HOME/opt/cross"
export PATH="$PREFIX/bin:$PATH"


echo "--- Compiling binutils ---";
rm -fdr build-binutils && mkdir -p build-binutils && pushd build-binutils
../binutils-2.41/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make -j$(nproc)
make install
popd


# The $PREFIX/bin directory _must_ be in the PATH
which -- $TARGET-as


echo "--- Compiling GCC ---";
rm -fdr build-gcc && mkdir -p build-gcc && pushd build-gcc
../gcc-13.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make -j$(nproc) all-gcc
make -j$(nproc) all-target-libgcc
make install-gcc
make install-target-libgcc
popd


echo "--- Confirm installation of the compiler ---";
$HOME/opt/cross/bin/$TARGET-gcc --version
$HOME/opt/cross/bin/$TARGET-ld --version