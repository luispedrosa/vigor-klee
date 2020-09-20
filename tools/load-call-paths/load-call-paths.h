#pragma once

#include "klee/ExprBuilder.h"
#include "klee/Constraints.h"

typedef struct {
  std::string function_name;
  std::map<std::string, std::pair<klee::ref<klee::Expr>,
                                  klee::ref<klee::Expr> > > extra_vars;
  std::map<std::string,
           std::pair<klee::ref<klee::Expr>, klee::ref<klee::Expr> > > args;

  klee::ref<klee::Expr> ret;
} call_t;

typedef struct {
  std::string file_name;
  klee::ConstraintManager constraints;
  std::vector<call_t> calls;
  std::map<std::string, const klee::Array *> arrays;
} call_path_t;

call_path_t *load_call_path(std::string file_name,
                            std::vector<std::string> expressions_str,
                            std::deque<klee::ref<klee::Expr> > &expressions);
