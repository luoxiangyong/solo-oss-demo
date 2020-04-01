#!/bin/bash
#
# Author: 罗祥勇 solo_lxy@126.com
# Description: 制作DMG安装包，让程序直接可以被拖进/Applications目录运行
# Create At: Tue, 31 Mar 2020 12:50:13 +0800
# History: Tue, 31 Mar 2020 12:50:13 +0800 初始版本
#

# 开始前请在源代码根目录执行：
# make distclean

package_name="solo-oss-demo"
package_version="1.0"

top_srcdir=`pwd`/..
build_dmg_dir=`pwd`/./build-dmg
contents_dir=$build_dmg_dir/contents
make_build_dir=$build_dmg_dir/build

# 创建相关目录
mkdir -p $contents_dir
mkdir -p $build_dmg_dir
mkdir -p $make_build_dir

cd $make_build_dir
#build_install_dir=`pwd`/../contents
echo "开始构建，并安装于:$contents_dir"
#(../../../configure --prefix=$contents_dir && make && make install) || exit 0
cd ../..

# 创建dmg
FILESIZE=$(du -sm "${contents_dir}" | cut -f1)
FILESIZE=$((${FILESIZE} + 5))
echo "包大小:${FILESIZE}M"

echo "创建DMG..."
dmg_name="${package_name}-${package_version}"
dmg_app_name="${dmg_name}.app"
dmg_path="$build_dmg_dir/../$dmg_name"
rm -f "${dmg_path}.dmg"
volume_dir="/Volumes/${dmg_name}"
hdiutil eject $volume_dir
hdiutil create -megabytes $FILESIZE -fs HFS+ -volname $dmg_name $dmg_path

echo "挂载DMG..."
hdiutil mount "${dmg_path}.dmg"

echo "当前目录:`pwd`"
echo "从拷贝数据到DMG..."
mkdir -p "${volume_dir}/$dmg_app_name/Contents/Frameworks"
mkdir -p "${volume_dir}/$dmg_app_name/Contents/Resources"
mkdir -p "${volume_dir}/$dmg_app_name/Contents/MacOS"
#mkdir -p "${volume_dir}/Contents/\{Frameworks,Resources,MacOS\}"
# 这里的路径及参数一定要仔细，不然老是出错！！！

# 拷贝元文件
cp ../pkgs/mac/Info.plist "$volume_dir/$dmg_app_name/Contents/"
cp ../pkgs/mac/PkgInfo "$volume_dir/$dmg_app_name/Contents/"

# 拷贝可执行文件
echo "拷贝数据: $contents_dir/bin/* -> $volume_dir/$dmg_app_name/Contents/MacOS/"
(cp  "$contents_dir/bin"/* "$volume_dir/$dmg_app_name/Contents/MacOS/")

# 拷贝库文件
echo "拷贝数据: $contents_dir/lib/* -> $volume_dir/$dmg_app_name/$dmg_name/Contents/Frameworks"
(cp  "$contents_dir/lib/"* "$volume_dir/$dmg_app_name/Contents/Frameworks")

# 拷贝图标
echo "拷贝数据: $top_srcdir/assets/${package_name}.icns -> $volume_dir/$dmg_app_name/.VolumeIcon"
cp  "$top_srcdir/assets/${package_name}".icns "$volume_dir/$dmg_app_name/Contents/Resources"
cp  "$top_srcdir/assets/${package_name}".icns "$volume_dir/$dmg_app_name/"
mv  "$volume_dir/$dmg_app_name/${package_name}".icns "$volume_dir/$dmg_app_name/.VolumeIcon"

# 拷贝背景图片
echo "$top_srcdir/assets/background.png -> $volume_dir/.background/bg.png"
mkdir -p "${volume_dir}/.background"
cp  "$top_srcdir/assets/background.png" "$volume_dir"/.background/bg.png

# 建立Applications快捷方式
echo "$top_srcdir/assets/Applications -> $volume_dir/Applications"
cp  -R "$top_srcdir/assets/Applications" "$volume_dir"/

echo "卸载DMG..."
hdiutil eject $volume_dir

#rm -rf $build_dmg_dir

echo "恭喜！顺利完成dmg：${dmg_path}.dmg 文件的制作"
