# Platforms
You should be able to build HexOS successfully on the following platforms:
- Linux
- Windows (Using WSL or Cygwin)

## Linux
1. Getting the source:
```bash
git clone https://github.com/Hexuro/HexOS
```
2. Changing the directory
```bash
cd ./HexOS
```
3. Setting the environmet up
```bash
bash ./setup.sh
```
4. Building the HexOS
```
make
```
Now you can use `./scripts/run.sh` to open the disk image in Qemu and use `./scripts/debug.sh` to debug the disk image on bochs.
