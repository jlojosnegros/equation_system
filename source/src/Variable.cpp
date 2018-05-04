#include "Variable.hpp"

Variable::Variable(double value, std::string name)
: Term(value)
, name(name)
{

}

std::string Variable::getName(void) const
{
    return std::__cxx11::string();
}

std::unique_ptr<Term> Variable::clon(void)
{
    return nullptr;
}

void Variable::dispatch(TermVisitor const &termVisitor)
{

}

std::string Variable::to_string(void) const
{
    return nullptr;
}

bool Variable::is_equal(Term const &term) const
{
    return false;
}

bool Variable::hasName(std::string const &name) const
{
    return Term::hasName(name);
}

bool Variable::hasName(const Term::NameSet &nameSet) const
{
    return Term::hasName(nameSet);
}




