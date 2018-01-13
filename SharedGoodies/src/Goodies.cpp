#include <Shared/Goodies.h>

#include <algorithm>

std::string Goodies::allCaps() const {
  std::string all_caps;
  std::transform( name_.cbegin(), name_.cend(),
    std::back_inserter( all_caps ), std::toupper );
  return all_caps;
}
