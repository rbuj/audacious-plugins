/*
 * Audacious - a cross-platform multimedia player
 * Copyright (c) 2007 Tomasz Moń
 * Copyright (c) 2011 John Lindgren
 *
 * Based on:
 * BMP - Cross-platform multimedia player
 * Copyright (C) 2003-2004  BMP development team.
 * XMMS:
 * Copyright (C) 1998-2003  XMMS development team.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; under version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses>.
 *
 * The Audacious team does not consider modular code linking to
 * Audacious or using our public API to be a derived work.
 */

#ifndef SKINS_UI_SKINNED_TEXTBOX_H
#define SKINS_UI_SKINNED_TEXTBOX_H

#include <libaudcore/objects.h>

#include "widget.h"

#if 0
typedef SmartPtr<cairo_surface_t, cairo_surface_destroy> CairoSurfacePtr;
typedef SmartPtr<PangoFontDescription, pango_font_description_free> PangoFontDescPtr;
#endif

class TextBox : public Widget
{
public:
    TextBox (int width, const char * font, bool scroll);
    ~TextBox ();

    void set_width (int width);
    const String & get_text () { return m_text; }
    void set_text (const char * text);
    void set_font (const char * font);
    void set_scroll (bool scroll);

#if 0
    typedef bool (* PressCB) (GdkEventButton *);
    void on_press (PressCB callback) { press = callback; }
#endif

    static void update_all ();

private:
#if 0
    virtual void draw (QPainter & cr);
    virtual bool button_press (GdkEventButton * event);
#endif

    void scroll_timeout ();
    static void scroll_timeout_cb (void * me)
        { ((TextBox *) me)->scroll_timeout (); }

    void render_vector (const char * text);
    void render_bitmap (const char * text);
    void render ();

    String m_text;
#if 0
    PangoFontDescPtr m_font;
    CairoSurfacePtr m_buf;
#endif

    int m_width = 0, m_buf_width = 0;
    bool m_may_scroll = false, m_two_way = false;
    bool m_scrolling = false, m_backward = false;
    int m_offset = 0, m_delay = 0;

#if 0
    PressCB press = nullptr;
#endif
};

#endif
