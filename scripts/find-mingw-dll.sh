#!/bin/bash
#
# Author: 罗祥勇 solo_lxy@126.com
# Description: 从Mingw32 W64目录中拷贝相关依赖dll，可以使本系统脱离Mingw环境运行
# Create At: Wed, 01 Apr 2020 12:52:54 +0800
# History: Wed, 01 Apr 2020 12:52:54 +0800 初始版本
#
# 

 array=("Widget.txt" test)

rm -f result.txt
rm -f tmp.txt
for file in Qt5Widgets.dll Qt5Core.dll
do 
ls -l /mingw64/bin/$file 
dll_path=/mingw64/bin/$file

ldd $dll_path | grep -v WINDOWS |  sort  | cut -f1 -d' ' | sed -e 's/\?*//g' > ${file}.txt
cat  ${file}.txt >> tmp.txt
done;

cat tmp.txt | sort | uniq >  result.txt

mkdir -p dll
for file in `cat result.txt`
do
cp -f /mingw64/bin/$file ./dll
done

for file in Qt5Widgets.dll Qt5Core.dll
do
cp -f /mingw64/bin/$file ./dll
done