#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
using namespace std;

//void write_color(ostream& out, color pixel_color) 
//{
//	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
//		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
//		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
//}

void write_color(ostream& out, color pixel_color, int samples_per_pixel)
{
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	//颜色除以采样数以及伽马校正2
	auto scale = 1.0 / samples_per_pixel;
	//r *= scale;
	//g *= scale;
	//b *= scale;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);

	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}     //先将三通道设置在0-1转化为单位向量，再乘以256

#endif