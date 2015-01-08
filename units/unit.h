#ifndef _UNIT__H
#define _UNIT__H
#include "conversion.h"

namespace Unit {

  /**
   * We use the quantity type to "tag" different kinds of quantities.
   * You can't convert (assign) between these basic quantities, but you can mix them
   * in calculations.
   */
  class quantity {};
  class none : public quantity {};
  class length : public quantity {};
  class mass : public quantity {};
  class time : public quantity {};
  class electric_current : public quantity {};
  class thermodynamic_temperature : public quantity {};
  class luminous_intensity : public quantity {};
  class amount_of_substance : public quantity {};

  template <class q1, class q2>
  class compound_quantity : public quantity {};

  template <class q>
  class inverse_quantity : public quantity {};

  namespace {
    /**
     * Helper: If u1 and u2 are equal types,
     * present type T as member typedefinition "type".
     */
    template <class u1, class u2, class T>
    class if_equal {};

    /**
     * Types are equal, define type.
     */
    template <class u, class T>
    class if_equal< u, u, T > { public: typedef T type; };

    /**
     * Type builders for quantities.
     * @{
     */
    template <class q1, class q2>
    class combine_quantities {
      public:
        typedef compound_quantity< q1, q2 > type;
    };

    template <class q>
    class combine_quantities< q, inverse_quantity<q> > {
      public:
        typedef q type;
    };

    template <class q>
    class combine_quantities< inverse_quantity<q>, q > {
      public:
        typedef q type;
    };

    template <class q>
    class invert_quantity {
      public:
        typedef inverse_quantity<q> type;
    };

    template <class q>
    class invert_quantity< inverse_quantity<q> > {
      public:
        typedef q type;
    };

    template <class q>
    class combine_quantities< none, inverse_quantity<q> > {
      public:
        typedef typename invert_quantity<q>::type type;
    };

    /** @} */

    /**
     * Determine unit name.
     * Test for static member name, use name() otherwise.
     */
    template <class u>
    const char * const unit_name( int i = sizeof(u::name) ) {
      return u::name;
    }

    template <class u>
    const char * const unit_name( void* ) {
      return u::name();
    }

  }

  template <class q=none, class c=Conversion::no_conversion>
  class unit {
    public:
      typedef c conversion;
      typedef q quantity;

      static const char * const name;

      template <class u>
      static const char * const getName() {
        return unit_name<u>();
      }
  };

  template <class u, int i>
  class do_alias : public u {
    public:
      static const char * const name;
  };

  template <class u1, class u2>
  class do_multiply : public unit< typename combine_quantities< typename u1::quantity, typename u2::quantity >::type,
                                   Conversion::compound_conversion< typename u1::conversion, typename u2::conversion > > {
    public:
      static const char * const name;
  };

  template <class u1, class u2>
  class do_divide : public unit< typename combine_quantities< typename u1::quantity,
                                                              typename invert_quantity< typename u2::quantity >::type >::type,
                                 Conversion::compound_conversion< typename u1::conversion, Conversion::inverse_conversion< typename u2::conversion > > > {
    public:
      static const char * const name;
  };

  template <class u>
  class do_divide< unit<>, u > : public unit< typename invert_quantity< typename u::quantity >::type,
                                              Conversion::inverse_conversion< typename u::conversion > > {
    public:
      static const char * const name;
  };

  /**
   * Alias units (for example rad = unit<>
   */
  template <class u, int i>
  class alias { public: typedef do_alias<u, i> type; };

  /**
   * Type builder for multiplication.
   */
  template <class u1, class u2>
  class multiply { public: typedef do_multiply<u1, u2> type; };

  /**
   * Type builder for division.
   */
  template <class u1, class u2>
  class divide { public: typedef do_divide<u1, u2> type; };

  /**
   * Type builder for exponentiation.
   */
  template <class u, int n=1>
  class pow { public: typedef do_multiply< typename pow<u, n-1>::type, u> type; };

  /**
   * Terminal rules
   * These provide termination points for the normalization rules.
   * @{
   */

  template <class u>
  class multiply< u, unit<> > { public: typedef u type; };

  template <class u>
  class multiply< unit<>, u > { public: typedef u type; };

  template <class u1, class u2>
  class multiply< do_divide<u1,u2>, u2 > { public: typedef u1 type; };

  template <class u1, class u2>
  class multiply< u1, do_divide<u2,u1> > { public: typedef u2 type; };

  template <class u>
  class divide< u, unit<> > { public: typedef u type; };

  template <class u>
  class divide< u, u > { public: typedef unit<> type; };

  template <class u>
  class divide< do_multiply<u,u>, u > { public: typedef u type; };

  template <class u1, class u2>
  class divide< do_multiply<u1,u2>, u2 > { public: typedef u1 type; };

  template <class u1, class u2>
  class divide< do_multiply<u1,u2>, u1 > { public: typedef u2 type; };

