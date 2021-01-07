#include "QueryResult.h"
#include "PTL.h"
namespace PTL
{
    void QueryResult::KillIfNotTerminal(void)
    {
        if (isSection) ErrorKill("Attempted to access a sections content for parsing as a primitive!");
    }
    
    QueryResult::operator const std::string()
    {
        KillIfNotTerminal();
        Variables::PTLString pvar("", "");
        std::string output;
        if (!pvar.ParseFromString(content, &output)) ErrorKill("Cannot parse \"" + content + "\" as string!");
        return output;
    }
    
    QueryResult::operator int ()
    {
        KillIfNotTerminal();
        Variables::PTLInteger pvar(0, "");
        int output;
        if (!pvar.ParseFromString(content, &output)) ErrorKill("Cannot parse \"" + content + "\" as integer!");
        return output;
    }
    
    QueryResult::operator std::vector<std::string> ()
    {
        KillIfNotTerminal();
        ErrorKill("QueryResult::operator std::vector<std::string> () not yet implemented");
    }
    
    QueryResult::operator double ()
    {
        KillIfNotTerminal();
        Variables::PTLDouble pvar(0, "");
        double output;
        if (!pvar.ParseFromString(content, &output)) ErrorKill("Cannot parse \"" + content + "\" as double!");
        return output;
    }
    
    QueryResult::operator bool ()
    {
        KillIfNotTerminal();
        Variables::PTLBoolean pvar(0, "");
        bool output;
        if (!pvar.ParseFromString(content, &output)) ErrorKill("Cannot parse \"" + content + "\" as boolean!");
        return output;
    }
    
    QueryResult::operator std::vector<int> ()
    {
        KillIfNotTerminal();
        Variables::PTLDynamicIntegerArray pvar("");
        int* outputar;
        int outputNum;
        if (!pvar.ParseFromString(content, &outputar)) ErrorKill("Cannot parse \"" + content + "\" as integer array!");
        pvar.SetSecondaryVariable(&outputNum);
        std::vector<int> output;
        for (int i = 0; i < outputNum; i++) output.push_back(outputar[i]);
        return output;
    }
    
    QueryResult::operator std::vector<double> ()
    {
        KillIfNotTerminal();
        Variables::PTLDynamicDoubleArray pvar("");
        double* outputar;
        int outputNum;
        if (!pvar.ParseFromString(content, &outputar)) ErrorKill("Cannot parse \"" + content + "\" as double array!");
        pvar.SetSecondaryVariable(&outputNum);
        std::vector<double> output;
        for (int i = 0; i < outputNum; i++) output.push_back(outputar[i]);
        return output;
    }
}