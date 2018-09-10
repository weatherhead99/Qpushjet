qpushjet
========

qpushjet is a desktop client for receiving [pushjet](https://pushjet.io) messages as fully integrated native desktop notifications.

At present this software is __pre-alpha__ and __non-functional__. It is in active development. So far this is a proof of concept of parts of the system, but more functionality is rapidly being developed.

Building
--------

qPushjet is intended to eventually be compatible with all major desktop operating systems. However, it is principally developed on GNU/Linux (specifically openSUSE), so testing for other systems may lag behind.

### Dependencies

At present, the only build dependency is on the Qt libraries (version >=5.6). Specifically the QtCore, QtWidgets, QtSvg, QtNetwork and QtDBus libraries are currently required. To build the program, the "-dev" or "-devel" development header libraries for all these components are needed.

You will also require the [cmake](https://cmake.org) build system generator tool (minimum version 3.2), and a build generator tool. The author's recommendation for this is the [Ninja](https://ninja-build.org) tool, but standard GNU make will be fine also. 

### Compiling

to check out and build qpushjet, use the following commands (on linux/OSX, after installing system dependencies):


```
git clone https://github.com/weatherhead99/qpushjet.git
cd qpushjet
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -GNinja
ninja
```

(you can  replace `-GNinja` and  `ninja` appropriately if you decided to use another make tool).

### Running
from a command line, you can run qpushjet like so:

```
qpushjet -s -d
```

The `-s` option starts the program with the settings dialog open. The `-d` option starts the program in debug mode, which enables some extra things to play with.
