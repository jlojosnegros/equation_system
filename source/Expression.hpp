#ifndef _EQUATION_SYSTEM_EXPRESSION_HPP_
#define _EQUATION_SYSTEM_EXPRESSION_HPP_

#include "DataTypes.hpp"
#include "NameSet.hpp"

#include <string>
#include <memory>
#include <list>

class Term;

class Expression final
{
public:
    Expression(void) = default;
    ~Expression() = default;

    void add(std::unique_ptr<Term> term);
    void add(Term&& term);
    void add(std::unique_ptr<Expression> expression);
    void add(Expression&& expression);

    void multiply(double value);

    void simplify(std::string name);
    void simplify(void);

    double getValue(std::string name) const;
    double getValue(void) const;

    NameSet getNameSet(void) const;
    bool hasName(std::string name) const;
    void apply(std::string name, double value);
    bool equal(Expression const& expression) const;

    std::unique_ptr<Expression> clon(void) const;

    std::string toString(void) const;
protected:
private:
    bool empty(void) const;
    TermList termList;
};

inline bool operator==(const Expression& lhs, const Expression& rhs)
{ /* do actual comparison */
    return lhs.getValue() == rhs.getValue();
}
inline bool operator!=(const Expression& lhs, const Expression& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Expression& lhs, const Expression& rhs)
{ /* do actual comparison */
    return lhs.getValue() < rhs.getValue();
}
inline bool operator> (const Expression& lhs, const Expression& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Expression& lhs, const Expression& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Expression& lhs, const Expression& rhs){return !operator< (lhs,rhs);}


#endif //_EQUATION_SYSTEM_EXPRESSION_HPP_

