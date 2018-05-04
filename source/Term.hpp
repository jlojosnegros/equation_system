#ifndef _EQUATION_SYSTEM_TERM_HPP_
#define _EQUATION_SYSTEM_TERM_HPP_

#include <string>

class Term
{
public:
    explicit Term(double value);
    virtual ~Term(void) = default;

    double getValue(void) const;
    void multiply(double factor);
    bool hasName(std::string const& name) const;
protected:
private:
    double value;
};

#endif //_EQUATION_SYSTEM_TERM_HPP_
