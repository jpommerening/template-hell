#ifndef _CONVERSION__H
#define _CONVERSION__H

/**
 * Basic conversions.
 */
namespace Conversion {

/**
 * Don't perform any conversion. (identity)
 */
class no_conversion {
  public:
    template <typename v>
    static inline v apply( const v value ) {
      return value;
    }

    template <typename v>
    static inline v revert( const v value ) {
      return value;
    }
};

/**
 * Basic from-to conversion. Application is reversion of
 * conversion a and application of conversion b.
 */
template <class a, class b=no_conversion>
class conversion {
  public:
    template <typename v>
    static inline v apply( const v value ) {
      return b::apply( a::revert( value ) );
    }

    template <typename v>
    static inline v revert( const v value ) {
      return a::apply( b::revert( value ) );
    }
};

template <class c>
class runtime_conversion {
  private:
    static const c converter;

  public:
    template <typename v>
    static v apply( const v value ) {
      return converter.apply( value );
    }

    template <typename v>
    static v revert( const v value ) {
      return converter.revert( value );
    }
};

/**
 * Compound (recursive) conversion. Application is
 * application of both conversion a then conversion b.
 */
template <class a, class b>
class compound_conversion {
  public:
    template <typename v>
    static inline v apply( const v value ) {
      return b::apply( a::apply( value ) );
    }

    template <typename v>
    static inline v revert( const v value ) {
      return a::revert( b::revert( value ) );
    }
};

/**
 * Inversion of conversion c. Application is
 * reversion of conversion c.
 */
template <class c>
class inverse_conversion {
  public:
    template <typename v>
    static inline v apply( const v value ) {
      return c::revert( value );
    }

    template <typename v>
    static inline v revert( const v value ) {
      return c::apply( value );
    }
};

/**
 * Mathematical, linear conversion.
 * Application is multiplication with nominator n and
 * division by denominator d.
 */
template <int n=1, int d=1>
class linear_conversion {
  static const long long numer = n;
  static const long long denom = d;

  public:
    template <typename v>
    static v apply( const v value ) {
      return value * numer / denom;
    }

    template <typename v>
    static v revert( const v value ) {
      return value * denom / numer;
    }
};

namespace {
  template <typename v, int b=10, int e=0, bool p=(e>=0)>
  struct pow;

  template <typename v, int b>
  struct pow< v, b, 0 > {
    static const v value = 1.;
  };

  template <typename v, int b, int e>
  struct pow< v, b, e, true > {
    static const v value = b * pow<v, b, e-1>::value;
  };

  template <typename v, int b, int e>
  struct pow< v, b, e, false > {
    static const v value = b / pow<v, b, 1-e>::value;
  };
}

/**
 * Decimal conversion.
 */
template <int e=0, bool p=(e>=0)>
class decimal_conversion;

template <int e>
class decimal_conversion< e, true > : public linear_conversion< 1, pow<long long, 10, e >::value > {};

template <int e>
class decimal_conversion< e, false > : public linear_conversion< pow<long long, 10, -e >::value, 1 > {};

/**
 * Template specializations for reduced overhead.
 * @{
 */

/**
 * No conversion neccessary from a to a.
 */
template <class a>
class conversion< a, a > : public no_conversion {};

/**
 * Application followed by reversion is no conversion.
 */
template <class a>
class compound_conversion< a, inverse_conversion<a> > : public no_conversion {};

/**
 * Reversion followed by application is no conversion.
 */
template <class a>
class compound_conversion< inverse_conversion<a>, a > : public no_conversion {};

/**
 * duplicate inversion is no conversion.
 */
template <class a>
class inverse_conversion< inverse_conversion<a> > : public no_conversion {};

/** @} */

/**
 * Template functions.
 * @{
 */

template <typename v, class from, class to>
const v convert( v value ) {
  return conversion< typename from::conversion, typename to::conversion >::apply( value );
}

/** @} */

}

#endif
