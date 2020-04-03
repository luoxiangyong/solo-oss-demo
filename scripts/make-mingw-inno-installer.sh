#!/bin/bash
#
# Author: 罗祥勇 solo_lxy@126.com
# Description: 使用Inno Setup,制作依赖Mingw 32 W64环境的安装包
# Create At: Wed, 01 Apr 2020 12:52:54 +0800
# History: Wed, 01 Apr 2020 12:52:54 +0800 初始版本
#

# 开始前请在源代码根目录执行：
# make distclean

export PATH="/c/Program Files (x86)/Inno Setup 6":$PATH

package_name="solo-oss-demo"
package_version="1.0"

# 准备制作目录
top_srcdir=`pwd`/..
build_inno_dir=`pwd`/build-inno
contents_dir=$build_inno_dir/contents
make_build_dir=$build_inno_dir/build

# 创建相关目录
mkdir -p $contents_dir
mkdir -p $build_inno_dir
mkdir -p $make_build_dir

rm -f $build_inno_dir/inno-setup.iss
cp -f $top_srcdir/pkgs/mingw/inno-setup.iss $build_inno_dir

cd $make_build_dir
echo "开始构建，并安装于:$contents_dir"
(../../../configure --prefix=$contents_dir && make && make install) || exit 0
cd ..

cp $top_srcdir/assets/${package_name}.ico $contents_dir/bin

echo "当前目录：`pwd`"

###############################################################################
echo "拷贝mingw64中的相关dll到：$contents_dir/bin"
rm -f result.txt
rm -f tmp.txt
for file in Qt5Widgets.dll Qt5Core.dll
do 
    dll_path=/mingw64/bin/$file
    ldd $dll_path | grep -v WINDOWS |  sort  | cut -f1 -d' ' | sed -e 's/\?*//g' \
        > ${file}.txt
    cat  ${file}.txt >> tmp.txt
done;

cat tmp.txt | sort | uniq >  result.txt

for file in `cat result.txt`
do
cp -f /mingw64/bin/$file $contents_dir/bin
done

for file in Qt5Widgets.dll Qt5Core.dll
do
cp -f /mingw64/bin/$file $contents_dir/bin
done

# 拷贝QT plugins
mkdir -p $contents_dir/bin/platforms
cp  /mingw64/share/Qt5/plugins/platforms/*.dll $contents_dir/bin/platforms

###############################################################################

echo "开始制作安装包"
iscc inno-setup.iss
rm ./inno-setup.iss
cd ..
rm -rf $build_inno_dir
echo "安装包制作完成：请运行：${package_name}-${package_version}-x86_64-inno.exe"