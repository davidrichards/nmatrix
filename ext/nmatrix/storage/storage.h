/////////////////////////////////////////////////////////////////////
// = NMatrix
//
// A linear algebra library for scientific computation in Ruby.
// NMatrix is part of SciRuby.
//
// NMatrix was originally inspired by and derived from NArray, by
// Masahiro Tanaka: http://narray.rubyforge.org
//
// == Copyright Information
//
// SciRuby is Copyright (c) 2010 - 2012, Ruby Science Foundation
// NMatrix is Copyright (c) 2012, Ruby Science Foundation
//
// Please see LICENSE.txt for additional copyright notices.
//
// == Contributing
//
// By contributing source code to SciRuby, you agree to be bound by
// our Contributor Agreement:
//
// * https://github.com/SciRuby/sciruby/wiki/Contributor-Agreement
//
// == storage.h
//
// This file brings together everything in the storage directory.  It should not
// be included by anything in the storage directory, but should be included by
// files needing to use the storage code.

#ifndef STORAGE_H
#define STORAGE_H

/*
 * Standard Includes
 */

#include <stdlib.h>

/*
 * Project Includes
 */

#include "types.h"

#include "data/data.h"

#include "common.h"
#include "dense.h"
#include "list.h"
#include "yale.h"

/*
 * Macros
 */

#define NMATRIX_DTYPE_IS_COMPLEX(s)		((s->dtype == COMPLEX64) or (s->dtype == COMPLEX128))
#define NMATRIX_DTYPE_IS_FLOAT(s)			((s->dtype == FLOAT32) or (s->dtype == FLOAT64))
#define NMATRIX_DTYPE_IS_INTEGER(s)		(s->dtype <= INT64)
#define NMATRIX_DTYPE_IS_RATIONAL(s)	((s->dtype == RATIONAL32) or (s->dtype == RATIONAL64) or (s->dtype == RATIONAL128))
#define NMATRIX_DTYPE_IS_RUBYOBJ(s)		(s->dtype == RUBYOBJ)


/*
 * Types
 */


/*
 * Data
 */

namespace nm {
	const int NUM_STYPES = 3;
}

extern "C" {

  extern const char* const STYPE_NAMES[nm::NUM_STYPES];
  extern void (* const STYPE_MARK[nm::NUM_STYPES])(void*);

  /*
   * Functions
   */

  /////////////////////////
  // Copying and Casting //
  /////////////////////////

  STORAGE*	  nm_dense_storage_from_list(const STORAGE* right, dtype_t l_dtype);
  STORAGE*	  nm_dense_storage_from_yale(const STORAGE* right, dtype_t l_dtype);
  STORAGE*		nm_list_storage_from_dense(const STORAGE* right, dtype_t l_dtype);
  STORAGE*		nm_list_storage_from_yale(const STORAGE* right, dtype_t l_dtype);
  STORAGE*		nm_yale_storage_from_list(const STORAGE* right, dtype_t l_dtype);
  STORAGE*		nm_yale_storage_from_dense(const STORAGE* right, dtype_t l_dtype);

} // end of extern "C" block


#endif // STORAGE_H
