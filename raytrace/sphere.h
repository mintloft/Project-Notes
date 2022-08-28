#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public: //英文冒号
	point3 center;
	double radius;
	shared_ptr<material> mat_ptr; //材质信息

public:
	sphere() {}
	sphere(point3 cen, double r, shared_ptr<material>m) 
		:center(cen), radius(r), mat_ptr(m) {};

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec)const override; //override避免派生类中忘记重写虚函数,不会调用默认
	virtual bool bounding_box(double time0, double time1, aabb& output_box) const override;

private:
	static void get_sphere_uv(const point3& p, double& u, double& v) 
	{   //球的纹理坐标
		// p: a given point on the sphere of radius one, centered at the origin.
		// u: returned value [0,1] of angle around the Y axis from X=-1.
		// v: returned value [0,1] of angle from Y=-1 to Y=+1.
		//     <1 0 0> yields <0.50 0.50>       <-1  0  0> yields <0.00 0.50>
		//     <0 1 0> yields <0.50 1.00>       < 0 -1  0> yields <0.50 0.00>
		//     <0 0 1> yields <0.25 0.50>       < 0  0 -1> yields <0.75 0.50>

		auto theta = acos(-p.y());
		auto phi = atan2(-p.z(), p.x()) + pi;

		u = phi / (2 * pi);
		v = theta / pi;
	}

};


bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec)const
{
	vec3 oc = r.origin() - center; //圆心到光源 
	auto a = r.direction().length_squared();
	auto half_b = dot(oc, r.direction()); //光的方向
	auto c = oc.length_squared() - radius * radius;

	auto discriminant = half_b * half_b - a * c;
	if (discriminant < 0) return false; //无交点返回
	auto sqrtd = sqrt(discriminant);

	//寻找范围内最近根（两个根中的）
	auto root = (-half_b - sqrtd) / a; //求根，先-
	if (root < t_min || t_max < root) //不在范围内则看+
	{
		root = (-half_b + sqrtd) / a; //求+根
		if (root < t_min || t_max < root) return false; //也不在范围内
	}

	//-号根在范围内则不看+号根
	rec.t = root;  //交点的光线t
	rec.p = r.at(rec.t); //交点坐标p
	vec3 outward_normal = (rec.p - center) / radius; //法线，并且单位化
	rec.set_face_normal(r, outward_normal);  //光源在内部，则法线朝内
	get_sphere_uv(outward_normal, rec.u, rec.v);
	rec.mat_ptr = mat_ptr; //材质信息

	return true;
}

bool sphere::bounding_box(double time0, double time1, aabb& output_box) const {
	output_box = aabb(
		center - vec3(radius, radius, radius),
		center + vec3(radius, radius, radius));
	return true;
}
#endif

