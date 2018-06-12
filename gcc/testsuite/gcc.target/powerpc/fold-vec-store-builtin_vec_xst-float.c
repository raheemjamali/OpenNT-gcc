/* Verify that overloaded built-ins for __builtin_vec_xst with float
   inputs produce the right code.  */

/* { dg-require-effective-target powerpc_vsx_ok } */
/* { dg-options "-mvsx -O2" } */

#include <altivec.h>

#define BUILD_VAR_TEST(TESTNAME1, VALUE, VAR_OFFSET, SAVETO)		\
void									\
TESTNAME1 ## _var (VALUE value, VAR_OFFSET offset, SAVETO * saveto) 	\
{									\
	__builtin_vec_xst (value, offset, saveto);		\
}

#define BUILD_CST_TEST(TESTNAME1, VALUE, CST_OFFSET, SAVETO)		\
void									\
TESTNAME1 ## _cst (VALUE value, SAVETO * saveto) 			\
{									\
	__builtin_vec_xst (value, CST_OFFSET, saveto);		\
}

BUILD_VAR_TEST( test1,  vector float, signed long long, float );
BUILD_VAR_TEST( test2,  vector float, signed int, float );
BUILD_CST_TEST( test3,  vector float, 12, float );

BUILD_VAR_TEST( test4,  vector float, signed long long, vector float );
BUILD_VAR_TEST( test5,  vector float, signed int, vector float );
BUILD_CST_TEST( test6,  vector float, 12, vector float );

/* { dg-final { scan-assembler-times {\mstxvd2x\M|\mstxvx\M|\mstvx\M} 6 } } */
