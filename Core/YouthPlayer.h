#pragma once

#include <string>
#include <string_view>
#include "Person.h"
#include "LoggingFacility.h"

class YouthPlayer : public Person
{
	friend class YouthPlayerFactory;
public:
	YouthPlayer() {}
	YouthPlayer(const Logger& logger) : logger(logger) {}
	~YouthPlayer() {}

	// getter/setter
	short getMainPosition() { return mainPosition; }
	short getTeamId() { return teamId; }

protected:
	void setMainPosition(short mainPosition) { this->mainPosition = mainPosition; }
	void setTeamId(short teamId) { this->teamId = teamId; }

private:
	short mainPosition;
	short teamId;

	Logger logger;
};
