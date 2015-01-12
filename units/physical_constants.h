#ifndef _PHYSICAL_CONSTANTS__H
#define _PHYSICAL_CONSTANTS__H
#include "unit.h"
#include "value.h"
#include "si_units.h"
#include "si_derived_units.h"
#include "mathematical_constants.h"

#include <cmath>

namespace PhysicalConstants {

  namespace {
    /* m/s */
    typedef Unit::divide< SIUnits::m, SIUnits::s >::type mps;

    /* N / A^2 */
    typedef Unit::divide<
      Unit::unwind<SIUnits::N>::type,
      Unit::pow<Unit::unwind<SIUnits::A>::type, 2>::type
    >::type NpA2;

    /* F / m */
    typedef Unit::divide< Unit::unwind<SIUnits::F>::type, SIUnits::m >::type Fpm;

    /* (m^3) / (kg * s^2) */
    typedef Unit::divide<
              Unit::pow<SIUnits::m,3>::type,
              Unit::multiply< SIUnits::kg, Unit::pow<SIUnits::s,2>::type >::type
            >::type m3pkgs2;

    /* J * s */
    typedef Unit::multiply< Unit::unwind<SIUnits::J>::type, SIUnits::s >::type Js;

    /* J / K */
    typedef Unit::divide< Unit::unwind<SIUnits::J>::type, Unit::unwind<SIUnits::K>::type >::type JpK;
  };

  /** Speed of light */
  template <typename v>
  class c0 : public Constant< v, mps > {
    public:
      c0() : Constant< v, mps >( v(299792458.0) ) {};
  };

  /** Vacuum permeability */
  template <typename v>
  class u0 : public Constant< v, NpA2 > {
    public:
      u0() : Constant< v, NpA2 >( MathematicalConstants::pi< v >() * 4e-7 ) {};
  };

  /** Vacuum permittivity */
  template <typename v>
  class e0 : public Constant< v, Fpm > {
    public:
      e0() : Constant< v, Fpm >( Constant< v >( 1.0 ) / (u0< v >() * c0< v >() * c0< v >()) ) {};
  };

  /** Gravitational constant */
  template <typename v>
  class G : public Constant< v, m3pkgs2 > {
    public:
      G() : Constant< v, m3pkgs2 >( (v) 6.67384e-11 ) {};
  };

  /** Planck constant */
  template <typename v>
  class h : public Constant< v, Js > {
    public:
      h() : Constant< v, Js >( (v) 6.62606957e-34 ) {};
  };

  /** Reduced Planck constant */
  template <typename v>
  class h_ : public Constant< v, Js > {
    public:
      h_() : Constant< v, Js >( (v) 1.054571726e-34 ) {};
  };

  /** Boltzmann constant */
  template <typename v>
  class kB : public Constant< v, JpK > {
    public:
      kB() : Constant< v, JpK >( (v) 1.3806488e-23 ) {};
  };

/**
 * Planck units
 */

  template <typename v>
  class mP : public Constant< v, SIUnits::g > {
    public:
      mP() : Constant< v, SIUnits::g >( sqrt( h_<double>().value() * c0<double>().value() / G<double>().value() ) ) {};
  };

  template <typename v>
  class lP : public Constant< v, SIUnits::m > {
    public:
      lP() : Constant< v, SIUnits::m >( sqrt( h_<double>().value() * G<double>().value() / pow( c0<double>().value(), 3 ) ) ) {};
  };
}

#endif
