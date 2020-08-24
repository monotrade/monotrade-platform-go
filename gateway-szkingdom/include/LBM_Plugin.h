/*************************************************
* Copyright (c) 2014,���ڽ�֤�Ƽ��ɷ����޹�˾
* All rights reserved
*
* �ļ����ƣ�LBM_Plugin.h
* ժ    Ҫ��LBM�㷨���
*
* ��ǰ�汾��1.0
* ��    �ߣ�����
* ������ڣ�2014��5��20��
**************************************************/
#pragma once
#include "Api_Define.h"
/**
* @defgroup AlgoPlug�㷨���ģ��
* �����㷨API
* @author ����
* @version 1.0
* @date 2013-2014
* @{
*/

/**
* @ingroup AlgoPlug
* @brief �㷨API���
*/


class __declspec(dllexport) LBM_Plugin
{
public:
  LBM_Plugin(void);
  ~LBM_Plugin(void);

  /**
  * ��ȡ������Ϣ
  * @param[in] nErrorType  ��������[0-�����1-���ף�2-���飻3-����]
  * @return ������Ϣ
  */
  char* GetLastError(short nErrorType);
  /**
  * ͬ����������ʱ���
  * @param[in] llDiffentSever �ͷ�������ʱ���,������
  * @return
  */
  void SetSvrDiffrent(__int64 llDiffentSever);
  /**
  * ��ʼ�����
  * @param[in] pInitInfo ����Ա�û�������
  * @param[in] nThreads �̳߳ص��߳���
  * @param[in] pszLogName  ��־�ļ�ǰ׺
  * @param[in] pszAlgoName  ��Ҫ��Ȩ��Ĳ�Ʒ����
  * @return ��ʼ������ɹ���ʧ��
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME);
  /**
  * KSMMApi�Ƿ�������
  * @return �ɹ���ʧ��
  */
  int GetConncet();
  /**
  * ��ʼ�����(��config.ini)
  * @param[in] pInitInfo ����Ա�û�������
  * @param[in] tagKcbpConfig KCBPͨѶ����
  * @param[in] nThreads �̳߳ص��߳���
  * @param[in] pszLogName  ��־�ļ�ǰ׺
  * @param[in] pszAlgoName  ��Ҫ��Ȩ��Ĳ�Ʒ����
  * @param[in] bLogOpenFlag ��ͨ��Ϣ�Ƿ�д����־�ļ�
  * @return ��ʼ������ɹ���ʧ��
  */
  int InitPlugin(PST_tagInitInfo pInitInfo, ST_tagKCBP_CONFIG& tagKcbpConfig, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME, int bLogOpenFlag = 0); //fengwc alter 7.27
  /**
  * ��ȡ�ɲ�����Ʊ
  * @param[out] pCodeInfo �ɲ����Ĺ�Ʊ��Ϣ[�ⲿ���ڴ���ϵͳ���գ�����ɾ��]
  * @param[out] nCodeItems �ɲ�����Ʊ����
  * @return ��ȡ�ɲ�����Ʊ�ɹ���ʧ��
  */
  int InitAlgo(ASSET_CODE** pCodeInfo, int& nCodeItems);

  // Add by chenmu 2015-1-22 10:30 ��ȡ������ʱ��
  /**
  * ��ȡ������ʱ�䣬�˵���Ϊͬ�����ã�������InitAlgo����ã��ͱ���ʱ��Ƚϣ������ʱ�������������첽���û��á�
  * @param[out] nDate ����������
  * @param[out] nTime ������ʱ��
  * @return ��ȡ������ʱ��ɹ���ʧ��
  */
  int GetSvrTime(int& nDate, int& nTime);
  // Add by chenmu 2015-1-22 Over

  /**
  * �ر��㷨
  */
  void Close();

  /**
  * ��������
  * @param[in] nHQErrorNum ����������
  * @return ���óɹ���ʧ��
  */
  bool SetHQErrorNum(int nHQErrorNum);

