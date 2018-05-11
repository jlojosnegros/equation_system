#ifndef EQUATION_SYSTEM_TEST_EXPRESSIONBUILDER_HPP
#define EQUATION_SYSTEM_TEST_EXPRESSIONBUILDER_HPP

#include "Expression.hpp"

class ExpressionBuilder final
{
public:
    ExpressionBuilder(void) = default;
    ~ExpressionBuilder() = default;

    ExpressionBuilder(ExpressionBuilder const& rhs) = delete;
    ExpressionBuilder& operator=(ExpressionBuilder const& rhs) = delete;

    ExpressionBuilder(ExpressionBuilder&& rhs) = delete;
    ExpressionBuilder& operator=(ExpressionBuilder&& rhs) = delete;

    ExpressionBuilder& term(Term&& term);
    ExpressionBuilder& expression(Expression&& expression);
    Expression build() const;
protected:
private:
    Expression m_expresion;
};

#endif //EQUATION_SYSTEM_TEST_EXPRESSIONBUILDER_HPP
