/*
Copyright (c) 2014 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include "util/lua.h"
#include "kernel/expr.h"

namespace lean {
/** \brief Create an explicit expression '@ f'.
    This only affects the elaborator behavior.
*/
expr mk_explicit(expr const & e);
/** \brief Return true iff \c e is an explicit expression. */
bool is_explicit(expr const & e);
/** \brief See #is_nested_annotation */
bool is_nested_explicit(expr const & e);
/** \brief Return the argument of an explicit expression.
    \pre is_explicit(e)
*/
expr const & get_explicit_arg(expr const & e);

/** \brief Create an explicit expression that is accepted as is
    by the elaborator.
*/
expr mk_as_is(expr const & e);
/** \brief Return true iff \c e was created with mk_as_is. */
bool is_as_is(expr const & e);
/** \brief Return the argument of an expression created using mk_as_is.
    \pre is_as_is(e)
*/
expr const & get_as_is_arg(expr const & e);

/** \brief Create an expression that should be treated as an atom by the elaborator.
    This expression also "cancels" the effect of a nested '@'.
*/
expr mk_as_atomic(expr const & e);
/** \brief Return true iff \c e is an atomic expression. */
bool is_as_atomic(expr const & e);
/** \brief Return the argument of an atomic expression.
    \pre is_atomic(e)
*/
expr const & get_as_atomic_arg(expr const & e);

/** \brief Create the expression '! e'.
    This only affects the elaborator behavior.
    It instructs the elaborator to keep adding '_'
    for \c e arguments.
*/
expr mk_consume_args(expr const & e);
/** \brief Return true iff \c e is an '!f' expression. */
bool is_consume_args(expr const & e);
expr const & get_consume_args_arg(expr const & e);

void open_explicit(lua_State * L);
void initialize_explicit();
void finalize_explicit();
}
