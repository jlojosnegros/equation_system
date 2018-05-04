#ifndef _EQUATION_SYSTEM_TERM_HPP_
#define _EQUATION_SYSTEM_TERM_HPP_

#include <string>
#include <set>

class Term
{
public:
    using NameSet = std::set<std::string>;

    explicit Term(double value);
    virtual ~Term(void) = default;

    double getValue(void) const;
    void multiply(double factor);
    bool hasName(std::string const& name) const;
    bool hasName(NameSet const& nameSet) const;
protected:
private:
    double value;
};

#endif //_EQUATION_SYSTEM_TERM_HPP_
