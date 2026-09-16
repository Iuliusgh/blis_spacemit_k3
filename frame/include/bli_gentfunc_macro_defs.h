/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin
   Copyright (C) 2023, Southern Methodist University

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name(s) of the copyright holder(s) nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#ifndef BLIS_GENTFUNC_MACRO_DEFS_H
#define BLIS_GENTFUNC_MACRO_DEFS_H

//
// -- MACROS TO INSERT FUNCTION-GENERATING MACROS ------------------------------
//



// -- Macros for generating BLAS routines --------------------------------------


// -- Basic one-operand macro --


#define INSERT_GENTFUNC_BLAS( blasname, blisname ) \
\
GENTFUNC( _Float16, h, blasname, blisname ) \
GENTFUNC( float,    s, blasname, blisname ) \
GENTFUNC( double,   d, blasname, blisname ) \
GENTFUNC( hcomplex, y, blasname, blisname ) \
GENTFUNC( scomplex, c, blasname, blisname ) \
GENTFUNC( dcomplex, z, blasname, blisname )


// -- Basic one-operand macro with real domain only --


#define INSERT_GENTFUNCRO_BLAS( blasname, blisname ) \
\
GENTFUNCRO( _Float16, h, blasname, blisname ) \
GENTFUNCRO( float,    s, blasname, blisname ) \
GENTFUNCRO( double,   d, blasname, blisname )


// -- Basic one-operand macro with complex domain only and real projection --


#define INSERT_GENTFUNCCO_BLAS( blasname, blisname ) \
\
GENTFUNCCO( hcomplex, _Float16, y, h, blasname, blisname ) \
GENTFUNCCO( scomplex, float,    c, s, blasname, blisname ) \
GENTFUNCCO( dcomplex, double,   z, d, blasname, blisname )


// -- Basic one-operand macro with conjugation (real funcs only, used only for dot, ger) --


#define INSERT_GENTFUNCDOTR_BLAS( blasname, blisname ) \
\
GENTFUNCDOT( _Float16, h, , BLIS_NO_CONJUGATE, blasname, blisname ) \
GENTFUNCDOT( float,    s, , BLIS_NO_CONJUGATE, blasname, blisname ) \
GENTFUNCDOT( double,   d, , BLIS_NO_CONJUGATE, blasname, blisname )


// -- Basic one-operand macro with conjugation (complex funcs only, used only for dot, ger) --


#define INSERT_GENTFUNCDOTC_BLAS( blasname, blisname ) \
\
GENTFUNCDOT( hcomplex, y, y, BLIS_CONJUGATE,   blasname, blisname ) \
GENTFUNCDOT( hcomplex, y, u, BLIS_NO_CONJUGATE, blasname, blisname ) \
GENTFUNCDOT( scomplex, c, c, BLIS_CONJUGATE,   blasname, blisname ) \
GENTFUNCDOT( scomplex, c, u, BLIS_NO_CONJUGATE, blasname, blisname ) \
GENTFUNCDOT( dcomplex, z, c, BLIS_CONJUGATE,    blasname, blisname ) \
GENTFUNCDOT( dcomplex, z, u, BLIS_NO_CONJUGATE, blasname, blisname )


// -- Basic one-operand macro with conjugation (used only for dot, ger) --


#define INSERT_GENTFUNCDOT_BLAS( blasname, blisname ) \
\
INSERT_GENTFUNCDOTR_BLAS( blasname, blisname ) \
INSERT_GENTFUNCDOTC_BLAS( blasname, blisname )


// -- Basic one-operand macro with real projection --


#define INSERT_GENTFUNCR_BLAS( rblasname, cblasname, blisname ) \
\
GENTFUNCR( _Float16, _Float16, h, h, rblasname, blisname ) \
GENTFUNCR( float,    float,    s, s, rblasname, blisname ) \
GENTFUNCR( double,   double,   d, d, rblasname, blisname ) \
GENTFUNCR( hcomplex, _Float16, y, h, cblasname, blisname ) \
GENTFUNCR( scomplex, float,    c, s, cblasname, blisname ) \
GENTFUNCR( dcomplex, double,   z, d, cblasname, blisname )


// -- Alternate two-operand macro (one char for complex, one for real proj) --


#define INSERT_GENTFUNCR2_BLAS( blasname, blisname ) \
\
GENTFUNCR2( _Float16, _Float16, h,  , blasname, blisname ) \
GENTFUNCR2( float,    float,    s,  , blasname, blisname ) \
GENTFUNCR2( double,   double,   d,  , blasname, blisname ) \
GENTFUNCR2( hcomplex, _Float16, y, h, blasname, blisname ) \
GENTFUNCR2( scomplex, float,    c, s, blasname, blisname ) \
GENTFUNCR2( dcomplex, double,   z, d, blasname, blisname )


// -- Extended two-operand macro (used only for scal) --


#define INSERT_GENTFUNCSCAL_BLAS( blasname, blisname ) \
\
GENTFUNCSCAL( _Float16, _Float16, h,  , h, blasname, blisname ) \
GENTFUNCSCAL( float,    float,    s,  , s, blasname, blisname ) \
GENTFUNCSCAL( double,   double,   d,  , d, blasname, blisname ) \
GENTFUNCSCAL( hcomplex, hcomplex, y,  , y, blasname, blisname ) \
GENTFUNCSCAL( scomplex, scomplex, c,  , c, blasname, blisname ) \
GENTFUNCSCAL( dcomplex, dcomplex, z,  , z, blasname, blisname ) \
GENTFUNCSCAL( hcomplex, _Float16, y, h, h, blasname, blisname ) \
GENTFUNCSCAL( scomplex, float,    c, s, s, blasname, blisname ) \
GENTFUNCSCAL( dcomplex, double,   z, d, d, blasname, blisname )




// -- Macros for functions with one operand ------------------------------------


// -- Basic one-operand macro --

#define INSERT_GENTFUNC_BASIC( ... ) \
\
GENTFUNC( _Float16, h, __VA_ARGS__ ) \
GENTFUNC( float,    s, __VA_ARGS__ ) \
GENTFUNC( double,   d, __VA_ARGS__ ) \
GENTFUNC( hcomplex, y, __VA_ARGS__ ) \
GENTFUNC( scomplex, c, __VA_ARGS__ ) \
GENTFUNC( dcomplex, z, __VA_ARGS__ )



// -- Basic one-operand with real projection --