  /**
  * ���ʱ������
  * @param[in] nTickTime ������ѯ���
  * @param[in] nOrderTime ί����ѯ���
  * @param[in] nConnectTime KCBP������ѯ���
  * @return ���óɹ���ʧ��
  */
  bool SetConfigTime(int nTickTime, int nOrderTime, int nConnectTime = 10000);

  /**
  * �������ٰ�������ѯ��֧��Ʊ���������,ÿ�β�ѯ�Ĺ�Ʊ��
  * @param[in] nCodeItems ÿ�β�ѯ�Ĺ�Ʊ��
  * @return ���óɹ���ʧ��
  */
  bool SetCodeItems(int nCodeItems);
  /**************************fengwc alter 1.18���ٰ溯��*****************************/
  /**
  * �õ���Ȩ��ʣ������
  * @return ��Ȩ��ʣ������
  */
  int GetOemDay();

  /**
  * ���Ĺ�Ʊ����
  * @param[in] pCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int SubScribe_Codes(char* pCode);
  int UnSubScribe_Codes(char* pCode);
  ////////////////////////////���ٰ�API�ӿ�///////////////////////////////////////////////////
  /**
  * ���û�ȡ��֧���й�Ʊ������ص�����
  * @param[in] nHandle ���
  * @param[in] pNQTickFun ��ͨ����ص�����
  * @param[in] pZSTickFun ��������ص�����
  */
  void SetCallBackHQCodesFunction(void* hWnd, CALLBACK_NQHQ_CODES pNQTickFun, CALLBACK_ZSHQ_CODES pZSTickFun);
  /**
  * ���û�ȡ�ֱֲ��Ʊ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ҵ��ģ���ȡ�ֱֲ��Ʊ��Ϣ�ص�����
  */
  void SetCallBackAssetShareFunction(void* hWnd, CALLBACK_ASSETSHARE pFun);
  /**
  * ���ò�ѯ�ϱʳֲֳɱ���Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ҵ��ģ���ȡ�ֱֲ��Ʊ��Ϣ�ص�����
  */
  void SetCallBackInvStkBcostRltFunction(void* hWnd, CALLBACK_INVSTKBCOSTRLT pFun);
  /**
  * ���û�ȡ��֧���й�Ʊ��ί����ϸ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ί����ϸ�ص�����
  */
  void SetCallBackQuoteCodesFunction(void* hWnd, CALLBACK_QUOTE_CODES pFun);

  /**
  * ���û�ȡ��֧���й�Ʊ�ķ��ղ�ѯ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ���ղ�ѯ�ص�����
  */
  void SetCallBackRiskInfoCodesFunction(void* hWnd, CALLBACK_RISKINFO_CODES pFun);

  /**
  * ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ������������Ϣ
  * @param[in] nHandle ���
  * @param[in] pFun ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ��ص�����
  */
  void SetCallBackAcctInfoFunction(void* hWnd, CALLBACK_ACCTINFO pFun);
  
