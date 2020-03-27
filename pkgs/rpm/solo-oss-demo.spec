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
xgettext --keyword=_ src/*.c src/*.cpp -o src/%{name}.pot
pushd $RPM_BUILD_DIR/%{name}-%{version}
msgmerge -U $RPM_BUILD_DIR/%{name}-%{version}/intl/%{name}_zh_CN.po $RPM_BUILD_DIR/%{name}-%{version}/src/%{name}.pot
msgfmt $RPM_BUILD_DIR/%{name}-%{version}/intl/%{name}_zh_CN.po -o $RPM_BUILD_DIR/%{name}-%{version}/%{name}.mo
cp $RPM_BUILD_DIR/%{name}-%{version}/%{name}.mo ${RPM_BUILD_ROOT}/usr/share/locale/zh_CN/LC_MESSAGES
popd 


%files
%{_bindir}/solo-hello
%{_bindir}/solo-navi-viewer
%{_libdir}/libsolo-basic.la
%{_libdir}/libsolo-basic.so
%{_libdir}/libsolo-basic.so.0
%{_libdir}/libsolo-basic.so.0.0.0
/usr/share/locale/zh_CN/LC_MESSAGES
%doc README

#%changelog
#* 2020/03/25 Xiangyong Luo <solo_lxy@126.com> - 2.10-1
#- Init create
