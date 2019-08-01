/* Pango
 * pangofc-font.h: Base fontmap type for fontconfig-based backends
 *
 * Copyright (C) 2003 Red Hat Software
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __PANGO_FC_FONT_H__
#define __PANGO_FC_FONT_H__

#include <pango/pango-glyph.h>
#include <pango/pango-font.h>
#include <pango/pango-glyph.h>

/* Freetype has undefined macros in its header */
#ifdef PANGO_COMPILATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wundef"
#endif

#include <fontconfig/fontconfig.h>

#ifdef PANGO_COMPILATION
#pragma GCC diagnostic pop
#endif

G_BEGIN_DECLS

#define PANGO_TYPE_FC_FONT              (pango_fc_font_get_type ())
#define PANGO_FC_FONT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FC_FONT, PangoFcFont))
#define PANGO_IS_FC_FONT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FC_FONT))

typedef struct _PangoFcFont      PangoFcFont;
typedef struct _PangoFcFontClass PangoFcFontClass;

PANGO_AVAILABLE_IN_ALL
GType      pango_fc_font_get_type (void) G_GNUC_CONST;

PANGO_DEPRECATED_IN_1_44
gboolean   pango_fc_font_has_char          (PangoFcFont      *font,
                                            gunichar          wc);
PANGO_AVAILABLE_IN_1_4
guint      pango_fc_font_get_glyph         (PangoFcFont      *font,
                                            gunichar          wc);
PANGO_DEPRECATED_FOR(PANGO_GET_UNKNOWN_GLYPH)
PangoGlyph pango_fc_font_get_unknown_glyph (PangoFcFont      *font,
                                            gunichar          wc);
PANGO_DEPRECATED_IN_1_32
void       pango_fc_font_kern_glyphs       (PangoFcFont      *font,
                                            PangoGlyphString *glyphs);

PANGO_DEPRECATED_IN_1_44_FOR(pango_font_get_hb_font)
gpointer   pango_fc_font_lock_face         (PangoFcFont      *font);
PANGO_DEPRECATED_IN_1_44_FOR(pango_font_get_hb_font)
void       pango_fc_font_unlock_face       (PangoFcFont      *font);

G_END_DECLS
#endif /* __PANGO_FC_FONT_H__ */
