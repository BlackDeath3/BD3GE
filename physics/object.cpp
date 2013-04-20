#include "../Header/includes.h"

/*
 *		Object class
 */

void	Object::setPosX(float x)
{
	mPos[0] = x;
}

void	Object::setPosY(float y)
{
	mPos[1] = y;
}

void	Object::setPosZ(float z)
{
	mPos[2] = z;
}

float	Object::getPosX(void)
{
	return mPos[0];
}

float	Object::getPosY(void)
{
	return mPos[1];
}

float	Object::getPosZ(void)
{
	return mPos[2];
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
	mPos[0] += mVel[0];
	mPos[1] += mVel[1];
	mPos[2] += mVel[2] / 100;
}

void	PhysicsObject::setVelX(float x)
{
	if(x > -10 && x < 10)
	{
		mVel[0] = x;
	}
}

void	PhysicsObject::setVelY(float y)
{
	if(y > -10 && y < 10)
	{
		mVel[1] = y;
	}
}

void	PhysicsObject::setVelZ(float z)
{
	if(z > -10 && z < 10)
	{
		mVel[2] = z;
	}
}

float	PhysicsObject::getVelX(void)
{
	return mVel[0];
}

float	PhysicsObject::getVelY(void)
{
	return mVel[1];
}

float	PhysicsObject::getVelZ(void)
{
	return mVel[2];
}

void	PhysicsObject::addVelX(float x)
{
	if(PLAYER_SPEED >= mVel[0] && -PLAYER_SPEED <= mVel[0])
	{
		mVel[0] += x;
	}
}

void	PhysicsObject::addVelY(float y)
{
	if(PLAYER_SPEED >= mVel[1] && -PLAYER_SPEED <= mVel[1])
	{
		mVel[1] += y;
	}
}

void	PhysicsObject::addVelZ(float z)
{
	mVel[2] += z;
}

/*
 * 		POSquare class
 */

