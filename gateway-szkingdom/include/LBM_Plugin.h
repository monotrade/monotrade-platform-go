/*************************************************
* Copyright (c) 2014,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：LBM_Plugin.h
* 摘    要：LBM算法插件
*
* 当前版本：1.0
* 作    者：陈牧
* 完成日期：2014年5月20日
**************************************************/
#pragma once
#include "Api_Define.h"
/**
* @defgroup AlgoPlug算法插件模块
* 基础算法API
* @author 陈牧
* @version 1.0
* @date 2013-2014
* @{
*/

/**
* @ingroup AlgoPlug
* @brief 算法API入口
*/


class __declspec(dllexport) LBM_Plugin
{
public:
  LBM_Plugin(void);
  ~LBM_Plugin(void);

  /**
  * 获取错误信息
  * @param[in] nErrorType  错误类型[0-插件；1-交易；2-行情；3-策略]
  * @return 错误信息
  */
  char* GetLastError(short nErrorType);
  /**
  * 同步服务器的时间差
  * @param[in] llDiffentSever 和服务器的时间差,毫秒数
  * @return
  */
  void SetSvrDiffrent(__int64 llDiffentSever);
  /**
  * 初始化插件
  * @param[in] pInitInfo 操作员用户名密码
  * @param[in] nThreads 线程池的线程数
  * @param[in] pszLogName  日志文件前缀
  * @param[in] pszAlgoName  需要授权码的产品名称
  * @return 初始化插件成功或失败
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME);
  /**
  * KSMMApi是否已连接
  * @return 成功或失败
  */
  int GetConncet();
  /**
  * 初始化插件(无config.ini)
  * @param[in] pInitInfo 操作员用户名密码
  * @param[in] tagKcbpConfig KCBP通讯设置
  * @param[in] nThreads 线程池的线程数
  * @param[in] pszLogName  日志文件前缀
  * @param[in] pszAlgoName  需要授权码的产品名称
  * @param[in] bLogOpenFlag 普通信息是否写入日志文件
  * @return 初始化插件成功或失败
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, ST_tagKCBP_CONFIG& tagKcbpConfig, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME, int bLogOpenFlag = 0); //fengwc alter 7.27
  /**
  * 获取可操作股票
  * @param[out] pCodeInfo 可操作的股票信息[这部分内存由系统回收，请勿删除]
  * @param[out] nCodeItems 可操作股票数量
  * @return 获取可操作股票成功或失败
  */
  int InitAlgo(ASSET_CODE** pCodeInfo, int& nCodeItems);

  // Add by chenmu 2015-1-22 10:30 获取服务器时间
  /**
  * 获取服务器时间，此调用为同步调用，建议在InitAlgo后调用（和本地时间比较，计算出时间差），勿与其它异步调用混用。
  * @param[out] nDate 服务器日期
  * @param[out] nTime 服务器时间
  * @return 获取服务器时间成功或失败
  */
  int GetSvrTime(int& nDate, int& nTime);
  // Add by chenmu 2015-1-22 Over

  /**
  * 关闭算法
  */
  void Close();

  /**
  * 行情配置
  * @param[in] nHQErrorNum 行情出错次数
  * @return 配置成功或失败
  */
  bool SetHQErrorNum(int nHQErrorNum);

  /**
  * 间隔时间配置
  * @param[in] nTickTime 行情轮询间隔
  * @param[in] nOrderTime 委托轮询间隔
  * @param[in] nConnectTime KCBP连接轮询间隔
  * @return 配置成功或失败
  */
  bool SetConfigTime(int nTickTime, int nOrderTime, int nConnectTime = 10000);

  /**
  * 设置提速版批量查询多支股票的相关请求,每次查询的股票数
  * @param[in] nCodeItems 每次查询的股票数
  * @return 配置成功或失败
  */
  bool SetCodeItems(int nCodeItems);
  /**************************fengwc alter 1.18提速版函数*****************************/
  /**
  * 得到授权码剩余天数
  * @return 授权码剩余天数
  */
  int GetOemDay();

