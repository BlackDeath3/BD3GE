#include "../Header/includes.h"

/*
 *	Camera Class
 */
Camera::Camera(float x, float y, float z, float lookX, float lookY, float lookZ, float lookXZAngle, float lookYZAngle)
{
	mPos[0] = x;
	mPos[1] = y;
	mPos[2] = z;
	mLook[0] = lookX;
	mLook[1] = lookY;
	mLook[2] = lookZ;
	mLookXZAngle = lookXZAngle;
	mLookYZAngle = lookYZAngle;
	mAltitudeLock = true;
}

Camera::~Camera()
{
}

void	Camera::setLookX(float lookX)
{
	mLook[0] = lookX;
}

void	Camera::setLookY(float lookY)
{
	mLook[1] = lookY;
}

void	Camera::setLookZ(float lookZ)
{
	mLook[2] = lookZ;
}

void	Camera::setLookXZAngle(float lookXZAngle)
{
	if(0 > lookXZAngle)
	{
		lookXZAngle += 360;
	}
	else if(360 < lookXZAngle)
	{
		lookXZAngle -= 360;
	}
	mLookXZAngle = lookXZAngle;
}

void	Camera::setLookYZAngle(float lookYZAngle)
{
	if(0 > lookYZAngle)
	{
		lookYZAngle += 360;
	}
	else if(360 < lookYZAngle)
	{
		lookYZAngle -= 360;
	}
	mLookYZAngle = lookYZAngle;
}

void	Camera::setAltitudeLock(bool state)
{
	mAltitudeLock = state;
}

float	Camera::getLookX(void)
{
	return mLook[0];
}

float	Camera::getLookY(void)
{
	return mLook[1];
}

float	Camera::getLookZ(void)
{
	return mLook[2];
}

float	Camera::getLookXZAngle(void)
{
	return mLookXZAngle;
}

float	Camera::getLookYZAngle(void)
{
	return mLookYZAngle;
}

bool	Camera::getAltitudeLock(void)
{
	return mAltitudeLock;
}

void	Camera::toggleAltitudeLock(void)
{
	mAltitudeLock = !mAltitudeLock;
}

float	Camera::calcDistance(float x, float y, float z)
{
	return sqrt(pow(mPos[0] - x, 2) + pow(mPos[1] - y, 2) + pow(mPos[2] - z, 2));
}

short	Camera::calcQuadrant(void)
{
	if(mPos[0] >= 0 && mPos[2] >= 0)		// Quadrant I
	{
		return 1;
	}
	else if(mPos[0] < 0 && mPos[2] >= 0)	// Quadrant II
	{
		return 2;
	}
	else if(mPos[0] <= 0 && mPos[2] < 0)	// Quadrant III
	{
		return 3;
	}
	else if(mPos[0] > 0 && mPos[2] <= 0)	// Quadrant IV
	{
		return 4;
	}
	else
	{
		return 0;
	}
}
