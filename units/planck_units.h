#ifndef _PLANCK_UNITS__H
#define _PLANCK_UNITS__H
#include "unit.h"
#include "planck_conversion.h"

namespace PlanckUnits {

 /**
  * Planck base units.
  * @{
  */

  class lP : public Unit::unit< Unit::length, Conversion::planck_conversion<Conversion::planck_unit::LENGTH> > {
    public:
      static const char * const name;
  };

  class mP : public Unit::unit< Unit::mass, Conversion::planck_conversion<Conversion::planck_unit::MASS> > {
    public:
      static const char * const name;
  };

  class tP : public Unit::unit< Unit::time, Conversion::planck_conversion<Conversion::planck_unit::TIME> > {
    public:
      static const char * const name;
  };

  class qP : public Unit::unit< Unit::do_multiply< Unit::time, Unit::electric_current >,
                                Conversion::planck_conversion<Conversion::planck_unit::CHARGE> > {
    public:
      static const char * const name;
  };

  class TP : public Unit::unit< Unit::thermodynamic_temperature,
                                Conversion::planck_conversion<Conversion::planck_unit::TEMPERATURE> > {
    public:
      static const char * const name;
  };

  /** @} */

}

#endif
