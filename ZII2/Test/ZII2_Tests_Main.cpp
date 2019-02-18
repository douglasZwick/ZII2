#include <sstream>
#include <gtest/gtest.h>
#include "Pixit.hpp"

namespace ZII2
{

// TEST 1 //
TEST(Pixit, default_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit pixit;
  EXPECT_EQ(0, pixit.GetPixels());
  EXPECT_EQ(0, pixit.GetSubpixels());
}

// TEST 2 //
TEST(Pixit, int_uint_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(5, 13);
  Pixit b = Pixit(0, 15);
  Pixit c = Pixit(0, 16);
  Pixit d = Pixit(0, 17);
  Pixit e = Pixit(-1, 0);
  Pixit f = Pixit(-1, 1);
  Pixit g = Pixit(-1, 15);
  Pixit h = Pixit(-1, 16);
  Pixit i = Pixit(-1, 17);
  Pixit j = Pixit(-1, 33);

  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  EXPECT_EQ(0, b.GetPixels());
  EXPECT_EQ(15, b.GetSubpixels());
  EXPECT_EQ(1, c.GetPixels());
  EXPECT_EQ(0, c.GetSubpixels());
  EXPECT_EQ(1, d.GetPixels());
  EXPECT_EQ(1, d.GetSubpixels());
  EXPECT_EQ(-1, e.GetPixels());
  EXPECT_EQ(0, e.GetSubpixels());
  EXPECT_EQ(-1, f.GetPixels());
  EXPECT_EQ(1, f.GetSubpixels());
  EXPECT_EQ(-1, g.GetPixels());
  EXPECT_EQ(15, g.GetSubpixels());
  EXPECT_EQ(0, h.GetPixels());
  EXPECT_EQ(0, h.GetSubpixels());
  EXPECT_EQ(0, i.GetPixels());
  EXPECT_EQ(1, i.GetSubpixels());
  EXPECT_EQ(1, j.GetPixels());
  EXPECT_EQ(1, j.GetSubpixels());

  Pixit::SetSubpixelResolution(60);

  a = Pixit(0, 1);
  b = Pixit(0, 15);
  c = Pixit(0, 16);
  d = Pixit(0, 17);
  e = Pixit(0, 59);
  f = Pixit(0, 60);
  g = Pixit(0, 61);
  h = Pixit(-1, 121);

  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(1, a.GetSubpixels());
  EXPECT_EQ(0, b.GetPixels());
  EXPECT_EQ(15, b.GetSubpixels());
  EXPECT_EQ(0, c.GetPixels());
  EXPECT_EQ(16, c.GetSubpixels());
  EXPECT_EQ(0, d.GetPixels());
  EXPECT_EQ(17, d.GetSubpixels());
  EXPECT_EQ(0, e.GetPixels());
  EXPECT_EQ(59, e.GetSubpixels());
  EXPECT_EQ(1, f.GetPixels());
  EXPECT_EQ(0, f.GetSubpixels());
  EXPECT_EQ(1, g.GetPixels());
  EXPECT_EQ(1, g.GetSubpixels());
  EXPECT_EQ(1, h.GetPixels());
  EXPECT_EQ(1, h.GetSubpixels());
}

// TEST 3 //
TEST(Pixit, copy_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(5, 13);
  Pixit b = Pixit(a);
  Pixit c = a;
  Pixit d = Pixit(-4, 3);
  Pixit e = Pixit(d);
  Pixit f = d;
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  EXPECT_EQ(5, b.GetPixels());
  EXPECT_EQ(13, b.GetSubpixels());
  EXPECT_EQ(5, c.GetPixels());
  EXPECT_EQ(13, c.GetSubpixels());
  EXPECT_EQ(-4, d.GetPixels());
  EXPECT_EQ(3, d.GetSubpixels());
  EXPECT_EQ(-4, e.GetPixels());
  EXPECT_EQ(3, e.GetSubpixels());
  EXPECT_EQ(-4, f.GetPixels());
  EXPECT_EQ(3, f.GetSubpixels());
}

// TEST 4 //
TEST(Pixit, int_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(30);
  Pixit b = Pixit(-7);
  EXPECT_EQ(30, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  EXPECT_EQ(-7, b.GetPixels());
  EXPECT_EQ(0, b.GetSubpixels());
}

// TEST 5 //
TEST(Pixit, float_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(5.25f);
  Pixit b = Pixit(1.0701f);
  Pixit c = Pixit(8.9f);
  Pixit d = Pixit(-4.0f);
  Pixit e = Pixit(-4.01f);
  Pixit f = Pixit(-4.1f);
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  EXPECT_EQ(1, b.GetPixels());
  EXPECT_EQ(1, b.GetSubpixels());
  EXPECT_EQ(8, c.GetPixels());
  EXPECT_EQ(14, c.GetSubpixels());
  EXPECT_EQ(-4, d.GetPixels());
  EXPECT_EQ(0, d.GetSubpixels());
  EXPECT_EQ(-5, e.GetPixels());
  EXPECT_EQ(Pixit::GetSubpixelResolution() - 1, e.GetSubpixels());
  EXPECT_EQ(-5, f.GetPixels());
  EXPECT_EQ(14, f.GetSubpixels());
}

// TEST 6 //
TEST(Pixit, operator_int)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(1, 8);
  Pixit b = Pixit::Zero;
  Pixit c = Pixit(-1, 8);
  int ai = int(a);
  int bi = int(b);
  int ci = int(c);
  EXPECT_EQ(1, ai);
  EXPECT_EQ(0, bi);
  EXPECT_EQ(-1, ci);
}

// TEST 7 //
TEST(Pixit, operator_bool)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(1, 8);
  Pixit b = Pixit::Zero;
  Pixit c = Pixit(-1, 8);
  bool ab = bool(a);
  bool bb = bool(b);
  bool cb = bool(c);
  EXPECT_TRUE(ab);
  EXPECT_FALSE(bb);
  EXPECT_TRUE(cb);
}