  /**
  * ���ö�֧���й�Ʊ�ı���ʱ���ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ����ʱ���ص�����
  */
  void SetCallBackNqContRecsCodesFunction(void* hWnd, CALLBACK_NQCONTRECS_CODES pFun);
  /**
  * ���ö�֧���й�Ʊ�Ŀɳ�����Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �ɳ�����Ϣ�ص�����
  */
  void SetCallBackWithdrawOrderCodesFunction(void* hWnd, CALLBACK_WITHDRAWORDER_CODES pFun);
  /**
  * ���û�ȡ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �ɽ���ϸ��Ϣ�ص�����
  */
  void SetCallBackMatchInfoCodesFunction(void* hWnd, CALLBACK_MATCHINFO_CODES pFun);
  /**
  * ���û�ȡ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ���ձ��۲�ѯ��Ϣ�ص�����
  */
  void SetCallBackCallHisLastQuoteCodesFunction(void* hWnd, CALLBACK_HISLASTQUOTE_CODES pFun);
  /************************************************************************************/


public:
  /**
  * ��ȡ��Ʊ������Ϣ
  * @param[in] szStkCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetNQInfo(char* pStkCode);
  /**
  * ������ͨ���飨�첽ģʽ��
  * @param[in] pStkCode ��Ʊ����
  */
  void GetNQTick(char* pStkCode);
  /**
  * �����������飨�첽ģʽ��
  * @param[in] pStkCode ��Ʊ����
  */
  void GetZSTick(char* pStkCode);
  /**
  * ��������ص�����
  * @param[in] nHandle ���
  * @param[in] pNQTickFun ��ͨ����ص�����
  * @param[in] pZSTickFun ��������ص�����
  */
  void SetCallBackHQFunction(void* hWnd, CALLBACK_NQHQ pNQTickFun, CALLBACK_ZSHQ pZSTickFun);
  /**
  * ����ί�лص�����
  * @param[in] nHandle ���
  * @param[in] pOrderFun ί�лص�����
  * @param[in] pTradeFun �ɽ��ص�����
  */
  void SetCallBackWTFunction(void* hWnd, CALLBACK_ORDER pOrderFun, CALLBACK_MATCH pTradeFun);
  /**
  * ���ò������߳��˳��ص�����
  * @param[in] nHandle ���
  * @param[in] pTickErrorFun �����ȡʧ�ܳ��޻ص�����
  * @param[in] pMainTreadStopFun ���߳�ֹͣ�ص�����
  */
  void SetCallBackMainThread(void* hWnd, CALLBACKFUN pTickErrorFun, CALLBACKFUN pMainTreadStopFun);
  /**
  * ����LBM����ص�����
  * @param[in] nHandle ���
  * @param[in] pLBMErrorFun LBM����ص�����
  */
  void SetCallBackLBMError(void* hWnd, CALLBACK_ERROR pLBMErrorFun);
  /**
  * ���ù�Ʊ����Ӧ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pNQInfoFun ��Ʊ������Ϣ�ص�����
  */
  void SetCallBackNQInfo(void* hWnd, CALLBACK_NQINFO pNQInfoFun);
  /**
  * �����ʽ�Ӧ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pFundFun �ʽ�Ӧ��ص�����
  */
  void SetCallBackFund(void* hWnd, CALLBACK_FUND pFundFun);
  /**
  * ���óֲ�Ӧ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pShareFun �ֲ�Ӧ��ص�����
  */
  void SetCallBackShare(void* hWnd, CALLBACK_SHARE pShareFun);
  /**
  * ����˫�߱��ۻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ˫�߱��ۻص�����
  */
  void SetCallBackQuote(void* hWnd, CALLBACK_QUOTE pQuoteFun);

