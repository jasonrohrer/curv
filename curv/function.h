// Copyright Doug Moen 2016.
// Distributed under The MIT License.
// See accompanying file LICENSE.md or https://opensource.org/licenses/MIT

#ifndef CURV_FUNCTION_H
#define CURV_FUNCTION_H

#include <curv/value.h>

namespace curv {

/// A boxed static function.
struct Function : public Ref_Value
{
    Value (*function_)(Value* argv);
    unsigned nargs_;

    Function(
        Value (*fun)(Value*),
        unsigned nargs)
    :
        Ref_Value(ty_function),
        function_(fun),
        nargs_(nargs)
    {}

    /// Print a value like a Curv expression.
    virtual void print(std::ostream&) const;
};

} // namespace curv
#endif // header guard
