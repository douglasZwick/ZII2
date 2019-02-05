#include <gtest/gtest.h>
#include "Pixit.hpp"

namespace ZII2
{

class PixitTester : public ::testing::Test
{}; // class Pixit_Tester

// TEST 1 //
TEST_F(PixitTester, default_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit pixit;
  EXPECT_EQ(0, pixit.GetPixels());
  EXPECT_EQ(0, pixit.GetSubpixels());
}

// TEST 2 //
TEST_F(PixitTester, int_uint_ctor)
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

  EXPECT_EQ(5,  a.GetPixels());
  EXPECT_EQ(13, a.GetSubpixels());
  EXPECT_EQ(0,  b.GetPixels());
  EXPECT_EQ(15, b.GetSubpixels());
  EXPECT_EQ(1,  c.GetPixels());
  EXPECT_EQ(0,  c.GetSubpixels());
  EXPECT_EQ(1,  d.GetPixels());
  EXPECT_EQ(1,  d.GetSubpixels());
  EXPECT_EQ(-1, e.GetPixels());
  EXPECT_EQ(0,  e.GetSubpixels());
  EXPECT_EQ(-1, f.GetPixels());
  EXPECT_EQ(1,  f.GetSubpixels());
  EXPECT_EQ(-1, g.GetPixels());
  EXPECT_EQ(15, g.GetSubpixels());
  EXPECT_EQ(0,  h.GetPixels());
  EXPECT_EQ(0,  h.GetSubpixels());
  EXPECT_EQ(0,  i.GetPixels());
  EXPECT_EQ(1,  i.GetSubpixels());
  EXPECT_EQ(1,  j.GetPixels());
  EXPECT_EQ(1,  j.GetSubpixels());

  Pixit::SetSubpixelResolution(60);

  a = Pixit(0, 1);
  b = Pixit(0, 15);
  c = Pixit(0, 16);
  d = Pixit(0, 17);
  e = Pixit(0, 59);
  f = Pixit(0, 60);
  g = Pixit(0, 61);
  h = Pixit(-1, 121);

  EXPECT_EQ(0,  a.GetPixels());
  EXPECT_EQ(1,  a.GetSubpixels());
  EXPECT_EQ(0,  b.GetPixels());
  EXPECT_EQ(15, b.GetSubpixels());
  EXPECT_EQ(0,  c.GetPixels());
  EXPECT_EQ(16, c.GetSubpixels());
  EXPECT_EQ(0,  d.GetPixels());
  EXPECT_EQ(17, d.GetSubpixels());
  EXPECT_EQ(0,  e.GetPixels());
  EXPECT_EQ(59, e.GetSubpixels());
  EXPECT_EQ(1,  f.GetPixels());
  EXPECT_EQ(0,  f.GetSubpixels());
  EXPECT_EQ(1,  g.GetPixels());
  EXPECT_EQ(1,  g.GetSubpixels());
  EXPECT_EQ(1,  h.GetPixels());
  EXPECT_EQ(1,  h.GetSubpixels());
}

// TEST 3 //
TEST_F(PixitTester, copy_ctor)
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
TEST_F(PixitTester, int_ctor)
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
TEST_F(PixitTester, float_ctor)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(5.25f);
  Pixit b = Pixit(1.0701f);
  Pixit c = 8.9f;
  Pixit d = Pixit(-4.0f);
  Pixit e = Pixit(-4.01f);
  Pixit f = -4.1f;
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
TEST_F(PixitTester, operator_int)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(1, 8);
  Pixit b = Pixit::Zero;
  Pixit c = Pixit(-1, 8);
  int ai = a;
  int bi = b;
  int ci = c;
  EXPECT_EQ(1, ai);
  EXPECT_EQ(0, bi);
  EXPECT_EQ(-1, ci);
}

