# libsubnet
libsubnet is a small C library for representing and working with network subnets.

## Example
A new subnet object can be created with the following code:

```c
subnet *sn = subnet_new("192.168.0.0". "255.255.0.0");
````

Alternatively, the subnet and mask can be provided in CIDR notation:

```c
subnet *sn = subnet_new_cidr("192.168.0.0/16");
```

Then certain properties can be retrieved:

```c
int num_usable_hosts = subnet_num_usable_hosts(sn);
char *broadcast_addr = subnet_broadcast_addr(sn);
```

## Contributing
Contributions are always welcome, so feel free to create a pull request for yours! This project follows the [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html), so please make sure your code is formatted accordingly before submitting a pull request.

## Support
Feel free to send me an email if you need any help using libsubnet or if you have any questions!

## License
libsubnet is licensed under the GNU General Public License, Version 3.

More information can be found in [LICENSE.md](LICENSE.md).
