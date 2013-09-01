/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include "expr.h"
#include "hash.h"

namespace lean {
typedef std::pair<expr, expr> expr_pair;
/** \brief Functional object for hashing expression pairs. */
struct expr_pair_hash {
    unsigned operator()(expr_pair const & p) const { return hash(p.first.hash(), p.second.hash()); }
};
/** \brief Functional object for comparing expression pairs. */
struct expr_pair_eq {
    unsigned operator()(expr_pair const & p1, expr_pair const & p2) const { return p1.first == p2.first && p1.second == p2.second; }
};
/** \brief Functional object for comparing expression pairs using pointer equality. */
struct expr_pair_eqp {
    unsigned operator()(expr_pair const & p1, expr_pair const & p2) const { return is_eqp(p1.first, p2.first) && is_eqp(p1.second, p2.second); }
};
}
