#include "A3LegacyWriter.h"
#include <fstream>
#include <sstream>
#include "TeamFactory.h"
#include "PlayerFactory.h"
#include "StadiumFactory.h"
#include "ReporterFactory.h"
#include "CelebrityFactory.h"
#include "SponsorFactory.h"
#include "RefereeFactory.h"
#include "ManagerFactory.h"
#include "TrainerFactory.h"
#include "YouthPlayerFactory.h"

using namespace Core;

void A3LegacyWriter::saveCountryFile(std::shared_ptr<Graph> graph, vertex_t countryId)
{
	auto country = graph->getCountryById(countryId);

	std::ofstream stream;
	std::string filename = country->getFilename();

	filename = filename.substr(0, filename.size() - 4) + "1" + filename.substr(filename.size() - 4, filename.size());

	stream.open(filename, std::ios::out);
	if (!stream.is_open())
	{
		logger->writeErrorEntry("Error while writing " + filename);
		stream.close();
		return;
	}

	// write file "header"
	stream << fileHeader << "\n";

	// country
	stream << "%SECT%LAND\n";
	CountryFactory::writeToSAV(*country, stream);

	// team
	auto teams = graph->getTeamIdsByCountry(countryId);
	for (std::vector<vertex_t>::iterator it = teams.begin(); it < teams.end(); ++it)
	{
		auto team = graph->getTeamById(*it);
		stream << "%SECT%VEREIN\n";
		TeamFactory::writeToSAV(*team, stream);

		// player
		auto players = graph->getPlayerIdsByTeam(*it);
		for (std::vector<vertex_t>::iterator itp = players.begin(); itp < players.end(); ++itp)
		{
			auto player = graph->getPlayerById(*itp);
			stream << "%SECT%SPIELER\n";
			PlayerFactory::writeToSAV(*player, stream);
			stream << "%ENDSECT%SPIELER\n";
		}
		stream << "%ENDSECT%VEREIN\n";

		// stadium
		stream << "%SECT%STADION\n";
		Stadium s = team->getStadium();
		StadiumFactory::writeToSAV(s, stream);
		stream << "%ENDSECT%STADION\n";
	}

	// amateur teams
	auto amateurTeams = country->getAmateurTeams();
	for (std::vector<std::string>::iterator it = amateurTeams.begin(); it < amateurTeams.end(); ++it)
	{
		stream << "%SECT%AMATEURV\n";
		stream << *it << "\n";
		stream << "%ENDSECT%AMATEURV\n";
	}
	
	// national trainer
	stream << "%SECT%TRAINER\n";
	auto nationalTrainer = country->getNationalTrainer();
	TrainerFactory::writeToSAV(nationalTrainer, stream);
	stream << "%ENDSECT%TRAINER\n";

	// youth player
	stream << "%SECT%AJUGEND\n";
	auto youthPlayer = country->getYouthPlayer();
	for (std::vector<YouthPlayer>::iterator it = youthPlayer.begin(); it < youthPlayer.end(); ++it)
	{
		YouthPlayerFactory::writeToSAV(*it, stream);
	}
	stream << "%ENDSECT%AJUGEND\n";

	// co-trainer
	stream << "%SECT%TRAINERP\n";
	auto coTrainer = country->getCoTrainer();
	for (std::vector<Trainer>::iterator it = coTrainer.begin(); it < coTrainer.end(); ++it)
	{
		stream << "%SECT%TRAINER\n";
		TrainerFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%TRAINER\n";
	}
	stream << "%ENDSECT%TRAINERP\n";

	// goalkeeper trainer
	stream << "%SECT%TWTRAINP\n";
	auto goalKeeperTrainer = country->getGoalKeeperTrainer();
	for (std::vector<Trainer>::iterator it = goalKeeperTrainer.begin(); it < goalKeeperTrainer.end(); ++it)
	{
		stream << "%SECT%TWTRAINER\n";
		TrainerFactory::writeToSAV(*it, stream, true);
		stream << "%ENDSECT%TWTRAINER\n";
	}
	stream << "%ENDSECT%TWTRAINP\n";

	// manager
	stream << "%SECT%MANAGERP\n";
	auto managers = country->getUnemployedManager();
	for (std::vector<Manager>::iterator it = managers.begin(); it < managers.end(); ++it)
	{
		stream << "%SECT%MANAGER\n";
		ManagerFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%MANAGER\n";
	}
	stream << "%ENDSECT%MANAGERP\n";

	// referee
	stream << "%SECT%SCHIRIP\n";
	auto referees = country->getReferees();
	for (std::vector<Referee>::iterator it = referees.begin(); it < referees.end(); ++it)
	{
		stream << "%SECT%SCHIRI\n";
		RefereeFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%SCHIRI\n";
	}
	stream << "%ENDSECT%SCHIRIP\n";

	// sponsor
	stream << "%SECT%SPONSORP\n";
	auto sponsors = country->getSponsors();
	for (std::vector<Sponsor>::iterator it = sponsors.begin(); it < sponsors.end(); ++it)
	{
		stream << "%SECT%SPONSOR\n";
		SponsorFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%SPONSOR\n";
	}
	stream << "%ENDSECT%SPONSORP\n";


	// celebrity
	stream << "%SECT%PROMIP\n";
	auto celebrities = country->getCelebrities();
	for (std::vector<Celebrity>::iterator it = celebrities.begin(); it < celebrities.end(); ++it)
	{
		stream << "%SECT%PROMI\n";
		CelebrityFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%PROMI\n";
	}
	stream << "%ENDSECT%PROMIP\n";

	// reporter
	stream << "%SECT%MEDIAP\n";
	auto reporter = country->getReporter();
	for (std::vector<Reporter>::iterator it = reporter.begin(); it < reporter.end(); ++it)
	{
		stream << "%SECT%REPORTER\n";
		ReporterFactory::writeToSAV(*it, stream);
		stream << "%ENDSECT%REPORTER\n";
	}
	
	stream << "%ENDSECT%MEDIAP\n";

	// critics
	stream << "%SECT%KRITIP\n";
	auto critics = country->getCritics();
	for (std::vector<Person>::iterator it = critics.begin(); it < critics.end(); ++it)
	{
		stream << "%SECT%KRITIKER\n";
		writePerson(*it, stream, false, false);
		stream << "%ENDSECT%KRITIKER\n";
	}
	stream << "%ENDSECT%KRITIP\n";

	// president
	stream << "%SECT%VPRAESID\n";
	Person president = country->getPresident();
	writePerson(president, stream);
	stream << "%ENDSECT%VPRAESID\n";

	stream << "%ENDSECT%LAND\n";

	stream.flush();
	stream.close();

	return;
}

void A3LegacyWriter::writePerson(Person& p, std::ofstream& out, bool birthday, bool firstnameFirst)
{
	if(firstnameFirst)
		out << p.getFirstname() << "\n";
	out << p.getLastname() << "\n";
	if(!firstnameFirst)
		out << p.getFirstname() << "\n";
	if(birthday)
		out << p.getBirthday() << "\n";
}