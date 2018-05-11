#ifndef EQUATION_SYSTEM_TERMVISITOR_HPP
#define EQUATION_SYSTEM_TERMVISITOR_HPP

#include "fwdVisitableTerms.hpp"

class TermVisitor
{
public:
    virtual void visit(Variable const& variable) = 0;
    virtual void visit(Constant const& constant) = 0;
    virtual ~TermVisitor() = default;
protected:
private:
};

#endif //EQUATION_SYSTEM_TERMVISITOR_HPP
