#include "../common/vector.h"

void mat44_perspective(mat44_t* m, float fovy, float aspect_ratio, float near_plane, float far_plane)
{
	const float
		y_scale = (float)(1 / cosf(fovy * M_PI / 360.0f)),
		x_scale = y_scale / aspect_ratio,
		frustum_length = far_plane - near_plane;

	m->m[0] = x_scale;
	m->m[5] = y_scale;
	m->m[10] = -((far_plane + near_plane) / frustum_length);
	m->m[11] = -1;
	m->m[14] = -((2 * near_plane * far_plane) / frustum_length);
}

float smoothDamp(float current, float target, float* currentVelocity, float smoothTime, float maxSpeed, float deltaTime)
{
	float num = 2.f / smoothTime;
	float num2 = num * deltaTime;
	float num3 = 1.f / (1.f + num2 + 0.48f * num2 * num2 + 0.235f * num2 * num2 * num2);
	float num4 = current - target;
	float num5 = target;
	float num6 = maxSpeed * smoothTime;

	if (num4 < -num6)
		num4 = -num6;
	else if (num4 > num6)
		num4 = num6;

	target = current - num4;
	float num7 = (*currentVelocity + num * num4) * deltaTime;
	*currentVelocity = (*currentVelocity - num * num7) * num3;
	float num8 = target + (num4 + num7) * num3;
	
	if (num5 - current > 0.f == num8 > num5)
	{
		num8 = num5;
		*currentVelocity = (num8 - num5) / deltaTime;
	}

	return num8;
}

float vec4_distance(vec4_t* p1, vec4_t* p2)
{
	return -1.f;
}
