#include "Variable.hpp"

#include <iterator>

Variable::Variable(double value, std::string name)
: Term(value)
, name(name)
{

}

std::string Variable::getName(void) const
{
    return name;
}

std::unique_ptr<Term> Variable::clon(void)
{
    return std::make_unique<Variable>(getValue(),name);
}

void Variable::dispatch(TermVisitor const &termVisitor)
{

}

std::string Variable::to_string(void) const
{
    return std::string("type: variable, name: ") + name;
}

bool Variable::is_equal(Term const &term) const
{
    auto var = dynamic_cast<Variable const*>(&term);
    if (nullptr == var)
    {
        return false;
    }

    return hasName(var->name);
}

bool Variable::hasName(std::string const &name) const
{
    return name == this->name;
}

bool Variable::hasName(const Term::NameSet &nameSet) const
{
    return std::end(nameSet) != nameSet.find(name);
}




