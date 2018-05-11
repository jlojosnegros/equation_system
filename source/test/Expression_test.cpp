#include "Expression.hpp"

#include "VariableBuilder.hpp"
#include "Variable.hpp"
#include "Constant.hpp"

#include "ExpressionBuilder.hpp"
#include "Expression.hpp"

#include <GUnit.h>


GTEST("Expression test")
{
    auto expression = ExpressionBuilder()
            .term(VariableBuilder().name("x").value(2).build())
            .term(VariableBuilder().name("y").value(3).build())
                    .term(Constant(5))
                            .build();
    SHOULD(" multiply")
    {
        std::cout << expression.toString() << std::endl;
    }

}