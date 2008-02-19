/* { dg-do run } */
/* { dg-options "-msse4 -msse5 -msse4a" } */

extern void abort (void);

int
main ()
{
#if !defined __SSE__
  abort ();
#endif
#if !defined __SSE2__
  abort ();
#endif
#if !defined __SSE3__
  abort ();
#endif
#if !defined __SSSE3__
  abort ();
#endif
#if !defined __SSE4_1__
  abort ();
#endif
#if !defined __SSE4_2__
  abort ();
#endif
#if !defined __SSE4A__
  abort ();
#endif
#if !defined __SSE5__
  abort ();
#endif
  return 0;
}
