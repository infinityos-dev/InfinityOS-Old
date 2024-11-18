# Platforms
You should be able to build InfinityOS successfully on the following platforms:
- Ubuntu
- Arch Linux (Setup is supported, but hasn't been testet)
- Windows (Using WSL or Cygwin)

## Linux
1. Getting the source:
```bash
git clone https://github.com/Hexuro/InfinityOS
```
2. Changing the directory
```bash
cd ./InfinityOS
```
3. Setting the environmet up
```bash
bash ./setup.sh
```
4. Building the InfinityOS
```
make
```
Now you can use `./scripts/run.sh` to open the disk image in Qemu and use `./scripts/debug.sh` to debug the disk image on bochs.
