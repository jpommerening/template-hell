#include "si_derived_units.h"

/* because these are typedefs and the ::name is in the
 * Unit namespace ... */
namespace Unit {

  template <> const char * const ::SIUnits::Hz::name = "Hz";
  template <> const char * const ::SIUnits::rad::name = "rad";
  template <> const char * const ::SIUnits::sr::name = "sr";
  template <> const char * const ::SIUnits::N::name = "N";
  template <> const char * const ::SIUnits::Pa::name = "Pa";
  template <> const char * const ::SIUnits::J::name = "J";
  template <> const char * const ::SIUnits::W::name = "W";
  template <> const char * const ::SIUnits::C::name = "C";
  template <> const char * const ::SIUnits::F::name = "F";
  template <> const char * const ::SIUnits::ohms::name = "";
  template <> const char * const ::SIUnits::S::name = "S";
  template <> const char * const ::SIUnits::Wb::name = "Wb";
  template <> const char * const ::SIUnits::T::name = "T";
  template <> const char * const ::SIUnits::H::name = "H";
  template <> const char * const ::SIUnits::lm::name = "lm";
  template <> const char * const ::SIUnits::lx::name = "lx";
  template <> const char * const ::SIUnits::Bq::name = "Bq";
  template <> const char * const ::SIUnits::Gy::name = "Gy";
  template <> const char * const ::SIUnits::Sv::name = "Sv";
  template <> const char * const ::SIUnits::kat::name = "kat";
};
