/**
* Project:		GameStateManager
* File Name:	Level3.c
* Author:		闷声发大财
* Date:		2017-4-22
* Purpose:		关卡3
*/
#include "Level3.h"

clock_t timeStart_level3;
const float bossOccurTime_level3 = 2.0f;

void Load3(void)
{
	// 初始化时间系统
	TimerIni(&timeStart_level3);

	printf("Level3: Load\n");
	theBaseList = NULL;
	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);

	PlayerLoad();
	BlockLoad();
	BulletLoad();
	MonsterLoad();
	PlatformLoad();
	Boss2Load();
	BackGroundLoad();
}

void Ini3(void)
{
	printf("Level3: Ini\n");
	// 获取当前关卡时间
	timeStart_level3 = clock();

	PlayerStart();
	BlockStart();
	PlatformStart();
	BackGroundStart();
	MonsterStart();
	BulletStart();
	Boss2Start();

	// 对象实例化：
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, iniPosition_Background, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, iniPosition_Platform, iniVelocity_Platform, 0, theBaseList, 0, NULL);

	//CreateObjInMap4(1.0f);
	//CreateObjInMap3(2.0f);
	//CreateObjInMap2(3.0f);
	//CreateObjInMap5(6.0f);
	//CreateObjInMap0(9.0f);
	//CreateObjInMap1(19.0f);
	CreateBossInMap_Level2(bossOccurTime_level3);
}

void Update3(void)
{
	Vector2D iniPosition_Block;
	Vector2D iniVelocity_Block;

	GetWinMaxMinXY();

	TimerUpdate(timeStart_level3);

	// =========================
	// 游戏逻辑响应输入
	// =========================
	KeyUpdate();

	// 更新对象
	ObjUpdate();

	// ====================
	// 碰撞检测
	// ====================
	BaseListTraverse(Visit_CollisionDetect);

	// =====================================
	// 计算所有对象的2D变换矩阵
	// =====================================
	BaseListTraverse(Visit_Matrix2DCount);
}

void Draw3(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// 逐个绘制对象列表中的所有对象
	BaseListTraverse(Visit_DrawObj);

}

void Free3(void)
{

	printf("Level3: free\n");
	// 使用函数gameObjDestroy删除列表中的对象
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload3(void)
{
	printf("Level3: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
