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

void	Input::listener(void)
{
	XEvent bugEvent;
	KeySym keysym;
	char *keyString = NULL;

	if(!XPending(display))
	{
		return;
	}
	XNextEvent(display, &event);
	if(KeyPress == event.type)
	{
		XLookupString(&event.xkey, keyString, 32, &keysym, NULL);
		keyString = XKeysymToString(keysym);
		if(0 == strcmp("Escape", keyString))
		{
			quit();
		}
		input.setKeyState(*keyString, true);
		std::cout << "'" << keyString << "' key pressed." << std::endl;
	}
	else if(KeyRelease == event.type)
	{
		// Check for X11 auto-repeat, dispose of false releases/presses
		if(XPending(display))	// Make sure there are events in the queue to prevent XPeekEvent from blocking execution.
		{
			XPeekEvent(display, &bugEvent);
		}
		if(KeyPress == bugEvent.type && bugEvent.xkey.keycode == event.xkey.keycode && bugEvent.xkey.time == event.xkey.time)
		{
			std::cout << "Extra key release, discarding." << std::endl;
			XNextEvent(display, &bugEvent);
			return;
		}
		//======================
		XLookupString(&event.xkey, keyString, 32, &keysym, NULL);
		keyString = XKeysymToString(keysym);
		input.setKeyState(*keyString, false);
		std::cout << "'" << keyString << "' key released" << std::endl;
	}
}

void	Input::handler(POCube* boxanne)
{
	if((false == input.getKeyState('w') && false == input.getKeyState('s')) || (true == input.getKeyState('w') && true == input.getKeyState('s')))
	{
		boxanne->setVelY(0);
	}
	else if(true == input.getKeyState('w'))
	{
		boxanne->addVelY(PLAYER_SPEED);
	}
	else if(true == input.getKeyState('s'))
	{
		boxanne->addVelY(-PLAYER_SPEED);
	}
	if((false == input.getKeyState('a') && false == input.getKeyState('d')) || (true == input.getKeyState('a') && true == input.getKeyState('d')))
	{
		boxanne->setVelX(0);
	}
	else if(true == input.getKeyState('a'))
	{
		boxanne->addVelX(-PLAYER_SPEED);
	}
	else if(true == input.getKeyState('d'))
	{
		boxanne->addVelX(PLAYER_SPEED);
	}
	if((false == input.getKeyState('q') && false == input.getKeyState('e')) || (true == input.getKeyState('q') && true == input.getKeyState('e')))
	{
		boxanne->setVelZ(0);
	}
	else if(true == input.getKeyState('q'))
	{
		boxanne->addVelZ(-PLAYER_SPEED);
	}
	else if(true == input.getKeyState('e'))
	{
		boxanne->addVelZ(PLAYER_SPEED);
	}
	boxanne->move();
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
