#ifndef _SI_DERIVED_UNITS__H
#define _SI_DERIVED_UNITS__H
#include "unit.h"
#include "si_units.h"

namespace SIUnits {

  namespace {
     typedef kilo<g> kg;
     typedef ::Unit::multiply<m,m>::type qm;
  };

  /**
   * Basic named derived units.
   * Each definition is in normalized SI form.
   * All use of derived units is unwound in subsequent definitions.
   * Some ::Units are redundant, it is not always possible to give them
   * unique names.
   * A Bequerel value may turn out to be in Hertz.
   */

  typedef ::Unit::do_divide< ::Unit::unit<>, s > Hz;
  typedef ::Unit::do_alias< ::Unit::unit<>, __LINE__ > rad;
  typedef ::Unit::do_alias< ::Unit::unit<>, __LINE__ > sr;
  typedef ::Unit::do_multiply< kg, ::Unit::divide< m, ::Unit::multiply<s,s>::type >::type > N;
  typedef ::Unit::do_divide< ::Unit::unwind<N>::type, qm > Pa;
  typedef ::Unit::do_multiply< ::Unit::unwind<N>::type, m > J;
  typedef ::Unit::do_divide< ::Unit::unwind<J>::type, s > W;
  typedef ::Unit::do_multiply< s, ::Unit::unwind<A>::type > C;
  typedef ::Unit::do_divide< ::Unit::unwind<W>::type, A > V;
  typedef ::Unit::do_divide< ::Unit::unwind<C>::type, ::Unit::unwind<V>::type > F;
  typedef ::Unit::do_divide< ::Unit::unwind<V>::type, A > ohms;
  typedef ::Unit::do_divide< ::Unit::unwind<A>::type, ::Unit::unwind<V>::type > S;
  typedef ::Unit::do_divide< ::Unit::unwind<J>::type, A > Wb;
  typedef ::Unit::do_multiply< ::Unit::unwind<V>::type, ::Unit::divide< s, qm >::type > T;
  typedef ::Unit::do_multiply< ::Unit::unwind<V>::type, ::Unit::divide< s, A >::type > H;
  typedef ::Unit::do_multiply< cd, sr > lm;
  typedef ::Unit::do_divide< ::Unit::unwind<lm>::type, ::Unit::unwind<sr>::type > lx;
  typedef ::Unit::do_alias< Hz, __LINE__ > Bq;
  typedef ::Unit::do_divide< ::Unit::unwind<J>::type, kg > Gy;
  typedef ::Unit::do_alias< Gy, __LINE__ > Sv;
  typedef ::Unit::do_divide< mol, s > kat;

}

#endif
