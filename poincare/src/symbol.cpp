#include <poincare/symbol.h>
#include <poincare/context.h>
#include "layout/string_layout.h"
extern "C" {
#include <assert.h>
}

Symbol::Symbol(const char * name) :
  m_name(*name)
{
  assert(strlen(name) == 1);
}

float Symbol::approximate(Context& context) const {
  return context[&m_name]->approximate(context);
}

Expression::Type Symbol::type() const {
  return Expression::Type::Symbol;
}

const char Symbol::name() const {
  return m_name;
}

ExpressionLayout * Symbol::createLayout() const {
  return new StringLayout(&m_name, 1);
}

Expression * Symbol::clone() const {
  char name[2];
  name[0] = m_name;
  name[1] = 0;
  return new Symbol(name);
}

bool Symbol::valueEquals(const Expression * e) const {
  assert(e->type() == Expression::Type::Symbol);
  return (m_name == ((Symbol *)e)->m_name);
}
