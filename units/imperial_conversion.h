#ifndef _IMPERIAL_CONVERSION__H
#define _IMPERIAL_CONVERSION__H
#include "conversion.h"

namespace Conversion {

  struct imperial_unit {
    enum {
      THOU,
      INCH,
      FOOT,
      YARD,
      CHAIN,
      FURLONG,
      MILE
    };
  };

  template <int u=imperial_unit::FOOT>
  class imperial_conversion {};

  template <>
  class imperial_conversion<imperial_unit::THOU> : public linear_conversion< 10000000, 254 > {};

  template <>
  class imperial_conversion<imperial_unit::INCH> : public linear_conversion< 10000, 254 > {};

  template <>
  class imperial_conversion<imperial_unit::FOOT> : public linear_conversion< 10000, 3048 > {};

  template <>
  class imperial_conversion<imperial_unit::YARD> : public linear_conversion< 10000, 9144 > {};

  template <>
  class imperial_conversion<imperial_unit::CHAIN> : public linear_conversion< 10000, 201168 > {};

  template <>
  class imperial_conversion<imperial_unit::FURLONG> : public linear_conversion< 1000, 201168 > {};

  template <>
  class imperial_conversion<imperial_unit::MILE> : public linear_conversion< 1000, 1609344 > {};

}

#endif
