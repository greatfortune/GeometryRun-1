/**
 * Project:		GameStateManager
 * File Name:	Level2.c
 * Author:		����
 * Date:		2017-4-22
 * Purpose:		�ؿ�2
 */
/* Project:		GProj_Asteroid
File Name:	Level1.c
Author:		���������
Date:
Purpose:		�ؿ�1  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level2.h"
#include "AEEngine.h"
#include "Input.h"
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "TimeManager.h"
#include "CreateObjectInMap.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

clock_t time_start_level2;

void Load2(void)
{
	// ��ʼ��ʱ��ϵͳ
	TimerIni(&time_start_level2);
	printf("Level2: Load\n");
	theBaseList = NULL;
	// ���ó���
	SetConstants();
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);

	// ���������ʵ��	

	// =======================
	// ƽ̨
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -0.05f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -0.05f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 0.05f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -0.05f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 0.05f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 0.05f, COLOR_PLAYER, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_PLATFORM, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlatForm.png"), theBaseList);

	// =======================
	// ����
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		3.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		3.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		3.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/level2.png"), theBaseList);

	// =========================
	// ����
	// =========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLAYER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlayer.png"), theBaseList);

	// ========================
	// ����
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/star.png"), theBaseList);

	// ========================
	// �ϰ���
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_BLOCK, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/theBlock2.png"), theBaseList);

	// ========================
	// �ӵ�
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_BULLET, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/bullet.png"), theBaseList);
}

void Ini2(void)
{
	printf("Level2: Ini\n");
	Vector2D iniPosition_Player = { -250.0f, 40.0f };
	Vector2D iniVelocity_Background = { -3.0f, 0.0f };
	Vector2D iniVelocity_Platform = { -3.0f, 0.0f };
	Vector2D iniPosition_Block = { 10.0f, 10.0f };
	Vector2D iniVelocity_Block = { -1.0f, -1.0f };
	float iniFloat = 1.0f;
	float iniMinX = 0.0f, iniMaxX = 100.0f, iniMinY = 70.0f, iniMaxY = 500.0f, iniMinVx = -1.0f, iniMaxVx = 1.0f;
	float iniMinVy = -1.0f, iniMaxVy = 1.0f, iniMinDir = -3.0f, iniMaxDir = 3.0f;

	// ���õ�ǰ�ϰ���Ĭ���ٶ�
	defaultBlockVel.x = -5.0f;
	defaultBlockVel.y = 0.0f;

	// ��ȡ��ǰ�ؿ�ʱ��
	time_start_level2 = clock();

	//��ֵ��ʼ��
	SetIniValue();

	// ����ʵ������
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, zero, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, zero, iniVelocity_Platform, 0, theBaseList, 0, NULL);
	// �ֱ�����3sʱ�̶�����һ��block����5sʱ�������5��block�������Ƿ�Χ��ı�ɾ�ˣ�
	//CreateOneObjAtTime(3.0f, OTYPE_BLOCK, SIZE_BLOCK, iniPosition_Block, iniVelocity_Block, iniFloat, theBaseList, 0, NULL);
	
	CreateObjInMap4(1.0f);
	CreateObjInMap3(2.0f);
	CreateObjInMap2(3.0f);
	CreateObjInMap5(6.0f);
	CreateObjInMap0(9.0f);
	CreateObjInMap1(19.0f);
}

void Update2(void)
{
	double frameTime;
	Vector2D iniPosition_Block;
	Vector2D iniVelocity_Block;

	GetWinMaxMinXY();

	TimerUpdate(time_start_level2);
	
	// =========================
	// ��Ϸ�߼���Ӧ����
	// =========================
	KeyUpdate();

	// ======================
	// ֡ʱ�䣺Unity�е�dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	// ======================
	// ֡ʱ�䣺Unity�е�dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	// ����Hero��Ķ���λ��
	BaseListTraverse(theBaseList, Visit_PositionUpdate);
	// ����Hero��λ��
	pHero->posCurr.x += frameTime * pHero->velCurr.x;
	pHero->posCurr.y += frameTime * pHero->velCurr.y;
	// Player����������ЧӦ
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// ====================
	// ��ײ���
	// ====================
	BaseListTraverse(theBaseList, Visit_CollisionDetect);

	// =====================================
	// �������ж����2D�任����
	// =====================================
	BaseListTraverse(theBaseList, Visit_Matrix2DCount);
}

void Draw2(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// ������ƶ����б��е����ж���
	BaseListTraverse(theBaseList, Visit_DrawObj);

}

void Free2(void)
{
	
	printf("Level2: free\n");
	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	
	BaseListTraverse(theBaseList, Visit_DestroyObj);

	TimerFree();
}

void Unload2(void)
{
	printf("Level2: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}