  /**
  * ���ó����ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �����ص�����
  */
  void SetCallBackCancelQuote(void* hWnd, CALLBACK_CANCELQUOTE pFun);
  /**
  * ��������ί����ϸӦ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ί����ϸ�ص�����
  */
  void SetCallBackQuoteList(void* hWnd, CALLBACK_QUOTELIST pQuoteFun);
  /**
  * �������гɽ���ϸ��ϸӦ�����ݻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteMatchFun �ɽ���ϸ�ص�����
  */
  void SetCallBackQuoteMatchList(void* hWnd, CALLBACK_QUOTEMATCH pQuoteMatchFun);
  //!< fengweican alter 2.28 ���Ӵ��ڽ��״���
  /**
  * ��������ת��֤ȯ�ʲ��ص�����
  * @param[in] nHandle ���
  * @param[in] pFun �����ص�����
  */
  void SetCallBackMovePosBatch(void* hWnd, CALLBACK_MOVEPOSBATCH pFun);
  /**
  * ���������޸�֤ȯ����޶�ص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ί����ϸ�ص�����
  */
  void SetCallBackCombiLmtInfoBatch(void* hWnd, CALLBACK_COMBILMTINFOBATCH pFun);
  /**
  * ���ò�ѯ�ʲ���Ԫ��֤ȯ��ϻص�����
  * @param[in] nHandle ���
  * @param[in] pFun ��ѯ�ʲ���Ԫ��֤ȯ��ϻص�����
  */
  void SetCallBackListCombiInfo(void* hWnd, CALLBACK_LISTCOMBIINFO pFun);
  /**
  * ���Ĺ�Ʊ����
  * @param[in] pCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int SubScribe(char* pCode);
  /**
  * �˶���Ʊ����
  * @param[in] pCode ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int UnSubScribe(char* pCode);
  /**
  * ��ȡ��Ʊ��ͨ����
  * @param[in] pCode ��Ʊ����
  * @return ������Ϣ
  */
  STK_NQ_TICK* GetNQTickInfo(char* pCode);
  /**
  * ��ȡ��Ʊ��������
  * @param[in] pCode ��Ʊ����
  * @return ������Ϣ
  */
  STK_NQ_ZSXX* GetZSTickInfo(char* pCode);
  /**
  * ��ȡί����Ϣ
  * @param[in] pOrderID ί�к�ͬ���
  * @return ί����Ϣ
  */
  ORDER_INFO* GetOrder(char* pOrderID);
  /**
  * ȡ����Ա���ʽ�
  * @param[in] nAssetID �ʲ���ԪID(0-��ʾ��ǰ�û��������ʲ���Ԫ)
  * @return ����LBM�ɹ���ʧ��
  */
  int GetFunds(int nAssetID);

  /**
  * ȡ����Ա�ĳֲ�
  * @param[in] nAssetID �ʲ���ԪID(0-��ʾ��ǰ�û��������ʲ���Ԫ)
  * @param[in] bZero �Ƿ񷵻سֲ�Ϊ0�ļ�¼
  * @return ����LBM�ɹ���ʧ��
  */
  int GetShare(int nAssetID, int bZero, char* pStkCode);

  /**
  * ���н��ױ���
  * @param[in] pQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int Quote(QUOTE_INFO* pQuoteInfo);

  /**
  * ���в��Խ��ױ���
  * @param[in] pAlgoQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int AlgoQuote(ALGOQUOTE_INFO* pAlgoQuoteInfo);
  /**
  * ���г����걨
  * @param[in] pOrderID ί�к�ͬ���
  * @param[in] chOrderType ί������
  * @return ����LBM�ɹ���ʧ��
  */
  int CancelOrder(char* pOrderID, char chOrderType);

