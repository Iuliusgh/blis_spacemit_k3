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

#ifndef BLIS_GENARRAY_MACRO_DEFS_H
#define BLIS_GENARRAY_MACRO_DEFS_H


// -- Macros to generate function arrays ---------------------------------------

// -- "Smart" one-operand macro --

#define GENARRAY_FPA(tname,opname) \
\
static tname PASTECH(opname,_fpa)[BLIS_NUM_FP_TYPES] = \
{ \
	( tname )PASTEMAC(h,opname), \
	( tname )PASTEMAC(y,opname), \
	( tname )PASTEMAC(s,opname), \
	( tname )PASTEMAC(c,opname), \
	( tname )PASTEMAC(d,opname), \
	( tname )PASTEMAC(z,opname)  \
}

#define GENARRAYRO_FPA(tname,opname) \
\
static tname PASTECH(opname,_fpa)[BLIS_NUM_FP_TYPES] = \
{ \
	( tname )PASTEMAC(h,opname), \
	( tname )PASTEMAC(s,opname), \
	( tname )PASTEMAC(d,opname), \
	NULL, \
	NULL, \
	NULL \
}

// -- "Smart" one-operand macro (with integer support) --

#define GENARRAY_FPA_I(tname,opname) \
\
static tname PASTECH(opname,_fpa)[BLIS_NUM_FP_TYPES+1] = \
{ \
	( tname )PASTEMAC(h,opname), \
	( tname )PASTEMAC(h,opname), \
	( tname )PASTEMAC(s,opname), \
	( tname )PASTEMAC(c,opname), \
	( tname )PASTEMAC(d,opname), \
	( tname )PASTEMAC(z,opname), \
	( tname )PASTEMAC(i,opname)  \
}

// -- "Smart" two-operand macro --

#define GENARRAY_FPA2(tname,op) \
\
static tname PASTECH(op,_fpa2)[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ ( tname )PASTEMAC(h,h,op),  ( tname )PASTEMAC(h,y,op),  ( tname )PASTEMAC(h,s,op),  ( tname )PASTEMAC(h,c,op),  ( tname )PASTEMAC(h,d,op),  ( tname )PASTEMAC(h,z,op) }, \
	{ ( tname )PASTEMAC(y,h,op),  ( tname )PASTEMAC(y,y,op),  ( tname )PASTEMAC(y,s,op),  ( tname )PASTEMAC(y,c,op),  ( tname )PASTEMAC(y,d,op),  ( tname )PASTEMAC(y,z,op) }, \
	{ ( tname )PASTEMAC(s,h,op),  ( tname )PASTEMAC(s,y,op),  ( tname )PASTEMAC(s,s,op),  ( tname )PASTEMAC(s,c,op),  ( tname )PASTEMAC(s,d,op),  ( tname )PASTEMAC(s,z,op) }, \
	{ ( tname )PASTEMAC(c,h,op),  ( tname )PASTEMAC(c,y,op),  ( tname )PASTEMAC(c,s,op),  ( tname )PASTEMAC(c,c,op),  ( tname )PASTEMAC(c,d,op),  ( tname )PASTEMAC(c,z,op) }, \
	{ ( tname )PASTEMAC(d,h,op),  ( tname )PASTEMAC(d,y,op),  ( tname )PASTEMAC(d,s,op),  ( tname )PASTEMAC(d,c,op),  ( tname )PASTEMAC(d,d,op),  ( tname )PASTEMAC(d,z,op) }, \
	{ ( tname )PASTEMAC(z,h,op),  ( tname )PASTEMAC(z,y,op),  ( tname )PASTEMAC(z,s,op),  ( tname )PASTEMAC(z,c,op),  ( tname )PASTEMAC(z,d,op),  ( tname )PASTEMAC(z,z,op) }  \
}

// -- "Smart" two-operand macro --

/*
#define GENARRAY2_VFP(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ PASTEMAC(s,s,op), PASTEMAC(s,c,op), PASTEMAC(s,d,op), PASTEMAC(s,z,op) }, \
	{ PASTEMAC(c,s,op), PASTEMAC(c,c,op), PASTEMAC(c,d,op), PASTEMAC(c,z,op) }, \
	{ PASTEMAC(d,s,op), PASTEMAC(d,c,op), PASTEMAC(d,d,op), PASTEMAC(d,z,op) }, \
	{ PASTEMAC(z,s,op), PASTEMAC(z,c,op), PASTEMAC(z,d,op), PASTEMAC(z,z,op) }  \
}
*/



// -- One-operand macro --

