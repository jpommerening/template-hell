#ifndef _SI_DERIVED_UNITS__H
#define _SI_DERIVED_UNITS__H
#include "si_units.h"

namespace SIUnits {

  namespace {
     typedef kilo<g> kg;
     typedef typename Unit::multiply<m,m>::type sqm;
     typedef typename Unit::divide<m, Unit::multiply<s,s>::type>::type mps2;
  };

  /**
   * Basic named derived units.
   * Each definition is in normalized SI form.
   * All use of derived units is unwound in subsequent definitions.
   * Some Units are redundant, it is not always possible to give them
   * unique names.
   * A Bequerel value may turn out to be in Hertz.
   */

  typedef typename Unit::divide<Unit::unit<>,s>::type Hz;
  typedef typename Unit::alias< Unit::unit<>, __LINE__ >::type rad;
  typedef typename Unit::alias< Unit::unit<>, __LINE__ >::type sr;
  typedef typename Unit::multiply< kg, mps2 >::type N;
  typedef typename Unit::divide< Unit::unwind<N>::type, sqm >::type Pa;
  typedef typename Unit::multiply< Unit::unwind<N>::type, m >::type J;
  typedef typename Unit::divide< Unit::unwind<J>::type, s >::type W;
  typedef typename Unit::multiply< s, Unit::unwind<A>::type >::type C;
  typedef typename Unit::divide< Unit::unwind<W>::type, A >::type V;
  typedef typename Unit::divide< Unit::unwind<C>::type, Unit::unwind<V>::type >::type F;
  typedef typename Unit::divide< Unit::unwind<V>::type, A >::type ohms;
  typedef typename Unit::divide< Unit::unwind<A>::type, Unit::unwind<V>::type >::type S;
  typedef typename Unit::divide< Unit::unwind<J>::type, A >::type Wb;
  typedef typename Unit::multiply< Unit::unwind<V>::type, Unit::divide< s, sqm >::type >::type T;
  typedef typename Unit::multiply< Unit::unwind<V>::type, Unit::divide< s, A >::type >::type H;
  typedef typename Unit::alias< cd, __LINE__ >::type lm;
  typedef typename Unit::divide< Unit::unwind<lm>::type, sqm >::type lx;
  typedef typename Unit::alias< Hz, __LINE__ >::type Bq;
  typedef typename Unit::divide< Unit::unwind<J>::type, kg >::type Gy;
  typedef typename Unit::alias< Gy, __LINE__ >::type Sv;
  typedef typename Unit::divide< mol, s >::type kat;

}

#endif