  /**
  * ���г����걨(�������µ�¼��ĳ���) fengwc alter 9.16
  * @param[in] pOrderID ί�к�ͬ���
  * @param[in] chOrderType ί������
  * @return ����LBM�ɹ���ʧ��
  */
  int CancelOldOrder(char* pOrderID, char chOrderType);
  /**
  * �ɽ��ر�
  * @param[in] pOrderID ί�к�ͬ���
  * @return ���سɽ��ر���Ϣ
  */
  QUOTE_MATCH_INFO* GetTrade(char* pOrderID);
  /**
  * ��ѯ��֧���й�Ʊ��ί����ϸ
  * @param[in] pOrderSearch ί�в�ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_Quote(ORDER_SEARCH OrderSearch);

  /**
  * ��ʱ��β�ѯ��֧���й�Ʊ�ĳɽ���ϸ
  * @param[in] MatchSearch ί�в�ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_QuoteMatch(ORDER_SEARCH MatchSearch);

  // Add by chenmu 2015-7-27 17:00 ���ɽ���Ų�ѯ�ɽ���ϸ
  /**
  * ���ɽ���Ų�ѯ��֧���й�Ʊ�ĳɽ���ϸ���˺���ֻ������KSMM���׹�̨v1.1.0.0�����ϰ汾���Ҳ���ͬʱ����List_QuoteMatch��
  * @param[in] MatchSearch �ɽ���ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_NewMatch(MATCH_SEARCHE MatchSearch);
  // End Add

  /**
  * ��ȡ���Ի�����Ϣ
  * @param[out] pAlgoBaseInfo ����������Ϣ
  * @param[out] nAlgoBaseItems �������Ը���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAlgoBaseInfo(ALGO_BASEINFO** pAlgoBaseInfo, int& nAlgoBaseItems);

  /**
  * ��ȡ������Ϣ
  * @param[in] nAssetID �ʲ���ԪID
  * @param[out] pAlgoInfo ������Ϣ
  * @param[out] nAlgoItems ���Ը���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAlgoInfo(int nAssetID, ALGO_INFO** pAlgoInfo, int& nAlgoItems);

  /**
  * ��ȡ���Բ�����Ϣ
  * @param[in] nAlgoID ����ID
  * @param[out] pAlgoParam ���Բ�����Ϣ
  * @param[out] nAlgoParamItems ���Բ�������
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAlgoParamInfo(int nAlgoID, ALGO_INFO_EXT** pAlgoParam, int& nAlgoParamItems);

  //add by zhangshuai
  /**
  * ���ò���״̬
  * @param[in] nAlgoID ����ID
  * @param[in] chAlgoStatus ����״̬
  * @return ����LBM�ɹ���ʧ��
  */
  int SetAlgoStatus(int nAlgoID, char chAlgoStatus);
  //!< fengweican alter 5.5 ������Ӫ��Ʊ����
  /**
  * ��Ӫ��Ʊ���ױ���
  * @param[in] pQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int NQWTQuote(NQWTQUOTE_INFO* pQuoteInfo);

  /**
  * ��ѡ���Ʊ���ױ���
  * @param[in] pAlgoQuote ������Ϣ
  * @param[in] iOrderType ί������: 0 - �޼�,1-���ַ����ţ� 2-�������ţ�3-�����嵵��ʱ�ɽ�ʣ�೷�� 4-�����嵵��ʱ�ɽ�ʣ��ת�޼�
  * @return ����LBM�ɹ���ʧ��
  */
  int JxWtQuote(ALGOQUOTE_INFO* pAlgoQuote, int iOrderType);
  /**
  * ��ѯ��֧��Ӫ��Ʊ��ί����ϸ
  * @param[in] pOrderSearch ί�в�ѯ���� 
  * @return ����LBM�ɹ���ʧ��
  */
  int List_NQWTQuote(NQWTORDER_SEARCH OrderSearch);
  /**
  * ��ѯ��֧��Ӫ��Ʊ�ĳɽ���ϸ
  * @param[in] MatchSearch �ɽ���ѯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int List_NQWTQuoteMatch(NQWTMATCH_SEARCHE MatchSearch);
  /**
  * ��ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ  L3015208
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int GetList_NQWTQuote_Codes(char* pCodeList);

  /**
  * ��ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ���  L3015209
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_NQWTMatchedInfo_Codes(char* pCodeList);
  //!< fengweican alter 2.28 ���Ӵ��ڽ��״���
  /**
  * ���Ͼ���ת�ú��̺���ڽ���ת��
  * @param[in] pQuoteInfo ������Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int DZQuote(DZQUOTE_INFO* pQuoteInfo);
  /**
  * ����ת��֤ȯ�ʲ�
  * @param[in] pInfo ֤ȯ�ʲ���Ϣ
  * @return ����LBM�ɹ���ʧ��
  */
  int MovePosBatch(ST_MovePosBatch* pInfo);
  /**
  * �����޸�֤ȯ����޶�
  * @param[in] szStkCodes ֤ȯ����^�ֲ��޶���ϣ���θ�ʽ���£�֤ȯ����1^�ֲ��޶�1|֤ȯ����2^�ֲ��޶�2|֤ȯ����3^�ֲ��޶�3|����
  * @return ����LBM�ɹ���ʧ��
  */
  int SetCombiLmtInfoBatch(char* szStkCodes);
  /**
  * ��ѯ�ʲ���Ԫ��֤ȯ���
  * @param[in] nAssetID �ʲ���ԪID
  * @param[in] nCombiID ���ID
  * @param[in] szStkCode ֤ȯ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetListCombiInfo(int nAssetID, int nCombiID, char* szStkCode);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ��ί����ϸ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ί����ϸ�ص�����
  */
  void SetCallBackNQWTQuoteCodesFunction(void* hWnd, CALLBACK_NQWTQUOTE_CODES pFun);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ��Ϣ�ص�����
  * @param[in] nHandle ���
  * @param[in] pFun ί����ϸ�ص�����
  */
  void SetCallBackNQWTMatchedInfoCodesFunction(void* hWnd, CALLBACK_NQWTMATCHEDINFO_CODES pFun);
  /**
  * ������Ӫ��Ʊ���ۻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ��Ӫ��Ʊ���ۻص�����
  */
  void SetCallBackNQWTQuote(void* hWnd, CALLBACK_NQWTQUOTE pQuoteFun);
  /**
  * ���þ�ѡ���Ʊ˫�߱��ۻص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ��ѡ���Ʊ˫�߱��ۻص�����
  */
  void SetCallBackJXWTQuote(void* hWnd, CALLBACK_JXWTQUOTE pQuoteFun);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ��ί����ϸ�ص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteFun ί����ϸ�ص�����
  */
  void SetCallBackNQWTQuoteList(void* hWnd, CALLBACK_NQWTQUOTELIST pQuoteFun);
  /**
  * ���û�ȡ��֧��Ӫ��Ʊ�ĳɽ���ϸ�ص�����
  * @param[in] nHandle ���
  * @param[in] pQuoteMatchFun �ɽ���ϸ�ص�����
  */
  void SetCallBackNQWTQuoteMatchList(void* hWnd, CALLBACK_NQWTQUOTEMATCH pQuoteMatchFun);
  //add end

