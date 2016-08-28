#ifndef _ACCF_FILEIO_H
#define _ACCF_FILEIO_H

#include <string>

#include "config.pb.h"
#include "messages.pb.h"

namespace accf {
  protos::Config LoadConfig(std::string filename, bool is_json);
  void DumpConfig(std::string filename, protos::Config& config, bool is_json);
}  // namespace accf

#endif  // _ACCF_FILEIO_H
