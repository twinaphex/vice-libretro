/*
 * archdep.h - Miscellaneous system-specific stuff.
 *
 * Written by
 *  Akop Karapetyan <dev@psp.akop.org>
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Andreas Boose <viceteam@t-online.de>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#ifndef _ARCHDEP_H
#define _ARCHDEP_H

#include "archapi.h"
/* Default sound output mode */
#define ARCHDEP_SOUND_OUTPUT_MODE SOUND_OUTPUT_SYSTEM

/* Filesystem dependant operators.  */
#define FSDEVICE_DEFAULT_DIR   "."
#define FSDEV_DIR_SEP_STR      "/"
#define FSDEV_DIR_SEP_CHR      '/'
#define FSDEV_EXT_SEP_STR      "."
#define FSDEV_EXT_SEP_CHR      '.'

/* Path separator.  */
#define ARCHDEP_FINDPATH_SEPARATOR_CHAR         ':'
#define ARCHDEP_FINDPATH_SEPARATOR_STRING       ":"

/* Modes for fopen().  */
#define MODE_READ              "r"
#define MODE_READ_TEXT         "r"
#define MODE_READ_WRITE        "r+"
#define MODE_WRITE             "w"
#define MODE_WRITE_TEXT        "w"
#define MODE_APPEND            "w+"
#define MODE_APPEND_READ_WRITE "a+"

/* Printer default devices.  */
#define ARCHDEP_PRINTER_DEFAULT_DEV1 "print.dump"
#define ARCHDEP_PRINTER_DEFAULT_DEV2 "|lpr"
#define ARCHDEP_PRINTER_DEFAULT_DEV3 "|petlp -F PS|lpr"

/* Video chip scaling.  */
#define ARCHDEP_VICII_DSIZE   1
#define ARCHDEP_VICII_DSCAN   1
#define ARCHDEP_VICII_HWSCALE 1
#define ARCHDEP_VDC_DSIZE     1
#define ARCHDEP_VDC_DSCAN     1
#define ARCHDEP_VDC_HWSCALE   0
#define ARCHDEP_VIC_DSIZE     1
#define ARCHDEP_VIC_DSCAN     1
#define ARCHDEP_VIC_HWSCALE   1
#define ARCHDEP_CRTC_DSIZE    1
#define ARCHDEP_CRTC_DSCAN    1
#define ARCHDEP_CRTC_HWSCALE  0
#define ARCHDEP_TED_DSIZE     1
#define ARCHDEP_TED_DSCAN     1
#define ARCHDEP_TED_HWSCALE   1

/* Video chip double buffering.  */
#define ARCHDEP_VICII_DBUF 0
#define ARCHDEP_VDC_DBUF   0
#define ARCHDEP_VIC_DBUF   0
#define ARCHDEP_CRTC_DBUF  0
#define ARCHDEP_TED_DBUF   0

/* Default RS232 devices.  */
#define ARCHDEP_RS232_DEV1 "/dev/ttyS0"
#define ARCHDEP_RS232_DEV2 "/dev/ttyS1"
#define ARCHDEP_RS232_DEV3 "rs232.dump"
#define ARCHDEP_RS232_DEV4 "|lpr"

/* Default location of raw disk images.  */
#define ARCHDEP_RAWDRIVE_DEFAULT "/dev/fd0"

/* Access types */
#define ARCHDEP_R_OK R_OK
#define ARCHDEP_W_OK W_OK
#define ARCHDEP_X_OK X_OK
#define ARCHDEP_F_OK F_OK

/* Standard line delimiter.  */
#define ARCHDEP_LINE_DELIMITER "\n"

/* Ethernet default device */
#define ARCHDEP_ETHERNET_DEFAULT_DEVICE "eth0"

/* Default sound fragment size */
#define ARCHDEP_SOUND_FRAGMENT_SIZE 1

/* No key symcode.  */
#define ARCHDEP_KEYBOARD_SYM_NONE 0
/* Keyword to use for a static prototype */
#define STATIC_PROTOTYPE static
extern int sound_init_psp_device();
extern const char *archdep_home_path(void);

/* set this path to customize the preference storage */ 
extern const char *archdep_pref_path;

/* Define the default system directory (where the ROMs are).  */
#ifndef __LIBRETRO__

#ifdef __NetBSD__
#define LIBDIR          PREFIX "/share/vice"
#else
#define LIBDIR          PREFIX "./vice"
#endif

#else
extern  char retro_system_data_directory[512];
#define RETRO_DEBUG 1

#if defined(ANDROID) || defined(__ANDROID__)
#define LIBDIR "/mnt/sdcard/data"
#else
#define LIBDIR retro_system_data_directory
#endif

#endif //__LIBRETRO__

#if defined(__FreeBSD__) || defined(__NetBSD__)
#define DOCDIR          PREFIX "/share/doc/vice"
#else
#define DOCDIR          LIBDIR "./doc"
#endif

#define VICEUSERDIR     ".vice"

#endif