POCube::POCube(float posX, float posY, float posZ, unsigned char red, unsigned char green, unsigned char blue, float velX, float velY, float velZ, float size)
{
	mPos[0] = posX;
	mPos[1] = posY;
	mPos[2] = posZ;
	mColor[0] = red;
	mColor[1] = green;
	mColor[2] = blue;
	mVel[0] = velX;
	mVel[1] = velY;
	mVel[2] = velZ;
	mSize = size;
//	mOggFile = new Ogg("/home/david/Programming/My Programs/Eclipse Workspace/GameLoop/Resource/01. And the Heavens Shall Tremble.ogg");
//	mOggFile.loadOggFile("/home/david/Programming/My Programs/Eclipse Workspace/GameLoop/Resource/01. And the Heavens Shall Tremble.ogg");
//	mOggFile.play();
	glGenVertexArrays(1, &mVAO);
	glBindVertexArray(mVAO);
	glGenBuffers(1, &mVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
}

void	POCube::draw(void)
{
	GLfloat westEdge = mPos[0] - (mSize / 2);
	GLfloat eastEdge = mPos[0] + (mSize / 2);
	GLfloat topEdge = mPos[1] + (mSize / 2);
	GLfloat bottomEdge = mPos[1] - (mSize / 2);
	GLfloat northEdge = mPos[2] - (mSize / 2);
	GLfloat southEdge = mPos[2] + (mSize / 2);

	// West edge
	mVertices[0] = westEdge;
	mVertices[1] = bottomEdge;
	mVertices[2] = northEdge;
	mVertices[3] = westEdge;
	mVertices[4] = topEdge;
	mVertices[5] = northEdge;
	mVertices[6] = westEdge;
	mVertices[7] = bottomEdge;
	mVertices[8] = southEdge;
	mVertices[9] = westEdge;
	mVertices[10] = topEdge;
	mVertices[11] = southEdge;
	mVertices[12] = westEdge;
	mVertices[13] = bottomEdge;
	mVertices[14] = southEdge;
	mVertices[15] = westEdge;
	mVertices[16] = topEdge;
	mVertices[17] = northEdge;
	//
	// East edge
	mVertices[18] = eastEdge;
	mVertices[19] = bottomEdge;
	mVertices[20] = southEdge;
	mVertices[21] = eastEdge;
	mVertices[22] = topEdge;
	mVertices[23] = southEdge;
	mVertices[24] = eastEdge;
	mVertices[25] = bottomEdge;
	mVertices[26] = northEdge;
	mVertices[27] = eastEdge;
	mVertices[28] = topEdge;
	mVertices[29] = northEdge;
	mVertices[30] = eastEdge;
	mVertices[31] = bottomEdge;
	mVertices[32] = northEdge;
	mVertices[33] = eastEdge;
	mVertices[34] = topEdge;
	mVertices[35] = southEdge;
	//
	// Top edge
	mVertices[36] = westEdge;
	mVertices[37] = topEdge;
	mVertices[38] = southEdge;
	mVertices[39] = westEdge;
	mVertices[40] = topEdge;
	mVertices[41] = northEdge;
	mVertices[42] = eastEdge;
	mVertices[43] = topEdge;
	mVertices[44] = southEdge;
	mVertices[45] = eastEdge;
	mVertices[46] = topEdge;
	mVertices[47] = northEdge;
	mVertices[48] = eastEdge;
	mVertices[49] = topEdge;
	mVertices[50] = southEdge;
	mVertices[51] = westEdge;
	mVertices[52] = topEdge;
	mVertices[53] = northEdge;
	//
	// Bottom edge
	mVertices[54] = westEdge;
	mVertices[55] = bottomEdge;
	mVertices[56] = southEdge;
	mVertices[57] = westEdge;
	mVertices[58] = bottomEdge;
	mVertices[59] = northEdge;
	mVertices[60] = eastEdge;
	mVertices[61] = bottomEdge;
	mVertices[62] = southEdge;
	mVertices[63] = eastEdge;
	mVertices[64] = bottomEdge;
	mVertices[65] = northEdge;
	mVertices[66] = eastEdge;
	mVertices[67] = bottomEdge;
	mVertices[68] = southEdge;
	mVertices[69] = westEdge;
	mVertices[70] = bottomEdge;
	mVertices[71] = northEdge;
	//
	// North edge
	mVertices[72] = westEdge;
	mVertices[73] = bottomEdge;
	mVertices[74] = southEdge;
	mVertices[75] = westEdge;
	mVertices[76] = topEdge;
	mVertices[77] = southEdge;
	mVertices[78] = eastEdge;
	mVertices[79] = bottomEdge;
	mVertices[80] = southEdge;
	mVertices[81] = eastEdge;
	mVertices[82] = topEdge;
	mVertices[83] = southEdge;
	mVertices[84] = eastEdge;
	mVertices[85] = bottomEdge;
	mVertices[86] = southEdge;
	mVertices[87] = westEdge;
	mVertices[88] = topEdge;
	mVertices[89] = southEdge;
	//
	// South edge
	mVertices[90] = westEdge;
	mVertices[91] = bottomEdge;
	mVertices[92] = southEdge;
	mVertices[93] = westEdge;
	mVertices[94] = topEdge;
	mVertices[95] = southEdge;
	mVertices[96] = eastEdge;
	mVertices[97] = bottomEdge;
	mVertices[98] = southEdge;
	mVertices[99] = eastEdge;
	mVertices[100] = topEdge;
	mVertices[101] = southEdge;
	mVertices[102] = eastEdge;
	mVertices[103] = bottomEdge;
	mVertices[104] = southEdge;
	mVertices[105] = westEdge;
	mVertices[106] = topEdge;
	mVertices[107] = southEdge;
	//
	glBufferData(GL_ARRAY_BUFFER, 432, mVertices, GL_STATIC_DRAW);
	// OpenGL 3.x+ Retained Mode
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDisableVertexAttribArray(0);
	//
	// Pre-OpenGL 3.x Immediate Mode
/*	float westBoundary = mPos[0] - (mSize / 2);
	float eastBoundary = mPos[0] + (mSize / 2);
	float topBoundary = mPos[1] + (mSize / 2);
	float bottomBoundary = mPos[1] - (mSize / 2);
	float northBoundary = mPos[2] + (mSize / 2);
	float southBoundary = mPos[2] - (mSize / 2);

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
	glEnd();*/
	//
}

void	POCube::setSize(float size)
{
	mSize = size;
}

float	POCube::getSize(void)
{
	return mSize;
}
