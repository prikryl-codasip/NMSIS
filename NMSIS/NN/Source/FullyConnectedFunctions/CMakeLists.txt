cmake_minimum_required (VERSION 3.5)

project(NMSISNNFullyConnected)

file(GLOB SRC "./*_*.c")

add_library(NMSISNNFullyConnected STATIC ${SRC})

### Includes
target_include_directories(NMSISNNFullyConnected PUBLIC "${NN}/Include")
target_include_directories(NMSISNNFullyConnected PUBLIC "${DSP}/Include")
