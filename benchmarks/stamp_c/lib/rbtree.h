/* =============================================================================
 *
 * rbtree.h
 * -- Red-black balanced binary search tree
 *
 * =============================================================================
 *
 * Copyright (C) Sun Microsystems Inc., 2006.  All Rights Reserved.
 * Authors: Dave Dice, Nir Shavit, Ori Shalev.
 *
 * STM: Transactional Locking for Disjoint Access Parallelism
 *
 * Transactional Locking II,
 * Dave Dice, Ori Shalev, Nir Shavit
 * DISC 2006, Sept 2006, Stockholm, Sweden.
 *
 * =============================================================================
 *
 * Modified by Chi Cao Minh
 *
 * =============================================================================
 *
 * For the license of bayes/sort.h and bayes/sort.c, please see the header
 * of the files.
 *
 * ------------------------------------------------------------------------
 *
 * For the license of kmeans, please see kmeans/LICENSE.kmeans
 *
 * ------------------------------------------------------------------------
 *
 * For the license of ssca2, please see ssca2/COPYRIGHT
 *
 * ------------------------------------------------------------------------
 *
 * For the license of lib/mt19937ar.c and lib/mt19937ar.h, please see the
 * header of the files.
 *
 * ------------------------------------------------------------------------
 *
 * For the license of lib/rbtree.h and lib/rbtree.c, please see
 * lib/LEGALNOTICE.rbtree and lib/LICENSE.rbtree
 *
 * ------------------------------------------------------------------------
 *
 * Unless otherwise noted, the following license applies to STAMP files:
 *
 * Copyright (c) 2007, Stanford University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of Stanford University nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY STANFORD UNIVERSITY ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL STANFORD UNIVERSITY BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * =============================================================================
 */


#ifndef RBTREE_H
#define RBTREE_H 1


#include "tm.h"
#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef struct rbtree rbtree_t;


/* =============================================================================
 * rbtree_verify
 * =============================================================================
 */
long
rbtree_verify (rbtree_t* s, long verbose);


/* =============================================================================
 * rbtree_alloc
 * =============================================================================
 */
TM_SAFE
rbtree_t*
rbtree_alloc (long (*compare)(const void*, const void*));


/* =============================================================================
 * rbtree_free
 * =============================================================================
 */
TM_SAFE
void
rbtree_free (rbtree_t* r);


/* =============================================================================
 * rbtree_insert
 * -- Returns TRUE on success
 * =============================================================================
 */
TM_SAFE
bool_t
rbtree_insert (rbtree_t* r, void* key, void* val);


/* =============================================================================
 * rbtree_delete
 * =============================================================================
 */
TM_SAFE
bool_t
rbtree_delete (rbtree_t* r, void* key);


/* =============================================================================
 * rbtree_update
 * -- Return FALSE if had to insert node first
 * =============================================================================
 */
TM_SAFE
bool_t
rbtree_update (rbtree_t* r, void* key, void* val);


/* =============================================================================
 * rbtree_get
 * =============================================================================
 */
TM_SAFE
void*
rbtree_get (rbtree_t* r, void* key);


/* =============================================================================
 * rbtree_contains
 * =============================================================================
 */
TM_SAFE
bool_t
rbtree_contains (  rbtree_t* r, void* key);


#define TMRBTREE_ALLOC()          rbtree_alloc()
#define TMRBTREE_FREE(r)          rbtree_free(r)
#define TMRBTREE_INSERT(r, k, v)  rbtree_insert(r, (void*)(k), (void*)(v))
#define TMRBTREE_DELETE(r, k)     rbtree_delete(r, (void*)(k))
#define TMRBTREE_UPDATE(r, k, v)  rbtree_update(r, (void*)(k), (void*)(v))
#define TMRBTREE_GET(r, k)        rbtree_get(r, (void*)(k))
#define TMRBTREE_CONTAINS(r, k)   rbtree_contains(r, (void*)(k))


#ifdef __cplusplus
}
#endif



#endif /* RBTREE_H */



/* =============================================================================
 *
 * End of rbtree.h
 *
 * =============================================================================
 */
