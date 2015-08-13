#include <string>
#include <boost/lexical_cast.hpp>

extern "C" void LLVMFuzzerTestOneInput(const char *data, size_t size) {
  if (size < 1) return;
  std::string str(data, size);

  try {
    int i = boost::lexical_cast<int>(str);
    std::string s = boost::lexical_cast<std::string>(i);
  } catch (...) {}

  try {
    double d = boost::lexical_cast<double>(str);
    std::string s = boost::lexical_cast<std::string>(d);
  } catch (...) {}
}
