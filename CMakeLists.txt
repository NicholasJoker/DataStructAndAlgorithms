cmake_minimum_required(VERSION 3.23)
project(DataStructAndAlgorithms)

set(CMAKE_CXX_STANDARD 20)

#add_executable(DataStructAndAlgorithms
#        ArrayList/ArrayList.cpp
#        README.md IllegalParameterValue/IllegalParameterValue.h)
include_directories(SYSTEM "/IllegalParameterValue/IllegalParameterValue")
add_executable(DataStruct main.cpp
        IllegalParaterValue/IllegalParaterValue.h
        linearList.h
        ArrayList/ArrayList.h CopyBackward.h ArrayList/ArrayListNoSTL.cpp ArrayList/ArrayListNoSTL.h Chain/Chain.cpp Chain/Chain.h)

