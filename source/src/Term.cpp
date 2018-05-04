#include "Term.hpp"

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
