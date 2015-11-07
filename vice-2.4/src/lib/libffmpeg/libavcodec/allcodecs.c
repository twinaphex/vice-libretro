/*
 * Provide registration of all codecs, parsers and bitstream filters for libavcodec.
 * Copyright (c) 2002 Fabrice Bellard
 *
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

/**
 * @file
 * Provide registration of all codecs, parsers and bitstream filters for libavcodec.
 */

#ifdef IDE_COMPILE
#include "ffmpeg-config.h"
#include "ide-config.h"
#else
#include "config.h"
#endif

#include "avcodec.h"
#include "version.h"

#define REGISTER_HWACCEL(X, x)                                          \
    {                                                                   \
        extern AVHWAccel ff_##x##_hwaccel;                              \
        if (CONFIG_##X##_HWACCEL)                                       \
            av_register_hwaccel(&ff_##x##_hwaccel);                     \
    }

#define REGISTER_ENCODER(X, x)                                          \
    {                                                                   \
        extern AVCodec ff_##x##_encoder;                                \
        if (CONFIG_##X##_ENCODER)                                       \
            avcodec_register(&ff_##x##_encoder);                        \
    }

#define REGISTER_DECODER(X, x)                                          \
    {                                                                   \
        extern AVCodec ff_##x##_decoder;                                \
        if (CONFIG_##X##_DECODER)                                       \
            avcodec_register(&ff_##x##_decoder);                        \
    }

#define REGISTER_ENCDEC(X, x) REGISTER_ENCODER(X, x); REGISTER_DECODER(X, x)

#define REGISTER_PARSER(X, x)                                           \
    {                                                                   \
        extern AVCodecParser ff_##x##_parser;                           \
        if (CONFIG_##X##_PARSER)                                        \
            av_register_codec_parser(&ff_##x##_parser);                 \
    }

#define REGISTER_BSF(X, x)                                              \
    {                                                                   \
        extern AVBitStreamFilter ff_##x##_bsf;                          \
        if (CONFIG_##X##_BSF)                                           \
            av_register_bitstream_filter(&ff_##x##_bsf);                \
    }

void avcodec_register_all(void)
{
    static int initialized;

    if (initialized)
        return;
    initialized = 1;

#  if (_MSC_VER < 1600)
#if (CONFIG_H263_VAAPI_HWACCEL == 1)
REGISTER_HWACCEL(H263_VAAPI, h263_vaapi); 
#endif

#if (CONFIG_H263_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(H263_VDPAU, h263_vdpau); 
#endif

#if (CONFIG_H264_DXVA2_HWACCEL == 1)
REGISTER_HWACCEL(H264_DXVA2, h264_dxva2); 
#endif

#if (CONFIG_H264_VAAPI_HWACCEL == 1)
REGISTER_HWACCEL(H264_VAAPI, h264_vaapi); 
#endif

#if (CONFIG_H264_VDA_HWACCEL == 1)
REGISTER_HWACCEL(H264_VDA, h264_vda); 
#endif

#if (CONFIG_H264_VDA_OLD_HWACCEL == 1)
REGISTER_HWACCEL(H264_VDA_OLD, h264_vda_old); 
#endif

#if (CONFIG_H264_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(H264_VDPAU, h264_vdpau); 
#endif

#if (CONFIG_MPEG1_XVMC_HWACCEL == 1)
REGISTER_HWACCEL(MPEG1_XVMC, mpeg1_xvmc); 
#endif

#if (CONFIG_MPEG1_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(MPEG1_VDPAU, mpeg1_vdpau); 
#endif

#if (CONFIG_MPEG2_XVMC_HWACCEL == 1)
REGISTER_HWACCEL(MPEG2_XVMC, mpeg2_xvmc); 
#endif

#if (CONFIG_MPEG2_DXVA2_HWACCEL == 1)
REGISTER_HWACCEL(MPEG2_DXVA2, mpeg2_dxva2); 
#endif

#if (CONFIG_MPEG2_VAAPI_HWACCEL == 1)
REGISTER_HWACCEL(MPEG2_VAAPI, mpeg2_vaapi); 
#endif

#if (CONFIG_MPEG2_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(MPEG2_VDPAU, mpeg2_vdpau); 
#endif

#if (CONFIG_MPEG4_VAAPI_HWACCEL == 1)
REGISTER_HWACCEL(MPEG4_VAAPI, mpeg4_vaapi); 
#endif

#if (CONFIG_MPEG4_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(MPEG4_VDPAU, mpeg4_vdpau); 
#endif

#if (CONFIG_VC1_DXVA2_HWACCEL == 1)
REGISTER_HWACCEL(VC1_DXVA2, vc1_dxva2); 
#endif

#if (CONFIG_VC1_VAAPI_HWACCEL == 1)
REGISTER_HWACCEL(VC1_VAAPI, vc1_vaapi); 
#endif

#if (CONFIG_VC1_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(VC1_VDPAU, vc1_vdpau); 
#endif

#if (CONFIG_WMV3_DXVA2_HWACCEL == 1)
REGISTER_HWACCEL(WMV3_DXVA2, wmv3_dxva2); 
#endif

#if (CONFIG_WMV3_VAAPI_HWACCEL == 1)
REGISTER_HWACCEL(WMV3_VAAPI, wmv3_vaapi); 
#endif

#if (CONFIG_WMV3_VDPAU_HWACCEL == 1)
REGISTER_HWACCEL(WMV3_VDPAU, wmv3_vdpau); 
#endif



#if (CONFIG_A64MULTI_ENCODER == 1)
REGISTER_ENCODER(A64MULTI, a64multi); 
#endif

#if (CONFIG_A64MULTI5_ENCODER == 1)
REGISTER_ENCODER(A64MULTI5, a64multi5); 
#endif

#if (CONFIG_ALIAS_PIX_ENCODER == 1)
REGISTER_ENCODER(ALIAS_PIX, alias_pix); 
#endif

#if (CONFIG_AMV_ENCODER == 1)
REGISTER_ENCODER(AMV, amv); 
#endif

#if (CONFIG_ASV1_ENCODER == 1)
REGISTER_ENCODER(ASV1, asv1); 
#endif

#if (CONFIG_ASV2_ENCODER == 1)
REGISTER_ENCODER(ASV2, asv2); 
#endif

#if (CONFIG_AVRP_ENCODER == 1)
REGISTER_ENCODER(AVRP, avrp); 
#endif

#if (CONFIG_AVUI_ENCODER == 1)
REGISTER_ENCODER(AVUI, avui); 
#endif

#if (CONFIG_AYUV_ENCODER == 1)
REGISTER_ENCODER(AYUV, ayuv); 
#endif

#if (CONFIG_BMP_ENCODER == 1)
REGISTER_ENCODER(BMP, bmp); 
#endif

#if (CONFIG_CINEPAK_ENCODER == 1)
REGISTER_ENCODER(CINEPAK, cinepak); 
#endif

#if (CONFIG_CLJR_ENCODER == 1)
REGISTER_ENCODER(CLJR, cljr); 
#endif

#if (CONFIG_COMFORTNOISE_ENCODER == 1)
REGISTER_ENCODER(COMFORTNOISE, comfortnoise); 
#endif

#if (CONFIG_DNXHD_ENCODER == 1)
REGISTER_ENCODER(DNXHD, dnxhd); 
#endif

#if (CONFIG_DPX_ENCODER == 1)
REGISTER_ENCODER(DPX, dpx); 
#endif

#if (CONFIG_DVVIDEO_ENCODER == 1)
REGISTER_ENCODER(DVVIDEO, dvvideo); 
#endif

#if (CONFIG_FFV1_ENCODER == 1)
REGISTER_ENCODER(FFV1, ffv1); 
#endif

#if (CONFIG_FFVHUFF_ENCODER == 1)
REGISTER_ENCODER(FFVHUFF, ffvhuff); 
#endif

#if (CONFIG_FLASHSV_ENCODER == 1)
REGISTER_ENCODER(FLASHSV, flashsv); 
#endif

#if (CONFIG_FLASHSV2_ENCODER == 1)
REGISTER_ENCODER(FLASHSV2, flashsv2); 
#endif

#if (CONFIG_FLV_ENCODER == 1)
REGISTER_ENCODER(FLV, flv); 
#endif

#if (CONFIG_GIF_ENCODER == 1)
REGISTER_ENCODER(GIF, gif); 
#endif

#if (CONFIG_H261_ENCODER == 1)
REGISTER_ENCODER(H261, h261); 
#endif

#if (CONFIG_H263_ENCODER == 1)
REGISTER_ENCODER(H263, h263); 
#endif

#if (CONFIG_H263P_ENCODER == 1)
REGISTER_ENCODER(H263P, h263p); 
#endif

#if (CONFIG_HUFFYUV_ENCODER == 1)
REGISTER_ENCODER(HUFFYUV, huffyuv); 
#endif

#if (CONFIG_JPEG2000_ENCODER == 1)
REGISTER_ENCODER(JPEG2000, jpeg2000); 
#endif

#if (CONFIG_JPEGLS_ENCODER == 1)
REGISTER_ENCODER(JPEGLS, jpegls); 
#endif

#if (CONFIG_LJPEG_ENCODER == 1)
REGISTER_ENCODER(LJPEG, ljpeg); 
#endif

#if (CONFIG_MJPEG_ENCODER == 1)
REGISTER_ENCODER(MJPEG, mjpeg); 
#endif

#if (CONFIG_MPEG1VIDEO_ENCODER == 1)
REGISTER_ENCODER(MPEG1VIDEO, mpeg1video); 
#endif

#if (CONFIG_MPEG2VIDEO_ENCODER == 1)
REGISTER_ENCODER(MPEG2VIDEO, mpeg2video); 
#endif

#if (CONFIG_MPEG4_ENCODER == 1)
REGISTER_ENCODER(MPEG4, mpeg4); 
#endif

#if (CONFIG_MSMPEG4V2_ENCODER == 1)
REGISTER_ENCODER(MSMPEG4V2, msmpeg4v2); 
#endif

#if (CONFIG_MSMPEG4V3_ENCODER == 1)
REGISTER_ENCODER(MSMPEG4V3, msmpeg4v3); 
#endif

#if (CONFIG_MSVIDEO1_ENCODER == 1)
REGISTER_ENCODER(MSVIDEO1, msvideo1); 
#endif

#if (CONFIG_PAM_ENCODER == 1)
REGISTER_ENCODER(PAM, pam); 
#endif

#if (CONFIG_PBM_ENCODER == 1)
REGISTER_ENCODER(PBM, pbm); 
#endif

#if (CONFIG_PCX_ENCODER == 1)
REGISTER_ENCODER(PCX, pcx); 
#endif

#if (CONFIG_PGM_ENCODER == 1)
REGISTER_ENCODER(PGM, pgm); 
#endif

#if (CONFIG_PGMYUV_ENCODER == 1)
REGISTER_ENCODER(PGMYUV, pgmyuv); 
#endif

#if (CONFIG_PNG_ENCODER == 1)
REGISTER_ENCODER(PNG, png); 
#endif

#if (CONFIG_PPM_ENCODER == 1)
REGISTER_ENCODER(PPM, ppm); 
#endif

#if (CONFIG_PRORES_ENCODER == 1)
REGISTER_ENCODER(PRORES, prores); 
#endif

#if (CONFIG_PRORES_AW_ENCODER == 1)
REGISTER_ENCODER(PRORES_AW, prores_aw); 
#endif

#if (CONFIG_PRORES_KS_ENCODER == 1)
REGISTER_ENCODER(PRORES_KS, prores_ks); 
#endif

#if (CONFIG_QTRLE_ENCODER == 1)
REGISTER_ENCODER(QTRLE, qtrle); 
#endif

#if (CONFIG_R10K_ENCODER == 1)
REGISTER_ENCODER(R10K, r10k); 
#endif

#if (CONFIG_R210_ENCODER == 1)
REGISTER_ENCODER(R210, r210); 
#endif

#if (CONFIG_RAWVIDEO_ENCODER == 1)
REGISTER_ENCODER(RAWVIDEO, rawvideo); 
#endif

#if (CONFIG_ROQ_ENCODER == 1)
REGISTER_ENCODER(ROQ, roq); 
#endif

#if (CONFIG_RV10_ENCODER == 1)
REGISTER_ENCODER(RV10, rv10); 
#endif

#if (CONFIG_RV20_ENCODER == 1)
REGISTER_ENCODER(RV20, rv20); 
#endif

#if (CONFIG_S302M_ENCODER == 1)
REGISTER_ENCODER(S302M, s302m); 
#endif

#if (CONFIG_SGI_ENCODER == 1)
REGISTER_ENCODER(SGI, sgi); 
#endif

#if (CONFIG_SNOW_ENCODER == 1)
REGISTER_ENCODER(SNOW, snow); 
#endif

#if (CONFIG_SUNRAST_ENCODER == 1)
REGISTER_ENCODER(SUNRAST, sunrast); 
#endif

#if (CONFIG_SVQ1_ENCODER == 1)
REGISTER_ENCODER(SVQ1, svq1); 
#endif

#if (CONFIG_TARGA_ENCODER == 1)
REGISTER_ENCODER(TARGA, targa); 
#endif

#if (CONFIG_TIFF_ENCODER == 1)
REGISTER_ENCODER(TIFF, tiff); 
#endif

#if (CONFIG_UTVIDEO_ENCODER == 1)
REGISTER_ENCODER(UTVIDEO, utvideo); 
#endif

#if (CONFIG_V210_ENCODER == 1)
REGISTER_ENCODER(V210, v210); 
#endif

#if (CONFIG_V308_ENCODER == 1)
REGISTER_ENCODER(V308, v308); 
#endif

#if (CONFIG_V408_ENCODER == 1)
REGISTER_ENCODER(V408, v408); 
#endif

#if (CONFIG_V410_ENCODER == 1)
REGISTER_ENCODER(V410, v410); 
#endif

#if (CONFIG_WMV1_ENCODER == 1)
REGISTER_ENCODER(WMV1, wmv1); 
#endif

#if (CONFIG_WMV2_ENCODER == 1)
REGISTER_ENCODER(WMV2, wmv2); 
#endif

#if (CONFIG_XBM_ENCODER == 1)
REGISTER_ENCODER(XBM, xbm); 
#endif

#if (CONFIG_XFACE_ENCODER == 1)
REGISTER_ENCODER(XFACE, xface); 
#endif

#if (CONFIG_XWD_ENCODER == 1)
REGISTER_ENCODER(XWD, xwd); 
#endif

#if (CONFIG_Y41P_ENCODER == 1)
REGISTER_ENCODER(Y41P, y41p); 
#endif

#if (CONFIG_YUV4_ENCODER == 1)
REGISTER_ENCODER(YUV4, yuv4); 
#endif

#if (CONFIG_ZLIB_ENCODER == 1)
REGISTER_ENCODER(ZLIB, zlib); 
#endif

#if (CONFIG_ZMBV_ENCODER == 1)
REGISTER_ENCODER(ZMBV, zmbv); 
#endif

#if (CONFIG_AAC_ENCODER == 1)
REGISTER_ENCODER(AAC, aac); 
#endif

#if (CONFIG_AC3_ENCODER == 1)
REGISTER_ENCODER(AC3, ac3); 
#endif

#if (CONFIG_AC3_FIXED_ENCODER == 1)
REGISTER_ENCODER(AC3_FIXED, ac3_fixed); 
#endif

#if (CONFIG_ALAC_ENCODER == 1)
REGISTER_ENCODER(ALAC, alac); 
#endif

#if (CONFIG_DCA_ENCODER == 1)
REGISTER_ENCODER(DCA, dca); 
#endif

#if (CONFIG_EAC3_ENCODER == 1)
REGISTER_ENCODER(EAC3, eac3); 
#endif

#if (CONFIG_FLAC_ENCODER == 1)
REGISTER_ENCODER(FLAC, flac); 
#endif

#if (CONFIG_G723_1_ENCODER == 1)
REGISTER_ENCODER(G723_1, g723_1); 
#endif

#if (CONFIG_MP2_ENCODER == 1)
REGISTER_ENCODER(MP2, mp2); 
#endif

#if (CONFIG_MP2FIXED_ENCODER == 1)
REGISTER_ENCODER(MP2FIXED, mp2fixed); 
#endif

#if (CONFIG_NELLYMOSER_ENCODER == 1)
REGISTER_ENCODER(NELLYMOSER, nellymoser); 
#endif

#if (CONFIG_RA_144_ENCODER == 1)
REGISTER_ENCODER(RA_144, ra_144); 
#endif

#if (CONFIG_SONIC_ENCODER == 1)
REGISTER_ENCODER(SONIC, sonic); 
#endif

#if (CONFIG_SONIC_LS_ENCODER == 1)
REGISTER_ENCODER(SONIC_LS, sonic_ls); 
#endif

#if (CONFIG_TTA_ENCODER == 1)
REGISTER_ENCODER(TTA, tta); 
#endif

#if (CONFIG_VORBIS_ENCODER == 1)
REGISTER_ENCODER(VORBIS, vorbis); 
#endif

#if (CONFIG_WAVPACK_ENCODER == 1)
REGISTER_ENCODER(WAVPACK, wavpack); 
#endif

#if (CONFIG_WMAV1_ENCODER == 1)
REGISTER_ENCODER(WMAV1, wmav1); 
#endif

#if (CONFIG_WMAV2_ENCODER == 1)
REGISTER_ENCODER(WMAV2, wmav2); 
#endif

#if (CONFIG_PCM_ALAW_ENCODER == 1)
REGISTER_ENCODER(PCM_ALAW, pcm_alaw); 
#endif

#if (CONFIG_PCM_F32BE_ENCODER == 1)
REGISTER_ENCODER(PCM_F32BE, pcm_f32be); 
#endif

#if (CONFIG_PCM_F32LE_ENCODER == 1)
REGISTER_ENCODER(PCM_F32LE, pcm_f32le); 
#endif

#if (CONFIG_PCM_F64BE_ENCODER == 1)
REGISTER_ENCODER(PCM_F64BE, pcm_f64be); 
#endif

#if (CONFIG_PCM_F64LE_ENCODER == 1)
REGISTER_ENCODER(PCM_F64LE, pcm_f64le); 
#endif

#if (CONFIG_PCM_MULAW_ENCODER == 1)
REGISTER_ENCODER(PCM_MULAW, pcm_mulaw); 
#endif

#if (CONFIG_PCM_S8_ENCODER == 1)
REGISTER_ENCODER(PCM_S8, pcm_s8); 
#endif

#if (CONFIG_PCM_S8_PLANAR_ENCODER == 1)
REGISTER_ENCODER(PCM_S8_PLANAR, pcm_s8_planar); 
#endif

#if (CONFIG_PCM_S16BE_ENCODER == 1)
REGISTER_ENCODER(PCM_S16BE, pcm_s16be); 
#endif

#if (CONFIG_PCM_S16BE_PLANAR_ENCODER == 1)
REGISTER_ENCODER(PCM_S16BE_PLANAR, pcm_s16be_planar); 
#endif

#if (CONFIG_PCM_S16LE_ENCODER == 1)
REGISTER_ENCODER(PCM_S16LE, pcm_s16le); 
#endif

#if (CONFIG_PCM_S16LE_PLANAR_ENCODER == 1)
REGISTER_ENCODER(PCM_S16LE_PLANAR, pcm_s16le_planar); 
#endif

#if (CONFIG_PCM_S24BE_ENCODER == 1)
REGISTER_ENCODER(PCM_S24BE, pcm_s24be); 
#endif

#if (CONFIG_PCM_S24DAUD_ENCODER == 1)
REGISTER_ENCODER(PCM_S24DAUD, pcm_s24daud); 
#endif

#if (CONFIG_PCM_S24LE_PLANAR_ENCODER == 1)
REGISTER_ENCODER(PCM_S24LE_PLANAR, pcm_s24le_planar); 
#endif

#if (CONFIG_PCM_S24LE_ENCODER == 1)
REGISTER_ENCODER(PCM_S24LE, pcm_s24le); 
#endif

#if (CONFIG_PCM_S32BE_ENCODER == 1)
REGISTER_ENCODER(PCM_S32BE, pcm_s32be); 
#endif

#if (CONFIG_PCM_S32LE_ENCODER == 1)
REGISTER_ENCODER(PCM_S32LE, pcm_s32le); 
#endif

#if (CONFIG_PCM_S32LE_PLANAR_ENCODER == 1)
REGISTER_ENCODER(PCM_S32LE_PLANAR, pcm_s32le_planar); 
#endif

#if (CONFIG_PCM_U8_ENCODER == 1)
REGISTER_ENCODER(PCM_U8, pcm_u8); 
#endif

#if (CONFIG_PCM_U16BE_ENCODER == 1)
REGISTER_ENCODER(PCM_U16BE, pcm_u16be); 
#endif

#if (CONFIG_PCM_U16LE_ENCODER == 1)
REGISTER_ENCODER(PCM_U16LE, pcm_u16le); 
#endif

#if (CONFIG_PCM_U24BE_ENCODER == 1)
REGISTER_ENCODER(PCM_U24BE, pcm_u24be); 
#endif

#if (CONFIG_PCM_U24LE_ENCODER == 1)
REGISTER_ENCODER(PCM_U24LE, pcm_u24le); 
#endif

#if (CONFIG_PCM_U32BE_ENCODER == 1)
REGISTER_ENCODER(PCM_U32BE, pcm_u32be); 
#endif

#if (CONFIG_PCM_U32LE_ENCODER == 1)
REGISTER_ENCODER(PCM_U32LE, pcm_u32le); 
#endif

#if (CONFIG_ROQ_DPCM_ENCODER == 1)
REGISTER_ENCODER(ROQ_DPCM, roq_dpcm); 
#endif

#if (CONFIG_ADPCM_ADX_ENCODER == 1)
REGISTER_ENCODER(ADPCM_ADX, adpcm_adx); 
#endif

#if (CONFIG_ADPCM_G722_ENCODER == 1)
REGISTER_ENCODER(ADPCM_G722, adpcm_g722); 
#endif

#if (CONFIG_ADPCM_G726_ENCODER == 1)
REGISTER_ENCODER(ADPCM_G726, adpcm_g726); 
#endif

#if (CONFIG_ADPCM_IMA_QT_ENCODER == 1)
REGISTER_ENCODER(ADPCM_IMA_QT, adpcm_ima_qt); 
#endif

#if (CONFIG_ADPCM_IMA_WAV_ENCODER == 1)
REGISTER_ENCODER(ADPCM_IMA_WAV, adpcm_ima_wav); 
#endif

#if (CONFIG_ADPCM_MS_ENCODER == 1)
REGISTER_ENCODER(ADPCM_MS, adpcm_ms); 
#endif

#if (CONFIG_ADPCM_SWF_ENCODER == 1)
REGISTER_ENCODER(ADPCM_SWF, adpcm_swf); 
#endif

#if (CONFIG_ADPCM_YAMAHA_ENCODER == 1)
REGISTER_ENCODER(ADPCM_YAMAHA, adpcm_yamaha); 
#endif

#if (CONFIG_SSA_ENCODER == 1)
REGISTER_ENCODER(SSA, ssa); 
#endif

#if (CONFIG_ASS_ENCODER == 1)
REGISTER_ENCODER(ASS, ass); 
#endif

#if (CONFIG_DVBSUB_ENCODER == 1)
REGISTER_ENCODER(DVBSUB, dvbsub); 
#endif

#if (CONFIG_DVDSUB_ENCODER == 1)
REGISTER_ENCODER(DVDSUB, dvdsub); 
#endif

#if (CONFIG_MOVTEXT_ENCODER == 1)
REGISTER_ENCODER(MOVTEXT, movtext); 
#endif

#if (CONFIG_SRT_ENCODER == 1)
REGISTER_ENCODER(SRT, srt); 
#endif

#if (CONFIG_SUBRIP_ENCODER == 1)
REGISTER_ENCODER(SUBRIP, subrip); 
#endif

#if (CONFIG_WEBVTT_ENCODER == 1)
REGISTER_ENCODER(WEBVTT, webvtt); 
#endif

#if (CONFIG_XSUB_ENCODER == 1)
REGISTER_ENCODER(XSUB, xsub); 
#endif

#if (CONFIG_LIBFAAC_ENCODER == 1)
REGISTER_ENCODER(LIBFAAC, libfaac); 
#endif

#if (CONFIG_LIBFDK_AAC_ENCODER == 1)
REGISTER_ENCODER(LIBFDK_AAC, libfdk_aac); 
#endif

#if (CONFIG_LIBGSM_ENCODER == 1)
REGISTER_ENCODER(LIBGSM, libgsm); 
#endif

#if (CONFIG_LIBGSM_MS_ENCODER == 1)
REGISTER_ENCODER(LIBGSM_MS, libgsm_ms); 
#endif

#if (CONFIG_LIBILBC_ENCODER == 1)
REGISTER_ENCODER(LIBILBC, libilbc); 
#endif

#if (CONFIG_LIBMP3LAME_ENCODER == 1)
REGISTER_ENCODER(LIBMP3LAME, libmp3lame); 
#endif

#if (CONFIG_LIBOPENCORE_AMRNB_ENCODER == 1)
REGISTER_ENCODER(LIBOPENCORE_AMRNB, libopencore_amrnb); 
#endif

#if (CONFIG_LIBOPENJPEG_ENCODER == 1)
REGISTER_ENCODER(LIBOPENJPEG, libopenjpeg); 
#endif

#if (CONFIG_LIBOPUS_ENCODER == 1)
REGISTER_ENCODER(LIBOPUS, libopus); 
#endif

#if (CONFIG_LIBSCHROEDINGER_ENCODER == 1)
REGISTER_ENCODER(LIBSCHROEDINGER, libschroedinger); 
#endif

#if (CONFIG_LIBSHINE_ENCODER == 1)
REGISTER_ENCODER(LIBSHINE, libshine); 
#endif

#if (CONFIG_LIBSPEEX_ENCODER == 1)
REGISTER_ENCODER(LIBSPEEX, libspeex); 
#endif

#if (CONFIG_LIBTHEORA_ENCODER == 1)
REGISTER_ENCODER(LIBTHEORA, libtheora); 
#endif

#if (CONFIG_LIBTWOLAME_ENCODER == 1)
REGISTER_ENCODER(LIBTWOLAME, libtwolame); 
#endif

#if (CONFIG_LIBUTVIDEO_ENCODER == 1)
REGISTER_ENCODER(LIBUTVIDEO, libutvideo); 
#endif

#if (CONFIG_LIBVO_AACENC_ENCODER == 1)
REGISTER_ENCODER(LIBVO_AACENC, libvo_aacenc); 
#endif

#if (CONFIG_LIBVO_AMRWBENC_ENCODER == 1)
REGISTER_ENCODER(LIBVO_AMRWBENC, libvo_amrwbenc); 
#endif

#if (CONFIG_LIBVORBIS_ENCODER == 1)
REGISTER_ENCODER(LIBVORBIS, libvorbis); 
#endif

#if (CONFIG_LIBVPX_VP8_ENCODER == 1)
REGISTER_ENCODER(LIBVPX_VP8, libvpx_vp8); 
#endif

#if (CONFIG_LIBVPX_VP9_ENCODER == 1)
REGISTER_ENCODER(LIBVPX_VP9, libvpx_vp9); 
#endif

#if (CONFIG_LIBWAVPACK_ENCODER == 1)
REGISTER_ENCODER(LIBWAVPACK, libwavpack); 
#endif

#if (CONFIG_LIBWEBP_ENCODER == 1)
REGISTER_ENCODER(LIBWEBP, libwebp); 
#endif

#if (CONFIG_LIBX264_ENCODER == 1)
REGISTER_ENCODER(LIBX264, libx264); 
#endif

#if (CONFIG_LIBX264RGB_ENCODER == 1)
REGISTER_ENCODER(LIBX264RGB, libx264rgb); 
#endif

#if (CONFIG_LIBX265_ENCODER == 1)
REGISTER_ENCODER(LIBX265, libx265); 
#endif

#if (CONFIG_LIBXAVS_ENCODER == 1)
REGISTER_ENCODER(LIBXAVS, libxavs); 
#endif

#if (CONFIG_LIBXVID_ENCODER == 1)
REGISTER_ENCODER(LIBXVID, libxvid); 
#endif

#if (CONFIG_LIBAACPLUS_ENCODER == 1)
REGISTER_ENCODER(LIBAACPLUS, libaacplus); 
#endif



#if (CONFIG_AASC_DECODER == 1)
REGISTER_DECODER(AASC, aasc); 
#endif

#if (CONFIG_AIC_DECODER == 1)
REGISTER_DECODER(AIC, aic); 
#endif

#if (CONFIG_ALIAS_PIX_DECODER == 1)
REGISTER_DECODER(ALIAS_PIX, alias_pix); 
#endif

#if (CONFIG_AMV_DECODER == 1)
REGISTER_DECODER(AMV, amv); 
#endif

#if (CONFIG_ANM_DECODER == 1)
REGISTER_DECODER(ANM, anm); 
#endif

#if (CONFIG_ANSI_DECODER == 1)
REGISTER_DECODER(ANSI, ansi); 
#endif

#if (CONFIG_ASV1_DECODER == 1)
REGISTER_DECODER(ASV1, asv1); 
#endif

#if (CONFIG_ASV2_DECODER == 1)
REGISTER_DECODER(ASV2, asv2); 
#endif

#if (CONFIG_AURA_DECODER == 1)
REGISTER_DECODER(AURA, aura); 
#endif

#if (CONFIG_AURA2_DECODER == 1)
REGISTER_DECODER(AURA2, aura2); 
#endif

#if (CONFIG_AVRP_DECODER == 1)
REGISTER_DECODER(AVRP, avrp); 
#endif

#if (CONFIG_AVRN_DECODER == 1)
REGISTER_DECODER(AVRN, avrn); 
#endif

#if (CONFIG_AVS_DECODER == 1)
REGISTER_DECODER(AVS, avs); 
#endif

#if (CONFIG_AVUI_DECODER == 1)
REGISTER_DECODER(AVUI, avui); 
#endif

#if (CONFIG_AYUV_DECODER == 1)
REGISTER_DECODER(AYUV, ayuv); 
#endif

#if (CONFIG_BETHSOFTVID_DECODER == 1)
REGISTER_DECODER(BETHSOFTVID, bethsoftvid); 
#endif

#if (CONFIG_BFI_DECODER == 1)
REGISTER_DECODER(BFI, bfi); 
#endif

#if (CONFIG_BINK_DECODER == 1)
REGISTER_DECODER(BINK, bink); 
#endif

#if (CONFIG_BMP_DECODER == 1)
REGISTER_DECODER(BMP, bmp); 
#endif

#if (CONFIG_BMV_VIDEO_DECODER == 1)
REGISTER_DECODER(BMV_VIDEO, bmv_video); 
#endif

#if (CONFIG_BRENDER_PIX_DECODER == 1)
REGISTER_DECODER(BRENDER_PIX, brender_pix); 
#endif

#if (CONFIG_C93_DECODER == 1)
REGISTER_DECODER(C93, c93); 
#endif

#if (CONFIG_CAVS_DECODER == 1)
REGISTER_DECODER(CAVS, cavs); 
#endif

#if (CONFIG_CDGRAPHICS_DECODER == 1)
REGISTER_DECODER(CDGRAPHICS, cdgraphics); 
#endif

#if (CONFIG_CDXL_DECODER == 1)
REGISTER_DECODER(CDXL, cdxl); 
#endif

#if (CONFIG_CINEPAK_DECODER == 1)
REGISTER_DECODER(CINEPAK, cinepak); 
#endif

#if (CONFIG_CLJR_DECODER == 1)
REGISTER_DECODER(CLJR, cljr); 
#endif

#if (CONFIG_CLLC_DECODER == 1)
REGISTER_DECODER(CLLC, cllc); 
#endif

#if (CONFIG_COMFORTNOISE_DECODER == 1)
REGISTER_DECODER(COMFORTNOISE, comfortnoise); 
#endif

#if (CONFIG_CPIA_DECODER == 1)
REGISTER_DECODER(CPIA, cpia); 
#endif

#if (CONFIG_CSCD_DECODER == 1)
REGISTER_DECODER(CSCD, cscd); 
#endif

#if (CONFIG_CYUV_DECODER == 1)
REGISTER_DECODER(CYUV, cyuv); 
#endif

#if (CONFIG_DFA_DECODER == 1)
REGISTER_DECODER(DFA, dfa); 
#endif

#if (CONFIG_DIRAC_DECODER == 1)
REGISTER_DECODER(DIRAC, dirac); 
#endif

#if (CONFIG_DNXHD_DECODER == 1)
REGISTER_DECODER(DNXHD, dnxhd); 
#endif

#if (CONFIG_DPX_DECODER == 1)
REGISTER_DECODER(DPX, dpx); 
#endif

#if (CONFIG_DSICINVIDEO_DECODER == 1)
REGISTER_DECODER(DSICINVIDEO, dsicinvideo); 
#endif

#if (CONFIG_DVVIDEO_DECODER == 1)
REGISTER_DECODER(DVVIDEO, dvvideo); 
#endif

#if (CONFIG_DXA_DECODER == 1)
REGISTER_DECODER(DXA, dxa); 
#endif

#if (CONFIG_DXTORY_DECODER == 1)
REGISTER_DECODER(DXTORY, dxtory); 
#endif

#if (CONFIG_EACMV_DECODER == 1)
REGISTER_DECODER(EACMV, eacmv); 
#endif

#if (CONFIG_EAMAD_DECODER == 1)
REGISTER_DECODER(EAMAD, eamad); 
#endif

#if (CONFIG_EATGQ_DECODER == 1)
REGISTER_DECODER(EATGQ, eatgq); 
#endif

#if (CONFIG_EATGV_DECODER == 1)
REGISTER_DECODER(EATGV, eatgv); 
#endif

#if (CONFIG_EATQI_DECODER == 1)
REGISTER_DECODER(EATQI, eatqi); 
#endif

#if (CONFIG_EIGHTBPS_DECODER == 1)
REGISTER_DECODER(EIGHTBPS, eightbps); 
#endif

#if (CONFIG_EIGHTSVX_EXP_DECODER == 1)
REGISTER_DECODER(EIGHTSVX_EXP, eightsvx_exp); 
#endif

#if (CONFIG_EIGHTSVX_FIB_DECODER == 1)
REGISTER_DECODER(EIGHTSVX_FIB, eightsvx_fib); 
#endif

#if (CONFIG_ESCAPE124_DECODER == 1)
REGISTER_DECODER(ESCAPE124, escape124); 
#endif

#if (CONFIG_ESCAPE130_DECODER == 1)
REGISTER_DECODER(ESCAPE130, escape130); 
#endif

#if (CONFIG_EXR_DECODER == 1)
REGISTER_DECODER(EXR, exr); 
#endif

#if (CONFIG_FFV1_DECODER == 1)
REGISTER_DECODER(FFV1, ffv1); 
#endif

#if (CONFIG_FFVHUFF_DECODER == 1)
REGISTER_DECODER(FFVHUFF, ffvhuff); 
#endif

#if (CONFIG_FIC_DECODER == 1)
REGISTER_DECODER(FIC, fic); 
#endif

#if (CONFIG_FLASHSV_DECODER == 1)
REGISTER_DECODER(FLASHSV, flashsv); 
#endif

#if (CONFIG_FLASHSV2_DECODER == 1)
REGISTER_DECODER(FLASHSV2, flashsv2); 
#endif

#if (CONFIG_FLIC_DECODER == 1)
REGISTER_DECODER(FLIC, flic); 
#endif

#if (CONFIG_FLV_DECODER == 1)
REGISTER_DECODER(FLV, flv); 
#endif

#if (CONFIG_FOURXM_DECODER == 1)
REGISTER_DECODER(FOURXM, fourxm); 
#endif

#if (CONFIG_FRAPS_DECODER == 1)
REGISTER_DECODER(FRAPS, fraps); 
#endif

#if (CONFIG_FRWU_DECODER == 1)
REGISTER_DECODER(FRWU, frwu); 
#endif

#if (CONFIG_G2M_DECODER == 1)
REGISTER_DECODER(G2M, g2m); 
#endif

#if (CONFIG_GIF_DECODER == 1)
REGISTER_DECODER(GIF, gif); 
#endif

#if (CONFIG_H261_DECODER == 1)
REGISTER_DECODER(H261, h261); 
#endif

#if (CONFIG_H263_DECODER == 1)
REGISTER_DECODER(H263, h263); 
#endif

#if (CONFIG_H263I_DECODER == 1)
REGISTER_DECODER(H263I, h263i); 
#endif

#if (CONFIG_H263P_DECODER == 1)
REGISTER_DECODER(H263P, h263p); 
#endif

#if (CONFIG_H264_DECODER == 1)
REGISTER_DECODER(H264, h264); 
#endif

#if (CONFIG_H264_CRYSTALHD_DECODER == 1)
REGISTER_DECODER(H264_CRYSTALHD, h264_crystalhd); 
#endif

#if (CONFIG_H264_VDA_DECODER == 1)
REGISTER_DECODER(H264_VDA, h264_vda); 
#endif

#if (CONFIG_H264_VDPAU_DECODER == 1)
REGISTER_DECODER(H264_VDPAU, h264_vdpau); 
#endif

#if (CONFIG_HEVC_DECODER == 1)
REGISTER_DECODER(HEVC, hevc); 
#endif

#if (CONFIG_HNM4_VIDEO_DECODER == 1)
REGISTER_DECODER(HNM4_VIDEO, hnm4_video); 
#endif

#if (CONFIG_HUFFYUV_DECODER == 1)
REGISTER_DECODER(HUFFYUV, huffyuv); 
#endif

#if (CONFIG_IDCIN_DECODER == 1)
REGISTER_DECODER(IDCIN, idcin); 
#endif

#if (CONFIG_IFF_BYTERUN1_DECODER == 1)
REGISTER_DECODER(IFF_BYTERUN1, iff_byterun1); 
#endif

#if (CONFIG_IFF_ILBM_DECODER == 1)
REGISTER_DECODER(IFF_ILBM, iff_ilbm); 
#endif

#if (CONFIG_INDEO2_DECODER == 1)
REGISTER_DECODER(INDEO2, indeo2); 
#endif

#if (CONFIG_INDEO3_DECODER == 1)
REGISTER_DECODER(INDEO3, indeo3); 
#endif

#if (CONFIG_INDEO4_DECODER == 1)
REGISTER_DECODER(INDEO4, indeo4); 
#endif

#if (CONFIG_INDEO5_DECODER == 1)
REGISTER_DECODER(INDEO5, indeo5); 
#endif

#if (CONFIG_INTERPLAY_VIDEO_DECODER == 1)
REGISTER_DECODER(INTERPLAY_VIDEO, interplay_video); 
#endif

#if (CONFIG_JPEG2000_DECODER == 1)
REGISTER_DECODER(JPEG2000, jpeg2000); 
#endif

#if (CONFIG_JPEGLS_DECODER == 1)
REGISTER_DECODER(JPEGLS, jpegls); 
#endif

#if (CONFIG_JV_DECODER == 1)
REGISTER_DECODER(JV, jv); 
#endif

#if (CONFIG_KGV1_DECODER == 1)
REGISTER_DECODER(KGV1, kgv1); 
#endif

#if (CONFIG_KMVC_DECODER == 1)
REGISTER_DECODER(KMVC, kmvc); 
#endif

#if (CONFIG_LAGARITH_DECODER == 1)
REGISTER_DECODER(LAGARITH, lagarith); 
#endif

#if (CONFIG_LOCO_DECODER == 1)
REGISTER_DECODER(LOCO, loco); 
#endif

#if (CONFIG_MDEC_DECODER == 1)
REGISTER_DECODER(MDEC, mdec); 
#endif

#if (CONFIG_MIMIC_DECODER == 1)
REGISTER_DECODER(MIMIC, mimic); 
#endif

#if (CONFIG_MJPEG_DECODER == 1)
REGISTER_DECODER(MJPEG, mjpeg); 
#endif

#if (CONFIG_MJPEGB_DECODER == 1)
REGISTER_DECODER(MJPEGB, mjpegb); 
#endif

#if (CONFIG_MMVIDEO_DECODER == 1)
REGISTER_DECODER(MMVIDEO, mmvideo); 
#endif

#if (CONFIG_MOTIONPIXELS_DECODER == 1)
REGISTER_DECODER(MOTIONPIXELS, motionpixels); 
#endif

#if FF_API_XVMC
#  if (CONFIG_MPEG_XVMC_DECODER == 1)
    REGISTER_DECODER(MPEG_XVMC, mpeg_xvmc);
#  endif
#endif /* FF_API_XVMC */

#if (CONFIG_MPEG1VIDEO_DECODER == 1)
REGISTER_DECODER(MPEG1VIDEO, mpeg1video); 
#endif

#if (CONFIG_MPEG2VIDEO_DECODER == 1)
REGISTER_DECODER(MPEG2VIDEO, mpeg2video); 
#endif

#if (CONFIG_MPEG4_DECODER == 1)
REGISTER_DECODER(MPEG4, mpeg4); 
#endif

#if (CONFIG_MPEG4_CRYSTALHD_DECODER == 1)
REGISTER_DECODER(MPEG4_CRYSTALHD, mpeg4_crystalhd); 
#endif

#if (CONFIG_MPEG4_VDPAU_DECODER == 1)
REGISTER_DECODER(MPEG4_VDPAU, mpeg4_vdpau); 
#endif

#if (CONFIG_MPEGVIDEO_DECODER == 1)
REGISTER_DECODER(MPEGVIDEO, mpegvideo); 
#endif

#if (CONFIG_MPEG_VDPAU_DECODER == 1)
REGISTER_DECODER(MPEG_VDPAU, mpeg_vdpau); 
#endif

#if (CONFIG_MPEG1_VDPAU_DECODER == 1)
REGISTER_DECODER(MPEG1_VDPAU, mpeg1_vdpau); 
#endif

#if (CONFIG_MPEG2_CRYSTALHD_DECODER == 1)
REGISTER_DECODER(MPEG2_CRYSTALHD, mpeg2_crystalhd); 
#endif

#if (CONFIG_MSA1_DECODER == 1)
REGISTER_DECODER(MSA1, msa1); 
#endif

#if (CONFIG_MSMPEG4_CRYSTALHD_DECODER == 1)
REGISTER_DECODER(MSMPEG4_CRYSTALHD, msmpeg4_crystalhd); 
#endif

#if (CONFIG_MSMPEG4V1_DECODER == 1)
REGISTER_DECODER(MSMPEG4V1, msmpeg4v1); 
#endif

#if (CONFIG_MSMPEG4V2_DECODER == 1)
REGISTER_DECODER(MSMPEG4V2, msmpeg4v2); 
#endif

#if (CONFIG_MSMPEG4V3_DECODER == 1)
REGISTER_DECODER(MSMPEG4V3, msmpeg4v3); 
#endif

#if (CONFIG_MSRLE_DECODER == 1)
REGISTER_DECODER(MSRLE, msrle); 
#endif

#if (CONFIG_MSS1_DECODER == 1)
REGISTER_DECODER(MSS1, mss1); 
#endif

#if (CONFIG_MSS2_DECODER == 1)
REGISTER_DECODER(MSS2, mss2); 
#endif

#if (CONFIG_MSVIDEO1_DECODER == 1)
REGISTER_DECODER(MSVIDEO1, msvideo1); 
#endif

#if (CONFIG_MSZH_DECODER == 1)
REGISTER_DECODER(MSZH, mszh); 
#endif

#if (CONFIG_MTS2_DECODER == 1)
REGISTER_DECODER(MTS2, mts2); 
#endif

#if (CONFIG_MVC1_DECODER == 1)
REGISTER_DECODER(MVC1, mvc1); 
#endif

#if (CONFIG_MVC2_DECODER == 1)
REGISTER_DECODER(MVC2, mvc2); 
#endif

#if (CONFIG_MXPEG_DECODER == 1)
REGISTER_DECODER(MXPEG, mxpeg); 
#endif

#if (CONFIG_NUV_DECODER == 1)
REGISTER_DECODER(NUV, nuv); 
#endif

#if (CONFIG_PAF_VIDEO_DECODER == 1)
REGISTER_DECODER(PAF_VIDEO, paf_video); 
#endif

#if (CONFIG_PAM_DECODER == 1)
REGISTER_DECODER(PAM, pam); 
#endif

#if (CONFIG_PBM_DECODER == 1)
REGISTER_DECODER(PBM, pbm); 
#endif

#if (CONFIG_PCX_DECODER == 1)
REGISTER_DECODER(PCX, pcx); 
#endif

#if (CONFIG_PGM_DECODER == 1)
REGISTER_DECODER(PGM, pgm); 
#endif

#if (CONFIG_PGMYUV_DECODER == 1)
REGISTER_DECODER(PGMYUV, pgmyuv); 
#endif

#if (CONFIG_PICTOR_DECODER == 1)
REGISTER_DECODER(PICTOR, pictor); 
#endif

#if (CONFIG_PNG_DECODER == 1)
REGISTER_DECODER(PNG, png); 
#endif

#if (CONFIG_PPM_DECODER == 1)
REGISTER_DECODER(PPM, ppm); 
#endif

#if (CONFIG_PRORES_DECODER == 1)
REGISTER_DECODER(PRORES, prores); 
#endif

#if (CONFIG_PRORES_LGPL_DECODER == 1)
REGISTER_DECODER(PRORES_LGPL, prores_lgpl); 
#endif

#if (CONFIG_PTX_DECODER == 1)
REGISTER_DECODER(PTX, ptx); 
#endif

#if (CONFIG_QDRAW_DECODER == 1)
REGISTER_DECODER(QDRAW, qdraw); 
#endif

#if (CONFIG_QPEG_DECODER == 1)
REGISTER_DECODER(QPEG, qpeg); 
#endif

#if (CONFIG_QTRLE_DECODER == 1)
REGISTER_DECODER(QTRLE, qtrle); 
#endif

#if (CONFIG_R10K_DECODER == 1)
REGISTER_DECODER(R10K, r10k); 
#endif

#if (CONFIG_R210_DECODER == 1)
REGISTER_DECODER(R210, r210); 
#endif

#if (CONFIG_RAWVIDEO_DECODER == 1)
REGISTER_DECODER(RAWVIDEO, rawvideo); 
#endif

#if (CONFIG_RL2_DECODER == 1)
REGISTER_DECODER(RL2, rl2); 
#endif

#if (CONFIG_ROQ_DECODER == 1)
REGISTER_DECODER(ROQ, roq); 
#endif

#if (CONFIG_RPZA_DECODER == 1)
REGISTER_DECODER(RPZA, rpza); 
#endif

#if (CONFIG_RV10_DECODER == 1)
REGISTER_DECODER(RV10, rv10); 
#endif

#if (CONFIG_RV20_DECODER == 1)
REGISTER_DECODER(RV20, rv20); 
#endif

#if (CONFIG_RV30_DECODER == 1)
REGISTER_DECODER(RV30, rv30); 
#endif

#if (CONFIG_RV40_DECODER == 1)
REGISTER_DECODER(RV40, rv40); 
#endif

#if (CONFIG_S302M_DECODER == 1)
REGISTER_DECODER(S302M, s302m); 
#endif

#if (CONFIG_SANM_DECODER == 1)
REGISTER_DECODER(SANM, sanm); 
#endif

#if (CONFIG_SGI_DECODER == 1)
REGISTER_DECODER(SGI, sgi); 
#endif

#if (CONFIG_SGIRLE_DECODER == 1)
REGISTER_DECODER(SGIRLE, sgirle); 
#endif

#if (CONFIG_SMACKER_DECODER == 1)
REGISTER_DECODER(SMACKER, smacker); 
#endif

#if (CONFIG_SMC_DECODER == 1)
REGISTER_DECODER(SMC, smc); 
#endif

#if (CONFIG_SMVJPEG_DECODER == 1)
REGISTER_DECODER(SMVJPEG, smvjpeg); 
#endif

#if (CONFIG_SNOW_DECODER == 1)
REGISTER_DECODER(SNOW, snow); 
#endif

#if (CONFIG_SP5X_DECODER == 1)
REGISTER_DECODER(SP5X, sp5x); 
#endif

#if (CONFIG_SUNRAST_DECODER == 1)
REGISTER_DECODER(SUNRAST, sunrast); 
#endif

#if (CONFIG_SVQ1_DECODER == 1)
REGISTER_DECODER(SVQ1, svq1); 
#endif

#if (CONFIG_SVQ3_DECODER == 1)
REGISTER_DECODER(SVQ3, svq3); 
#endif

#if (CONFIG_TARGA_DECODER == 1)
REGISTER_DECODER(TARGA, targa); 
#endif

#if (CONFIG_TARGA_Y216_DECODER == 1)
REGISTER_DECODER(TARGA_Y216, targa_y216); 
#endif

#if (CONFIG_THEORA_DECODER == 1)
REGISTER_DECODER(THEORA, theora); 
#endif

#if (CONFIG_THP_DECODER == 1)
REGISTER_DECODER(THP, thp); 
#endif

#if (CONFIG_TIERTEXSEQVIDEO_DECODER == 1)
REGISTER_DECODER(TIERTEXSEQVIDEO, tiertexseqvideo); 
#endif

#if (CONFIG_TIFF_DECODER == 1)
REGISTER_DECODER(TIFF, tiff); 
#endif

#if (CONFIG_TMV_DECODER == 1)
REGISTER_DECODER(TMV, tmv); 
#endif

#if (CONFIG_TRUEMOTION1_DECODER == 1)
REGISTER_DECODER(TRUEMOTION1, truemotion1); 
#endif

#if (CONFIG_TRUEMOTION2_DECODER == 1)
REGISTER_DECODER(TRUEMOTION2, truemotion2); 
#endif

#if (CONFIG_TSCC_DECODER == 1)
REGISTER_DECODER(TSCC, tscc); 
#endif

#if (CONFIG_TSCC2_DECODER == 1)
REGISTER_DECODER(TSCC2, tscc2); 
#endif

#if (CONFIG_TXD_DECODER == 1)
REGISTER_DECODER(TXD, txd); 
#endif

#if (CONFIG_ULTI_DECODER == 1)
REGISTER_DECODER(ULTI, ulti); 
#endif

#if (CONFIG_UTVIDEO_DECODER == 1)
REGISTER_DECODER(UTVIDEO, utvideo); 
#endif

#if (CONFIG_V210_DECODER == 1)
REGISTER_DECODER(V210, v210); 
#endif

#if (CONFIG_V210X_DECODER == 1)
REGISTER_DECODER(V210X, v210x); 
#endif

#if (CONFIG_V308_DECODER == 1)
REGISTER_DECODER(V308, v308); 
#endif

#if (CONFIG_V408_DECODER == 1)
REGISTER_DECODER(V408, v408); 
#endif

#if (CONFIG_V410_DECODER == 1)
REGISTER_DECODER(V410, v410); 
#endif

#if (CONFIG_VB_DECODER == 1)
REGISTER_DECODER(VB, vb); 
#endif

#if (CONFIG_VBLE_DECODER == 1)
REGISTER_DECODER(VBLE, vble); 
#endif

#if (CONFIG_VC1_DECODER == 1)
REGISTER_DECODER(VC1, vc1); 
#endif

#if (CONFIG_VC1_CRYSTALHD_DECODER == 1)
REGISTER_DECODER(VC1_CRYSTALHD, vc1_crystalhd); 
#endif

#if (CONFIG_VC1_VDPAU_DECODER == 1)
REGISTER_DECODER(VC1_VDPAU, vc1_vdpau); 
#endif

#if (CONFIG_VC1IMAGE_DECODER == 1)
REGISTER_DECODER(VC1IMAGE, vc1image); 
#endif

#if (CONFIG_VCR1_DECODER == 1)
REGISTER_DECODER(VCR1, vcr1); 
#endif

#if (CONFIG_VMDVIDEO_DECODER == 1)
REGISTER_DECODER(VMDVIDEO, vmdvideo); 
#endif

#if (CONFIG_VMNC_DECODER == 1)
REGISTER_DECODER(VMNC, vmnc); 
#endif

#if (CONFIG_VP3_DECODER == 1)
REGISTER_DECODER(VP3, vp3); 
#endif

#if (CONFIG_VP5_DECODER == 1)
REGISTER_DECODER(VP5, vp5); 
#endif

#if (CONFIG_VP6_DECODER == 1)
REGISTER_DECODER(VP6, vp6); 
#endif

#if (CONFIG_VP6A_DECODER == 1)
REGISTER_DECODER(VP6A, vp6a); 
#endif

#if (CONFIG_VP6F_DECODER == 1)
REGISTER_DECODER(VP6F, vp6f); 
#endif

#if (CONFIG_VP7_DECODER == 1)
REGISTER_DECODER(VP7, vp7); 
#endif

#if (CONFIG_VP8_DECODER == 1)
REGISTER_DECODER(VP8, vp8); 
#endif

#if (CONFIG_VP9_DECODER == 1)
REGISTER_DECODER(VP9, vp9); 
#endif

#if (CONFIG_VQA_DECODER == 1)
REGISTER_DECODER(VQA, vqa); 
#endif

#if (CONFIG_WEBP_DECODER == 1)
REGISTER_DECODER(WEBP, webp); 
#endif

#if (CONFIG_WMV1_DECODER == 1)
REGISTER_DECODER(WMV1, wmv1); 
#endif

#if (CONFIG_WMV2_DECODER == 1)
REGISTER_DECODER(WMV2, wmv2); 
#endif

#if (CONFIG_WMV3_DECODER == 1)
REGISTER_DECODER(WMV3, wmv3); 
#endif

#if (CONFIG_WMV3_CRYSTALHD_DECODER == 1)
REGISTER_DECODER(WMV3_CRYSTALHD, wmv3_crystalhd); 
#endif

#if (CONFIG_WMV3_VDPAU_DECODER == 1)
REGISTER_DECODER(WMV3_VDPAU, wmv3_vdpau); 
#endif

#if (CONFIG_WMV3IMAGE_DECODER == 1)
REGISTER_DECODER(WMV3IMAGE, wmv3image); 
#endif

#if (CONFIG_WNV1_DECODER == 1)
REGISTER_DECODER(WNV1, wnv1); 
#endif

#if (CONFIG_XAN_WC3_DECODER == 1)
REGISTER_DECODER(XAN_WC3, xan_wc3); 
#endif

#if (CONFIG_XAN_WC4_DECODER == 1)
REGISTER_DECODER(XAN_WC4, xan_wc4); 
#endif

#if (CONFIG_XBM_DECODER == 1)
REGISTER_DECODER(XBM, xbm); 
#endif

#if (CONFIG_XFACE_DECODER == 1)
REGISTER_DECODER(XFACE, xface); 
#endif

#if (CONFIG_XL_DECODER == 1)
REGISTER_DECODER(XL, xl); 
#endif

#if (CONFIG_XWD_DECODER == 1)
REGISTER_DECODER(XWD, xwd); 
#endif

#if (CONFIG_Y41P_DECODER == 1)
REGISTER_DECODER(Y41P, y41p); 
#endif

#if (CONFIG_YOP_DECODER == 1)
REGISTER_DECODER(YOP, yop); 
#endif

#if (CONFIG_YUV4_DECODER == 1)
REGISTER_DECODER(YUV4, yuv4); 
#endif

#if (CONFIG_ZERO12V_DECODER == 1)
REGISTER_DECODER(ZERO12V, zero12v); 
#endif

#if (CONFIG_ZEROCODEC_DECODER == 1)
REGISTER_DECODER(ZEROCODEC, zerocodec); 
#endif

#if (CONFIG_ZLIB_DECODER == 1)
REGISTER_DECODER(ZLIB, zlib); 
#endif

#if (CONFIG_ZMBV_DECODER == 1)
REGISTER_DECODER(ZMBV, zmbv); 
#endif




#if (CONFIG_AAC_DECODER == 1)
REGISTER_DECODER(AAC, aac); 
#endif

#if (CONFIG_AAC_LATM_DECODER == 1)
REGISTER_DECODER(AAC_LATM, aac_latm); 
#endif

#if (CONFIG_AC3_DECODER == 1)
REGISTER_DECODER(AC3, ac3); 
#endif

#if (CONFIG_AC3_FIXED_DECODER == 1)
REGISTER_DECODER(AC3_FIXED, ac3_fixed); 
#endif

#if (CONFIG_ALAC_DECODER == 1)
REGISTER_DECODER(ALAC, alac); 
#endif

#if (CONFIG_ALS_DECODER == 1)
REGISTER_DECODER(ALS, als); 
#endif

#if (CONFIG_AMRNB_DECODER == 1)
REGISTER_DECODER(AMRNB, amrnb); 
#endif

#if (CONFIG_AMRWB_DECODER == 1)
REGISTER_DECODER(AMRWB, amrwb); 
#endif

#if (CONFIG_APE_DECODER == 1)
REGISTER_DECODER(APE, ape); 
#endif

#if (CONFIG_ATRAC1_DECODER == 1)
REGISTER_DECODER(ATRAC1, atrac1); 
#endif

#if (CONFIG_ATRAC3_DECODER == 1)
REGISTER_DECODER(ATRAC3, atrac3); 
#endif

#if (CONFIG_ATRAC3P_DECODER == 1)
REGISTER_DECODER(ATRAC3P, atrac3p); 
#endif

#if (CONFIG_BINKAUDIO_DCT_DECODER == 1)
REGISTER_DECODER(BINKAUDIO_DCT, binkaudio_dct); 
#endif

#if (CONFIG_BINKAUDIO_RDFT_DECODER == 1)
REGISTER_DECODER(BINKAUDIO_RDFT, binkaudio_rdft); 
#endif

#if (CONFIG_BMV_AUDIO_DECODER == 1)
REGISTER_DECODER(BMV_AUDIO, bmv_audio); 
#endif

#if (CONFIG_COOK_DECODER == 1)
REGISTER_DECODER(COOK, cook); 
#endif

#if (CONFIG_DCA_DECODER == 1)
REGISTER_DECODER(DCA, dca); 
#endif

#if (CONFIG_DSD_LSBF_DECODER == 1)
REGISTER_DECODER(DSD_LSBF, dsd_lsbf); 
#endif

#if (CONFIG_DSD_MSBF_DECODER == 1)
REGISTER_DECODER(DSD_MSBF, dsd_msbf); 
#endif

#if (CONFIG_DSD_LSBF_PLANAR_DECODER == 1)
REGISTER_DECODER(DSD_LSBF_PLANAR, dsd_lsbf_planar); 
#endif

#if (CONFIG_DSD_MSBF_PLANAR_DECODER == 1)
REGISTER_DECODER(DSD_MSBF_PLANAR, dsd_msbf_planar); 
#endif

#if (CONFIG_DSICINAUDIO_DECODER == 1)
REGISTER_DECODER(DSICINAUDIO, dsicinaudio); 
#endif

#if (CONFIG_EAC3_DECODER == 1)
REGISTER_DECODER(EAC3, eac3); 
#endif

#if (CONFIG_EVRC_DECODER == 1)
REGISTER_DECODER(EVRC, evrc); 
#endif

#if (CONFIG_FFWAVESYNTH_DECODER == 1)
REGISTER_DECODER(FFWAVESYNTH, ffwavesynth); 
#endif

#if (CONFIG_FLAC_DECODER == 1)
REGISTER_DECODER(FLAC, flac); 
#endif

#if (CONFIG_G723_1_DECODER == 1)
REGISTER_DECODER(G723_1, g723_1); 
#endif

#if (CONFIG_G729_DECODER == 1)
REGISTER_DECODER(G729, g729); 
#endif

#if (CONFIG_GSM_DECODER == 1)
REGISTER_DECODER(GSM, gsm); 
#endif

#if (CONFIG_GSM_MS_DECODER == 1)
REGISTER_DECODER(GSM_MS, gsm_ms); 
#endif

#if (CONFIG_IAC_DECODER == 1)
REGISTER_DECODER(IAC, iac); 
#endif

#if (CONFIG_IMC_DECODER == 1)
REGISTER_DECODER(IMC, imc); 
#endif

#if (CONFIG_MACE3_DECODER == 1)
REGISTER_DECODER(MACE3, mace3); 
#endif

#if (CONFIG_MACE6_DECODER == 1)
REGISTER_DECODER(MACE6, mace6); 
#endif

#if (CONFIG_METASOUND_DECODER == 1)
REGISTER_DECODER(METASOUND, metasound); 
#endif

#if (CONFIG_MLP_DECODER == 1)
REGISTER_DECODER(MLP, mlp); 
#endif

#if (CONFIG_MP1_DECODER == 1)
REGISTER_DECODER(MP1, mp1); 
#endif

#if (CONFIG_MP1FLOAT_DECODER == 1)
REGISTER_DECODER(MP1FLOAT, mp1float); 
#endif

#if (CONFIG_MP2_DECODER == 1)
REGISTER_DECODER(MP2, mp2); 
#endif

#if (CONFIG_MP2FLOAT_DECODER == 1)
REGISTER_DECODER(MP2FLOAT, mp2float); 
#endif

#if (CONFIG_MP3_DECODER == 1)
REGISTER_DECODER(MP3, mp3); 
#endif

#if (CONFIG_MP3FLOAT_DECODER == 1)
REGISTER_DECODER(MP3FLOAT, mp3float); 
#endif

#if (CONFIG_MP3ADU_DECODER == 1)
REGISTER_DECODER(MP3ADU, mp3adu); 
#endif

#if (CONFIG_MP3ADUFLOAT_DECODER == 1)
REGISTER_DECODER(MP3ADUFLOAT, mp3adufloat); 
#endif

#if (CONFIG_MP3ON4_DECODER == 1)
REGISTER_DECODER(MP3ON4, mp3on4); 
#endif

#if (CONFIG_MP3ON4FLOAT_DECODER == 1)
REGISTER_DECODER(MP3ON4FLOAT, mp3on4float); 
#endif

#if (CONFIG_MPC7_DECODER == 1)
REGISTER_DECODER(MPC7, mpc7); 
#endif

#if (CONFIG_MPC8_DECODER == 1)
REGISTER_DECODER(MPC8, mpc8); 
#endif

#if (CONFIG_NELLYMOSER_DECODER == 1)
REGISTER_DECODER(NELLYMOSER, nellymoser); 
#endif

#if (CONFIG_ON2AVC_DECODER == 1)
REGISTER_DECODER(ON2AVC, on2avc); 
#endif

#if (CONFIG_OPUS_DECODER == 1)
REGISTER_DECODER(OPUS, opus); 
#endif

#if (CONFIG_PAF_AUDIO_DECODER == 1)
REGISTER_DECODER(PAF_AUDIO, paf_audio); 
#endif

#if (CONFIG_QCELP_DECODER == 1)
REGISTER_DECODER(QCELP, qcelp); 
#endif

#if (CONFIG_QDM2_DECODER == 1)
REGISTER_DECODER(QDM2, qdm2); 
#endif

#if (CONFIG_RA_144_DECODER == 1)
REGISTER_DECODER(RA_144, ra_144); 
#endif

#if (CONFIG_RA_288_DECODER == 1)
REGISTER_DECODER(RA_288, ra_288); 
#endif

#if (CONFIG_RALF_DECODER == 1)
REGISTER_DECODER(RALF, ralf); 
#endif

#if (CONFIG_SHORTEN_DECODER == 1)
REGISTER_DECODER(SHORTEN, shorten); 
#endif

#if (CONFIG_SIPR_DECODER == 1)
REGISTER_DECODER(SIPR, sipr); 
#endif

#if (CONFIG_SMACKAUD_DECODER == 1)
REGISTER_DECODER(SMACKAUD, smackaud); 
#endif

#if (CONFIG_SONIC_DECODER == 1)
REGISTER_DECODER(SONIC, sonic); 
#endif

#if (CONFIG_TAK_DECODER == 1)
REGISTER_DECODER(TAK, tak); 
#endif

#if (CONFIG_TRUEHD_DECODER == 1)
REGISTER_DECODER(TRUEHD, truehd); 
#endif

#if (CONFIG_TRUESPEECH_DECODER == 1)
REGISTER_DECODER(TRUESPEECH, truespeech); 
#endif

#if (CONFIG_TTA_DECODER == 1)
REGISTER_DECODER(TTA, tta); 
#endif

#if (CONFIG_TWINVQ_DECODER == 1)
REGISTER_DECODER(TWINVQ, twinvq); 
#endif

#if (CONFIG_VMDAUDIO_DECODER == 1)
REGISTER_DECODER(VMDAUDIO, vmdaudio); 
#endif

#if (CONFIG_VORBIS_DECODER == 1)
REGISTER_DECODER(VORBIS, vorbis); 
#endif

#if (CONFIG_WAVPACK_DECODER == 1)
REGISTER_DECODER(WAVPACK, wavpack); 
#endif

#if (CONFIG_WMALOSSLESS_DECODER == 1)
REGISTER_DECODER(WMALOSSLESS, wmalossless); 
#endif

#if (CONFIG_WMAPRO_DECODER == 1)
REGISTER_DECODER(WMAPRO, wmapro); 
#endif

#if (CONFIG_WMAV1_DECODER == 1)
REGISTER_DECODER(WMAV1, wmav1); 
#endif

#if (CONFIG_WMAV2_DECODER == 1)
REGISTER_DECODER(WMAV2, wmav2); 
#endif

#if (CONFIG_WMAVOICE_DECODER == 1)
REGISTER_DECODER(WMAVOICE, wmavoice); 
#endif

#if (CONFIG_WS_SND1_DECODER == 1)
REGISTER_DECODER(WS_SND1, ws_snd1); 
#endif



#if (CONFIG_PCM_ALAW_DECODER == 1)
REGISTER_DECODER(PCM_ALAW, pcm_alaw); 
#endif

#if (CONFIG_PCM_BLURAY_DECODER == 1)
REGISTER_DECODER(PCM_BLURAY, pcm_bluray); 
#endif

#if (CONFIG_PCM_DVD_DECODER == 1)
REGISTER_DECODER(PCM_DVD, pcm_dvd); 
#endif

#if (CONFIG_PCM_F32BE_DECODER == 1)
REGISTER_DECODER(PCM_F32BE, pcm_f32be); 
#endif

#if (CONFIG_PCM_F32LE_DECODER == 1)
REGISTER_DECODER(PCM_F32LE, pcm_f32le); 
#endif

#if (CONFIG_PCM_F64BE_DECODER == 1)
REGISTER_DECODER(PCM_F64BE, pcm_f64be); 
#endif

#if (CONFIG_PCM_F64LE_DECODER == 1)
REGISTER_DECODER(PCM_F64LE, pcm_f64le); 
#endif

#if (CONFIG_PCM_LXF_DECODER == 1)
REGISTER_DECODER(PCM_LXF, pcm_lxf); 
#endif

#if (CONFIG_PCM_MULAW_DECODER == 1)
REGISTER_DECODER(PCM_MULAW, pcm_mulaw); 
#endif

#if (CONFIG_PCM_S8_DECODER == 1)
REGISTER_DECODER(PCM_S8, pcm_s8); 
#endif

#if (CONFIG_PCM_S8_PLANAR_DECODER == 1)
REGISTER_DECODER(PCM_S8_PLANAR, pcm_s8_planar); 
#endif

#if (CONFIG_PCM_S16BE_DECODER == 1)
REGISTER_DECODER(PCM_S16BE, pcm_s16be); 
#endif

#if (CONFIG_PCM_S16BE_PLANAR_DECODER == 1)
REGISTER_DECODER(PCM_S16BE_PLANAR, pcm_s16be_planar); 
#endif

#if (CONFIG_PCM_S16LE_DECODER == 1)
REGISTER_DECODER(PCM_S16LE, pcm_s16le); 
#endif

#if (CONFIG_PCM_S16LE_PLANAR_DECODER == 1)
REGISTER_DECODER(PCM_S16LE_PLANAR, pcm_s16le_planar); 
#endif

#if (CONFIG_PCM_S24BE_DECODER == 1)
REGISTER_DECODER(PCM_S24BE, pcm_s24be); 
#endif

#if (CONFIG_PCM_S24DAUD_DECODER == 1)
REGISTER_DECODER(PCM_S24DAUD, pcm_s24daud); 
#endif

#if (CONFIG_PCM_S24LE_DECODER == 1)
REGISTER_DECODER(PCM_S24LE, pcm_s24le); 
#endif

#if (CONFIG_PCM_S24LE_PLANAR_DECODER == 1)
REGISTER_DECODER(PCM_S24LE_PLANAR, pcm_s24le_planar); 
#endif

#if (CONFIG_PCM_S32BE_DECODER == 1)
REGISTER_DECODER(PCM_S32BE, pcm_s32be); 
#endif

#if (CONFIG_PCM_S32LE_DECODER == 1)
REGISTER_DECODER(PCM_S32LE, pcm_s32le); 
#endif

#if (CONFIG_PCM_S32LE_PLANAR_DECODER == 1)
REGISTER_DECODER(PCM_S32LE_PLANAR, pcm_s32le_planar); 
#endif

#if (CONFIG_PCM_U8_DECODER == 1)
REGISTER_DECODER(PCM_U8, pcm_u8); 
#endif

#if (CONFIG_PCM_U16BE_DECODER == 1)
REGISTER_DECODER(PCM_U16BE, pcm_u16be); 
#endif

#if (CONFIG_PCM_U16LE_DECODER == 1)
REGISTER_DECODER(PCM_U16LE, pcm_u16le); 
#endif

#if (CONFIG_PCM_U24BE_DECODER == 1)
REGISTER_DECODER(PCM_U24BE, pcm_u24be); 
#endif

#if (CONFIG_PCM_U24LE_DECODER == 1)
REGISTER_DECODER(PCM_U24LE, pcm_u24le); 
#endif

#if (CONFIG_PCM_U32BE_DECODER == 1)
REGISTER_DECODER(PCM_U32BE, pcm_u32be); 
#endif

#if (CONFIG_PCM_U32LE_DECODER == 1)
REGISTER_DECODER(PCM_U32LE, pcm_u32le); 
#endif

#if (CONFIG_PCM_ZORK_DECODER == 1)
REGISTER_DECODER(PCM_ZORK, pcm_zork); 
#endif



#if (CONFIG_INTERPLAY_DPCM_DECODER == 1)
REGISTER_DECODER(INTERPLAY_DPCM, interplay_dpcm); 
#endif

#if (CONFIG_ROQ_DPCM_DECODER == 1)
REGISTER_DECODER(ROQ_DPCM, roq_dpcm); 
#endif

#if (CONFIG_SOL_DPCM_DECODER == 1)
REGISTER_DECODER(SOL_DPCM, sol_dpcm); 
#endif

#if (CONFIG_XAN_DPCM_DECODER == 1)
REGISTER_DECODER(XAN_DPCM, xan_dpcm); 
#endif



#if (CONFIG_ADPCM_4XM_DECODER == 1)
REGISTER_DECODER(ADPCM_4XM, adpcm_4xm); 
#endif

#if (CONFIG_ADPCM_ADX_DECODER == 1)
REGISTER_DECODER(ADPCM_ADX, adpcm_adx); 
#endif

#if (CONFIG_ADPCM_AFC_DECODER == 1)
REGISTER_DECODER(ADPCM_AFC, adpcm_afc); 
#endif

#if (CONFIG_ADPCM_CT_DECODER == 1)
REGISTER_DECODER(ADPCM_CT, adpcm_ct); 
#endif

#if (CONFIG_ADPCM_DTK_DECODER == 1)
REGISTER_DECODER(ADPCM_DTK, adpcm_dtk); 
#endif

#if (CONFIG_ADPCM_EA_DECODER == 1)
REGISTER_DECODER(ADPCM_EA, adpcm_ea); 
#endif

#if (CONFIG_ADPCM_EA_MAXIS_XA_DECODER == 1)
REGISTER_DECODER(ADPCM_EA_MAXIS_XA, adpcm_ea_maxis_xa); 
#endif

#if (CONFIG_ADPCM_EA_R1_DECODER == 1)
REGISTER_DECODER(ADPCM_EA_R1, adpcm_ea_r1); 
#endif

#if (CONFIG_ADPCM_EA_R2_DECODER == 1)
REGISTER_DECODER(ADPCM_EA_R2, adpcm_ea_r2); 
#endif

#if (CONFIG_ADPCM_EA_R3_DECODER == 1)
REGISTER_DECODER(ADPCM_EA_R3, adpcm_ea_r3); 
#endif

#if (CONFIG_ADPCM_EA_XAS_DECODER == 1)
REGISTER_DECODER(ADPCM_EA_XAS, adpcm_ea_xas); 
#endif

#if (CONFIG_ADPCM_G722_DECODER == 1)
REGISTER_DECODER(ADPCM_G722, adpcm_g722); 
#endif

#if (CONFIG_ADPCM_G726_DECODER == 1)
REGISTER_DECODER(ADPCM_G726, adpcm_g726); 
#endif

#if (CONFIG_ADPCM_G726LE_DECODER == 1)
REGISTER_DECODER(ADPCM_G726LE, adpcm_g726le); 
#endif

#if (CONFIG_ADPCM_IMA_AMV_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_AMV, adpcm_ima_amv); 
#endif

#if (CONFIG_ADPCM_IMA_APC_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_APC, adpcm_ima_apc); 
#endif

#if (CONFIG_ADPCM_IMA_DK3_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_DK3, adpcm_ima_dk3); 
#endif

#if (CONFIG_ADPCM_IMA_DK4_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_DK4, adpcm_ima_dk4); 
#endif

#if (CONFIG_ADPCM_IMA_EA_EACS_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_EA_EACS, adpcm_ima_ea_eacs); 
#endif

#if (CONFIG_ADPCM_IMA_EA_SEAD_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_EA_SEAD, adpcm_ima_ea_sead); 
#endif

#if (CONFIG_ADPCM_IMA_ISS_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_ISS, adpcm_ima_iss); 
#endif

#if (CONFIG_ADPCM_IMA_OKI_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_OKI, adpcm_ima_oki); 
#endif

#if (CONFIG_ADPCM_IMA_QT_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_QT, adpcm_ima_qt); 
#endif

#if (CONFIG_ADPCM_IMA_RAD_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_RAD, adpcm_ima_rad); 
#endif

#if (CONFIG_ADPCM_IMA_SMJPEG_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_SMJPEG, adpcm_ima_smjpeg); 
#endif

#if (CONFIG_ADPCM_IMA_WAV_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_WAV, adpcm_ima_wav); 
#endif

#if (CONFIG_ADPCM_IMA_WS_DECODER == 1)
REGISTER_DECODER(ADPCM_IMA_WS, adpcm_ima_ws); 
#endif

#if (CONFIG_ADPCM_MS_DECODER == 1)
REGISTER_DECODER(ADPCM_MS, adpcm_ms); 
#endif

#if (CONFIG_ADPCM_SBPRO_2_DECODER == 1)
REGISTER_DECODER(ADPCM_SBPRO_2, adpcm_sbpro_2); 
#endif

#if (CONFIG_ADPCM_SBPRO_3_DECODER == 1)
REGISTER_DECODER(ADPCM_SBPRO_3, adpcm_sbpro_3); 
#endif

#if (CONFIG_ADPCM_SBPRO_4_DECODER == 1)
REGISTER_DECODER(ADPCM_SBPRO_4, adpcm_sbpro_4); 
#endif

#if (CONFIG_ADPCM_SWF_DECODER == 1)
REGISTER_DECODER(ADPCM_SWF, adpcm_swf); 
#endif

#if (CONFIG_ADPCM_THP_DECODER == 1)
REGISTER_DECODER(ADPCM_THP, adpcm_thp); 
#endif

#if (CONFIG_ADPCM_VIMA_DECODER == 1)
REGISTER_DECODER(ADPCM_VIMA, adpcm_vima); 
#endif

#if (CONFIG_ADPCM_XA_DECODER == 1)
REGISTER_DECODER(ADPCM_XA, adpcm_xa); 
#endif

#if (CONFIG_ADPCM_YAMAHA_DECODER == 1)
REGISTER_DECODER(ADPCM_YAMAHA, adpcm_yamaha); 
#endif

#if (CONFIG_VIMA_DECODER == 1)
REGISTER_DECODER(VIMA, vima); 
#endif



#if (CONFIG_SSA_DECODER == 1)
REGISTER_DECODER(SSA, ssa); 
#endif

#if (CONFIG_ASS_DECODER == 1)
REGISTER_DECODER(ASS, ass); 
#endif

#if (CONFIG_DVBSUB_DECODER == 1)
REGISTER_DECODER(DVBSUB, dvbsub); 
#endif

#if (CONFIG_DVDSUB_DECODER == 1)
REGISTER_DECODER(DVDSUB, dvdsub); 
#endif

#if (CONFIG_JACOSUB_DECODER == 1)
REGISTER_DECODER(JACOSUB, jacosub); 
#endif

#if (CONFIG_MICRODVD_DECODER == 1)
REGISTER_DECODER(MICRODVD, microdvd); 
#endif

#if (CONFIG_MOVTEXT_DECODER == 1)
REGISTER_DECODER(MOVTEXT, movtext); 
#endif

#if (CONFIG_MPL2_DECODER == 1)
REGISTER_DECODER(MPL2, mpl2); 
#endif

#if (CONFIG_PGSSUB_DECODER == 1)
REGISTER_DECODER(PGSSUB, pgssub); 
#endif

#if (CONFIG_PJS_DECODER == 1)
REGISTER_DECODER(PJS, pjs); 
#endif

#if (CONFIG_REALTEXT_DECODER == 1)
REGISTER_DECODER(REALTEXT, realtext); 
#endif

#if (CONFIG_SAMI_DECODER == 1)
REGISTER_DECODER(SAMI, sami); 
#endif

#if (CONFIG_SRT_DECODER == 1)
REGISTER_DECODER(SRT, srt); 
#endif

#if (CONFIG_SUBRIP_DECODER == 1)
REGISTER_DECODER(SUBRIP, subrip); 
#endif

#if (CONFIG_SUBVIEWER_DECODER == 1)
REGISTER_DECODER(SUBVIEWER, subviewer); 
#endif

#if (CONFIG_SUBVIEWER1_DECODER == 1)
REGISTER_DECODER(SUBVIEWER1, subviewer1); 
#endif

#if (CONFIG_TEXT_DECODER == 1)
REGISTER_DECODER(TEXT, text); 
#endif

#if (CONFIG_VPLAYER_DECODER == 1)
REGISTER_DECODER(VPLAYER, vplayer); 
#endif

#if (CONFIG_WEBVTT_DECODER == 1)
REGISTER_DECODER(WEBVTT, webvtt); 
#endif

#if (CONFIG_XSUB_DECODER == 1)
REGISTER_DECODER(XSUB, xsub); 
#endif



#if (CONFIG_LIBCELT_DECODER == 1)
REGISTER_DECODER(LIBCELT, libcelt); 
#endif

#if (CONFIG_LIBFDK_AAC_DECODER == 1)
REGISTER_DECODER(LIBFDK_AAC, libfdk_aac); 
#endif

#if (CONFIG_LIBGSM_DECODER == 1)
REGISTER_DECODER(LIBGSM, libgsm); 
#endif

#if (CONFIG_LIBGSM_MS_DECODER == 1)
REGISTER_DECODER(LIBGSM_MS, libgsm_ms); 
#endif

#if (CONFIG_LIBILBC_DECODER == 1)
REGISTER_DECODER(LIBILBC, libilbc); 
#endif

#if (CONFIG_LIBOPENCORE_AMRNB_DECODER == 1)
REGISTER_DECODER(LIBOPENCORE_AMRNB, libopencore_amrnb); 
#endif

#if (CONFIG_LIBOPENCORE_AMRWB_DECODER == 1)
REGISTER_DECODER(LIBOPENCORE_AMRWB, libopencore_amrwb); 
#endif

#if (CONFIG_LIBOPENJPEG_DECODER == 1)
REGISTER_DECODER(LIBOPENJPEG, libopenjpeg); 
#endif

#if (CONFIG_LIBOPUS_DECODER == 1)
REGISTER_DECODER(LIBOPUS, libopus); 
#endif

#if (CONFIG_LIBSCHROEDINGER_DECODER == 1)
REGISTER_DECODER(LIBSCHROEDINGER, libschroedinger); 
#endif

#if (CONFIG_LIBSPEEX_DECODER == 1)
REGISTER_DECODER(LIBSPEEX, libspeex); 
#endif

#if (CONFIG_LIBSTAGEFRIGHT_H264_DECODER == 1)
REGISTER_DECODER(LIBSTAGEFRIGHT_H264, libstagefright_h264); 
#endif

#if (CONFIG_LIBUTVIDEO_DECODER == 1)
REGISTER_DECODER(LIBUTVIDEO, libutvideo); 
#endif

#if (CONFIG_LIBVORBIS_DECODER == 1)
REGISTER_DECODER(LIBVORBIS, libvorbis); 
#endif

#if (CONFIG_LIBVPX_VP8_DECODER == 1)
REGISTER_DECODER(LIBVPX_VP8, libvpx_vp8); 
#endif

#if (CONFIG_LIBVPX_VP9_DECODER == 1)
REGISTER_DECODER(LIBVPX_VP9, libvpx_vp9); 
#endif

#if (CONFIG_LIBZVBI_TELETEXT_DECODER == 1)
REGISTER_DECODER(LIBZVBI_TELETEXT, libzvbi_teletext); 
#endif



#if (CONFIG_BINTEXT_DECODER == 1)
REGISTER_DECODER(BINTEXT, bintext); 
#endif

#if (CONFIG_XBIN_DECODER == 1)
REGISTER_DECODER(XBIN, xbin); 
#endif

#if (CONFIG_IDF_DECODER == 1)
REGISTER_DECODER(IDF, idf); 
#endif



#if (CONFIG_AAC_PARSER == 1)
REGISTER_PARSER(AAC, aac); 
#endif

#if (CONFIG_AAC_LATM_PARSER == 1)
REGISTER_PARSER(AAC_LATM, aac_latm); 
#endif

#if (CONFIG_AC3_PARSER == 1)
REGISTER_PARSER(AC3, ac3); 
#endif

#if (CONFIG_ADX_PARSER == 1)
REGISTER_PARSER(ADX, adx); 
#endif

#if (CONFIG_BMP_PARSER == 1)
REGISTER_PARSER(BMP, bmp); 
#endif

#if (CONFIG_CAVSVIDEO_PARSER == 1)
REGISTER_PARSER(CAVSVIDEO, cavsvideo); 
#endif

#if (CONFIG_COOK_PARSER == 1)
REGISTER_PARSER(COOK, cook); 
#endif

#if (CONFIG_DCA_PARSER == 1)
REGISTER_PARSER(DCA, dca); 
#endif

#if (CONFIG_DIRAC_PARSER == 1)
REGISTER_PARSER(DIRAC, dirac); 
#endif

#if (CONFIG_DNXHD_PARSER == 1)
REGISTER_PARSER(DNXHD, dnxhd); 
#endif

#if (CONFIG_DPX_PARSER == 1)
REGISTER_PARSER(DPX, dpx); 
#endif

#if (CONFIG_DVBSUB_PARSER == 1)
REGISTER_PARSER(DVBSUB, dvbsub); 
#endif

#if (CONFIG_DVDSUB_PARSER == 1)
REGISTER_PARSER(DVDSUB, dvdsub); 
#endif

#if (CONFIG_DVD_NAV_PARSER == 1)
REGISTER_PARSER(DVD_NAV, dvd_nav); 
#endif

#if (CONFIG_FLAC_PARSER == 1)
REGISTER_PARSER(FLAC, flac); 
#endif

#if (CONFIG_GSM_PARSER == 1)
REGISTER_PARSER(GSM, gsm); 
#endif

#if (CONFIG_H261_PARSER == 1)
REGISTER_PARSER(H261, h261); 
#endif

#if (CONFIG_H263_PARSER == 1)
REGISTER_PARSER(H263, h263); 
#endif

#if (CONFIG_H264_PARSER == 1)
REGISTER_PARSER(H264, h264); 
#endif

#if (CONFIG_HEVC_PARSER == 1)
REGISTER_PARSER(HEVC, hevc); 
#endif

#if (CONFIG_MJPEG_PARSER == 1)
REGISTER_PARSER(MJPEG, mjpeg); 
#endif

#if (CONFIG_MLP_PARSER == 1)
REGISTER_PARSER(MLP, mlp); 
#endif

#if (CONFIG_MPEG4VIDEO_PARSER == 1)
REGISTER_PARSER(MPEG4VIDEO, mpeg4video); 
#endif

#if (CONFIG_MPEGAUDIO_PARSER == 1)
REGISTER_PARSER(MPEGAUDIO, mpegaudio); 
#endif

#if (CONFIG_MPEGVIDEO_PARSER == 1)
REGISTER_PARSER(MPEGVIDEO, mpegvideo); 
#endif

#if (CONFIG_OPUS_PARSER == 1)
REGISTER_PARSER(OPUS, opus); 
#endif

#if (CONFIG_PNG_PARSER == 1)
REGISTER_PARSER(PNG, png); 
#endif

#if (CONFIG_PNM_PARSER == 1)
REGISTER_PARSER(PNM, pnm); 
#endif

#if (CONFIG_RV30_PARSER == 1)
REGISTER_PARSER(RV30, rv30); 
#endif

#if (CONFIG_RV40_PARSER == 1)
REGISTER_PARSER(RV40, rv40); 
#endif

#if (CONFIG_TAK_PARSER == 1)
REGISTER_PARSER(TAK, tak); 
#endif

#if (CONFIG_VC1_PARSER == 1)
REGISTER_PARSER(VC1, vc1); 
#endif

#if (CONFIG_VORBIS_PARSER == 1)
REGISTER_PARSER(VORBIS, vorbis); 
#endif

#if (CONFIG_VP3_PARSER == 1)
REGISTER_PARSER(VP3, vp3); 
#endif

#if (CONFIG_VP8_PARSER == 1)
REGISTER_PARSER(VP8, vp8); 
#endif

#if (CONFIG_VP9_PARSER == 1)
REGISTER_PARSER(VP9, vp9); 
#endif



#if (CONFIG_AAC_ADTSTOASC_BSF == 1)
REGISTER_BSF(AAC_ADTSTOASC, aac_adtstoasc); 
#endif

#if (CONFIG_CHOMP_BSF == 1)
REGISTER_BSF(CHOMP, chomp); 
#endif

#if (CONFIG_DUMP_EXTRADATA_BSF == 1)
REGISTER_BSF(DUMP_EXTRADATA, dump_extradata); 
#endif

#if (CONFIG_H264_MP4TOANNEXB_BSF == 1)
REGISTER_BSF(H264_MP4TOANNEXB, h264_mp4toannexb); 
#endif

#if (CONFIG_IMX_DUMP_HEADER_BSF == 1)
REGISTER_BSF(IMX_DUMP_HEADER, imx_dump_header); 
#endif

#if (CONFIG_MJPEG2JPEG_BSF == 1)
REGISTER_BSF(MJPEG2JPEG, mjpeg2jpeg); 
#endif

#if (CONFIG_MJPEGA_DUMP_HEADER_BSF == 1)
REGISTER_BSF(MJPEGA_DUMP_HEADER, mjpega_dump_header); 
#endif

#if (CONFIG_MP3_HEADER_DECOMPRESS_BSF == 1)
REGISTER_BSF(MP3_HEADER_DECOMPRESS, mp3_header_decompress); 
#endif

#if (CONFIG_MOV2TEXTSUB_BSF == 1)
REGISTER_BSF(MOV2TEXTSUB, mov2textsub); 
#endif

#if (CONFIG_NOISE_BSF == 1)
REGISTER_BSF(NOISE, noise); 
#endif

#if (CONFIG_REMOVE_EXTRADATA_BSF == 1)
REGISTER_BSF(REMOVE_EXTRADATA, remove_extradata); 
#endif

#if (CONFIG_TEXT2MOVSUB_BSF == 1)
REGISTER_BSF(TEXT2MOVSUB, text2movsub); 
#endif
#else
    /* hardware accelerators */
    REGISTER_HWACCEL(H263_VAAPI,        h263_vaapi);
    REGISTER_HWACCEL(H263_VDPAU,        h263_vdpau);
    REGISTER_HWACCEL(H264_DXVA2,        h264_dxva2);
    REGISTER_HWACCEL(H264_VAAPI,        h264_vaapi);
    REGISTER_HWACCEL(H264_VDA,          h264_vda);
    REGISTER_HWACCEL(H264_VDA_OLD,      h264_vda_old);
    REGISTER_HWACCEL(H264_VDPAU,        h264_vdpau);
    REGISTER_HWACCEL(MPEG1_XVMC,        mpeg1_xvmc);
    REGISTER_HWACCEL(MPEG1_VDPAU,       mpeg1_vdpau);
    REGISTER_HWACCEL(MPEG2_XVMC,        mpeg2_xvmc);
    REGISTER_HWACCEL(MPEG2_DXVA2,       mpeg2_dxva2);
    REGISTER_HWACCEL(MPEG2_VAAPI,       mpeg2_vaapi);
    REGISTER_HWACCEL(MPEG2_VDPAU,       mpeg2_vdpau);
    REGISTER_HWACCEL(MPEG4_VAAPI,       mpeg4_vaapi);
    REGISTER_HWACCEL(MPEG4_VDPAU,       mpeg4_vdpau);
    REGISTER_HWACCEL(VC1_DXVA2,         vc1_dxva2);
    REGISTER_HWACCEL(VC1_VAAPI,         vc1_vaapi);
    REGISTER_HWACCEL(VC1_VDPAU,         vc1_vdpau);
    REGISTER_HWACCEL(WMV3_DXVA2,        wmv3_dxva2);
    REGISTER_HWACCEL(WMV3_VAAPI,        wmv3_vaapi);
    REGISTER_HWACCEL(WMV3_VDPAU,        wmv3_vdpau);

    /* video codecs */
    REGISTER_ENCODER(A64MULTI,          a64multi);
    REGISTER_ENCODER(A64MULTI5,         a64multi5);
    REGISTER_DECODER(AASC,              aasc);
    REGISTER_DECODER(AIC,               aic);
    REGISTER_ENCDEC (ALIAS_PIX,         alias_pix);
    REGISTER_ENCDEC (AMV,               amv);
    REGISTER_DECODER(ANM,               anm);
    REGISTER_DECODER(ANSI,              ansi);
    REGISTER_ENCDEC (ASV1,              asv1);
    REGISTER_ENCDEC (ASV2,              asv2);
    REGISTER_DECODER(AURA,              aura);
    REGISTER_DECODER(AURA2,             aura2);
    REGISTER_ENCDEC (AVRP,              avrp);
    REGISTER_DECODER(AVRN,              avrn);
    REGISTER_DECODER(AVS,               avs);
    REGISTER_ENCDEC (AVUI,              avui);
    REGISTER_ENCDEC (AYUV,              ayuv);
    REGISTER_DECODER(BETHSOFTVID,       bethsoftvid);
    REGISTER_DECODER(BFI,               bfi);
    REGISTER_DECODER(BINK,              bink);
    REGISTER_ENCDEC (BMP,               bmp);
    REGISTER_DECODER(BMV_VIDEO,         bmv_video);
    REGISTER_DECODER(BRENDER_PIX,       brender_pix);
    REGISTER_DECODER(C93,               c93);
    REGISTER_DECODER(CAVS,              cavs);
    REGISTER_DECODER(CDGRAPHICS,        cdgraphics);
    REGISTER_DECODER(CDXL,              cdxl);
    REGISTER_ENCDEC (CINEPAK,           cinepak);
    REGISTER_ENCDEC (CLJR,              cljr);
    REGISTER_DECODER(CLLC,              cllc);
    REGISTER_ENCDEC (COMFORTNOISE,      comfortnoise);
    REGISTER_DECODER(CPIA,              cpia);
    REGISTER_DECODER(CSCD,              cscd);
    REGISTER_DECODER(CYUV,              cyuv);
    REGISTER_DECODER(DFA,               dfa);
    REGISTER_DECODER(DIRAC,             dirac);
    REGISTER_ENCDEC (DNXHD,             dnxhd);
    REGISTER_ENCDEC (DPX,               dpx);
    REGISTER_DECODER(DSICINVIDEO,       dsicinvideo);
    REGISTER_ENCDEC (DVVIDEO,           dvvideo);
    REGISTER_DECODER(DXA,               dxa);
    REGISTER_DECODER(DXTORY,            dxtory);
    REGISTER_DECODER(EACMV,             eacmv);
    REGISTER_DECODER(EAMAD,             eamad);
    REGISTER_DECODER(EATGQ,             eatgq);
    REGISTER_DECODER(EATGV,             eatgv);
    REGISTER_DECODER(EATQI,             eatqi);
    REGISTER_DECODER(EIGHTBPS,          eightbps);
    REGISTER_DECODER(EIGHTSVX_EXP,      eightsvx_exp);
    REGISTER_DECODER(EIGHTSVX_FIB,      eightsvx_fib);
    REGISTER_DECODER(ESCAPE124,         escape124);
    REGISTER_DECODER(ESCAPE130,         escape130);
    REGISTER_DECODER(EXR,               exr);
    REGISTER_ENCDEC (FFV1,              ffv1);
    REGISTER_ENCDEC (FFVHUFF,           ffvhuff);
    REGISTER_DECODER(FIC,               fic);
    REGISTER_ENCDEC (FLASHSV,           flashsv);
    REGISTER_ENCDEC (FLASHSV2,          flashsv2);
    REGISTER_DECODER(FLIC,              flic);
    REGISTER_ENCDEC (FLV,               flv);
    REGISTER_DECODER(FOURXM,            fourxm);
    REGISTER_DECODER(FRAPS,             fraps);
    REGISTER_DECODER(FRWU,              frwu);
    REGISTER_DECODER(G2M,               g2m);
    REGISTER_ENCDEC (GIF,               gif);
    REGISTER_ENCDEC (H261,              h261);
    REGISTER_ENCDEC (H263,              h263);
    REGISTER_DECODER(H263I,             h263i);
    REGISTER_ENCDEC (H263P,             h263p);
    REGISTER_DECODER(H264,              h264);
    REGISTER_DECODER(H264_CRYSTALHD,    h264_crystalhd);
    REGISTER_DECODER(H264_VDA,          h264_vda);
    REGISTER_DECODER(H264_VDPAU,        h264_vdpau);
    REGISTER_DECODER(HEVC,              hevc);
    REGISTER_DECODER(HNM4_VIDEO,        hnm4_video);
    REGISTER_ENCDEC (HUFFYUV,           huffyuv);
    REGISTER_DECODER(IDCIN,             idcin);
    REGISTER_DECODER(IFF_BYTERUN1,      iff_byterun1);
    REGISTER_DECODER(IFF_ILBM,          iff_ilbm);
    REGISTER_DECODER(INDEO2,            indeo2);
    REGISTER_DECODER(INDEO3,            indeo3);
    REGISTER_DECODER(INDEO4,            indeo4);
    REGISTER_DECODER(INDEO5,            indeo5);
    REGISTER_DECODER(INTERPLAY_VIDEO,   interplay_video);
    REGISTER_ENCDEC (JPEG2000,          jpeg2000);
    REGISTER_ENCDEC (JPEGLS,            jpegls);
    REGISTER_DECODER(JV,                jv);
    REGISTER_DECODER(KGV1,              kgv1);
    REGISTER_DECODER(KMVC,              kmvc);
    REGISTER_DECODER(LAGARITH,          lagarith);
    REGISTER_ENCODER(LJPEG,             ljpeg);
    REGISTER_DECODER(LOCO,              loco);
    REGISTER_DECODER(MDEC,              mdec);
    REGISTER_DECODER(MIMIC,             mimic);
    REGISTER_ENCDEC (MJPEG,             mjpeg);
    REGISTER_DECODER(MJPEGB,            mjpegb);
    REGISTER_DECODER(MMVIDEO,           mmvideo);
    REGISTER_DECODER(MOTIONPIXELS,      motionpixels);
#if FF_API_XVMC
    REGISTER_DECODER(MPEG_XVMC,         mpeg_xvmc);
#endif /* FF_API_XVMC */
    REGISTER_ENCDEC (MPEG1VIDEO,        mpeg1video);
    REGISTER_ENCDEC (MPEG2VIDEO,        mpeg2video);
    REGISTER_ENCDEC (MPEG4,             mpeg4);
    REGISTER_DECODER(MPEG4_CRYSTALHD,   mpeg4_crystalhd);
    REGISTER_DECODER(MPEG4_VDPAU,       mpeg4_vdpau);
    REGISTER_DECODER(MPEGVIDEO,         mpegvideo);
    REGISTER_DECODER(MPEG_VDPAU,        mpeg_vdpau);
    REGISTER_DECODER(MPEG1_VDPAU,       mpeg1_vdpau);
    REGISTER_DECODER(MPEG2_CRYSTALHD,   mpeg2_crystalhd);
    REGISTER_DECODER(MSA1,              msa1);
    REGISTER_DECODER(MSMPEG4_CRYSTALHD, msmpeg4_crystalhd);
    REGISTER_DECODER(MSMPEG4V1,         msmpeg4v1);
    REGISTER_ENCDEC (MSMPEG4V2,         msmpeg4v2);
    REGISTER_ENCDEC (MSMPEG4V3,         msmpeg4v3);
    REGISTER_DECODER(MSRLE,             msrle);
    REGISTER_DECODER(MSS1,              mss1);
    REGISTER_DECODER(MSS2,              mss2);
    REGISTER_ENCDEC (MSVIDEO1,          msvideo1);
    REGISTER_DECODER(MSZH,              mszh);
    REGISTER_DECODER(MTS2,              mts2);
    REGISTER_DECODER(MVC1,              mvc1);
    REGISTER_DECODER(MVC2,              mvc2);
    REGISTER_DECODER(MXPEG,             mxpeg);
    REGISTER_DECODER(NUV,               nuv);
    REGISTER_DECODER(PAF_VIDEO,         paf_video);
    REGISTER_ENCDEC (PAM,               pam);
    REGISTER_ENCDEC (PBM,               pbm);
    REGISTER_ENCDEC (PCX,               pcx);
    REGISTER_ENCDEC (PGM,               pgm);
    REGISTER_ENCDEC (PGMYUV,            pgmyuv);
    REGISTER_DECODER(PICTOR,            pictor);
    REGISTER_ENCDEC (PNG,               png);
    REGISTER_ENCDEC (PPM,               ppm);
    REGISTER_ENCDEC (PRORES,            prores);
    REGISTER_ENCODER(PRORES_AW,         prores_aw);
    REGISTER_ENCODER(PRORES_KS,         prores_ks);
    REGISTER_DECODER(PRORES_LGPL,       prores_lgpl);
    REGISTER_DECODER(PTX,               ptx);
    REGISTER_DECODER(QDRAW,             qdraw);
    REGISTER_DECODER(QPEG,              qpeg);
    REGISTER_ENCDEC (QTRLE,             qtrle);
    REGISTER_ENCDEC (R10K,              r10k);
    REGISTER_ENCDEC (R210,              r210);
    REGISTER_ENCDEC (RAWVIDEO,          rawvideo);
    REGISTER_DECODER(RL2,               rl2);
    REGISTER_ENCDEC (ROQ,               roq);
    REGISTER_DECODER(RPZA,              rpza);
    REGISTER_ENCDEC (RV10,              rv10);
    REGISTER_ENCDEC (RV20,              rv20);
    REGISTER_DECODER(RV30,              rv30);
    REGISTER_DECODER(RV40,              rv40);
    REGISTER_ENCDEC (S302M,             s302m);
    REGISTER_DECODER(SANM,              sanm);
    REGISTER_ENCDEC (SGI,               sgi);
    REGISTER_DECODER(SGIRLE,            sgirle);
    REGISTER_DECODER(SMACKER,           smacker);
    REGISTER_DECODER(SMC,               smc);
    REGISTER_DECODER(SMVJPEG,           smvjpeg);
    REGISTER_ENCDEC (SNOW,              snow);
    REGISTER_DECODER(SP5X,              sp5x);
    REGISTER_ENCDEC (SUNRAST,           sunrast);
    REGISTER_ENCDEC (SVQ1,              svq1);
    REGISTER_DECODER(SVQ3,              svq3);
    REGISTER_ENCDEC (TARGA,             targa);
    REGISTER_DECODER(TARGA_Y216,        targa_y216);
    REGISTER_DECODER(THEORA,            theora);
    REGISTER_DECODER(THP,               thp);
    REGISTER_DECODER(TIERTEXSEQVIDEO,   tiertexseqvideo);
    REGISTER_ENCDEC (TIFF,              tiff);
    REGISTER_DECODER(TMV,               tmv);
    REGISTER_DECODER(TRUEMOTION1,       truemotion1);
    REGISTER_DECODER(TRUEMOTION2,       truemotion2);
    REGISTER_DECODER(TSCC,              tscc);
    REGISTER_DECODER(TSCC2,             tscc2);
    REGISTER_DECODER(TXD,               txd);
    REGISTER_DECODER(ULTI,              ulti);
    REGISTER_ENCDEC (UTVIDEO,           utvideo);
    REGISTER_ENCDEC (V210,              v210);
    REGISTER_DECODER(V210X,             v210x);
    REGISTER_ENCDEC (V308,              v308);
    REGISTER_ENCDEC (V408,              v408);
    REGISTER_ENCDEC (V410,              v410);
    REGISTER_DECODER(VB,                vb);
    REGISTER_DECODER(VBLE,              vble);
    REGISTER_DECODER(VC1,               vc1);
    REGISTER_DECODER(VC1_CRYSTALHD,     vc1_crystalhd);
    REGISTER_DECODER(VC1_VDPAU,         vc1_vdpau);
    REGISTER_DECODER(VC1IMAGE,          vc1image);
    REGISTER_DECODER(VCR1,              vcr1);
    REGISTER_DECODER(VMDVIDEO,          vmdvideo);
    REGISTER_DECODER(VMNC,              vmnc);
    REGISTER_DECODER(VP3,               vp3);
    REGISTER_DECODER(VP5,               vp5);
    REGISTER_DECODER(VP6,               vp6);
    REGISTER_DECODER(VP6A,              vp6a);
    REGISTER_DECODER(VP6F,              vp6f);
    REGISTER_DECODER(VP7,               vp7);
    REGISTER_DECODER(VP8,               vp8);
    REGISTER_DECODER(VP9,               vp9);
    REGISTER_DECODER(VQA,               vqa);
    REGISTER_DECODER(WEBP,              webp);
    REGISTER_ENCDEC (WMV1,              wmv1);
    REGISTER_ENCDEC (WMV2,              wmv2);
    REGISTER_DECODER(WMV3,              wmv3);
    REGISTER_DECODER(WMV3_CRYSTALHD,    wmv3_crystalhd);
    REGISTER_DECODER(WMV3_VDPAU,        wmv3_vdpau);
    REGISTER_DECODER(WMV3IMAGE,         wmv3image);
    REGISTER_DECODER(WNV1,              wnv1);
    REGISTER_DECODER(XAN_WC3,           xan_wc3);
    REGISTER_DECODER(XAN_WC4,           xan_wc4);
    REGISTER_ENCDEC (XBM,               xbm);
    REGISTER_ENCDEC (XFACE,             xface);
    REGISTER_DECODER(XL,                xl);
    REGISTER_ENCDEC (XWD,               xwd);
    REGISTER_ENCDEC (Y41P,              y41p);
    REGISTER_DECODER(YOP,               yop);
    REGISTER_ENCDEC (YUV4,              yuv4);
    REGISTER_DECODER(ZERO12V,           zero12v);
    REGISTER_DECODER(ZEROCODEC,         zerocodec);
    REGISTER_ENCDEC (ZLIB,              zlib);
    REGISTER_ENCDEC (ZMBV,              zmbv);

    /* audio codecs */
    REGISTER_ENCDEC (AAC,               aac);
    REGISTER_DECODER(AAC_LATM,          aac_latm);
    REGISTER_ENCDEC (AC3,               ac3);
    REGISTER_ENCDEC (AC3_FIXED,         ac3_fixed);
    REGISTER_ENCDEC (ALAC,              alac);
    REGISTER_DECODER(ALS,               als);
    REGISTER_DECODER(AMRNB,             amrnb);
    REGISTER_DECODER(AMRWB,             amrwb);
    REGISTER_DECODER(APE,               ape);
    REGISTER_DECODER(ATRAC1,            atrac1);
    REGISTER_DECODER(ATRAC3,            atrac3);
    REGISTER_DECODER(ATRAC3P,           atrac3p);
    REGISTER_DECODER(BINKAUDIO_DCT,     binkaudio_dct);
    REGISTER_DECODER(BINKAUDIO_RDFT,    binkaudio_rdft);
    REGISTER_DECODER(BMV_AUDIO,         bmv_audio);
    REGISTER_DECODER(COOK,              cook);
    REGISTER_ENCDEC (DCA,               dca);
    REGISTER_DECODER(DSD_LSBF,          dsd_lsbf);
    REGISTER_DECODER(DSD_MSBF,          dsd_msbf);
    REGISTER_DECODER(DSD_LSBF_PLANAR,   dsd_lsbf_planar);
    REGISTER_DECODER(DSD_MSBF_PLANAR,   dsd_msbf_planar);
    REGISTER_DECODER(DSICINAUDIO,       dsicinaudio);
    REGISTER_ENCDEC (EAC3,              eac3);
    REGISTER_DECODER(EVRC,              evrc);
    REGISTER_DECODER(FFWAVESYNTH,       ffwavesynth);
    REGISTER_ENCDEC (FLAC,              flac);
    REGISTER_ENCDEC (G723_1,            g723_1);
    REGISTER_DECODER(G729,              g729);
    REGISTER_DECODER(GSM,               gsm);
    REGISTER_DECODER(GSM_MS,            gsm_ms);
    REGISTER_DECODER(IAC,               iac);
    REGISTER_DECODER(IMC,               imc);
    REGISTER_DECODER(MACE3,             mace3);
    REGISTER_DECODER(MACE6,             mace6);
    REGISTER_DECODER(METASOUND,         metasound);
    REGISTER_DECODER(MLP,               mlp);
    REGISTER_DECODER(MP1,               mp1);
    REGISTER_DECODER(MP1FLOAT,          mp1float);
    REGISTER_ENCDEC (MP2,               mp2);
    REGISTER_DECODER(MP2FLOAT,          mp2float);
    REGISTER_ENCODER(MP2FIXED,          mp2fixed);
    REGISTER_DECODER(MP3,               mp3);
    REGISTER_DECODER(MP3FLOAT,          mp3float);
    REGISTER_DECODER(MP3ADU,            mp3adu);
    REGISTER_DECODER(MP3ADUFLOAT,       mp3adufloat);
    REGISTER_DECODER(MP3ON4,            mp3on4);
    REGISTER_DECODER(MP3ON4FLOAT,       mp3on4float);
    REGISTER_DECODER(MPC7,              mpc7);
    REGISTER_DECODER(MPC8,              mpc8);
    REGISTER_ENCDEC (NELLYMOSER,        nellymoser);
    REGISTER_DECODER(ON2AVC,            on2avc);
    REGISTER_DECODER(OPUS,              opus);
    REGISTER_DECODER(PAF_AUDIO,         paf_audio);
    REGISTER_DECODER(QCELP,             qcelp);
    REGISTER_DECODER(QDM2,              qdm2);
    REGISTER_ENCDEC (RA_144,            ra_144);
    REGISTER_DECODER(RA_288,            ra_288);
    REGISTER_DECODER(RALF,              ralf);
    REGISTER_DECODER(SHORTEN,           shorten);
    REGISTER_DECODER(SIPR,              sipr);
    REGISTER_DECODER(SMACKAUD,          smackaud);
    REGISTER_ENCDEC (SONIC,             sonic);
    REGISTER_ENCODER(SONIC_LS,          sonic_ls);
    REGISTER_DECODER(TAK,               tak);
    REGISTER_DECODER(TRUEHD,            truehd);
    REGISTER_DECODER(TRUESPEECH,        truespeech);
    REGISTER_ENCDEC (TTA,               tta);
    REGISTER_DECODER(TWINVQ,            twinvq);
    REGISTER_DECODER(VMDAUDIO,          vmdaudio);
    REGISTER_ENCDEC (VORBIS,            vorbis);
    REGISTER_ENCDEC (WAVPACK,           wavpack);
    REGISTER_DECODER(WMALOSSLESS,       wmalossless);
    REGISTER_DECODER(WMAPRO,            wmapro);
    REGISTER_ENCDEC (WMAV1,             wmav1);
    REGISTER_ENCDEC (WMAV2,             wmav2);
    REGISTER_DECODER(WMAVOICE,          wmavoice);
    REGISTER_DECODER(WS_SND1,           ws_snd1);

    /* PCM codecs */
    REGISTER_ENCDEC (PCM_ALAW,          pcm_alaw);
    REGISTER_DECODER(PCM_BLURAY,        pcm_bluray);
    REGISTER_DECODER(PCM_DVD,           pcm_dvd);
    REGISTER_ENCDEC (PCM_F32BE,         pcm_f32be);
    REGISTER_ENCDEC (PCM_F32LE,         pcm_f32le);
    REGISTER_ENCDEC (PCM_F64BE,         pcm_f64be);
    REGISTER_ENCDEC (PCM_F64LE,         pcm_f64le);
    REGISTER_DECODER(PCM_LXF,           pcm_lxf);
    REGISTER_ENCDEC (PCM_MULAW,         pcm_mulaw);
    REGISTER_ENCDEC (PCM_S8,            pcm_s8);
    REGISTER_ENCDEC (PCM_S8_PLANAR,     pcm_s8_planar);
    REGISTER_ENCDEC (PCM_S16BE,         pcm_s16be);
    REGISTER_ENCDEC (PCM_S16BE_PLANAR,  pcm_s16be_planar);
    REGISTER_ENCDEC (PCM_S16LE,         pcm_s16le);
    REGISTER_ENCDEC (PCM_S16LE_PLANAR,  pcm_s16le_planar);
    REGISTER_ENCDEC (PCM_S24BE,         pcm_s24be);
    REGISTER_ENCDEC (PCM_S24DAUD,       pcm_s24daud);
    REGISTER_ENCDEC (PCM_S24LE,         pcm_s24le);
    REGISTER_ENCDEC (PCM_S24LE_PLANAR,  pcm_s24le_planar);
    REGISTER_ENCDEC (PCM_S32BE,         pcm_s32be);
    REGISTER_ENCDEC (PCM_S32LE,         pcm_s32le);
    REGISTER_ENCDEC (PCM_S32LE_PLANAR,  pcm_s32le_planar);
    REGISTER_ENCDEC (PCM_U8,            pcm_u8);
    REGISTER_ENCDEC (PCM_U16BE,         pcm_u16be);
    REGISTER_ENCDEC (PCM_U16LE,         pcm_u16le);
    REGISTER_ENCDEC (PCM_U24BE,         pcm_u24be);
    REGISTER_ENCDEC (PCM_U24LE,         pcm_u24le);
    REGISTER_ENCDEC (PCM_U32BE,         pcm_u32be);
    REGISTER_ENCDEC (PCM_U32LE,         pcm_u32le);
    REGISTER_DECODER(PCM_ZORK,          pcm_zork);

    /* DPCM codecs */
    REGISTER_DECODER(INTERPLAY_DPCM,    interplay_dpcm);
    REGISTER_ENCDEC (ROQ_DPCM,          roq_dpcm);
    REGISTER_DECODER(SOL_DPCM,          sol_dpcm);
    REGISTER_DECODER(XAN_DPCM,          xan_dpcm);

    /* ADPCM codecs */
    REGISTER_DECODER(ADPCM_4XM,         adpcm_4xm);
    REGISTER_ENCDEC (ADPCM_ADX,         adpcm_adx);
    REGISTER_DECODER(ADPCM_AFC,         adpcm_afc);
    REGISTER_DECODER(ADPCM_CT,          adpcm_ct);
    REGISTER_DECODER(ADPCM_DTK,         adpcm_dtk);
    REGISTER_DECODER(ADPCM_EA,          adpcm_ea);
    REGISTER_DECODER(ADPCM_EA_MAXIS_XA, adpcm_ea_maxis_xa);
    REGISTER_DECODER(ADPCM_EA_R1,       adpcm_ea_r1);
    REGISTER_DECODER(ADPCM_EA_R2,       adpcm_ea_r2);
    REGISTER_DECODER(ADPCM_EA_R3,       adpcm_ea_r3);
    REGISTER_DECODER(ADPCM_EA_XAS,      adpcm_ea_xas);
    REGISTER_ENCDEC (ADPCM_G722,        adpcm_g722);
    REGISTER_ENCDEC (ADPCM_G726,        adpcm_g726);
    REGISTER_DECODER(ADPCM_G726LE,      adpcm_g726le);
    REGISTER_DECODER(ADPCM_IMA_AMV,     adpcm_ima_amv);
    REGISTER_DECODER(ADPCM_IMA_APC,     adpcm_ima_apc);
    REGISTER_DECODER(ADPCM_IMA_DK3,     adpcm_ima_dk3);
    REGISTER_DECODER(ADPCM_IMA_DK4,     adpcm_ima_dk4);
    REGISTER_DECODER(ADPCM_IMA_EA_EACS, adpcm_ima_ea_eacs);
    REGISTER_DECODER(ADPCM_IMA_EA_SEAD, adpcm_ima_ea_sead);
    REGISTER_DECODER(ADPCM_IMA_ISS,     adpcm_ima_iss);
    REGISTER_DECODER(ADPCM_IMA_OKI,     adpcm_ima_oki);
    REGISTER_ENCDEC (ADPCM_IMA_QT,      adpcm_ima_qt);
    REGISTER_DECODER(ADPCM_IMA_RAD,     adpcm_ima_rad);
    REGISTER_DECODER(ADPCM_IMA_SMJPEG,  adpcm_ima_smjpeg);
    REGISTER_ENCDEC (ADPCM_IMA_WAV,     adpcm_ima_wav);
    REGISTER_DECODER(ADPCM_IMA_WS,      adpcm_ima_ws);
    REGISTER_ENCDEC (ADPCM_MS,          adpcm_ms);
    REGISTER_DECODER(ADPCM_SBPRO_2,     adpcm_sbpro_2);
    REGISTER_DECODER(ADPCM_SBPRO_3,     adpcm_sbpro_3);
    REGISTER_DECODER(ADPCM_SBPRO_4,     adpcm_sbpro_4);
    REGISTER_ENCDEC (ADPCM_SWF,         adpcm_swf);
    REGISTER_DECODER(ADPCM_THP,         adpcm_thp);
    REGISTER_DECODER(ADPCM_VIMA,        adpcm_vima);
    REGISTER_DECODER(ADPCM_XA,          adpcm_xa);
    REGISTER_ENCDEC (ADPCM_YAMAHA,      adpcm_yamaha);
    REGISTER_DECODER(VIMA,              vima);

    /* subtitles */
    REGISTER_ENCDEC (SSA,               ssa);
    REGISTER_ENCDEC (ASS,               ass);
    REGISTER_ENCDEC (DVBSUB,            dvbsub);
    REGISTER_ENCDEC (DVDSUB,            dvdsub);
    REGISTER_DECODER(JACOSUB,           jacosub);
    REGISTER_DECODER(MICRODVD,          microdvd);
    REGISTER_ENCDEC (MOVTEXT,           movtext);
    REGISTER_DECODER(MPL2,              mpl2);
    REGISTER_DECODER(PGSSUB,            pgssub);
    REGISTER_DECODER(PJS,               pjs);
    REGISTER_DECODER(REALTEXT,          realtext);
    REGISTER_DECODER(SAMI,              sami);
    REGISTER_ENCDEC (SRT,               srt);
    REGISTER_ENCDEC (SUBRIP,            subrip);
    REGISTER_DECODER(SUBVIEWER,         subviewer);
    REGISTER_DECODER(SUBVIEWER1,        subviewer1);
    REGISTER_DECODER(TEXT,              text);
    REGISTER_DECODER(VPLAYER,           vplayer);
    REGISTER_ENCDEC (WEBVTT,            webvtt);
    REGISTER_ENCDEC (XSUB,              xsub);

    /* external libraries */
    REGISTER_DECODER(LIBCELT,           libcelt);
    REGISTER_ENCODER(LIBFAAC,           libfaac);
    REGISTER_ENCDEC (LIBFDK_AAC,        libfdk_aac);
    REGISTER_ENCDEC (LIBGSM,            libgsm);
    REGISTER_ENCDEC (LIBGSM_MS,         libgsm_ms);
    REGISTER_ENCDEC (LIBILBC,           libilbc);
    REGISTER_ENCODER(LIBMP3LAME,        libmp3lame);
    REGISTER_ENCDEC (LIBOPENCORE_AMRNB, libopencore_amrnb);
    REGISTER_DECODER(LIBOPENCORE_AMRWB, libopencore_amrwb);
    REGISTER_ENCDEC (LIBOPENJPEG,       libopenjpeg);
    REGISTER_ENCDEC (LIBOPUS,           libopus);
    REGISTER_ENCDEC (LIBSCHROEDINGER,   libschroedinger);
    REGISTER_ENCODER(LIBSHINE,          libshine);
    REGISTER_ENCDEC (LIBSPEEX,          libspeex);
    REGISTER_DECODER(LIBSTAGEFRIGHT_H264, libstagefright_h264);
    REGISTER_ENCODER(LIBTHEORA,         libtheora);
    REGISTER_ENCODER(LIBTWOLAME,        libtwolame);
    REGISTER_ENCDEC (LIBUTVIDEO,        libutvideo);
    REGISTER_ENCODER(LIBVO_AACENC,      libvo_aacenc);
    REGISTER_ENCODER(LIBVO_AMRWBENC,    libvo_amrwbenc);
    REGISTER_ENCDEC (LIBVORBIS,         libvorbis);
    REGISTER_ENCDEC (LIBVPX_VP8,        libvpx_vp8);
    REGISTER_ENCDEC (LIBVPX_VP9,        libvpx_vp9);
    REGISTER_ENCODER(LIBWAVPACK,        libwavpack);
    REGISTER_ENCODER(LIBWEBP,           libwebp);
    REGISTER_ENCODER(LIBX264,           libx264);
    REGISTER_ENCODER(LIBX264RGB,        libx264rgb);
    REGISTER_ENCODER(LIBX265,           libx265);
    REGISTER_ENCODER(LIBXAVS,           libxavs);
    REGISTER_ENCODER(LIBXVID,           libxvid);
    REGISTER_DECODER(LIBZVBI_TELETEXT,  libzvbi_teletext);
    REGISTER_ENCODER(LIBAACPLUS,        libaacplus);

    /* text */
    REGISTER_DECODER(BINTEXT,           bintext);
    REGISTER_DECODER(XBIN,              xbin);
    REGISTER_DECODER(IDF,               idf);

    /* parsers */
    REGISTER_PARSER(AAC,                aac);
    REGISTER_PARSER(AAC_LATM,           aac_latm);
    REGISTER_PARSER(AC3,                ac3);
    REGISTER_PARSER(ADX,                adx);
    REGISTER_PARSER(BMP,                bmp);
    REGISTER_PARSER(CAVSVIDEO,          cavsvideo);
    REGISTER_PARSER(COOK,               cook);
    REGISTER_PARSER(DCA,                dca);
    REGISTER_PARSER(DIRAC,              dirac);
    REGISTER_PARSER(DNXHD,              dnxhd);
    REGISTER_PARSER(DPX,                dpx);
    REGISTER_PARSER(DVBSUB,             dvbsub);
    REGISTER_PARSER(DVDSUB,             dvdsub);
    REGISTER_PARSER(DVD_NAV,            dvd_nav);
    REGISTER_PARSER(FLAC,               flac);
    REGISTER_PARSER(GSM,                gsm);
    REGISTER_PARSER(H261,               h261);
    REGISTER_PARSER(H263,               h263);
    REGISTER_PARSER(H264,               h264);
    REGISTER_PARSER(HEVC,               hevc);
    REGISTER_PARSER(MJPEG,              mjpeg);
    REGISTER_PARSER(MLP,                mlp);
    REGISTER_PARSER(MPEG4VIDEO,         mpeg4video);
    REGISTER_PARSER(MPEGAUDIO,          mpegaudio);
    REGISTER_PARSER(MPEGVIDEO,          mpegvideo);
    REGISTER_PARSER(OPUS,               opus);
    REGISTER_PARSER(PNG,                png);
    REGISTER_PARSER(PNM,                pnm);
    REGISTER_PARSER(RV30,               rv30);
    REGISTER_PARSER(RV40,               rv40);
    REGISTER_PARSER(TAK,                tak);
    REGISTER_PARSER(VC1,                vc1);
    REGISTER_PARSER(VORBIS,             vorbis);
    REGISTER_PARSER(VP3,                vp3);
    REGISTER_PARSER(VP8,                vp8);
    REGISTER_PARSER(VP9,                vp9);

    /* bitstream filters */
    REGISTER_BSF(AAC_ADTSTOASC,         aac_adtstoasc);
    REGISTER_BSF(CHOMP,                 chomp);
    REGISTER_BSF(DUMP_EXTRADATA,        dump_extradata);
    REGISTER_BSF(H264_MP4TOANNEXB,      h264_mp4toannexb);
    REGISTER_BSF(IMX_DUMP_HEADER,       imx_dump_header);
    REGISTER_BSF(MJPEG2JPEG,            mjpeg2jpeg);
    REGISTER_BSF(MJPEGA_DUMP_HEADER,    mjpega_dump_header);
    REGISTER_BSF(MP3_HEADER_DECOMPRESS, mp3_header_decompress);
    REGISTER_BSF(MOV2TEXTSUB,           mov2textsub);
    REGISTER_BSF(NOISE,                 noise);
    REGISTER_BSF(REMOVE_EXTRADATA,      remove_extradata);
    REGISTER_BSF(TEXT2MOVSUB,           text2movsub);
#endif
}
