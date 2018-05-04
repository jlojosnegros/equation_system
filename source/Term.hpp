#ifndef _EQUATION_SYSTEM_TERM_HPP_
#define _EQUATION_SYSTEM_TERM_HPP_


class Term
{
public:
    explicit Term(double value);
    virtual ~Term(void) = default;

    float getValue(void) const;
    void multiply(float value);
protected:
private:
    double value;
};

#endif //_EQUATION_SYSTEM_TERM_HPP_