  /**
  * 订阅股票行情
  * @param[in] pCode 股票代码
  * @return 调用LBM成功或失败
  */
  int SubScribe_Codes(char* pCode);
  int UnSubScribe_Codes(char* pCode);
  ////////////////////////////提速版API接口///////////////////////////////////////////////////
  /**
  * 设置获取多支做市股票的行情回调函数
  * @param[in] nHandle 句柄
  * @param[in] pNQTickFun 普通行情回调函数
  * @param[in] pZSTickFun 做市行情回调函数
  */
  void SetCallBackHQCodesFunction(void* hWnd, CALLBACK_NQHQ_CODES pNQTickFun, CALLBACK_ZSHQ_CODES pZSTickFun);
  /**
  * 设置获取持仓表股票信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 业务模块获取持仓表股票信息回调函数
  */
  void SetCallBackAssetShareFunction(void* hWnd, CALLBACK_ASSETSHARE pFun);
  /**
  * 设置查询合笔持仓成本信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 业务模块获取持仓表股票信息回调函数
  */
  void SetCallBackInvStkBcostRltFunction(void* hWnd, CALLBACK_INVSTKBCOSTRLT pFun);
  /**
  * 设置获取多支做市股票的委托明细回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 委托明细回调函数
  */
  void SetCallBackQuoteCodesFunction(void* hWnd, CALLBACK_QUOTE_CODES pFun);

  /**
  * 设置获取多支做市股票的风险查询回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 风险查询回调函数
  */
  void SetCallBackRiskInfoCodesFunction(void* hWnd, CALLBACK_RISKINFO_CODES pFun);

  /**
  * 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情信息
  * @param[in] nHandle 句柄
  * @param[in] pFun 当前交易员汇总的资产单元资金、市值，系统业务回调函数
  */
  void SetCallBackAcctInfoFunction(void* hWnd, CALLBACK_ACCTINFO pFun);
  
  /**
  * 设置多支做市股票的报价时长回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 报价时长回调函数
  */
  void SetCallBackNqContRecsCodesFunction(void* hWnd, CALLBACK_NQCONTRECS_CODES pFun);
  /**
  * 设置多支做市股票的可撤单信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 可撤单信息回调函数
  */
  void SetCallBackWithdrawOrderCodesFunction(void* hWnd, CALLBACK_WITHDRAWORDER_CODES pFun);
  /**
  * 设置获取多支做市股票的成交明细信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 成交明细信息回调函数
  */
  void SetCallBackMatchInfoCodesFunction(void* hWnd, CALLBACK_MATCHINFO_CODES pFun);
  /**
  * 设置获取多支做市股票的昨日报价查询信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 昨日报价查询信息回调函数
  */
  void SetCallBackCallHisLastQuoteCodesFunction(void* hWnd, CALLBACK_HISLASTQUOTE_CODES pFun);
  /************************************************************************************/


public:
  /**
  * 获取股票基本信息
  * @param[in] szStkCode 股票代码
  * @return 调用LBM成功或失败
  */
  int GetNQInfo(char* pStkCode);
  /**
  * 请求普通行情（异步模式）
  * @param[in] pStkCode 股票代码
  */
  void GetNQTick(char* pStkCode);
  /**
  * 请求做市行情（异步模式）
  * @param[in] pStkCode 股票代码
  */
  void GetZSTick(char* pStkCode);
  /**
  * 设置行情回调函数
  * @param[in] nHandle 句柄
  * @param[in] pNQTickFun 普通行情回调函数
  * @param[in] pZSTickFun 做市行情回调函数
  */
  void SetCallBackHQFunction(void* hWnd, CALLBACK_NQHQ pNQTickFun, CALLBACK_ZSHQ pZSTickFun);
  /**
  * 设置委托回调函数
  * @param[in] nHandle 句柄
  * @param[in] pOrderFun 委托回调函数
  * @param[in] pTradeFun 成交回调函数
  */
  void SetCallBackWTFunction(void* hWnd, CALLBACK_ORDER pOrderFun, CALLBACK_MATCH pTradeFun);
  /**
  * 设置策略主线程退出回调函数
  * @param[in] nHandle 句柄
  * @param[in] pTickErrorFun 行情获取失败超限回调函数
  * @param[in] pMainTreadStopFun 主线程停止回调函数
  */
  void SetCallBackMainThread(void* hWnd, CALLBACKFUN pTickErrorFun, CALLBACKFUN pMainTreadStopFun);
  /**
  * 设置LBM错误回调函数
  * @param[in] nHandle 句柄
  * @param[in] pLBMErrorFun LBM错误回调函数
  */
  void SetCallBackLBMError(void* hWnd, CALLBACK_ERROR pLBMErrorFun);
  /**
  * 设置股票基础应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pNQInfoFun 股票基础信息回调函数
  */
  void SetCallBackNQInfo(void* hWnd, CALLBACK_NQINFO pNQInfoFun);
  /**
  * 设置资金应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFundFun 资金应答回调函数
  */
  void SetCallBackFund(void* hWnd, CALLBACK_FUND pFundFun);
  /**
  * 设置持仓应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pShareFun 持仓应答回调函数
  */
  void SetCallBackShare(void* hWnd, CALLBACK_SHARE pShareFun);
  /**
  * 设置双边报价回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 双边报价回调函数
  */
  void SetCallBackQuote(void* hWnd, CALLBACK_QUOTE pQuoteFun);

