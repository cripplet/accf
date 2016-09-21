#include <memory>

#include "config.pb.h"

#include "config.h"

std::unique_ptr<protos::Config> _config;

std::unique_ptr<protos::Config> accf::GetConfig(std::string filename) {
  std::unique_ptr<protos::Config> _config(nullptr);
  return _config;
}

void accf::SetConfig(std::string filename) {
}