// TEST 8 //
TEST(Pixit, operator_float)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(1, 8);
  Pixit b = Pixit::Zero;
  Pixit c = Pixit(-1, 8);
  float af = float(a);
  float bf = float(b);
  float cf = float(c);
  EXPECT_FLOAT_EQ(1.5f, af);
  EXPECT_FLOAT_EQ(0.0f, bf);
  EXPECT_FLOAT_EQ(-0.5f, cf);

  Pixit::SetSubpixelResolution(60);

  a = Pixit(1, 30);
  b = Pixit::Zero;
  c = Pixit(-1, 30);
  af = float(a);
  bf = float(b);
  cf = float(c);
  EXPECT_FLOAT_EQ(1.5f, af);
  EXPECT_FLOAT_EQ(0.0f, bf);
  EXPECT_FLOAT_EQ(-0.5f, cf);
}

// TEST 9 //
TEST(Pixit, operator_assign)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(5, 13);
  Pixit b = Pixit(-3, 5);
  a = b;
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(5, a.GetSubpixels());
}

// TEST 10 //
TEST(Pixit, operator_plusequal)
{
  Pixit a = Pixit::Zero;
  a += Pixit(4, 5);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(5, a.GetSubpixels());
  a += Pixit::Zero;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(5, a.GetSubpixels());
  a += Pixit(1, Pixit::GetSubpixelResolution() - a.GetSubpixels());
  EXPECT_EQ(6, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a += Pixit(-3, 1);
  EXPECT_EQ(3, a.GetPixels());
  EXPECT_EQ(1, a.GetSubpixels());
  a += Pixit(0, 15);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a += Pixit(-4);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a += Pixit(0, 8);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a += Pixit(-1);
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a += Pixit(2);
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a += Pixit(-0.5f);
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a += Pixit::One;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 11 //
TEST(Pixit, operator_minusequal)
{
  Pixit a = Pixit::Zero;
  a -= Pixit(4, 5);
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(11, a.GetSubpixels());
  a -= Pixit::Zero;
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(11, a.GetSubpixels());
  a -= Pixit(1, 11);
  EXPECT_EQ(-6, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a -= Pixit(-4, 15);
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(1, a.GetSubpixels());
  a -= Pixit(0, 1);
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a -= Pixit(-1);
  EXPECT_EQ(-2, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a -= Pixit(0, 8);
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a -= Pixit(-1);
  EXPECT_EQ(-2, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a -= Pixit(2);
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a -= Pixit(-0.5f);
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a -= Pixit::One;
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 12 //
TEST(Pixit, operator_timesequal)
{
  Pixit a = Pixit::One;
  a *= Pixit(2, 3);
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a *= Pixit::One;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a *= Pixit::Zero;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(4, 5);
  a *= Pixit(1, 1);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= Pixit(-1);
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a *= Pixit(11, 11);
  EXPECT_EQ(-54, a.GetPixels());
  EXPECT_EQ(10, a.GetSubpixels());
  a *= Pixit(2);
  EXPECT_EQ(-107, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a *= Pixit(1.1f);
  EXPECT_EQ(-114, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= Pixit(0);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 13 //
TEST(Pixit, operator_timesequal_int)
{
  Pixit a = Pixit::One;
  a *= Pixit(2, 3);
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a *= 1;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a *= 0;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(4, 5);
  a *= Pixit(1, 1);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= -1;
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a *= Pixit(11, 11);
  EXPECT_EQ(-54, a.GetPixels());
  EXPECT_EQ(10, a.GetSubpixels());
  a *= 2;
  EXPECT_EQ(-107, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a *= Pixit(1.1f);
  EXPECT_EQ(-114, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= 0;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 14 //
TEST(Pixit, operator_timesequal_float)
{
  Pixit a = Pixit::One;
  a *= 2.1875f;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a *= 1.0f;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a *= 0.0f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(4, 5);
  a *= 1.0625f;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= -1.0f;
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a *= 11.6875f;
  EXPECT_EQ(-54, a.GetPixels());
  EXPECT_EQ(10, a.GetSubpixels());
  a *= 2.0f;
  EXPECT_EQ(-107, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a *= 1.1f;
  EXPECT_EQ(-118, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= 0.0f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 15 //
TEST(Pixit, operator_divideequal)
{
  Pixit a = Pixit(9, 9);
  a /= Pixit(2, 5);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a /= Pixit::One;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a /= a;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a /= Pixit(2);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a /= Pixit(1.1f);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a /= Pixit(0, 8);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(14, a.GetSubpixels());
  a /= Pixit(-1, 15);
  EXPECT_EQ(-14, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 16 //
TEST(Pixit, operator_divideequal_int)
{
  Pixit a = Pixit(9, 9);
  a /= Pixit(2, 5);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a /= 1;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a /= a;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a /= 2;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a /= Pixit(1.1f);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a /= Pixit(0, 8);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(14, a.GetSubpixels());
  a /= Pixit(-1, 15);
  EXPECT_EQ(-14, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 17 //
TEST(Pixit, operator_divideequal_float)
{
  Pixit a = Pixit(9, 9);
  a /= 2.3125f;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a /= 1.0f;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a /= a;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a /= 2.0f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a /= 1.1f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a /= 0.5f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(14, a.GetSubpixels());
  a /= -0.0625f;
  EXPECT_EQ(-14, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 18 //
TEST(Pixit, operator_negate)
{
  Pixit a = -Pixit::One;
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = -Pixit::Zero;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = -Pixit(3, 5);
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(11, a.GetSubpixels());
  a = -Pixit(-7, 13);
  EXPECT_EQ(6, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = -a;
  EXPECT_EQ(-7, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
}

// TEST 19 //
TEST(Pixit, operator_plusplus)
{
  Pixit a = Pixit::Zero;
  ++a;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(1, a.GetSubpixels());
  a = Pixit(0, 15);
  ++a;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(-1);
  ++a;
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(1, a.GetSubpixels());
  a = Pixit(-1, 15);
  ++a;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 20 //
TEST(Pixit, operator_minusminus)
{
  Pixit a = Pixit::Zero;
  --a;
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(15, a.GetSubpixels());
  a = Pixit(0, 1);
  --a;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(1, 0);
  --a;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(15, a.GetSubpixels());
}

// TEST 21 //
TEST(Pixit, ispos)
{
  Pixit a = Pixit::One;
  Pixit b = Pixit(0, 8);
  Pixit c = Pixit::Zero;
  Pixit d = Pixit(-1, 8);
  Pixit e = -Pixit::One;
  EXPECT_TRUE(a.IsPos());
  EXPECT_TRUE(b.IsPos());
  EXPECT_FALSE(c.IsPos());
  EXPECT_FALSE(d.IsPos());
  EXPECT_FALSE(e.IsPos());
}

// TEST 22 //
TEST(Pixit, iszero)
{
  Pixit a = Pixit::One;
  Pixit b = Pixit(0, 8);
  Pixit c = Pixit::Zero;
  Pixit d = Pixit(-1, 8);
  Pixit e = -Pixit::One;
  EXPECT_FALSE(a.IsZero());
  EXPECT_FALSE(b.IsZero());
  EXPECT_TRUE(c.IsZero());
  EXPECT_FALSE(d.IsZero());
  EXPECT_FALSE(e.IsZero());
}

// TEST 23 //
TEST(Pixit, isneg)
{
  Pixit a = Pixit::One;
  Pixit b = Pixit(0, 8);
  Pixit c = Pixit::Zero;
  Pixit d = Pixit(-1, 8);
  Pixit e = -Pixit::One;
  EXPECT_FALSE(a.IsNeg());
  EXPECT_FALSE(b.IsNeg());
  EXPECT_FALSE(c.IsNeg());
  EXPECT_TRUE(d.IsNeg());
  EXPECT_TRUE(e.IsNeg());
}

// FRIENDS AND FAMILY //

// TEST 24 //
TEST(Pixit, operator_plus)
{
  Pixit a = Pixit::Zero + Pixit::Zero;  // should be 0p0
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = a + Pixit::One;                   // should be 1p0
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit::One + Pixit::One;          // should be 2p0
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(3, 9) + Pixit(9, 14);       // should be 13p7
  EXPECT_EQ(13, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a = a + Pixit(-13, 9);                // should be 1p0
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = a + Pixit(-7, 1);                 // should be -6p1
  EXPECT_EQ(-6, a.GetPixels());
  EXPECT_EQ(1, a.GetSubpixels());
  a = a + Pixit(0, 15);                 // should be -5p0
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit::One + Pixit(5.5f);         // should be 6p8
  EXPECT_EQ(6, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
}

// TEST 25 //
TEST(Pixit, operator_minus)
{
  Pixit a = Pixit::Zero - Pixit::Zero;  // should be 0p0
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = a - Pixit::One;                   // should be -1p0
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit::One - Pixit::One;          // should be 0p0
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = -Pixit(2, 7) - Pixit(9, 14);      // should be -13p11
  EXPECT_EQ(-13, a.GetPixels());
  EXPECT_EQ(11, a.GetSubpixels());
  a = a - Pixit(-14, 11);               // should be 1p0
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = a - Pixit(7, 1);                  // should be -7p15
  EXPECT_EQ(-7, a.GetPixels());
  EXPECT_EQ(15, a.GetSubpixels());
  a = a - Pixit(0, 15);                 // should be -7p0
  EXPECT_EQ(-7, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(5.5f) - Pixit::One;         // should be 4p8
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
}

// TEST 26 //
TEST(Pixit, operator_times)
{
  Pixit a = Pixit::One * Pixit(2, 3);
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = Pixit(2, 3) * Pixit::One;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = Pixit(2, 3) * Pixit::Zero;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(4, 5) * Pixit(1, 1);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = Pixit(4, 9) * Pixit(-1);
  EXPECT_EQ(-5, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a = Pixit(-5, 7) * Pixit(11, 11);
  EXPECT_EQ(-54, a.GetPixels());
  EXPECT_EQ(10, a.GetSubpixels());
  a = Pixit(-54, 10) * Pixit(2);
  EXPECT_EQ(-107, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a = Pixit(-107, 4) * Pixit(1.1f);
  EXPECT_EQ(-114, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = Pixit(-114, 9) * Pixit(0);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 27 //
TEST(Pixit, operator_times_int)
{
  Pixit a = Pixit::One * 5;
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = 5 * Pixit::One;
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(1, 8) * 2;
  EXPECT_EQ(3, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = 2 * Pixit(1, 8);
  EXPECT_EQ(3, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(1, 1) * 15;
  EXPECT_EQ(15, a.GetPixels());
  EXPECT_EQ(15, a.GetSubpixels());
  a = 15 * Pixit(1, 1);
  EXPECT_EQ(15, a.GetPixels());
  EXPECT_EQ(15, a.GetSubpixels());
  a = Pixit(0, 15) * 7;
  EXPECT_EQ(6, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = 7 * Pixit(0, 15);
  EXPECT_EQ(6, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = Pixit(1, 13) * 45;
  EXPECT_EQ(81, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = 45 * Pixit(1, 13);
  EXPECT_EQ(81, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = Pixit(1, 1) * -3;
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  a = -3 * Pixit(1, 1);
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  a = Pixit(-1, 1) * -3;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  a = -3 * Pixit(-1, 1);
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  a = -Pixit(1, 1) * -3;
  EXPECT_EQ(3, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = -3 * -Pixit(1, 1);
  EXPECT_EQ(3, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = -Pixit(-1, 1) * -3;
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = -3 * -Pixit(-1, 1);
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = Pixit::Zero * -99;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = -99 * Pixit::Zero;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(-15, 15) * 0;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = 0 * Pixit(-15, 15);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 28 //
TEST(Pixit, operator_times_float)
{
  Pixit a = Pixit::One * 5.0f;
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = 5.0f * Pixit::One;
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit::Zero * -99.9f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = -99.9f * Pixit::Zero;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(-15, 15) * 0.0f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = 0.0f * Pixit(-15, 15);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(3, 9) * 0.3333333333333333333333333f;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = 0.3333333333333333333333333f * Pixit(3, 9);
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = Pixit(5, 3) * 0.5f;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = 0.5f * Pixit(5, 3);
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = Pixit(1, 1) * 1.1f;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a = 1.1f * Pixit(1, 1);
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a = Pixit(1, 15) * 2.2f;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a = 2.2f * Pixit(1, 15);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a = Pixit(5, 13) * -0.1f;
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(6, a.GetSubpixels());
  a = -0.1f * Pixit(5, 13);
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(6, a.GetSubpixels());
  a = -Pixit(5, 13) * 0.1f;
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(6, a.GetSubpixels());
  a = 0.1f * -Pixit(5, 13);
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(6, a.GetSubpixels());
  a = -Pixit(5, 13) * -0.1f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = -0.1f * -Pixit(5, 13);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
}

// TEST 29 //
TEST(Pixit, operator_divide)
{
  Pixit a = Pixit(9, 9) / Pixit(2, 5);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a = Pixit(4, 2) / Pixit::One;
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a = Pixit(4, 2) / a;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit::One / Pixit(2);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a = Pixit(0, 8) / Pixit(1.1f);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a = Pixit(0, 7) / Pixit(0, 8);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(14, a.GetSubpixels());
  a = Pixit(0, 14) / Pixit(-1, 15);
  EXPECT_EQ(-14, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 30 //
TEST(Pixit, operator_divide_float)
{
  Pixit a = Pixit::One / (0.2f);
  EXPECT_EQ(5, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit::Zero / (1 / -99.9f);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a = Pixit(3, 9) / 3.0f;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(3, a.GetSubpixels());
  a = Pixit(5, 3) / 2.0f;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a = Pixit(1, 1) / (1 / 1.1f);
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(2, a.GetSubpixels());
  a = Pixit(1, 15) / (1 / 2.2f);
  EXPECT_EQ(4, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a = Pixit(5, 13) / (1 / -0.1f);
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(6, a.GetSubpixels());
  a = -Pixit(5, 13) / (1 / 0.1f);
  EXPECT_EQ(-1, a.GetPixels());
  EXPECT_EQ(6, a.GetSubpixels());
  a = -Pixit(5, 13) / (1 / -0.1f);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
}

Pixit p12 = Pixit(1, 2);
Pixit p13 = Pixit(1, 3);
Pixit p21 = Pixit(2, 1);
Pixit p23 = Pixit(2, 3);
Pixit p31 = Pixit(3, 1);
Pixit p32 = Pixit(3, 2);

// TEST 31 //
TEST(Pixit, operator_eq)
{
  EXPECT_FALSE(p12 == p13);
  EXPECT_FALSE(p13 == p23);
  EXPECT_TRUE(p12 == Pixit(1, 2));
}

// TEST 32 //
TEST(Pixit, operator_ne)
{
  EXPECT_TRUE(p12 != p13);
  EXPECT_TRUE(p13 != p23);
  EXPECT_FALSE(p12 != Pixit(1, 2));
}

// TEST 33 //
TEST(Pixit, operator_gt)
{
  EXPECT_TRUE(p32 > p12);
  EXPECT_FALSE(p12 > p32);
  EXPECT_TRUE(p13 > p12);
  EXPECT_FALSE(p12 > p13);
  EXPECT_FALSE(Pixit::Zero > Pixit::Zero);
}

// TEST 34 //
TEST(Pixit, operator_ge)
{
  EXPECT_TRUE(p32 >= p12);
  EXPECT_FALSE(p12 >= p32);
  EXPECT_TRUE(p13 >= p12);
  EXPECT_FALSE(p12 >= p13);
  EXPECT_TRUE(Pixit::Zero >= Pixit::Zero);
}

// TEST 35 //
TEST(Pixit, operator_lt)
{
  EXPECT_FALSE(p32 < p12);
  EXPECT_TRUE(p12 < p32);
  EXPECT_FALSE(p13 < p12);
  EXPECT_TRUE(p12 < p13);
  EXPECT_FALSE(Pixit::Zero < Pixit::Zero);
}

// TEST 36 //
TEST(Pixit, operator_le)
{
  EXPECT_FALSE(p32 <= p12);
  EXPECT_TRUE(p12 <= p32);
  EXPECT_FALSE(p13 <= p12);
  EXPECT_TRUE(p12 <= p13);
  EXPECT_TRUE(Pixit::Zero <= Pixit::Zero);
}

// TEST 37 //
TEST(Pixit, operator_stream_insertion)
{
  Pixit a;
  std::stringstream stream;
  a = Pixit(1, 2);
  stream = std::stringstream() << a;
  EXPECT_STREQ("1_2", stream.str().c_str());
  Pixit::sDelimiter = "p";
  stream = std::stringstream() << a;
  EXPECT_STREQ("1p2", stream.str().c_str());
  a = Pixit(-5, 13);
  stream = std::stringstream() << a;
  EXPECT_STREQ("-5p13", stream.str().c_str());
}

} // namespace ZII2
