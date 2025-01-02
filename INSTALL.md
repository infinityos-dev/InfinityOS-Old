# Platforms
You should be able to build InfinityOS successfully on the following platforms:
- Ubuntu
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
3. Installing the individual required tools
Debian-based:
```bash
curl -L https://raw.githubusercontent.com/notbonzo-com/osdev-utils/main/toolchain.sh -o /tmp/toolchain.sh
chmod +x /tmp/toolchain.sh
/tmp/toolchain.sh # The important part is to choose `i686-elf` as the architecture.
```
Arch-based:
```bash
scons toolchain
```
4. Building the InfinityOS
```
scons
```
Now you can use `bash ./scripts/run.sh`/`scons run` to open the disk image in Qemu and use `bash ./scripts/debug.sh` to debug the disk image on bochs.
