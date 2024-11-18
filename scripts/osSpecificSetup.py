import distro
import subprocess
supportedos = ["Arch Linux", "Ubuntu", "Debian"]
osname = distro.name()
if osname == supportedos[0]:
    print("your os is supported")
    subprocess.run("./setup_pacman.sh")
elif osname == supportedos[1]:
    print("your os is supported")
    subprocess.run("./setup_apt.sh")
elif osname == supportedos[2]:
    print("your os is supported")
    subprocess.run("./setup_apt.sh")
else:
    print("if your os uses apt or pacman run ./script/setup_pacman.sh for pacman or ./script/setup_apt.sh for apt")
