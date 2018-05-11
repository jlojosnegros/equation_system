#include "VariableBuilder.hpp"
#include "Variable.hpp"

#include <utility>

VariableBuilder& VariableBuilder::name(std::string name)
{
    m_name = std::move(name);
    return *this;
}

VariableBuilder &VariableBuilder::value(double value)
{
    m_value = value;
    return *this;
}

Variable VariableBuilder::build(void) const
{
    return {m_value, m_name};
}
