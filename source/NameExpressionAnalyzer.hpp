#ifndef EQUATION_SYSTEM_NAMEEXPRESSIONANALYZER_HPP
#define EQUATION_SYSTEM_NAMEEXPRESSIONANALYZER_HPP


#include "TermVisitor.hpp"
#include "fwdVisitableTerms.hpp"
#include "DataTypes.hpp"
#include "NameSet.hpp"

class NameExpressionAnalyzer : public TermVisitor
{
public:
    explicit NameExpressionAnalyzer(TermList& termList);
    void visit(Variable const &variable) override;
    void visit(Constant const &constant) override;
    NameSet getNameSet(void) const;

    ~NameExpressionAnalyzer() override = default;

private:
    TermList& termList;
    NameSet nameset;
};

#endif //EQUATION_SYSTEM_NAMEEXPRESSIONANALYZER_HPP