  /**
  * 设置撤单回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 撤单回调函数
  */
  void SetCallBackCancelQuote(void* hWnd, CALLBACK_CANCELQUOTE pFun);
  /**
  * 设置做市委托明细应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 委托明细回调函数
  */
  void SetCallBackQuoteList(void* hWnd, CALLBACK_QUOTELIST pQuoteFun);
  /**
  * 设置做市成交明细明细应答数据回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteMatchFun 成交明细回调函数
  */
  void SetCallBackQuoteMatchList(void* hWnd, CALLBACK_QUOTEMATCH pQuoteMatchFun);
  //!< fengweican alter 2.28 增加大宗交易处理
  /**
  * 设置批量转移证券资产回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 撤单回调函数
  */
  void SetCallBackMovePosBatch(void* hWnd, CALLBACK_MOVEPOSBATCH pFun);
  /**
  * 设置批量修改证券组合限额回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 委托明细回调函数
  */
  void SetCallBackCombiLmtInfoBatch(void* hWnd, CALLBACK_COMBILMTINFOBATCH pFun);
  /**
  * 设置查询资产单元的证券组合回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 查询资产单元的证券组合回调函数
  */
  void SetCallBackListCombiInfo(void* hWnd, CALLBACK_LISTCOMBIINFO pFun);
  /**
  * 订阅股票行情
  * @param[in] pCode 股票代码
  * @return 调用LBM成功或失败
  */
  int SubScribe(char* pCode);
  /**
  * 退订股票行情
  * @param[in] pCode 股票代码
  * @return 调用LBM成功或失败
  */
  int UnSubScribe(char* pCode);
  /**
  * 获取股票普通行情
  * @param[in] pCode 股票代码
  * @return 行情信息
  */
  STK_NQ_TICK* GetNQTickInfo(char* pCode);
  /**
  * 获取股票做市行情
  * @param[in] pCode 股票代码
  * @return 行情信息
  */
  STK_NQ_ZSXX* GetZSTickInfo(char* pCode);
  /**
  * 获取委托信息
  * @param[in] pOrderID 委托合同序号
  * @return 委托信息
  */
  ORDER_INFO* GetOrder(char* pOrderID);
  /**
  * 取操作员的资金
  * @param[in] nAssetID 资产单元ID(0-表示当前用户的所有资产单元)
  * @return 调用LBM成功或失败
  */
  int GetFunds(int nAssetID);

  /**
  * 取操作员的持仓
  * @param[in] nAssetID 资产单元ID(0-表示当前用户的所有资产单元)
  * @param[in] bZero 是否返回持仓为0的记录
  * @return 调用LBM成功或失败
  */
  int GetShare(int nAssetID, int bZero, char* pStkCode);

  /**
  * 做市交易报单
  * @param[in] pQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int Quote(QUOTE_INFO* pQuoteInfo);

  /**
  * 做市策略交易报单
  * @param[in] pAlgoQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int AlgoQuote(ALGOQUOTE_INFO* pAlgoQuoteInfo);
  /**
  * 做市撤单申报
  * @param[in] pOrderID 委托合同序号
  * @param[in] chOrderType 委托类型
  * @return 调用LBM成功或失败
  */
  int CancelOrder(char* pOrderID, char chOrderType);

