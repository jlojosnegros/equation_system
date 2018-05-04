#include "Term.hpp"

#include <GUnit.h>

GTEST("Term test"){

    static constexpr double s_value = 3.1415927;
    Term term (s_value);

    SHOULD("Return the same value")
    {
        EXPECT_EQ(s_value, term.getValue()) << "Error: getValue() does not return correct value";
    }
}