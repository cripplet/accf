#include "Catch/catch.hpp"

#include <iostream>
#include <string>

#include "config.pb.h"

#include "fileio.h"
#include "exceptions.h"

TEST_CASE("fileio|successful dump/load", "Tests common case") {
  protos::Config c;
  c.set_tolerance(1.0 / 100000000.0);
  c.set_n_angular_buckets(1000);

  accf::DumpConfig("data/simpleconfig.buf", c, false);
  protos::Config d = accf::LoadConfig("data/simpleconfig.buf", false);

  std::string cs, ds;
  c.SerializeToString(&cs);
  d.SerializeToString(&ds);

  REQUIRE(cs == ds);
}

TEST_CASE("fileio|unimplemented", "Asserts unimplemented parts of the code") {
  protos::Config c;
  c.set_tolerance(1.0 / 100000000.0);
  c.set_n_angular_buckets(1000);

  REQUIRE_THROWS_AS(accf::DumpConfig("data/simpleconfig.buf", c, true), accf::NotImplemented);
  REQUIRE_THROWS_AS(accf::LoadConfig("data/simpleconfig.buf", true), accf::NotImplemented);
}

TEST_CASE("fileio|load nonexistent file", "Tests error is raised when loading from invalid file") {
  protos::Config c;
  c.set_tolerance(1.0 / 100000000.0);
  c.set_n_angular_buckets(1000);

  REQUIRE_THROWS_AS(accf::LoadConfig("data/non-existent", false), accf::ParseError);
}
