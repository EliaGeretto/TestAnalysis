#ifndef TESTANALYSIS_TESTANALYSIS_H
#define TESTANALYSIS_TESTANALYSIS_H

#include "llvm/Pass.h"

#include <cstdint>
#include <memory>
#include <string>

namespace test_analysis {
class TestAnalysis : public llvm::ModulePass {
public:
  using AnalysisResult = std::uint64_t;

  static char ID;
  TestAnalysis();
  ~TestAnalysis();

  bool runOnModule(llvm::Module &M) override;
  void getAnalysisUsage(llvm::AnalysisUsage &Info) const override;
  void print(llvm::raw_ostream &O, const llvm::Module *M) const override;

  const AnalysisResult &getResult() const;

private:
  AnalysisResult Result;
};
} // namespace test_analysis

#endif
