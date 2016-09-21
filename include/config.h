#ifndef _ACCF_CONFIG_H
#define _ACCF_CONFIG_H

#include <memory>

#include "config.pb.h"

namespace accf {
  std::unique_ptr<protos::Config> GetConfig(std::string filename);
  void SetConfig(std::string filename);
}  // namespace accf

#endif  // _ACCF_CONFIG_H
