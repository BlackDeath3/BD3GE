#ifndef INPUT_H
#define INPUT_H

class Key
{
	public:
				Key();
				~Key();
		void	setCharacter(char character);
		void	setState(bool state);
		char	getCharacter(void);
		bool	getState(void);
	protected:
		char	mCharacter;
		bool	mState;
};

class Input
{
	public:
				Input();
				~Input();
		void	handler(void);
		void	setKeyState(char character, bool state);
		bool	getKeyState(char character);
	protected:
		Key		mKeys[KEY_COUNT];
};

#endif /* INPUT_H */
