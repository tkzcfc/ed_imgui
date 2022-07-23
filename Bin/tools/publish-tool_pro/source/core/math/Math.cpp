#include "Math.h"
#include "MathCom.h"
#include "MathUtil.h"

namespace Math
{
	void CreateTranslation(float xTranslation, float yTranslation, float zTranslation, Mat4* dst)
	{
		MH_ASSERT(dst);
		dst->setIdentity();

		dst->m[12] = xTranslation;
		dst->m[13] = yTranslation;
		dst->m[14] = zTranslation;
	}

	void CreateScale(float xScale, float yScale, float zScale, Mat4* dst)
	{
		MH_ASSERT(dst);

		dst->setIdentity();

		dst->m[0] = xScale;
		dst->m[5] = yScale;
		dst->m[10] = zScale;
	}

	

	void CreateRotation(const Vec3& axis, float angle, Mat4* dst)
	{
		CreateRotation(axis.x, axis.y, axis.z, angle, dst);
	}

	void CreateRotation(float x, float y, float z, float angle, Mat4* dst)
	{
		MH_ASSERT(dst);

		// Make sure the input axis is normalized.
		float n = x*x + y*y + z*z;
		if (n != 1.0f)
		{
			// Not normalized.
			n = std::sqrt(n);
			// Prevent divide too close to zero.
			if (n > 0.000001f)
			{
				n = 1.0f / n;
				x *= n;
				y *= n;
				z *= n;
			}
		}

		float c = std::cos(angle);
		float s = std::sin(angle);

		float t = 1.0f - c;
		float tx = t * x;
		float ty = t * y;
		float tz = t * z;
		float txy = tx * y;
		float txz = tx * z;
		float tyz = ty * z;
		float sx = s * x;
		float sy = s * y;
		float sz = s * z;

		dst->m[0] = c + tx*x;
		dst->m[1] = txy + sz;
		dst->m[2] = txz - sy;
		dst->m[3] = 0.0f;

		dst->m[4] = txy - sz;
		dst->m[5] = c + ty*y;
		dst->m[6] = tyz + sx;
		dst->m[7] = 0.0f;

		dst->m[8] = txz + sy;
		dst->m[9] = tyz - sx;
		dst->m[10] = c + tz*z;
		dst->m[11] = 0.0f;

		dst->m[12] = 0.0f;
		dst->m[13] = 0.0f;
		dst->m[14] = 0.0f;
		dst->m[15] = 1.0f;
	}

	void CreateRotationX(float angle, Mat4* dst)
	{
		MH_ASSERT(dst);
		dst->setIdentity();

		float c = std::cos(angle);
		float s = std::sin(angle);

		dst->m[5] = c;
		dst->m[6] = s;
		dst->m[9] = -s;
		dst->m[10] = c;
	}

	void CreateRotationY(float angle, Mat4* dst)
	{
		MH_ASSERT(dst);
		dst->setIdentity();

		float c = std::cos(angle);
		float s = std::sin(angle);

		dst->m[0] = c;
		dst->m[2] = -s;
		dst->m[8] = s;
		dst->m[10] = c;
	}

	void CreateRotationZ(float angle, Mat4* dst)
	{
		MH_ASSERT(dst);
		dst->setIdentity();

		float c = std::cos(angle);
		float s = std::sin(angle);

		dst->m[0] = c;
		dst->m[1] = s;
		dst->m[4] = -s;
		dst->m[5] = c;
	}


	void CreateLookAt(const Vec3& eyePosition, const Vec3& targetPosition, const Vec3& up, Mat4* dst)
	{
		CreateLookAt(eyePosition.x, eyePosition.y, eyePosition.z, targetPosition.x, targetPosition.y, targetPosition.z,
			up.x, up.y, up.z, dst);
	}

	void CreateLookAt(float eyePositionX, float eyePositionY, float eyePositionZ,
		float targetPositionX, float targetPositionY, float targetPositionZ,
		float upX, float upY, float upZ, Mat4* dst)
	{
		MH_ASSERT(dst);

		Vec3 eye(eyePositionX, eyePositionY, eyePositionZ);
		Vec3 target(targetPositionX, targetPositionY, targetPositionZ);
		Vec3 up(upX, upY, upZ);
		up.normalize();

		Vec3 zaxis;
		zaxis = eye - target;
		zaxis.normalize();

		Vec3 xaxis;
		Vec3::cross(up, zaxis, &xaxis);
		xaxis.normalize();

		Vec3 yaxis;
		Vec3::cross(zaxis, xaxis, &yaxis);
		yaxis.normalize();

		dst->m[0] = xaxis.x;
		dst->m[1] = yaxis.x;
		dst->m[2] = zaxis.x;
		dst->m[3] = 0.0f;

		dst->m[4] = xaxis.y;
		dst->m[5] = yaxis.y;
		dst->m[6] = zaxis.y;
		dst->m[7] = 0.0f;

		dst->m[8] = xaxis.z;
		dst->m[9] = yaxis.z;
		dst->m[10] = zaxis.z;
		dst->m[11] = 0.0f;

		dst->m[12] = -Vec3::dot(xaxis, eye);
		dst->m[13] = -Vec3::dot(yaxis, eye);
		dst->m[14] = -Vec3::dot(zaxis, eye);
		dst->m[15] = 1.0f;
	}

