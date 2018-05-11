#ifndef EQUATION_SYSTEM_TEST_VARIABLEBUILDER_HPP
#define EQUATION_SYSTEM_TEST_VARIABLEBUILDER_HPP

#include <string>

class Variable;

class VariableBuilder final
{
public:
    VariableBuilder(void) = default;
    ~VariableBuilder() = default;

    VariableBuilder(VariableBuilder const& rhs) = delete;
    VariableBuilder& operator=(VariableBuilder const& rhs) = delete;

    VariableBuilder(VariableBuilder&& rhs) = delete;
    VariableBuilder& operator=(VariableBuilder&& rhs) = delete;

    VariableBuilder& name(std::string name);
    VariableBuilder& value(double value);

    Variable build(void) const;
protected:
private:
    std::string m_name;
    double m_value;
};

#endif // EQUATION_SYSTEM_TEST_VARIABLEBUILDER_HPP

