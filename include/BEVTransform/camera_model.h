#ifndef CAMERA_MODEL_H
#define CAMERA_MODEL_H

#include <bits/stdc++.h>

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <memory>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <regex>
#include <sstream>
#include <string>
#include <thread>

// #include "configs/config.h"
// #include "sensors/car_status.h"

#include "BEVTransform/birdview_model.h"
#include "BEVTransform/four_points.h"

// #include "utils/filesystem_include.h"

#ifndef __GNUC__
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#define SMARTCAM_CAMERA_CALIB_FILE "../assets/configs/bev_calib.txt"


class CameraModel {
  BirdViewModel birdview_model;

 public:
  explicit CameraModel();
  void readCalibFile(std::string file_path);
  BirdViewModel *getBirdViewModel();

 public:
  void updateCameraModel(float car_width, float carpet_width,
                         float car_to_carpet_distance, float carpet_length,
                         float tl_x, float tl_y, float tr_x, float tr_y,
                         float br_x, float br_y, float bl_x, float bl_y);

  bool isCalibrated();
};

#endif  // CAMERA_MODEL_H
