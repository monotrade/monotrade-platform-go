/*************************************************
* Copyright (c) 2020,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�api_define.h
* ժ    Ҫ��API�������
*
* ��ǰ�汾��1.0
* ��    �ߣ���ɭ
* ������ڣ�20120��5��13��
**************************************************/
#pragma once
#include "Define_Acce.h"
#include "LBM_Define.h"
#include "Define.h"


#define OEM_PRODUCT_NAME  "���ٰ�"   //fengwc alter 1.18

#

/**************/
/** �ص����� */
struct CALLBACK_PARAM
{
  void* Plugin;         //!< LBM_Pluginָ��
  void* hCallWnd;       //!< ���÷����
};

/** LBM������Ϣ */
struct LBM_ERROR_INFO
{
  int nAssetID;         //!< �ʲ���ԪID
  char szLBMID[16];       //!< LBM���
  char szStkCode[LEN_CODELIST];       //!< ��Ʊ���� fengwc alter 1.18 �����Ʊ����ռ䣬�÷��¹�Ʊ�����б�
  char szOrderID[36];       //!< ��ͬ���
  char szErrorInfo[255];      //!< ������Ϣ
  // Add by chenmu 2015-8-17 14:30
  char szUserDefine[16 + 1];      //!< �û��Զ���
};
typedef void (*CALLBACKFUN)(CALLBACK_PARAM* pParam, char* pObject);
typedef void (*CALLBACK_NQHQ)(CALLBACK_PARAM* pParam, STK_NQ_TICK* pNQHQInfo);            //!< ��ȡ��֧��Ʊ����ͨ����ص�����
typedef void (*CALLBACK_ZSHQ)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo);            //!< ��ȡ��֧��Ʊ����������ص�����
typedef void (*CALLBACK_ORDER)(CALLBACK_PARAM* pParam, ORDER_INFO* pOrderInfo);           //!< ί��ȷ�ϻص�����
typedef void (*CALLBACK_MATCH)(CALLBACK_PARAM* pParam, MATCH_INFO* pMatchInfo);           //!< �ɽ�ȷ�ϻص�����
typedef void (*CALLBACK_ERROR)(CALLBACK_PARAM* pParam, LBM_ERROR_INFO* pErrorInfo);         //!< LBM����ص�����
typedef void (*CALLBACK_NQINFO)(CALLBACK_PARAM* pParam, STK_NQINFO* pNQInfo, int nItem);        //!< ��ȡ��Ʊ������Ϣ�ص�����
typedef void (*CALLBACK_FUND)(CALLBACK_PARAM* pParam, ASSET_FUND* pFund, int nItem);          //!< ��ȡ�ʲ���Ԫ�ʽ�ص�����
typedef void (*CALLBACK_SHARE)(CALLBACK_PARAM* pParam, ASSET_SHARE* pShare, int nItem);       //!< ��ȡ�ʲ���Ԫ�ֲֻص�����
typedef void (*CALLBACK_QUOTE)(CALLBACK_PARAM* pParam, QUOTE_BACK_INFO* pBackQuote);          //!< ��ȡ˫�߱��ۻص�����
typedef void (*CALLBACK_CANCELQUOTE)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< ��ȡ�����ص�����
typedef void (*CALLBACK_QUOTELIST)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pQuote, int nItem);    //!< ��ȡ��֧���й�Ʊ��ί����ϸ�ص�����
typedef void (*CALLBACK_QUOTEMATCH)(CALLBACK_PARAM* pParam, QUOTE_MATCH_INFO* pMatch, int nItem);   //!< ��ȡ��֧���й�Ʊ�ĳɽ���ϸ�ص�����
typedef void (*CALLBACK_TRADESUM)(CALLBACK_PARAM* pParam, QUOTE_TRADESUM_INFO* pSumInfo, int nItem);  //!< ĳ�ճɽ�������Ϣ�ص�����

