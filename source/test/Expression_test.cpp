#include "Expression.hpp"

#include "VariableBuilder.hpp"
#include "Variable.hpp"
#include "Constant.hpp"

#include "ExpressionBuilder.hpp"
#include "Expression.hpp"

#include <GUnit.h>


GTEST("Expression test")
{
    constexpr double x_value = 2;
    constexpr double y_value = 3;
    constexpr double cte_value = 5;

    auto expression = ExpressionBuilder()
            .term(VariableBuilder().name("x").value(x_value).build())
            .term(VariableBuilder().name("y").value(y_value).build())
                    .term(Constant(cte_value))
                            .build();
    SHOULD(" multiply all ")
    {
        const double factor = 2.3;
        const auto mult_expression = ExpressionBuilder()
                .term(VariableBuilder().name("x").value(factor * x_value).build())
                .term(VariableBuilder().name("y").value(factor * y_value).build())
                .term(Constant(factor*cte_value))
                .build();

        expression.multiply(factor);
//        std::cout << expression.toString() << std::endl;
//        std::cout << mult_expression.toString() << std::endl;
        EXPECT_EQ(mult_expression, expression);
    }

    SHOULD(" simplify variable in a expression with constants")
    {
        constexpr double x2_value = 3.2;

        auto expression = ExpressionBuilder()
                .term(VariableBuilder().name("x").value(x_value).build())
                .term(VariableBuilder().name("y").value(y_value).build())
                .term(Constant(cte_value))
                .term(VariableBuilder().name("x").value(x2_value).build())
                .build();

        const auto expected_expression = ExpressionBuilder()
                .term(VariableBuilder().name("x").value(x_value+x2_value).build())
                .term(VariableBuilder().name("y").value(y_value).build())
                .term(Constant(cte_value))
                .build();

        expression.simplify("x");

//        std::cout << expression.toString() << std::endl;
//        std::cout << expected_expression.toString() << std::endl;

        EXPECT_EQ(expected_expression, expression);
    }

    SHOULD(" simplify constants in expression ")
    {
        constexpr double cte2_value = 3.2;

        auto expression = ExpressionBuilder()
                .term(VariableBuilder().name("x").value(x_value).build())
                .term(VariableBuilder().name("y").value(y_value).build())
                .term(Constant(cte_value))
                .term(Constant(cte2_value))
                .build();

        const auto expected_expression = ExpressionBuilder()
                .term(VariableBuilder().name("x").value(x_value).build())
                .term(VariableBuilder().name("y").value(y_value).build())
                .term(Constant(cte_value + cte2_value))
                .build();

        expression.simplify();

//        std::cout << expression.toString() << std::endl;
//        std::cout << expected_expression.toString() << std::endl;

        EXPECT_EQ(expected_expression, expression);
    }

    SHOULD(" simplify a non existing variable in expression ")
    {
        auto cloned_expression = expression.clon();
        cloned_expression->simplify("z");

        std::cout << cloned_expression->toString() << std::endl;
        std::cout << expression.toString() << std::endl;

        EXPECT_EQ(expression, *cloned_expression.get());
    }

}