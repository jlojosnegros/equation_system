#include "Expression.hpp"

#include "VariableBuilder.hpp"
#include "Variable.hpp"
#include "Constant.hpp"

#include <GUnit.h>


GTEST("Expression test")
{
    Expression expression{};
    auto x_var = VariableBuilder().name("x").value(2).build();
    auto y_var = VariableBuilder().name("y").value(3).build();
    Constant cte(5);

    expression.add(std::move(x_var));
    expression.add(std::move(y_var));
    expression.add(std::move(cte));

    SHOULD(" multiply")
    {
        std::cout << expression.toString() << std::endl;
    }

}