////////****************************fengwc alter 1.18************************************/
typedef void (*CALLBACK_ASSETSHARE)(CALLBACK_PARAM* pParam, ST_AssetShareInfo* pInfo, int nItem);          //!< ��ȡ�ֱֲ��Ʊ��Ϣ�ص�����
typedef void (*CALLBACK_NQHQ_CODES)(CALLBACK_PARAM* pParam, ST_NQInfo_Codes* pNQHQInfo, int nItem);        //!< ��ȡ��֧��Ʊ����ͨ���顢�ֲ֡����۾��ۻص�����
typedef void (*CALLBACK_ZSHQ_CODES)(CALLBACK_PARAM* pParam, STK_NQ_ZSXX* pZSHQInfo, int nItem);          //!< ��ȡ��֧��Ʊ����������ص�����
typedef void (*CALLBACK_QUOTE_CODES)(CALLBACK_PARAM* pParam, ST_Quote_Codes* pInfo, int nItem);          //!< ��ȡ��֧���й�Ʊ��ί����ϸ��Ϣ�ص�����
typedef void (*CALLBACK_RISKINFO_CODES)(CALLBACK_PARAM* pParam, ST_RiskInfo_Codes* pInfo, int nItem);        //!< ��ȡ��֧���й�Ʊ�ķ��ղ�ѯ��Ϣ�ص�����
typedef void (*CALLBACK_ACCTINFO)(CALLBACK_PARAM* pParam, ST_AcctInfo* pInfo, int nItem);              //!< ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ������������Ϣ�ص�����
typedef void (*CALLBACK_NQCONTRECS_CODES)(CALLBACK_PARAM* pParam, ST_NqContRecs_Codes* pInfo, int nItem);      //!< ��ȡ��֧���й�Ʊ�ı���ʱ����Ϣ�ص�����
typedef void (*CALLBACK_WITHDRAWORDER_CODES)(CALLBACK_PARAM* pParam, ST_WithdrawOrder_Codes* pInfo, int nItem);  //!< ��ȡ��֧���й�Ʊ�Ŀɳ�����Ϣ�ص�����
typedef void (*CALLBACK_MATCHINFO_CODES)(CALLBACK_PARAM* pParam, ST_MatchInfo_Codes* pInfo, int nItem);      //!< ��ȡ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ�ص�����
typedef void (*CALLBACK_HISLASTQUOTE_CODES)(CALLBACK_PARAM* pParam, QUOTE_ORDER_INFO* pInfo, int nItem);     ///!< ��ȡ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ�ص�����
typedef void (*CALLBACK_INVSTKBCOSTRLT)(CALLBACK_PARAM* pParam, ST_InvStkBcostRltInfo* pInfo, int nItem);        //!< ��ȡ�ϱʳֲֳɱ���Ϣ�ص�����
/*****************************************************************************************/
//!< fengweican alter 5.5 ������Ӫ��Ʊ����
typedef void (*CALLBACK_NQWTQUOTE)(CALLBACK_PARAM* pParam, NQWTQUOTE_BACK_INFO* pBackQuote);            //!< ��Ӫ��Ʊ���ۻص�����
typedef void (*CALLBACK_NQWTQUOTELIST)(CALLBACK_PARAM* pParam, NQWTQUOTE_ORDER_INFO* pQuote, int nItem);      //!< ��ȡ��֧��Ӫ��Ʊ��ί����ϸ
typedef void (*CALLBACK_NQWTQUOTEMATCH)(CALLBACK_PARAM* pParam, NQWTQUOTE_MATCH_INFO* pMatch, int nItem);     //!< ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ
typedef void (*CALLBACK_NQWTQUOTE_CODES)(CALLBACK_PARAM* pParam, ST_NQWTQuote_Codes* pInfo, int nItem);      //!< ��ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ
typedef void (*CALLBACK_NQWTMATCHEDINFO_CODES)(CALLBACK_PARAM* pParam, ST_NQWTMatchedInfo_Codes* pInfo, int nItem);//!< ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ
//!< fengweican alter 2.28 ���Ӵ��ڽ��״���
typedef void (*CALLBACK_MOVEPOSBATCH)(CALLBACK_PARAM* pParam, ST_MovePosBatch* pInfo, int nItem);            //!< ��ȡ�����ص�����
typedef void (*CALLBACK_COMBILMTINFOBATCH)(CALLBACK_PARAM* pParam, char* pBackCancelQuote, int nLen);           //!< ��ȡ�����ص�����
typedef void (*CALLBACK_LISTCOMBIINFO)(CALLBACK_PARAM* pParam, ST_ASSET_CODE_INFO* pInfo, int nItem);            //!< ��ȡ�����ص�����
//add end
typedef void (*CALLBACK_JXWTQUOTE)(CALLBACK_PARAM* pParam, JXWTQUOTE_BACK_INFO* pBackQuote);            //!< ��Ӫ��Ʊ���ۻص�����
