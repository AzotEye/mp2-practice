#include "Polinom.h"
#include <gtest.h>

TEST(Monom, can_create_monom)
{
    ASSERT_NO_THROW(Monom m);
}

TEST(Monom, can_create_monom_with_degree_and_coeff)
{
    Monom m(7, 12);
    EXPECT_EQ(7, m.GetDegree());
    EXPECT_EQ(12, m.GetCoeff());
}

TEST(Monom, cant_create_monom_with_degree_out_of_range)
{
    ASSERT_ANY_THROW(Monom m(-1, 12));
}

TEST(Monom, can_create_monom_from_string)
{
    Monom m("-x^2");
    EXPECT_EQ(200, m.GetDegree());
    EXPECT_EQ(-1, m.GetCoeff());
}

TEST(Monom, cant_create_monom_from_invalid_string)
{
    ASSERT_ANY_THROW(Monom m(" x ^2"));
}

TEST(Monom, cant_create_monom_from_string_with_invalid_monom)
{
    ASSERT_ANY_THROW(Monom m("x^20"));
}

TEST(Monom, can_get_degree)
{
    Monom m("x^2");
    ASSERT_NO_THROW(m.GetDegree());
    EXPECT_EQ(200, m.GetDegree());
}

TEST(Monom, can_get_coeff)
{
    Monom m("-x^2");
    ASSERT_NO_THROW(m.GetCoeff());
    EXPECT_EQ(-1, m.GetCoeff());
}

TEST(Monom, equal_monoms_are_equal)
{
    Monom m("-x^2");
    Monom m1("-x^2");
    EXPECT_TRUE(m == m);
    EXPECT_TRUE(m == m1);
}

TEST(Monom, not_equal_monoms_are_not_equal)
{
    Monom m("x");
    Monom m1("x^2");
    EXPECT_TRUE(m != m1);
}

TEST(Monom, can_compare_monoms)
{
    Monom m("x");
    Monom m1("x^2");
    Monom m3("y*z");
    EXPECT_TRUE(m >= m);
    EXPECT_TRUE(m <= m);
    EXPECT_TRUE(m < m1);
    EXPECT_TRUE(m > m3);
    EXPECT_FALSE(m < m3);
    EXPECT_FALSE(m > m1);
}

TEST(Monom, can_sum_monoms_with_same_degree)
{
    Monom m("x");
    Monom m1("2*x");
    Monom m2;
    ASSERT_NO_THROW(m2 = m + m1);
    EXPECT_EQ(3, m2.GetCoeff());
    EXPECT_EQ(100, m2.GetDegree());
}

TEST(Monom, cant_sum_monoms_with_diff_degree)
{
    Monom m("x");
    Monom m1("2*x^6");
    ASSERT_ANY_THROW(m + m1);
}

TEST(Monom, can_sub_monoms_with_same_degree)
{
    Monom m("x");
    Monom m1("2*x");
    Monom m2;
    ASSERT_NO_THROW(m2 = m - m1);
    EXPECT_EQ(-1, m2.GetCoeff());
    EXPECT_EQ(100, m2.GetDegree());
}

TEST(Monom, cant_sub_monoms_with_diff_degree)
{
    Monom m("x");
    Monom m1("2*x^6");
    ASSERT_ANY_THROW(m - m1);
}

TEST(Monom, can_mul_monoms_within_degree_range)
{
    Monom m("x");
    Monom m1("2*x");
    Monom m2;
    ASSERT_NO_THROW(m2 = m * m1);
    EXPECT_EQ(2, m2.GetCoeff());
    EXPECT_EQ(200, m2.GetDegree());
}

TEST(Monom, cant_mul_monoms_outside_of_degree_range)
{
    Monom m("x^9");
    Monom m1("2*x");
    Monom m2;
    ASSERT_ANY_THROW(m2 = m * m1);
}

TEST(Monom, can_calculate_monom)
{
    Monom m("6*x^6*y");
    EXPECT_EQ(0, m(1, 0, 12314));
}

TEST(Polinom, can_create_polinom)
{
    ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_copy_polinom)
{
    Polinom p("x");
    ASSERT_NO_THROW(Polinom p1(p));
}

TEST(Polinom, copied_polinoms_are_equal)
{
    Polinom p("x");
    Polinom p1(p);
    EXPECT_TRUE(p == p1);
}

TEST(Polinom, can_create_polinom_from_string)
{
    ASSERT_NO_THROW(Polinom p("x+y+z+x^5"));
}

