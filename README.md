# C++ Publisher-Subscriber Module Project Template

### build
build project by cmake, check out CMakeLists.txt

To build
```
mkdir build  #if PubSubTemplate/build doesn't exist
cd build
cmake .. 
make
```
Upon modifications were made in CMakeLists.txt, rerun cmake by:
```
make clean
cmake ..
make
```

### Project Structure
```
.
├── build
├── CMakeLists.txt
├── doc
├── include
│   ├── Main
│   │   ├── ModuleA.hpp
│   │   ├── ModuleB.hpp
│   │   └── ModuleC.hpp
│   └── PubSubModule
│       ├── cp_queue.hpp
│       ├── inter_thread_pubsub.hpp
│       ├── module.hpp
│       ├── oop_observer.hpp
│       └── thread_pool.hpp
├── README.md
├── source
│   └── Main
│       ├── ModuleA.cpp
│       ├── ModuleB.cpp
│       ├── ModuleC.cpp
│       └── module_runner.cpp
└── test
```

PubSubModule/ contains the source code implementing this inter-thread pub-sub system.

Main/ under include and source contains example module running on seperate threads and exchanging messages through the pub-sub system.