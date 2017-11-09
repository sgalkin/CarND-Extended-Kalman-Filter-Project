#pragma once

#include "Eigen/Dense"
#include "model.h"

template<size_t S>
struct MeasurementBase
{
  static constexpr size_t Size = S;
  
  using Measurement = Eigen::Matrix<double, Size, 1>;
  using Covariance = Eigen::Matrix<double, Size, Size>;
  using Projection = Eigen::Matrix<double, Size, Model::N>;

  using Package = std::tuple<std::chrono::microseconds, Measurement>;
};

template<typename IS, typename P>
IS& operator>> (IS& is, std::tuple<std::chrono::microseconds, P>& p) {
  long long ts = 0;
  is >> std::get<1>(p) >> ts;
  std::get<0>(p) = std::chrono::microseconds(ts);
  return is;
}
