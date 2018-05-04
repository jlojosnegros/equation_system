#ifndef _EQUATION_SYSTEM_TERM_HPP_
#define _EQUATION_SYSTEM_TERM_HPP_

#include <string>
#include <set>
#include <memory>

class TermVisitor;

class Term
{
public:
    using NameSet = std::set<std::string>;

    explicit Term(double value);
    virtual ~Term(void) = default;

    double getValue(void) const;
    void multiply(double factor);

    virtual bool hasName(std::string const& name) const;

    virtual bool hasName(NameSet const& nameSet) const;

    virtual std::unique_ptr<Term> clon(void) = 0;
    std::string toString(void) const;

    virtual void dispatch(TermVisitor const& termVisitor) = 0;
    bool equal(Term const& term) const;

protected:
private:
    double value;

    virtual std::string to_string(void) const = 0;
    virtual bool is_equal(Term const& term) const = 0;
};

inline bool operator==(const Term& lhs, const Term& rhs)
{ /* do actual comparison */
    return lhs.getValue() == rhs.getValue();
}
inline bool operator!=(const Term& lhs, const Term& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Term& lhs, const Term& rhs)
{ /* do actual comparison */
    return lhs.getValue() < rhs.getValue();
}
inline bool operator> (const Term& lhs, const Term& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Term& lhs, const Term& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Term& lhs, const Term& rhs){return !operator< (lhs,rhs);}

#endif //_EQUATION_SYSTEM_TERM_HPP_
