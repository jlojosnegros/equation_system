#include "Expression.hpp"

#include "Term.hpp"
#include "Variable.hpp"
#include "Constant.hpp"
#include "NameExpressionAnalyzer.hpp"

#include <numeric>
#include <algorithm>
#include <sstream>

void Expression::add(std::unique_ptr<Term> term)
{
    termList.push_back(std::move(term));
}

void Expression::add(Term &&term)
{
    add(term.clon());
}

void Expression::add(std::unique_ptr<Expression> expression)
{
    for (auto& term : expression->termList)
    {
        termList.push_back(std::move(term));
    }
}

void Expression::add(Expression&& expression)
{
    add(expression.clon());
}

void Expression::multiply(double value)
{
    for (auto& term : termList)
    {
        term->multiply(value);
    }
}

void Expression::simplify(std::string name)
{
    //get current value of each variable with name
    auto sum = std::accumulate(std::begin(termList), std::end(termList)
                    ,0.0,
                           [&name](double accumulated, auto& term){
                               return accumulated + (term->hasName(name))?term->getValue():0.0;
                           });

    // remove all the terms with name
    termList.erase(std::remove_if(std::begin(termList), std::end(termList),
    [&name](auto& term){return term->hasName(name);}));

    // insert the new one with the accumulate.
    termList.push_back(std::make_unique<Variable>(sum,name));
}

void Expression::simplify(void)
{
    // get all the variable names in the term list.
    NameExpressionAnalyzer analyzer;
    for(auto& term : termList)
    {
        term->dispatch(analyzer);
    }
    auto nameSet = analyzer.getNameSet();

    //get current value of each element without any name ( no name => constant )
    auto sum = std::accumulate(std::begin(termList), std::end(termList)
            ,0.0,
                               [&nameSet](double accumulated, auto& term){
                                   return accumulated + (!term->hasName(nameSet))?term->getValue():0.0;
                               });

    // remove all the terms without any name ( no name => constant )
    termList.erase(std::remove_if(std::begin(termList), std::end(termList),
                                  [&nameSet](auto& term){return !term->hasName(nameSet);}));

    // insert the new one with the accumulate.
    termList.push_back(std::make_unique<Constant>(sum));
}

double Expression::getValue(std::string name) const
{
    return 0;
}

double Expression::getValue(void) const
{
    return 0;
}

NameSet Expression::getNameSet(void) const
{
    return NameSet();
}

bool Expression::hasName(std::string name) const
{
    return false;
}

void Expression::apply(std::string name, double value)
{

}

bool Expression::equal(Expression const &expression) const
{
    return false;
}

std::unique_ptr<Expression> Expression::clon(void) const
{
    //return std::move(std::make_unique<Expression>(*this));
}

#include <iostream>
std::string Expression::toString(void) const
{
    if (termList.empty())
        return "";

    if (2 > std::size(termList))
    {
        return (*std::begin(termList))->toString();
    }
    return std::accumulate(
            std::next(std::begin(termList)), std::end(termList),
            (*std::begin(termList))->toString(),
            [](std::string accum, auto& term)
            {
//                std::cout << "ac:" << accum << std::endl;
//                std::cout << "tm:" << term->toString() << std::endl;
//                std::cout << "rt:" << accum + "+" + term->toString() << std::endl;
                return accum + "+" + term->toString();
                //return accum.append("+").append(term->toString());
            }
    );

}

bool Expression::empty(void) const
{
    return false;
}

