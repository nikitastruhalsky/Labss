#include <gtest/gtest.h>
#include "Stack.h"
#include "Calc.h"

/////////////////////////   TESTS FOR A STACK ///////////////////////////

TEST(Stack, Push)
{
    Stack<int> stack1(10);
    stack1.push("a");
    EXPECT_EQ(stack1.peek(), "a");
    EXPECT_EQ(stack1.size(), 1);
}

TEST(Stack, Pop)
{
    Stack<int> stack1(10);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    stack1.pop();
    EXPECT_EQ(stack1.peek(), "b");
    EXPECT_EQ(stack1.size(), 2);
    EXPECT_EQ(stack1.pop(), "b");
    EXPECT_EQ(stack1.peek(),"a");
    stack1.pop();
    EXPECT_EQ(stack1.IsEmpty(), true);
}

TEST(Stack, Size)
{
    Stack<int> stack1(10);
    EXPECT_EQ(stack1.size(), 0);
    stack1.push("a");
    stack1.push("b");
    EXPECT_EQ(stack1.size(), 2);
    stack1.pop();
    EXPECT_EQ(stack1.size(), 1);
}

TEST(Stack, IsEmpty)
{
    Stack<int> stack1(10);
    EXPECT_EQ(stack1.IsEmpty(), true);
    stack1.push("a");
    EXPECT_EQ(stack1.IsEmpty(), false);
}

TEST(Stack, IsFull)
{
    Stack<int> stack1(3);
    EXPECT_EQ(stack1.IsFull(), false);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    EXPECT_EQ(stack1.IsFull(), true);
}

TEST(Oper, Oper_GetElem)
{
    Stack<int> stack1(10);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    EXPECT_EQ(stack1.operator[](2), "c");
}

TEST(Oper, Oper_Equal)
{
    Stack<int> stack1(3);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    Stack<int> stack2(3);
    stack2.push("a");
    stack2.push("b");
    stack2.push("c");
    Stack<int> stack3(3);
    stack3.push("a");
    stack3.push("b");
    stack3.push("d");
    EXPECT_EQ(stack1 == stack2, true);
    EXPECT_EQ(stack1 == stack3, false);
}

TEST(Oper, Oper_IsNotEqual)
{
    Stack<int> stack1(3);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    Stack<int> stack2(3);
    stack2.push("a");
    stack2.push("b");
    stack2.push("c");
    Stack<int> stack3(3);
    stack3.push("a");
    stack3.push("b");
    stack3.push("d");
    EXPECT_EQ(stack1 != stack2, false);
    EXPECT_EQ(stack1 != stack3, true);
}

TEST(Oper, Oper_Less)
{
    Stack<int> stack1(3);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    Stack<int> stack4(4);
    stack4.push("d");
    stack4.push("e");
    stack4.push("f");
    stack4.push("g");
    Stack<int> stack5(2);
    stack5.push("d");
    stack5.push("e");
    EXPECT_EQ(stack1 < stack4, true);
    EXPECT_EQ(stack1 < stack5, false);
}

TEST(Oper, Oper_More)
{
    Stack<int> stack1(3);
    stack1.push("a");
    stack1.push("b");
    stack1.push("c");
    Stack<int> stack4(4);
    stack4.push("d");
    stack4.push("e");
    stack4.push("f");
    stack4.push("g");
    Stack<int> stack5(2);
    stack5.push("d");
    stack5.push("e");
    EXPECT_EQ(stack1 > stack4, false);
    EXPECT_EQ(stack1 > stack5, true);
}

TEST(Stack, Peek)
{
    Stack<int> stack1(10);
    stack1.push("a");
    EXPECT_EQ(stack1.peek(),"a");
    stack1.push("b");
    EXPECT_EQ(stack1.peek(),"b");
}


////////////////////////        TESTS FOR A CALCULATOR          /////////////////////

TEST(Calc_Correct_Expr, BracketsNumber)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("( ( ( 34 * ( 3 - 4 ) ) - 22 ) * 2 )"), true);
    EXPECT_EQ(line.IsCorrect("( ( 23 - 4 ) - 12"), false);
}

