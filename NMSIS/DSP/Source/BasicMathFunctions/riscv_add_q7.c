/* ----------------------------------------------------------------------
 * Project:      NMSIS DSP Library
 * Title:        riscv_add_q7.c
 * Description:  Q7 vector addition
 *
 * $Date:        18. March 2019
 * $Revision:    V1.6.0
 *
 * Target Processor: RISC-V cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2019 ARM Limited or its affiliates. All rights reserved.
 * Copyright (c) 2019 Nuclei Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "riscv_math.h"

/**
  @ingroup groupMath
 */

/**
  @addtogroup BasicAdd
  @{
 */

/**
  @brief         Q7 vector addition.
  @param[in]     pSrcA      points to the first input vector
  @param[in]     pSrcB      points to the second input vector
  @param[out]    pDst       points to the output vector
  @param[in]     blockSize  number of samples in each vector
  @return        none

  @par           Scaling and Overflow Behavior
                   The function uses saturating arithmetic.
                   Results outside of the allowable Q7 range [0x80 0x7F] are saturated.
 */

void riscv_add_q7(
  const q7_t * pSrcA,
  const q7_t * pSrcB,
        q7_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                               /* Loop counter */

#if defined (RISCV_MATH_LOOPUNROLL)

#ifdef RISCV_DSP64
  /* Loop unrolling: Compute 8 outputs at a time */
  blkCnt = blockSize >> 3U;
#else
	/* Loop unrolling: Compute 4 outputs at a time */
  blkCnt = blockSize >> 2U;
#endif

  while (blkCnt > 0U)
  {
    /* C = A + B */

#if defined (RISCV_MATH_DSP)

#ifdef RISCV_DSP64
    /* Add and store result in destination buffer (4 samples at a time). */
    write_q7x8_ia (&pDst, __DQADD8 (read_q7x8_ia ((q7_t **) &pSrcA), read_q7x8_ia ((q7_t **) &pSrcB)));
#else
	  write_q7x4_ia (&pDst, __QADD8 (read_q7x4_ia ((q7_t **) &pSrcA), read_q7x4_ia ((q7_t **) &pSrcB)));
#endif

#else
	*pDst++ = (q7_t) __SSAT((q15_t) *pSrcA++ + *pSrcB++, 8);
    *pDst++ = (q7_t) __SSAT((q15_t) *pSrcA++ + *pSrcB++, 8);
    *pDst++ = (q7_t) __SSAT((q15_t) *pSrcA++ + *pSrcB++, 8);
    *pDst++ = (q7_t) __SSAT((q15_t) *pSrcA++ + *pSrcB++, 8);
#endif

    /* Decrement loop counter */
    blkCnt--;
  }

#ifdef RISCV_DSP64
  /* Loop unrolling: Compute remaining outputs */
  blkCnt = blockSize % 0x8U;
#else
	blkCnt = blockSize % 0x4U;
#endif

#else

  /* Initialize blkCnt with number of samples */
  blkCnt = blockSize;

#endif /* #if defined (RISCV_MATH_LOOPUNROLL) */

  while (blkCnt > 0U)
  {
    /* C = A + B */

    /* Add and store result in destination buffer. */
    *pDst++ = (q7_t) __SSAT((q15_t) *pSrcA++ + *pSrcB++, 8);

    /* Decrement loop counter */
    blkCnt--;
  }

}

/**
  @} end of BasicAdd group
 */