  /**
  * 做市撤单申报(用于重新登录后的撤单) fengwc alter 9.16
  * @param[in] pOrderID 委托合同序号
  * @param[in] chOrderType 委托类型
  * @return 调用LBM成功或失败
  */
  int CancelOldOrder(char* pOrderID, char chOrderType);
  /**
  * 成交回报
  * @param[in] pOrderID 委托合同序号
  * @return 返回成交回报信息
  */
  QUOTE_MATCH_INFO* GetTrade(char* pOrderID);
  /**
  * 查询单支做市股票的委托明细
  * @param[in] pOrderSearch 委托查询条件
  * @return 调用LBM成功或失败
  */
  int List_Quote(ORDER_SEARCH OrderSearch);

  /**
  * 按时间段查询单支做市股票的成交明细
  * @param[in] MatchSearch 委托查询条件
  * @return 调用LBM成功或失败
  */
  int List_QuoteMatch(ORDER_SEARCH MatchSearch);

  // Add by chenmu 2015-7-27 17:00 按成交编号查询成交明细
  /**
  * 按成交编号查询单支做市股票的成交明细（此函数只适用于KSMM交易柜台v1.1.0.0及以上版本，且不可同时调用List_QuoteMatch）
  * @param[in] MatchSearch 成交查询条件
  * @return 调用LBM成功或失败
  */
  int List_NewMatch(MATCH_SEARCHE MatchSearch);
  // End Add

  /**
  * 获取策略基本信息
  * @param[out] pAlgoBaseInfo 基本策略信息
  * @param[out] nAlgoBaseItems 基本策略个数
  * @return 调用LBM成功或失败
  */
  int GetAlgoBaseInfo(ALGO_BASEINFO** pAlgoBaseInfo, int& nAlgoBaseItems);

  /**
  * 获取策略信息
  * @param[in] nAssetID 资产单元ID
  * @param[out] pAlgoInfo 策略信息
  * @param[out] nAlgoItems 策略个数
  * @return 调用LBM成功或失败
  */
  int GetAlgoInfo(int nAssetID, ALGO_INFO** pAlgoInfo, int& nAlgoItems);

  /**
  * 获取策略参数信息
  * @param[in] nAlgoID 策略ID
  * @param[out] pAlgoParam 策略参数信息
  * @param[out] nAlgoParamItems 策略参数个数
  * @return 调用LBM成功或失败
  */
  int GetAlgoParamInfo(int nAlgoID, ALGO_INFO_EXT** pAlgoParam, int& nAlgoParamItems);

