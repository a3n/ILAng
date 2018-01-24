/// \file
/// Source for the model z3 expression generator.

#include "ila/model_expr_generator.h"

namespace ila {

ModelExprGen::ModelExprGen(z3::context& ctx)
    : ctx_(ctx), gen_(Z3ExprAdapter(ctx)) {}

ModelExprGen::~ModelExprGen() {}

void ModelExprGen::set_z3_simplify(bool z3_smpl) { gen_.set_simplify(z3_smpl); }

z3::expr ModelExprGen::Node(const ExprPtr node, const std::string& prefix,
                            const std::string& suffix) {
  auto e = gen_.GetExpr(node, prefix, suffix);
  return e;
}

z3::expr ModelExprGen::Instr(const InstrPtr instr, const std::string& prefix,
                             const std::string& suffix_prev,
                             const std::string& suffix_next, bool complete) {
  ILA_NOT_NULL(instr);
  ILA_DLOG("ModelGen.Instr") << "Generate z3 expr for " << instr
                             << " with prefix (" << prefix << ") and suffix ("
                             << suffix_prev << ", " << suffix_next << ")\n";

  auto ila = instr->host();
  ILA_NOT_NULL(ila);

  auto cnst = ctx_.bool_val(true);

  auto state_num = ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto state_n = ila->state(i);
    auto update_n = instr->GetUpdate(state_n);

    if (update_n != NULL) { // update function specified
      auto next_val_e = gen_.GetExpr(update_n, prefix, suffix_prev);
      auto next_var_e = gen_.GetExpr(state_n, prefix, suffix_next);
      auto eq_cnst = (next_var_e == next_val_e);
      cnst = cnst && eq_cnst;
    } else if (complete == true) {
      auto next_val_e = gen_.GetExpr(state_n, prefix, suffix_prev);
      auto next_var_e = gen_.GetExpr(state_n, prefix, suffix_next);
      auto eq_cnst = (next_var_e == next_val_e);
      cnst = cnst && eq_cnst;
    }
  }

  auto decode_n = instr->GetDecode();
  ILA_NOT_NULL(decode_n);
  auto decode_e = gen_.GetExpr(decode_n, prefix, suffix_prev);

  auto instr_cnst = z3::implies(decode_e, cnst);
  return instr_cnst;
}

z3::expr ModelExprGen::IlaOneHotFlat(const InstrLvlAbsPtr ila,
                                     const std::string& prefix,
                                     const std::string& suffix_prev,
                                     const std::string& suffix_next) {
  ILA_NOT_NULL(ila);
  ILA_DLOG("ModelGen.IlaOneHotFlat")
      << "Generate z3 expr for " << ila << " with prefix (" << prefix
      << ") and suffix (" << suffix_prev << ", " << suffix_next << ")\n";

  auto valid_n = ila->valid();
  ILA_NOT_NULL(valid_n);
  auto valid_e = gen_.GetExpr(valid_n, prefix, suffix_prev);

  auto cnst = ctx_.bool_val(true);
  auto instr_num = ila->instr_num();
  for (size_t i = 0; i != instr_num; i++) {
    auto instr_i = ila->instr(i);
    auto instr_cnst = Instr(instr_i, prefix, suffix_prev, suffix_next, true);
    // Assume one-hot encoding of the instruction decode.
    cnst = cnst && instr_cnst;
  }

  auto ila_cnst = z3::implies(valid_e, cnst);
  return ila_cnst;
}

} // namespace ila

