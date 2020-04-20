# Mini-ARM-os

* https://github.com/jserv/mini-arm-os
* [用十分鐘 向jserv學習作業系統設計](https://www.slideshare.net/ccckmit/jserv)

## 安裝

* https://github.com/jserv/mini-arm-os

* https://unix.stackexchange.com/questions/453032/how-to-install-a-functional-arm-cross-gcc-toolchain-on-ubuntu-18-04-bionic-beav



```
sudo apt remove gcc-arm-none-eabi
sudo apt-add-repository ppa:team-gcc-arm-embedded/ppa
sudo apt update
[...] Ign:4 http://ppa.launchpad.net/team-gcc-arm-embedded/ppa/ubuntu bionic InRelease
Get:5 http://security.ubuntu.com/ubuntu bionic-security InRelease [83.2 kB]
Err:6 http://ppa.launchpad.net/team-gcc-arm-embedded/ppa/ubuntu bionic Release
404 Not Found [IP: 91.189.95.83 80]
Reading package lists... Done
E: The repository 'http://ppa.launchpad.net/team-gcc-arm-embedded/ppa/ubuntu bionic Release' does not have a Release file.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
sudo apt-install gcc-arm-embedded
```