/* Pango
 * pango-context.h: Rendering contexts
 *
 * Copyright (C) 2000 Red Hat Software
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

#ifndef __PANGO_CONTEXT_H__
#define __PANGO_CONTEXT_H__

#include <pango/pango-font.h>
#include <pango/pango-fontmap.h>
#include <pango/pango-attributes.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Sort of like a GC - application set information about how
 * to handle scripts
 */
typedef struct _PangoContext      PangoContext;
typedef struct _PangoContextClass PangoContextClass;

#define PANGO_TYPE_CONTEXT              (pango_context_get_type ())
#define PANGO_CONTEXT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_CONTEXT, PangoContext))
#define PANGO_CONTEXT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_CONTEXT, PangoContextClass))
#define PANGO_IS_CONTEXT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_CONTEXT))
#define PANGO_IS_CONTEXT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_CONTEXT))
#define PANGO_CONTEXT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_CONTEXT, PangoContextClass))


/* The PangoContext and PangoContextClass structs are private; if you
 * need to create a subclass of these, mail otaylor@redhat.com
 */

GType         pango_context_get_type      (void);
PangoContext *pango_context_new           (void);
void          pango_context_add_font_map  (PangoContext                 *context,
					   PangoFontMap                 *font_map);
void          pango_context_list_fonts    (PangoContext                 *context,
					   const char                   *family,
					   PangoFontDescription       ***descs,
					   int                          *n_descs);
void          pango_context_list_families (PangoContext                 *context,
					   gchar                      ***families,
					   int                          *n_families);
PangoFont *   pango_context_load_font     (PangoContext                 *context,
					   const PangoFontDescription   *desc);

void                  pango_context_set_font_description (PangoContext               *context,
							  const PangoFontDescription *desc);
PangoFontDescription *pango_context_get_font_description (PangoContext               *context);
char *                pango_context_get_lang             (PangoContext               *context);
void                  pango_context_set_lang             (PangoContext               *context,
							  const char                 *lang);
void                  pango_context_set_base_dir         (PangoContext               *context,
							  PangoDirection              direction);
PangoDirection        pango_context_get_base_dir         (PangoContext               *context);


/* Break a string of Unicode characters into segments with
 * consistent shaping/language engine and bidrectional level.
 * Returns a GList of PangoItem's
 */
GList *pango_itemize (PangoContext   *context, 
		      const char     *text, 
		      gint            length,
		      PangoAttrList  *attrs);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PANGO_CONTEXT_H__ */
