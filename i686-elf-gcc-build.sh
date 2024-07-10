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


#echo "Press enter to continue"
#read _

echo "This script will build the i686-elf GCC cross compiler"
echo "Do you wish to continue?"
select yn in "Yes" "No"; do
    case $yn in
        Yes ) break;;
        No ) exit;;
    esac
done

echo "install";