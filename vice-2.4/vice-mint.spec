%define version 2.4.20
%define rel     1
%define prefix /usr/
Summary: VICE, the Versatile Commodore Emulator
Name: vice
Version: %version
Release: %rel
Copyright: GPL
Group: X11/Applications/Emulators
Source: http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/vice-%{version}.tar.gz
URL: http://vice-emu.sourceforge.net/
Packager: Marco van den Heuvel <blackystardust68@yahoo.com>
BuildRoot: /var/tmp/vice-build-root

%description
VICE is a set of accurate emulators for the Commodore 64, 128, VIC20,
PET, Plus4, CBM-II 8-bit computers and the C64DTV, all of which run under
the X Window System.

%prep
%setup -q

%build
CFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=%{prefix} --with-sdlsound --host=m68k-atari-mint --x-includes="" --x-libraries="" --without-resid
make

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT%{prefix}
make prefix=$RPM_BUILD_ROOT%{prefix} VICEDIR=$RPM_BUILD_ROOT%{prefix}/lib/vice install-strip
gzip -9 $RPM_BUILD_ROOT%{prefix}/man/man1/*
gzip -9 $RPM_BUILD_ROOT%{prefix}/info/*
mkdir -p $RPM_BUILD_ROOT%{_menudir}

%clean
rm -rf $RPM_BUILD_ROOT

%files

%doc AUTHORS FEEDBACK INSTALL README

%{prefix}/bin/x64
%{prefix}/bin/x64dtv
%{prefix}/bin/x64sc
%{prefix}/bin/x128
%{prefix}/bin/xplus4
%{prefix}/bin/xvic
%{prefix}/bin/xpet
%{prefix}/bin/xcbm2
%{prefix}/bin/xcbm5x0
%{prefix}/bin/c1541
%{prefix}/bin/cartconv
%{prefix}/bin/petcat
%{prefix}/bin/vsid
%{prefix}/lib/vice/
%{prefix}/man/man1/*
%{prefix}/info/vice.info*

%changelog
