# RISCV

```
root@localhost:~/riscv# git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
Cloning into 'riscv-gnu-toolchain'...
remote: Enumerating objects: 387, done.
remote: Counting objects: 100% (387/387), done.
remote: Compressing objects: 100% (368/368), done.
remote: Total 7690 (delta 28), reused 91 (delta 10), pack-reused 7303
Receiving objects: 100% (7690/7690), 5.47 MiB | 4.35 MiB/s, done.
Resolving deltas: 100% (3616/3616), done.
Submodule 'qemu' (https://git.qemu.org/git/qemu.git) registered for path 'qemu'
Submodule 'riscv-binutils' (https://github.com/riscv/riscv-binutils-gdb.git) registered for path 'riscv-binutils'      
Submodule 'riscv-dejagnu' (https://github.com/riscv/riscv-dejagnu.git) registered for path 'riscv-dejagnu'
Submodule 'riscv-gcc' (https://github.com/riscv/riscv-gcc.git) registered for path 'riscv-gcc'
Submodule 'riscv-gdb' (https://github.com/riscv/riscv-binutils-gdb.git) registered for path 'riscv-gdb'
Submodule 'riscv-glibc' (https://github.com/riscv/riscv-glibc.git) registered for path 'riscv-glibc'
Submodule 'riscv-newlib' (https://github.com/riscv/riscv-newlib.git) registered for path 'riscv-newlib'
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu'...
remote: Counting objects: 490133, done.        
remote: Compressing objects: 100% (87375/87375), done.        
remote: Total 490133 (delta 402824), reused 488466 (delta 401442)        
Receiving objects: 100% (490133/490133), 173.83 MiB | 14.01 MiB/s, done.
Resolving deltas: 100% (402824/402824), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/riscv-binutils'...
remote: Enumerating objects: 881139, done.        
remote: Total 881139 (delta 0), reused 0 (delta 0), pack-reused 881139        
Receiving objects: 100% (881139/881139), 334.90 MiB | 18.23 MiB/s, done.
Resolving deltas: 100% (731709/731709), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/riscv-dejagnu'...
remote: Enumerating objects: 5208, done.        
remote: Total 5208 (delta 0), reused 0 (delta 0), pack-reused 5208        
Receiving objects: 100% (5208/5208), 3.10 MiB | 3.09 MiB/s, done.
Resolving deltas: 100% (3957/3957), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/riscv-gcc'...
remote: Enumerating objects: 15, done.        
remote: Counting objects: 100% (15/15), done.        
remote: Compressing objects: 100% (13/13), done.        
remote: Total 2451560 (delta 2), reused 4 (delta 2), pack-reused 2451545        
Receiving objects: 100% (2451560/2451560), 1.20 GiB | 18.71 MiB/s, done.
Resolving deltas: 100% (1898481/1898481), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/riscv-gdb'...
remote: Enumerating objects: 881139, done.        
remote: Total 881139 (delta 0), reused 0 (delta 0), pack-reused 881139        
Receiving objects: 100% (881139/881139), 334.90 MiB | 18.72 MiB/s, done.
Resolving deltas: 100% (731709/731709), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/riscv-glibc'...
remote: Enumerating objects: 38049, done.        
remote: Counting objects: 100% (38049/38049), done.        
remote: Compressing objects: 100% (8180/8180), done.        
remote: Total 497733 (delta 30409), reused 32756 (delta 29191), pack-reused 459684        
Receiving objects: 100% (497733/497733), 172.13 MiB | 16.28 MiB/s, done.
Resolving deltas: 100% (420592/420592), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/riscv-newlib'...
remote: Enumerating objects: 2843, done.        
remote: Counting objects: 100% (2843/2843), done.        
remote: Compressing objects: 100% (1176/1176), done.        
remote: Total 167828 (delta 1989), reused 2103 (delta 1655), pack-reused 164985        
Receiving objects: 100% (167828/167828), 100.58 MiB | 8.21 MiB/s, done.
Resolving deltas: 100% (135816/135816), done.
Submodule path 'qemu': checked out 'fdd76fecdde1ad444ff4deb7f1c4f7e4a1ef97d6'
Submodule 'capstone' (https://git.qemu.org/git/capstone.git) registered for path 'qemu/capstone'
Submodule 'dtc' (https://git.qemu.org/git/dtc.git) registered for path 'qemu/dtc'
Submodule 'roms/QemuMacDrivers' (https://git.qemu.org/git/QemuMacDrivers.git) registered for path 'qemu/roms/QemuMacDrivers'
Submodule 'roms/SLOF' (https://git.qemu.org/git/SLOF.git) registered for path 'qemu/roms/SLOF'
Submodule 'roms/edk2' (https://git.qemu.org/git/edk2.git) registered for path 'qemu/roms/edk2'
Submodule 'roms/ipxe' (https://git.qemu.org/git/ipxe.git) registered for path 'qemu/roms/ipxe'
Submodule 'roms/openbios' (https://git.qemu.org/git/openbios.git) registered for path 'qemu/roms/openbios'
Submodule 'roms/opensbi' (https://git.qemu.org/git/opensbi.git) registered for path 'qemu/roms/opensbi'
Submodule 'roms/qboot' (https://github.com/bonzini/qboot) registered for path 'qemu/roms/qboot'
Submodule 'roms/qemu-palcode' (https://git.qemu.org/git/qemu-palcode.git) registered for path 'qemu/roms/qemu-palcode' 
Submodule 'roms/seabios' (https://git.qemu.org/git/seabios.git/) registered for path 'qemu/roms/seabios'
Submodule 'roms/seabios-hppa' (https://git.qemu.org/git/seabios-hppa.git) registered for path 'qemu/roms/seabios-hppa'
Submodule 'roms/sgabios' (https://git.qemu.org/git/sgabios.git) registered for path 'qemu/roms/sgabios'
Submodule 'roms/skiboot' (https://git.qemu.org/git/skiboot.git) registered for path 'qemu/roms/skiboot'
Submodule 'roms/u-boot' (https://git.qemu.org/git/u-boot.git) registered for path 'qemu/roms/u-boot'
Submodule 'roms/u-boot-sam460ex' (https://git.qemu.org/git/u-boot-sam460ex.git) registered for path 'qemu/roms/u-boot-sam460ex'
Submodule 'slirp' (https://git.qemu.org/git/libslirp.git) registered for path 'qemu/slirp'
Submodule 'tests/fp/berkeley-softfloat-3' (https://git.qemu.org/git/berkeley-softfloat-3.git) registered for path 'qemu/tests/fp/berkeley-softfloat-3'
Submodule 'tests/fp/berkeley-testfloat-3' (https://git.qemu.org/git/berkeley-testfloat-3.git) registered for path 'qemu/tests/fp/berkeley-testfloat-3'
Submodule 'ui/keycodemapdb' (https://git.qemu.org/git/keycodemapdb.git) registered for path 'qemu/ui/keycodemapdb'
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/capstone'...
remote: Counting objects: 29721, done.        
remote: Compressing objects: 100% (11133/11133), done.        
remote: Total 29721 (delta 21899), reused 25068 (delta 18159)        
Receiving objects: 100% (29721/29721), 39.61 MiB | 1.36 MiB/s, done.
Resolving deltas: 100% (21899/21899), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/dtc'...
remote: Counting objects: 5410, done.        
remote: Compressing objects: 100% (2769/2769), done.        
remote: Total 5410 (delta 4034), reused 3460 (delta 2597)        
Receiving objects: 100% (5410/5410), 1.14 MiB | 944.00 KiB/s, done.
Resolving deltas: 100% (4034/4034), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/QemuMacDrivers'...
remote: Counting objects: 81, done.        
remote: Compressing objects: 100% (80/80), done.        
remote: Total 81 (delta 33), reused 0 (delta 0)
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/SLOF'...
remote: Counting objects: 7551, done.        
remote: Compressing objects: 100% (2670/2670), done.        
remote: Total 7551 (delta 5801), reused 6230 (delta 4795)        
Receiving objects: 100% (7551/7551), 2.17 MiB | 1.07 MiB/s, done.
Resolving deltas: 100% (5801/5801), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/edk2'...
remote: Counting objects: 352104, done.        
remote: Compressing objects: 100% (97455/97455), done.        
remote: Total 352104 (delta 256042), reused 338766 (delta 244503)        
Receiving objects: 100% (352104/352104), 251.39 MiB | 3.00 MiB/s, done.
Resolving deltas: 100% (256042/256042), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/ipxe'...
remote: Counting objects: 53154, done.        
remote: Compressing objects: 100% (13603/13603), done.        
remote: Total 53154 (delta 40389), reused 49777 (delta 37841)        
Receiving objects: 100% (53154/53154), 12.88 MiB | 5.17 MiB/s, done.
Resolving deltas: 100% (40389/40389), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/openbios'...
remote: Counting objects: 14784, done.        
remote: Compressing objects: 100% (4528/4528), done.        
remote: Total 14784 (delta 10965), reused 13795 (delta 10218)        
Receiving objects: 100% (14784/14784), 2.92 MiB | 2.58 MiB/s, done.
Resolving deltas: 100% (10965/10965), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/opensbi'...
remote: Counting objects: 5312, done.        
remote: Compressing objects: 100% (2875/2875), done.        
remote: Total 5312 (delta 3331), reused 3475 (delta 2152)        
Receiving objects: 100% (5312/5312), 924.72 KiB | 1.78 MiB/s, done.
Resolving deltas: 100% (3331/3331), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/qboot'...
remote: Enumerating objects: 35, done.        
remote: Counting objects: 100% (35/35), done.        
remote: Compressing objects: 100% (27/27), done.        
remote: Total 432 (delta 12), reused 16 (delta 7), pack-reused 397        
Receiving objects: 100% (432/432), 107.19 KiB | 336.00 KiB/s, done.
Resolving deltas: 100% (268/268), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/qemu-palcode'...
remote: Counting objects: 286, done.        
remote: Compressing objects: 100% (112/112), done.        
remote: Total 286 (delta 176), reused 277 (delta 171)        
Receiving objects: 100% (286/286), 147.87 KiB | 410.00 KiB/s, done.
Resolving deltas: 100% (176/176), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/seabios'...
remote: Counting objects: 15894, done.        
remote: Compressing objects: 100% (4135/4135), done.        
remote: Total 15894 (delta 12793), reused 14497 (delta 11751)        
Receiving objects: 100% (15894/15894), 3.33 MiB | 3.19 MiB/s, done.
Resolving deltas: 100% (12793/12793), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/seabios-hppa'...
remote: Counting objects: 16337, done.        
remote: Compressing objects: 100% (3651/3651), done.        
remote: Total 16337 (delta 13155), reused 15729 (delta 12678)        
Receiving objects: 100% (16337/16337), 3.40 MiB | 2.90 MiB/s, done.
Resolving deltas: 100% (13155/13155), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/sgabios'...
remote: Counting objects: 30, done.        
remote: Compressing objects: 100% (29/29), done.        
remote: Total 30 (delta 12), reused 0 (delta 0)        
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/skiboot'...
remote: Counting objects: 35428, done.        
remote: Compressing objects: 100% (8435/8435), done.        
remote: Total 35428 (delta 27525), reused 34692 (delta 26887)        
Receiving objects: 100% (35428/35428), 11.96 MiB | 4.81 MiB/s, done.
Resolving deltas: 100% (27525/27525), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/u-boot'...
remote: Counting objects: 709704, done.        
remote: Compressing objects: 100% (115984/115984), done.        
remote: Total 709704 (delta 590979), reused 702669 (delta 584319)        
Receiving objects: 100% (709704/709704), 139.11 MiB | 10.58 MiB/s, done.
Resolving deltas: 100% (590979/590979), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/u-boot-sam460ex'...
remote: Counting objects: 4019, done.        
remote: Compressing objects: 100% (2944/2944), done.        
remote: Total 4019 (delta 1038), reused 3985 (delta 1021)        
Receiving objects: 100% (4019/4019), 9.31 MiB | 5.96 MiB/s, done.
Resolving deltas: 100% (1038/1038), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/slirp'...
remote: Counting objects: 3202, done.        
remote: Compressing objects: 100% (1055/1055), done.        
remote: Total 3202 (delta 2477), reused 2713 (delta 2144)        
Receiving objects: 100% (3202/3202), 663.56 KiB | 1.75 MiB/s, done.
Resolving deltas: 100% (2477/2477), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/tests/fp/berkeley-softfloat-3'...
remote: Counting objects: 2555, done.        
remote: Compressing objects: 100% (204/204), done.        
remote: Total 2555 (delta 2348), reused 2555 (delta 2348)        
Receiving objects: 100% (2555/2555), 742.70 KiB | 1.02 MiB/s, done.
Resolving deltas: 100% (2348/2348), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/tests/fp/berkeley-testfloat-3'...
remote: Counting objects: 1451, done.        
remote: Compressing objects: 100% (268/268), done.        
remote: Total 1451 (delta 1180), reused 1451 (delta 1180)        
Receiving objects: 100% (1451/1451), 530.47 KiB | 787.00 KiB/s, done.
Resolving deltas: 100% (1180/1180), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/ui/keycodemapdb'...
remote: Counting objects: 313, done.        
remote: Compressing objects: 100% (135/135), done.        
remote: Total 313 (delta 155), reused 252 (delta 128)        
Receiving objects: 100% (313/313), 94.92 KiB | 276.00 KiB/s, done.
Resolving deltas: 100% (155/155), done.
Submodule path 'qemu/capstone': checked out '22ead3e0bfdb87516656453336160e0a37b066bf'
Submodule path 'qemu/dtc': checked out '88f18909db731a627456f26d779445f84e449536'
Submodule path 'qemu/roms/QemuMacDrivers': checked out '90c488d5f4a407342247b9ea869df1c2d9c8e266'
Submodule path 'qemu/roms/SLOF': checked out '8e012d6fddb62be833d746cef3f03e6c8beecde0'
Submodule path 'qemu/roms/edk2': checked out '20d2e5a125e34fc8501026613a71549b2a1a3e54'
Submodule 'SoftFloat' (https://github.com/ucb-bar/berkeley-softfloat-3.git) registered for path 'qemu/roms/edk2/ArmPkg/Library/ArmSoftFloatLib/berkeley-softfloat-3'
Submodule 'CryptoPkg/Library/OpensslLib/openssl' (https://github.com/openssl/openssl) registered for path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl'
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/edk2/ArmPkg/Library/ArmSoftFloatLib/berkeley-softfloat-3'...   
remote: Enumerating objects: 2555, done.        
remote: Total 2555 (delta 0), reused 0 (delta 0), pack-reused 2555        
Receiving objects: 100% (2555/2555), 745.72 KiB | 1.04 MiB/s, done.
Resolving deltas: 100% (2349/2349), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl'...
remote: Enumerating objects: 22, done.        
remote: Counting objects: 100% (22/22), done.        
remote: Compressing objects: 100% (19/19), done.        
remote: Total 370076 (delta 3), reused 7 (delta 3), pack-reused 370054        
Receiving objects: 100% (370076/370076), 193.88 MiB | 18.84 MiB/s, done.
Resolving deltas: 100% (255026/255026), done.
Submodule path 'qemu/roms/edk2/ArmPkg/Library/ArmSoftFloatLib/berkeley-softfloat-3': checked out 'b64af41c3276f97f0e181920400ee056b9c88037'
Submodule path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl': checked out '50eaac9f3337667259de725451f201e784599687'
Submodule 'boringssl' (https://boringssl.googlesource.com/boringssl) registered for path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/boringssl'
Submodule 'krb5' (https://github.com/krb5/krb5) registered for path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/krb5'
Submodule 'pyca.cryptography' (https://github.com/pyca/cryptography.git) registered for path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/pyca-cryptography'
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/boringssl'...        
remote: Sending approximately 147.22 MiB ...        
remote: Counting objects: 14, done        
remote: Total 75741 (delta 52449), reused 75741 (delta 52449)        
Receiving objects: 100% (75741/75741), 147.22 MiB | 18.28 MiB/s, done.
Resolving deltas: 100% (52449/52449), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/krb5'...
remote: Enumerating objects: 164, done.        
remote: Counting objects: 100% (164/164), done.        
remote: Compressing objects: 100% (124/124), done.        
remote: Total 247172 (delta 72), reused 67 (delta 39), pack-reused 247008        
Receiving objects: 100% (247172/247172), 71.45 MiB | 15.57 MiB/s, done.
Resolving deltas: 100% (198923/198923), done.
Cloning into '/root/riscv/riscv-gnu-toolchain/qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/pyca-cryptography'...
remote: Enumerating objects: 56, done.        
remote: Counting objects: 100% (56/56), done.        
remote: Compressing objects: 100% (52/52), done.        
remote: Total 53555 (delta 15), reused 15 (delta 4), pack-reused 53499        
Receiving objects: 100% (53555/53555), 45.36 MiB | 13.52 MiB/s, done.
Resolving deltas: 100% (36246/36246), done.
Submodule path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/boringssl': checked out '2070f8ad9151dc8f3a73bffaa146b5e6937a583f'
Submodule path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/krb5': checked out 'b9ad6c49505c96a088326b62a52568e3484f2168'
Submodule path 'qemu/roms/edk2/CryptoPkg/Library/OpensslLib/openssl/pyca-cryptography': checked out '09403100de2f6f1cdd0d484dcb8e620f1c335c8f'
Submodule path 'qemu/roms/ipxe': checked out 'de4565cbe76ea9f7913a01f331be3ee901bb6e17'
Submodule path 'qemu/roms/openbios': checked out '7e5b89e4295063d8eba55b9c8ce8bc681c2d129a'
Submodule path 'qemu/roms/opensbi': checked out 'ac5e821d50be631f26274765a59bc1b444ffd862'
Submodule path 'qemu/roms/qboot': checked out 'cb1c49e0cfac99b9961d136ac0194da62c28cf64'
Submodule path 'qemu/roms/qemu-palcode': checked out 'bf0e13698872450164fa7040da36a95d2d4b326f'
Submodule path 'qemu/roms/seabios': checked out 'f21b5a4aeb020f2a5e2c6503f906a9349dd2f069'
Submodule path 'qemu/roms/seabios-hppa': checked out '1630ac7d65c4a09218cc677f1fa56cd5b3140447'
Submodule path 'qemu/roms/sgabios': checked out 'cbaee52287e5f32373181cff50a00b6c4ac9015a'
Submodule path 'qemu/roms/skiboot': checked out '3a6fdede6ce117facec0108afe716cf5d0472c3f'
Submodule path 'qemu/roms/u-boot': checked out 'd3689267f92c5956e09cc7d1baa4700141662bff'
Submodule path 'qemu/roms/u-boot-sam460ex': checked out '60b3916f33e617a815973c5a6df77055b2e3a588'
Submodule path 'qemu/slirp': checked out '2faae0f778f818fadc873308f983289df697eb93'
Submodule path 'qemu/tests/fp/berkeley-softfloat-3': checked out 'b64af41c3276f97f0e181920400ee056b9c88037'
Submodule path 'qemu/tests/fp/berkeley-testfloat-3': checked out '5a59dcec19327396a011a17fd924aed4fec416b3'
Submodule path 'qemu/ui/keycodemapdb': checked out '6b3d716e2b6472eb7189d3220552280ef3d832ce'
Submodule path 'riscv-binutils': checked out 'd7f734bc7e9e5fb6c33b433973b57e1eed3a7e9f'
Submodule path 'riscv-dejagnu': checked out '4ea498a8e1fafeb568530d84db1880066478c86b'
Submodule path 'riscv-gcc': checked out '54945eb8ad5a066da2d4e6a62ffeb513d341eb41'
Submodule path 'riscv-gdb': checked out 'fec47beb8a1f0a6c4a6b0c548cded5711d0c27da'
Submodule path 'riscv-glibc': checked out '06983fe52cfe8e4779035c27e8cc5d2caab31531'
Submodule path 'riscv-newlib': checked out 'f289cef6be67da67b2d97a47d6576fa7e6b4c858'
```

