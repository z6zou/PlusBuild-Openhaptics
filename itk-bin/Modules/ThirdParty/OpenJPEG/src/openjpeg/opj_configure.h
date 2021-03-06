/*
 * here is where system comupted values get stored these values should only
 * change when the target compile platform changes
 */

/* what byte order */
#ifndef __OPJ_CONFIGURE_H
#define __OPJ_CONFIGURE_H

/* All compilers that support Mac OS X define either __BIG_ENDIAN__ or
   __LITTLE_ENDIAN__ to match the endianness of the architecture being
   compiled for. This is not necessarily the same as the architecture of
   the machine doing the building. In order to support Universal Binaries on
   Mac OS X, we prefer those defines to decide the endianness.
   Elsewhere use the platform check result.  */
#if !defined(__APPLE__)
/* #undef CMAKE_WORDS_BIGENDIAN */
  #ifdef CMAKE_WORDS_BIGENDIAN
        #define OPJ_BIG_ENDIAN
  #else
        #define OPJ_LITTLE_ENDIAN
  #endif
#else
  #if defined(__BIG_ENDIAN__)
        #define OPJ_BIG_ENDIAN
  #else
        #define OPJ_LITTLE_ENDIAN
  #endif
#endif


#endif /* __OPJ_CONFIGURE_H */
