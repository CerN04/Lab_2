#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "Decimal.h"

std::string DecimalToString(const Decimal &d) { // Всопмогательная ф-я
    std::string result;
    for (size_t i = d.GetSize(); i > 0; --i) {
        result += d.GetItem(i - 1);
    }
    return result;
}

TEST(DecimalTest, DefaultConstructor) {
    Decimal d;
    EXPECT_EQ(d.GetSize(), 0);
}

TEST(DecimalTest, SizeValueConstructor) {
    Decimal d(3, '5');
    EXPECT_EQ(d.GetSize(), 3);
    EXPECT_EQ(d.GetItem(0), '5');
    EXPECT_EQ(d.GetItem(1), '5');
    EXPECT_EQ(d.GetItem(2), '5');
}

TEST(DecimalTest, StringConstructor) {
    Decimal d("12345");
    EXPECT_EQ(d.GetSize(), 5);
    EXPECT_EQ(d.GetItem(0), '5');
    EXPECT_EQ(d.GetItem(1), '4');
    EXPECT_EQ(d.GetItem(2), '3');
    EXPECT_EQ(d.GetItem(3), '2');
    EXPECT_EQ(d.GetItem(4), '1');
}

TEST(DecimalTest, Add) {
    Decimal a("123");
    Decimal b("456");
    Decimal result = a.Add(b);
    EXPECT_EQ(DecimalToString(result), "579");
}

TEST(DecimalTest, AddWithCarry) {
    Decimal a("999");
    Decimal b("1");
    Decimal result = a.Add(b);
    EXPECT_EQ(DecimalToString(result), "1000");
}

TEST(DecimalTest, Sub) {
    Decimal a("456");
    Decimal b("123");
    Decimal result = a.Sub(b);
    EXPECT_EQ(DecimalToString(result), "333");
}

TEST(DecimalTest, SubWithBorrow) {
    Decimal a("1000");
    Decimal b("1");
    Decimal result = a.Sub(b);
    EXPECT_EQ(DecimalToString(result), "999");
}

TEST(DecimalTest, SubNegativeResult) {
    Decimal a("123");
    Decimal b("456");
    EXPECT_THROW(a.Sub(b), std::logic_error);
}

TEST(DecimalTest, Equal) {
    Decimal a("123");
    Decimal b("123");
    EXPECT_TRUE(a.Equal(b));
}

TEST(DecimalTest, NotEqual) {
    Decimal a("123");
    Decimal b("124");
    EXPECT_FALSE(a.Equal(b));
}

TEST(DecimalTest, More) {
    Decimal a("124");
    Decimal b("123");
    EXPECT_TRUE(a.More(b));
}

TEST(DecimalTest, Less) {
    Decimal a("123");
    Decimal b("124");
    EXPECT_TRUE(a.Less(b));
}

TEST(DecimalTest, Print) {
    Decimal d("12345");
    testing::internal::CaptureStdout();
    d.Print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "12345\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
