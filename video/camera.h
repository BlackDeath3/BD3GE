#ifndef CAMERA_H
#define CAMERA_H

class Camera : public Object
{
	public:
				Camera(float x = 0.0, float y = 1.0, float z = 50.0, float lookX = 0.0, float lookY = 0.0, float lookZ = -5.0, float lookXZAngle = 90.0, float lookYZAngle = 180.0);
				~Camera();
		void	setLookX(float lookX);
		void	setLookY(float lookY);
		void	setLookZ(float lookZ);
		void	setLookXZAngle(float lookXZAngle);
		void	setLookYZAngle(float lookYZAngle);
		void	setAltitudeLock(bool state);
		float	getLookX(void);
		float	getLookY(void);
		float	getLookZ(void);
		float	getLookXZAngle(void);
		float	getLookYZAngle(void);
		bool	getAltitudeLock(void);
		void	toggleAltitudeLock(void);
		float	calcDistance(float x = 0.0, float y = 0.0, float z = 0.0);
		short	calcQuadrant(void);
	protected:
		float	mLook[3];
		float	mLookXZAngle;
		float	mLookYZAngle;
		bool	mAltitudeLock;
};

#endif /* CAMERA_H */