  template <class u1, class u2>
  class divide< u1, do_multiply<u1,u2> > { public: typedef typename divide< unit<>, u2 >::type type; };

  template <class u1, class u2>
  class divide< u1, do_multiply<u2,u1> > { public: typedef typename divide< unit<>, u2 >::type type; };

  /** @} */

  /**
   * Normalization rules.
   * These rules serve to simplify and disambiguate formulae.
   * Normalization follows the goal to reduce the whole term to a minimal
   * number of divisions which happen at the outermost level.
   * There is probably a solution with less template specializations,
   * but this will do for now.
   * @{
   */

  template <class u1, class u2>
  class multiply< unit<>, do_multiply<u1,u2> > { public: typedef typename multiply<u1,u2>::type type; };

  template <class u1, class u2, class u3>
  class multiply< u1, do_multiply<u2,u3> > { public: typedef typename multiply< typename multiply<u1,u2>::type, u3 >::type type; };

  template <class u1, class u2, class u3>
  class multiply< do_divide<u1,u2>, u3 > { public: typedef typename divide< typename multiply<u1,u3>::type, u2 >::type type; };

  template <class u1, class u2, class u3>
  class multiply< u1, do_divide<u2,u3> > { public: typedef typename divide< u1, typename multiply<u2,u3>::type >::type type; };

  template <class u1, class u2, class u3>
  class multiply< do_divide<u1,u2>, do_divide<u3,u1> > { public: typedef typename divide<u3,u2>::type type; };

  template <class u1, class u2, class u3>
  class multiply< do_divide<u1,u2>, do_divide<u2,u3> > { public: typedef typename divide<u1,u3>::type type; };

  template <class u1, class u2, class u3, class u4>
  class multiply< do_divide<u1,u2>, do_divide<u3,u4> > { public: typedef typename divide< typename multiply<u1,u3>::type, typename multiply<u2,u4>::type >::type type; };

  template <class u1, class u2, class u3>
  class divide< u1, do_divide<u2,u3> > { public: typedef typename divide< typename multiply<u1,u3>::type, u2 >::type type; };

  template <class u1, class u2, class u3>
  class divide< do_divide< u1, u2 >, u3 > { public: typedef typename divide< u1, typename multiply<u2,u3>::type >::type type; };

  template <class u1, class u2, class u3, class u4>
  class divide< do_divide< u1, u2 >, do_divide< u3, u4 > > { public: typedef typename divide< typename multiply<u1,u4>::type, typename multiply<u2,u3>::type >::type type; };

  template <class u>
  class pow<u,2> { public: typedef typename multiply<u,u>::type type; };

  template <class u>
  class pow<u,1> { public: typedef u type; };

  template <class u>
  class pow<u,0> { public: typedef unit<> type; };

  /** @} */

  /**
   * Sorting rules.
   * We want to sort subsequent multiplications in a predictable manner.
   * @{
   */

  /** @} */

  /**
   * Equivalent fraction rules.
   * Once divisions only contain multiplications on both sides, factors
   * that appear on both sides can be eliminated.
   * @{
   */

  template <class u1, class u2, class u3>
  class divide< do_multiply<u1,u2>, do_multiply<u3,u1> > { public: typedef typename divide< u2, u3 >::type type; };

  template <class u1, class u2, class u3>
  class divide< do_multiply<u1,u2>, do_multiply<u3,u2> > { public: typedef typename divide< u1, u3 >::type type; };

  template <class u1, class u2, class u3>
  class divide< do_multiply<u1,u2>, do_multiply<u1,u3> > { public: typedef typename divide< u2, u3 >::type type; };

  template <class u1, class u2, class u3>
  class divide< do_multiply<u1,u2>, do_multiply<u2,u3> > { public: typedef typename divide< u1, u3 >::type type; };

  template <class u1, class u2>
  class divide< do_multiply<u1,u2>, do_multiply<u2,u2> > { public: typedef typename divide< u1, u2 >::type type; };

  template <class u1, class u2>
  class divide< do_multiply<u1,u2>, do_multiply<u1,u1> > { public: typedef typename divide< u2, u1 >::type type; };

  template <class u>
  class divide< do_multiply<u,u>, do_multiply<u,u> > { public: typedef unit<> type; };

  /** @} */

  /**
   * Check that type quantities are equal.
   */
  template <class u1, class u2>
  class checked_conversion : public if_equal< typename u1::quantity, typename u2::quantity,
                                              Conversion::conversion< typename u1::conversion, typename u2::conversion > >::type {};

  /**
   * Helper to unwind complex types.
   */

  template <class u>
  class unwind { public: typedef u type; };

  template <class u1, class u2>
  class unwind< do_multiply<u1,u2> > { public: typedef typename multiply<u1,u2>::type type; };

  template <class u1, class u2>
  class unwind< do_divide<u1,u2> > { public: typedef typename divide<u1,u2>::type type; };

}

#endif
