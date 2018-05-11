#include "ExpressionBuilder.hpp"

#include <utility>

ExpressionBuilder& ExpressionBuilder::term(Term&& term)
{
    m_expresion.add(std::move(term));
    return *this;
}

ExpressionBuilder& ExpressionBuilder::expression(Expression&& expression)
{
    m_expresion.add(std::move(expression));
    return *this;
}

Expression ExpressionBuilder::build() const
{
    return std::move(m_expresion);
}