TEST(Polinom, cant_create_polinom_from_invalid_string)
{
    ASSERT_ANY_THROW(Polinom p("x+y +x^5"));
    ASSERT_ANY_THROW(Polinom p("x+y^999"));
}

TEST(Polinom, equal_polinoms_are_equal)
{
    Polinom p("x");
    Polinom p1("x");
    EXPECT_TRUE(p == p1);
}

TEST(Polinom, same_polinoms_are_equal)
{
    Polinom p("x");
    EXPECT_TRUE(p == p);
}

TEST(Polinom, not_equal_polinoms_are_not_equal)
{
    Polinom p("x");
    Polinom p1("x+4");
    EXPECT_TRUE(p != p1);
}

TEST(Polinom, can_assign_polinoms)
{
    Polinom p("x+y");
    Polinom p1;
    ASSERT_NO_THROW(p1 = p);
}

TEST(Polinom, assigned_polinoms_are_equal)
{
    Polinom p("x+y");
    Polinom p1("-x+y+x+x");
    p1 = p;
    EXPECT_TRUE(p1 == p);
}

TEST(Polinom, can_add_const_to_polinom)
{
    Polinom p("x+y");
    ASSERT_NO_THROW(p + 123);
}

TEST(Polinom, can_substract_const_from_polinom)
{
    Polinom p("x+y");
    ASSERT_NO_THROW(p - 123);
}

TEST(Polinom, can_multiply_polinom_on_const)
{
    Polinom p("x+y");
    ASSERT_NO_THROW(p * 123);
}

TEST(Polinom, can_add_monom_to_polinom)
{
    Polinom p("x+y");
    Monom m(100, 2);
    ASSERT_NO_THROW(p + m);
}

TEST(Polinom, can_substract_monom_from_polinom)
{
    Polinom p("x+y");
    Monom m(100, 2);
    ASSERT_NO_THROW(p - m);
}

TEST(Polinom, can_multiply_polinom_on_monom)
{
    Polinom p("x+y");
    Monom m(100, 2);
    ASSERT_NO_THROW(p * m);
}

TEST(Polinom, can_add_polinom_to_polinom)
{
    Polinom p("x+y");
    Polinom p1("z");
    ASSERT_NO_THROW(p + p1);
}

TEST(Polinom, can_substract_polinom_from_polinom)
{
    Polinom p("x+y");
    Polinom p1("z");
    ASSERT_NO_THROW(p - p1);
}

TEST(Polinom, can_multiply_polinom_on_polinom)
{
    Polinom p("x+y");
    Polinom p1("z");
    ASSERT_NO_THROW(p * p1);
}

TEST(Polinom, can_calculate_polinom)
{
    Polinom p("x+y^2-2*z-y+3*x");
    EXPECT_EQ(2, p(1,1,1));   
}

TEST(Polinom, sum)
{
    Polinom p1("x+1");
    Polinom p2("x-1");
    EXPECT_EQ(Polinom("2*x"), p1+p2);
}

TEST(Polinom, sub)
{
    Polinom p1("x+1");
    Polinom p2("x-1");
    EXPECT_EQ(Polinom("2"), p1 - p2);
}

TEST(Polinom, mul)
{
    Polinom p1("x+1");
    Polinom p2("x-1");
    EXPECT_EQ(Polinom("x^2-1"), p1 * p2);
}

TEST(Polinom, test_complicated_sum)
{
    Polinom p1("2*x*y^2*z+z^4*y");
    Polinom p2("-x*z^9+x^3-y*z^4");
    EXPECT_EQ(Polinom("x^3+2*x*y^2*z-x*z^9"), p1 + p2);
}

TEST(Polinom, test_general_polinoms_1)
{
    Polinom p1("-2*y^2*x+10*z^3*x");
    Polinom p2("z^2*x-3+2*x");
    EXPECT_EQ(Polinom("-2*y^2*x^2*z^2+10*x^2*z^5+20*x^2*z^3-4*y^2*x^2+6*x*y^2-30*x*z^3"), p1 * p2);
}

TEST(Polinom, test_general_polinoms_2)
{
    Polinom p1("-2*y^2*x+10*z^3*x");
    Polinom p2("z^3*x-3+2*x");
    EXPECT_EQ(Polinom("-2*y^2*x+11*x*z^3+2*x-3"), p1 + p2);
}
