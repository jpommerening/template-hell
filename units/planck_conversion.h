#ifndef _PLANCK_CONVERSION__H
#define _PLANCK_CONVERSION__H
#include "conversion.h"
#include "physical_constants.h"

namespace Conversion {

struct planck_unit {
  enum {
    LENGTH,
    MASS,
    TIME,
    CHARGE,
    TEMPERATURE
  };
};

template <class c>
class constant_conversion {
  public:
    template <typename v>
    static v apply( const v value ) {
      return value / c().value();
    }

    template <typename v>
    static v revert( const v value ) {
      return value * c().value();
    }
};

template <int u>
class planck_conversion {};

template <>
class planck_conversion<planck_unit::LENGTH> : public constant_conversion< PhysicalConstants::lP<double> > {};

template <>
class planck_conversion<planck_unit::MASS> : public constant_conversion< PhysicalConstants::mP<double> > {};

template <>
class planck_conversion<planck_unit::TIME> : public linear_conversion< 1000, 10 > {};

template <>
class planck_conversion<planck_unit::CHARGE> : public linear_conversion< 1000, 10 > {};

template <>
class planck_conversion<planck_unit::TEMPERATURE> : public linear_conversion< 1000, 10 > {};

}

#endif
