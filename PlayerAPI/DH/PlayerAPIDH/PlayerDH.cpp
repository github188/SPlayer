#include "stdafx.h"
#include "PlayerDH.h"

#include <stdio.h>

#include "../inc/dhPlay.h"
#pragma comment(lib,"../lib/dhPlay.lib")

char* CPlayerFactoryDH::Name()
{
	return "��";
}

BOOL CPlayerFactoryDH::IsBelongThis(char *pFile)
{
	FILE *pfd = NULL;
	int ret = fopen_s(&pfd, pFile, "rb");
	if (pfd)//���ļ��ɹ�
	{
		char buf[8];
		memset(buf, 0, 8);
		fread(buf, 8, 1, pfd);

		if (strncmp(buf, "DHAV", 4) == 0)
		{
			return true;
		}
		fclose(pfd);
	}


	return false;
}

BOOL CPlayerFactoryDH::Init()
{
	return true;
}

void CPlayerFactoryDH::Release()
{

}

IPlayer *CPlayerFactoryDH::CreatePlayer()
{
	return new CPlayerDH();
}
/////////////

CPlayerDH::CPlayerDH()
{
}


CPlayerDH::~CPlayerDH()
{
}



BOOL CPlayerDH::OpenFile(char *PFile, HWND hwnd)
{
	m_hwnd = hwnd;
	if (PLAY_GetFreePort(&m_nPort))
	{
		return PLAY_OpenFile(m_nPort, PFile);
	}
	return false;
}

BOOL CPlayerDH::Play()
{
	return PLAY_Play(m_nPort, m_hwnd);	
}

BOOL CPlayerDH::Pause(DWORD nPause)
{
	return PLAY_Pause(m_nPort, nPause);
}

BOOL CPlayerDH::Stop()
{
	PLAY_Stop(m_nPort);
	PLAY_CloseFile(m_nPort);
	return PLAY_ReleasePort(m_nPort);
}


BOOL CPlayerDH::Fast()
{
	return PLAY_Fast(m_nPort);
}

BOOL CPlayerDH::Slow()
{
	return PLAY_Slow(m_nPort);
}

BOOL CPlayerDH::OneByOne()
{
	return PLAY_OneByOne(m_nPort);
}

BOOL CPlayerDH::OneByOneBack()
{
	return PLAY_OneByOneBack(m_nPort);
}

BOOL CPlayerDH::PlaySoundShare()
{
	return PLAY_PlaySoundShare(m_nPort);

}

BOOL  CPlayerDH::StopSoundShare()
{
	return PLAY_StopSoundShare(m_nPort);
}

BOOL CPlayerDH::SetVolume(WORD nVolume)
{
	return PLAY_SetVolume(m_nPort, nVolume);
}

DWORD CPlayerDH::GetVolume()
{
	return PLAY_GetVolume(m_nPort);
}

BOOL  CPlayerDH::SetPlayPos(float fRelativePos)
{
	return PLAY_SetPlayPos(m_nPort, fRelativePos);
}

float CPlayerDH::GetPlayPos()
{
	return PLAY_GetPlayPos(m_nPort);
}

DWORD CPlayerDH::GetFileTime()
{
	return PLAY_GetFileTime(m_nPort);
}

DWORD CPlayerDH::GetPlayedTime()
{
	return PLAY_GetPlayedTime(m_nPort);
}

BOOL  CPlayerDH::GetPictureSize(LONG *pWidth, LONG *pHeight)
{
	return PLAY_GetPictureSize(m_nPort, pWidth, pHeight);
}

typedef void (CALLBACK *pFileEnd)(DWORD nPort, DWORD nUser);

BOOL  CPlayerDH::SetFileEndCallback(long nID, FileEndCallback callBack, void *pUser)
{
	return PLAY_SetFileEndCallBack(m_nPort, (pFileEnd)callBack, (DWORD)pUser);
}

BOOL  CPlayerDH::CapturePic(char *pSaveFile, int iType)
{
	int width, height;
	PLAY_GetPictureSize(m_nPort, (long*)&width, (long*)&height);
	if (iType == 0)
	{
		return PLAY_CatchResizePic(m_nPort, pSaveFile, width, height, PicFormat_BMP);
	}
	else if (iType == 1)
	{
		return PLAY_CatchResizePic(m_nPort, pSaveFile, width, height, PicFormat_JPEG);
	}
}

BOOL CPlayerDH::FileCutStart(const char* srcFileName, const char* destFileName, unsigned __int64 startTime, unsigned __int64 endTime, BOOL bFast)
{
	return false;
}

BOOL CPlayerDH::FileCutClose()
{
	return false;
}

int CPlayerDH::FileCutProcess()
{
	return 0;
}

BOOL CPlayerDH::FileConvertStart(const char* srcFileName, const char* destFileName, unsigned __int64 startTime, unsigned __int64 endTime, bool bConvert, T_ConverterParameters *pConvertPara)
{
	//PLAY_StartAVIResizeConvert//ֻ����ý������
	/*
	if (PLAY_GetFreePort(&m_nPort))
	{
		return PLAY_StartAVIConvert(m_nPort,  destFileName, startTime, endTime, width, height);)
	}
	*/
	return false;
}

BOOL CPlayerDH::FileConvertClose()
{
	return PLAY_StopAVIConvert(m_nPort);	
}

int CPlayerDH::FileConvertProcess()
{
	return 0;
}

BOOL  CPlayerDH::FileConvertPause(DWORD nPause)
{
	return false;
}