#include "GenericInputWidget.h"

namespace mc_rtc_rviz
{

template<>
void GenericInputWidget<double>::set_validator()
{
  auto validator = new QDoubleValidator(this);
  edit_->setValidator(validator);
}

template<>
void GenericInputWidget<int>::set_validator()
{
  auto validator = new QIntValidator(this);
  edit_->setValidator(validator);
}

template<>
void GenericInputWidget<std::string>::to_edit(const std::string & data)
{
  edit_->setText(data.c_str());
}

template<>
std::string GenericInputWidget<std::string>::from_edit()
{
  return edit_->text().toStdString();
}

template<>
int GenericInputWidget<int>::from_edit()
{
  return edit_->text().toInt();
}

template<>
double GenericInputWidget<double>::from_edit()
{
  return edit_->text().toDouble();
}


}
