cmake_minimum_required(VERSION 3.10.2)

#YAUTF building
add_library(yautf SHARED YAUTF@aa75fd8/src/yautf.cc)

#LOAD building
add_library(load SHARED libload/)
