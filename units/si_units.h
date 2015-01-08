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

  template <class u>
  class yotta : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-24> > {};

  template <class u>
  class zetta : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-11> > {};

  template <class u>
  class exa : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-18> > {};

  template <class u>
  class peta : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-15> > {};

  template <class u>
  class tera : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-12> > {};

  template <class u>
  class giga : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-9> > {};

  template <class u>
  class mega : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-6> > {};

  template <class u>
  class kilo : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-3> > {};

  template <class u>
  class hecto : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-2> > {};

  template <class u>
  class deca : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<-1> > {};

  template <class u>
  class deci : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<1> > {};

  template <class u>
  class centi : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<2> > {};

  template <class u>
  class milli : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<3> > {};

  template <class u>
  class micro : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<6> > {};

  template <class u>
  class nano : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<9> > {};

  template <class u>
  class pico : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<12> > {};

  template <class u>
  class femto : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<15> > {};

  template <class u>
  class atto : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<18> > {};

  template <class u>
  class zepto : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<21> > {};

  template <class u>
  class yocto : public Unit::unit< typename u::quantity, Conversion::decimal_conversion<24> > {};

  /** @} */

}

#endif