TEST(Calc_Correct_Expr, CorrectWord)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("23.233.33 + 3"), false);
    EXPECT_EQ(line.IsCorrect(".121 + 3"), false);
    EXPECT_EQ(line.IsCorrect("6 & 65 + 1"), false);
    EXPECT_EQ(line.IsCorrect("23?12 + 1"), false);
    EXPECT_EQ(line.IsCorrect("--3 + 3"), false);
    EXPECT_EQ(line.IsCorrect("7 ++ 98"), false);
    EXPECT_EQ(line.IsCorrect("23- 12"), false);
}

TEST(Calc_Correct_Expr, AfterBracket)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("3 + ( )"), false);
    EXPECT_EQ(line.IsCorrect("3 + ( - 4 )"), false);
    EXPECT_EQ(line.IsCorrect("3 + ( -4 )"), true);
    EXPECT_EQ(line.IsCorrect("3 + ( 4 + 88 )"), true);
    EXPECT_EQ(line.IsCorrect("3 + ( 3 - 8 ) 45 * 6"), false);
    EXPECT_EQ(line.IsCorrect("3 + ( 3 - 8 ) ( 2 + 7 )"), false);
    EXPECT_EQ(line.IsCorrect("3 + ( 3 - 8 ) * 4"), true);
}

TEST(Calc_Correct_Expr, AfterNumber)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("3 + 23"), true);
    EXPECT_EQ(line.IsCorrect("3 - 23"), true);
    EXPECT_EQ(line.IsCorrect("3 * 23"), true);
    EXPECT_EQ(line.IsCorrect("3 / 23"), true);
    EXPECT_EQ(line.IsCorrect("3 ( 23 + 3 )"), false);
    EXPECT_EQ(line.IsCorrect("3 + 88 3"), false);
    EXPECT_EQ(line.IsCorrect("( 3 - 9 ) * 23"), true);
}

TEST(Calc_Correct_Expr, AfterMult)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("3 * 22"), true);
    EXPECT_EQ(line.IsCorrect("3 * ( 34 - 8 )"), true);
    EXPECT_EQ(line.IsCorrect("3 * * 77"), false);
    EXPECT_EQ(line.IsCorrect("3 * / 77"), false);
    EXPECT_EQ(line.IsCorrect("3 * - 77"), false);
    EXPECT_EQ(line.IsCorrect("( 3 * ) 77"), false);
    EXPECT_EQ(line.IsCorrect("3 * + 77"), false);
}

TEST(Calc_Correct_Expr, AfterDiv)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("3 / 22"), true);
    EXPECT_EQ(line.IsCorrect("3 / ( 34 - 8 )"), true);
    EXPECT_EQ(line.IsCorrect("3 / * 77"), false);
    EXPECT_EQ(line.IsCorrect("3 / / 77"), false);
    EXPECT_EQ(line.IsCorrect("3 / - 77"), false);
    EXPECT_EQ(line.IsCorrect("( 3 / ) 77"), false);
    EXPECT_EQ(line.IsCorrect("3 / + 77"), false);
}

TEST(Calc_Correct_Expr, AfterPlus)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("3 + 22"), true);
    EXPECT_EQ(line.IsCorrect("3 + ( 34 - 8 )"), true);
    EXPECT_EQ(line.IsCorrect("3 + * 77"), false);
    EXPECT_EQ(line.IsCorrect("3 + / 77"), false);
    EXPECT_EQ(line.IsCorrect("3 + - 77"), false);
    EXPECT_EQ(line.IsCorrect("( 3 + ) 77"), false);
    EXPECT_EQ(line.IsCorrect("3 + + 77"), false);
}

TEST(Calc_Correct_Expr, AfterMinus)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("3 - 22"), true);
    EXPECT_EQ(line.IsCorrect("3 - ( 34 - 8 )"), true);
    EXPECT_EQ(line.IsCorrect("3 - * 77"), false);
    EXPECT_EQ(line.IsCorrect("3 - / 77"), false);
    EXPECT_EQ(line.IsCorrect("3 - - 77"), false);
    EXPECT_EQ(line.IsCorrect("( 3 - ) 77"), false);
    EXPECT_EQ(line.IsCorrect("3 - + 77"), false);
}

