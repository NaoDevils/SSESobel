Readme
---------------------------


This is our SSE Sobel implementation designed for the NAO robot's images. It currently only works with YUV422 images.

# Includes and Code
In the directory ``include`` you will find three header files.

``SIMD.h`` defines two helper functions for compiler intrinsics.

``Vector2D.h`` defines a class that inherits from ``std::vector`` for convenient indexing of a two dimensional vector, that only consists of one array. This class is used as our return type for all sobel operator functions.

``SobelDortmund.h`` is the header file from the main class ``SobelDortmund``, which implements all sobel operator functions.


The directory ``src`` contains the actual implementation file ``SobelDortmund.cpp``.

# Binaries

In the folder ``bin`` there are four versions of the static built library.

The ``x86`` folder contains a release and a debug version compiled for the robot.
These were compiled using the commands
```
clang -march=atom -std=c++11 -target i686-pc-linux-gnu -fPIC -Iinclude/ -O3 -mssse3 -pipe -fomit-frame-pointer -c src/SobelDortmund.cpp -o SobelDortmund.o
```
and
```
clang -march=atom -std=c++11 -target i686-pc-linux-gnu -fPIC -Iinclude/ -g -mssse3 -pipe -c src/SobelDortmund.cpp -o SobelDortmund.o
```

The ``x64`` folder also contains a release and a debug version compiled for Linux 64-Bit. You can use these if you have a simulator and want to build a robot's code version for your PC. They were built using the same commands as above, but without ``-march=atom`` and ``-target i686-pc-linux-gnu``.

# Documentation

There are two doxygen documentations available in the ``Doxy`` folder. There is a html version as well as the latex document.

# Changing the image sizes

Our default (**full**) image sizes are 1280x960 for the upper and 640x480 for the lower image of the robot. These sizes are used by the overloaded functions. If you want to change these alter the following lines in ``SobelDortmund.h``:
```cpp
//------------ Edit if you are using other image sizes --------------
// Constants regarding image sizes
static const int IMAGE_UPPER_FULL_WIDTH = 1280;
static const int IMAGE_UPPER_FULL_HEIGHT = 960;
static const int IMAGE_LOWER_FULL_WIDTH = 640;
static const int IMAGE_LOWER_FULL_HEIGHT = 480;
//-------------------------------------------------------------------
```
You will need to recompile the source after that.
