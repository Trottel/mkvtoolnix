/*
  mkvmerge -- utility for splicing together matroska files
      from component media subtypes

  hacks.h

  Written by Moritz Bunkus <moritz@bunkus.org>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file
    \version $Id$
    \brief some hacks that the author might want to use
    \author Moritz Bunkus <moritz@bunkus.org>
*/

#ifndef __HACKS_H
#define __HACKS_H

// Some hacks that are configurable via command line but which should ONLY!
// be used by the author.
#define ENGAGE_SPACE_AFTER_CHAPTERS "space_after_chapters"
#define ENGAGE_NO_CHAPTERS_IN_META_SEEK "no_chapters_in_meta_seek"
#define ENGAGE_NO_META_SEEK "no_meta_seek"

bool hack_engaged(const char *hack);

#endif // __HACKS_H
