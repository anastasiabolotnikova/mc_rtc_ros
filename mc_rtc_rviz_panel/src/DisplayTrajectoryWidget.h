#pragma once

#include "ClientWidget.h"
#include "utils.h"
#include <mc_rtc/ros.h>
#include <visualization_msgs/MarkerArray.h>

namespace mc_rtc_rviz
{

struct DisplayTrajectoryWidget : public ClientWidget
{
  Q_OBJECT
public:
  DisplayTrajectoryWidget(const ClientWidgetParam & params,
                          visualization_msgs::MarkerArray & markers,
                          const mc_rtc::gui::LineConfig & config);

  void update(const std::vector<Eigen::Vector3d> & points);
  void update(const std::vector<sva::PTransformd> & points);
  void update(const Eigen::Vector3d & point);
  void update(const sva::PTransformd & points);
private:
  visualization_msgs::MarkerArray & markers_;
  visualization_msgs::Marker path_;
  mc_rtc::gui::LineConfig config_;
  void configure();
};

}