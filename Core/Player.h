#pragma once

#include <string>
#include <string_view>
#include "Person.h"
#include "EasyLogger.h"

namespace Core
{
	class Player : public Person
	{
		friend class PlayerFactory;
	public:
		Player(const Logger& logger) : hasArtistName(false), age(0), skinColor(0), hairColor(0), skill(0), nationalityFirst(0), residient(0), mainPosition(0), alternativeFristPosition(0),
									   alternativeSecondPosition(0), playerSkillPositive(0), playerSkillNegative(0), playerProperties(0), playerPersonality(0), foot(0), talent(0), audience(0),
									   nationalitySecond(0), nationalPlayer(false), nationalPlayerResigned(false), nationalTeam(false), captainResigned(false), shirtNumber(0), appearence(0),
									   unknown1(0), unknown2(0), unknown3(0), unknown4(0), unknown5(0), unknown6(0), unknown7(0), logger(logger) {}
		~Player() {}
		bool operator==(const Player& p) const
		{
			return firstname == p.firstname && lastname == p.lastname && birthday == p.birthday;
		}
		bool operator!=(const Player& p) const
		{
			return firstname != p.firstname || lastname != p.lastname || birthday != p.birthday;
		}

		// getter
		short getSkinColor() { return skinColor; }
		short getHairColor() { return hairColor; }
		short getAge() { return age; }
		short getSkill() { return skill; }
		short getNationalityFirst() { return nationalityFirst; }
		bool getResidient() { return residient; }
		short getMainPosition() { return mainPosition; }
		short getAlternativeFirstPosition() { return alternativeFristPosition; }
		short getAlternativeSecondPosition() { return alternativeSecondPosition; }
		int getPlayerSkillPositive() { return playerSkillPositive; }
		int getPlayerSkillNegative() { return playerSkillNegative; }
		int getPlayerProperties() { return playerProperties; }
		int getPlayerPersonality() { return playerPersonality; }
		bool getHasArtistName() { return hasArtistName; }
		std::string getArtistName() { return artistName; }
		short getFoot() { return foot; }
		short getTalent() { return talent; }
		short getHealth() { return health; }
		short getAudience() { return audience; }
		short getNationalitySecond() { return nationalitySecond; }
		bool getNationalPlayer() { return nationalPlayer; }
		bool getNationalPlayerResigned() { return nationalPlayerResigned; }
		bool getNationalTeam() { return nationalTeam; }
		bool getCaptainResigned() { return captainResigned; }
		short getShirtNumber() { return shirtNumber; }
		long getAppearence() { return appearence; }
		int getUnknown1() { return unknown1; }
		short getUnknown2() { return unknown2; }
		int getUnknown3() { return unknown3; }
		short getUnknown4() { return unknown4; }
		short getUnknown5() { return unknown5; }
		short getUnknown6() { return unknown6; }
		short getUnknown7() { return unknown7; }
		// setter
		void setSkinColor(const short skinColor) { this->skinColor = skinColor; }
		void setHairColor(const short hairColor) { this->hairColor = hairColor; }
		void setAge(const short age) { this->age = age; }
		void setSkill(const short skill) { this->skill = skill; }
		void setNationalityFirst(const short nationalityFirst) { this->nationalityFirst = nationalityFirst; }
		void setResidient(const bool residient) { this->residient = residient; }
		void setMainPosition(const short mainPosition) { this->mainPosition = mainPosition; }
		void setAlternativeFirstPosition(const short alternativeFirstPosition) { this->alternativeFristPosition = alternativeFirstPosition; }
		void setAlternativeSecondPosition(const short alternativeSecondPosition) { this->alternativeSecondPosition = alternativeSecondPosition; }
		void setPlayerSkillPositive(const int playerSkillPositive) { this->playerSkillPositive = playerSkillPositive; }
		void setPlayerSkillNegative(const int playerSkillNegative) { this->playerSkillNegative = playerSkillNegative; }
		void setPlayerProperties(const int playerProperties) { this->playerProperties = playerProperties; }
		void setPlayerPersonality(const int playerPersonality) { this->playerPersonality = playerPersonality; }
		void setHasArtistName(const bool hasArtistName) { this->hasArtistName = hasArtistName; }
		void setArtistName(const std::string artistName) { this->artistName = artistName; }
		void setFoot(const short foot) { this->foot = foot; }
		void setTalent(const short talent) { this->talent = talent; }
		void setHealth(const short health) { this->health = health; }
		void setAudience(const short audience) { this->audience = audience; }
		void setNationalitySecond(const short nationalitySecond) { this->nationalitySecond = nationalitySecond; }
		void setNationalPlayer(const bool nationalPlayer) { this->nationalPlayer = nationalPlayer; }
		void setNationalPlayerResigned(const bool nationalPlayerResigned) { this->nationalPlayerResigned = nationalPlayerResigned; }
		void setNationalTeam(const bool nationalTeam) { this->nationalTeam = nationalTeam; }
		void setCaptainResigned(const bool captainResigned) { this->captainResigned = captainResigned; }
		void setShirtNumber(const short shirtNumber) { this->shirtNumber = shirtNumber; }
		void setAppearence(const long appearence) { this->appearence = appearence; }
		void setUnknown1(const int unknown1) { this->unknown1 = unknown1; }
		void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
		void setUnknown3(const int unknown3) { this->unknown3 = unknown3; }
		void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
		void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
		void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
		void setUnknown7(const short unknown7) { this->unknown7 = unknown7; }

