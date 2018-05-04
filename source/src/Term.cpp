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

bool Term::hasName(Term::NameSet const& nameSet) const
{
    return false;
}

std::string Term::toString(void) const
{
    std::stringstream ss;

    ss << "value:" << getValue()
       << " " << to_string();

    return ss.str();
}