#define INSERT_GENTFUNCR_BASIC( ... ) \
\
GENTFUNCR( _Float16, _Float16, h, h, __VA_ARGS__ ) \
GENTFUNCR( float,    float,    s, s, __VA_ARGS__ ) \
GENTFUNCR( double,   double,   d, d, __VA_ARGS__ ) \
GENTFUNCR( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
GENTFUNCR( scomplex, float,    c, s, __VA_ARGS__ ) \
GENTFUNCR( dcomplex, double,   z, d, __VA_ARGS__ )



// -- Basic one-operand macro with real domain only --

#define INSERT_GENTFUNCRO_BASIC( ... ) \
\
GENTFUNCRO( _Float16, h, __VA_ARGS__ ) \
GENTFUNCRO( float,    s, __VA_ARGS__ ) \
GENTFUNCRO( double,   d, __VA_ARGS__ )

// -- Basic one-operand macro with complex domain only --

#define INSERT_GENTFUNCCO_BASIC( ... ) \
\
GENTFUNCCO( hcomplex, y,  __VA_ARGS__ ) \
GENTFUNCCO( scomplex, c,  __VA_ARGS__ ) \
GENTFUNCCO( dcomplex, z,  __VA_ARGS__ )

// -- Basic one-operand macro with real domain only and complex projection --

#define INSERT_GENTFUNCRO( ... ) \
\
GENTFUNCRO( _Float16, hcomplex, h, y, __VA_ARGS__ ) \
GENTFUNCRO( float,    scomplex, s, c, __VA_ARGS__ ) \
GENTFUNCRO( double,   dcomplex, d, z, __VA_ARGS__ )

// -- Basic one-operand macro with complex domain only and real projection --

#define INSERT_GENTFUNCCO( ... ) \
\
GENTFUNCCO( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
GENTFUNCCO( scomplex, float,    c, s, __VA_ARGS__ ) \
GENTFUNCCO( dcomplex, double,   z, d, __VA_ARGS__ )



// -- Basic one-operand macro with integer instance --

#define INSERT_GENTFUNC_BASIC_I( ... ) \
\
GENTFUNC( _Float16, h, __VA_ARGS__ ) \
GENTFUNC( float,    s, __VA_ARGS__ ) \
GENTFUNC( double,   d, __VA_ARGS__ ) \
GENTFUNC( hcomplex, y, __VA_ARGS__ ) \
GENTFUNC( scomplex, c, __VA_ARGS__ ) \
GENTFUNC( dcomplex, z, __VA_ARGS__ ) \
GENTFUNC( gint_t,   i, __VA_ARGS__ )



// -- Basic one-operand with integer projection --

#define INSERT_GENTFUNCI_BASIC( ... ) \
\
GENTFUNCI( _Float16, gint_t, h, i, __VA_ARGS__ ) \
GENTFUNCI( float,    gint_t, s, i, __VA_ARGS__ ) \
GENTFUNCI( double,   gint_t, d, i, __VA_ARGS__ ) \
GENTFUNCI( hcomplex, gint_t, y, i, __VA_ARGS__ ) \
GENTFUNCI( scomplex, gint_t, c, i, __VA_ARGS__ ) \
GENTFUNCI( dcomplex, gint_t, z, i, __VA_ARGS__ )



// -- Basic one-operand with real and integer projections --

#define INSERT_GENTFUNCRI_BASIC( ... ) \
\
GENTFUNCRI( _Float16, _Float16, gint_t, h, h, i, __VA_ARGS__ ) \
GENTFUNCRI( float,    float,    gint_t, s, s, i, __VA_ARGS__ ) \
GENTFUNCRI( double,   double,   gint_t, d, d, i, __VA_ARGS__ ) \
GENTFUNCRI( hcomplex, _Float16, gint_t, y, h, i, __VA_ARGS__ ) \
GENTFUNCRI( scomplex, float,    gint_t, c, s, i, __VA_ARGS__ ) \
GENTFUNCRI( dcomplex, double,   gint_t, z, d, i, __VA_ARGS__ )




// -- Macros for functions with two primary operands ---------------------------


// -- Basic two-operand macro --

#define INSERT_GENTFUNC2_BASIC( ... ) \
\
GENTFUNC2( _Float16, _Float16, h, h, __VA_ARGS__ ) \
GENTFUNC2( float,    float,    s, s, __VA_ARGS__ ) \
GENTFUNC2( double,   double,   d, d, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, hcomplex, y, y, __VA_ARGS__ ) \
GENTFUNC2( scomplex, scomplex, c, c, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, dcomplex, z, z, __VA_ARGS__ )



// -- Mixed domain two-operand macro --

#define INSERT_GENTFUNC2_MIX_D( ... ) \
\
GENTFUNC2( _Float16, hcomplex, h, y, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
\
GENTFUNC2( float,    scomplex, s, c, __VA_ARGS__ ) \
GENTFUNC2( scomplex, float,    c, s, __VA_ARGS__ ) \
\
GENTFUNC2( double,   dcomplex, d, z, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, double,   z, d, __VA_ARGS__ )



// -- Mixed precision two-operand macro --

#define INSERT_GENTFUNC2_MIX_P( ... ) \
\
GENTFUNC2( _Float16, float,    h, s, __VA_ARGS__ ) \
GENTFUNC2( _Float16, double,   h, d, __VA_ARGS__ ) \
GENTFUNC2( float,    _Float16, s, h, __VA_ARGS__ ) \
GENTFUNC2( float,    double,   s, d, __VA_ARGS__ ) \
GENTFUNC2( double,   _Float16, d, h, __VA_ARGS__ ) \
GENTFUNC2( double,   float,    d, s, __VA_ARGS__ ) \
\
GENTFUNC2( hcomplex, scomplex, y, c, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, dcomplex, y, z, __VA_ARGS__ ) \
GENTFUNC2( scomplex, hcomplex, c, y, __VA_ARGS__ ) \
GENTFUNC2( scomplex, dcomplex, c, z, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, hcomplex, z, y, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, scomplex, z, c, __VA_ARGS__ )



// -- Mixed domain/precision (all) two-operand macro --

#define INSERT_GENTFUNC2_MIX_DP( ... ) \
\
GENTFUNC2( _Float16, float,    h, s, __VA_ARGS__ ) \
GENTFUNC2( _Float16, double,   h, d, __VA_ARGS__ ) \
GENTFUNC2( _Float16, hcomplex, h, y, __VA_ARGS__ ) \
GENTFUNC2( _Float16, scomplex, h, c, __VA_ARGS__ ) \
GENTFUNC2( _Float16, dcomplex, h, z, __VA_ARGS__ ) \
\
GENTFUNC2( float,    _Float16, s, h, __VA_ARGS__ ) \
GENTFUNC2( float,    double,   s, d, __VA_ARGS__ ) \
GENTFUNC2( float,    hcomplex, s, y, __VA_ARGS__ ) \
GENTFUNC2( float,    scomplex, s, c, __VA_ARGS__ ) \
GENTFUNC2( float,    dcomplex, s, z, __VA_ARGS__ ) \
\
GENTFUNC2( double,   _Float16, d, h, __VA_ARGS__ ) \
GENTFUNC2( double,   float,    d, s, __VA_ARGS__ ) \
GENTFUNC2( double,   hcomplex, d, y, __VA_ARGS__ ) \
GENTFUNC2( double,   scomplex, d, c, __VA_ARGS__ ) \
GENTFUNC2( double,   dcomplex, d, z, __VA_ARGS__ ) \
\
GENTFUNC2( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, float,    y, s, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, double,   y, d, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, scomplex, y, c, __VA_ARGS__ ) \
GENTFUNC2( hcomplex, dcomplex, y, z, __VA_ARGS__ ) \
\
GENTFUNC2( scomplex, _Float16, c, h, __VA_ARGS__ ) \
GENTFUNC2( scomplex, float,    c, s, __VA_ARGS__ ) \
GENTFUNC2( scomplex, double,   c, d, __VA_ARGS__ ) \
GENTFUNC2( scomplex, hcomplex, c, y, __VA_ARGS__ ) \
GENTFUNC2( scomplex, dcomplex, c, z, __VA_ARGS__ ) \
\
GENTFUNC2( dcomplex, _Float16, z, h, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, float,    z, s, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, double,   z, d, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, hcomplex, z, y, __VA_ARGS__ ) \
GENTFUNC2( dcomplex, scomplex, z, c, __VA_ARGS__ )



// -- Basic two-operand with real projection of second operand --

#define INSERT_GENTFUNC2R_BASIC( ... ) \
\
GENTFUNC2R( _Float16, _Float16, _Float16, h, h, h, __VA_ARGS__ ) \
GENTFUNC2R( float,    float,    float,    s, s, s, __VA_ARGS__ ) \
GENTFUNC2R( double,   double,   double,   d, d, d, __VA_ARGS__ ) \
GENTFUNC2R( hcomplex, hcomplex, _Float16, y, y, h, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, scomplex, float,    c, c, s, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, dcomplex, double,   z, z, d, __VA_ARGS__ )



// -- Mixed domain two-operand with real projection of second operand --

#define INSERT_GENTFUNC2R_MIX_D( ... ) \
\
GENTFUNC2R( _Float16, hcomplex, _Float16, h, y, h, __VA_ARGS__ ) \
GENTFUNC2R( hcomplex, _Float16, _Float16, y, h, h, __VA_ARGS__ ) \
\
GENTFUNC2R( float,    scomplex, float, s, c, s, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, float,    float, c, s, s, __VA_ARGS__ ) \
\
GENTFUNC2R( double,   dcomplex, double, d, z, d, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, double,   double, z, d, d, __VA_ARGS__ )



// -- Mixed precision two-operand with real projection of second operand --

#define INSERT_GENTFUNC2R_MIX_P( ... ) \
\
GENTFUNC2R( _Float16, float,    float,    h, s, s, __VA_ARGS__ ) \
GENTFUNC2R( _Float16, double,   double,   h, d, d, __VA_ARGS__ ) \
GENTFUNC2R( float,    _Float16, _Float16, s, h, h, __VA_ARGS__ ) \
GENTFUNC2R( float,    double,   double,   s, d, d, __VA_ARGS__ ) \
GENTFUNC2R( double,   _Float16, _Float16, d, h, h, __VA_ARGS__ ) \
GENTFUNC2R( double,   float,    float,    d, s, s, __VA_ARGS__ ) \
\
GENTFUNC2R( hcomplex, scomplex, float,    y, c, s, __VA_ARGS__ ) \
GENTFUNC2R( hcomplex, dcomplex, double,   y, z, d, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, hcomplex, _Float16, c, y, h, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, dcomplex, double,   c, z, d, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, hcomplex, _Float16, z, y, h, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, scomplex, float,    z, c, s, __VA_ARGS__ )



// -- Real-only two-operand with complex projection of both operands --

#define INSERT_GENTFUNC2RO( ... ) \
\
GENTFUNC2RO( _Float16, hcomplex, _Float16, hcomplex, h, y, h, y, __VA_ARGS__ ) \
GENTFUNC2RO( float,    scomplex, float,    scomplex, s, c, s, c, __VA_ARGS__ ) \
GENTFUNC2RO( double,   dcomplex, double,   dcomplex, d, z, d, z, __VA_ARGS__ )



// -- Mixed precision real-only two-operand with complex projection of both operands --

#define INSERT_GENTFUNC2RO_MIX_P( ... ) \
\
GENTFUNC2RO( _Float16, hcomplex, float,    scomplex, h, y, s, c, __VA_ARGS__ ) \
GENTFUNC2RO( _Float16, hcomplex, double,   dcomplex, h, y, d, z, __VA_ARGS__ ) \
GENTFUNC2RO( float,    scomplex, _Float16, hcomplex, s, c, h, y, __VA_ARGS__ ) \
GENTFUNC2RO( float,    scomplex, double,   dcomplex, s, c, d, z, __VA_ARGS__ ) \
GENTFUNC2RO( double,   dcomplex, _Float16, hcomplex, d, z, h, y, __VA_ARGS__ ) \
GENTFUNC2RO( double,   dcomplex, float,    scomplex, d, z, s, c, __VA_ARGS__ )



// -- Mixed domain/precision (all) two-operand macro with real projection of second operand --

#define INSERT_GENTFUNC2R_MIX_DP( ... ) \
\
GENTFUNC2R( _Float16, float,    float,    h, s, s, __VA_ARGS__ ) \
GENTFUNC2R( _Float16, double,   double,   h, d, d, __VA_ARGS__ ) \
GENTFUNC2R( _Float16, hcomplex, _Float16, h, y, h, __VA_ARGS__ ) \
GENTFUNC2R( _Float16, scomplex, float,    h, c, s, __VA_ARGS__ ) \
GENTFUNC2R( _Float16, dcomplex, double,   h, z, d, __VA_ARGS__ ) \
\
GENTFUNC2R( float,    _Float16, _Float16, s, h, h, __VA_ARGS__ ) \
GENTFUNC2R( float,    double,   double,   s, d, d, __VA_ARGS__ ) \
GENTFUNC2R( float,    hcomplex, _Float16, s, y, h, __VA_ARGS__ ) \
GENTFUNC2R( float,    scomplex, float,    s, c, s, __VA_ARGS__ ) \
GENTFUNC2R( float,    dcomplex, double,   s, z, d, __VA_ARGS__ ) \
\
GENTFUNC2R( double,   _Float16, _Float16, d, h, h, __VA_ARGS__ ) \
GENTFUNC2R( double,   float,    float,    d, s, s, __VA_ARGS__ ) \
GENTFUNC2R( double,   hcomplex, _Float16, d, y, h, __VA_ARGS__ ) \
GENTFUNC2R( double,   scomplex, float,    d, c, s, __VA_ARGS__ ) \
GENTFUNC2R( double,   dcomplex, double,   d, z, d, __VA_ARGS__ ) \
\
GENTFUNC2R( homplex, _Float16, _Float16, y, h, h, __VA_ARGS__ ) \
GENTFUNC2R( homplex, float,    float,    y, s, s, __VA_ARGS__ ) \
GENTFUNC2R( homplex, double,   double,   y, d, d, __VA_ARGS__ ) \
GENTFUNC2R( homplex, scomplex, float,    y, c, s, __VA_ARGS__ ) \
GENTFUNC2R( homplex, dcomplex, double,   y, z, d, __VA_ARGS__ ) \
\
GENTFUNC2R( scomplex, _Float16, _Float16, c, h, h, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, float,    float,    c, s, s, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, double,   double,   c, d, d, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, hcomplex, _Float16, c, y, h, __VA_ARGS__ ) \
GENTFUNC2R( scomplex, dcomplex, double,   c, z, d, __VA_ARGS__ ) \
\
GENTFUNC2R( dcomplex, _Float16, _Float16, z, h, h, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, float,    float,    z, s, s, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, double,   double,   z, d, d, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, hcomplex, _Float16, z, y, h, __VA_ARGS__ ) \
GENTFUNC2R( dcomplex, scomplex, float,    z, c, s, __VA_ARGS__ )




// -- Macros for functions with three primary operands -------------------------


// -- Basic three-operand macro --

#define INSERT_GENTFUNC3_BASIC( ... ) \
\
GENTFUNC3( _Float16, _Float16, _Float16, h, h, h, __VA_ARGS__ ) \
GENTFUNC3( float,    float,    float,    s, s, s, __VA_ARGS__ ) \
GENTFUNC3( double,   double,   double,   d, d, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, hcomplex, hcomplex, y, y, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, scomplex, scomplex, c, c, c, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, dcomplex, dcomplex, z, z, z, __VA_ARGS__ )



// -- Mixed domain three-operand macro --

#define INSERT_GENTFUNC3_MIX_D( ... ) \
\
GENTFUNC3( _Float16, _Float16, hcomplex, h, h, y, __VA_ARGS__ ) \
GENTFUNC3( _Float16, hcomplex, _Float16, h, y, h, __VA_ARGS__ ) \
GENTFUNC3( _Float16, hcomplex, hcomplex, h, y, y, __VA_ARGS__ ) \
\
GENTFUNC3( float,    float,    scomplex, s, s, c, __VA_ARGS__ ) \
GENTFUNC3( float,    scomplex, float,    s, c, s, __VA_ARGS__ ) \
GENTFUNC3( float,    scomplex, scomplex, s, c, c, __VA_ARGS__ ) \
\
GENTFUNC3( double,   double,   dcomplex, d, d, z, __VA_ARGS__ ) \
GENTFUNC3( double,   dcomplex, double,   d, z, d, __VA_ARGS__ ) \
GENTFUNC3( double,   dcomplex, dcomplex, d, z, z, __VA_ARGS__ ) \
\
GENTFUNC3( hcomplex, _Float16, _Float16, y, h, h, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, _Float16, hcomplex, y, h, y, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, hcomplex, _Float16, y, y, h, __VA_ARGS__ ) \
\
GENTFUNC3( scomplex, float,    float,    c, s, s, __VA_ARGS__ ) \
GENTFUNC3( scomplex, float,    scomplex, c, s, c, __VA_ARGS__ ) \
GENTFUNC3( scomplex, scomplex, float,    c, c, s, __VA_ARGS__ ) \
\
GENTFUNC3( dcomplex, double,   double,   z, d, d, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, double,   dcomplex, z, d, z, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, dcomplex, double,   z, z, d, __VA_ARGS__ )



// -- Mixed precision three-operand macro --

#define INSERT_GENTFUNC3_MIX_P( ... ) \
\
GENTFUNC3( _Float16, _Float16, float,    h, h, s, __VA_ARGS__ ) \
GENTFUNC3( _Float16, _Float16, double,   h, h, d, __VA_ARGS__ ) \
GENTFUNC3( _Float16, _Float16, scomplex, h, h, c, __VA_ARGS__ ) \
GENTFUNC3( _Float16, _Float16, dcomplex, h, h, z, __VA_ARGS__ ) \
\
GENTFUNC3( _Float16, float,    _Float16, h, s, h, __VA_ARGS__ ) \
GENTFUNC3( _Float16, float,    float,    h, s, s, __VA_ARGS__ ) \
GENTFUNC3( _Float16, float,    double,   h, s, d, __VA_ARGS__ ) \
GENTFUNC3( _Float16, float,    hcomplex, h, s, y, __VA_ARGS__ ) \
GENTFUNC3( _Float16, float,    scomplex, h, s, c, __VA_ARGS__ ) \
GENTFUNC3( _Float16, float,    dcomplex, h, s, z, __VA_ARGS__ ) \
\
GENTFUNC3( _Float16, double,   _Float16, h, d, h, __VA_ARGS__ ) \
GENTFUNC3( _Float16, double,   float,    h, d, s, __VA_ARGS__ ) \
GENTFUNC3( _Float16, double,   double,   h, d, d, __VA_ARGS__ ) \
GENTFUNC3( _Float16, double,   hcomplex, h, d, y, __VA_ARGS__ ) \
GENTFUNC3( _Float16, double,   scomplex, h, d, c, __VA_ARGS__ ) \
GENTFUNC3( _Float16, double,   dcomplex, h, d, z, __VA_ARGS__ ) \
\
GENTFUNC3( _Float16, hcomplex, float,    h, y, s, __VA_ARGS__ ) \
GENTFUNC3( _Float16, hcomplex, double,   h, y, d, __VA_ARGS__ ) \
GENTFUNC3( _Float16, hcomplex, scomplex, h, y, c, __VA_ARGS__ ) \
GENTFUNC3( _Float16, hcomplex, dcomplex, h, y, z, __VA_ARGS__ ) \
\
GENTFUNC3( _Float16, scomplex, _Float16, h, c, h, __VA_ARGS__ ) \
GENTFUNC3( _Float16, scomplex, float,    h, c, s, __VA_ARGS__ ) \
GENTFUNC3( _Float16, scomplex, double,   h, c, d, __VA_ARGS__ ) \
GENTFUNC3( _Float16, scomplex, hcomplex, h, c, y, __VA_ARGS__ ) \
GENTFUNC3( _Float16, scomplex, scomplex, h, c, c, __VA_ARGS__ ) \
GENTFUNC3( _Float16, scomplex, dcomplex, h, c, z, __VA_ARGS__ ) \
\
GENTFUNC3( _Float16, dcomplex, _Float16, h, z, h, __VA_ARGS__ ) \
GENTFUNC3( _Float16, dcomplex, float,    h, z, s, __VA_ARGS__ ) \
GENTFUNC3( _Float16, dcomplex, double,   h, z, d, __VA_ARGS__ ) \
GENTFUNC3( _Float16, dcomplex, hcomplex, h, z, y, __VA_ARGS__ ) \
GENTFUNC3( _Float16, dcomplex, scomplex, h, z, c, __VA_ARGS__ ) \
GENTFUNC3( _Float16, dcomplex, dcomplex, h, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3( float,    _Float16, _Float16, s, h, h, __VA_ARGS__ ) \
GENTFUNC3( float,    _Float16, float,    s, h, s, __VA_ARGS__ ) \
GENTFUNC3( float,    _Float16, double,   s, h, d, __VA_ARGS__ ) \
GENTFUNC3( float,    _Float16, hcomplex, s, h, y, __VA_ARGS__ ) \
GENTFUNC3( float,    _Float16, scomplex, s, h, c, __VA_ARGS__ ) \
GENTFUNC3( float,    _Float16, dcomplex, s, h, z, __VA_ARGS__ ) \
\
GENTFUNC3( float,    float,    _Float16, s, s, h, __VA_ARGS__ ) \
GENTFUNC3( float,    float,    double,   s, s, d, __VA_ARGS__ ) \
GENTFUNC3( float,    float,    hcomplex, s, s, y, __VA_ARGS__ ) \
GENTFUNC3( float,    float,    dcomplex, s, s, z, __VA_ARGS__ ) \
\
GENTFUNC3( float,    double,   _Float16, s, d, h, __VA_ARGS__ ) \
GENTFUNC3( float,    double,   float,    s, d, s, __VA_ARGS__ ) \
GENTFUNC3( float,    double,   double,   s, d, d, __VA_ARGS__ ) \
GENTFUNC3( float,    double,   hcomplex, s, d, y, __VA_ARGS__ ) \
GENTFUNC3( float,    double,   scomplex, s, d, c, __VA_ARGS__ ) \
GENTFUNC3( float,    double,   dcomplex, s, d, z, __VA_ARGS__ ) \
\
GENTFUNC3( float,    hcomplex, _Float16, s, y, h, __VA_ARGS__ ) \
GENTFUNC3( float,    hcomplex, float,    s, y, s, __VA_ARGS__ ) \
GENTFUNC3( float,    hcomplex, double,   s, y, d, __VA_ARGS__ ) \
GENTFUNC3( float,    hcomplex, hcomplex, s, y, y, __VA_ARGS__ ) \
GENTFUNC3( float,    hcomplex, scomplex, s, y, c, __VA_ARGS__ ) \
GENTFUNC3( float,    hcomplex, dcomplex, s, y, z, __VA_ARGS__ ) \
\
GENTFUNC3( float,    scomplex, _Float16, s, c, h, __VA_ARGS__ ) \
GENTFUNC3( float,    scomplex, double,   s, c, d, __VA_ARGS__ ) \
GENTFUNC3( float,    scomplex, hcomplex, s, c, y, __VA_ARGS__ ) \
GENTFUNC3( float,    scomplex, dcomplex, s, c, z, __VA_ARGS__ ) \
\
GENTFUNC3( float,    dcomplex, _Float16, s, z, h, __VA_ARGS__ ) \
GENTFUNC3( float,    dcomplex, float,    s, z, s, __VA_ARGS__ ) \
GENTFUNC3( float,    dcomplex, double,   s, z, d, __VA_ARGS__ ) \
GENTFUNC3( float,    dcomplex, hcomplex, s, z, y, __VA_ARGS__ ) \
GENTFUNC3( float,    dcomplex, scomplex, s, z, c, __VA_ARGS__ ) \
GENTFUNC3( float,    dcomplex, dcomplex, s, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3( double,   _Float16, _Float16, d, h, h, __VA_ARGS__ ) \
GENTFUNC3( double,   _Float16, float,    d, h, s, __VA_ARGS__ ) \
GENTFUNC3( double,   _Float16, double,   d, h, d, __VA_ARGS__ ) \
GENTFUNC3( double,   _Float16, hcomplex, d, h, y, __VA_ARGS__ ) \
GENTFUNC3( double,   _Float16, scomplex, d, h, c, __VA_ARGS__ ) \
GENTFUNC3( double,   _Float16, dcomplex, d, h, z, __VA_ARGS__ ) \
\
GENTFUNC3( double,   float,    _Float16, d, s, h, __VA_ARGS__ ) \
GENTFUNC3( double,   float,    float,    d, s, s, __VA_ARGS__ ) \
GENTFUNC3( double,   float,    double,   d, s, d, __VA_ARGS__ ) \
GENTFUNC3( double,   float,    hcomplex, d, s, y, __VA_ARGS__ ) \
GENTFUNC3( double,   float,    scomplex, d, s, c, __VA_ARGS__ ) \
GENTFUNC3( double,   float,    dcomplex, d, s, z, __VA_ARGS__ ) \
\
GENTFUNC3( double,   double,   _Float16, d, d, h, __VA_ARGS__ ) \
GENTFUNC3( double,   double,   float,    d, d, s, __VA_ARGS__ ) \
GENTFUNC3( double,   double,   hcomplex, d, d, y, __VA_ARGS__ ) \
GENTFUNC3( double,   double,   scomplex, d, d, c, __VA_ARGS__ ) \
\
GENTFUNC3( double,   hcomplex, _Float16, d, y, h, __VA_ARGS__ ) \
GENTFUNC3( double,   hcomplex, float,    d, y, s, __VA_ARGS__ ) \
GENTFUNC3( double,   hcomplex, double,   d, y, d, __VA_ARGS__ ) \
GENTFUNC3( double,   hcomplex, hcomplex, d, y, y, __VA_ARGS__ ) \
GENTFUNC3( double,   hcomplex, scomplex, d, y, c, __VA_ARGS__ ) \
GENTFUNC3( double,   hcomplex, dcomplex, d, y, z, __VA_ARGS__ ) \
\
GENTFUNC3( double,   scomplex, _Float16, d, c, h, __VA_ARGS__ ) \
GENTFUNC3( double,   scomplex, float,    d, c, s, __VA_ARGS__ ) \
GENTFUNC3( double,   scomplex, double,   d, c, d, __VA_ARGS__ ) \
GENTFUNC3( double,   scomplex, hcomplex, d, c, y, __VA_ARGS__ ) \
GENTFUNC3( double,   scomplex, scomplex, d, c, c, __VA_ARGS__ ) \
GENTFUNC3( double,   scomplex, dcomplex, d, c, z, __VA_ARGS__ ) \
\
GENTFUNC3( double,   dcomplex, _Float16, d, z, h, __VA_ARGS__ ) \
GENTFUNC3( double,   dcomplex, float,    d, z, s, __VA_ARGS__ ) \
GENTFUNC3( double,   dcomplex, hcomplex, d, z, y, __VA_ARGS__ ) \
GENTFUNC3( double,   dcomplex, scomplex, d, z, c, __VA_ARGS__ ) \
\
\
GENTFUNC3( hcomplex, _Float16, float,    y, h, s, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, _Float16, double,   y, h, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, _Float16, scomplex, y, h, c, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, _Float16, dcomplex, y, h, z, __VA_ARGS__ ) \
\
GENTFUNC3( hcomplex, float,    _Float16, y, s, h, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, float,    float,    y, s, s, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, float,    double,   y, s, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, float,    hcomplex, y, s, y, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, float,    scomplex, y, s, c, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, float,    dcomplex, y, s, z, __VA_ARGS__ ) \
\
GENTFUNC3( hcomplex, double,   _Float16, y, d, h, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, double,   float,    y, d, s, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, double,   double,   y, d, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, double,   hcomplex, y, d, y, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, double,   scomplex, y, d, c, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, double,   dcomplex, y, d, z, __VA_ARGS__ ) \
\
GENTFUNC3( hcomplex, hcomplex, float,    y, y, s, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, hcomplex, double,   y, y, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, hcomplex, scomplex, y, y, c, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, hcomplex, dcomplex, y, y, z, __VA_ARGS__ ) \
\
GENTFUNC3( hcomplex, scomplex, _Float16, y, c, h, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, scomplex, float,    y, c, s, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, scomplex, double,   y, c, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, scomplex, hcomplex, y, c, y, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, scomplex, scomplex, y, c, c, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, scomplex, dcomplex, y, c, z, __VA_ARGS__ ) \
\
GENTFUNC3( hcomplex, dcomplex, _Float16, y, z, h, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, dcomplex, float,    y, z, s, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, dcomplex, double,   y, z, d, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, dcomplex, hcomplex, y, z, y, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, dcomplex, scomplex, y, z, c, __VA_ARGS__ ) \
GENTFUNC3( hcomplex, dcomplex, dcomplex, y, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3( scomplex, _Float16, _Float16, c, h, h, __VA_ARGS__ ) \
GENTFUNC3( scomplex, _Float16, float,    c, h, s, __VA_ARGS__ ) \
GENTFUNC3( scomplex, _Float16, double,   c, h, d, __VA_ARGS__ ) \
GENTFUNC3( scomplex, _Float16, hcomplex, c, h, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, _Float16, scomplex, c, h, c, __VA_ARGS__ ) \
GENTFUNC3( scomplex, _Float16, dcomplex, c, h, z, __VA_ARGS__ ) \
\
GENTFUNC3( scomplex, float,    _Float16, c, s, h, __VA_ARGS__ ) \
GENTFUNC3( scomplex, float,    double,   c, s, d, __VA_ARGS__ ) \
GENTFUNC3( scomplex, float,    hcomplex, c, s, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, float,    dcomplex, c, s, z, __VA_ARGS__ ) \
\
GENTFUNC3( scomplex, double,   _Float16, c, d, h, __VA_ARGS__ ) \
GENTFUNC3( scomplex, double,   float,    c, d, s, __VA_ARGS__ ) \
GENTFUNC3( scomplex, double,   double,   c, d, d, __VA_ARGS__ ) \
GENTFUNC3( scomplex, double,   hcomplex, c, d, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, double,   scomplex, c, d, c, __VA_ARGS__ ) \
GENTFUNC3( scomplex, double,   dcomplex, c, d, z, __VA_ARGS__ ) \
\
GENTFUNC3( scomplex, hcomplex, _Float16, c, y, h, __VA_ARGS__ ) \
GENTFUNC3( scomplex, hcomplex, float,    c, y, s, __VA_ARGS__ ) \
GENTFUNC3( scomplex, hcomplex, double,   c, y, d, __VA_ARGS__ ) \
GENTFUNC3( scomplex, hcomplex, hcomplex, c, y, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, hcomplex, scomplex, c, y, c, __VA_ARGS__ ) \
GENTFUNC3( scomplex, hcomplex, dcomplex, c, y, z, __VA_ARGS__ ) \
\
GENTFUNC3( scomplex, scomplex, _Float16, c, c, h, __VA_ARGS__ ) \
GENTFUNC3( scomplex, scomplex, double,   c, c, d, __VA_ARGS__ ) \
GENTFUNC3( scomplex, scomplex, hcomplex, c, c, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, scomplex, dcomplex, c, c, z, __VA_ARGS__ ) \
\
GENTFUNC3( scomplex, dcomplex, _Float16, c, z, h, __VA_ARGS__ ) \
GENTFUNC3( scomplex, dcomplex, float,    c, z, s, __VA_ARGS__ ) \
GENTFUNC3( scomplex, dcomplex, double,   c, z, d, __VA_ARGS__ ) \
GENTFUNC3( scomplex, dcomplex, hcomplex, c, z, y, __VA_ARGS__ ) \
GENTFUNC3( scomplex, dcomplex, scomplex, c, z, c, __VA_ARGS__ ) \
GENTFUNC3( scomplex, dcomplex, dcomplex, c, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3( dcomplex, _Float16, _Float16, z, h, h, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, _Float16, float,    z, h, s, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, _Float16, double,   z, h, d, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, _Float16, hcomplex, z, h, c, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, _Float16, scomplex, z, h, c, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, _Float16, dcomplex, z, h, z, __VA_ARGS__ ) \
\
GENTFUNC3( dcomplex, float,    _Float16, z, s, h, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, float,    float,    z, s, s, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, float,    double,   z, s, d, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, float,    hcomplex, z, s, y, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, float,    scomplex, z, s, c, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, float,    dcomplex, z, s, z, __VA_ARGS__ ) \
\
GENTFUNC3( dcomplex, double,   _Float16, z, d, h, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, double,   float,    z, d, s, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, double,   hcomplex, z, d, y, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, double,   scomplex, z, d, c, __VA_ARGS__ ) \
\
GENTFUNC3( dcomplex, hcomplex, _Float16, z, y, h, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, hcomplex, float,    z, y, s, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, hcomplex, double,   z, y, d, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, hcomplex, hcomplex, z, y, y, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, hcomplex, scomplex, z, y, c, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, hcomplex, dcomplex, z, y, z, __VA_ARGS__ ) \
\
GENTFUNC3( dcomplex, scomplex, _Float16, z, c, h, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, scomplex, float,    z, c, s, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, scomplex, double,   z, c, d, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, scomplex, hcomplex, z, c, y, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, scomplex, scomplex, z, c, c, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, scomplex, dcomplex, z, c, z, __VA_ARGS__ ) \
\
GENTFUNC3( dcomplex, dcomplex, _Float16, z, z, h, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, dcomplex, float,    z, z, s, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, dcomplex, hcomplex, z, z, y, __VA_ARGS__ ) \
GENTFUNC3( dcomplex, dcomplex, scomplex, z, z, c, __VA_ARGS__ )



// -- Basic three-operand with union of operands 1 and 2 --

#define INSERT_GENTFUNC3U12_BASIC( ... ) \
\
GENTFUNC3U12( _Float16, _Float16, _Float16, _Float16, h, h, h, h, __VA_ARGS__ ) \
GENTFUNC3U12( float,    float,    float,    float,    s, s, s, s, __VA_ARGS__ ) \
GENTFUNC3U12( double,   double,   double,   double,   d, d, d, d, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, hcomplex, hcomplex, hcomplex, y, y, y, y, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, scomplex, scomplex, scomplex, c, c, c, c, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, dcomplex, dcomplex, dcomplex, z, z, z, z, __VA_ARGS__ )



// -- Mixed domain three-operand with union of operands 1 and 2 --

#define INSERT_GENTFUNC3U12_MIX_D( ... ) \
\
GENTFUNC3U12( _Float16, _Float16, hcomplex, _Float16, h, h, y, h, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, hcomplex, _Float16, hcomplex, h, y, h, y, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, hcomplex, hcomplex, hcomplex, h, y, y, y, __VA_ARGS__ ) \
\
GENTFUNC3U12( float,    float,    scomplex, float,    s, s, c, s, __VA_ARGS__ ) \
GENTFUNC3U12( float,    scomplex, float,    scomplex, s, c, s, c, __VA_ARGS__ ) \
GENTFUNC3U12( float,    scomplex, scomplex, scomplex, s, c, c, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( double,   double,   dcomplex, double,   d, d, z, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   dcomplex, double,   dcomplex, d, z, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   dcomplex, dcomplex, dcomplex, d, z, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( hcomplex, _Float16, _Float16, hcomplex, y, h, h, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, _Float16, hcomplex, hcomplex, y, h, y, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, hcomplex, _Float16, hcomplex, y, y, h, y, __VA_ARGS__ ) \
\
GENTFUNC3U12( scomplex, float,    float,    scomplex, c, s, s, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, float,    scomplex, scomplex, c, s, c, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, scomplex, float,    scomplex, c, c, s, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( dcomplex, double,   double,   dcomplex, z, d, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, double,   dcomplex, dcomplex, z, d, z, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, dcomplex, double,   dcomplex, z, z, d, z, __VA_ARGS__ )



// -- Mixed precision three-operand with union of operands 1 and 2 --

#define INSERT_GENTFUNC3U12_MIX_P( ... ) \
\
GENTFUNC3U12( _Float16, _Float16, float,    _Float16, h, h, s, h, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, _Float16, double,   _Float16, h, h, d, h, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, _Float16, scomplex, _Float16, h, h, c, h, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, _Float16, dcomplex, _Float16, h, h, z, h, __VA_ARGS__ ) \
\
GENTFUNC3U12( _Float16, float,    _Float16, float,    h, s, h, s, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, float,    float,    float,    h, s, s, s, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, float,    double,   float,    h, s, d, s, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, float,    hcomplex, float,    h, s, y, s, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, float,    scomplex, float,    h, s, c, s, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, float,    dcomplex, float,    h, s, z, s, __VA_ARGS__ ) \
\
GENTFUNC3U12( _Float16, double,   _Float16, double,   h, d, h, d, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, double,   float,    double,   h, d, s, d, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, double,   double,   double,   h, d, d, d, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, double,   hcomplex, double,   h, d, y, d, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, double,   scomplex, double,   h, d, c, d, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, double,   dcomplex, double,   h, d, z, d, __VA_ARGS__ ) \
\
GENTFUNC3U12( _Float16, hcomplex, float,    hcomplex, h, y, s, y, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, hcomplex, double,   hcomplex, h, y, d, y, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, hcomplex, scomplex, hcomplex, h, y, c, y, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, hcomplex, dcomplex, hcomplex, h, y, z, y, __VA_ARGS__ ) \
\
GENTFUNC3U12( _Float16, scomplex, _Float16, scomplex, h, c, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, scomplex, float,    scomplex, h, c, s, c, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, scomplex, double,   scomplex, h, c, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, scomplex, hcomplex, scomplex, h, c, cy c, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, scomplex, scomplex, scomplex, h, c, c, c, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, scomplex, dcomplex, scomplex, h, c, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( _Float16, dcomplex, _Float16, dcomplex, h, z, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, dcomplex, float,    dcomplex, h, z, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, dcomplex, double,   dcomplex, h, z, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, dcomplex, hcomplex, dcomplex, h, z, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, dcomplex, scomplex, dcomplex, h, z, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( _Float16, dcomplex, dcomplex, dcomplex, h, z, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3U12( float,    _Float16, _Float16, _Float16, s, h, h, h, __VA_ARGS__ ) \
GENTFUNC3U12( float,    _Float16, float,    _Float16, s, h, s, h, __VA_ARGS__ ) \
GENTFUNC3U12( float,    _Float16, double,   _Float16, s, h, d, h, __VA_ARGS__ ) \
GENTFUNC3U12( float,    _Float16, hcomplex, _Float16, s, h, y, h, __VA_ARGS__ ) \
GENTFUNC3U12( float,    _Float16, scomplex, _Float16, s, h, c, h, __VA_ARGS__ ) \
GENTFUNC3U12( float,    _Float16, dcomplex, _Float16, s, h, z, h, __VA_ARGS__ ) \
\
GENTFUNC3U12( float,    float,    _Float16, float,    s, s, d, s, __VA_ARGS__ ) \
GENTFUNC3U12( float,    float,    double,   float,    s, s, d, s, __VA_ARGS__ ) \
GENTFUNC3U12( float,    float,    hcomplex, float,    s, s, y, s, __VA_ARGS__ ) \
GENTFUNC3U12( float,    float,    dcomplex, float,    s, s, z, s, __VA_ARGS__ ) \
\
GENTFUNC3U12( float,    double,   _Float16, double,   s, d, h, d, __VA_ARGS__ ) \
GENTFUNC3U12( float,    double,   float,    double,   s, d, s, d, __VA_ARGS__ ) \
GENTFUNC3U12( float,    double,   double,   double,   s, d, d, d, __VA_ARGS__ ) \
GENTFUNC3U12( float,    double,   hcomplex, double,   s, d, y, d, __VA_ARGS__ ) \
GENTFUNC3U12( float,    double,   scomplex, double,   s, d, c, d, __VA_ARGS__ ) \
GENTFUNC3U12( float,    double,   dcomplex, double,   s, d, z, d, __VA_ARGS__ ) \
\
GENTFUNC3U12( float,    hcomplex, _Float16, scomplex, s, y, h, c,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    hcomplex, float,    scomplex, s, y, s, c,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    hcomplex, double,   scomplex, s, y, d, c,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    hcomplex, hcomplex, scomplex, s, y, y, c,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    hcomplex, scomplex, scomplex, s, y, c, c,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    hcomplex, dcomplex, scomplex, s, y, z, c,  _VA_ARGS__ ) \
\
GENTFUNC3U12( float,    scomplex, _Float16, scomplex, s, c, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( float,    scomplex, double,   scomplex, s, c, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( float,    scomplex, hcomplex, scomplex, s, c, y, c, __VA_ARGS__ ) \
GENTFUNC3U12( float,    scomplex, dcomplex, scomplex, s, c, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( float,    dcomplex, _Float16, dcomplex, s, z, h, z,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    dcomplex, float,    dcomplex, s, z, s, z,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    dcomplex, double,   dcomplex, s, z, d, z,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    dcomplex, hcomplex, dcomplex, s, z, y, z,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    dcomplex, scomplex, dcomplex, s, z, c, z,  _VA_ARGS__ ) \
GENTFUNC3U12( float,    dcomplex, dcomplex, dcomplex, s, z, z, z,  _VA_ARGS__ ) \
\
\
GENTFUNC3U12( double,   float,    _Float16, double,   d, s, h, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   float,    float,    double,   d, s, s, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   float,    double,   double,   d, s, d, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   float,    hcomplex, double,   d, s, y, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   float,    scomplex, double,   d, s, c, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   float,    dcomplex, double,   d, s, z, d, __VA_ARGS__ ) \
\
GENTFUNC3U12( double,   double,   _Float16, double,   d, d, h, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   double,   float,    double,   d, d, s, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   double,   hcomplex, double,   d, d, y, d, __VA_ARGS__ ) \
GENTFUNC3U12( double,   double,   scomplex, double,   d, d, c, d, __VA_ARGS__ ) \
\
GENTFUNC3U12( double,   hcomplex, _Float16, dcomplex, d, y, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   hcomplex, float,    dcomplex, d, y, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   hcomplex, double,   dcomplex, d, y, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   hcomplex, hcomplex, dcomplex, d, y, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   hcomplex, scomplex, dcomplex, d, y, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   hcomplex, dcomplex, dcomplex, d, y, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( double,   scomplex, _Float16, dcomplex, d, c, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   scomplex, float,    dcomplex, d, c, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   scomplex, double,   dcomplex, d, c, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   scomplex, hcomplex, dcomplex, d, c, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   scomplex, scomplex, dcomplex, d, c, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   scomplex, dcomplex, dcomplex, d, c, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( double,   dcomplex, _Float16, dcomplex, d, z, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   dcomplex, float,    dcomplex, d, z, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   dcomplex, hcomplex, dcomplex, d, z, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( double,   dcomplex, scomplex, dcomplex, d, z, c, z, __VA_ARGS__ ) \
\
\
GENTFUNC3U12( hcomplex, _Float16, float,    hcomplex, y, h, s, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, _Float16, double,   hcomplex, y, h, d, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, _Float16, scomplex, hcomplex, y, h, c, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, _Float16, dcomplex, hcomplex, y, h, z, y, __VA_ARGS__ ) \
\
GENTFUNC3U12( hcomplex, float,    _Float16, scomplex, y, s, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, float,    float,    scomplex, y, s, s, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, float,    double,   scomplex, y, s, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, float,    hcomplex, scomplex, y, s, y, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, float,    scomplex, scomplex, y, s, c, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, float,    dcomplex, scomplex, y, s, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( hcomplex, double,   _Float16, dcomplex, y, d, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, double,   float,    dcomplex, y, d, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, double,   double,   dcomplex, y, d, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, double,   hcomplex, dcomplex, y, d, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, double,   scomplex, dcomplex, y, d, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, double,   dcomplex, dcomplex, y, d, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( hcomplex, hcomplex, float,    hcomplex, y, y, s, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, hcomplex, double,   hcomplex, y, y, d, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, hcomplex, scomplex, hcomplex, y, y, c, y, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, hcomplex, dcomplex, hcomplex, y, y, z, y, __VA_ARGS__ ) \
\
GENTFUNC3U12( hcomplex, scomplex, _Float16, scomplex, y, c, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, scomplex, float,    scomplex, y, c, s, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, scomplex, double,   scomplex, y, c, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, scomplex, hcomplex, scomplex, y, c, y, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, scomplex, scomplex, scomplex, y, c, c, c, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, scomplex, dcomplex, scomplex, y, c, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( hcomplex, dcomplex, _Float16, dcomplex, y, z, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, dcomplex, float,    dcomplex, y, z, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, dcomplex, double,   dcomplex, y, z, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, dcomplex, hcomplex, dcomplex, y, z, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, dcomplex, scomplex, dcomplex, y, z, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( hcomplex, dcomplex, dcomplex, dcomplex, y, z, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3U12( scomplex, _Float16, _Float16, scomplex, c, h, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, _Float16, float,    scomplex, c, h, s, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, _Float16, double,   scomplex, c, h, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, _Float16, hcomplex, scomplex, c, h, y, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, _Float16, scomplex, scomplex, c, h, c, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, _Float16, dcomplex, scomplex, c, h, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( scomplex, float,    _Float16, scomplex, c, s, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, float,    double,   scomplex, c, s, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, float,    hcomplex, scomplex, c, s, y, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, float,    dcomplex, scomplex, c, s, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( scomplex, double,   _Float16, dcomplex, c, d, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, double,   float,    dcomplex, c, d, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, double,   double,   dcomplex, c, d, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, double,   hcomplex, dcomplex, c, d, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, double,   scomplex, dcomplex, c, d, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, double,   dcomplex, dcomplex, c, d, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( scomplex, scomplex, _Float16, scomplex, c, c, h, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, scomplex, double,   scomplex, c, c, d, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, scomplex, hcomplex, scomplex, c, c, y, c, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, scomplex, dcomplex, scomplex, c, c, z, c, __VA_ARGS__ ) \
\
GENTFUNC3U12( scomplex, hcomplex, _Float16, dcomplex, c, y, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, hcomplex, float,    dcomplex, c, y, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, hcomplex, double,   dcomplex, c, y, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, hcomplex, hcomplex, dcomplex, c, y, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, hcomplex, scomplex, dcomplex, c, y, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, hcomplex, dcomplex, dcomplex, c, y, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( scomplex, dcomplex, _Float16, dcomplex, c, z, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, dcomplex, float,    dcomplex, c, z, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, dcomplex, double,   dcomplex, c, z, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, dcomplex, hcomplex, dcomplex, c, z, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, dcomplex, scomplex, dcomplex, c, z, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( scomplex, dcomplex, dcomplex, dcomplex, c, z, z, z, __VA_ARGS__ ) \
\
\
GENTFUNC3U12( dcomplex, _Float16, _Float16, dcomplex, z, h, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, _Float16, float,    dcomplex, z, h, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, _Float16, double,   dcomplex, z, h, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, _Float16, hcomplex, dcomplex, z, h, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, _Float16, scomplex, dcomplex, z, h, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, _Float16, dcomplex, dcomplex, z, h, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( dcomplex, float,    _Float16, dcomplex, z, s, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, float,    float,    dcomplex, z, s, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, float,    double,   dcomplex, z, s, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, float,    hcomplex, dcomplex, z, s, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, float,    scomplex, dcomplex, z, s, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, float,    dcomplex, dcomplex, z, s, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( dcomplex, double,   _Float16, dcomplex, z, d, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, double,   float,    dcomplex, z, d, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, double,   hcomplex, dcomplex, z, d, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, double,   scomplex, dcomplex, z, d, c, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( dcomplex, hcomplex, _Float16, dcomplex, z, y, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, hcomplex, float,    dcomplex, z, y, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, hcomplex, double,   dcomplex, z, y, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, hcomplex, hcomplex, dcomplex, z, y, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, hcomplex, scomplex, dcomplex, z, y, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, hcomplex, dcomplex, dcomplex, z, y, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( dcomplex, scomplex, _Float16, dcomplex, z, c, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, scomplex, float,    dcomplex, z, c, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, scomplex, double,   dcomplex, z, c, d, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, scomplex, hcomplex, dcomplex, z, c, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, scomplex, scomplex, dcomplex, z, c, c, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, scomplex, dcomplex, dcomplex, z, c, z, z, __VA_ARGS__ ) \
\
GENTFUNC3U12( dcomplex, dcomplex, _Float16, dcomplex, z, z, h, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, dcomplex, float,    dcomplex, z, z, s, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, dcomplex, hcomplex, dcomplex, z, z, y, z, __VA_ARGS__ ) \
GENTFUNC3U12( dcomplex, dcomplex, scomplex, dcomplex, z, z, c, z, __VA_ARGS__ )


#endif
