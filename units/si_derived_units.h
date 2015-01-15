#ifndef _SI_DERIVED_UNITS__H
#define _SI_DERIVED_UNITS__H
#include "unit.h"
#include "si_units.h"

namespace SIUnits {

  namespace {
     typedef kilo<g> kg;
     typedef Unit::multiply<m,m>::type sqm;
     typedef Unit::divide<m, Unit::multiply<s,s>::type>::type mps2;
  };

  /**
   * Basic named derived units.
   * Each definition is in normalized SI form.
   */

  typedef Unit::divide< Unit::unit<>,s>::type Hz;
  typedef Unit::alias< Unit::unit<>, __LINE__ >::type rad;
  typedef Unit::alias< Unit::unit<>, __LINE__ >::type sr;
  typedef Unit::multiply< kg, mps2 >::type N;
  typedef Unit::divide< N, sqm >::type Pa;
  typedef Unit::multiply< N, m >::type J;
  typedef Unit::divide< J, s >::type W;
  typedef Unit::multiply< s, A >::type C;
  typedef Unit::divide< W, A >::type V;
  typedef Unit::divide< C, V >::type F;
  typedef Unit::divide< V, A >::type ohm;
  typedef Unit::divide< A, V >::type S;
  typedef Unit::divide< J, A >::type Wb;
  typedef Unit::multiply< V, Unit::divide< s, sqm >::type >::type T;
  typedef Unit::multiply< V, Unit::divide< s, A >::type >::type H;
  typedef Unit::alias< cd, __LINE__ >::type lm;
  typedef Unit::divide< lm, sqm >::type lx;
  typedef Unit::alias< Hz, __LINE__ >::type Bq;
  typedef Unit::divide< J, kg >::type Gy;
  typedef Unit::alias< Gy, __LINE__ >::type Sv;
  typedef Unit::divide< mol, s >::type kat;

}

#endif