  /***************************fengwc alter 1.18********************************/

public:
  /**
  * ��ȡ�ֱֲ��Ʊ��Ϣ L3014026
  * @param[in] nAssetID �ʲ���ԪID
  * @param[in] pCode    ��Ʊ����
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAssetShare(int nAssetID, char* pCode);
  /**
  * ��ȡ�ϱʳֲֳɱ���Ϣ
  * @param[in] nAssetID �ʲ���ԪID
  * @param[in] szCodeList    ��Ʊ�����б�
  * @return ����LBM�ɹ���ʧ��
  */
  int GetInvStkBcostRlt(int nAssetID, char* szCodeList);
  /**
  * ��ȡ��ǰ����Ա���ܵ��ʲ���Ԫ�ʽ���ֵ��ϵͳҵ���л���־�����б�־����Ʊ���������� L3015204
  * @param[in] nAssetID �ʲ���ԪID
  * @return ����LBM�ɹ���ʧ��
  */
  int GetAcctInfo(int nAssetID);
  /**
  * ��ȡ��֧���й�Ʊ��ί����ϸ��Ϣ  L3015202
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_Quote_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�ķ�����Ϣ  L3015203
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_RiskInfo_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�ı���ʱ����Ϣ  L3015205
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_NqContRecs_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�Ŀɳ�����Ϣ  L3015206
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_WithdrawOrder_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�ĳɽ���ϸ��Ϣ  L3015207
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_QuoteMatch_Codes(char* pCodeList);

  /**
  * ��ȡ��֧���й�Ʊ�����ձ��۲�ѯ��Ϣ  L3015210
  * @param[in] pCodeList ��Ʊ�б���
  * @return ����LBM�ɹ���ʧ��
  */
  int  GetList_HisLastQuote_Codes(char* pCodeList);
  /*****************************************************/

  /*ͬ���ӿ�*/
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