#define GENARRAY(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES] = \
{ \
	PASTEMAC(h,op), \
	PASTEMAC(y,op), \
	PASTEMAC(s,op), \
	PASTEMAC(c,op), \
	PASTEMAC(d,op), \
	PASTEMAC(z,op)  \
}

#define GENARRAY_I(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES+1] = \
{ \
	PASTEMAC(h,op), \
	PASTEMAC(y,op), \
	PASTEMAC(s,op), \
	PASTEMAC(c,op), \
	PASTEMAC(d,op), \
	PASTEMAC(z,op), \
	PASTEMAC(i,op)  \
}

/*
#define GENARRAYR(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ PASTEMAC(s,s,op), NULL,              PASTEMAC(s,d,op), NULL,             }, \
	{ PASTEMAC(c,s,op), NULL,              PASTEMAC(c,d,op), NULL,             }, \
	{ PASTEMAC(d,s,op), NULL,              PASTEMAC(d,d,op), NULL,             }, \
	{ PASTEMAC(z,s,op), NULL,              PASTEMAC(z,d,op), NULL,             }  \
}
*/



// -- One-operand macro (with custom prefix) --

#define GENARRAY_PREF(arrayname,prefix,op) \
\
arrayname[BLIS_NUM_FP_TYPES] = \
{ \
	PASTECH(prefix,h,op), \
	PASTECH(prefix,y,op), \
	PASTECH(prefix,s,op), \
	PASTECH(prefix,c,op), \
	PASTECH(prefix,d,op), \
	PASTECH(prefix,z,op)  \
}



// -- Two-operand macros --


#define GENARRAY2_ALL(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ PASTEMAC(h,h,op),  PASTEMAC(h,y,op),  PASTEMAC(h,s,op),  PASTEMAC(h,c,op),  PASTEMAC(h,d,op),  PASTEMAC(h,z,op),}, \
	{ PASTEMAC(y,h,op),  PASTEMAC(y,y,op),  PASTEMAC(y,s,op),  PASTEMAC(y,c,op),  PASTEMAC(y,d,op),  PASTEMAC(y,z,op),}, \
	{ PASTEMAC(s,h,op),  PASTEMAC(s,y,op),  PASTEMAC(s,s,op),  PASTEMAC(s,c,op),  PASTEMAC(s,d,op),  PASTEMAC(s,z,op),}, \
	{ PASTEMAC(c,h,op),  PASTEMAC(c,y,op),  PASTEMAC(c,s,op),  PASTEMAC(c,c,op),  PASTEMAC(c,d,op),  PASTEMAC(c,z,op),}, \
	{ PASTEMAC(d,h,op),  PASTEMAC(d,y,op),  PASTEMAC(d,s,op),  PASTEMAC(d,c,op),  PASTEMAC(d,d,op),  PASTEMAC(d,z,op),}, \
	{ PASTEMAC(z,h,op),  PASTEMAC(z,y,op),  PASTEMAC(z,s,op),  PASTEMAC(z,c,op),  PASTEMAC(z,d,op),  PASTEMAC(z,z,op),}  \
}


#define GENARRAY2_MIXP(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ PASTEMAC(h,h,op),  NULL,              PASTEMAC(h,s,op),  NULL,              PASTEMAC(h,d,op),  NULL,            }, \
	{ NULL,              PASTEMAC(y,y,op),  NULL,              PASTEMAC(y,c,op),  NULL,              PASTEMAC(y,z,op),}, \
	{ PASTEMAC(s,h,op),  NULL,              PASTEMAC(s,s,op),  NULL,              PASTEMAC(s,d,op),  NULL,            }, \
	{ NULL,              PASTEMAC(c,y,op),  NULL,              PASTEMAC(c,c,op),  NULL,              PASTEMAC(c,z,op),}, \
	{ PASTEMAC(d,h,op),  NULL,              PASTEMAC(d,s,op),  NULL,              PASTEMAC(d,d,op),  NULL,            }, \
	{ NULL,              PASTEMAC(z,y,op),  NULL,              PASTEMAC(z,c,op),  NULL,              PASTEMAC(z,z,op),}  \
}


#define GENARRAY2_EXT(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ PASTEMAC(h,h,op), PASTEMAC(h,y,op), NULL,             NULL,             NULL,             NULL,             }, \
	{ PASTEMAC(y,h,op), PASTEMAC(y,h,op), NULL,             NULL,             NULL,             NULL,             }, \
	{ NULL,             NULL,             PASTEMAC(s,s,op), PASTEMAC(s,c,op), NULL,             NULL,             }, \
	{ NULL,             NULL,             PASTEMAC(c,s,op), PASTEMAC(c,c,op), NULL,             NULL,             }, \
	{ NULL,             NULL,             NULL,             NULL,             PASTEMAC(d,d,op), PASTEMAC(d,z,op), }, \
	{ NULL,             NULL,             NULL,             NULL,             PASTEMAC(z,d,op), PASTEMAC(z,z,op), }  \
}


