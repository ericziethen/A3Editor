#include "Toolset.h"
#include "A3LegacyReader.h"
#include "A3LegacyWriter.h"
#include <thread>

std::string Toolset::translate(const std::string value)
{
    if (translator == nullptr)
        return std::string();
    else
        return translator->translate(value);
}

std::vector<std::string> Toolset::GetPlayableCountries()
{
    if (playableCountries == nullptr)
        return std::vector<std::string>();
    else
        return playableCountries->GetList();
}

std::vector<std::string> Toolset::GetCountriesWithLeagues()
{
    if (countriesWithLeagues == nullptr)
        return std::vector<std::string>();
    else
        return countriesWithLeagues->GetList();
}

void Toolset::reinitializeGraph()
{
    reinitializeGraph(nullptr);
}

// reinitialize default data
void Toolset::reinitializeGraph(DialogLoader *dlg)
{
    // load graph data from Data.org folder
    loadSAVFiles("../Game/data/Data.org/", dlg);
}

void Toolset::loadGraph()
{
    loadGraph(nullptr);
}

// load current user defined data from filesystem
void Toolset::loadGraph(DialogLoader *dlg)
{
    // load graph data from Data.a3 folder
    loadSAVFiles("../Game/data/Data.a3/", dlg);
}

// save current user defined data to filesystem
void Toolset::saveGraph()
{
    // save all loaded countries to filesystem
    Core::A3LegacyWriter writer(logger);
    auto countries = graph->getCountryIds();
    for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
    {
        writer.saveCountryFile(graph, *it);
    }
}

void Toolset::loadSAVFiles(std::string path, DialogLoader* dlg)
{
    // load graph data from Data.org folder
    InitializeGraph();
    if (dlg)dlg->setProgress(10, "initilize");
    Core::A3LegacyReader reader(logger);
    // to speed up debugging only load 2 countries
    std::thread t1(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandDeut.sav");
#ifndef _DEBUG
    std::thread t2(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandEngl.sav");
    std::thread t3(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandFran.sav");
    std::thread t4(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandHoll.sav");
#endif
    t1.join();
    if (dlg) dlg->setProgress(20, "load LandDeut.sav");
#ifndef _DEBUG
    t2.join();
    if (dlg) dlg->setProgress(20, "load LandEngl.sav");
    t3.join();
    if (dlg) dlg->setProgress(20, "load LandFran.sav");
    t4.join();
    if (dlg) dlg->setProgress(20, "load LandHoll.sav");
#endif
#ifndef _DEBUG
    std::thread t5(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandItal.sav");
#endif
    std::thread t6(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandOest.sav");
#ifndef _DEBUG
    std::thread t7(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandPort.sav");
    std::thread t8(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandScho.sav");
    t5.join();
    if (dlg) dlg->setProgress(60, "load LandItal.sav");
#endif
    t6.join();
    if (dlg) dlg->setProgress(70, "load LandOest.sav");
#ifndef _DEBUG
    t7.join();
    if (dlg) dlg->setProgress(75, "load LandPort.sav");
    t8.join();
    if (dlg) dlg->setProgress(80, "load LandScho.sav");
    std::thread t9(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandSchw.sav");
    std::thread t10(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandSpan.sav");
    std::thread t11(&Core::A3LegacyReader::loadCountryFile, &reader, graph, path + "LandTuer.sav");
#endif
    // load nations file
    std::thread t12(&Core::A3LegacyReader::loadNationFile, &reader, graph, path + "Laender.sav");
#ifndef _DEBUG
    t9.join();
    if (dlg) dlg->setProgress(85, "load LandSchw.sav");
    t10.join();
    if (dlg) dlg->setProgress(90, "load LandSpan.sav");
    t11.join();
    if (dlg) dlg->setProgress(95, "load LandTuer.sav");
#endif
    t12.join();
    if (dlg) dlg->setProgress(100, "load Laender.sav");
    // load non playable countries
    std::thread t13(&Core::A3LegacyReader::loadNonPlayableCountryFile, &reader, graph, path + "Internat.sav");
    t13.join();
}