## 安裝套件

```
root@localhost:~/riscv#  sudo apt-get install autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev g
awk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
Reading package lists... Done
Building dependency tree       
Reading state information... Done
Note, selecting 'libexpat1-dev' instead of 'libexpat-dev'
autoconf is already the newest version (2.69-11).
automake is already the newest version (1:1.15.1-3ubuntu2).
autotools-dev is already the newest version (20180224.1).
bc is already the newest version (1.07.1-2).
bison is already the newest version (2:3.0.4.dfsg-1build1).
build-essential is already the newest version (12.4ubuntu1).
flex is already the newest version (2.6.4-6).
gawk is already the newest version (1:4.1.4+dfsg-1build1).
libgmp-dev is already the newest version (2:6.1.2+dfsg-2).
libmpc-dev is already the newest version (1.1.0-1).
libmpfr-dev is already the newest version (4.0.1-1).
libtool is already the newest version (2.4.6-2).
patchutils is already the newest version (0.3.4-2).
zlib1g-dev is already the newest version (1:1.2.11.dfsg-0ubuntu2).
gperf is already the newest version (3.1-1).
texinfo is already the newest version (6.5.0.dfsg.1-2).
curl is already the newest version (7.58.0-2ubuntu3.8).
libexpat1-dev is already the newest version (2.2.5-3ubuntu0.2).
0 upgraded, 0 newly installed, 0 to remove and 317 not upgraded.
```

## 

```
root@localhost:~/riscv/riscv-gnu-toolchain# ./configure --prefix=/usr/local
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables...
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking for grep that handles long lines and -e... /bin/grep
checking for fgrep... /bin/grep -F
checking for grep that handles long lines and -e... (cached) /bin/grep
checking for bash... /bin/bash
checking for __gmpz_init in -lgmp... yes
checking for mpfr_init in -lmpfr... yes
checking for mpc_init2 in -lmpc... yes
checking for curl... /usr/bin/curl
checking for wget... /usr/bin/wget
checking for ftp... /usr/bin/ftp
configure: creating ./config.status
config.status: creating Makefile
config.status: creating scripts/wrapper/awk/awk
config.status: creating scripts/wrapper/sed/sed
```

## 

```
root@localhost:~/riscv/riscv-gnu-toolchain# riscv64-unknown-elf-gcc --version
riscv64-unknown-elf-gcc (GCC) 9.2.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

root@localhost:~/riscv/riscv-gnu-toolchain# qemu-system-riscv64 --version
QEMU emulator version 4.1.0
Copyright (c) 2003-2019 Fabrice Bellard and the QEMU Project developers
```

## 
