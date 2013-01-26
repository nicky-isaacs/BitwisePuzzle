/* Testing Code */

#include <limits.h>
int test_isZero(int x) {
  return x == 0;
}
int test_tmax(void) {
  return LONG_MAX;
}
int test_fitsBits(int x, int n)
{
  int TMin_n = -(1 << (n-1));
  int TMax_n = (1 << (n-1)) - 1;
  return x >= TMin_n && x <= TMax_n;
}
int test_negate(int x) {
  return -x;
}
int test_addOK(int x, int y)
{
  int sum = x+y;
  return !(x < 0 && y < 0 && sum >= 0) && !(x > 0 && y > 0 && sum <= 0);
}
int test_reverseBytes(int x)
{
  union U {
    int result;
    char byte[4];
  };
  union U u;
  int temp;
  u.result = x;
  temp = u.byte[0];
  u.byte[0] = u.byte[3];
  u.byte[3] = temp;
  temp = u.byte[1];
  u.byte[1] = u.byte[2];
  u.byte[2] = temp;
  return u.result;
}
int test_logicalShift(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}
int test_conditional(int x, int y, int z)
{
  return x?y:z;
}
int test_sm2tc(int x) {
  int sign = x < 0;
  int mag = x & LONG_MAX;
  return sign ? -mag : mag;
}
int test_bitParity(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result ^= (x >> i) & 0x1;
  return result;
}
int test_isPower2(int x) {
  int i;
  for (i = 0; i < 31; i++) {
    if (x == 1<<i)
      return 1;
  }
  return 0;
}
int test_bang(int x)
{
  return !x;
}
int test_classLog2(int x) {
  int mask, result;
  /* find the leftmost bit */
  result = 31;
  mask = 1 << result;
  while (!(x & mask)) {
    result--;
    mask = 1 << result;
  }
  return result;
}
