#ifndef _VALUE__H
#define _VALUE__H
#include <iostream>
#include "conversion.h"
#include "unit.h"

template < typename v, class u=Unit::unit<> >
class Value {
  public:
    typedef v type;
    typedef u unit;

  private:
    v value_;

  public:

    explicit Value( v value ) : value_( value ) {
      std::cout << "Constructed value: " << value_ << u::name << " from scalar.\n";
    }

    Value( const Value &value ) : value_( value.value_ ) {};

    template <class u2>
    Value( const Value<v,u2> &value ) : value_( Unit::checked_conversion< u2, u >::apply( value.value() ) ) {
      std::cout << "Constructed value: " << value_ << u::name << " from object.\n";
    }

    Value<v,u>& operator+=( const Value<v,u> &rhs ) {
      value_ += rhs.value_;
      return *this;
    }

    Value<v,u>& operator-=( const Value<v,u> &rhs ) {
      value_ -= rhs.value_;
      return *this;
    }

    Value<v,u>& operator*=( const v &rhs ) {
      value_ *= rhs;
      return *this;
    }

    Value<v,u>& operator/=( const v &rhs ) {
      value_ /= rhs;
      return *this;
    }

    const v value() const { return value_; }

    const Value<v,u> operator+( const Value<v,u> &rhs ) const {
      std::cout << "Add values: " << value_ << u::name << " + " << rhs.value_ << u::name << "\n";
      Value<v,u> result = *this;
      result += rhs;
      return result;
    }

    const Value<v,u> operator-( const Value<v,u> &rhs ) const {
      std::cout << "Substract values: " << value_ << u::name << " - " << rhs.value_ << u::name << "\n";
      Value<v,u> result = *this;
      result -= rhs;
      return result;
    }

    template<class u2>
    const Value< v, typename Unit::multiply<u,u2>::type > operator*( const Value<v,u2> &rhs ) const {
      std::cout << "Multiply values: " << value_ << u::name << " * " << rhs.value() << u2::name << "\n";
      return Value< v, typename Unit::multiply<u,u2>::type >( value_ * rhs.value() );
    }

    template<class u2>
    const Value< v, typename Unit::divide<u,u2>::type > operator/( const Value<v,u2> &rhs ) const {
      std::cout << "Divide values: " << value_ << u::name << " / " << rhs.value() << u2::name << "\n";
      return Value< v, typename Unit::divide<u,u2>::type >( value_ / rhs.value() );
    }

    const Value operator*( const v &rhs ) const {
      return Value( value_ * rhs );
    }

    const Value operator/( const v &rhs ) const {
      return Value( value_ / rhs );
    }

    /*
    operator v() const {
      return value_;
    }
    */
};

template <typename v, typename u=Unit::unit<> >
class Constant : public Value< v, u> {
  public:
    Constant( v value ) : Value<v,u>( value ) {};
    Constant( const Constant &value ) : Value<v,u>( value.value() ) {};

  private:
    Constant<v,u> operator=( const Constant<v,u> &rhs );
    Constant<v,u> operator+=( const Constant<v,u> &rhs );
    Constant<v,u> operator-=( const Constant<v,u> &rhs );
    Constant<v,u> operator*=( const Constant<v,u> &rhs );
    Constant<v,u> operator/=( const Constant<v,u> &rhs );
};

#endif
