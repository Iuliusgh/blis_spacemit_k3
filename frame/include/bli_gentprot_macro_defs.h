/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

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


#ifndef BLIS_GENTPROT_MACRO_DEFS_H
#define BLIS_GENTPROT_MACRO_DEFS_H

//
// -- MACROS TO INSERT PROTOTYPE-GENERATING MACROS -----------------------------
//



// -- Macros for generating BLAS routines --------------------------------------


// -- Basic one-operand macro --


#define INSERT_GENTPROT_BLAS( blasname ) \
\
GENTPROT( _Float16, h, blasname ) \
GENTPROT( float,    s, blasname ) \
GENTPROT( double,   d, blasname ) \
GENTPROT( hcomplex, y, blasname ) \
GENTPROT( scomplex, c, blasname ) \
GENTPROT( dcomplex, z, blasname )


// -- Basic one-operand macro with real domain only --


#define INSERT_GENTPROTRO_BLAS( blasname ) \
\
GENTPROTRO( _Float16, h, blasname ) \
GENTPROTRO( float,    s, blasname ) \
GENTPROTRO( double,   d, blasname )


// -- Basic one-operand macro with complex domain only and real projection --


#define INSERT_GENTPROTCO_BLAS( blasname ) \
\
GENTPROTCO( hcomplex, _Float16, y, h, blasname ) \
GENTPROTCO( scomplex, float,    c, s, blasname ) \
GENTPROTCO( dcomplex, double,   z, d, blasname )


// -- Basic one-operand macro with conjugation (real funcs only, used only for dot, ger) --


#define INSERT_GENTPROTDOTR_BLAS( blasname ) \
\
GENTPROTDOT( _Float16, h,  , blasname ) \
GENTPROTDOT( float,    s,  , blasname ) \
GENTPROTDOT( double,   d,  , blasname )


// -- Basic one-operand macro with conjugation (complex funcs only, used only for dot, ger) --


#define INSERT_GENTPROTDOTC_BLAS( blasname ) \
\
GENTPROTDOT( hcomplex, y, y, blasname ) \
GENTPROTDOT( hcomplex, y, u, blasname ) \
GENTPROTDOT( scomplex, c, c, blasname ) \
GENTPROTDOT( scomplex, c, u, blasname ) \
GENTPROTDOT( dcomplex, z, c, blasname ) \
GENTPROTDOT( dcomplex, z, u, blasname )


// -- Basic one-operand macro with conjugation (used only for dot, ger) --


#define INSERT_GENTPROTDOT_BLAS( blasname ) \
\
INSERT_GENTPROTDOTR_BLAS( blasname ) \
INSERT_GENTPROTDOTC_BLAS( blasname )


// -- Basic one-operand macro with real projection --


#define INSERT_GENTPROTR_BLAS( rblasname, cblasname ) \
\
GENTPROTR( _Float16, _Float16, h, h, rblasname ) \
GENTPROTR( float,    float,    s, s, rblasname ) \
GENTPROTR( double,   double,   d, d, rblasname ) \
GENTPROTR( hcomplex, _Float16, y, h, cblasname ) \
GENTPROTR( scomplex, float,    c, s, cblasname ) \
GENTPROTR( dcomplex, double,   z, d, cblasname )


// -- Alternate two-operand macro (one char for complex, one for real proj) --


#define INSERT_GENTPROTR2_BLAS( blasname ) \
\
GENTPROTR2( _Float16, _Float16,  , h, blasname ) \
GENTPROTR2( float,    float,     , s, blasname ) \
GENTPROTR2( double,   double,    , d, blasname ) \
GENTPROTR2( hcomplex, _Float16, y, h, blasname ) \
GENTPROTR2( scomplex, float,    c, s, blasname ) \
GENTPROTR2( dcomplex, double,   z, d, blasname )


// -- Extended two-operand macro (used only for scal) --


#define INSERT_GENTPROTSCAL_BLAS( blasname ) \
\
GENTPROTSCAL( _Float16, _Float16,  , h, blasname ) \
GENTPROTSCAL( float,    float,     , s, blasname ) \
GENTPROTSCAL( double,   double,    , d, blasname ) \
GENTPROTSCAL( hcomplex, hcomplex,  , y, blasname ) \
GENTPROTSCAL( scomplex, scomplex,  , c, blasname ) \
GENTPROTSCAL( dcomplex, dcomplex,  , z, blasname ) \
GENTPROTSCAL( _Float16, hcomplex, y, h, blasname ) \
GENTPROTSCAL( float,    scomplex, s, c, blasname ) \
GENTPROTSCAL( double,   dcomplex, d, z, blasname )




// -- Macros for functions with one operand ------------------------------------


// -- Basic one-operand macro --

#define INSERT_GENTPROT_BASIC( ... ) \
\
GENTPROT( _Float16, h, __VA_ARGS__ ) \
GENTPROT( float,    s, __VA_ARGS__ ) \
GENTPROT( double,   d, __VA_ARGS__ ) \
GENTPROT( hcomplex, y, __VA_ARGS__ ) \
GENTPROT( scomplex, c, __VA_ARGS__ ) \
GENTPROT( dcomplex, z, __VA_ARGS__ )



// -- Basic one-operand with real projection --

