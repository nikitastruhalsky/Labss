//
// Created by Owner on 25.11.2020.
//

#include <gtest/gtest.h>
#include "ProperFraction.h"

TEST(Denominator, NotEqualToZero)
{
    ProperFraction a(3, 5);
    EXPECT_NE(a.GetDenominator(), 0);
}

TEST(Copy, IsEqualToProperFraction)
{
    ProperFraction a (2, 7);
    ProperFraction b (a);
    EXPECT_EQ(a.print(), b.print());
}

TEST(ProperFraction, IsProper)
{
    ProperFraction a(5,6);
    EXPECT_LT(a.GetNNumerator(), a.GetDenominator());
}

TEST(ProperFraction, AfterReduction)
{
    ProperFraction a(12, 16);
    EXPECT_EQ(a.print(), 0.75);
}

TEST(ProperFraction, IsIrreducible)
{
    ProperFraction a(11, 16);
    double x = (double)a.GetNNumerator() / a.GetDenominator();
    EXPECT_EQ(a.print(), x);
}

TEST(ProperFraction, IsReducible)
{
    ProperFraction a(-48, 60);
    EXPECT_EQ(a.GetNNumerator(), -4);
    EXPECT_EQ(a.GetDenominator(), 5);
}

TEST(ProperFraction, IsReducible_WithSignChange)
{
    ProperFraction a(-36, -72);
    EXPECT_EQ(a.print(), 0.5);
}

TEST(NumenatorAndDenominator, IsEqualToThreeAndFive)
{
    ProperFraction a(3, 5);
    EXPECT_EQ(a.GetNNumerator(), 3);
    EXPECT_EQ(a.GetDenominator(), 5);
}

TEST(NegativeNumenatorAndDenominator, IsEqualToThreeAndFive)
{
    ProperFraction a(-3, -5);
    EXPECT_EQ(a.GetNNumerator(), -3);
    EXPECT_EQ(a.GetDenominator(), -5);
}

TEST(AddingPozitive, Correct)
{
    ProperFraction a(2,5);
    ProperFraction b(4, 7);
    a.Add(b);
    EXPECT_EQ(a.GetNNumerator(), 34);
    EXPECT_EQ(a.GetDenominator(), 35);
}

TEST(AddingNegative, Correct)
{
    ProperFraction a(-2,9);
    ProperFraction b(-4, 9);
    a.Add(b);
    EXPECT_EQ(a.GetNNumerator(), -2);
    EXPECT_EQ(a.GetDenominator(), 3);
}

TEST(AddingNegAndPoz, Correct)
{
    ProperFraction a(-2,9);
    ProperFraction b(4, 9);
    a.Add(b);
    EXPECT_EQ(a.GetNNumerator(), 2);
    EXPECT_EQ(a.GetDenominator(), 9);
}

TEST(Mult, Correct)
{
    ProperFraction a(3, 5);
    ProperFraction b(7, 12);
    a.Multiply(b);
    EXPECT_EQ(a.GetNNumerator(), 7);
    EXPECT_EQ(a.GetDenominator(), 20);
}

TEST(MultZero, Correct)
{
    ProperFraction a(3,5);
    ProperFraction b(0, 4);
    a.Multiply(b);
    EXPECT_EQ(a.GetNNumerator(), 0);
    EXPECT_EQ(a.GetDenominator(), 20);
}

TEST(MultNeg, Correct)
{
    ProperFraction a(-3, 5);
    ProperFraction b(-7, 12);
    a.Multiply(b);
    EXPECT_EQ(a.GetNNumerator(), 7);
    EXPECT_EQ(a.GetDenominator(), 20);
}

TEST(MultPosAndNeg, Correct)
{
    ProperFraction a(-3, 5);
    ProperFraction b(7, 12);
    a.Multiply(b);
    EXPECT_EQ(a.GetNNumerator(), -7);
    EXPECT_EQ(a.GetDenominator(), 20);
}

TEST(Div, Correct)
{
    ProperFraction a(3,8);
    ProperFraction b(4, 7);
    a.Divide(b);
    EXPECT_EQ(a.GetNNumerator(), 21);
    EXPECT_EQ(a.GetDenominator(), 32);
}

TEST(DivNeg, Correct)
{
    ProperFraction a(-3, 6);
    ProperFraction b(-6, 9);
    a.Divide(b);
    EXPECT_EQ(a.print(), 0.75);
}

TEST(DivPosAndNeg, Correct)
{
    ProperFraction a(-3, 5);
    ProperFraction b(7, 11);
    a.Divide(b);
    EXPECT_EQ(a.GetNNumerator(), -33);
    EXPECT_EQ(a.GetDenominator(), 35);
}

TEST(ZeroInDenominator, Mistake)
{
    EXPECT_THROW({ ProperFraction a(3,0); }, std::invalid_argument);
}

TEST(DivOnZero, Mistake)
{
    ProperFraction a (4,5);
    ProperFraction b (0, 4);
    EXPECT_THROW({ a.Divide(b); }, std::invalid_argument);
}