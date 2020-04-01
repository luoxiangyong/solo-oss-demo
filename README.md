# 基本介绍

本程序使用了gettext、libintl、QT5等库



# 环境准备

## Ubuntu or Debian

使用的ubuntu版本是18.04 LTS

```
sudo apt-get install build-essential fakeroot dh-make
sudo apt install autoconf automake libtool
sudo apt install qtbase5-dev
```

## Mingw32 W64

使用的Windows 10

```
pacman -S mingw32-w64-x86_64-qt5
```

mingw环境下：
+ 需要添加intl库的依赖
+ 注意使用git命令时，设置：git config --global core.autocrlf true,避免不同平台下CRLF的问题
+ libtool需要添加-no-undefined，不然会报错，具体可查看libtool的手册解释
+ 如果安装了Anaconda的话，Mingw中的qt5可能会与anaconda的qt冲突，我现在的解决方法是更改了anaconda的目录名。以后找下更好的方法。


## Mac OS X 10.13.6

到[MacPorts](https://www.macports.org/install.php)下载并安装

Mac OS X下我选择安装qt513版本的qt

```
sudo port install qt513
sudo port install autoconf automake libtool gdb pkgconfig
```
该命令将一下库都安装了，其中就有我们要使用的gettext
> assimp
 bzip2
 cairo
 clang-9.0
 clang_select
 db48
 dbus
 double-conversion
 expat
 fontconfig
 freetype
 gdbm
 gettext
 giflib
 glib2
 graphite2
 harfbuzz
 icu
 jasper
 jpeg
 lcms2
 ld64
 ld64-latest
 libcxx
 libedit
 libffi
 libiconv
 libmng
 libomp
 libpixman
 libpng
 libsdl2
 libtapi
 libxml2
 llvm-9.0
 llvm_select
 lz4
 minizip
 ncurses
 openssl
 ossp-uuid
 pcre
 pcre2
 perl5
 perl5.28
 python27
 python2_select
 python_select
 qt513-qt3d
 qt513-qtbase
 qt513-qtconnectivity
 qt513-qtdeclarative
 qt513-qtgamepad
 qt513-qtgraphicaleffects
 qt513-qtimageformats
 qt513-qtlocation
 qt513-qtmacextras
 qt513-qtmultimedia
 qt513-qtnetworkauth
 qt513-qtquickcontrols
 qt513-qtquickcontrols2
 qt513-qtremoteobjects
 qt513-qtscxml
 qt513-qtsensors
 qt513-qtserialbus
 qt513-qtserialport
 qt513-qtspeech
 qt513-qtsvg
 qt513-qttools
 qt513-qttranslations
 qt513-qtwebchannel
 qt513-qtwebsockets
 qt513-qtxmlpatterns
 qt513-sqlite-plugin
 readline
 sqlite3
 tiff
 webp
 xar
 xorg-libX11
 xorg-libXau
 xorg-libXdmcp
 xorg-libXext
 xorg-libice
 xorg-libpthread-stubs
 xorg-libsm
 xorg-libxcb
 xorg-xcb-proto
 xorg-xcb-util
 xorg-xorgproto
 xrender
 xz
 zlib
 zstd



## Fedora 31



## ArchLinux

Arch Linux；构建 ID：rolling

```bash
sudo pacman -S qt5-base pkgconfig autoconf automake libtool gdb pkgconfig		
```



# 常见问题集锦

1. 如果出现libtool版本问题，执行

   ```
    autoreconf -ivf 
   ```

   强制生成相关文件即可

2. 本程序使用的intl在linux发布版上不需要直接链接，但在Mingw、Mac OS X上需要与libintl库链接

3. Bash脚本中cp指令的路径写法和字符串表示要注意了，不要搞混淆
4. 在用NSIS编写安装脚本是，要使用UTF-8 With BOM格式保存，要不然出现中文编译不通过。不过NISEdit还是是乱码