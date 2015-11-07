/*
 * Common code for the RTP depacketization of MPEG-1/2 formats.
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

#include "libavutil/attributes.h"
#include "libavutil/intreadwrite.h"
#include "rtpdec_formats.h"

static av_cold int mpeg_init(AVFormatContext *ctx, int st_index, PayloadContext *data)
{
    if (st_index < 0)
        return 0;
    ctx->streams[st_index]->need_parsing = AVSTREAM_PARSE_FULL;
    return 0;
}

static int mpeg_parse_packet(AVFormatContext *ctx, PayloadContext *data,
                             AVStream *st, AVPacket *pkt, uint32_t *timestamp,
                             const uint8_t *buf, int len, uint16_t seq,
                             int flags)
{
    unsigned int h;
    if (len <= 4)
        return AVERROR_INVALIDDATA;
    h    = AV_RB32(buf);
    buf += 4;
    len -= 4;
    if (st->codec->codec_type == AVMEDIA_TYPE_VIDEO && h & (1 << 26)) {
        /* MPEG-2 */
        if (len <= 4)
            return AVERROR_INVALIDDATA;
        buf += 4;
        len -= 4;
    }
    if (av_new_packet(pkt, len) < 0)
        return AVERROR(ENOMEM);
    memcpy(pkt->data, buf, len);
    pkt->stream_index = st->index;
    return 0;
}

RTPDynamicProtocolHandler ff_mpeg_audio_dynamic_handler = {
#ifdef IDE_COMPILE
    { 0 }, AVMEDIA_TYPE_AUDIO,
    AV_CODEC_ID_MP3,
    14,
    mpeg_init,
    0, 0, 0, mpeg_parse_packet,
#else
	.codec_type        = AVMEDIA_TYPE_AUDIO,
    .codec_id          = AV_CODEC_ID_MP3,
    .init              = mpeg_init,
    .parse_packet      = mpeg_parse_packet,
    .static_payload_id = 14,
#endif
};

RTPDynamicProtocolHandler ff_mpeg_video_dynamic_handler = {
#ifdef IDE_COMPILE
    { 0 }, AVMEDIA_TYPE_VIDEO,
    AV_CODEC_ID_MPEG2VIDEO,
    32,
    mpeg_init,
    0, 0, 0, mpeg_parse_packet,
#else
	.codec_type        = AVMEDIA_TYPE_VIDEO,
    .codec_id          = AV_CODEC_ID_MPEG2VIDEO,
    .init              = mpeg_init,
    .parse_packet      = mpeg_parse_packet,
    .static_payload_id = 32,
#endif
};
