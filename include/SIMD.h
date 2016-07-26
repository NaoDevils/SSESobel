/**
 * @file include/SIMD.h
 *
 * Declares some helper functions for SIMD intrinsics
 *
 * @author <A href=mailto:fabian.rensen@tu-dortmund.de>Fabian Rensen</A>
 */

#pragma once

#include <tmmintrin.h>

/**
* \brief Shifts each of the 16 8-bit integers in a bits right, shifting in zeroes.
* This function is not available in SSE3, so it emulates the function by copying the register content to
* two 16-Bit interpreted registers. _mm_srli_epi16 is then called on those two registers and the contents are wrote back
* to one register.
* \param [in] a SSE Register containing 16 8-bit integers.
* \param [in] bits Number of bits to shift the Register a.
* \return The shifted register
*/
inline __m128i _mm_srli_epi8(__m128i a, int bits)
{
  __m128i u = _mm_unpacklo_epi8(a, _mm_setzero_si128());
  __m128i v = _mm_unpackhi_epi8(a, _mm_setzero_si128());
  u = _mm_srli_epi16(u, bits);
  v = _mm_srli_epi16(v, bits);
  return _mm_packus_epi16(u, v);
}

/**
* \brief Shifts each of the 16 8-bit integers in a bits left, shifting in zeroes.
* This function is not available in SSE3, so it emulates the function by copying the register content to
* two 16-Bit interpreted registers. _mm_srli_epi16 is then called on those two registers and the contents are wrote back
* to one register.
* \param [in] a SSE Register containing 16 8-bit integers.
* \param [in] bits Number of bits to shift the Register a.
* \return The shifted register
*/
inline __m128i _mm_slli_epi8(__m128i a, int bits)
{
  __m128i u = _mm_unpacklo_epi8(a, _mm_setzero_si128());
  __m128i v = _mm_unpackhi_epi8(a, _mm_setzero_si128());
  u = _mm_slli_epi16(u, bits);
  v = _mm_slli_epi16(v, bits);
  return _mm_packus_epi16(u, v);
}
