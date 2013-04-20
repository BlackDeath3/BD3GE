/*
 * 		Ogg class
 */

#include "../Header/includes.h"

//Ogg::Ogg(Object* object)
Ogg::Ogg()
{
//	mObject = object;
	alGenBuffers(1, &mIdBuffer);
	alGenSources(1, &mIdSources);
	alSource3f(mIdSources, AL_POSITION, 0.0f, 0.0f, 0.0f);
	mInfo = NULL;
	mFormat = 0;
	mFrequency = 0;
	mLoaded = false;
}

//Ogg::Ogg(char* filename, Object* object)
Ogg::Ogg(char*filename)
{
//	mObject = object;
	alGenBuffers(1, &mIdBuffer);
	alGenSources(1, &mIdSources);
	alSource3f(mIdSources, AL_POSITION, 0.0f, 0.0f, 0.0f);
	mLoaded = false;
	loadOggFile(filename);
	mLoaded = true;
}

Ogg::~Ogg()
{
	alDeleteBuffers(1, &mIdBuffer);
	alDeleteSources(1, &mIdSources);
}

ALuint Ogg::getIdBuffer(void)
{
	return mIdBuffer;
}

ALuint Ogg::getIdSources(void)
{
	return mIdSources;
}

ALuint Ogg::getFormat(void)
{
	return mFormat;
}

ALsizei Ogg::getFrequency(void)
{
	return mFrequency;
}

std::vector <char> Ogg::getBuffer(void)
{
	return mBuffer;
}

void Ogg::loadOggFile(char* filename)
{
	FILE* infile = NULL;
	int bitStream = 0;
	long bytes = 0;
	char tempBuffer[32768];
	bool success;

	if(true == mLoaded)
	{
		std::cout << "File object already loaded." << std::endl;
		return;
	}
	infile = fopen(filename, "rb");
	success = ov_open(infile, &mFile, NULL, 0);
	switch(success)
	{
		case OV_EREAD:
			std::cout << "OV_EREAD" << std::endl;
			break;
		case OV_ENOTVORBIS:
			std::cout << "OV_ENOTVORBIS" << std::endl;
			break;
		case OV_EVERSION:
			std::cout << "OV_EVERSION" << std::endl;
			break;
		case OV_EBADHEADER:
			std::cout << "OV_EBADHEADER" << std::endl;
			break;
		case OV_EFAULT:
			std::cout << "OV_EFAULT" << std::endl;
			break;
		default:
			std::cout << "File opened successfully." << std::endl;
			break;
	}
	mInfo = ov_info(&mFile, -1);
	switch(mInfo->channels)
	{
		case 1:
			mFormat = AL_FORMAT_MONO16;
			std::cout << "Format is mono-16." << std::endl;
			break;
		case 2:
			std::cout << "Format is stereo-16." << std::endl;
			mFormat = AL_FORMAT_STEREO16;
			break;
	}
	mFrequency = mInfo->rate;
	do
	{
		bytes = ov_read(&mFile, tempBuffer, 32768, 0, 2, 1, &bitStream);
		mBuffer.insert(mBuffer.end(), tempBuffer, tempBuffer + bytes);
	} while(bytes > 0);
	ov_clear(&mFile);
}

void Ogg::play(void)
{
	ALint state = 0;

	alBufferData(mIdBuffer, mFormat, &mBuffer[0], mBuffer.size(), mFrequency);
	alSourcei(mIdSources, AL_BUFFER, mIdBuffer);
	alSourcePlay(mIdSources);
/*	do
	{
		alGetSourcei(mIdSources, AL_SOURCE_STATE, &state);
	} while (state != AL_STOPPED);*/
}
