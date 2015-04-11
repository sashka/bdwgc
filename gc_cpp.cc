/*
 * Copyright (c) 1994 by Xerox Corporation.  All rights reserved.
 *
 * THIS MATERIAL IS PROVIDED AS IS, WITH ABSOLUTELY NO WARRANTY EXPRESSED
 * OR IMPLIED.  ANY USE IS AT YOUR OWN RISK.
 *
 *     Last modified on Sat Nov 19 19:31:14 PST 1994 by ellis
 *
 * Permission is hereby granted to copy this code for any purpose,
 * provided the above notices are retained on all copies.
 */

/*************************************************************************
This implementation module for gc_c++.h provides an implementation of
the global operators "new" and "delete" that calls the Boehm
allocator.  All objects allocated by this implementation will be
non-collectable but part of the root set of the collector.

You should ensure (using implementation-dependent techniques) that the
linker finds this module before the library that defines the default
built-in "new" and "delete".

Authors: John R. Ellis and Jesse Hull

**************************************************************************/

# ifdef HAVE_CONFIG_H
#   include "private/config.h"
# endif

# ifndef GC_BUILD
#   define GC_BUILD
# endif

#if !defined(GC_ATOMIC_UNCOLLECTABLE) && defined(ATOMIC_UNCOLLECTABLE)
  /* For compatibility with old-style naming. */
# define GC_ATOMIC_UNCOLLECTABLE
#endif

#include "gc_cpp.h"
