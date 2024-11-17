# Platforms
You should be able to build HexOS successfully on the following platforms:
- Linux Ubuntu

## Ubuntu Linux
1. Getting the source:
```bash
git clone https://github.com/Hexuro/HexOS
```
2. Setting the environmet up
```bash
./scripts/setup_debian.sh
```
3. Building the HexOS
```
make
```
Now you can use `./scripts/run.sh` to open the disk image in Qemu and use `./scripts/debug.sh` to debug the disk image on bochs.
