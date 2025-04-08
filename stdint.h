#ifndef _STDINT_H
#define _STDINT_H

/* Only define types if they aren't already defined by sys/int_types.h or other system headers */

#ifndef __int8_t_defined
typedef signed char        int8_t;
typedef unsigned char      uint8_t;
#define __int8_t_defined
#endif

#ifndef __int16_t_defined
typedef short              int16_t;
typedef unsigned short     uint16_t;
#define __int16_t_defined
#endif

#ifndef __int32_t_defined
typedef int                int32_t;
typedef unsigned int       uint32_t;
#define __int32_t_defined
#endif

#ifndef __int64_t_defined
typedef long long          int64_t;
typedef unsigned long long uint64_t;
#define __int64_t_defined
#endif

#ifndef __intptr_t_defined
#if defined(__sparc__) || defined(__i386__) || defined(__sun)
typedef long               intptr_t;
typedef unsigned long      uintptr_t;
#else
#error "Define intptr_t/uintptr_t for your architecture."
#endif
#define __intptr_t_defined
#endif

#endif /* _STDINT_H */