	private:
		bool hasArtistName;
		std::string artistName;
		short age = 0;					// nonsense because of birthday
		short skinColor = 0;			// 0...bright, 1...dark, 2...afrikan, 3...asian
		short hairColor = 0;			// 0...light blonde, 1...blonde, 2...brown, 3...red, 4...black, 5...bald, 6...grey
		short skill = 0;
		short nationalityFirst = 0;
		bool residient;
		short mainPosition = 0;
		short alternativeFristPosition = 0;
		short alternativeSecondPosition = 0;
		int playerSkillPositive = 0;		// bitmask for goalkeeper or field player
		int playerSkillNegative = 0;		// * **** **** **** **1*...header
											// * **** **** **** *1**...duel
											// * **** **** **** 1***...speed
											// * **** **** ***1 ****...firingPower
											// * **** **** **1* ****...penalty
											// * **** **** *1** ****...freeKicks
											// * **** **** 1*** ****...flanks
											// * **** ***1 **** ****...goalInstict
											// * **** **1* **** ****...runner
											// * **** *1** **** ****...technique
											// * **** 1*** **** ****...ballMagic
											// * ***1 **** **** ****...playmaker
											// * **1* **** **** ****...quadChain
											// * *1** **** **** ****...gameOverview
											// * 1*** **** **** ****...holdBall
											// 1 **** **** **** ****...dribbling
		int playerProperties = 0;			// bitmask
											// * **** **** **** **1*...fighter
											// * **** **** **** *1**...trainingWorldChamption
											// * **** **** **** 1***...trainingLazyPlayer
											// * **** **** ***1 ****...violator
											// * **** **** **1* ****...fairPlayer
											// * **** **** *1** ****...mimosa
											// * **** **** 1*** ****...slyfox
											// * **** ***1 **** ****...specialist
											// * **** **1* **** ****...allrounder
											// * **** *1** **** ****...flexiblePlayer
											// * **** 1*** **** ****...refereeFavorite
											// * ***1 **** **** ****...homePlayer
											// * **1* **** **** ****...fairWeatherPlayer
											// * *1** **** **** ****...joker
											// * 1*** **** **** ****...egoist
											// 1 **** **** **** ****...brotherLightFooted
		int playerPersonality = 0;			// bitmask
											// * **** **** **** **1*...leader
											// * **** **** **** *1**...hotHead
											// * **** **** **** 1***...happyNature
											// * **** **** ***1 ****...manWithoutNerves
											// * **** **** **1* ****...bundleOfNerves
											// * **** **** *1** ****...phlegmatic
											// * **** **** 1*** ****...moneyVolture
											// * **** ***1 **** ****...clubSupporter
											// * **** **1* **** ****...professionalPattern
											// * **** *1** **** ****...scandalNoodle
											// * **** 1*** **** ****...sensitive
											// * ***1 **** **** ****...airsAndGraces
											// * **1* **** **** ****...teenStar
											// * *1** **** **** ****...troublemaker
											// * 1*** **** **** ****...liverwurst
											// 1 **** **** **** ****...unifyingFigure
		short foot = 0;						// 1...right, 2...left, 3...both feet
		short talent = 0;					// 5...two left feet, 4...little talented, 3...normally talented, 2...talent, 1...mega talent
		short health = 0;					// 1...normal, 2...robust, 3...susceptible, 4...kneeProblems, 5...quicklyFitAtain, 6...lastsUntilFitAgain, 7...snivelling
		short audience = 0;					// 1...normal, 2...favorite, 3...hateFigure
		short nationalitySecond = 0;
		bool nationalPlayer;
		bool nationalPlayerResigned;
		bool nationalTeam;
		bool captainResigned;
		short shirtNumber = 0;
		long appearence = 0;			// bitmask for hair type and beard
										// 0000 **** **** **** ****...extremly short
										// 0001 **** **** **** ****...short
										// 0010 **** **** **** ****...curly head
										// 0011 **** **** **** ****...long
										// **** **** **** **** ***1...unshaven
										// **** **** **** **** **1*...beard
										// **** **** **** **** *1**...moustache
										// **** **** **** **** 1***...goatee

		int unknown1 = 0;
		short unknown2 = 0;
		int unknown3 = 0;
		short unknown4 = 0;
		short unknown5 = 0;
		short unknown6 = 0;
		short unknown7 = 0;

		Logger logger;
	};
}