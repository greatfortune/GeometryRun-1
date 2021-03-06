/**
 * Project:		GeometryRun
 * File Name:	System.h
 * Author:		王晶
 * Date:		2017-4-22
 * Purpose:		系统处理模块
 */

#pragma once

#include <stdio.h>
#include <Windows.h>

 //------------------------------------------------------------------------------
 // Typedef:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Consts:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Structures:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Variables:
 //------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

			// 系统初始化
extern int System_Initialize(HINSTANCE, int);

// 系统退出
extern void System_Exit(void);