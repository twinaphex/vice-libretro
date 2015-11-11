/*
 * vsyncarch.c - End-of-frame handling for Unix
 *
 * Written by
 *  Dag Lem <resid@nimrod.no>
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


#include "vice.h"

#include "kbdbuf.h"
#include "ui.h"
#include "uistatusbar.h"
#include "vsyncapi.h"
#include "videoarch.h"

#include "libretro-core.h"

#ifdef __X64SC__
//XS:0   YS:16 XI:0 YI:0 W:384 H:272 XSC64
#define XS 0
#define YS 16
#else
//XS:104 YS:16 XI:0 YI:0 W:384 H:272 X64
#define XS 104
#define YS 16
#endif

extern struct video_canvas_s *RCANVAS;

extern int vice_statusbar;

#include <time.h>

/* SDL_Delay & GetTicks have 1ms resolution, while VICE needs 1us */
#define VICE_SDL_TICKS_SCALE 1000
/* hook to ui event dispatcher */
static void_hook_t ui_dispatch_hook;

/* ------------------------------------------------------------------------- */

/* Number of timer units per second. */
signed long vsyncarch_frequency(void)
{
    /* Microseconds resolution. */
    return  1000 * VICE_SDL_TICKS_SCALE;
}

/* Get time in timer units. */
unsigned long vsyncarch_gettime(void)
{

 return GetTicks() * (unsigned long)VICE_SDL_TICKS_SCALE;
}

void vsyncarch_init(void)
{
    (void)vsync_set_event_dispatcher(ui_dispatch_events);
}

/* Display speed (percentage) and frame rate (frames per second). */
void vsyncarch_display_speed(double speed, double frame_rate, int warp_enabled)
{
    ui_display_speed((float)speed, (float)frame_rate, warp_enabled);
}

/* Sleep a number of timer units. */
void vsyncarch_sleep(signed long delay)
{//printf("delay:%d \n",delay);
	usleep(delay);
}

void vsyncarch_presync(void)
{

    kbdbuf_flush();
	
	retro_poll_event();

	video_canvas_render(RCANVAS,(BYTE *)Retro_Screen,
						384, 272,
                        XS,YS,//xs, ys,
                        0,0,//xi, yi,
                        384*4, 32);

	retro_virtualkb();

    if (uistatusbar_state & UISTATUSBAR_ACTIVE && vice_statusbar==1) {
		
        uistatusbar_draw();
    }

	if(pauseg==1)pause_select();

#ifndef NO_LIBCO
	co_switch(mainThread);
#endif

}

void_hook_t vsync_set_event_dispatcher(void_hook_t hook)
{
    void_hook_t t = ui_dispatch_hook;
    ui_dispatch_hook = hook;
    return t;
}

void vsyncarch_postsync(void)
{
    /* Dispatch all the pending UI events.  */
    ui_dispatch_events();
}