#define GENARRAY2_MIN(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ PASTEMAC(h,h,op), NULL,             NULL,             NULL,             NULL,             NULL,             }, \
	{ NULL,             PASTEMAC(y,y,op), NULL,             NULL,             NULL,             NULL,             }, \
	{ NULL,             NULL,             PASTEMAC(s,s,op), NULL,             NULL,             NULL,             }, \
	{ NULL,             NULL,             NULL,             PASTEMAC(c,c,op), NULL,             NULL,             }, \
	{ NULL,             NULL,             NULL,             NULL,             PASTEMAC(d,d,op), NULL,             }, \
	{ NULL,             NULL,             NULL,             NULL,             NULL,             PASTEMAC(z,z,op), }  \
}


// -- Three-operand macros --


#define GENARRAY3_ALL(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ \
	{ PASTEMAC(h,h,h,op), PASTEMAC(h,h,y,op),  PASTEMAC(h,h,s,op),  PASTEMAC(h,h,c,op),  PASTEMAC(h,h,d,op),  PASTEMAC(h,h,z,op) }, \
	{ PASTEMAC(h,y,h,op), PASTEMAC(h,y,y,op),  PASTEMAC(h,y,s,op),  PASTEMAC(h,y,c,op),  PASTEMAC(h,y,d,op),  PASTEMAC(h,y,z,op) }, \
	{ PASTEMAC(h,s,h,op), PASTEMAC(h,s,y,op),  PASTEMAC(h,s,s,op),  PASTEMAC(h,s,c,op),  PASTEMAC(h,s,d,op),  PASTEMAC(h,s,z,op) }, \
	{ PASTEMAC(h,c,h,op), PASTEMAC(h,c,y,op),  PASTEMAC(h,c,s,op),  PASTEMAC(h,c,c,op),  PASTEMAC(h,c,d,op),  PASTEMAC(h,c,z,op) }, \
	{ PASTEMAC(h,d,h,op), PASTEMAC(h,d,y,op),  PASTEMAC(h,d,s,op),  PASTEMAC(h,d,c,op),  PASTEMAC(h,d,d,op),  PASTEMAC(h,d,z,op) }, \
	{ PASTEMAC(h,z,h,op), PASTEMAC(h,z,y,op),  PASTEMAC(h,z,s,op),  PASTEMAC(h,z,c,op),  PASTEMAC(h,z,d,op),  PASTEMAC(h,z,z,op) }  \
	}, \
	{ \
	{ PASTEMAC(y,h,h,op), PASTEMAC(y,h,y,op),  PASTEMAC(y,h,s,op),  PASTEMAC(y,h,c,op),  PASTEMAC(y,h,d,op),  PASTEMAC(y,h,z,op) }, \
	{ PASTEMAC(y,y,h,op), PASTEMAC(y,y,y,op),  PASTEMAC(y,y,s,op),  PASTEMAC(y,y,c,op),  PASTEMAC(y,y,d,op),  PASTEMAC(y,y,z,op) }, \
	{ PASTEMAC(y,s,h,op), PASTEMAC(y,s,y,op),  PASTEMAC(y,s,s,op),  PASTEMAC(y,s,c,op),  PASTEMAC(y,s,d,op),  PASTEMAC(y,s,z,op) }, \
	{ PASTEMAC(y,c,h,op), PASTEMAC(y,c,y,op),  PASTEMAC(y,c,s,op),  PASTEMAC(y,c,c,op),  PASTEMAC(y,c,d,op),  PASTEMAC(y,c,z,op) }, \
	{ PASTEMAC(y,d,h,op), PASTEMAC(y,d,y,op),  PASTEMAC(y,d,s,op),  PASTEMAC(y,d,c,op),  PASTEMAC(y,d,d,op),  PASTEMAC(y,d,z,op) }, \
	{ PASTEMAC(y,z,h,op), PASTEMAC(y,z,y,op),  PASTEMAC(y,z,s,op),  PASTEMAC(y,z,c,op),  PASTEMAC(y,z,d,op),  PASTEMAC(y,z,z,op) }  \
	}, \
	{ \
	{ PASTEMAC(s,h,h,op), PASTEMAC(s,h,y,op),  PASTEMAC(s,h,s,op),  PASTEMAC(s,h,c,op),  PASTEMAC(s,h,d,op),  PASTEMAC(s,h,z,op) }, \
	{ PASTEMAC(s,y,h,op), PASTEMAC(s,y,y,op),  PASTEMAC(s,y,s,op),  PASTEMAC(s,y,c,op),  PASTEMAC(s,y,d,op),  PASTEMAC(s,y,z,op) }, \
	{ PASTEMAC(s,s,h,op), PASTEMAC(s,s,y,op),  PASTEMAC(s,s,s,op),  PASTEMAC(s,s,c,op),  PASTEMAC(s,s,d,op),  PASTEMAC(s,s,z,op) }, \
	{ PASTEMAC(s,c,h,op), PASTEMAC(s,c,y,op),  PASTEMAC(s,c,s,op),  PASTEMAC(s,c,c,op),  PASTEMAC(s,c,d,op),  PASTEMAC(s,c,z,op) }, \
	{ PASTEMAC(s,d,h,op), PASTEMAC(s,d,y,op),  PASTEMAC(s,d,s,op),  PASTEMAC(s,d,c,op),  PASTEMAC(s,d,d,op),  PASTEMAC(s,d,z,op) }, \
	{ PASTEMAC(s,z,h,op), PASTEMAC(s,z,y,op),  PASTEMAC(s,z,s,op),  PASTEMAC(s,z,c,op),  PASTEMAC(s,z,d,op),  PASTEMAC(s,z,z,op) }  \
	}, \
	{ \
	{ PASTEMAC(c,h,h,op), PASTEMAC(c,h,y,op),  PASTEMAC(c,h,s,op),  PASTEMAC(c,h,c,op),  PASTEMAC(c,h,d,op),  PASTEMAC(c,h,z,op) }, \
	{ PASTEMAC(c,y,h,op), PASTEMAC(c,y,y,op),  PASTEMAC(c,y,s,op),  PASTEMAC(c,y,c,op),  PASTEMAC(c,y,d,op),  PASTEMAC(c,y,z,op) }, \
	{ PASTEMAC(c,s,h,op), PASTEMAC(c,s,y,op),  PASTEMAC(c,s,s,op),  PASTEMAC(c,s,c,op),  PASTEMAC(c,s,d,op),  PASTEMAC(c,s,z,op) }, \
	{ PASTEMAC(c,c,h,op), PASTEMAC(c,c,y,op),  PASTEMAC(c,c,s,op),  PASTEMAC(c,c,c,op),  PASTEMAC(c,c,d,op),  PASTEMAC(c,c,z,op) }, \
	{ PASTEMAC(c,d,h,op), PASTEMAC(c,d,y,op),  PASTEMAC(c,d,s,op),  PASTEMAC(c,d,c,op),  PASTEMAC(c,d,d,op),  PASTEMAC(c,d,z,op) }, \
	{ PASTEMAC(c,z,h,op), PASTEMAC(c,z,y,op),  PASTEMAC(c,z,s,op),  PASTEMAC(c,z,c,op),  PASTEMAC(c,z,d,op),  PASTEMAC(c,z,z,op) }  \
	}, \
	{ \
	{ PASTEMAC(d,h,h,op), PASTEMAC(d,h,y,op),  PASTEMAC(d,h,s,op),  PASTEMAC(d,h,c,op),  PASTEMAC(d,h,d,op),  PASTEMAC(d,h,z,op) }, \
	{ PASTEMAC(d,y,h,op), PASTEMAC(d,y,y,op),  PASTEMAC(d,y,s,op),  PASTEMAC(d,y,c,op),  PASTEMAC(d,y,d,op),  PASTEMAC(d,y,z,op) }, \
	{ PASTEMAC(d,s,h,op), PASTEMAC(d,s,y,op),  PASTEMAC(d,s,s,op),  PASTEMAC(d,s,c,op),  PASTEMAC(d,s,d,op),  PASTEMAC(d,s,z,op) }, \
	{ PASTEMAC(d,c,h,op), PASTEMAC(d,c,y,op),  PASTEMAC(d,c,s,op),  PASTEMAC(d,c,c,op),  PASTEMAC(d,c,d,op),  PASTEMAC(d,c,z,op) }, \
	{ PASTEMAC(d,d,h,op), PASTEMAC(d,d,y,op),  PASTEMAC(d,d,s,op),  PASTEMAC(d,d,c,op),  PASTEMAC(d,d,d,op),  PASTEMAC(d,d,z,op) }, \
	{ PASTEMAC(d,z,h,op), PASTEMAC(d,z,y,op),  PASTEMAC(d,z,s,op),  PASTEMAC(d,z,c,op),  PASTEMAC(d,z,d,op),  PASTEMAC(d,z,z,op) }  \
	}, \
	{ \
	{ PASTEMAC(z,h,h,op), PASTEMAC(z,h,y,op),  PASTEMAC(z,h,s,op),  PASTEMAC(z,h,c,op),  PASTEMAC(z,h,d,op),  PASTEMAC(z,h,z,op) }, \
	{ PASTEMAC(z,y,h,op), PASTEMAC(z,y,y,op),  PASTEMAC(z,y,s,op),  PASTEMAC(z,y,c,op),  PASTEMAC(z,y,d,op),  PASTEMAC(z,y,z,op) }, \
	{ PASTEMAC(z,s,h,op), PASTEMAC(z,s,y,op),  PASTEMAC(z,s,s,op),  PASTEMAC(z,s,c,op),  PASTEMAC(z,s,d,op),  PASTEMAC(z,s,z,op) }, \
	{ PASTEMAC(z,c,h,op), PASTEMAC(z,c,y,op),  PASTEMAC(z,c,s,op),  PASTEMAC(z,c,c,op),  PASTEMAC(z,c,d,op),  PASTEMAC(z,c,z,op) }, \
	{ PASTEMAC(z,d,h,op), PASTEMAC(z,d,y,op),  PASTEMAC(z,d,s,op),  PASTEMAC(z,d,c,op),  PASTEMAC(z,d,d,op),  PASTEMAC(z,d,z,op) }, \
	{ PASTEMAC(z,z,h,op), PASTEMAC(z,z,y,op),  PASTEMAC(z,z,s,op),  PASTEMAC(z,z,c,op),  PASTEMAC(z,z,d,op),  PASTEMAC(z,z,z,op) }  \
	} \
}


