#!/bin/bash

current_source_dir=$(pwd)/..
rpm_build_dir=~/rpmbuild

# [ $1='' ] || echo ERRIR; exit 1

# 确保创建rpm的目录存在
if [ ! -d $rpm_build_dir ]; then
    mkdir -p $rpm_build_dir
fi

echo "创建源码压缩包 $current_source_dir"
cd $current_source_dir
make dist

name='solo-oss-demo'
version='1.0'
spec_name="${name}.spec"
package_name="${name}-${version}.tar.gz"

pushd $current_source_dir
echo  "准备rpm包创建的环境 $rpm_build_dir"
rpmdev-setuptree
echo "拷贝相关数据"
cd $rpm_build_dir
echo "PWD: $(pwd) "
echo "SOURCE: ${current_source_dir}"
echo "RPMBUILD: ${rpm_build_dir}"
cp $current_source_dir/$package_name ./SOURCES/ 
cp $current_source_dir/pkgs/rpm/${spec_name} ./SPECS/ 

echo "创建rpm包"
cd SPECS
rpmbuild -ba ${spec_name}
popd

echo "删除rpm构建环境"
#rm -rf $rpm_build_dir
