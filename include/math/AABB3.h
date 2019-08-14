#ifndef __AABB3_H_INCLUDE__
#define __AABB3_H_INCLUDE__
#ifndef __VECTOR3_H_INCLUDE__
#include "Vector3.h"
#endif
#endif
class Matrix4x3;
class AABB3
{
public:
  Vector3 min;
  Vector3 max;
  Vector3 size() const
  {
    return max - min;
  }
  float xSize()
  {
    return max.x - min.x;
  }
  float ySize()
  {
    return max.y - min.y;
  }
  float zSize()
  {
    return max.z - min.z;
  }
  Vector3 center() const
  {
    return (min + max) * 0.5;
  }
  //获得aabb 的八个顶点
  Vector3 corner(int i) const;

  void empty();
  void add(const AABB3 &box);
  void add(const Vector3 &p);
  void setTransformedBox(const AABB3 &box, const Matrix4x3 &m);
  bool isEmpty() const;
  //是否被box包含
  bool contains(const Vector3 &p) const;
  //返回box最近的点
  Vector3 closestPointTo(const Vector3 &p) const;
  bool intersectSphere(const Vector3 &center, float radis) const;
  //和参数射线的相交性测试，如果不想交返回值小于1
  float rayIntersect(const Vector3 &rayOrg, const Vector3 &rayDelta, Vector3 *returnNormal = 0)const;
  //和平面的相交性测试
  float planeIntersect(const Vector3 &n,float planeD,const Vector3 &dir)const;
  //判断box在平面的哪一边
  int classifyPlane(const Vector3 &n, float d) const;

private:
  /* data */
public:
  AABB3(/* args */);
  ~AABB3();
};

AABB3::AABB3(/* args */)
{
}

AABB3::~AABB3()
{
}
//静态aabb3 相交判断
bool intersectAABBs(const AABB3 &box1,const AABB3 &box2, AABB3 *boxIntersect=0);
bool intersectMovingAABB(const AABB3 &stationaryBox,const AABB3 &movingBox,const Vector3 &d);