TEST(Calc_Correct_Expr, EndExpr)
{
    Calculator line;
    EXPECT_EQ(line.IsCorrect("4 + 8"), true);
    EXPECT_EQ(line.IsCorrect("4 + ( 7 + 9 )"), true);
    EXPECT_EQ(line.IsCorrect("4 + 8 +"), false);
    EXPECT_EQ(line.IsCorrect("4 + 8 -"), false);
    EXPECT_EQ(line.IsCorrect("4 + 8 *"), false);
    EXPECT_EQ(line.IsCorrect("4 + 8 /"), false);
    EXPECT_EQ(line.IsCorrect("4 + ) 8 ("), false);
}

TEST(Calc_Correct_Value, Simple)
{
    Calculator line;
    std::string expr;
    EXPECT_EQ(line.count(line.algorithm("1 + 2")), 3);
    EXPECT_EQ(line.count(line.algorithm("5 * 2")), 10);
    EXPECT_EQ(line.count(line.algorithm("5 / 2")), 2.5);
    EXPECT_EQ(line.count(line.algorithm("5 - 2")), 3);
    EXPECT_EQ(line.count(line.algorithm("( 9 + 2 ) / 11")), 1);
    EXPECT_EQ(line.count(line.algorithm("5 * ( 2 + 3 )")), 25);
    EXPECT_EQ(line.count(line.algorithm("5 ^ 2")), 25);
}

TEST(Calc_Correct_Value, Negative)
{
    Calculator line;
    std::string expr;
    EXPECT_EQ(line.count(line.algorithm("-1 + 2")), 1);
    EXPECT_EQ(line.count(line.algorithm("5 * ( -2 )")), -10);
    EXPECT_EQ(line.count(line.algorithm("( -5 ) / 2")), -2.5);
    EXPECT_EQ(line.count(line.algorithm("5 - ( -2 )")), 7);
}

TEST(Calc_Correct_Value, Double)
{
    Calculator line;
    std::string expr;
    EXPECT_EQ(line.count(line.algorithm("1.3 + 2.22")), 3.52);
    EXPECT_EQ(line.count(line.algorithm("5.01 * 2")), 10.02);
    EXPECT_EQ(line.count(line.algorithm("5 / 2.5")), 2);
    EXPECT_EQ(line.count(line.algorithm("5 - 2.999")), 2.001);
    EXPECT_EQ(line.count(line.algorithm("( 9.3 + 2.6 ) / 7")), 1.7);
    EXPECT_EQ(line.count(line.algorithm("5.9 * ( 2 + 3.1 )")), 30.09);
    EXPECT_EQ(line.count(line.algorithm("2.5 ^ 2")), 6.25);
}

TEST(Calc_Correct_Value, Hard)
{
    Calculator line;
    std::string expr;
    EXPECT_EQ(line.count(line.algorithm("( 1 + 2 ) - ( 1 + 2 )")), 0);
    EXPECT_EQ(line.count(line.algorithm("24 / 6 / 2")), 2);
    EXPECT_EQ(line.count(line.algorithm("-3 - 2 * ( -1 )")), -1);
    EXPECT_EQ(line.count(line.algorithm("( 2 * 4 ) + 7 / 7 + ( 0.2 / 2 - 1 ) / 9")), 8.9);
    EXPECT_EQ(line.count(line.algorithm("( 1.2 + 0.6 ) * 10 - 6 + 2 * ( -2 - 1 ) / ( -1 )")), 18);
    EXPECT_EQ(line.count(line.algorithm("( ( ( 3 + 4 ) / 7 + 28 * 4 ) - 1324 ) * 2 - ( -2021 )")), -401);
    EXPECT_EQ(line.count(line.algorithm("( -84 / 6 ) * ( -1 ) - ( ( ( ( 23 - 32 / 4 ) / 3  + 6 * ( -1 ) ) - 17 ) / 12 - ( -3.5 ) )")), 12);
    EXPECT_FLOAT_EQ(line.count(line.algorithm("( 12.56 / 123.6 * 896 ) - ( ( -1 ) / 1235 / 89 * 52 - 65 ) / 2563 / ( 23 + 36 * 76 - 98 ) - 89 + ( -9 )")), -6.9503002);
}