#define INSERT_GENTPROTR_BASIC( ... ) \
\
GENTPROTR( _Float16, _Float16, h, h, __VA_ARGS__ ) \
GENTPROTR( float,    float,    s, s, __VA_ARGS__ ) \
GENTPROTR( double,   double,   d, d, __VA_ARGS__ ) \
GENTPROTR( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
GENTPROTR( scomplex, float,    c, s, __VA_ARGS__ ) \
GENTPROTR( dcomplex, double,   z, d, __VA_ARGS__ )



// -- Basic one-operand macro with real domain only --

#define INSERT_GENTPROTRO_BASIC( ... ) \
\
GENTPROTRO( _Float16, h, __VA_ARGS__ ) \
GENTPROTRO( float,    s, __VA_ARGS__ ) \
GENTPROTRO( double,   d, __VA_ARGS__ )



// -- Basic one-operand macro with complex domain only and real projection --

#define INSERT_GENTPROTCO_BASIC( ... ) \
\
GENTPROTCO( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
GENTPROTCO( scomplex, float,    c, s, __VA_ARGS__ ) \
GENTPROTCO( dcomplex, double,   z, d, __VA_ARGS__ )



// -- Basic one-operand macro with integer instance --

#define INSERT_GENTPROT_BASIC_I( ... ) \
\
GENTPROT( _Float16, h, __VA_ARGS__ ) \
GENTPROT( float,    s, __VA_ARGS__ ) \
GENTPROT( double,   d, __VA_ARGS__ ) \
GENTPROT( hcomplex, y, __VA_ARGS__ ) \
GENTPROT( scomplex, c, __VA_ARGS__ ) \
GENTPROT( dcomplex, z, __VA_ARGS__ ) \
GENTPROT( gint_t,   i, __VA_ARGS__ )



// -- Basic one-operand with integer projection --

#define INSERT_GENTPROTI_BASIC( ... ) \
\
GENTPROTI( _Float16, gint_t, h, i, __VA_ARGS__ ) \
GENTPROTI( float,    gint_t, s, i, __VA_ARGS__ ) \
GENTPROTI( double,   gint_t, d, i, __VA_ARGS__ ) \
GENTPROTI( hcomplex, gint_t, y, i, __VA_ARGS__ ) \
GENTPROTI( scomplex, gint_t, c, i, __VA_ARGS__ ) \
GENTPROTI( dcomplex, gint_t, z, i, __VA_ARGS__ )



// -- Basic one-operand with real and integer projections --

#define INSERT_GENTPROTRI_BASIC( funcname ) \
\
GENTPROTRI( _Float16, _Float16, gint_t, h, h, i, funcname ) \
GENTPROTRI( float,    float,    gint_t, s, s, i, funcname ) \
GENTPROTRI( double,   double,   gint_t, d, d, i, funcname ) \
GENTPROTRI( hcomplex, _Float16, gint_t, y, h, i, funcname ) \
GENTPROTRI( scomplex, float,    gint_t, c, s, i, funcname ) \
GENTPROTRI( dcomplex, double,   gint_t, z, d, i, funcname )




// -- Macros for functions with two primary operands ---------------------------


// -- Basic two-operand macro --

#define INSERT_GENTPROT2_BASIC( ... ) \
\
GENTPROT2( _Float16, _Float16, h, h, __VA_ARGS__ ) \
GENTPROT2( float,    float,    s, s, __VA_ARGS__ ) \
GENTPROT2( double,   double,   d, d, __VA_ARGS__ ) \
GENTPROT2( hcomplex, hcomplex, y, y, __VA_ARGS__ ) \
GENTPROT2( scomplex, scomplex, c, c, __VA_ARGS__ ) \
GENTPROT2( dcomplex, dcomplex, z, z, __VA_ARGS__ )



// -- Mixed domain two-operand macro --

#define INSERT_GENTPROT2_MIX_D( ... ) \
\
GENTPROT2( _Float16, hcomplex, h, y, __VA_ARGS__ ) \
GENTPROT2( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
\
GENTPROT2( float,    scomplex, s, c, __VA_ARGS__ ) \
GENTPROT2( scomplex, float,    c, s, __VA_ARGS__ ) \
\
GENTPROT2( double,   dcomplex, d, z, __VA_ARGS__ ) \
GENTPROT2( dcomplex, double,   z, d, __VA_ARGS__ )



// -- Mixed precision two-operand macro --

#define INSERT_GENTPROT2_MIX_P( ... ) \
\
GENTPROT2( _Float16, float,    h, s, __VA_ARGS__ ) \
GENTPROT2( _Float16, double,   h, d, __VA_ARGS__ ) \
GENTPROT2( _Float16, scomplex, h, c, __VA_ARGS__ ) \
GENTPROT2( _Float16, dcomplex, h, z, __VA_ARGS__ ) \
\
GENTPROT2( float,    _Float16, s, h, __VA_ARGS__ ) \
GENTPROT2( float,    double,   s, d, __VA_ARGS__ ) \
GENTPROT2( float,    hcomplex, s, y, __VA_ARGS__ ) \
GENTPROT2( float,    dcomplex, s, z, __VA_ARGS__ ) \
\
GENTPROT2( double,   _Float16, d, h, __VA_ARGS__ ) \
GENTPROT2( double,   float,    d, s, __VA_ARGS__ ) \
GENTPROT2( double,   hcomplex, d, y, __VA_ARGS__ ) \
GENTPROT2( double,   scomplex, d, c, __VA_ARGS__ ) \
\
GENTPROT2( hcomplex, float,    y, s, __VA_ARGS__ ) \
GENTPROT2( hcomplex, double,   y, d, __VA_ARGS__ ) \
GENTPROT2( hcomplex, scomplex, y, c, __VA_ARGS__ ) \
GENTPROT2( hcomplex, dcomplex, y, z, __VA_ARGS__ ) \
\
GENTPROT2( scomplex, _Float16, c, h, __VA_ARGS__ ) \
GENTPROT2( scomplex, double,   c, d, __VA_ARGS__ ) \
GENTPROT2( scomplex, hcomplex, c, y, __VA_ARGS__ ) \
GENTPROT2( scomplex, dcomplex, c, z, __VA_ARGS__ ) \
\
GENTPROT2( dcomplex, _Float16, z, h, __VA_ARGS__ ) \
GENTPROT2( dcomplex, float,    z, s, __VA_ARGS__ ) \
GENTPROT2( dcomplex, hcomplex, z, y, __VA_ARGS__ ) \
GENTPROT2( dcomplex, scomplex, z, c, __VA_ARGS__ ) \



// -- Mixed domain/precision (all) two-operand macro --

#define INSERT_GENTPROT2_MIX_DP( ... ) \
\
GENTPROT2( _Float16, float,    h, s, __VA_ARGS__ ) \
GENTPROT2( _Float16, double,   h, d, __VA_ARGS__ ) \
GENTPROT2( _Float16, hcomplex, h, y, __VA_ARGS__ ) \
GENTPROT2( _Float16, scomplex, h, c, __VA_ARGS__ ) \
GENTPROT2( _Float16, dcomplex, h, z, __VA_ARGS__ ) \
\
GENTPROT2( float,    _Float16, s, h, __VA_ARGS__ ) \
GENTPROT2( float,    double,   s, d, __VA_ARGS__ ) \
GENTPROT2( float,    hcomplex, s, y, __VA_ARGS__ ) \
GENTPROT2( float,    scomplex, s, c, __VA_ARGS__ ) \
GENTPROT2( float,    dcomplex, s, z, __VA_ARGS__ ) \
\
GENTPROT2( double,   _Float16, d, h, __VA_ARGS__ ) \
GENTPROT2( double,   float,    d, s, __VA_ARGS__ ) \
GENTPROT2( double,   hcomplex, d, y, __VA_ARGS__ ) \
GENTPROT2( double,   scomplex, d, c, __VA_ARGS__ ) \
GENTPROT2( double,   dcomplex, d, z, __VA_ARGS__ ) \
\
GENTPROT2( hcomplex, _Float16, y, h, __VA_ARGS__ ) \
GENTPROT2( hcomplex, float,    y, s, __VA_ARGS__ ) \
GENTPROT2( hcomplex, double,   y, d, __VA_ARGS__ ) \
GENTPROT2( hcomplex, scomplex, y, c, __VA_ARGS__ ) \
GENTPROT2( hcomplex, dcomplex, y, z, __VA_ARGS__ ) \
\
GENTPROT2( scomplex, _Float16, c, h, __VA_ARGS__ ) \
GENTPROT2( scomplex, float,    c, s, __VA_ARGS__ ) \
GENTPROT2( scomplex, double,   c, d, __VA_ARGS__ ) \
GENTPROT2( scomplex, hcomplex, c, y, __VA_ARGS__ ) \
GENTPROT2( scomplex, dcomplex, c, z, __VA_ARGS__ ) \
\
GENTPROT2( dcomplex, _Float16, z, h, __VA_ARGS__ ) \
GENTPROT2( dcomplex, float,    z, s, __VA_ARGS__ ) \
GENTPROT2( dcomplex, double,   z, d, __VA_ARGS__ ) \
GENTPROT2( dcomplex, hcomplex, z, y, __VA_ARGS__ ) \
GENTPROT2( dcomplex, scomplex, z, c, __VA_ARGS__ )



// -- Basic two-operand with real projection of first operand --

#define INSERT_GENTPROT2R_BASIC( ... ) \
\
GENTPROT2R( _Float16, _Float16, _Float16, h, h, h, __VA_ARGS__ ) \
GENTPROT2R( float,    float,    float,    s, s, s, __VA_ARGS__ ) \
GENTPROT2R( double,   double,   double,   d, d, d, __VA_ARGS__ ) \
GENTPROT2R( hcomplex, hcomplex, _Float16, y, y, h, __VA_ARGS__ ) \
GENTPROT2R( scomplex, scomplex, float,    c, c, s, __VA_ARGS__ ) \
GENTPROT2R( dcomplex, dcomplex, double,   z, z, d, __VA_ARGS__ )



// -- Mixed domain two-operand with real projection of first operand --

#define INSERT_GENTPROT2R_MIX_D( ... ) \
\
GENTPROT2R( _Float16, hcomplex, _Float16, h, y, h, __VA_ARGS__ ) \
GENTPROT2R( hcomplex, _Float16, _Float16, y, h, h, __VA_ARGS__ ) \
\
GENTPROT2R( float,    scomplex, float, s, c, s, __VA_ARGS__ ) \
GENTPROT2R( scomplex, float,    float, c, s, s, __VA_ARGS__ ) \
\
GENTPROT2R( double,   dcomplex, double, d, z, d, __VA_ARGS__ ) \
GENTPROT2R( dcomplex, double,   double, z, d, d, __VA_ARGS__ )



// -- Mixed precision two-operand with real projection of first operand --

#define INSERT_GENTPROT2R_MIX_P( ... ) \
\
GENTPROT2R( _Float16, _Float16, _Float16, h, h, h, __VA_ARGS__ ) \
GENTPROT2R( _Float16, double,   _Float16, h, d, h, __VA_ARGS__ ) \
GENTPROT2R( _Float16, scomplex, _Float16, h, c, h, __VA_ARGS__ ) \
GENTPROT2R( _Float16, dcomplex, _Float16, h, z, h, __VA_ARGS__ ) \
\
GENTPROT2R( float,    _Float16, float,    s, h, s, __VA_ARGS__ ) \
GENTPROT2R( float,    double,   float,    s, d, s, __VA_ARGS__ ) \
GENTPROT2R( float,    hcomplex, float,    s, y, s, __VA_ARGS__ ) \
GENTPROT2R( float,    dcomplex, float,    s, z, s, __VA_ARGS__ ) \
\
GENTPROT2R( double,   _Float16, double,   d, h, d, __VA_ARGS__ ) \
GENTPROT2R( double,   float,    double,   d, s, d, __VA_ARGS__ ) \
GENTPROT2R( double,   hcomplex, double,   d, y, d, __VA_ARGS__ ) \
GENTPROT2R( double,   scomplex, double,   d, c, d, __VA_ARGS__ ) \
\
GENTPROT2R( hcomplex, float,    _Float16, y, s, h, __VA_ARGS__ ) \
GENTPROT2R( hcomplex, double,   _Float16, y, d, h, __VA_ARGS__ ) \
GENTPROT2R( hcomplex, scomplex, _Float16, y, c, h, __VA_ARGS__ ) \
GENTPROT2R( hcomplex, dcomplex, _Float16, y, z, h, __VA_ARGS__ ) \
\
GENTPROT2R( scomplex, _Float16, float,    c, h, s, __VA_ARGS__ ) \
GENTPROT2R( scomplex, double,   float,    c, d, s, __VA_ARGS__ ) \
GENTPROT2R( scomplex, hcomplex, float,    c, y, s, __VA_ARGS__ ) \
GENTPROT2R( scomplex, dcomplex, float,    c, z, s, __VA_ARGS__ ) \
\
GENTPROT2R( dcomplex, _Float16, double,   z, h, d, __VA_ARGS__ ) \
GENTPROT2R( dcomplex, float,    double,   z, s, d, __VA_ARGS__ ) \
GENTPROT2R( dcomplex, hcomplex, double,   z, y, d, __VA_ARGS__ ) \
GENTPROT2R( dcomplex, scomplex, double,   z, c, d, __VA_ARGS__ )



// -- Macros for functions with three primary operands -------------------------


// -- Basic three-operand macro --


#define INSERT_GENTPROT3_BASIC( funcname ) \
\
GENTPROT3( _Float16, _Float16, _Float16, h, h, h, funcname ) \
GENTPROT3( float,    float,    float,    s, s, s, funcname ) \
GENTPROT3( double,   double,   double,   d, d, d, funcname ) \
GENTPROT3( hcomplex, hcomplex, hcomplex, y, y, y, funcname ) \
GENTPROT3( scomplex, scomplex, scomplex, c, c, c, funcname ) \
GENTPROT3( dcomplex, dcomplex, dcomplex, z, z, z, funcname )


// -- Mixed domain three-operand macro --


#define INSERT_GENTPROT3_MIX_D( funcname ) \
\
GENTPROT3( _Float16, _Float16, hcomplex, h, h, y, funcname ) \
GENTPROT3( _Float16, hcomplex, _Float16, h, y, h, funcname ) \
GENTPROT3( _Float16, hcomplex, hcomplex, h, y, y, funcname ) \
\
GENTPROT3( float,    float,    scomplex, s, s, c, funcname ) \
GENTPROT3( float,    scomplex, float,    s, c, s, funcname ) \
GENTPROT3( float,    scomplex, scomplex, s, c, c, funcname ) \
\
GENTPROT3( double,   double,   dcomplex, d, d, z, funcname ) \
GENTPROT3( double,   dcomplex, double,   d, z, d, funcname ) \
GENTPROT3( double,   dcomplex, dcomplex, d, z, z, funcname ) \
\
GENTPROT3( hcomplex, _Float16, _Float16, y, h, h, funcname ) \
GENTPROT3( hcomplex, _Float16, hcomplex, y, h, y, funcname ) \
GENTPROT3( hcomplex, hcomplex, _Float16, y, y, h, funcname ) \
\
GENTPROT3( scomplex, float,    float,    c, s, s, funcname ) \
GENTPROT3( scomplex, float,    scomplex, c, s, c, funcname ) \
GENTPROT3( scomplex, scomplex, float,    c, c, s, funcname ) \
\
GENTPROT3( dcomplex, double,   double,   z, d, d, funcname ) \
GENTPROT3( dcomplex, double,   dcomplex, z, d, z, funcname ) \
GENTPROT3( dcomplex, dcomplex, double,   z, z, d, funcname )


// -- Mixed precision three-operand macro --


#define INSERT_GENTPROT3_MIX_P( funcname ) \
\
GENTPROT3( _Float16, _Float16, float,    h, h, s, funcname ) \
GENTPROT3( _Float16, _Float16, double,   h, h, d, funcname ) \
GENTPROT3( _Float16, _Float16, scomplex, h, h, c, funcname ) \
GENTPROT3( _Float16, _Float16, dcomplex, h, h, z, funcname ) \
\
GENTPROT3( _Float16, float,    _Float16, h, s, h, funcname ) \
GENTPROT3( _Float16, float,    float,    h, s, s, funcname ) \
GENTPROT3( _Float16, float,    double,   h, s, d, funcname ) \
GENTPROT3( _Float16, float,    hcomplex, h, s, y, funcname ) \
GENTPROT3( _Float16, float,    scomplex, h, s, c, funcname ) \
GENTPROT3( _Float16, float,    dcomplex, h, s, z, funcname ) \
\
GENTPROT3( _Float16, double,   _Float16, h, d, h, funcname ) \
GENTPROT3( _Float16, double,   float,    h, d, s, funcname ) \
GENTPROT3( _Float16, double,   double,   h, d, d, funcname ) \
GENTPROT3( _Float16, double,   hcomplex, h, d, y, funcname ) \
GENTPROT3( _Float16, double,   scomplex, h, d, c, funcname ) \
GENTPROT3( _Float16, double,   dcomplex, h, d, z, funcname ) \
\
GENTPROT3( _Float16, hcomplex, float,    h, y, s, funcname ) \
GENTPROT3( _Float16, hcomplex, double,   h, y, d, funcname ) \
GENTPROT3( _Float16, hcomplex, scomplex, h, y, c, funcname ) \
GENTPROT3( _Float16, hcomplex, dcomplex, h, y, z, funcname ) \
\
GENTPROT3( _Float16, scomplex, _Float16, h, c, h, funcname ) \
GENTPROT3( _Float16, scomplex, float,    h, c, s, funcname ) \
GENTPROT3( _Float16, scomplex, double,   h, c, d, funcname ) \
GENTPROT3( _Float16, scomplex, hcomplex, h, c, y, funcname ) \
GENTPROT3( _Float16, scomplex, scomplex, h, c, c, funcname ) \
GENTPROT3( _Float16, scomplex, dcomplex, h, c, z, funcname ) \
\
GENTPROT3( _Float16, dcomplex, _Float16, h, z, h, funcname ) \
GENTPROT3( _Float16, dcomplex, float,    h, z, s, funcname ) \
GENTPROT3( _Float16, dcomplex, double,   h, z, d, funcname ) \
GENTPROT3( _Float16, dcomplex, hcomplex, h, z, y, funcname ) \
GENTPROT3( _Float16, dcomplex, scomplex, h, z, c, funcname ) \
GENTPROT3( _Float16, dcomplex, dcomplex, h, z, z, funcname ) \
\
\
GENTPROT3( float,    _Float16, _Float16, s, h, h, funcname ) \
GENTPROT3( float,    _Float16, float,    s, h, s, funcname ) \
GENTPROT3( float,    _Float16, double,   s, h, d, funcname ) \
GENTPROT3( float,    _Float16, hcomplex, s, h, y, funcname ) \
GENTPROT3( float,    _Float16, scomplex, s, h, c, funcname ) \
GENTPROT3( float,    _Float16, dcomplex, s, h, z, funcname ) \
\
GENTPROT3( float,    float,    _Float16, s, s, h, funcname ) \
GENTPROT3( float,    float,    double,   s, s, d, funcname ) \
GENTPROT3( float,    float,    hcomplex, s, s, y, funcname ) \
GENTPROT3( float,    float,    dcomplex, s, s, z, funcname ) \
\
GENTPROT3( float,    double,   _Float16, s, d, h, funcname ) \
GENTPROT3( float,    double,   float,    s, d, s, funcname ) \
GENTPROT3( float,    double,   double,   s, d, d, funcname ) \
GENTPROT3( float,    double,   hcomplex, s, d, y, funcname ) \
GENTPROT3( float,    double,   scomplex, s, d, c, funcname ) \
GENTPROT3( float,    double,   dcomplex, s, d, z, funcname ) \
\
GENTPROT3( float,    hcomplex, _Float16, s, y, h, funcname ) \
GENTPROT3( float,    hcomplex, float,    s, y, s, funcname ) \
GENTPROT3( float,    hcomplex, double,   s, y, d, funcname ) \
GENTPROT3( float,    hcomplex, hcomplex, s, y, y, funcname ) \
GENTPROT3( float,    hcomplex, scomplex, s, y, c, funcname ) \
GENTPROT3( float,    hcomplex, dcomplex, s, y, z, funcname ) \
\
GENTPROT3( float,    scomplex, _Float16, s, c, h, funcname ) \
GENTPROT3( float,    scomplex, double,   s, c, d, funcname ) \
GENTPROT3( float,    scomplex, hcomplex, s, c, y, funcname ) \
GENTPROT3( float,    scomplex, dcomplex, s, c, z, funcname ) \
\
GENTPROT3( float,    dcomplex, _Float16, s, z, h, funcname ) \
GENTPROT3( float,    dcomplex, float,    s, z, s, funcname ) \
GENTPROT3( float,    dcomplex, double,   s, z, d, funcname ) \
GENTPROT3( float,    dcomplex, hcomplex, s, z, y, funcname ) \
GENTPROT3( float,    dcomplex, scomplex, s, z, c, funcname ) \
GENTPROT3( float,    dcomplex, dcomplex, s, z, z, funcname ) \
\
\
GENTPROT3( double,   _Float16, _Float16, d, h, h, funcname ) \
GENTPROT3( double,   _Float16, float,    d, h, s, funcname ) \
GENTPROT3( double,   _Float16, double,   d, h, d, funcname ) \
GENTPROT3( double,   _Float16, hcomplex, d, h, y, funcname ) \
GENTPROT3( double,   _Float16, scomplex, d, h, c, funcname ) \
GENTPROT3( double,   _Float16, dcomplex, d, h, z, funcname ) \
\
GENTPROT3( double,   float,    _Float16, d, s, h, funcname ) \
GENTPROT3( double,   float,    float,    d, s, s, funcname ) \
GENTPROT3( double,   float,    double,   d, s, d, funcname ) \
GENTPROT3( double,   float,    hcomplex, d, s, y, funcname ) \
GENTPROT3( double,   float,    scomplex, d, s, c, funcname ) \
GENTPROT3( double,   float,    dcomplex, d, s, z, funcname ) \
\
GENTPROT3( double,   double,   _Float16, d, d, h, funcname ) \
GENTPROT3( double,   double,   float,    d, d, s, funcname ) \
GENTPROT3( double,   double,   hcomplex, d, d, y, funcname ) \
GENTPROT3( double,   double,   scomplex, d, d, c, funcname ) \
\
GENTPROT3( double,   hcomplex, _Float16, d, y, h, funcname ) \
GENTPROT3( double,   hcomplex, float,    d, y, s, funcname ) \
GENTPROT3( double,   hcomplex, double,   d, y, d, funcname ) \
GENTPROT3( double,   hcomplex, hcomplex, d, y, y, funcname ) \
GENTPROT3( double,   hcomplex, scomplex, d, y, c, funcname ) \
GENTPROT3( double,   hcomplex, dcomplex, d, y, z, funcname ) \
\
GENTPROT3( double,   scomplex, _Float16, d, c, h, funcname ) \
GENTPROT3( double,   scomplex, float,    d, c, s, funcname ) \
GENTPROT3( double,   scomplex, double,   d, c, d, funcname ) \
GENTPROT3( double,   scomplex, hcomplex, d, c, y, funcname ) \
GENTPROT3( double,   scomplex, scomplex, d, c, c, funcname ) \
GENTPROT3( double,   scomplex, dcomplex, d, c, z, funcname ) \
\
GENTPROT3( double,   dcomplex, _Float16, d, z, h, funcname ) \
GENTPROT3( double,   dcomplex, float,    d, z, s, funcname ) \
GENTPROT3( double,   dcomplex, hcomplex, d, z, y, funcname ) \
GENTPROT3( double,   dcomplex, scomplex, d, z, c, funcname ) \
\
\
GENTPROT3( hcomplex, _Float16, float,    h, h, s, funcname ) \
GENTPROT3( hcomplex, _Float16, double,   h, h, d, funcname ) \
GENTPROT3( hcomplex, _Float16, scomplex, h, h, c, funcname ) \
GENTPROT3( hcomplex, _Float16, dcomplex, h, h, z, funcname ) \
\
GENTPROT3( hcomplex, float,    _Float16, h, s, h, funcname ) \
GENTPROT3( hcomplex, float,    float,    h, s, s, funcname ) \
GENTPROT3( hcomplex, float,    double,   h, s, d, funcname ) \
GENTPROT3( hcomplex, float,    hcomplex, h, s, y, funcname ) \
GENTPROT3( hcomplex, float,    scomplex, h, s, c, funcname ) \
GENTPROT3( hcomplex, float,    dcomplex, h, s, z, funcname ) \
\
GENTPROT3( hcomplex, double,   _Float16, h, d, h, funcname ) \
GENTPROT3( hcomplex, double,   float,    h, d, s, funcname ) \
GENTPROT3( hcomplex, double,   double,   h, d, d, funcname ) \
GENTPROT3( hcomplex, double,   hcomplex, h, d, y, funcname ) \
GENTPROT3( hcomplex, double,   scomplex, h, d, c, funcname ) \
GENTPROT3( hcomplex, double,   dcomplex, h, d, z, funcname ) \
\
GENTPROT3( hcomplex, hcomplex, float,    h, y, s, funcname ) \
GENTPROT3( hcomplex, hcomplex, double,   h, y, d, funcname ) \
GENTPROT3( hcomplex, hcomplex, scomplex, h, y, c, funcname ) \
GENTPROT3( hcomplex, hcomplex, dcomplex, h, y, z, funcname ) \
\
GENTPROT3( hcomplex, scomplex, _Float16, h, c, h, funcname ) \
GENTPROT3( hcomplex, scomplex, float,    h, c, s, funcname ) \
GENTPROT3( hcomplex, scomplex, double,   h, c, d, funcname ) \
GENTPROT3( hcomplex, scomplex, hcomplex, h, c, y, funcname ) \
GENTPROT3( hcomplex, scomplex, scomplex, h, c, c, funcname ) \
GENTPROT3( hcomplex, scomplex, dcomplex, h, c, z, funcname ) \
\
GENTPROT3( hcomplex, dcomplex, _Float16, h, z, h, funcname ) \
GENTPROT3( hcomplex, dcomplex, float,    h, z, s, funcname ) \
GENTPROT3( hcomplex, dcomplex, double,   h, z, d, funcname ) \
GENTPROT3( hcomplex, dcomplex, hcomplex, h, z, y, funcname ) \
GENTPROT3( hcomplex, dcomplex, scomplex, h, z, c, funcname ) \
GENTPROT3( hcomplex, dcomplex, dcomplex, h, z, z, funcname ) \
\
\
GENTPROT3( scomplex, _Float16, _Float16, c, h, h, funcname ) \
GENTPROT3( scomplex, _Float16, float,    c, h, s, funcname ) \
GENTPROT3( scomplex, _Float16, double,   c, h, d, funcname ) \
GENTPROT3( scomplex, _Float16, hcomplex, c, h, y, funcname ) \
GENTPROT3( scomplex, _Float16, scomplex, c, h, c, funcname ) \
GENTPROT3( scomplex, _Float16, dcomplex, c, h, z, funcname ) \
\
GENTPROT3( scomplex, float,    _Float16, c, s, h, funcname ) \
GENTPROT3( scomplex, float,    double,   c, s, d, funcname ) \
GENTPROT3( scomplex, float,    hcomplex, c, s, y, funcname ) \
GENTPROT3( scomplex, float,    dcomplex, c, s, z, funcname ) \
\
GENTPROT3( scomplex, double,   _Float16, c, d, h, funcname ) \
GENTPROT3( scomplex, double,   float,    c, d, s, funcname ) \
GENTPROT3( scomplex, double,   double,   c, d, d, funcname ) \
GENTPROT3( scomplex, double,   hcomplex, c, d, y, funcname ) \
GENTPROT3( scomplex, double,   scomplex, c, d, c, funcname ) \
GENTPROT3( scomplex, double,   dcomplex, c, d, z, funcname ) \
\
GENTPROT3( scomplex, hcomplex, _Float16, c, y, h, funcname ) \
GENTPROT3( scomplex, hcomplex, float,    c, y, s, funcname ) \
GENTPROT3( scomplex, hcomplex, double,   c, y, d, funcname ) \
GENTPROT3( scomplex, hcomplex, hcomplex, c, y, y, funcname ) \
GENTPROT3( scomplex, hcomplex, scomplex, c, y, c, funcname ) \
GENTPROT3( scomplex, hcomplex, dcomplex, c, y, z, funcname ) \
\
GENTPROT3( scomplex, scomplex, _Float16, c, c, h, funcname ) \
GENTPROT3( scomplex, scomplex, double,   c, c, d, funcname ) \
GENTPROT3( scomplex, scomplex, hcomplex, c, c, y, funcname ) \
GENTPROT3( scomplex, scomplex, dcomplex, c, c, z, funcname ) \
\
GENTPROT3( scomplex, dcomplex, _Float16, c, z, h, funcname ) \
GENTPROT3( scomplex, dcomplex, float,    c, z, s, funcname ) \
GENTPROT3( scomplex, dcomplex, double,   c, z, d, funcname ) \
GENTPROT3( scomplex, dcomplex, hcomplex, c, z, y, funcname ) \
GENTPROT3( scomplex, dcomplex, scomplex, c, z, c, funcname ) \
GENTPROT3( scomplex, dcomplex, dcomplex, c, z, z, funcname ) \
\
\
GENTPROT3( dcomplex, _Float16, _Float16, z, h, h, funcname ) \
GENTPROT3( dcomplex, _Float16, float,    z, h, s, funcname ) \
GENTPROT3( dcomplex, _Float16, double,   z, h, d, funcname ) \
GENTPROT3( dcomplex, _Float16, hcomplex, z, h, y, funcname ) \
GENTPROT3( dcomplex, _Float16, scomplex, z, h, c, funcname ) \
GENTPROT3( dcomplex, _Float16, dcomplex, z, h, z, funcname ) \
\
GENTPROT3( dcomplex, float,    _Float16, z, s, h, funcname ) \
GENTPROT3( dcomplex, float,    float,    z, s, s, funcname ) \
GENTPROT3( dcomplex, float,    double,   z, s, d, funcname ) \
GENTPROT3( dcomplex, float,    hcomplex, z, s, y, funcname ) \
GENTPROT3( dcomplex, float,    scomplex, z, s, c, funcname ) \
GENTPROT3( dcomplex, float,    dcomplex, z, s, z, funcname ) \
\
GENTPROT3( dcomplex, double,   _Float16, z, d, h, funcname ) \
GENTPROT3( dcomplex, double,   float,    z, d, s, funcname ) \
GENTPROT3( dcomplex, double,   hcomplex, z, d, y, funcname ) \
GENTPROT3( dcomplex, double,   scomplex, z, d, c, funcname ) \
\
GENTPROT3( dcomplex, hcomplex, _Float16, z, h, h, funcname ) \
GENTPROT3( dcomplex, hcomplex, float,    z, h, s, funcname ) \
GENTPROT3( dcomplex, hcomplex, double,   z, h, d, funcname ) \
GENTPROT3( dcomplex, hcomplex, hcomplex, z, h, y, funcname ) \
GENTPROT3( dcomplex, hcomplex, scomplex, z, h, c, funcname ) \
GENTPROT3( dcomplex, hcomplex, dcomplex, z, h, z, funcname ) \
\
GENTPROT3( dcomplex, scomplex, _Float16, z, c, h, funcname ) \
GENTPROT3( dcomplex, scomplex, float,    z, c, s, funcname ) \
GENTPROT3( dcomplex, scomplex, double,   z, c, d, funcname ) \
GENTPROT3( dcomplex, scomplex, hcomplex, z, c, y, funcname ) \
GENTPROT3( dcomplex, scomplex, scomplex, z, c, c, funcname ) \
GENTPROT3( dcomplex, scomplex, dcomplex, z, c, z, funcname ) \
\
GENTPROT3( dcomplex, dcomplex, _Float16, z, z, h, funcname ) \
GENTPROT3( dcomplex, dcomplex, float,    z, z, s, funcname ) \
GENTPROT3( dcomplex, dcomplex, hcomplex, z, z, y, funcname ) \
GENTPROT3( dcomplex, dcomplex, scomplex, z, z, c, funcname ) \



// -- Basic three-operand with union of operands 1 and 2 --


#define INSERT_GENTPROT3U12_BASIC( funcname ) \
\
GENTPROT3U12( _Float16, _Float16, _Float16, _Float16, h, h, h, h, funcname ) \
GENTPROT3U12( float,    float,    float,    float,    s, s, s, s, funcname ) \
GENTPROT3U12( double,   double,   double,   double,   d, d, d, d, funcname ) \
GENTPROT3U12( hcomplex, hcomplex, hcomplex, hcomplex, y, y, y, y, funcname ) \
GENTPROT3U12( scomplex, scomplex, scomplex, scomplex, c, c, c, c, funcname ) \
GENTPROT3U12( dcomplex, dcomplex, dcomplex, dcomplex, z, z, z, z, funcname )


// -- Mixed domain three-operand with union of operands 1 and 2 --


#define INSERT_GENTPROT3U12_MIX_D( funcname ) \
\
GENTPROT3U12( _Float16, _Float16, hcomplex, _Float16, h, h, y, h, funcname ) \
GENTPROT3U12( _Float16, hcomplex, _Float16, hcomplex, h, y, h, y, funcname ) \
GENTPROT3U12( _Float16, hcomplex, hcomplex, hcomplex, h, y, y, y, funcname ) \
\
GENTPROT3U12( float,    float,    scomplex, float,    s, s, c, s, funcname ) \
GENTPROT3U12( float,    scomplex, float,    scomplex, s, c, s, c, funcname ) \
GENTPROT3U12( float,    scomplex, scomplex, scomplex, s, c, c, c, funcname ) \
\
GENTPROT3U12( double,   double,   dcomplex, double,   d, d, z, d, funcname ) \
GENTPROT3U12( double,   dcomplex, double,   dcomplex, d, z, d, z, funcname ) \
GENTPROT3U12( double,   dcomplex, dcomplex, dcomplex, d, z, z, z, funcname ) \
\
GENTPROT3U12( hcomplex, _Float16, _Float16, hcomplex, y, h, h, y, funcname ) \
GENTPROT3U12( hcomplex, _Float16, hcomplex, hcomplex, y, h, y, y, funcname ) \
GENTPROT3U12( hcomplex, hcomplex, _Float16, hcomplex, y, y, h, y, funcname ) \
\
GENTPROT3U12( scomplex, float,    float,    scomplex, c, s, s, c, funcname ) \
GENTPROT3U12( scomplex, float,    scomplex, scomplex, c, s, c, c, funcname ) \
GENTPROT3U12( scomplex, scomplex, float,    scomplex, c, c, s, c, funcname ) \
\
GENTPROT3U12( dcomplex, double,   double,   dcomplex, z, d, d, z, funcname ) \
GENTPROT3U12( dcomplex, double,   dcomplex, dcomplex, z, d, z, z, funcname ) \
GENTPROT3U12( dcomplex, dcomplex, double,   dcomplex, z, z, d, z, funcname )


// -- Mixed precision three-operand with union of operands 1 and 2 --


#define INSERT_GENTPROT3U12_MIX_P( funcname ) \
\
GENTPROT3U12( _Float16, _Float16, float,    _Float16, h, h, s, h, funcname ) \
GENTPROT3U12( _Float16, _Float16, double,   _Float16, h, h, d, h, funcname ) \
GENTPROT3U12( _Float16, _Float16, scomplex, _Float16, h, h, c, h, funcname ) \
GENTPROT3U12( _Float16, _Float16, dcomplex, _Float16, h, h, z, h, funcname ) \
\
GENTPROT3U12( _Float16, float,    _Float16, float,    h, s, h, s, funcname ) \
GENTPROT3U12( _Float16, float,    float,    float,    h, s, s, s, funcname ) \
GENTPROT3U12( _Float16, float,    double,   float,    h, s, d, s, funcname ) \
GENTPROT3U12( _Float16, float,    hcomplex, float,    h, s, y, s, funcname ) \
GENTPROT3U12( _Float16, float,    scomplex, float,    h, s, c, s, funcname ) \
GENTPROT3U12( _Float16, float,    dcomplex, float,    h, s, z, s, funcname ) \
\
GENTPROT3U12( _Float16, double,   _Float16, double,   h, d, h, d, funcname ) \
GENTPROT3U12( _Float16, double,   float,    double,   h, d, s, d, funcname ) \
GENTPROT3U12( _Float16, double,   double,   double,   h, d, d, d, funcname ) \
GENTPROT3U12( _Float16, double,   hcomplex, double,   h, d, y, d, funcname ) \
GENTPROT3U12( _Float16, double,   scomplex, double,   h, d, c, d, funcname ) \
GENTPROT3U12( _Float16, double,   dcomplex, double,   h, d, z, d, funcname ) \
\
GENTPROT3U12( _Float16, hcomplex, float,    hcomplex, h, y, s, y, funcname ) \
GENTPROT3U12( _Float16, hcomplex, double,   hcomplex, h, y, d, y, funcname ) \
GENTPROT3U12( _Float16, hcomplex, scomplex, hcomplex, h, y, c, y, funcname ) \
GENTPROT3U12( _Float16, hcomplex, dcomplex, hcomplex, h, y, z, y, funcname ) \
\
GENTPROT3U12( _Float16, scomplex, _Float16, scomplex, h, c, d, c, funcname ) \
GENTPROT3U12( _Float16, scomplex, float,    scomplex, h, c, s, c, funcname ) \
GENTPROT3U12( _Float16, scomplex, double,   scomplex, h, c, d, c, funcname ) \
GENTPROT3U12( _Float16, scomplex, hcomplex, scomplex, h, c, y, c, funcname ) \
GENTPROT3U12( _Float16, scomplex, scomplex, scomplex, h, c, c, c, funcname ) \
GENTPROT3U12( _Float16, scomplex, dcomplex, scomplex, h, c, z, c, funcname ) \
\
GENTPROT3U12( _Float16, dcomplex, _Float16, dcomplex, h, z, h, z, funcname ) \
GENTPROT3U12( _Float16, dcomplex, float,    dcomplex, h, z, s, z, funcname ) \
GENTPROT3U12( _Float16, dcomplex, double,   dcomplex, h, z, d, z, funcname ) \
GENTPROT3U12( _Float16, dcomplex, hcomplex, dcomplex, h, z, c, z, funcname ) \
GENTPROT3U12( _Float16, dcomplex, scomplex, dcomplex, h, z, c, z, funcname ) \
GENTPROT3U12( _Float16, dcomplex, dcomplex, dcomplex, h, z, z, z, funcname ) \
\
\
GENTPROT3U12( float,    _Float16, _Float16, float,    s, h, h, s, funcname ) \
GENTPROT3U12( float,    _Float16, float,    float,    s, h, s, s, funcname ) \
GENTPROT3U12( float,    _Float16, double,   float,    s, h, d, s, funcname ) \
GENTPROT3U12( float,    _Float16, hcomplex, float,    s, h, y, s, funcname ) \
GENTPROT3U12( float,    _Float16, scomplex, float,    s, h, c, s, funcname ) \
GENTPROT3U12( float,    _Float16, dcomplex, float,    s, h, z, s, funcname ) \
\
GENTPROT3U12( float,    float,    _Float16, float,    s, s, h, s, funcname ) \
GENTPROT3U12( float,    float,    double,   float,    s, s, d, s, funcname ) \
GENTPROT3U12( float,    float,    hcomplex, float,    s, s, y, s, funcname ) \
GENTPROT3U12( float,    float,    dcomplex, float,    s, s, z, s, funcname ) \
\
GENTPROT3U12( float,    double,   _Float16, double,   s, d, h, d, funcname ) \
GENTPROT3U12( float,    double,   float,    double,   s, d, s, d, funcname ) \
GENTPROT3U12( float,    double,   double,   double,   s, d, d, d, funcname ) \
GENTPROT3U12( float,    double,   hcomplex, double,   s, d, y, d, funcname ) \
GENTPROT3U12( float,    double,   scomplex, double,   s, d, c, d, funcname ) \
GENTPROT3U12( float,    double,   dcomplex, double,   s, d, z, d, funcname ) \
\
GENTPROT3U12( float,    hcomplex, _Float16, scomplex, s, y, h, c, funcname ) \
GENTPROT3U12( float,    hcomplex, float,    scomplex, s, y, s, c, funcname ) \
GENTPROT3U12( float,    hcomplex, double,   scomplex, s, y, d, c, funcname ) \
GENTPROT3U12( float,    hcomplex, hcomplex, scomplex, s, y, y, c, funcname ) \
GENTPROT3U12( float,    hcomplex, scomplex, scomplex, s, y, c, c, funcname ) \
GENTPROT3U12( float,    hcomplex, dcomplex, scomplex, s, y, z, c, funcname ) \
\
GENTPROT3U12( float,    scomplex, _Float16, scomplex, s, h, d, c, funcname ) \
GENTPROT3U12( float,    scomplex, double,   scomplex, s, c, d, c, funcname ) \
GENTPROT3U12( float,    scomplex, hcomplex, scomplex, s, c, y, c, funcname ) \
GENTPROT3U12( float,    scomplex, dcomplex, scomplex, s, c, z, c, funcname ) \
\
GENTPROT3U12( float,    dcomplex, _Float16, dcomplex, s, z, h, z, funcname ) \
GENTPROT3U12( float,    dcomplex, float,    dcomplex, s, z, s, z, funcname ) \
GENTPROT3U12( float,    dcomplex, double,   dcomplex, s, z, d, z, funcname ) \
GENTPROT3U12( float,    dcomplex, hcomplex, dcomplex, s, z, y, z, funcname ) \
GENTPROT3U12( float,    dcomplex, scomplex, dcomplex, s, z, c, z, funcname ) \
GENTPROT3U12( float,    dcomplex, dcomplex, dcomplex, s, z, z, z, funcname ) \
\
\
GENTPROT3U12( double,   _Float16, _Float16, double,   d, s, h, d, funcname ) \
GENTPROT3U12( double,   _Float16, float,    double,   d, s, s, d, funcname ) \
GENTPROT3U12( double,   _Float16, double,   double,   d, s, d, d, funcname ) \
GENTPROT3U12( double,   _Float16, hcomplex, double,   d, s, y, d, funcname ) \
GENTPROT3U12( double,   _Float16, scomplex, double,   d, s, c, d, funcname ) \
GENTPROT3U12( double,   _Float16, dcomplex, double,   d, s, z, d, funcname ) \
\
GENTPROT3U12( double,   float,    _Float16, double,   d, s, h, d, funcname ) \
GENTPROT3U12( double,   float,    float,    double,   d, s, s, d, funcname ) \
GENTPROT3U12( double,   float,    double,   double,   d, s, d, d, funcname ) \
GENTPROT3U12( double,   float,    hcomplex, double,   d, s, y, d, funcname ) \
GENTPROT3U12( double,   float,    scomplex, double,   d, s, c, d, funcname ) \
GENTPROT3U12( double,   float,    dcomplex, double,   d, s, z, d, funcname ) \
\
GENTPROT3U12( double,   double,   _Float16  double,   d, d, h, d, funcname ) \
GENTPROT3U12( double,   double,   float,    double,   d, d, s, d, funcname ) \
GENTPROT3U12( double,   double,   hcomplex, double,   d, d, y, d, funcname ) \
GENTPROT3U12( double,   double,   scomplex, double,   d, d, c, d, funcname ) \
\
GENTPROT3U12( double,   hcomplex, _Float16, dcomplex, d, y, h, z, funcname ) \
GENTPROT3U12( double,   hcomplex, float,    dcomplex, d, y, s, z, funcname ) \
GENTPROT3U12( double,   hcomplex, double,   dcomplex, d, y, d, z, funcname ) \
GENTPROT3U12( double,   hcomplex, hcomplex, dcomplex, d, y, y, z, funcname ) \
GENTPROT3U12( double,   hcomplex, scomplex, dcomplex, d, y, c, z, funcname ) \
GENTPROT3U12( double,   hcomplex, dcomplex, dcomplex, d, y, z, z, funcname ) \
\
GENTPROT3U12( double,   scomplex, _Float16, dcomplex, d, c, h, z, funcname ) \
GENTPROT3U12( double,   scomplex, float,    dcomplex, d, c, s, z, funcname ) \
GENTPROT3U12( double,   scomplex, double,   dcomplex, d, c, d, z, funcname ) \
GENTPROT3U12( double,   scomplex, hcomplex, dcomplex, d, c, y, z, funcname ) \
GENTPROT3U12( double,   scomplex, scomplex, dcomplex, d, c, c, z, funcname ) \
GENTPROT3U12( double,   scomplex, dcomplex, dcomplex, d, c, z, z, funcname ) \
\
GENTPROT3U12( double,   dcomplex, _Float16, dcomplex, d, z, h, z, funcname ) \
GENTPROT3U12( double,   dcomplex, float,    dcomplex, d, z, s, z, funcname ) \
GENTPROT3U12( double,   dcomplex, hcomplex, dcomplex, d, z, y, z, funcname ) \
GENTPROT3U12( double,   dcomplex, scomplex, dcomplex, d, z, c, z, funcname ) \
\
\
GENTPROT3U12( hcomplex, _Float16, float,    hcomplex, y, h, s, y, funcname ) \
GENTPROT3U12( hcomplex, _Float16, double,   hcomplex, y, h, d, y, funcname ) \
GENTPROT3U12( hcomplex, _Float16, scomplex, hcomplex, y, h, c, y, funcname ) \
GENTPROT3U12( hcomplex, _Float16, dcomplex, hcomplex, y, h, z, y, funcname ) \
\
GENTPROT3U12( hcomplex, float,    _Float16, scomplex, y, s, h, c, funcname ) \
GENTPROT3U12( hcomplex, float,    float,    scomplex, y, s, s, c, funcname ) \
GENTPROT3U12( hcomplex, float,    double,   scomplex, y, s, d, c, funcname ) \
GENTPROT3U12( hcomplex, float,    hcomplex, scomplex, y, s, y, c, funcname ) \
GENTPROT3U12( hcomplex, float,    scomplex, scomplex, y, s, c, c, funcname ) \
GENTPROT3U12( hcomplex, float,    dcomplex, scomplex, y, s, z, c, funcname ) \
\
GENTPROT3U12( hcomplex, double,   _Float16, dcomplex, y, d, h, z, funcname ) \
GENTPROT3U12( hcomplex, double,   float,    dcomplex, y, d, s, z, funcname ) \
GENTPROT3U12( hcomplex, double,   double,   dcomplex, y, d, d, z, funcname ) \
GENTPROT3U12( hcomplex, double,   hcomplex, dcomplex, y, d, y, z, funcname ) \
GENTPROT3U12( hcomplex, double,   scomplex, dcomplex, y, d, c, z, funcname ) \
GENTPROT3U12( hcomplex, double,   dcomplex, dcomplex, y, d, z, z, funcname ) \
\
GENTPROT3U12( hcomplex, hcomplex, float,    hcomplex, y, y, s, c, funcname ) \
GENTPROT3U12( hcomplex, hcomplex, double,   hcomplex, y, y, d, c, funcname ) \
GENTPROT3U12( hcomplex, hcomplex, scomplex, hcomplex, y, y, c, c, funcname ) \
GENTPROT3U12( hcomplex, hcomplex, dcomplex, hcomplex, y, y, z, c, funcname ) \
\
GENTPROT3U12( hcomplex, scomplex, _Float16, scomplex, y, c, h, c, funcname ) \
GENTPROT3U12( hcomplex, scomplex, float,    scomplex, y, c, s, c, funcname ) \
GENTPROT3U12( hcomplex, scomplex, double,   scomplex, y, c, d, c, funcname ) \
GENTPROT3U12( hcomplex, scomplex, hcomplex, scomplex, y, c, y, c, funcname ) \
GENTPROT3U12( hcomplex, scomplex, scomplex, scomplex, y, c, c, c, funcname ) \
GENTPROT3U12( hcomplex, scomplex, dcomplex, scomplex, y, c, z, c, funcname ) \
\
GENTPROT3U12( hcomplex, dcomplex, _Float16, dcomplex, y, z, h, z, funcname ) \
GENTPROT3U12( hcomplex, dcomplex, float,    dcomplex, y, z, s, z, funcname ) \
GENTPROT3U12( hcomplex, dcomplex, double,   dcomplex, y, z, d, z, funcname ) \
GENTPROT3U12( hcomplex, dcomplex, hcomplex, dcomplex, y, z, y, z, funcname ) \
GENTPROT3U12( hcomplex, dcomplex, scomplex, dcomplex, y, z, c, z, funcname ) \
GENTPROT3U12( hcomplex, dcomplex, dcomplex, dcomplex, y, z, z, z, funcname ) \
\
\
GENTPROT3U12( scomplex, _Float16, _Float16, scomplex, c, h, h, c, funcname ) \
GENTPROT3U12( scomplex, _Float16, float,    scomplex, c, h, s, c, funcname ) \
GENTPROT3U12( scomplex, _Float16, double,   scomplex, c, h, d, c, funcname ) \
GENTPROT3U12( scomplex, _Float16, hcomplex, scomplex, c, h, y, c, funcname ) \
GENTPROT3U12( scomplex, _Float16, scomplex, scomplex, c, h, c, c, funcname ) \
GENTPROT3U12( scomplex, _Float16, dcomplex, scomplex, c, h, z, c, funcname ) \
\
GENTPROT3U12( scomplex, float,    _Float16, scomplex, c, s, h, c, funcname ) \
GENTPROT3U12( scomplex, float,    double,   scomplex, c, s, d, c, funcname ) \
GENTPROT3U12( scomplex, float,    hcomplex, scomplex, c, s, y, c, funcname ) \
GENTPROT3U12( scomplex, float,    dcomplex, scomplex, c, s, z, c, funcname ) \
\
GENTPROT3U12( scomplex, double,   _Float16, dcomplex, c, d, h, z, funcname ) \
GENTPROT3U12( scomplex, double,   float,    dcomplex, c, d, s, z, funcname ) \
GENTPROT3U12( scomplex, double,   double,   dcomplex, c, d, d, z, funcname ) \
GENTPROT3U12( scomplex, double,   hcomplex, dcomplex, c, d, y, z, funcname ) \
GENTPROT3U12( scomplex, double,   scomplex, dcomplex, c, d, c, z, funcname ) \
GENTPROT3U12( scomplex, double,   dcomplex, dcomplex, c, d, z, z, funcname ) \
\
GENTPROT3U12( scomplex, hcomplex, _Float16, scomplex, c, y, h, c, funcname ) \
GENTPROT3U12( scomplex, hcomplex, float,    scomplex, c, y, s, c, funcname ) \
GENTPROT3U12( scomplex, hcomplex, double,   scomplex, c, y, d, c, funcname ) \
GENTPROT3U12( scomplex, hcomplex, hcomplex, scomplex, c, y, y, c, funcname ) \
GENTPROT3U12( scomplex, hcomplex, scomplex, scomplex, c, y, c, c, funcname ) \
GENTPROT3U12( scomplex, hcomplex, dcomplex, scomplex, c, y, z, c, funcname ) \
\
GENTPROT3U12( scomplex, scomplex, _Float16, scomplex, c, c, h, c, funcname ) \
GENTPROT3U12( scomplex, scomplex, double,   scomplex, c, c, d, c, funcname ) \
GENTPROT3U12( scomplex, scomplex, hcomplex, scomplex, c, c, y, c, funcname ) \
GENTPROT3U12( scomplex, scomplex, dcomplex, scomplex, c, c, z, c, funcname ) \
\
GENTPROT3U12( scomplex, dcomplex, _Float16, dcomplex, c, z, h, z, funcname ) \
GENTPROT3U12( scomplex, dcomplex, float,    dcomplex, c, z, s, z, funcname ) \
GENTPROT3U12( scomplex, dcomplex, double,   dcomplex, c, z, d, z, funcname ) \
GENTPROT3U12( scomplex, dcomplex, hcomplex, dcomplex, c, z, y, z, funcname ) \
GENTPROT3U12( scomplex, dcomplex, scomplex, dcomplex, c, z, c, z, funcname ) \
GENTPROT3U12( scomplex, dcomplex, dcomplex, dcomplex, c, z, z, z, funcname ) \
\
\
GENTPROT3U12( dcomplex, _Float16, _Float16, dcomplex, z, h, h, z, funcname ) \
GENTPROT3U12( dcomplex, _Float16, float,    dcomplex, z, h, s, z, funcname ) \
GENTPROT3U12( dcomplex, _Float16, double,   dcomplex, z, h, d, z, funcname ) \
GENTPROT3U12( dcomplex, _Float16, hcomplex, dcomplex, z, h, y, z, funcname ) \
GENTPROT3U12( dcomplex, _Float16, scomplex, dcomplex, z, h, c, z, funcname ) \
GENTPROT3U12( dcomplex, _Float16, dcomplex, dcomplex, z, h, z, z, funcname ) \
\
GENTPROT3U12( dcomplex, float,    _Float16, dcomplex, z, s, h, z, funcname ) \
GENTPROT3U12( dcomplex, float,    float,    dcomplex, z, s, s, z, funcname ) \
GENTPROT3U12( dcomplex, float,    double,   dcomplex, z, s, d, z, funcname ) \
GENTPROT3U12( dcomplex, float,    hcomplex, dcomplex, z, s, y, z, funcname ) \
GENTPROT3U12( dcomplex, float,    scomplex, dcomplex, z, s, c, z, funcname ) \
GENTPROT3U12( dcomplex, float,    dcomplex, dcomplex, z, s, z, z, funcname ) \
\
GENTPROT3U12( dcomplex, double,   _Float16, dcomplex, z, d, h, z, funcname ) \
GENTPROT3U12( dcomplex, double,   float,    dcomplex, z, d, s, z, funcname ) \
GENTPROT3U12( dcomplex, double,   hcomplex, dcomplex, z, d, y, z, funcname ) \
GENTPROT3U12( dcomplex, double,   scomplex, dcomplex, z, d, c, z, funcname ) \
\
GENTPROT3U12( dcomplex, scomplex, _Float16, dcomplex, z, c, h, z, funcname ) \
GENTPROT3U12( dcomplex, scomplex, float,    dcomplex, z, c, s, z, funcname ) \
GENTPROT3U12( dcomplex, scomplex, double,   dcomplex, z, c, d, z, funcname ) \
GENTPROT3U12( dcomplex, scomplex, hcomplex, dcomplex, z, c, y, z, funcname ) \
GENTPROT3U12( dcomplex, scomplex, scomplex, dcomplex, z, c, c, z, funcname ) \
GENTPROT3U12( dcomplex, scomplex, dcomplex, dcomplex, z, c, z, z, funcname ) \
\
GENTPROT3U12( dcomplex, dcomplex, _Float16, dcomplex, z, z, h, z, funcname ) \
GENTPROT3U12( dcomplex, dcomplex, float,    dcomplex, z, z, s, z, funcname ) \
GENTPROT3U12( dcomplex, dcomplex, hcomplex, dcomplex, z, z, y, z, funcname ) \
GENTPROT3U12( dcomplex, dcomplex, scomplex, dcomplex, z, z, c, z, funcname )


#endif
