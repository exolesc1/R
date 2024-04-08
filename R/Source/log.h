#include <iostream>

class Log
{
public:
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};

public:
	void SetLevel(Level level);
	void Error(const char* message);
	void Warn(const char* message);
	void Info(const char* message);

public:
	static Level mLogLevel;
};