#include "pch.h"

namespace Helper
{
	D2D1_VECTOR_2F AddVector(const D2D1_VECTOR_2F& a, const D2D1_VECTOR_2F& b)
	{
		D2D1_VECTOR_2F result;
		result.x = a.x + b.x;
		result.y = a.y + b.y;
		return result;
	}

	D2D1_VECTOR_2F NormalizeVector(const D2D1_VECTOR_2F& vector)
	{
		D2D1_VECTOR_2F result{ 0 };
		float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
		if ((vector.x == 0.0f) && (vector.y == 0.0f))
		{
			return result;
		}

		result.x = vector.x / length;
		result.y = vector.y / length;
		return result;
	}

	D2D1_VECTOR_2F MultiplyVector(const D2D1_VECTOR_2F& vector, float scalar)
	{
		D2D1_VECTOR_2F result;
		result.x = vector.x * scalar;
		result.y = vector.y * scalar;
		return result;
	}

	bool IsZeroVector(const D2D1_VECTOR_2F& vector)
	{
		return (vector.x == 0.0f) && (vector.y == 0.0f);
	}

	float GetVectorLength(const D2D1_VECTOR_2F& vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	void GetRotationFromMatrix(const D2D_MATRIX_3X2_F& mat, float* Rotation)
	{
		*Rotation = atan2f(mat._21, mat._11);
	}

	void GetScaleFromMatrix(const D2D_MATRIX_3X2_F& mat, float* ScaleX, float* ScaleY)
	{
		*ScaleX = sqrtf(mat._11 * mat._11 + mat._12 * mat._12);
		*ScaleY = sqrtf(mat._21 * mat._21 + mat._22 * mat._22);
	}

	void GetLocationFromMatrix(const D2D_MATRIX_3X2_F& mat, float* x, float* y)
	{
		*x = mat._31;
		*y = mat._32;
	}

	void SetRotationToMatrix(D2D_MATRIX_3X2_F& mat, float Rotation)
	{
		mat._11 = cosf(Rotation);
		mat._12 = sinf(Rotation);
		mat._21 = -sinf(Rotation);
		mat._22 = cosf(Rotation);
	}

	void SetScaleToMatrix(D2D_MATRIX_3X2_F& mat, float ScaleX, float ScaleY)
	{
		mat._11 = ScaleX;
		mat._22 = ScaleY;
	}
}

