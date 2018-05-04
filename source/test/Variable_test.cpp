#include "Variable.hpp"

#include <GUnit.h>

GTEST("Variable test")
{
    static constexpr auto expected_name = "variable_name";
    static constexpr double expected_value = 3.1415927;

    Variable variable(expected_value, expected_name);

    SHOULD(" have the exected name and only the expected one")
    {
        constexpr auto wrong_name = "wrong_name";
        EXPECT_NE(expected_name, wrong_name);
        EXPECT_TRUE(variable.hasName(expected_name));
        EXPECT_FALSE(variable.hasName(wrong_name));
    }

    SHOULD(" return the expected name")
    {
        EXPECT_EQ(expected_name, variable.getName());
    }

    SHOULD(" return the expected value")
    {
        EXPECT_EQ(expected_value, variable.getValue());
    }

    SHOULD(" multiply the value")
    {
        constexpr double factor = 2.3;
        variable.multiply(factor);
        EXPECT_EQ(expected_value*factor, variable.getValue());
    }
}