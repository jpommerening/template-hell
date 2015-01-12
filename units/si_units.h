#ifndef _SI_UNITS__H
#define _SI_UNITS__H
#include "unit.h"

namespace SIUnits {

  /**
   * SI base units.
   * @{
   */

  class m : public Unit::unit< Unit::length > {
    public:
      static const char * const name;
  };

  class g : public Unit::unit< Unit::mass > {
    public:
      static const char * const name;
  };

  class s : public Unit::unit< Unit::time > {
    public:
      static const char * const name;
  };

  class A : public Unit::unit< Unit::electric_current > {
    public:
      static const char * const name;
  };

  class K : public Unit::unit< Unit::thermodynamic_temperature > {
    public:
      static const char * const name;
  };

  class cd : public Unit::unit< Unit::luminous_intensity > {
    public:
      static const char * const name;
  };

  class mol : public Unit::unit< Unit::amount_of_substance > {
    public:
      static const char * const name;
  };

  /** @} */

  /**
   * SI prefixes.
   * @{
   */

  namespace {
    template <class u, int i>
    class SIPrefix : public Unit::unit<
      typename u::quantity,
      Conversion::compound_conversion< typename u::conversion, Conversion::decimal_conversion<i> >
    > {
      public:
        static const char * const name;
    };
  }

  template <class u> class yotta : public SIPrefix< u, 24 > {};
  template <class u> class zetta : public SIPrefix< u, 21 > {};
  template <class u> class exa   : public SIPrefix< u, 18 > {};
  template <class u> class peta  : public SIPrefix< u, 15 > {};
  template <class u> class tera  : public SIPrefix< u, 12 > {};
  template <class u> class giga  : public SIPrefix< u, 9 > {};
  template <class u> class mega  : public SIPrefix< u, 6> {};
  template <class u> class kilo  : public SIPrefix< u, 3> {};
  template <class u> class hecto : public SIPrefix< u, 2 > {};
  template <class u> class deca  : public SIPrefix< u, 1 > {};

  template <class u> class deci  : public SIPrefix< u, -1 > {};
  template <class u> class centi : public SIPrefix< u, -2 > {};
  template <class u> class milli : public SIPrefix< u, -3 > {};
  template <class u> class micro : public SIPrefix< u, -6 > {};
  template <class u> class nano  : public SIPrefix< u, -9 > {};
  template <class u> class pico  : public SIPrefix< u, -12 > {};
  template <class u> class femto : public SIPrefix< u, -15 > {};
  template <class u> class atto  : public SIPrefix< u, -18 > {};
  template <class u> class zepto : public SIPrefix< u, -21 > {};
  template <class u> class yocto : public SIPrefix< u, -24 > {};

  /** @} */

}

#endif
