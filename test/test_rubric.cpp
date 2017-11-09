#include <fstream>
#include <string>
#include <iostream>

#include "catch.hpp"
#include "../src/application.h"

namespace {
  const std::string input = "../data/obj_pose-laser-radar-synthetic-input.txt";

  Model::x rmse;

  struct FileProtocol {
    static bool checkHeader(const std::string&) { return true; }

    static std::string getPayload(std::string message) { return message; }
    static std::string getMeasurement(std::string payload) { return payload; }

    static std::string formatResponse() { return std::string(); }
    static std::string formatResponse(const Model::x&, const Model::x& RMSE) {
      rmse = RMSE;
      return std::string();
    }
  };
}

TEST_CASE("Rubric", "[require]") {
  std::ifstream f(input.c_str());
  Application<FileProtocol> app;
  for(std::string s; std::getline(f, s); ) {
    app.ProcessMessage(s);
  }
  REQUIRE((rmse.array() < (Model::x() << 0.11, 0.11, 0.52, 0.52).finished().array()).all());
}
