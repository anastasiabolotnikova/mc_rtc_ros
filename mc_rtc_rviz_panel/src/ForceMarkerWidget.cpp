#include "ForceMarkerWidget.h"

#include <mc_rbdyn/configuration_io.h>

namespace mc_rtc_rviz
{

ForceMarkerWidget::ForceMarkerWidget(const ClientWidgetParam & params,
                                         const WidgetId & requestId,
                                         visualization_msgs::MarkerArray & markers)
: ClientWidget(params),
  request_id_(requestId),
  markers_(markers)
{
}

void ForceMarkerWidget::update(const sva::ForceVecd & force, const sva::PTransformd & surface, const mc_rtc::gui::ForceConfig & c)
{
    Eigen::Vector3d cop = surface.translation();
    visualization_msgs::Marker m;
    m.type = visualization_msgs::Marker::ARROW;
    m.action = visualization_msgs::Marker::ADD;
    m.lifetime = ros::Duration(1);
    auto rosPoint = [](const Eigen::Vector3d & vec)
    {
      geometry_msgs::Point p;
      p.x = vec.x();
      p.y = vec.y();
      p.z = vec.z();
      return p;
    };
    const auto& start = cop;
    const auto& end = cop + c.force_scale * force.force();
    m.points.push_back(rosPoint(start));
    m.points.push_back(rosPoint(end));
    m.scale.x = c.shaft_diam;
    m.scale.y = c.head_diam;
    m.scale.z = c.head_len;
    m.color.a = c.color.a;
    m.color.r = c.color.r;
    m.color.g = c.color.g;
    m.color.b = c.color.b;
    m.header.stamp = ros::Time::now();
    m.header.frame_id = "robot_map";
    m.ns = id2name(request_id_);
    markers_.markers.push_back(m);

    if(c.start_point_scale > 0)
    {
      markers_.markers.push_back(getPointMarker(id2name(id()) + "_start_point", start, c.color, c.start_point_scale));
    }
    if(c.end_point_scale > 0)
    {
      markers_.markers.push_back(getPointMarker(id2name(id()) + "_end_point", end, c.color, c.end_point_scale));
    }
}

}