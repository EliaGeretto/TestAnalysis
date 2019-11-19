#include "TestAnalysis/TestAnalysis.h"

#include "llvm/IR/Module.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/raw_ostream.h"

#define DEBUG_TYPE "test-analysis"

using namespace test_analysis;
using namespace llvm;

char TestAnalysis::ID = 0;
TestAnalysis::TestAnalysis() : ModulePass(ID) {}
TestAnalysis::~TestAnalysis() = default;

bool TestAnalysis::runOnModule(Module &M) {
  Result = 42;

  return false;
}

void TestAnalysis::getAnalysisUsage(AnalysisUsage &Info) const {
  Info.setPreservesAll();
}

void TestAnalysis::print(raw_ostream &O, const Module *M) const {
  O << formatv("The result is: {0}", 42);
}

const TestAnalysis::AnalysisResult &TestAnalysis::getResult() const {
  return Result;
}

static RegisterPass<TestAnalysis> RegisterTestAnalysis{
    "test-analysis", "A simple test analysis that returns 42", true, true};
