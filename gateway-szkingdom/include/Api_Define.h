/*************************************************
* Copyright (c) 2020,深圳金证科技股份有限公司
* All rights reserved
*
* 文件名称：api_define.h
* 摘    要：API定义汇总
*
* 当前版本：1.0
* 作    者：邱海森
* 完成日期：20120年5月13日
**************************************************/
#pragma once
#include "Define_Acce.h"
#include "LBM_Define.h"
#include "Define.h"


#define OEM_PRODUCT_NAME  "提速版"   //fengwc alter 1.18

#

/**************/
/** 回调参数 */
struct CALLBACK_PARAM
{
  void* Plugin;         //!< LBM_Plugin指针
  void* hCallWnd;       //!< 调用方句柄
};

/** LBM错误信息 */
struct LBM_ERROR_INFO
{
  int nAssetID;         //!< 资产单元ID
  char szLBMID[16];       //!< LBM编号
  char szStkCode[LEN_CODELIST];       //!< 股票代码 fengwc alter 1.18 扩大股票代码空间，好放下股票代码列表
  char szOrderID[36];       //!< 合同序号
  char szErrorInfo[255];      //!< 错误信息
  // Add by chenmu 2015-8-17 14:30
  char szUserDefine[16 + 1];      //!< 用户自定义
};
typedef void (*CALLBACKFUN)(CALLBACK_PARAM* pParam, char* pObject);
typedef void (*CALLBACK_NQHQ)(CALLBACK_PARAM* pParam, STK_NQ_TICK* pNQHQInfo);            //!< 获取单支股票的普通行情回调函数
typedef void (*CALLBACK_ZSHQ)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo);            //!< 获取单支股票的做市行情回调函数
typedef void (*CALLBACK_ORDER)(CALLBACK_PARAM* pParam, ORDER_INFO* pOrderInfo);           //!< 委托确认回调函数
typedef void (*CALLBACK_MATCH)(CALLBACK_PARAM* pParam, MATCH_INFO* pMatchInfo);           //!< 成交确认回调函数
typedef void (*CALLBACK_ERROR)(CALLBACK_PARAM* pParam, LBM_ERROR_INFO* pErrorInfo);         //!< LBM错误回调函数
typedef void (*CALLBACK_NQINFO)(CALLBACK_PARAM* pParam, STK_NQINFO* pNQInfo, int nItem);        //!< 获取股票基础信息回调函数
typedef void (*CALLBACK_FUND)(CALLBACK_PARAM* pParam, ASSET_FUND* pFund, int nItem);          //!< 获取资产单元资金回调函数
typedef void (*CALLBACK_SHARE)(CALLBACK_PARAM* pParam, ASSET_SHARE* pShare, int nItem);       //!< 获取资产单元持仓回调函数
typedef void (*CALLBACK_QUOTE)(CALLBACK_PARAM* pParam, QUOTE_BACK_INFO* pBackQuote);          //!< 获取双边报价回调函数
typedef void (*CALLBACK_CANCELQUOTE)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< 获取撤单回调函数
typedef void (*CALLBACK_QUOTELIST)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pQuote, int nItem);    //!< 获取单支做市股票的委托明细回调函数
typedef void (*CALLBACK_QUOTEMATCH)(CALLBACK_PARAM* pParam, QUOTE_MATCH_INFO* pMatch, int nItem);   //!< 获取单支做市股票的成交明细回调函数
typedef void (*CALLBACK_TRADESUM)(CALLBACK_PARAM* pParam, QUOTE_TRADESUM_INFO* pSumInfo, int nItem);  //!< 某日成交汇总信息回调函数