#define GENARRAY3_EXT(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ \
	{ PASTEMAC(h,h,h,op), PASTEMAC(h,h,y,op), NULL,               NULL,               NULL,               NULL,               }, \
	{ PASTEMAC(h,y,h,op), PASTEMAC(h,y,y,op), NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }  \
	}, \
	{ \
	{ PASTEMAC(y,h,h,op), PASTEMAC(y,h,y,op), NULL,               NULL,               NULL,               NULL,               }, \
	{ PASTEMAC(y,y,h,op), PASTEMAC(y,y,y,op), NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }  \
	}, \
	{ \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               PASTEMAC(s,s,s,op), PASTEMAC(s,s,c,op), NULL,               NULL,               }, \
	{ NULL,               NULL,               PASTEMAC(s,c,s,op), PASTEMAC(s,c,c,op), NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }  \
	}, \
	{ \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               PASTEMAC(c,s,s,op), PASTEMAC(c,s,c,op), NULL,               NULL,               }, \
	{ NULL,               NULL,               PASTEMAC(c,c,s,op), PASTEMAC(c,c,c,op), NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }  \
	}, \
	{ \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               PASTEMAC(d,d,d,op), PASTEMAC(d,d,z,op) }, \
	{ NULL,               NULL,               NULL,               NULL,               PASTEMAC(d,z,d,op), PASTEMAC(d,z,z,op) }  \
	}, \
	{ \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               NULL,               NULL,               }, \
	{ NULL,               NULL,               NULL,               NULL,               PASTEMAC(z,d,d,op), PASTEMAC(z,d,z,op) }, \
	{ NULL,               NULL,               NULL,               NULL,               PASTEMAC(z,z,d,op), PASTEMAC(z,z,z,op) }  \
	} \
}


#define GENARRAY3_MIN(arrayname,op) \
\
arrayname[BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES][BLIS_NUM_FP_TYPES] = \
{ \
	{ \
	{ PASTEMAC(h,h,h,op), NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,               NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,               NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,               NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,               NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,               NULL,                NULL,                NULL,                NULL,                NULL,               }  \
	}, \
	{ \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                PASTEMAC(y,y,y,op),  NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }  \
	}, \
	{ \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                PASTEMAC(s,s,s,op),  NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }  \
	}, \
	{ \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                PASTEMAC(c,c,c,op),  NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }  \
	}, \
	{ \
	{ NULL,                NULL,                NULL,                NULL,                NULL,               NULL,                }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,               NULL,                }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,               NULL,                }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,               NULL,                }, \
	{ NULL,                NULL,                NULL,                PASTEMAC(d,d,d,op),  NULL,               NULL,                }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,               NULL,                }  \
	}, \
	{ \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                NULL,               }, \
	{ NULL,                NULL,                NULL,                NULL,                NULL,                PASTEMAC(z,z,z,op), }  \
	} \
}


#endif
