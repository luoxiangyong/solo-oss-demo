Name:     solo-oss-demo
Version:  1.0
Release:  1%{?dist}
Summary:  The "solo OSS demo" program from practice
Summary(zh_CN):  开源软件开发练习
License:  GPLv3+
#URL:      http://ftp.gnu.org/gnu/hello    
#Source0:  http://ftp.gnu.org/gnu/hello/%{name}-%{version}.tar.gz
Source0 : %{name}-%{version}.tar.gz
%description
The "solo demo" program, done with all bells and whistles of a proper FOSS 
project, including configuration, build, internationalization, help files, etc.

%description -l zh_CN
"solo demo" 程序, 包含 FOSS 项目所需的所有部分, 包括配置, 构建, 国际化, 帮助文件等.

BuildRequires:  gettext
Requires: qt5-qtbase-devel


%prep
%setup -q


%build
%configure
make %{?_smp_mflags}


%install
make install DESTDIR=%{buildroot}
mkdir -p ${RPM_BUILD_ROOT}/usr/share/locale/zh_CN/LC_MESSAGES
mkdir -p $RPM_BUILD_DIR/%{name}-%{version}/tmp
xgettext --keyword=_ src/*.c src/*.cpp -o src/so_hello.pot
pushd $RPM_BUILD_DIR/%{name}-%{version}
msgmerge $RPM_BUILD_DIR/%{name}-%{version}/intl/so_hello_zh_CN.po $RPM_BUILD_DIR/%{name}-%{version}/src/so_hello.pot
msgfmt $RPM_BUILD_DIR/%{name}-%{version}/intl/so_hello_zh_CN.po -o $RPM_BUILD_DIR/%{name}-%{version}/so_hello.mo
cp $RPM_BUILD_DIR/%{name}-%{version}/so_hello.mo ${RPM_BUILD_ROOT}/usr/share/locale/zh_CN/LC_MESSAGES
popd 


%files
%{_bindir}/so_hello
%{_bindir}/so_hello_gui
%{_libdir}/libsohello.la
%{_libdir}/libsohello.so
%{_libdir}/libsohello.so.0
%{_libdir}/libsohello.so.0.0.0
/usr/share/locale/zh_CN/LC_MESSAGES
#/usr/share/doc/so-hello/so_hello_zh_CN.po
%doc README

#%changelog
#* 2020/03/25 Xiangyong Luo <solo_lxy@126.com> - 2.10-1
#- Init create
