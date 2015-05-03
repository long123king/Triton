#include <stdexcept>

#include "ControlFlow.h"
#include "Registers.h"



SymbolicElement *ControlFlow::rip(AnalysisProcessor &ap, uint64_t nextAddr)
{
  SymbolicElement     *se;
  std::stringstream   expr;

  /*
   * Create the SMT semantic.
   * RIP = nextAddress
   */
  expr << smt2lib::bv(nextAddr, 64);

  /* Create the symbolic element */
  se = ap.createRegSE(expr, ID_RIP, "RIP");

  return se;
}
