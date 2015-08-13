#include <string>
#include <boost/algorithm/string/case_conv.hpp>

namespace ba = boost::algorithm;

extern "C" void LLVMFuzzerTestOneInput(const char *data, size_t size) {
  if (size < 1) return;

  {
    std::string str(data, size);
    std::string out;
    out = ba::to_lower_copy(str);
    out = ba::to_upper_copy(str);
  }

  {
    std::string str(data, size);
    ba::to_lower(str);
  }

  {
    std::string str(data, size);
    ba::to_upper(str);
  }
}
