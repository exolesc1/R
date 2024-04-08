#include "log.h"
#include <iostream>


Log::Level Log::mLogLevel = LevelInfo;

void Log::SetLevel(Level level)
{
	mLogLevel = level;
}

void Log::Error(const char* message)
{
	if (mLogLevel >= LevelError)
		std::cout << "[error]: " << message << std::endl;
}

void Log::Warn(const char* message)
{
	if (mLogLevel >= LevelWarning)
		std::cout << "[Warning]: " << message << std::endl;
}

void Log::Info(const char* message)
{
	if (mLogLevel >= LevelInfo)
		std::cout << "[info]: " << message << std::endl;
}