	void CreatePerspective(float fieldOfView, float aspectRatio,
		float zNearPlane, float zFarPlane, Mat4* dst)
	{
		MH_ASSERT(dst);
		MH_ASSERT(zFarPlane != zNearPlane);

		float f_n = 1.0f / (zFarPlane - zNearPlane);
		float theta = MH_DEG_TO_RAD(fieldOfView) * 0.5f;
		if (std::abs(std::fmod(theta, MH_PIOVER2)) < MH_EPSILON)
		{
			MH_LOG("Invalid field of view value (%f) causes attempted calculation tan(%f), which is undefined.", fieldOfView, theta);
			return;
		}
		float divisor = std::tan(theta);
		MH_ASSERT(divisor);
		float factor = 1.0f / divisor;

		memset(dst, 0, MATRIX_SIZE);

		MH_ASSERT(aspectRatio);
		dst->m[0] = (1.0f / aspectRatio) * factor;
		dst->m[5] = factor;
		dst->m[10] = (-(zFarPlane + zNearPlane)) * f_n;
		dst->m[11] = -1.0f;
		dst->m[14] = -2.0f * zFarPlane * zNearPlane * f_n;
	}

	void CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane, Mat4* dst)
	{
		float halfWidth = width / 2.0f;
		float halfHeight = height / 2.0f;
		CreateOrthographicOffCenter(-halfWidth, halfWidth, -halfHeight, halfHeight, zNearPlane, zFarPlane, dst);
	}

	void CreateOrthographicOffCenter(float left, float right, float bottom, float top,
		float zNearPlane, float zFarPlane, Mat4* dst)
	{
		MH_ASSERT(dst);
		MH_ASSERT(right != left);
		MH_ASSERT(top != bottom);
		MH_ASSERT(zFarPlane != zNearPlane);

		memset(dst, 0, MATRIX_SIZE);
		dst->m[0] = 2 / (right - left);
		dst->m[5] = 2 / (top - bottom);
		dst->m[10] = 2 / (zNearPlane - zFarPlane);

		dst->m[12] = (left + right) / (left - right);
		dst->m[13] = (top + bottom) / (bottom - top);
		dst->m[14] = (zNearPlane + zFarPlane) / (zNearPlane - zFarPlane);
		dst->m[15] = 1;
	}


	//* [1 B C 0]
	//* [D 1 F 0]
	//* [H I 1 0]
	//* [0 0 0 1]
	void CreateShear(float B, float C, float D, float F, float H, float I, Mat4* dst)
	{
		MH_ASSERT(dst);
		dst->setIdentity();

		dst->m[1] = B;
		dst->m[2] = C;
		dst->m[4] = D;
		dst->m[6] = F;
		dst->m[8] = H;
		dst->m[9] = I;
	}

	void CreateSkewXY(float skewx, float skewy, Mat4* dst)
	{
		CreateShear((float)tanf(MH_DEG_TO_RAD(skewy)), 0.0f, (float)tanf(MH_DEG_TO_RAD(skewx)), 0.0f, 0.0f, 0.0f, dst);
	}
}

//dst->m[0] = 1.0f; dst->m[1] = 1.0f; dst->m[2] = 1.0f;
//dst->m[4] = 1.0f; dst->m[5] = 1.0f; dst->m[6] = 1.0f;
//dst->m[8] = 1.0f; dst->m[9] = 1.0f; dst->m[10] = 1.0f;

//dst->m[0] = 1.0f; dst->m[1] = 1.0f; dst->m[2] = 1.0f; dst->m[3] = 1.0f;
//dst->m[4] = 1.0f; dst->m[5] = 1.0f; dst->m[6] = 1.0f; dst->m[7] = 1.0f;
//dst->m[8] = 1.0f; dst->m[9] = 1.0f; dst->m[10] = 1.0f; dst->m[11] = 1.0f;
//dst->m[12] = 1.0f; dst->m[13] = 1.0f; dst->m[14] = 1.0f; dst->m[15] = 1.0f;