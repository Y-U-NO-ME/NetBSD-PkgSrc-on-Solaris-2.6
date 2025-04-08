#ifndef _STDINT_H
#define _STDINT_H

typedef signed char        int8_t;
typedef unsigned char      uint8_t;
typedef short              int16_t;
typedef unsigned short     uint16_t;
typedef int                int32_t;
typedef unsigned int       uint32_t;

#if defined(__sparc__) || defined(__i386__) || defined(__sun)
typedef long               intptr_t;
typedef unsigned long      uintptr_t;
#endif

typedef long long          int64_t;
typedef unsigned long long uint64_t;

#endif /* _STDINT_H */
