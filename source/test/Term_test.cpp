#include "Term.hpp"

#include <GUnit.h>

GTEST("Term test"){

    static constexpr double s_value = 3.1415927;
    Term term (s_value);

    SHOULD("Return the current value")
    {
        EXPECT_EQ(s_value, term.getValue()) << "Error: getValue() does not return correct value";
    }

    SHOULD("multiply the internal value")
    {
        constexpr double factor = 2.12345;
        term.multiply(factor);
        EXPECT_EQ(s_value*factor, term.getValue());
    }

}