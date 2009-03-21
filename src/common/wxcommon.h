/*
   wxcommon.h

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   definitions for wxWindows

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __WXCOMMON_H
#define __WXCOMMON_H

#include "config.h"
#include "os.h"

#include <wx/version.h>

#if defined(wxUSE_UNICODE) && wxUSE_UNICODE
# define wxU(s) wxString(s, wxConvUTF8)
# define wxCS(s) ((const wchar_t *)(s).c_str())
# define wxMB(s) ((const char *)(s).mb_str(wxConvUTF8))
# define wxUCS(s) wxU(s).c_str()
# define wxCS2WS(s) wxUCS((s).c_str())
# define WXUNICODE 1
#else
# error wxWidgets was not compiled with Unicode support.
#endif

/* i18n stuff */
#if defined(HAVE_LIBINTL_H)
# include <libintl.h>
# if !defined Z
#  define Z(s) wxU(gettext(s))
# endif
#else /* HAVE_LIBINTL_H */
# if !defined Z
#  define Z(s) wxU(s)
# endif
#endif

// Use wxComboBox on non-Windows builds with wxWidgets 2.8.0 and newer
// because GTK's combo box has serious problems (see bug 339).
#if !defined(wxMTX_COMBOBOX_TYPE)
# if !defined(SYS_WINDOWS) && !defined(SYS_APPLE) && defined(HAVE_WXBITMAPCOMBOBOX) && HAVE_WXBITMAPCOMBOBOX
#  define USE_WXBITMAPCOMBOBOX
#  define wxMTX_COMBOBOX_TYPE wxBitmapComboBox
#  include <wx/bmpcbox.h>

# else

#  define wxMTX_COMBOBOX_TYPE wxComboBox

# endif
#endif

#endif /* __WXCOMMON_H */
