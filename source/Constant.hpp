#ifndef _EQUATION_SYSTEM_CONSTANT_HPP_
#define _EQUATION_SYSTEM_CONSTANT_HPP_

#include "Term.hpp"

class Constant : public Term
{
public:
    using Term::Term;//Constant(double value);
    ~Constant(void) override = default;

    std::unique_ptr<Term> clon(void) override;
    void dispatch(TermVisitor const &termVisitor) override;

private:
    std::string to_string(void) const override;
    bool is_equal(Term const& term) const override;

protected:
private:
};

#endif // _EQUATION_SYSTEM_CONSTANT_HPP_
