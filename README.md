<div align="center">
	<img src="logo.png" width="400">
  <br/>
</div>

libsubnet is a small C library for representing and working with network subnets.  Currently, libsubnet is a small library with a limited amount of features, but if you have a feature you would like to see in the library, feel free to suggest it or submit a pull request.

## Installation

You need [CMake](https://cmake.org/) and [GNU Make](https://www.gnu.org/software/make/) installed on your system to build and install libsubnet. Both of these should be available in your package manager.

To build and install, first clone the repository and enter the project directory:

```git clone https://github.com/jonpalmisc/libsubnet.git && cd libsubnet```

Then generate a Makefile using CMake, then build and install the library:

```cmake . && make install```

## Usage

First and foremost, include libsubnet in your code:

```c
#include <libsubnet/subnet.h>
```

Now a new subnet object can be created with the following code:
/
```c
subnet *sn = subnet_new("192.168.2.64". "255.255.255.224");
````

Alternatively, the subnet and mask can be provided in CIDR notation:

```c
subnet *sn = subnet_new_cidr("192.168.2.64/27");
```

Then certain properties can be retrieved:

```c
int num_usable_hosts = subnet_num_usable_hosts(sn);   // 32
char *broadcast_addr = subnet_broadcast_addr(sn);     // 192.168.2.95
```

If you desire to create a subnet struct by hand, you can do the following:

```c
subnet *sn = malloc(sizeof(subnet));
sn->addr = 0xC0A80240;
sn->mask = 0xFFFFFFE0;
```

The code above would create a subnet with the same base address and mask as the other examples above.

Last but not least, instruct your compiler to link against libsubnet by passing `-lsubnet` as an argument when compiling.

_You may need to tell your compiler where to find the libsubnet headers and binaries.  See your compiler's manual for details on how to do this._


## Contributing

Contributions are always welcome, so feel free to create a pull request for yours! This project follows the [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html), so please make sure your code is formatted accordingly before submitting a pull request.

## Documentation

Documentation can be built with [Doxygen](http://www.doxygen.nl/) and then found in the `docs` folder.

## Support

Feel free to send me an email if you need any help using libsubnet or if you have any questions!

## License

libsubnet is licensed under the GNU General Public License, Version 3.

More information can be found in [LICENSE.md](LICENSE.md).
