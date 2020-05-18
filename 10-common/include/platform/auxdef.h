/*******************************************************************************
 * ģ����      : TiVidDrv
 * �ļ���      : TiVidDrvDef.h
 * ����ļ�    : 
 * �ļ�ʵ�ֹ���: ��ģ��Ĺ�������
 * ����        : ť���ҩI
 * �汾        : V1.0 Copyright(C) 1995-2006 KEDACOM, All rights reserved.
 * -----------------------------------------------------------------------------
 * �޸ļ�¼:
 * ��  ��       �汾        �޸���      �޸�����
 * 2006/04/25   1.0a        ť����      ����	
*******************************************************************************/
#ifndef TIVIDDRVDEF_H
#define TIVIDDRVDEF_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "algorithmType.h"

#if !defined(s32)
    #define s32 int
#endif

/*��Ϣ��ӡ*/
#define MESSAGE   		printf

/*����*/
#define HANG()          do {MESSAGE("hang ... \n"); while (1) {volatile char x = 0;}} while (0)

/*��ȫ���ͷ��ڴ�*/
#define SAFE_FREE(p)    do {if (p) {free(p); p=NULL;}} while (0)

/*����*/
#define ASSERT(c)       do {assert(c);} while (0)

/*�������*/
#define C(c, n)         do {if (!(c)) {nRet=(n); goto finish;}} while (0)

/*���󷵻�*/
#define R(n)            do {nRet=(n); goto finish;} while (0)

#endif /*#ifndef TIVIDDRVDEF_H*/
