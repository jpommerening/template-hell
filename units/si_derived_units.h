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
   */

  typedef typename Unit::divide< Unit::unit<>,s>::type Hz;
  typedef typename Unit::alias< Unit::unit<>, __LINE__ >::type rad;
  typedef typename Unit::alias< Unit::unit<>, __LINE__ >::type sr;
  typedef typename Unit::multiply< kg, mps2 >::type N;
  typedef typename Unit::divide< N, sqm >::type Pa;
  typedef typename Unit::multiply< N, m >::type J;
  typedef typename Unit::divide< J, s >::type W;
  typedef typename Unit::multiply< s, A >::type C;
  typedef typename Unit::divide< W, A >::type V;
  typedef typename Unit::divide< C, V >::type F;
  typedef typename Unit::divide< V, A >::type ohm;
  typedef typename Unit::divide< A, V >::type S;
  typedef typename Unit::divide< J, A >::type Wb;
  typedef typename Unit::multiply< V, Unit::divide< s, sqm >::type >::type T;
  typedef typename Unit::multiply< V, Unit::divide< s, A >::type >::type H;
  typedef typename Unit::alias< cd, __LINE__ >::type lm;
  typedef typename Unit::divide< lm, sqm >::type lx;
  typedef typename Unit::alias< Hz, __LINE__ >::type Bq;
  typedef typename Unit::divide< J, kg >::type Gy;
  typedef typename Unit::alias< Gy, __LINE__ >::type Sv;
  typedef typename Unit::divide< mol, s >::type kat;

}

#endif
