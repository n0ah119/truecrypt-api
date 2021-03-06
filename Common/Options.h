/* Legal Notice: Portions of the source code contained in this file were 
derived from the source code of TrueCrypt 7.1a which is Copyright (c) 2003-2013 
TrueCrypt Developers Association and is governed by the TrueCrypt License 3.0. 
Modifications and additions to the original source code (contained in this file) 
and all other portions of this file are Copyright (c) 2013 Nic Nilov and are 
governed by license terms which are TBD. */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "Wipe.h"

//TODO: refactor to enum
#define TC_OPTION_BASE					0x800
#define TC_OPTION_CACHE_PASSWORDS		TC_OPTION_BASE + 1
#define TC_OPTION_MOUNT_READONLY		TC_OPTION_BASE + 2
#define TC_OPTION_MOUNT_REMOVABLE		TC_OPTION_BASE + 3
#define TC_OPTION_PRESERVE_TIMESTAMPS	TC_OPTION_BASE + 4
#define TC_OPTION_HIDDEN_SECTOR_STATUS	TC_OPTION_BASE + 5
#define TC_OPTION_ENABLE_KEYFILES		TC_OPTION_BASE + 6
#define TC_OPTION_MOUNT_CLOSE_SESSIONS	TC_OPTION_BASE + 7
#define TC_OPTION_TOKEN_LIBRARY			TC_OPTION_BASE + 8
#define TC_OPTION_DRIVER_PATH			TC_OPTION_BASE + 9
#define TC_OPTION_WIPE_CACHE_ON_EXIT	TC_OPTION_BASE + 10

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		DWORD OptionId;
		DWORD OptionValue;
	} TCAPI_OPTION, *PTCAPI_OPTION;

#pragma warning(push)
#pragma warning(disable:4200)

	typedef struct {
		DWORD NumberOfOptions;
		TCAPI_OPTION Options[];
	} TCAPI_OPTIONS, *PTCAPI_OPTIONS;

#pragma warning(pop)

	extern BOOL bPreserveTimestamp;
	extern BOOL bCacheInDriver;
	extern BOOL bMountReadOnly;
	extern BOOL bMountRemovable;
	extern BOOL bWipeCacheOnExit;

	extern char *lpszDriverPath;

	/* This value may changed only by calling ChangeSystemEncryptionStatus(). Only the wizard can change it
	(others may still read it though). */
	extern int SystemEncryptionStatus;

	/* Only the wizard can change this value (others may only read it). */
	extern WipeAlgorithmId nWipeMode;

	extern BOOL bPortableModeConfirmed;
	extern BOOL bInPlaceEncNonSysPending;

	static BOOL LoadStoredSettings();
	BOOL ApplyOptions(PTCAPI_OPTIONS options);
	BOOL TryDetectSystemEncryptionStatus (void);
	int TryDetectNonSysInPlaceEncSettings (WipeAlgorithmId *wipeAlgorithm);
	uint32 ReadEncryptionThreadPoolFreeCpuCountLimit ();
	BOOL IsNonInstallMode();
	char *GetConfigPath (char *fileName);

#ifdef __cplusplus
}
#endif

#endif

