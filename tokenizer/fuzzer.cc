#include <string.h>
#include <string>
#include <boost/tokenizer.hpp>

extern "C" void LLVMFuzzerTestOneInput(const char *data, size_t size) {
  if (size < 1) return;
  std::string str(data, size);
  boost::tokenizer<> tok(str);
  for (auto& x : tok) {
    static std::string unused = std::move(x);
  }
}
