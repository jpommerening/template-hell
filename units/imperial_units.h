#ifndef _IMPERIAL_UNITS__H
#define _IMPERIAL_UNITS__H
#include "unit.h"
#include "imperial_conversion.h"

namespace ImperialUnits {

  class thou : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::THOU> > {
    public:
      static const char * const name;
  };

  class inch : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::INCH> > {
    public:
      static const char * const name;
  };

  class foot : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::FOOT> > {
    public:
      static const char * const name;
  };

  class yard : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::YARD> > {
    public:
      static const char * const name;
  };

  class chain : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::CHAIN> > {
    public:
      static const char * const name;
  };

  class furlong : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::FURLONG> > {
    public:
      static const char * const name;
  };

  class mile : public Unit::unit< Unit::length, Conversion::imperial_conversion<Conversion::imperial_unit::MILE> > {
    public:
      static const char * const name;
  };

}

#endif
