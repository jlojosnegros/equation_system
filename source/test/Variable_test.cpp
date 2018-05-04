#include "Variable.hpp"
#include "Constant.hpp"

#include "NameSet.hpp"

#include <GUnit.h>

#include <iterator>

GTEST("Variable test")
{
    static constexpr auto expected_name = "variable_name";
    static constexpr double expected_value = 3.1415927;

    Variable variable(expected_value, expected_name);

    SHOULD(" have the expected name and only the expected one")
    {
        constexpr auto wrong_name = "wrong_name";
        EXPECT_NE(expected_name, wrong_name);
        EXPECT_TRUE(variable.hasName(expected_name));
        EXPECT_FALSE(variable.hasName(wrong_name));
    }

    SHOULD(" have the expected name even in a name set")
    {
        NameSet nameSet = { "name1", "name2", "name3"};
        EXPECT_EQ(std::end(nameSet), nameSet.find(expected_name));

        EXPECT_FALSE(variable.hasName(nameSet));

        nameSet.insert(expected_name);
        EXPECT_NE(std::end(nameSet), nameSet.find(expected_name));
        EXPECT_TRUE(variable.hasName(nameSet));
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

    SHOULD(" be equal to another variable")
    {
        Variable another(expected_value, expected_name);
        EXPECT_TRUE(variable.equal(another));
    }

    SHOULD(" be equal to the cloned constant")
    {
        auto cloned = variable.clon();
        EXPECT_TRUE(cloned->equal(variable));
    }

    SHOULD(" NOT be equal to a constant")
    {
        Constant constant(expected_value);
        EXPECT_FALSE(variable.equal(constant));
    }
}