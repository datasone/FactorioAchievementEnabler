#pragma once

#include "Common.h"
#include "_EXP_Control.h"
#include "PatchUtil.h"
#include "DoPatch.h"

#define dll_export extern "C" __declspec(dllexport) void __cdecl
#define var_export extern "C" __declspec(dllexport)

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);

void initLibrary();
void exitLibrary();

HINSTANCE hInstance;
HMODULE hDll;

void fixAPI(LPCSTR lpProcName, uAddr a);

namespace API_EXPORT
{
#ifdef __EXP_VERSION
	dll_export GetFileVersionInfoA(void);
	dll_export GetFileVersionInfoByHandle(void);
	dll_export GetFileVersionInfoExW(void);
	dll_export GetFileVersionInfoSizeA(void);
	dll_export GetFileVersionInfoSizeExW(void);
	dll_export GetFileVersionInfoSizeW(void);
	dll_export GetFileVersionInfoW(void);
	dll_export VerFindFileA(void);
	dll_export VerFindFileW(void);
	dll_export VerInstallFileA(void);
	dll_export VerInstallFileW(void);
	dll_export VerLanguageNameA(void);
	dll_export VerLanguageNameW(void);
	dll_export VerQueryValueA(void);
	dll_export VerQueryValueW(void);
	dll_export VerQueryValueIndexA(void);
	dll_export VerQueryValueIndexW(void);
#endif

#ifdef __EXP_LPK
	dll_export LpkDllInitialize(void);
	dll_export LpkDrawTextEx(void);
	var_export VOID(*LpkEditControl[14])();
	dll_export LpkExtTextOut(void);
	dll_export LpkGetCharacterPlacement(void);
	dll_export LpkGetTextExtentExPoint(void);
	dll_export LpkInitialize(void);
	dll_export LpkPSMTextOut(void);
	dll_export LpkTabbedTextOut(void);
	dll_export LpkUseGDIWidthCache(void);
	dll_export ftsWordBreak(void);
#endif

#ifdef __EXP_MSIMG32
	dll_export AlphaBlend(void);
	dll_export DllInitialize(void);
	dll_export GradientFill(void);
	dll_export TransparentBlt(void);
	dll_export vSetDdrawflag(void);
#endif

#ifdef __EXP_WINMM
	#ifdef PlaySound
		#ifndef __BAK__PlaySound
			#define __BAK__PlaySound PlaySound
		#endif
		#undef PlaySound
	#endif
	dll_export mciExecute(void);
	dll_export CloseDriver(void);
	dll_export DefDriverProc(void);
	dll_export DriverCallback(void);
	dll_export DrvGetModuleHandle(void);
	dll_export GetDriverModuleHandle(void);
	dll_export OpenDriver(void);
	dll_export PlaySound(void);
	dll_export PlaySoundA(void);
	dll_export PlaySoundW(void);
	dll_export SendDriverMessage(void);
	dll_export WOWAppExit(void);
	dll_export auxGetDevCapsA(void);
	dll_export auxGetDevCapsW(void);
	dll_export auxGetNumDevs(void);
	dll_export auxGetVolume(void);
	dll_export auxOutMessage(void);
	dll_export auxSetVolume(void);
	dll_export joyConfigChanged(void);
	dll_export joyGetDevCapsA(void);
	dll_export joyGetDevCapsW(void);
	dll_export joyGetNumDevs(void);
	dll_export joyGetPos(void);
	dll_export joyGetPosEx(void);
	dll_export joyGetThreshold(void);
	dll_export joyReleaseCapture(void);
	dll_export joySetCapture(void);
	dll_export joySetThreshold(void);
	dll_export mciDriverNotify(void);
	dll_export mciDriverYield(void);
	dll_export mciFreeCommandResource(void);
	dll_export mciGetCreatorTask(void);
	dll_export mciGetDeviceIDA(void);
	dll_export mciGetDeviceIDFromElementIDA(void);
	dll_export mciGetDeviceIDFromElementIDW(void);
	dll_export mciGetDeviceIDW(void);
	dll_export mciGetDriverData(void);
	dll_export mciGetErrorStringA(void);
	dll_export mciGetErrorStringW(void);
	dll_export mciGetYieldProc(void);
	dll_export mciLoadCommandResource(void);
	dll_export mciSendCommandA(void);
	dll_export mciSendCommandW(void);
	dll_export mciSendStringA(void);
	dll_export mciSendStringW(void);
	dll_export mciSetDriverData(void);
	dll_export mciSetYieldProc(void);
	dll_export midiConnect(void);
	dll_export midiDisconnect(void);
	dll_export midiInAddBuffer(void);
	dll_export midiInClose(void);
	dll_export midiInGetDevCapsA(void);
	dll_export midiInGetDevCapsW(void);
	dll_export midiInGetErrorTextA(void);
	dll_export midiInGetErrorTextW(void);
	dll_export midiInGetID(void);
	dll_export midiInGetNumDevs(void);
	dll_export midiInMessage(void);
	dll_export midiInOpen(void);
	dll_export midiInPrepareHeader(void);
	dll_export midiInReset(void);
	dll_export midiInStart(void);
	dll_export midiInStop(void);
	dll_export midiInUnprepareHeader(void);
	dll_export midiOutCacheDrumPatches(void);
	dll_export midiOutCachePatches(void);
	dll_export midiOutClose(void);
	dll_export midiOutGetDevCapsA(void);
	dll_export midiOutGetDevCapsW(void);
	dll_export midiOutGetErrorTextA(void);
	dll_export midiOutGetErrorTextW(void);
	dll_export midiOutGetID(void);
	dll_export midiOutGetNumDevs(void);
	dll_export midiOutGetVolume(void);
	dll_export midiOutLongMsg(void);
	dll_export midiOutMessage(void);
	dll_export midiOutOpen(void);
	dll_export midiOutPrepareHeader(void);
	dll_export midiOutReset(void);
	dll_export midiOutSetVolume(void);
	dll_export midiOutShortMsg(void);
	dll_export midiOutUnprepareHeader(void);
	dll_export midiStreamClose(void);
	dll_export midiStreamOpen(void);
	dll_export midiStreamOut(void);
	dll_export midiStreamPause(void);
	dll_export midiStreamPosition(void);
	dll_export midiStreamProperty(void);
	dll_export midiStreamRestart(void);
	dll_export midiStreamStop(void);
	dll_export mixerClose(void);
	dll_export mixerGetControlDetailsA(void);
	dll_export mixerGetControlDetailsW(void);
	dll_export mixerGetDevCapsA(void);
	dll_export mixerGetDevCapsW(void);
	dll_export mixerGetID(void);
	dll_export mixerGetLineControlsA(void);
	dll_export mixerGetLineControlsW(void);
	dll_export mixerGetLineInfoA(void);
	dll_export mixerGetLineInfoW(void);
	dll_export mixerGetNumDevs(void);
	dll_export mixerMessage(void);
	dll_export mixerOpen(void);
	dll_export mixerSetControlDetails(void);
	dll_export mmDrvInstall(void);
	dll_export mmGetCurrentTask(void);
	dll_export mmTaskBlock(void);
	dll_export mmTaskCreate(void);
	dll_export mmTaskSignal(void);
	dll_export mmTaskYield(void);
	dll_export mmioAdvance(void);
	dll_export mmioAscend(void);
	dll_export mmioClose(void);
	dll_export mmioCreateChunk(void);
	dll_export mmioDescend(void);
	dll_export mmioFlush(void);
	dll_export mmioGetInfo(void);
	dll_export mmioInstallIOProcA(void);
	dll_export mmioInstallIOProcW(void);
	dll_export mmioOpenA(void);
	dll_export mmioOpenW(void);
	dll_export mmioRead(void);
	dll_export mmioRenameA(void);
	dll_export mmioRenameW(void);
	dll_export mmioSeek(void);
	dll_export mmioSendMessage(void);
	dll_export mmioSetBuffer(void);
	dll_export mmioSetInfo(void);
	dll_export mmioStringToFOURCCA(void);
	dll_export mmioStringToFOURCCW(void);
	dll_export mmioWrite(void);
	dll_export mmsystemGetVersion(void);
	dll_export sndPlaySoundA(void);
	dll_export sndPlaySoundW(void);
	dll_export timeBeginPeriod(void);
	dll_export timeEndPeriod(void);
	dll_export timeGetDevCaps(void);
	dll_export timeGetSystemTime(void);
	dll_export timeGetTime(void);
	dll_export timeKillEvent(void);
	dll_export timeSetEvent(void);
	dll_export waveInAddBuffer(void);
	dll_export waveInClose(void);
	dll_export waveInGetDevCapsA(void);
	dll_export waveInGetDevCapsW(void);
	dll_export waveInGetErrorTextA(void);
	dll_export waveInGetErrorTextW(void);
	dll_export waveInGetID(void);
	dll_export waveInGetNumDevs(void);
	dll_export waveInGetPosition(void);
	dll_export waveInMessage(void);
	dll_export waveInOpen(void);
	dll_export waveInPrepareHeader(void);
	dll_export waveInReset(void);
	dll_export waveInStart(void);
	dll_export waveInStop(void);
	dll_export waveInUnprepareHeader(void);
	dll_export waveOutBreakLoop(void);
	dll_export waveOutClose(void);
	dll_export waveOutGetDevCapsA(void);
	dll_export waveOutGetDevCapsW(void);
	dll_export waveOutGetErrorTextA(void);
	dll_export waveOutGetErrorTextW(void);
	dll_export waveOutGetID(void);
	dll_export waveOutGetNumDevs(void);
	dll_export waveOutGetPitch(void);
	dll_export waveOutGetPlaybackRate(void);
	dll_export waveOutGetPosition(void);
	dll_export waveOutGetVolume(void);
	dll_export waveOutMessage(void);
	dll_export waveOutOpen(void);
	dll_export waveOutPause(void);
	dll_export waveOutPrepareHeader(void);
	dll_export waveOutReset(void);
	dll_export waveOutRestart(void);
	dll_export waveOutSetPitch(void);
	dll_export waveOutSetPlaybackRate(void);
	dll_export waveOutSetVolume(void);
	dll_export waveOutUnprepareHeader(void);
	dll_export waveOutWrite(void);
	#ifdef __BAK__PlaySound
		#define PlaySound __BAK__PlaySound
		#undef __BAK__PlaySound
	#endif
#endif
}