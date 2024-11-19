//========= Copyleft iSquad Software, Some rights reserved.============//
//
// 
//
//=======================================================================//

#include "cbase.h"
#include "proto_version.h"
#include "filesystem.h"

const char * GetArch()
{
#if defined( __x86_64__) || defined( _M_X64 )
	return "amd64";
#elif defined(__i386__) || defined(_X86_) || defined(_M_IX86)
	return "i386";
#elif defined __aarch64__
        return "aarch64";
#elif defined __arm__ || defined _M_ARM
        return "arm";
#elif defined __e2k__ || defined e2k
	return "e2k ( Elbrus )";
#else
	return "Unknown";
#endif
}

const char * GetProtoVersion()
{

#if defined CSTRIKE15 || defined SWARM_DLL
	return "Source Engine (Left 4 Dead Branch)"
#else
	if ( PROTOCOL_VERSION == 25 )
	{
		return "Source Engine 25 / 1.17 (nillerusr's fork)";
	}
	else if ( PROTOCOL_VERSION == 24 )
	{
		return "Source Engine 24 / Steam Original Engine";
	}
#endif
}

const char * GetPlatform()
{
#ifdef LINUX	
	return "Linux";
#elif ANDROID 
	return "Android";
#elif PLATFORM_FBSD
	return "FreeBSD";
#elif PLATFORM_BSD
	return "*BSD";
#elif WIN32
	return "Windows";
#elif OSX
	return "OSX";
#elif PLATFORM_HAIKU
	return "Haiku";
#else
	return "Unknown Platform (You on AmigaOS?)"
#endif
}

const char * GetGame()
{
	const char * var;
	KeyValues *kv = new KeyValues("KeyValues");
	kv->LoadFromFile( g_pFullFileSystem, "gameinfo.txt" );
	
	if ( kv )	
	{
		for ( KeyValues *control = kv->GetFirstSubKey(); control != NULL; control = control->GetNextKey() )
		{		
			if ( !Q_strcasecmp( control->GetName(), "game" ) )
			{

				var = control->GetString();
			}
		}
	}
	return var;
}

CON_COMMAND_F( sourcefetch, "Print info about engine", FCVAR_NONE )
{
	//Use a monospaced fonts for this ASCII art!!!!!
	Msg("@@@@@@&#BBGGGGGGGGGGGGGGGGGGGGGGGGG#&@@@\n"
		"@&BPY?77!!!!!!!!!!!!!!!!!!!!!!!!!!!7?5#@\n"
		"Y7!!!7?JY55555YJ?77!!!77777777777777!!7G\n"
		"GJJ5B&@@@@@@@@@@@&#PY7!!77777777777777!?\n"
		"@@@@@@@@&&&&&&&@@@@@@&GJ!!777777777777!Y\n"
		"@@@@#GP555555555PG#@@@@@B?!7777777777!J&\n"
		"@@&PYYY555PPPP5YYYY5#@@@@@5!77777777!?&@\n"
		"@@PY5555B@@@@@&P55555#@@@@@5!777777!7#@@\n"
		"@@PY5555PB&&@@@@&&&&&&@@@@@@J!7777!7B@@@\n"
		"@@&P5YY5YY555PPGB#&@@@@@@@@@G!7777!P@@@@\n"
		"@@@@#BGP555YYYYYYY55G&@@@@@@#7777!5@@@@@\n"
		"@@@@@@@@@&&#BBP55555YP@@@@@@B!77!Y@@@@@@\n"
		"@#PPPPPB@@@@@@@&555555&@@@@@Y!7!J@@@@@@@\n"
		"@@PYYYY5G#&&&&#G5555YG@@@@@B77!?&@@@@@@@\n"
		"@@@B55YYYY5555YYYY5PB@@@@@B7!!7#@@@@@@@@\n"
		"@@@@@#BGPPPPPPPPGB#@@@@@&57!!?#@@@@@@@@@\n"
		"@@@@@@@@@@@@@@@@@@@@@@&P?!!!Y&@@@@@@@@@@\n"
		"@@@@@@@@@@@@@@@@@@@@@@P!!7JB@@@@@@@@@@@@\n"
		"@@@@@@@@@@@@@@@@@@@@@@@BGB@@@@@@@@@@@@@@\n");
	Msg("Source Engine\n");
	Msg("----------\n");
	Msg("Engine Version: %s\n", GetProtoVersion() );
	Msg("Platform: %s\n", GetPlatform());
	Msg("Arch: %s\n", GetArch());
	Msg("Game: %s\n", GetGame());
}
