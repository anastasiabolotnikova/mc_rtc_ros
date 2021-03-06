/*
 * Copyright 2016-2019 CNRS-UM LIRMM, CNRS-AIST JRL
 */

#pragma once

#include "ClientWidget.h"

namespace mc_rtc_rviz
{

struct ArrayInputWidget : public ClientWidget
{
  Q_OBJECT
public:
  ArrayInputWidget(const ClientWidgetParam & param, const std::vector<std::string> & labels);

  void update(const Eigen::VectorXd & data);

  QPushButton * showHideButton() override;

protected:
  QPushButton * lock_button_;
  QHBoxLayout * labels_layout_;
  QGridLayout * edits_layout_;
  int edits_row_ = 0;
  std::vector<QLineEdit *> edits_;
private slots:
  void lock_toggled(bool);
  void edit_return_pressed();
};

} // namespace mc_rtc_rviz
