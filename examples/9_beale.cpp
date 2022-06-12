#include <iostream>
#include "module.hpp"
#include "ceres/ceres.h"
#include "glog/logging.h"

// f(x,y) = (1-x)^2 + 100(y - x^2)^2;
struct Beale {
  template <typename T>
  bool operator()(const T* parameters, T* cost) const {
    const T x = parameters[0];
    const T y = parameters[1];
    cost[0] = (1.5 - x + x * y) * (1.5 - x + x * y) + (2.25 - x + x * y * y) * (2.25 - x + x * y * y) + (2.625 - x + x * y * y * y) * (2.625 - x + x * y * y * y);
    return true;
  }
  static ceres::FirstOrderFunction* Create() {
    constexpr int kNumParameters = 2;
    return new ceres::AutoDiffFirstOrderFunction<Beale, kNumParameters>(
        new Beale);
  }
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);

  double parameters[2] = {0.0, 0.0};


  ceres::GradientProblem problem(Beale::Create());

  ceres::GradientProblemSolver::Options options;
  options.minimizer_progress_to_stdout = true;
  ceres::GradientProblemSolver::Summary summary;

  ceres::Solve(options, problem, parameters, &summary);
  
  std::cout << summary.FullReport() << std::endl;
  std::cout << "Initial x: " << 0.0 << " y: " << 0.0 << std::endl;
  std::cout << "Final   x: " << parameters[0] << " y: " << parameters[1] << std::endl;
  return 0;
}