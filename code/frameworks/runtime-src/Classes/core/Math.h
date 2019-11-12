#pragma once

#include "cocos2d.h"

using namespace cocos2d;

namespace Math {
	void CreateTranslation(float xTranslation, float yTranslation, float zTranslation, Mat4* dst);

	void CreateScale(float xScale, float yScale, float zScale, Mat4* dst);

	void CreateRotation(const Vec3& axis, float angle, Mat4* dst);

	void CreateRotation(float x, float y, float z, float angle, Mat4* dst);

	void CreateRotationX(float angle, Mat4* dst);

	void CreateRotationY(float angle, Mat4* dst);

	void CreateRotationZ(float angle, Mat4* dst);
	
	void CreateLookAt(const Vec3& eyePosition, const Vec3& targetPosition, const Vec3& up, Mat4* dst);

	void CreateLookAt(float eyePositionX, float eyePositionY, float eyePositionZ,
		float targetPositionX, float targetPositionY, float targetPositionZ,
		float upX, float upY, float upZ, Mat4* dst);

	void CreatePerspective(float fieldOfView, float aspectRatio,
		float zNearPlane, float zFarPlane, Mat4* dst);

	void CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane, Mat4* dst);

	void CreateOrthographicOffCenter(float left, float right, float bottom, float top,
		float zNearPlane, float zFarPlane, Mat4* dst);

	/*
	* ¥Ì«–æÿ’Û
	* http://blog.sina.com.cn/s/blog_6163bdeb0102du6p.html
	* [1 B C 0]
	* [D 1 F 0]
	* [H I 1 0]
	* [0 0 0 1]
	*
	* (1)—ÿX÷·∫¨YœÚ¥Ì«–
	*  [1 0 0 0]
	*  [D 1 0 0]
	*  [0 0 1 0]
	*  [0 0 0 1]
	*  º¥‘⁄XY∆Ω√Ê∏ƒ±‰X◊¯±Í
	*  -----------				  -----------
	*  |		 |			     /		   /
	*  |		 |     ->	    /		  /
	*  |		 |			   /		 /
	*  -----------			  -----------
	*
	* (2)—ÿX÷·∫¨ZœÚ¥Ì«–
	*  [1 0 0 0]
	*  [0 1 0 0]
	*  [H 0 1 0]
	*  [0 0 0 1]
	*
	* (3)—ÿY÷·∫¨XœÚ¥Ì«–
	*  [1 B 0 0]
	*  [0 1 0 0]
	*  [0 0 1 0]
	*  [0 0 0 1]
	*
	* (4)—ÿY÷·∫¨ZœÚ¥Ì«–
	*  [1 0 0 0]
	*  [0 1 0 0]
	*  [0 I 1 0]
	*  [0 0 0 1]
	*
	* (5)—ÿZ÷·∫¨XœÚ¥Ì«–
	*  [1 0 C 0]
	*  [0 1 0 0]
	*  [0 0 1 0]
	*  [0 0 0 1]
	*
	* (6)—ÿZ÷·∫¨YœÚ¥Ì«–
	*  [1 0 0 0]
	*  [0 1 F 0]
	*  [0 0 1 0]
	*  [0 0 0 1]
	*/
	void CreateShear(float B, float C, float D, float F, float H, float I, Mat4* dst);

	// skewx skewy Ω«∂»
	void CreateSkewXY(float skewx, float skewy, Mat4* dst);
}
