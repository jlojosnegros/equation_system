#include "Constant.hpp"

std::unique_ptr<Term> Constant::clon(void)
{
    return std::make_unique<Constant>(getValue());
}

void Constant::dispatch(TermVisitor const &termVisitor)
{

}

std::string Constant::to_string(void) const
{
    return "type: constant";
}

bool Constant::is_equal(Term const& term) const
{
    return nullptr != dynamic_cast<Constant const*>(&term);
}

