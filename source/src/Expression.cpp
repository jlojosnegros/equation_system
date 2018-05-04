#include "Expression.hpp"

#include "Term.hpp"

void Expression::add(std::unique_ptr<Term> term)
{
    termList.push_back(term);
}

void Expression::add(Term &&term)
{
    add(term.clon());
}

void Expression::add(std::unique_ptr<Expression> expression)
{
    for (auto term : expression->termList)
    {
        termList.push_back(term);
    }
}

void Expression::add(Expression&& expression)
{
    add(expression.clon());
}

void Expression::multiply(double value)
{
    for (auto term : termList)
    {
        term->multiply(value);
    }
}

void Expression::simplify(std::string name)
{

}

void Expression::simplify(void)
{

}

double Expression::getValue(std::string name) const
{
    return 0;
}

double Expression::getValue(void) const
{
    return 0;
}

NameSet Expression::getNameSet(void) const
{
    return NameSet();
}

bool Expression::hasName(std::string name) const
{
    return false;
}

void Expression::apply(std::string name, double value)
{

}

bool Expression::equal(Expression const &expression) const
{
    return false;
}

std::unique_ptr<Expression> Expression::clon(void) const
{
    return std::unique_ptr<Expression>();
}

std::string Expression::toString(void) const
{
    return std::__cxx11::string();
}

bool Expression::empty(void) const
{
    return false;
}

