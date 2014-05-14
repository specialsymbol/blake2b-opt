#ifndef CPUID_H
#define CPUID_H

#include "driver.h"

#if defined(__cplusplus)
extern "C" {
#endif

enum cpuid_flags_generic_t {
	CPUID_GENERIC   = (0      )
};

#if defined(ARCH_X86)
enum cpuid_flags_x86_t {
	CPUID_X86       = (1 <<  0),
	CPUID_MMX       = (1 <<  1),
	CPUID_SSE       = (1 <<  2),
	CPUID_SSE2      = (1 <<  3),
	CPUID_SSE3      = (1 <<  4),
	CPUID_SSSE3     = (1 <<  5),
	CPUID_SSE4_1    = (1 <<  6),
	CPUID_SSE4_2    = (1 <<  7),
	CPUID_AVX       = (1 <<  8),
	CPUID_XOP       = (1 <<  9),
	CPUID_AVX2      = (1 << 10),
	CPUID_AVX512    = (1 << 11),

	CPUID_RDRAND    = (1 << 26),
	CPUID_POPCNT    = (1 << 27),
	CPUID_FMA4      = (1 << 28),
	CPUID_FMA3      = (1 << 29),
	CPUID_PCLMULQDQ = (1 << 30),
	CPUID_AES       = (1 << 31)
};
#endif

uint32_t cpuid(void);


/* runtime dispatching based on current cpu */
typedef struct cpu_specific_impl_t {
	uint32_t cpu_flags;
	const char *desc;
	/* additional information, pointers to methods, etc... */
} cpu_specific_impl_t;

typedef int (*impl_test)(const void *impl);

const void *cpu_select(const void *impls, size_t impl_size, impl_test test_fn);


#if defined(__cplusplus)
}
#endif

#endif /* CPUID_H */
