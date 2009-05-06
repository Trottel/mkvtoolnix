/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   math helper functions

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#include "common/os.h"

#include "common/math.h"

uint32_t
round_to_nearest_pow2(uint32_t value) {
  int64_t best_value = 0;
  int64_t test_value = 1;

  while (0x80000000ul >= test_value) {
    if (iabs(value - test_value) < iabs(value - best_value))
      best_value = test_value;
    test_value <<= 1;
  }

  return best_value;
}

int
int_log2(uint32_t value) {
  uint32_t bit, mask;
  uint32_t highest = 0;
  for (mask = 1, bit = 0; 31 >= bit; mask <<= 1, ++bit)
    if (value & mask)
      highest = bit;

  return highest;
}
