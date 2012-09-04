#include "../Header/includes.h"

/*
 * 		Key class
 */

Key::Key()
{
	mCharacter = '\0';
	mState = false;
}

Key::~Key()
{
}

void	Key::setCharacter(char character)
{
	mCharacter = character;
}

void	Key::setState(bool state)
{
	mState = state;
}

char	Key::getCharacter(void)
{
	return mCharacter;
}

bool	Key::getState(void)
{
	return mState;
}

/*
 * 		Input class
 */

Input::Input()
{
	int i = 0;

	for(; i < 26; ++i)					// Initialize a-z character keys
	{
		mKeys[i].setCharacter((char)(i + 97));
	}
	mKeys[26].setCharacter(' ');		// Initialize space key
}

Input::~Input()
{
}

void	Input::handler(void)
{
	if((false == input.getKeyState('w') && false == input.getKeyState('s')) || true == input.getKeyState('w') && true == input.getKeyState('s'))
	{
		boxanne.setVelY(0);
	}
	else if(true == input.getKeyState('w') && PLAYER_SPEED > boxanne.getVelY())
	{
	//	boxanne.addVelY(PLAYER_SPEED);
		boxanne.setVelY(PLAYER_SPEED);
	}
	else if(true == input.getKeyState('s') && -PLAYER_SPEED < boxanne.getVelY())
	{
	//	boxanne.addVelY(-PLAYER_SPEED);
		boxanne.setVelY(-PLAYER_SPEED);
	}
	if((false == input.getKeyState('a') && false == input.getKeyState('d')) || (true == input.getKeyState('a') && true == input.getKeyState('d')))
	{
		boxanne.setVelX(0);
	}
	else if(true == input.getKeyState('a') && -PLAYER_SPEED < boxanne.getVelX())
	{
		boxanne.addVelX(-PLAYER_SPEED);
	}
	else if(true == input.getKeyState('d') && PLAYER_SPEED > boxanne.getVelX())
	{
		boxanne.addVelX(PLAYER_SPEED);
	}
	if((false == input.getKeyState('q') && false == input.getKeyState('e')) || (true == input.getKeyState('q') && true == input.getKeyState('e')))
	{
		boxanne.setVelZ(0);
	}
	else if(true == input.getKeyState('q') && -PLAYER_SPEED < boxanne.getVelX())
	{
		boxanne.addVelZ(-PLAYER_SPEED);
	}
	else if(true == input.getKeyState('e') && PLAYER_SPEED > boxanne.getVelX())
	{
		boxanne.addVelZ(PLAYER_SPEED);
	}
	boxanne.move();
}

void	Input::setKeyState(char character, bool state)
{
	int i = 0;
	timeval time;

	for(; i < KEY_COUNT; ++i)
	{
		if(mKeys[i].getCharacter() == character)
		{
			mKeys[i].setState(state);
		}
	}
}

bool	Input::getKeyState(char character)
{
	int i = 0;

	for(; i < KEY_COUNT; ++i)
	{
		if(mKeys[i].getCharacter() == character)
		{
			return mKeys[i].getState();
		}
	}

	return false;
}
