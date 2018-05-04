#ifndef _EQUATION_SYSTEM_VARIABLE_HPP_
#define _EQUATION_SYSTEM_VARIABLE_HPP_

#include "Term.hpp"

#include <string>
#include <memory>

class TermVisitor;

class Variable : public Term
{
public:
    Variable(double value, std::string name);
    ~Variable(void) override = default;

    std::string getName(void) const;
    std::unique_ptr<Term> clon(void) override;
    void dispatch(TermVisitor const &termVisitor) override;

    bool hasName(std::string const &name) const override;

    bool hasName(NameSet const &nameSet) const override;

private:
    std::string to_string(void) const override;
    bool is_equal(Term const &term) const override;

protected:
private:
    std::string name;
};


#endif //_EQUATION_SYSTEM_VARIABLE_HPP_

