#pragma once

#include "goodies_export.h"
#include <string>

class GOODIES_EXPORT Goodies {
  std::string const name_;
public:
  Goodies( std::string const& name ) : name_( name ) {}

  std::string allCaps() const;
};
