/*
   mkvmerge GUI -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   header editor: track type page class

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __HE_TRACK_TYPE_PAGE_H
#define __HE_TRACK_TYPE_PAGE_H

#include "common/os.h"

#include <wx/string.h>

#include "mmg/header_editor/top_level_page.h"

class he_track_type_page_c: public he_top_level_page_c {
public:
  int m_track_type;
  unsigned int m_track_number;

public:
  he_track_type_page_c(header_editor_frame_c *parent, int track_type, unsigned int track_number, ebml_element_cptr l1_element);
  virtual ~he_track_type_page_c();

  virtual void translate_ui();
};

#endif // __HE_TRACK_TYPE_PAGE_H