////////****************************fengwc alter 1.18************************************/
typedef void (*CALLBACK_ASSETSHARE)(CALLBACK_PARAM* pParam, ST_AssetShareInfo* pInfo, int nItem);          //!< 获取持仓表股票信息回调函数
typedef void (*CALLBACK_NQHQ_CODES)(CALLBACK_PARAM* pParam, ST_NQInfo_Codes* pNQHQInfo, int nItem);        //!< 获取多支股票的普通行情、持仓、报价均价回调函数
typedef void (*CALLBACK_ZSHQ_CODES)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo, int nItem);          //!< 获取多支股票的做市行情回调函数
typedef void (*CALLBACK_QUOTE_CODES)(CALLBACK_PARAM* pParam, ST_Quote_Codes* pInfo, int nItem);          //!< 获取多支做市股票的委托明细信息回调函数
typedef void (*CALLBACK_RISKINFO_CODES)(CALLBACK_PARAM* pParam, ST_RiskInfo_Codes* pInfo, int nItem);        //!< 获取多支做市股票的风险查询信息回调函数
typedef void (*CALLBACK_ACCTINFO)(CALLBACK_PARAM* pParam, ST_AcctInfo* pInfo, int nItem);              //!< 获取当前交易员汇总的资产单元资金、市值，系统业务切换标志，闭市标志定股票的做市行情信息回调函数
typedef void (*CALLBACK_NQCONTRECS_CODES)(CALLBACK_PARAM* pParam, ST_NqContRecs_Codes* pInfo, int nItem);      //!< 获取多支做市股票的报价时长信息回调函数
typedef void (*CALLBACK_WITHDRAWORDER_CODES)(CALLBACK_PARAM* pParam, ST_WithdrawOrder_Codes* pInfo, int nItem);  //!< 获取多支做市股票的可撤单信息回调函数
typedef void (*CALLBACK_MATCHINFO_CODES)(CALLBACK_PARAM* pParam, ST_MatchInfo_Codes* pInfo, int nItem);      //!< 获取多支做市股票的成交明细信息回调函数
typedef void (*CALLBACK_HISLASTQUOTE_CODES)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pInfo, int nItem);     ///!< 获取多支做市股票的昨日报价查询信息回调函数
typedef void (*CALLBACK_INVSTKBCOSTRLT)(CALLBACK_PARAM* pParam, ST_InvStkBcostRltInfo* pInfo, int nItem);        //!< 获取合笔持仓成本信息回调函数
/*****************************************************************************************/
//!< fengweican alter 5.5 增加自营股票处理
typedef void (*CALLBACK_NQWTQUOTE)(CALLBACK_PARAM* pParam, NQWTQUOTE_BACK_INFO* pBackQuote);            //!< 自营股票报价回调函数
typedef void (*CALLBACK_NQWTQUOTELIST)(CALLBACK_PARAM* pParam, NQWTQUOTE_ORDER_INFO* pQuote, int nItem);      //!< 获取单支自营股票的委托明细
typedef void (*CALLBACK_NQWTQUOTEMATCH)(CALLBACK_PARAM* pParam, NQWTQUOTE_MATCH_INFO* pMatch, int nItem);     //!< 获取单支自营股票的成交明细信息
typedef void (*CALLBACK_NQWTQUOTE_CODES)(CALLBACK_PARAM* pParam, ST_NQWTQuote_Codes* pInfo, int nItem);      //!< 获取多支自营股票的委托明细信息
typedef void (*CALLBACK_NQWTMATCHEDINFO_CODES)(CALLBACK_PARAM* pParam, ST_NQWTMatchedInfo_Codes* pInfo, int nItem);//!< 获取多支自营股票的成交明细信息
//!< fengweican alter 2.28 增加大宗交易处理
typedef void (*CALLBACK_MOVEPOSBATCH)(CALLBACK_PARAM* pParam, ST_MovePosBatch* pInfo, int nItem);            //!< 获取撤单回调函数
typedef void (*CALLBACK_COMBILMTINFOBATCH)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< 获取撤单回调函数
typedef void (*CALLBACK_LISTCOMBIINFO)(CALLBACK_PARAM* pParam, ST_ASSET_CODE_INFO* pInfo, int nItem);            //!< 获取撤单回调函数
//add end
typedef void (*CALLBACK_JXWTQUOTE)(CALLBACK_PARAM* pParam, JXWTQUOTE_BACK_INFO* pBackQuote);            //!< 自营股票报价回调函数
