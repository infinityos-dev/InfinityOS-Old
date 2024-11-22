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
3. Running the setup.sh
```
./setup.sh
```
4. Running the file returned by setup.sh
```
./scripts/xxx
```
5. Building the InfinityOS
```
make
```
Now you can use `bash ./scripts/run.sh` to open the disk image in Qemu and use `bash ./scripts/debug.sh` to debug the disk image on bochs.
