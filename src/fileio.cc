#include <fstream>
#include <iostream>
#include <string>

#include "config.pb.h"
#include "exceptions.h"
#include "messages.pb.h"

#include "fileio.h"

protos::Config accf::LoadConfig(std::string filename, bool is_json) {
  protos::Config config;
  if(!is_json) {
    std::fstream input(filename, std::ios::in | std::ios::binary);
    if(!config.ParseFromIstream(&input)) {
      throw ParseError();
    } else {
      return config;
    }
  } else {
    throw NotImplemented();
  }
}

void accf::DumpConfig(std::string filename, protos::Config& config, bool is_json) {
  if(!is_json) {
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if(!config.SerializeToOstream(&output)) {
      throw ParseError();
    }
  } else {
    throw NotImplemented();
  }
}
