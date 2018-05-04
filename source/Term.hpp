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
