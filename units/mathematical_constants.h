#ifndef _MATHEMATICAL_CONSTANTS__H
#define _MATHEMATICAL_CONSTANTS__H
#include "value.h"
#include <cmath>

namespace MathematicalConstants {

  template <typename v>
  class pi : public Constant< v > {
    public:
      pi() : Constant< v >( v(M_PI) ) {};
  };

  template <typename v>
  class e : public Constant< v > {
    public:
      e() : Constant< v >( v(M_E) ) {};
  };

}

#endif
