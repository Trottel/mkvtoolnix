/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   class definition for the video output module

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __P_MPEG1_2_H
#define __P_MPEG1_2_H

#include "common/common_pch.h"

#include "common/mpeg1_2.h"
#include "output/p_video.h"
#include "mpegparser/M2VParser.h"

class mpeg1_2_video_packetizer_c: public video_packetizer_c {
protected:
  M2VParser m_parser;
  memory_cptr m_seq_hdr;
  bool m_framed, m_aspect_ratio_extracted;

public:
  mpeg1_2_video_packetizer_c(generic_reader_c *p_reader, track_info_c &p_ti, int version, double fps, int width, int height, int dwidth, int dheight, bool framed);

  virtual int process(packet_cptr packet);
  virtual void flush();

  virtual const std::string get_format_name(bool translate = true) {
    return translate ? Y("MPEG-1/2") : "MPEG-1/2";
  }

protected:
  virtual void extract_fps(const unsigned char *buffer, int size);
  virtual void extract_aspect_ratio(const unsigned char *buffer, int size);
  virtual void create_private_data();
  virtual int process_framed(packet_cptr packet);
  virtual bool put_sequence_headers_into_codec_state(packet_cptr packet);
};

#endif  // __P_MPEG1_2_H
