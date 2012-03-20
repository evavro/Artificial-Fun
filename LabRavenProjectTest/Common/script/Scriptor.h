#ifndef SCRIPTOR_H
#define SCRIPTOR_H
//-----------------------------------------------------------------------------
//
//  Name:   Scriptor.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class encapsulating the basic functionality necessary to read a
//          Lua config file
//-----------------------------------------------------------------------------
extern "C"
{
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}

#pragma comment(lib, "lua.lib")
//#pragma comment(lib, "lualib.lib")

#include "LuaHelperFunctions.h"



class Scriptor
{
private:

  lua_State* m_pLuaState;

public:

  Scriptor():m_pLuaState(lua_open())
  {
    //open the libraries
    OpenLuaLibraries(m_pLuaState);
  }

  ~Scriptor(){lua_close(m_pLuaState);}

  void RunScriptFile(char* ScriptName)
  {
     RunLuaScript(m_pLuaState, ScriptName);
  }

  lua_State* GetState(){return m_pLuaState;}


  int GetInt(char* VariableName)
  {
    return PopLuaNumber<int>(m_pLuaState, VariableName);
  }
    
  double GetFloat(char* VariableName)
  {
    return PopLuaNumber<float>(m_pLuaState, VariableName);
  }

  double GetDouble(char* VariableName)
  {
    return PopLuaNumber<double>(m_pLuaState, VariableName);
  }

  std::string GetString(char* VariableName)
  {
    return PopLuaString(m_pLuaState, VariableName);
  }

  bool GetBool(char* VariableName)
  {
    return PopLuaBool(m_pLuaState, VariableName);
  }

  inline std::string LuaPopStringFieldFromArray(lua_State* L, const int key)
{

  //push the key onto the stack
  lua_pushnumber(L, key);

  //table is now at -2 (key is at -1). lua_gettable now pops the key off
  //the stack and then puts the data found at the key location on the stack
  lua_gettable(L, -2);

  //check that the variable is the correct type. If it is not throw an
  //exception
  if (!lua_isstring(L, -1))
  {
    std::string err("<LuaPopStringFieldFromTable> Cannot retrieve: ");

    throw std::runtime_error(err + ttos(key));
  }

  //grab the data
  std::string s = lua_tostring(L, -1);

  lua_pop(L, 1);

  return s;
}


  std::string GetStringFromArray(char* ArrayName, int key)
  {
	lua_settop(m_pLuaState, 0);
	lua_getglobal(m_pLuaState, ArrayName);
	if (!lua_istable(m_pLuaState, 1))
	{
		return "";
	} else
	{
		return LuaPopStringFieldFromArray(m_pLuaState, key);
	}
  }

  std::string GetStringFromTable(char* ArrayName, char* key)
  {
	lua_settop(m_pLuaState, 0);
	lua_getglobal(m_pLuaState, ArrayName);
	if (!lua_istable(m_pLuaState, 1))
	{
		return "";
	} else
	{
		return LuaPopStringFieldFromTable(m_pLuaState, key);
	}
  }
};

#endif

 
  