// TEST 7 //
TEST_F(PixitTester, operator_bool)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(1, 8);
  Pixit b = Pixit::Zero;
  Pixit c = Pixit(-1, 8);
  bool ab = a;
  bool bb = b;
  bool cb = c;
  EXPECT_TRUE(ab);
  EXPECT_FALSE(bb);
  EXPECT_TRUE(cb);
}

// TEST 8 //
TEST_F(PixitTester, operator_float)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(1, 8);
  Pixit b = Pixit::Zero;
  Pixit c = Pixit(-1, 8);
  float af = a;
  float bf = b;
  float cf = c;
  EXPECT_FLOAT_EQ(1.5f, af);
  EXPECT_FLOAT_EQ(0.0f, bf);
  EXPECT_FLOAT_EQ(-0.5f, cf);

  Pixit::SetSubpixelResolution(60);

  a = Pixit(1, 30);
  b = Pixit::Zero;
  c = Pixit(-1, 30);
  af = a;
  bf = b;
  cf = c;
  EXPECT_FLOAT_EQ(1.5f, af);
  EXPECT_FLOAT_EQ(0.0f, bf);
  EXPECT_FLOAT_EQ(-0.5f, cf);
}

// TEST 9 //
TEST_F(PixitTester, operator_assign)
{
  Pixit::SetSubpixelResolution(16);

  Pixit a = Pixit(5, 13);
  Pixit b = Pixit(-3, 5);
  a = b;
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(5, a.GetSubpixels());
}

// TEST 10 //
TEST_F(PixitTester, operator_plusequal)
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
  a += 2;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a += -0.5f;
  EXPECT_EQ(1, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a += Pixit::One;
  EXPECT_EQ(2, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 11 //
TEST_F(PixitTester, operator_minusequal)
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
  a -= 2;
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a -= -0.5f;
  EXPECT_EQ(-3, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
  a -= Pixit::One;
  EXPECT_EQ(-4, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 12 //
TEST_F(PixitTester, operator_timesequal)
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
  a *= 2;
  EXPECT_EQ(-107, a.GetPixels());
  EXPECT_EQ(4, a.GetSubpixels());
  a *= 1.1f;
  EXPECT_EQ(-114, a.GetPixels());
  EXPECT_EQ(9, a.GetSubpixels());
  a *= 0;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 13 //
TEST_F(PixitTester, operator_divideequal)
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
  a /= 2;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(8, a.GetSubpixels());
  a /= 1.1f;
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(7, a.GetSubpixels());
  a /= Pixit(0, 8);
  EXPECT_EQ(0, a.GetPixels());
  EXPECT_EQ(14, a.GetSubpixels());
  a /= Pixit(-1, 15);
  EXPECT_EQ(-14, a.GetPixels());
  EXPECT_EQ(0, a.GetSubpixels());
}

// TEST 14 //
TEST_F(PixitTester, operator_negate)
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

// TEST 15 //
TEST_F(PixitTester, operator_plusplus)
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

// TEST 16 //
TEST_F(PixitTester, operator_minusminus)
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

// TEST 17 //
TEST_F(PixitTester, ispos)
{
  Pixit a = Pixit::One;
  Pixit b = Pixit::Zero;
  Pixit c = -Pixit::One;
  EXPECT_TRUE(a.IsPos());
  EXPECT_FALSE(b.IsPos());
  EXPECT_FALSE(c.IsPos());
}

// TEST 18 //
TEST_F(PixitTester, iszero)
{
  Pixit a = Pixit::One;
  Pixit b = Pixit::Zero;
  Pixit c = -Pixit::One;
  EXPECT_FALSE(a.IsZero());
  EXPECT_TRUE(b.IsZero());
  EXPECT_FALSE(c.IsZero());
}

// TEST 19 //
TEST_F(PixitTester, isneg)
{
  Pixit a = Pixit::One;
  Pixit b = Pixit::Zero;
  Pixit c = -Pixit::One;
  EXPECT_FALSE(a.IsNeg());
  EXPECT_FALSE(b.IsNeg());
  EXPECT_TRUE(c.IsNeg());
}

} // namespace ZII2
