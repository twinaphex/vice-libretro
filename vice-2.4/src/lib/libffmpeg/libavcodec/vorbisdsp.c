/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifdef IDE_COMPILE
#include "ffmpeg-config.h"
#include "ide-config.h"
#else
#include "config.h"
#endif

#include "libavutil/attributes.h"
#include "vorbisdsp.h"
#include "vorbis.h"

av_cold void ff_vorbisdsp_init(VorbisDSPContext *dsp)
{
    dsp->vorbis_inverse_coupling = ff_vorbis_inverse_coupling;

#if (ARCH_AARCH64 == 1)
    if (ARCH_AARCH64)
        ff_vorbisdsp_init_aarch64(dsp);
#endif
#if (ARCH_ARM == 1)
    if (ARCH_ARM)
        ff_vorbisdsp_init_arm(dsp);
#endif
#if (ARCH_PPC == 1)
    if (ARCH_PPC)
        ff_vorbisdsp_init_ppc(dsp);
#endif
#if (ARCH_X86 == 1)
    if (ARCH_X86)
        ff_vorbisdsp_init_x86(dsp);
#endif
}
