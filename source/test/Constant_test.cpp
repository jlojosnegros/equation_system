#include "Constant.hpp"
#include <GUnit.h>

GTEST("Constant test")
{
    static constexpr double expected = 3.1415927;
    Constant constant(expected);

    SHOULD(" be equal to another constant")
    {
        Constant another(expected);
        EXPECT_TRUE(constant.equal(another));
    }

    SHOULD(" be equal to the cloned constant")
    {
        auto cloned = constant.clon();
        EXPECT_TRUE(cloned->equal(constant));
    }

}

