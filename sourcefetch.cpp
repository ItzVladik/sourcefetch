//========= Copyleft iSquad Software, Some rights reserved.============//
//
// 
//
//=======================================================================//

#include "cbase.h"
#include "proto_version.h"
#include "filesystem.h"
#include "tier0/platform.h"

Color clr;

#ifdef ANDROID
#define OpenGL "OpenGL ES"
#else
#define OpenGL "OpenGL"
#endif

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
#elif defined __e2k__ || defined E2K
	return "e2k ( Elbrus )";
#else
	return "Unknown";
#endif
}

const char * GetProtoVersion()
{

#if defined CSTRIKE15 || defined SWARM_DLL
	return "Source Engine (Left 4 Dead Branch)";
#else
	if ( PROTOCOL_VERSION == 25 )
	{
		return "Source Engine 25 / 1.17 (nillerusr's fork)";
	}
	else if ( PROTOCOL_VERSION == 24 )
	{
		return "Source Engine 24 / 2013";
	}
	else if ( PROTOCOL_VERSION == 14 )
	{
		return "Source Engine 12 / 2007";
	}
	else if ( PROTOCOL_VERSION == 2 )
	{
		return "Source Engine 2 / 2003";
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

const char * GetArt( const char * game )
{
	if ( FStrEq( game, "HALF-LIFE" ) )
	{
		// eto pzdc
		clr = { 255, 128, 0, 255 };
		return  	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
				"@@@@@@@@@@@@@&#BGPP55PPGB#&@@@@@@@@@@@@@\n"
				"@@@@@@@@@&BPY?????????????JYP#@@@@@@@@@@\n"
				"@@@@@@@&PJ???Y5G##&&&##BP5J???YG@@@@@@@@\n"
				"@@@@@@P???JG&@@####&@@@@@@&B5???JB@@@@@@\n"
				"@@@@&Y??JG@@@@&YJJ?J&@@@@@@@@&5???P@@@@@\n"
				"@@@&J??J&@@@@@@@@&Y?Y@@@@@@@@@@G???5@@@@\n"
				"@@@5???&@@@@@@@@@@5??5@@@@@@@@@@P???B@@@\n"
				"@@&J??P@@@@@@@@@&Y????P@@@@@@@@@&???5@@@\n"
				"@@&???G@@@@@@@@BJ??G5??B@@@@@@@@@J??Y@@@\n"
				"@@&J??5@@@@@@@G??J#@@Y??#@@@@@@@&???5@@@\n"
				"@@@P???#@@@@@5??5&@@@&J?J##B@@@@5???#@@@\n"
				"@@@@Y??J#@@#Y??G@@@@@@B????J#@@P???P@@@@\n"
				"@@@@&5???P&&##&@@@@@@@@BG#&@@#Y???G@@@@@\n"
				"@@@@@@GJ??JP#@@@@@@@@@@@@@&GY???Y#@@@@@@\n"
				"@@@@@@@&GY???JYPGBB##BBP5J????5B@@@@@@@@\n"
				"@@@@@@@@@@#G5J????????????YPB&@@@@@@@@@@\n"
				"@@@@@@@@@@@@@@&#BGGGGGBB#&@@@@@@@@@@@@@@\n"
				"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	}
	else if ( FStrEq( game, "HALF-LIFE 2") )
	{
		clr = {  255, 128, 0, 255  };
		return  "@@@@@@@@@@@&#BGGPPPPPPPPPPPPPPP5PPPB#@@@\n"
				"@@@@@@@&BPYJJJJJYYYJJJ??JJJJJ222222JJ5#@\n"
				"@@@@@#PJ?J5G#&@@@@@&&#BPYJJJJJJ2222JJJY@\n"
				"@@@&PJ?YB&@@&GGGGB@@@@@@@#PJJ222&BJJJJP@\n"
				"@@#Y?JB@@@@@&YYJJJB@@@@@@@@#222#BGGJJ5@@\n"
				"@&JJJ#@@@@@@@@@#JJJ#@@@@@@@@@5JJJJJJ5@@@\n"
				"@PJJB@@@@@@@@@&5JJJY&@@@@@@@@&JJJJJY&@@@\n"
				"@YJJ&@@@@@@@@#YJJJJJ5@@@@@@@@@5JJJY&@@@@\n"
				"@YJJ&@@@@@@@GJJJG&5JJP@@@@@@@@5JJJ#@@@@@\n"
				"@PJJG@@@@@&5JJY#@@&YJJG&#&@@@&JJJ#@@@@@@\n"
				"@&YJJB@@@#Y?J5&@@@@&JJJJJY&@&YJJB@@@@@@@\n"
				"@@&Y?JG@@#BB#@@@@@@@BPGB#&@#Y?JB@@@@@@@@\n"
				"@@@&PJ?YG&@@@@@@@@@@@@@@@B5JJ5#@@@@@@@@@\n"
				"@@@@@&GYJJYPB#&&&&&&#BG5J?J5B@@@@@@@@@@@\n"
				"@@@@@@@@#G5JJJJJJJJJJJJYPB&@@@@@@@@@@@@@\n"
				"@@@@@@@@@@@@&#BBGGGBB#&@@@@@@@@@@@@@@@@@\n";
	}
	else if ( FStrEq( game, "Half-Life 2 DM") )
	{
		clr = { 255, 128, 0, 255 };
		// later i try to make ascii art for hl2dm
		return 	 	"@@@@@@@@@@@&#BGGPPPPPPPPPPPPPPP5PPPB#@@@\n"
				"@@@@@@@&BPYJJJJJYYYJJJ??JJJJJ222222JJ5#@\n"
				"@@@@@#PJ?J5G#&@@@@@&&#BPYJJJJJJ2222JJJY@\n"
				"@@@&PJ?YB&@@&GGGGB@@@@@@@#PJJ222&BJJJJP@\n"
				"@@#Y?JB@@@@@&YYJJJB@@@@@@@@#222#BGGJJ5@@\n"
				"@&JJJ#@@@@@@@@@#JJJ#@@@@@@@@@5JJJJJJ5@@@\n"
				"@PJJB@@@@@@@@@&5JJJY&@@@@@@@@&JJJJJY&@@@\n"
				"@YJJ&@@@@@@@@#YJJJJJ5@@@@@@@@@5JJJY&@@@@\n"
				"@YJJ&@@@@@@@GJJJG&5JJP@@@@@@@@5JJJ#@@@@@\n"
				"@PJJG@@@@@&5JJY#@@&YJJG&#&@@@&JJJ#@@@@@@\n"
				"@&YJJB@@@#Y?J5&@@@@&JJJJJY&@&YJJB@@@@@@@\n"
				"@@&Y?JG@@#BB#@@@@@@@BPGB#&@#Y?JB@@@@@@@@\n"
				"@@@&PJ?YG&@@@@@@@@@@@@@@@B5JJ5#@@@@@@@@@\n"
				"@@@@@&GYJJYPB#&&&&&&#BG5J?J5B@@@@@@@@@@@\n"
				"@@@@@@@@#G5JJJJJJJJJJJJYPB&@@@@@@@@@@@@@\n"
				"@@@@@@@@@@@@&#BBGGGBB#&@@@@@@@@@@@@@@@@@\n";
	}
	else if (FStrEq( game, "Counter-Strike Source" ))
	{
		clr = { 0, 0, 0, 255 };
		return  	"@@@@@@@@@@@@@&BG5YJJ?JY5GB&@@@@@@@@@@@@@\n"
				"@@@@@@@@@&GJ!^. .JPPY^   .^!JG#@@@@@@@@@\n"
				"@@@@@@&G?:      ?&##&P ::     :7G&@@@@@@\n"
				"@@@@@G!       ^5#####P5B#GPPG55?J!P@@@@@\n"
				"@@@#?        ~#&#####55G#&&#GY^::  ?#@@@\n"
				"@@#!         Y&#######&#G??7Y.      ~#@@\n"
				"@#!         .G#####&J!~^.   ~^       !#@\n"
				"&5          7&#####5.                 5&\n"
				"&7          ?&#####P!                 !&\n"
				"#!          7####&###P~               ~#\n"
				"&?         :B###5JB&#&G               7&\n"
				"&P         5&##5  :Y###5:             P&\n"
				"@&7       ~###B.    ~P#&G:           !#@\n"
				"@@#!    ^YB###!      :##&7          ~#@@\n"
				"@@@#?  ?#&###!        J##5         ?#@@@\n"
				"@@@@@G~?#&5::         :#&G:     .!G&@@@@\n"
				"@@@@@@&PY?:            JG#G.  ^?G&@@@@@@\n"
				"@@@@@@@@@#PJ!^:.        .!?7JG&@@@@@@@@@\n"
				"@@@@@@@@@@@@@&#GP5YJJY5PGB#@@@@@@@@@@@@@\n";
	}
	else if ( FStrEq( game, "Portal" ) )
	{
		clr = { 53, 187, 255, 255 };
		return  	"@@@@@@@@@@@@@@@@@@&BPYJ????JJ5G#@@@@@@@@\n"
				"@@@@@@@@@@@@@@@&G5J????????????JYB&@@@@@\n"
				"@@@@@@@@@@@@@#PJ???JY5PGGGPYJ?????Y#@@@@\n"
				"@@@@@@@@@###PJ???YG#&@@@@@@@#P?????JG@@@\n"
				"@@@@@@@&GGGJ???YB&@@@@@@@@@@@@BJ?????G@@\n"
				"@@@@@@&PP5???JG&@@@@@@@@@@@@@@@BJ????J#@\n"
				"@@@@@&55Y???Y#@@@@@@@@@@@@@@@@@@P?J???5&\n"
				"@@@@&5JJ???5&@@@@@@@@@@@@@@@@@@@#JPJ???B\n"
				"@@@&5?????P&@@@@@@@@@@@@@@@@@@@@@YP5???5\n"
				"@@@G?????5&@@@@@@@@@@@@@@@@@@@@@@5GG???J\n"
				"@@BJ????Y&@@@@@@@@@@@@@@@@@@@@@@@5BB????\n"
				"@&Y????J#@@@@@@@@@@@@@@@@@@@@@@@@5&B????\n"
				"@G?????P@@@@@@@@@@@@@@@@@@@@@@@@&G@G????\n"
				"&Y????J&@@@@@@@@@@@@@@@@@@@@@@@@#&@P???J\n"
				"B?????P@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y???5\n"
				"5????J#@@@@@@@@@@@@@@@@@@@@@@@@@@@#J???B\n"
				"J????Y&@@@@@@@@@@@@@@@@@@@@@@@@@@@P???Y&\n"
				"?????P@@@@@@@@@@@@@@@@@@@@@@@@@@@&J???B@\n"
				"?????G@@@@@@@@@@@@@@@@@@@@@@@@@@@5???5@@\n"
				"?????G@@@@@@@@@@@@@@@@@@@@@@@@@@G???J#@@\n"
				"J????P@@@@@@@@@@@@@@@@@@@@@@@@@BJ??JB@@@\n"
				"5????Y@@#&@@@@@@@@@@@@@@@@@@@@BJ???G@@@@\n"
				"#J???J#@&G&@@@@@@@@@@@@@@@@@&GJ??JG@@@@@\n"
				"@P????P@@B5&@@@@@@@@@@@@@@@#5???JB@@@@@@\n"
				"@&Y????G@@GYB&@@@@@@@@@@&#5J???Y#@@@@@@@\n"
				"@@#Y???JG@@GYYG#&&&&&#BPY????JP&@@@@@@@@\n"
				"@@@&5????5#@&PYJJYYYJJ??????5#@@@@@@@@@@\n"
				"@@@@@BY???J5G#&#GP55YJ???J5#@@@@@@@@@@@@\n"
				"@@@@@@&B5J???JY55P5YJ?JYG#@@@@@@@@@@@@@@\n"
				"@@@@@@@@@#G5YJ????JYPB#@@@@@@@@@@@@@@@@@\n";
	}
	else if ( Q_strncmp( game, "Team Fortress", 14 ) == 0 )
	{
		clr = {  204, 102, 0, 255 };
		return 		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
				"@@@@@@@@@@@@@@&&#BBG&@@@&&@@@@@@@@@@@@@@\n"
				"@@@@@@@@@@&BPYJ????J&@@&JJYPB&@@@@@@@@@@\n"
				"@@@@@@@@#5J????????5@@@B?????J5#@@@@@@@@\n"
				"@@@@@@#5???????????G@@@P????????5#@@@@@@\n"
				"@@@@@GJ????????????#@@@Y?????????JB@@@@@\n"
				"@@@@G?????????????5@@@#?????????JYYB@@@@\n"
				"@@@@GP55YYJJJ??JG#@@@@&GJ?????JYYYYY&@@@\n"
				"@@@@@@@@@@@&&&#&@@@@@@@@&5JJJYYYYYYJG@@@\n"
				"@@@BPGGBB##&&@@@@@@@@@@@@@@&&&###BBGB@@@\n"
				"@@@GJJJJJJJJYY5&@@@@@@@@&&&&@@@@@@@@@@@@\n"
				"@@@&YYYYYYYYYYY5B@@@@@&B5YYY555PPPGG@@@@\n"
				"@@@@BYYYYYYYYYYYY&@@@PYYYYYYYYYYYYYB@@@@\n"
				"@@@@@BYYYYYYYYYY5@@@&YYYYYYYYYYYYYB@@@@@\n"
				"@@@@@@&PYYYYYYYYG@@@BYYYYYYYYYYYP&@@@@@@\n"
				"@@@@@@@@#G5YYYYY#@@@PYYYYYYYY5G#@@@@@@@@\n"
				"@@@@@@@@@@&#GP55&@@&YYYYY5PG#&@@@@@@@@@@\n"
				"@@@@@@@@@@@@@@@&@@@&BB##&@@@@@@@@@@@@@@@\n"
				"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	}
	else
	{
		return  	"@@@@@@&#BBGGGGGGGGGGGGGGGGGGGGGGGGG#&@@@\n"
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
				"@@@@@@@@@@@@@@@@@@@@@@@BGB@@@@@@@@@@@@@@\n";
	}
}

CON_COMMAND_F( sourcefetch, "Print info about engine", FCVAR_NONE )
{
	//Use a monospaced fonts for this ASCII art!!!!!
	ConColorMsg( clr, GetArt( GetGame() ) );
	Msg("Source Engine\n");
	Msg("----------\n");
	Msg("Engine Version: %s\n", GetProtoVersion() );
	Msg("Platform: %s\n", GetPlatform());
	Msg("Arch: %s\n", GetArch());
	Msg("Game: %s\n", GetGame());

	if ( IsPlatformOpenGL() )
		Msg("Renderer: %s\n", OpenGL );
	else
		Msg("Renderer Direct3D\n" );

#ifdef MAPBASE
	Msg("Mapbase: %s\n", MAPBASE_VERSION );
#endif
}
