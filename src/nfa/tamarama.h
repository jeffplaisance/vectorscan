/*
 * Copyright (c) 2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Intel Corporation nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TAMARAMA_H
#define TAMARAMA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "callback.h"
#include "ue2common.h"

struct mq;
struct NFA;
struct hs_scratch;

char nfaExecTamarama0_testEOD(const struct NFA *n, const char *state,
                              const char *streamState, u64a offset,
                              NfaCallback callback, void *context);
char nfaExecTamarama0_QR(const struct NFA *n, struct mq *q, ReportID report);
char nfaExecTamarama0_reportCurrent(const struct NFA *n, struct mq *q);
char nfaExecTamarama0_inAccept(const struct NFA *n, ReportID report,
                               struct mq *q);
char nfaExecTamarama0_inAnyAccept(const struct NFA *n, struct mq *q);
char nfaExecTamarama0_queueInitState(const struct NFA *n, struct mq *q);
char nfaExecTamarama0_queueCompressState(const struct NFA *n,
                                         const struct mq *q,
                                         s64a loc);
char nfaExecTamarama0_expandState(const struct NFA *n, void *dest,
                                  const void *src, u64a offset, u8 key);
enum nfa_zombie_status nfaExecTamarama0_zombie_status(const struct NFA *n,
                                                      struct mq *q, s64a loc);
char nfaExecTamarama0_Q(const struct NFA *nfa, struct mq *q, s64a end);
char nfaExecTamarama0_Q2(const struct NFA *nfa, struct mq *q, s64a end);

// only used by outfix and miracles, no implementation for tamarama
#define nfaExecTamarama0_initCompressedState NFA_API_NO_IMPL
#define nfaExecTamarama0_B_Reverse NFA_API_NO_IMPL

#ifdef __cplusplus
}
#endif

#endif