  //add by zhangshuai
  /**
  * 配置策略状态
  * @param[in] nAlgoID 策略ID
  * @param[in] chAlgoStatus 策略状态
  * @return 调用LBM成功或失败
  */
  int SetAlgoStatus(int nAlgoID, char chAlgoStatus);
  //!< fengweican alter 5.5 增加自营股票处理
  /**
  * 自营股票交易报单
  * @param[in] pQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int NQWTQuote(NQWTQUOTE_INFO* pQuoteInfo);

  /**
  * 精选层股票交易报单
  * @param[in] pAlgoQuote 报价信息
  * @param[in] iOrderType 委托类型: 0 - 限价,1-对手方最优， 2-本方最优，3-最优五档即时成交剩余撤销 4-最优五档即时成交剩余转限价
  * @return 调用LBM成功或失败
  */
  int JxWtQuote(ALGOQUOTE_INFO* pAlgoQuote, int iOrderType);
  /**
  * 查询单支自营股票的委托明细
  * @param[in] pOrderSearch 委托查询条件 
  * @return 调用LBM成功或失败
  */
  int List_NQWTQuote(NQWTORDER_SEARCH OrderSearch);
  /**
  * 查询单支自营股票的成交明细
  * @param[in] MatchSearch 成交查询条件
  * @return 调用LBM成功或失败
  */
  int List_NQWTQuoteMatch(NQWTMATCH_SEARCHE MatchSearch);
  /**
  * 获取多支自营股票的委托明细信息  L3015208
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int GetList_NQWTQuote_Codes(char* pCodeList);

  /**
  * 获取多支自营股票的成交明细信息结果  L3015209
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_NQWTMatchedInfo_Codes(char* pCodeList);
  //!< fengweican alter 2.28 增加大宗交易处理
  /**
  * 集合竞价转让和盘后大宗交易转让
  * @param[in] pQuoteInfo 报价信息
  * @return 调用LBM成功或失败
  */
  int DZQuote(DZQUOTE_INFO* pQuoteInfo);
  /**
  * 批量转移证券资产
  * @param[in] pInfo 证券资产信息
  * @return 调用LBM成功或失败
  */
  int MovePosBatch(ST_MovePosBatch* pInfo);
  /**
  * 批量修改证券组合限额
  * @param[in] szStkCodes 证券代码^持仓限额组合，入参格式如下：证券代码1^持仓限额1|证券代码2^持仓限额2|证券代码3^持仓限额3|……
  * @return 调用LBM成功或失败
  */
  int SetCombiLmtInfoBatch(char* szStkCodes);
  /**
  * 查询资产单元的证券组合
  * @param[in] nAssetID 资产单元ID
  * @param[in] nCombiID 组合ID
  * @param[in] szStkCode 证券代码
  * @return 调用LBM成功或失败
  */
  int GetListCombiInfo(int nAssetID, int nCombiID, char* szStkCode);
  /**
  * 设置获取多支自营股票的委托明细信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 委托明细回调函数
  */
  void SetCallBackNQWTQuoteCodesFunction(void* hWnd, CALLBACK_NQWTQUOTE_CODES pFun);
  /**
  * 设置获取多支自营股票的成交明细信息回调函数
  * @param[in] nHandle 句柄
  * @param[in] pFun 委托明细回调函数
  */
  void SetCallBackNQWTMatchedInfoCodesFunction(void* hWnd, CALLBACK_NQWTMATCHEDINFO_CODES pFun);
  /**
  * 设置自营股票报价回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 自营股票报价回调函数
  */
  void SetCallBackNQWTQuote(void* hWnd, CALLBACK_NQWTQUOTE pQuoteFun);
  /**
  * 设置精选层股票双边报价回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 精选层股票双边报价回调函数
  */
  void SetCallBackJXWTQuote(void* hWnd, CALLBACK_JXWTQUOTE pQuoteFun);
  /**
  * 设置获取单支自营股票的委托明细回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteFun 委托明细回调函数
  */
  void SetCallBackNQWTQuoteList(void* hWnd, CALLBACK_NQWTQUOTELIST pQuoteFun);
  /**
  * 设置获取单支自营股票的成交明细回调函数
  * @param[in] nHandle 句柄
  * @param[in] pQuoteMatchFun 成交明细回调函数
  */
  void SetCallBackNQWTQuoteMatchList(void* hWnd, CALLBACK_NQWTQUOTEMATCH pQuoteMatchFun);
  //add end

  /***************************fengwc alter 1.18********************************/

public:
  /**
  * 获取持仓表股票信息 L3014026
  * @param[in] nAssetID 资产单元ID
  * @param[in] pCode    股票代码
  * @return 调用LBM成功或失败
  */
  int GetAssetShare(int nAssetID, char* pCode);
  /**
  * 获取合笔持仓成本信息
  * @param[in] nAssetID 资产单元ID
  * @param[in] szCodeList    股票代码列表
  * @return 调用LBM成功或失败
  */
  int GetInvStkBcostRlt(int nAssetID, char* szCodeList);
  /**
  * 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情 L3015204
  * @param[in] nAssetID 资产单元ID
  * @return 调用LBM成功或失败
  */
  int GetAcctInfo(int nAssetID);
  /**
  * 获取多支做市股票的委托明细信息  L3015202
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_Quote_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的风险信息  L3015203
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_RiskInfo_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的报价时长信息  L3015205
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_NqContRecs_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的可撤单信息  L3015206
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_WithdrawOrder_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的成交明细信息  L3015207
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_QuoteMatch_Codes(char* pCodeList);

  /**
  * 获取多支做市股票的昨日报价查询信息  L3015210
  * @param[in] pCodeList 股票列表集合
  * @return 调用LBM成功或失败
  */
  int  GetList_HisLastQuote_Codes(char* pCodeList);
  /*****************************************************/

  /*同步接口*/
  int GetMmOrder(const char* szStkCode,  int iNum, bool bReverseOrder = true);
  int GetMmMatched();
  int GetStkInfo(const char* szStkCode, STK_NQINFO* stNqInfo);
  int GetAssetShare(int AssetId, ASSET_SHARE* stAssetShare);
  int GetAseetFund();
  int MmQuote();
  int CancelMmOrder();
  private:
    void* m_clKsmmApi;
};

