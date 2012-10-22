#ifndef OGG_H
#define OGG_H

//class Object;

class Ogg
{
	public:
		Ogg();
		Ogg(char* filename);
//		Ogg(Object* object);
//		Ogg(char* filename, Object* object);
		~Ogg();
		ALuint				getIdBuffer(void);
		ALuint				getIdSources(void);
		ALuint				getFormat(void);
		ALsizei				getFrequency(void);
		std::vector <char>	getBuffer(void);
		void				loadOggFile(char* filename);
		void				play(void);
	protected:
//		Object*				mObject;
		ALuint				mIdBuffer;
		ALuint				mIdSources;
		bool				mLoaded;
		OggVorbis_File		mFile;
		vorbis_info*		mInfo;
		ALuint				mFormat;
		ALsizei				mFrequency;
		std::vector <char>	mBuffer;
};

#endif /* OGG_H */
