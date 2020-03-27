#!/bin/bash

# 合并代码中需要翻译的项

xgettext --keyword=_ ../src/*.c ../src/*.cpp -o ../src/tmp.pot
msgmerge -U ../intl/solo-oss-demo_zh_CN.po ../src/test.pot
rm ../src/tmp.pot