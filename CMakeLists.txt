cmake_minimum_required(VERSION 3.20)
project(TI_assignment_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(TI_assignment_1 main.cpp
        StringValidator.h
        Step1/FileManager.h Step1/FileManager.cpp
        Step2/Node.h Step2/Node.cpp Step2/CompareNodes.h Step2/Encoding.h Step2/Encoding.cpp
        Step3/TraverseShannonFano.h Step4/CompressFile.h Step4/CompressFile.cpp
        Step5/CalculateDataCompression.h Step5/CalculateDataCompression.cpp)
