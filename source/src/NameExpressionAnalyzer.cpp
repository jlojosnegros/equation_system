#include "NameExpressionAnalyzer.hpp"

NameExpressionAnalyzer::NameExpressionAnalyzer(TermList& termList)
: termList(termList)
{

}

NameSet NameExpressionAnalyzer::getNameSet(void) const
{
    return NameSet();
}

void NameExpressionAnalyzer::visit(Variable const &variable)
{

}

void NameExpressionAnalyzer::visit(Constant const &constant)
{

}





