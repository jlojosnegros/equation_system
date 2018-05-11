#include "Term.hpp"

#include <sstream>

Term::Term(double value)
 : value(value)
{

}

double Term::getValue(void) const
{
    return value;
}

void Term::multiply(double factor)
{
    value *= factor;
}

bool Term::hasName(std::string const& name) const
{
    return false;
}

bool Term::hasName(NameSet const& nameSet) const
{
    return false;
}

std::string Term::toString(void) const
{
    std::stringstream ss;
    ss << getValue()<< to_string();
    return ss.str();
}

bool Term::equal(Term const &term) const
{
    return (*this == term) && is_equal(term);
}


