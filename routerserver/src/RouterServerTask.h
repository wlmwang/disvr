
/**
 * Copyright (C) Anny.
 * Copyright (C) Disvr, Inc.
 */

#ifndef _ROUTER_SERVER_TASK_H_
#define _ROUTER_SERVER_TASK_H_

#include <arpa/inet.h>
#include <functional>

#include "wType.h"
#include "wLog.h"
#include "wTcpTask.h"
#include "wDispatch.h"
#include "SvrCommand.h"

#define REG_FUNC(ActIdx, vFunc) wDispatch<function<int(char*, int)>, int>::Func_t {ActIdx, std::bind(vFunc, this, std::placeholders::_1, std::placeholders::_2)}
#define DEC_DISP(dispatch) wDispatch<function<int(char*, int)>, int> dispatch
#define DEC_FUNC(func) int func(char *pBuffer, int iLen)

#define ROUTER_REG_DISP(cmdid, paraid, func) mDispatch.Register("RouterServerTask", CMD_ID(cmdid, paraid), REG_FUNC(CMD_ID(cmdid, paraid), func));

class RouterServerTask : public wTcpTask
{
	public:
		RouterServerTask();
		RouterServerTask(wSocket *pSocket);
		~RouterServerTask();
		
		void Initialize();

		virtual int VerifyConn();
		virtual int Verify();

		virtual int HandleRecvMessage(char * pBuffer, int nLen);
		
		int ParseRecvMessage(struct wCommand* pCommand, char *pBuffer, int iLen);

		DEC_FUNC(InitSvrReq);
		DEC_FUNC(ReloadSvrReq);
		DEC_FUNC(SyncSvrReq);	//主动同步svr配置  建议agent只增量、更新、不删除同步（删除可让disabled=1）
		
	protected:
		DEC_DISP(mDispatch);
};

#endif
