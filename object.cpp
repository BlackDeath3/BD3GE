#include "../Header/includes.h"

/*
 *		Object class
 */

void	Object::setPosX(float x)
{
	mPosX = x;
}

void	Object::setPosY(float y)
{
	mPosY = y;
}

void	Object::setPosZ(float z)
{
	mPosZ = z;
}

float	Object::getPosX(void)
{
	return mPosX;
}

float	Object::getPosY(void)
{
	return mPosY;
}

float	Object::getPosZ(void)
{
	return mPosZ;
}

unsigned char *	Object::getColor(void)
{
	return mColor;
}

/*
 * bool	Object::isInBounds(void)
{
}
*/

/*
 *		PhysicsObject class
 */

void	PhysicsObject::move(void)
{
	mPosX += mVelX;
	mPosY += mVelY;
	mPosZ += mVelZ / 100;
}

void	PhysicsObject::setVelX(float x)
{
	if(x > -10 && x < 10)
	{
		mVelX = x;
	}
}

void	PhysicsObject::setVelY(float y)
{
	if(y > -10 && y < 10)
	{
		mVelY = y;
	}
}

void	PhysicsObject::setVelZ(float z)
{
	if(z > -10 && z < 10)
	{
		mVelZ = z;
	}
}

float	PhysicsObject::getVelX(void)
{
	return mVelX;
}

float	PhysicsObject::getVelY(void)
{
	return mVelY;
}

float	PhysicsObject::getVelZ(void)
{
	return mVelZ;
}

void	PhysicsObject::addVelX(float x)
{
	mVelX += x;
}

void	PhysicsObject::addVelY(float y)
{
	mVelY += y;
}

void	PhysicsObject::addVelZ(float z)
{
	mVelZ += z;
}

/*
 * 		POSquare class
 */

POCube::POCube(float posX, float posY, float posZ, unsigned char red, unsigned char green, unsigned char blue, float velX, float velY, float velZ, float size)
{
	mPosX = posX;
	mPosY = posY;
	mPosZ = posZ;
	mColor[0] = red;
	mColor[1] = green;
	mColor[2] = blue;
	mVelX = velX;
	mVelY = velY;
	mVelZ = velZ;
	mSize = size;
}

void	POCube::draw(void)
{
	float westBoundary = mPosX - (mSize / 2);
	float eastBoundary = mPosX + (mSize / 2);
	float topBoundary = mPosY + (mSize / 2);
	float bottomBoundary = mPosY - (mSize / 2);
	float northBoundary = mPosZ + (mSize / 2);
	float southBoundary = mPosZ - (mSize / 2);

	glColor3f(mColor[0], mColor[1], mColor[2]);
	glBegin(GL_POLYGON);	// North
		glVertex3f(westBoundary, topBoundary, northBoundary);
		glVertex3f(eastBoundary, topBoundary, northBoundary);
		glVertex3f(eastBoundary, bottomBoundary, northBoundary);
		glVertex3f(westBoundary, bottomBoundary, northBoundary);
	glEnd();
	glBegin(GL_POLYGON);	// South
		glVertex3f(westBoundary, topBoundary, southBoundary);
		glVertex3f(eastBoundary, topBoundary, southBoundary);
		glVertex3f(eastBoundary, bottomBoundary, southBoundary);
		glVertex3f(westBoundary, bottomBoundary, southBoundary);
	glEnd();
	glBegin(GL_POLYGON);	// West
		glVertex3f(westBoundary, topBoundary, northBoundary);
		glVertex3f(westBoundary, topBoundary, southBoundary);
		glVertex3f(westBoundary, bottomBoundary, southBoundary);
		glVertex3f(westBoundary, bottomBoundary, northBoundary);
	glEnd();
	glBegin(GL_POLYGON);	// East
		glVertex3f(eastBoundary, topBoundary, northBoundary);
		glVertex3f(eastBoundary, topBoundary, southBoundary);
		glVertex3f(eastBoundary, bottomBoundary, southBoundary);
		glVertex3f(eastBoundary, bottomBoundary, northBoundary);
	glEnd();
	glBegin(GL_POLYGON);	// Top
		glVertex3f(westBoundary, topBoundary, southBoundary);
		glVertex3f(westBoundary, topBoundary, northBoundary);
		glVertex3f(eastBoundary, topBoundary, northBoundary);
		glVertex3f(eastBoundary, topBoundary, southBoundary);
	glEnd();
	glBegin(GL_POLYGON);	// Bottom
		glVertex3f(westBoundary, bottomBoundary, southBoundary);
		glVertex3f(westBoundary, bottomBoundary, northBoundary);
		glVertex3f(eastBoundary, bottomBoundary, northBoundary);
		glVertex3f(eastBoundary, bottomBoundary, southBoundary);
	glEnd();
}

void	POCube::setSize(float size)
{
	mSize = size;
}

float	POCube::getSize(void)
{
	return mSize;
}
