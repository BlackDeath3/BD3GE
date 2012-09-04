#ifndef OBJECT_H
#define OBJECT_H

class Object
{
	public:
		virtual void	draw(void) {};
		void			setPosX(float x);
		void			setPosY(float y);
		void			setPosZ(float z);
		float			getPosX(void);
		float			getPosY(void);
		float			getPosZ(void);
		unsigned char*	getColor(void);
	//	bool			isInBounds(void);	// TO DO: create general method that checks to see if object is within game window
	protected:
		float			mPosX;
		float			mPosY;
		float			mPosZ;
		unsigned char	mColor[3];
};

class PhysicsObject : public Object
{
	public:
		virtual void	draw(void) {};
		void			move(void);
		void			setVelX(float x);
		void			setVelY(float y);
		void			setVelZ(float z);
		float			getVelX(void);
		float			getVelY(void);
		float			getVelZ(void);
		float			getVelVec(void);
		void			addVelX(float x);
		void			addVelY(float y);
		void			addVelZ(float z);
	protected:
		float			mVelX;
		float			mVelY;
		float			mVelZ;
};

class POCube : public PhysicsObject
{
	public:
		POCube(float posX, float posY, float posZ, unsigned char red, unsigned char green, unsigned char blue, float velX, float velY, float velZ, float size);
		virtual void	draw(void);
		void			setSize(float size);
		float			getSize(void);
	protected:
		float			mSize;
};

#endif /* OBJECT_H */
