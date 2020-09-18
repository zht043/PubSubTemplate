# cmake usage tips

# run cmake 
# 1. if build/ folder not exist, mkdir build
# 2. cd build/
# 3. cmake ..
# 4. make

# rerun cmake after modifications on CMakeLists.txt
# 1. cd build/
# 2. make clean
# 3. cmake ..
# 4. make




#specify minimum required cmake version
cmake_minimum_required(VERSION 3.10)



#set project name
project(PubSubTemplate)

#set target name
set(Target module_runner.exe)

#set compiler
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

#set c++ version
set(CMAKE_CXX_STANDARD 17)



set(CMAKE_POSITION_INDEPENDENT_CODE ON)


#find dependency package required to use boost library
#minimum version 1.65.1 (default for Ubuntu 18.04)
find_package(Boost REQUIRED COMPONENTS date_time chrono system thread log)


#set include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
include_directories(${Boost_INCLUDE_DIRS})


#set variable to represent source files in the source folders
# - make sure to rerun cmake everytime a file is added to or remnove from the folders
AUX_SOURCE_DIRECTORY(./source/Main Main_srcs)



#add macro definitions "#define xxx"
add_definitions(-DBOOST_LOG_DYN_LINK) #macro needed by boost logger



#add target to be built
add_executable(${Target} ${Main_srcs})
#specify the libraries to be linked to the target added by [add_executable]
target_link_libraries(${Target} ${Boost_Libraries} Boost::date_time 
                                                   Boost::chrono 
                                                   Boost::system 
                                                   Boost::thread 
                                                   Boost::log
                                                                    )


