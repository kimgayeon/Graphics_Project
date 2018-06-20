#include "Camera.h"
#include "transform.hpp"

const kmuvcl::math::vec3f Camera::center_position() const
{

  kmuvcl::math::vec3f center_position(position_(0) + front_dir_(0),
                 position_(1) + front_dir_(1),
                 position_(2) + front_dir_(2));
  return center_position;
}

// TODO: fill up the following functions properly
void Camera::move_forward(float delta)
{
  for(int i=0; i<3; i++)
      position_(i)+=front_dir_(i)*delta;
}

void Camera::move_backward(float delta)
{
  for(int i=0; i<3; i++)
      position_(i)-=front_dir_(i)*delta;
}

void Camera::move_left(float delta)
{
  for(int i=0; i<3; i++)
    position_(i)-=right_dir_(i)*delta;
}

void Camera::move_right(float delta)
{
  for(int i=0; i<3; i++)
    position_(i)+=right_dir_(i)*delta;
}

void Camera::rotate_left(float delta)
{
  kmuvcl::math::vec4f  Vec4f(front_dir_(0),front_dir_(1),front_dir_(2),0);

  Vec4f= kmuvcl::math::rotate(delta, 0.0f, 1.0f, 0.0f) * Vec4f;

  front_dir_(0)=Vec4f(0);
  front_dir_(1)=Vec4f(1);
  front_dir_(2)=Vec4f(2);

  right_dir_ = kmuvcl::math::cross(front_dir_, up_dir_);

}

void Camera::rotate_right(float delta)
{
  kmuvcl::math::vec4f  Vec4f(front_dir_(0),front_dir_(1),front_dir_(2),0);

  Vec4f= kmuvcl::math::rotate(delta, 0.0f, -1.0f, 0.0f) * Vec4f;

  front_dir_(0)=Vec4f(0);
  front_dir_(1)=Vec4f(1);
  front_dir_(2)=Vec4f(2);

  right_dir_ = kmuvcl::math::cross(front_dir_, up_dir_);

}