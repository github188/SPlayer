/** $Id$ $DateTime$
*  @file  bsrDvrSdkType.h
*  @brief dvr sdk 所使用的类型的声明文件
*  @version 0.0.1
*  @since 0.0.1
*  @author SongZhanjun<songzhj@bstar.com.cn>
*  @date 2009-06-01    Created it
*/
/******************************************************************************
*@note
Copyright 2007, BeiJing Bluestar Corporation, Limited
ALL RIGHTS RESERVED
Permission is hereby granted to licensees of BeiJing Bluestar, Inc. products
to use or abstract this computer program for the sole purpose of implementing
a product based on BeiJing Bluestar, Inc. products. No other rights to
reproduce, use, or disseminate this computer program,whether in part or  in
whole, are granted. BeiJing Bluestar, Inc. makes no representation or
warranties with respect to the performance of this computer program, and
specifically disclaims any responsibility for any damages, special or
consequential, connected with the use of this program.
For details, see http://www.bstar.com.cn/
******************************************************************************/

#ifndef USE_DVXSDK_TYPE_HEADER
#define USE_DVXSDK_TYPE_HEADER

#pragma warning (disable: 4200)
/**********************************************************************************/
// 句柄定义
/// DVR 句柄
typedef void*	DvxHandle;
typedef void*	IpcHandle;
/// 现场流句柄
typedef void*	RealHandle;
//  透明通道句柄
typedef void*   TunnelHandle;
/// 对讲流句柄
typedef void*	SpeechHandle;
/// 远程回放句柄
typedef void*	PlayHandle;
/// 下载句柄
typedef void*	DumpHandle;
/// 本地磁盘管理句柄
typedef void*	DiskHandle;
/// 本地回放句柄
typedef void*	LocalPlayHandle;
/// 本地回放剪辑句柄
typedef void* FileCutHandle;
/// 本地文件句柄
typedef void*	ArchiveHandle;
/// 本地下载句柄
typedef void*	LocalDumpHandle;

#ifndef InfoHandle
typedef void* InfoHandle;
#endif

#pragma pack( push, 1 )

// BSFP帧头数据格式
struct FrameHeader
{
  unsigned int mark;			  /**< 帧头的前导标识，用于帧头定位，固定值为0xBF9D1FDB */
  unsigned char type;			  /**< 帧类型标识符 1：音频 2：视频 3：语音 4: 音视频智能分析信息 9：消息通告 10: 命令请求与应答*/
  char channel;						  /**< 通道号  取值范围（-127~128）*/
  unsigned short device;	  /**< 设备出厂序列号 */
  unsigned int length;		  /**< 本帧数据(data)总长度，不包括28 个字节的帧头 */
  unsigned int sequence;	  /**< 该类型帧在该通道(channel)的序号，各类型独立计数，从系统启动后开始计数 */
  unsigned int timestamp;	  /**< 该帧捕获的系统时间，为time_t 标准时间 */
  unsigned int tick;			  /**< 该帧捕获的系统参考时钟计数(单位为微秒) */
  unsigned char codec;		
  unsigned char resolution;	/**< 分辨率 */
  unsigned char frameRate;
  unsigned char frameType;
};

// 抓图类型
enum
{
	IPC_SNAP_IMAGE_BMP	= 0x00,
	IPC_SNAP_IMAGE_JPG	= 0x01
};

//产品硬件平台型号
enum 
{
  DEV_PLATFORM_SUNFLOWER = 1,
  DEV_PLATFORM_CHALLENGER = 2,
  DEV_PLATFORM_LIMIT = 3,
  DEV_PLATFORM_LC = 4,
  DEV_PLATFORM_LOTUS = 5,
  DEV_PLATFORM_PEONY = 6,
  DEV_PLATFORM_TULIP = 7,
  DEV_PLATFORM_TULIPB = 8,
  DEV_PLATFORM_TULIPC = 9,
  DEV_PLATFORM_XARINA = 12,
}; 

//IPC能力表
enum
{
  IPCDIF_WDR =      0x80 , //宽动态 Bit8
  IPCDIF_DAYNIGHT = 0x100,   //日夜型 Bit9
  IPCDIF_BACKLIGHTCOMP = 0x200,  //背光补偿 Bit10
  IPCDIF_STRONGLIGHTCTRL = 0x400,  //强光抑制 Bit11
  IPCDIF_DIGITALNOISE = 0x800,  //数字降噪 Bit12
  IPCDIF_IA =      0x8000 , //智能 Bit16
	IPCDIF_SIP =     0x10000 , //SIP协议支持 Bit17
};

// 系统重启的返回结果
typedef enum
{
  DVX_REBOOT_STATUS_SUCCESS = 0x0000,
  DVX_REBOOT_STATUS_RECORD  = 0x0001,
  DVX_REBOOT_STATUS_BACKUP  = 0x0002,
  DVX_REBOOT_STATUS_PREVIEW = 0x0020,
  DVX_REBOOT_STATUS_PLAYBACK= 0x0040,
  DVX_REBOOT_STATUS_DUMP    = 0x0080,
  DVX_REBOOT_STATUS_SPEECH  = 0x0100,
}ERebootStatus;
typedef unsigned int RebootStatus;


// 播放模式
enum
{
	DVX_PLAY_MODE_NORMAL		= 0x00,
	DVX_PLAY_MODE_PERFRAME	= 0x01,
	DVX_PLAY_MODE_IFRAME		= 0x02,
};

enum upload_stat_bitmap/** 上传状态的位 */
{
  bit_cur_system_time         = 0x00000001,
  bit_system_run_time         = 0x00000002,
  bit_load_perminute             = 0x00000004,
  bit_load_per5minutes           = 0x00000008,
  bit_load_per15minutes          = 0x00000010,
  bit_system_total_mem        = 0x00000020,
  bit_system_free_mem         = 0x00000040,
  bit_buffer_mem              = 0x00000080,
  bit_total_swap              = 0x00000100,
  bit_free_swap               = 0x00000200,
  bit_process_count           = 0x00000400,
  bit_camera_stat             = 0x00000800,
  bit_user_count              = 0x00001000,
  bit_video_count             = 0x00002000,
  bit_SD_stat                 = 0x00004000,
  bit_cur_code_rate           = 0x00008000,
  bit_earlist_videotime       = 0x00010000,
  bit_SD_total_size           = 0x00020000,
  bit_SD_left_size            = 0x00040000,
};

// Enable
#define DVX_ENABLE			1
#define DVX_DISABLE			0

/// 可写文件类型
typedef enum
{
  DVX_FILETYPE_BSA	= 1,
  DVX_FILETYPE_BSK	= 2,
  DVX_FILETYPE_BSN	= 3,
  DVX_FILETYPE_BSX	= 4,
  DVX_FILETYPE_MP4	= 5,
}EDvxFileType;

/// 文件打开模式
#define		DVX_OPENMODE_CREATE	(0)
#define		DVX_OPENMODE_APPEND	(1)


///最大事件数目
#define  DVX_MAX_EVENT_NUMBER  4096
#define  DVX_MAX_ALARM_PAYLOAD 1024*256
#define  DVX_MAX_ALARMPIC_PAYLOAD 1024*256

struct TimeRange
{
	unsigned int beginTime;    //起始时间
	unsigned int endTime;      //结束时间
};

/// 所有流列表
struct StreamInfo
{
	int streamId;
	int sessionId;
	int chnnlNum;
	int protocol;
	int srcAddr;
	int srcPort;
	int dstAddr;
	int dstPort;
	int status;		// UNUSED(0)/OPEN(1)/START(2)/STOP(3)/CLOSE(4)
	int time;
};

struct StreamInfoList
{
	StreamInfo info[80];
	int count;
};

typedef enum
{
  DVX_STREAM_STATUS_UNUSED = 0,
  DVX_STREAM_STATUS_OPEN = 1,
  DVX_STREAM_STATUS_START = 2,
  DVX_STREAM_STATUS_STOP = 3,
  DVX_STREAM_STATUS_CLOSE = 4,
}EDvxStreamState;
/// 流状态参数
struct StreamState
{
	int idReal;			// 流标识
	int status;			// UNUSED(0)/OPEN(1)/START(2)/STOP(3)/CLOSE(4)
	int xmit;				// 数据传输的连接状态: OFF(0)/ON(1)
	int cause;			// 引超上述状态的原因
	__int64 bytes;	// 本下载流已传输的累积字节数
};

/** @addtogroup grReal
*  @{
*/
/// 现场流打开参数
struct RealOpenPara
{
	char channel;     ///.通道号，1-16表示1-16通道。 
	char subStream;   /// 0表示主码流，1表示子码流。
  char transProc;   /// 传输协议: 1, TCP，4RTP
	char transMode;   /// 
	int  ip;
};
///打开透明通道数据流
struct TunnelOpenPara
{
	int devId;			//设备号: RS232-1(1)|RS232-2(2)|RS485-1(3)|RS485-2(4)|
	int protocol;		//1: TCP 4: UDP(RTP) 暂不支持
	int ip;				//IP地址,被动时为零，
};
//现场视频叠加
typedef struct 
{
  bool bDrawCap;
  HBITMAP hBitmapCap;
  int  nOffset;
}RealDrawPara;
/// SDK的网络协议
enum
{
	DVX_PROTOCAL_TCP						= 1,
	DVX_PROTOCAL_UDP_UNICAST		= 2,
	DVX_PROTOCAL_UDP_MULTICAST	= 3,
	DVX_PROTOCAL_RTP						= 4,
};

/// 数据传输模式
#define	DVX_TRANSMODE_PASSIVE		1   // 
#define	DVX_TRANSMODE_ACTIVE		2

/// 码流的参数
#define DVX_STREAM_PRI					0
#define DVX_STREAM_SUB					1
#define MAX_BITRATE_NUM                 8 

///云台控制命令
#define 	DVX_PTZCRL_CMD_STOP		0     //停止

#define 	DVX_PTZCRL_CMD_PAN		1	    //摆动

///摆动方向控制参数
enum
{
	DVX_PTZCRL_CMD_PAN_LEFT       = 1,  //左摆
	DVX_PTZCRL_CMD_PAN_RIGHT      = -1, //右摆动
	DVX_PTZCRL_CMD_PAN_RESET      = 0,  //摆动复位
};

#define 	DVX_PTZCRL_CMD_TILT		2     //俯仰
///俯仰方向控制参数
enum
{
	DVX_PTZCRL_CMD_TILT_UP        = 1,  //向上
	DVX_PTZCRL_CMD_TILT_DOWN      = -1, //向下
	DVX_PTZCRL_CMD_TILT_RESET     = 0,  //复位
};

#define 	DVX_PTZCRL_CMD_ZOOM		3			//缩放
///缩放控制参数
enum
{
	DVX_PTZCRL_CMD_ZOOM_AUTO      = 0,  //自动
	DVX_PTZCRL_CMD_ZOOM_WIDE      = 1,  //放大
	DVX_PTZCRL_CMD_ZOOM_TELE      = -1,	//缩小
};

#define 	DVX_PTZCRLL_CMD_FOCUS	4			//焦距
///焦距调整参数
enum
{
	DVX_PTZCRLL_CMD_FOCUS_AUTO    = 0,  //自动
	DVX_PTZCRLL_CMD_FOCUS_NEAR    = 1,  //缩近
	DVX_PTZCRLL_CMD_FOCUS_FAR     = -1, //远距
};

#define   DVX_PTZCRL_CMD_IRIS		5			//光圈
///光圈调整参数
enum
{
	DVX_PTZCRL_CMD_IRIS_AUTO      = 0,  //自动
	DVX_PTZCRL_CMD_IRIS_OPEN      = 1,  //打开
	DVX_PTZCRL_CMD_IRIS_CLOSE     = -1, //关闭
};


#define DVX_PTZCRL_CMD_SWAY    6
//斜向摆动参数
enum
{
  DVX_PTZCRL_CMD_SWAY_TOPLEFT = 3,
  DVX_PTZCRL_CMD_SWAY_BOTTOMRIGHT = -3,
  DVX_PTZCRL_CMD_SWAY_TOPRIGHT = 4,
  DVX_PTZCRL_CMD_SWAY_BOTTOMLEFT = -4,
};

#define   DVX_PTZCRL_CMD_AUTOSCAN		7 //自动扫描

#define 	DVX_PTZCRL_CMD_AUX_I			8	//辅助一
#define 	DVX_PTZCRL_CMD_AUX_II			9	//辅助二
///辅助I II开关参数
#define 	DVX_PTZCRL_CMD_AUX_OPEN   1 //辅助(I / II)打开
#define 	DVX_PTZCRL_CMD_AUX_CLOSE  0	//辅助(I / II)关闭

#define   DVX_PTZCRL_CMD_PANSPEED   11//摆动速度
///摆动速度控制参数
enum
{
	DVX_PTZCRL_CMD_PANSPEED_I     = 1,	//摆动速度
	DVX_PTZCRL_CMD_PANSPEED_II    = 2,  //摆动速度1
	DVX_PTZCRL_CMD_PANSPEED_III   = 3,  //摆动速度2
	DVX_PTZCRL_CMD_PANSPEED_IV    = 4,  //摆动速度3
	DVX_PTZCRL_CMD_PANSPEED_V     = 5,  //摆动速度4
};

#define   DVX_PTZCRL_CMD_TILTSPEED 12	//俯仰速度
///俯仰速度控制参数(速度级别)
enum
{
	DVX_PTZCRL_CMD_TILTSPEED_I    = 1,		
	DVX_PTZCRL_CMD_TILTSPEED_II   = 2, 		
	DVX_PTZCRL_CMD_TILTSPEED_III  = 3,		
	DVX_PTZCRL_CMD_TILTSPEED_IV   = 4,		
	DVX_PTZCRL_CMD_TILTSPEED_V    = 5,	
};

#define   DVX_PTZCRLL_CMD_FOCUSSPEED 13	//聚焦速度
///聚焦速度控制命令参数(速度级别)
enum
{
	DVX_PTZCRLL_CMD_FOCUSSPEED_I   = 1,		 
	DVX_PTZCRLL_CMD_FOCUSSPEED_II  = 2,	   
	DVX_PTZCRLL_CMD_FOCUSSPEED_III = 3,		  
	DVX_PTZCRLL_CMD_FOCUSSPEED_IV  = 4,		
	DVX_PTZCRLL_CMD_FOCUSSPEED_V   = 5,		
};

#define   DVX_PTZCRLL_CMD_ZOOMSPEED  14	//缩放速度		
///缩放速度控制命令参数(速度级别)
enum
{
	DVX_PTZCRLL_CMD_ZOOMSPEED_I   = 1,			
	DVX_PTZCRLL_CMD_ZOOMSPEED_II  = 2,				
	DVX_PTZCRLL_CMD_ZOOMSPEED_III = 3,			
	DVX_PTZCRLL_CMD_ZOOMSPEED_IV  = 4,		
	DVX_PTZCRLL_CMD_ZOOMSPEED_V   = 5,				
};

///预置位命令</* arg 参数取值为1-255 预置位编号*/>
enum
{
	DVX_PTZCRL_CMD_PRESETCLEAR = 20,	  //预置位清除
	DVX_PTZCRL_CMD_PRESETGOTO	 = 21,	  //预置位使用
	DVX_PTZCRL_CMD_PRESETSET	 = 22,	  //预置位保存
};

enum
{
	DVX_PTZCRLL_CMD_TRACESTOP  = 30,		//轨迹运行停止
	DVX_PTZCRLL_CMD_TRACESTART = 31,		//轨迹运行开始
	DVX_PTZCRLL_CMD_TRACEBEGIN = 32,		//轨迹记录开始
	DVX_PTZCRLL_CMD_TRACEEND   = 33,		//轨迹记录
};

///巡航命令
///</* 以下四个命令arg 参数取值为1-16 巡航路径*/>
enum
{
  DVX_PTZCRLL_CMD_PATROLSTOP       = 40,  // 巡航停止
	DVX_PTZCRLL_CMD_PATROLSTART      = 41,	// 巡航开始
	DVX_PTZCRLL_CMD_PATROLROUTEDEL   = 42,	// 巡航路径删除
	DVX_PTZCRLL_CMD_PATROLROUTEBEGIN = 43,	// 巡航路径修改开始
	DVX_PTZCRLL_CMD_PATROLROUTEEND   = 44,	// 巡航路径修改结束
};

#define DVX_PTZCRLL_CMD_BRUSH     51  // 雨刷
enum
{
	DVX_PTZCRLL_CMD_BRUSH_OFF     = 0,	//关闭
	DVX_PTZCRLL_CMD_BRUSH_ON      = 1,  //打开
};
#define DVX_PTZCRLL_CMD_LIGHT      52	// 灯光
enum
{
	DVX_PTZCRLL_CMD_LIGHT_OFF     = 0,	//关闭
	DVX_PTZCRLL_CMD_LIGHT_ON      = 1,  //打开
};

// 扫描
#define   DVX_PTZCRLL_CMD_SCAN_LEFT     60
#define   DVX_PTZCRLL_CMD_SCAN_RIGHT    61
#define   DVX_PTZCRLL_CMD_SCAN_START    62
#define   DVX_PTZCRLL_CMD_SCAN_CLOSE    63

// 水平旋转
#define   DVX_PTZCRLL_CMD_ROTATE_START  70
#define   DVX_PTZCRLL_CMD_ROTATE_CLOSE  71

///检索条件key值
enum
{
	DVX_SEARCH_KEY_CHANNEL = 1,     //按通道
	DVX_SEARCH_KEY_TIME    = 2,     //时间段
	DVX_SEARCH_KEY_TYPE    = 3,		  //录像起因类型
	DVX_SEARCH_KEY_DISK    = 4,		  //录像存储位置
	DVX_SEARCH_KEY_ALBUM   = 5,     //磁盘组编号
	DVX_SEARCH_KEY_CARD    = 6,     //卡号
	DVX_SEARCH_KEY_ATM     = 7,     //ATM交易信息
	DVX_SEARCH_KEY_AI      = 11,    //智能信息
};

///跳转类型
enum
{
	DVX_SEEK_TYPE_LENGTH = 1,
	DVX_SEEK_TYPE_TIME   = 2,
	DVX_SEEK_TYPE_FRAME  = 3,
};

///跳转基准
#define   DVX_SEEK_START 0
#define   DVX_SEEK_END   1

///回放参数选择
#define   DVX_PLAYBACK_SET_KEY_FREETIME      2

#define   DVX_PLAYBACK_SET_KEY_KEEP          3

#define   DVX_PLAYBACK_SET_KEY_KEEP_FALSE    0
#define   DVX_PLAYBACK_SET_KEY_KEEP_TRUE     1

#define   DVX_PLAYBACK_SET_KEY_WITHSOUND     1
#define   DVX_PLAYBACK_SET_KEY_WITHOUTSOUND  0
#define   DVX_PLAYBACK_SET_KEY_SPEEDCONTROL  61

#define		DVX_XLATE_TM_SZ  1
#define		DVX_XLATE_SZ_TM  2

///日志相关
#define   MAX_FILE_READ    (16*1024)

//语言选择
#define   DVX_LANGUAGE_ZH_CN    1
#define   DVX_LANGUAGE_EN_US    2


/// 现场流的配置参数
struct RealParameter
{
	int cmd;				/**< 命令 */
	int value;			/**< 命令值 */
};

/** @}*/	// end of addtogroup grReal

/** @addtogroup grSearch
*  @{
*/

//智能
struct IACond
{
  char type;
  char behavior;
  short arg;
  unsigned int algs[8]; //按照IVSType定义，BITMAP形式，共256 bits。某一种IVSType对应取值为algs[(IVSType - 1) /32]的第[IVSType % 32]位。
  int res;
};

//交易信息
struct AtmTrans
{
	char  meta[4];  //meta[0]=1 
	char  card[16];  //	BCD 卡号) 结尾1111以
	int transType; //0为伍 取款1 存款2 转账3 修改密码4 查询5
	unsigned int atmTime; //0为忽略
	char atmID[8];  
	char  transID[16];
	int amountOp;
	double amount1;
	double amount2;
	int balanceOp;
	double balance1;
	double balance2;
};

//查询条件
typedef union ArcQueryValue
{
  unsigned int channel;
  TimeRange timeRange;
  unsigned int type;
  unsigned int disk;
  IACond iaCond;
  char   data[56];
} ArcQueryValue;

//ATM查询条件
typedef union ArcQueryValueATM
{
	unsigned int channel;
	TimeRange timeRange;
	unsigned int type;
	unsigned int disk;
	AtmTrans atmTrans;
	IACond iaCond;
	char   data[248];
} ArcQueryValueATM;

struct ArcCond
{
  char key;
  char op;
  char res[6];
  ArcQueryValue value;
};

struct ArcCondATM
{
	char key;
	char op;
	char res[6];
	ArcQueryValueATM value;
};

typedef enum
{
  DVX_FILE_TYPE_ALL     = 0,
  DVX_FILE_TYPE_MANUAL  = 1,
  DVX_FILE_TYPE_TIME    = 2,
  DVX_FILE_TYPE_DETECT  = 3,
  DVX_FILE_TYPE_ALARM   = 4,
  DVX_FILE_TYPE_CARD    = 5,
  DVX_FILE_TYPE_LOSS    = 6,
  DVX_FILE_TYPE_MASK    = 7,
  DVX_FILE_TYPE_INTEL   = 11,
}EDVX_FILE_TYPE;

///事件查询打开
struct ArchEventOpts
{
  char res[7];        //保留
  char count;         // 条件个数
  ArcCond condList[16];
};

///事件查询打开
struct ArchEventATMOpts
{
	char res[7];        //保留
	char count;         // 条件个数
	ArcCondATM condList[16];
};

struct ArcLocation
{
  char diskNo;      // 磁盘序号
  char partNo;      // 分区序号
  char isEvenRound; // 奇偶轮次
  char res;         // 保留
  short recordBlockOffset;  // 录像块内偏移
  short recordBlockNo; // 录像块号
  long long startPos;   // 起始位置
};

struct ArcItem
{
  long long     id;             //事件唯一索引
  char     type;                //起因事件类型
  char     subtype;             //子类型
  char     timeShift;           //时间偏移
  char     channel;             //通道
  char     profile;             //画质分辨率
  char     disk;                //磁盘
  unsigned short  period;       // 时长（秒）
  int      timeReverseNo;       // 时间翻转序号
  unsigned int    beginTime;    //开始时间
  unsigned long long size;      // 字长（字节）
  ArcLocation location;         //虚拟物理地址
};

struct SDArcItem
{
	long long     id;             //事件唯一索引
	char     type;                //起因事件类型
	char     subtype;             //子类型
	unsigned short  period;       // 时长（秒）
	unsigned int    beginTime;    //开始时间
	unsigned long long size;      // 字长（字节）
	unsigned char location[32];         //虚拟物理地址	
	char     profile;             //画质分辨率
	unsigned char res[7];
};

///结果集导航， 获取单页结果
struct FetchResult
{
  unsigned int queryId;
  unsigned int total;       //记录总数
  char version;
  char res[3];
  int          rowId;       //起始行编号	
  unsigned int rowcount;    //本页实际记录数
  ArcItem rowList[50];
};

///结果集导航， 获取单页结果
struct FetchResultIpcSD
{
	unsigned int queryId;
	unsigned int total;       //记录总数
	char version;
	char res[3];
	int          rowId;       //起始行编号	
	unsigned int rowcount;    //本页实际记录数
	int          res1;
	SDArcItem    rowList[50];
};


struct FsImageLocation
{
	unsigned long long seq; //序列号 
	char diskNo; //磁盘号 
	char partNo; //分区号 
	char res[22]; //保留
};
struct VMFSImageItem
{
	long long id; /*event identifier. */ 
    unsigned int type; /*event type. */ 
    unsigned int subtype; /*event sub type. */ 
	char channel; /*channel for event.*/ 
	char profile; /*vedio format. */ 
	char disk; /*the disk to save the event. */ 
	char res1[1]; 
	unsigned int time; /*start time. */
	char res2[8];
	unsigned long long size; /* size for the event.*/ 
	FsImageLocation location; /*start pos for record disk.*/
};

typedef struct
{
  long long id;         /* identifier.  */
  char type;       /*event type. */
  char subtype;  /*event sub type. */
  char profile;  /* image format */ 
  char res1 ;
  unsigned int time;        /*start time. */
  unsigned long long size;
	unsigned int EvtType; /*event type. 多Event 类型替换type 参数*/
  char res2[4] ;
}SDFSItem;

typedef union
{
	unsigned char data[128]; //占位符
	VMFSImageItem vmfsItem; //VMFS存储的图片Item
	SDFSItem sdfsItem; //待定，预留给将来的SD卡图片item
}ArcPicItem;
//图片查询结果集导航，获取一页结果集(NVR扩展)
struct PicFetchResult
{
	unsigned int queryId; //
	unsigned int total; // 记录总数
	char itemType; //每行的记录类型：VMFS(1) | SDFS(2)，决定rowList如何解释
	char version;
	char res[2]; 
	int rowId; //起始行编号
	unsigned int rowCount; //本页实际记录个数
	ArcPicItem rowList[50];
};
struct EventNarrowOpt
{
  int           channel;    //通道(1-16) 
  unsigned int  time;       //时间，0为当前 
  int           timeDiff;   //时间方向(单位为秒，大于0向后，小于 0向前) 
  unsigned int  rowCount;   //期望记录个数(1-50)   
};

struct EventNarrowResult
{
  int           channel;    //通道(1-16) 
  unsigned int  time;       //时间，0为当前 
  int           timeDiff;   //时间方向(单位为秒， 大于0向后小于0向前) ,实际时间差   
  unsigned int  rowCount;   //本页实际记录个数   
  ArcItem       rowList[50];     
};

///时间分布图
struct TimeLine
{
  unsigned int   begintime; //开始时间
  unsigned short period;    //持续时长
  char           type;      //手工(1) | 定时(2)| 侦测(3)|报警(4)| 卡号(5)| 智能(11)
  char           flags;     //保留
};

//录像事件描述
struct EventPlotOpts
{
  char    res[7];     
  char    condCount;
  ArcCond condList[16];
};

//录像事件描述
struct EventPlotATMOpts
{
	char    res[7];     
	char    condCount;
	ArcCondATM condList[16];
};

//事件分布列表
struct EventPlotResult
{
  unsigned int total;
  TimeLine     timelineList[DVX_MAX_EVENT_NUMBER];
};

///通道日历
struct EventCalendar
{
  int channel;
  int year;
  int month;
};

//
struct EventCalendarList 
{
  int          channel;
  int          year;
  int          month;
  unsigned int monthView;
};

///时间详细信息
struct EventDescribe
{
  ArcItem item;
  char    data[56];
};

///单位换算
struct EventXlate
{
  ArcItem   item;
  int       channel;
  int       mode;
  long long origin;
  long long extent;
};
//单位换算(NVR扩展)
struct EventPicXlateIn
{
	int channel;//通道(1-32)
	int mode;//转换模式：// TM_SZ(1)|SZ_TM(2)，目前只支持TM_SZ
	long long origin;//转换前的起始点
	long long extent;//转换前的范围(长度)
	char itemType; //每行的记录类型：VMFS(1) | SDFS(2)，决定rowList如何解释
	char res[7]; //
	ArcPicItem event; //转换的基准eventTM: origin: 标准时间(time_t)extent: 时长(秒)SZ: origin: 起始点(字节)extent: 长度(字节)

};
struct EventPicXlateOut
{
	int channel;//通道(1-32)
	int mode;//转换模式：// TM_SZ(1)|SZ_TM(2)
	long long origin;//转换后的起始点
	long long extent;//转换后的范围(长度)

};
#define EVENTXLATE_MODE_TM_SZ   (1)   // TM:时间， SZ:大小
#define EVENTXLATE_MODE_SZ_TM   (2)

//查询时间
struct TimeSpan
{
  unsigned int beginTime; //起始时间
  unsigned int endTime;   //结束时间
};

//查询条件
struct ArchItem
{
  char key;
  char op;     //运算符
  char value[30];
};

/// 检索输入参数
struct ArchListOpts
{
  int      page;  /**< 为期望结果集返回的页码，1表示首页，-1表示末页，超过最大值返回末页;页尺寸固定为50(pagzeSize=50),*/
  int      count;
  ArchItem item[8];
};

//录像信息
struct Clip
{
  char             index[64]; //录像段唯一索引,名称
  unsigned int     time;      //开始时间
  unsigned int     period;    //时间长度(秒)
  unsigned __int64 size;      //字长(字节)
  char             type;      //起因类型
  char             chnnl;     //通道
  char             disk;      //磁盘
  char             flags;     //保留
  char             res[4];    //保留,确保每个Clip的8bytes的对齐
};

//检索输出参数
struct ClipList
{
  int  pageCount; //总页数
  int  curPage;   //当前页码
  int  total;     //记录总数
  int  curCount;  //本页记录个数
  Clip clips[50];
};

//文件描述查询输入参数
struct ArchDesCond
{
  char     index[64]; //录像段唯一索引,见Archive.list返回
  int      count;
  ArchItem ArchItems[18];
};

//文件描述查询信息输出参数
struct ArchDesInfo
{
  char         index[64];   // 录像段唯一索引,见Archive.list 返回
  int          channel;
  unsigned int time;
  int          count;
  ArchItem     ArchItems[16];
};

//录像片段
struct Slice
{
  unsigned int beginTime; //开始时间
  unsigned int endTime;   //结束时间
  char         type;      //1=录像；2=时间；3=运动量
  char         res;
  short        val;
};

///通道录像状态与时间分布；
struct ArchPlotOpts
{
  int          chnnl;
  unsigned int beginTime;
  unsigned int endTime;
};

///录像时间段转换文件长度偏移
struct DvrRecordTimeToLen
{
  int          type;
  int          channel;
  char         fileIndex[64];
  unsigned int beginTime;
  unsigned int endTime;
  __int64      beginPos;
  __int64      offset;
};

///定时备份参数
struct  BackupDest   
{ 
  int  drive;      //目的盘：USB(1)|DVD(2) 
  char partition;  //目的FDISK 分区： 
  char format;     //BSR(1)|MP4(2)   
  char res[2];     // 
}; 

enum
{
  DVX_BACKUP_REPREAT_DAILY     = (1),
  DVX_BACKUP_REPREAT_WEEKLY    = (2),
  DVX_BACKUP_REPREAT_MONTHLY   = (3),
  DVX_BACKUP_REPREAT_ONCE      = (0),
};

//备份计划
struct BackupPlan   
{ 
  char repreat;   //重复方式: 	//DAILY(1)|WEEKLY(2)| MONTHLY(3)|ONCE(0) 
  char days;      //DAILY: 1-7; WEEKLY:  bit1=星期一,...,bit7=星	期日    
  char res[2];
  unsigned int execTime;  //执行时间，距离凌晨0点的秒数;
}; 

//备份具体时间
struct BackupEntity   
{ 
  unsigned int channels;  //录像通道 bitmap 
  char         type;      //录像性质(0为全部) 
  char         isCard;
	char         res;    
  char         stretch;   //录像延伸时间(天) 
	AtmTrans     atmTrans;
  unsigned int startTime; //录像开始时间(s) 
  unsigned int endTime;   //录像结束时间(s) 
	unsigned int cardNoOffset;
};

typedef union UnionBackupCond
{
  struct AtmTrans atmCond; //仅当type 为卡号(5) 时有效
  unsigned int vcaAlgsCond[8]; //最大256 种智能算法，BITMAP
}BackupCond;

//备份具体时间
struct BackupEntityEX   
{ 
  unsigned int channels;  //录像通道 bitmap 
  char         type;      //录像性质(0为全部) 
  char         isCard;
  char         res;    
  char         stretch;   //录像延伸时间(天) 
  BackupCond condition;  //各种性质的查询条件
  unsigned int startTime; //录像开始时间(s) 
  unsigned int endTime;   //录像结束时间(s) 
  unsigned int cardNoOffset;
};

//备份参数
struct BackupPara
{
  int          taskId;        //固定为 1   
  char         eabled;        //开关
  char         res[3];
  BackupEntity backupEntity;  //备份媒体内容 
  BackupDest   backupDest;    //备份目的地 
  BackupPlan   backupPlan;    //备份时间计划 
};

//备份参数
struct BackupParaEX
{
  int          taskId;        //固定为 1   
  char         eabled;        //开关
  char         mediatype;     // 录像(0)| 图片(1)	 
  char         res[2];
  BackupEntityEX backupEntity;  //备份媒体内容 
  BackupDest   backupDest;    //备份目的地 
  BackupPlan   backupPlan;    //备份时间计划 
};
/** @} */	// end of addtogroup grSearch

struct RecordClip
{
  unsigned int startTime;
  unsigned int endTime;
};

enum
{
  DVX_INDEXTYPE_DVX6 = 1,
  DVX_INDEXTYPE_DVX7_EVENT = 2,
  DVX_INDEXTYPE_DVX7_CLIP = 3,
  DVX_INDEXTYPE_DVX7_IPC = 4,
};

struct VideoSlicePara
{
	unsigned int startTime; //开始时间
	unsigned int endTime;   //结束时间
	unsigned int gap;       //切片间隔
};

typedef union
{
	char    file[64];   // idxType = 1, 仅Ipc6使用
	ArcItem item;       // idxType = 2, dvx77中事件的描述信息
	RecordClip clip;    // idxType = 3, 起止时间的描述
	SDArcItem sdItem;   // idxType = 4 Ipc中事件的描述信息
	VideoSlicePara slice;
}index_t;

//图片回放中index_t
typedef union
{
	char    file[1024];   // idxType = 1, 仅Dvr6使用
	VMFSImageItem item;       // idxType = 2, Dvr7中事件的描述信息
	RecordClip clip;    // idxType = 3, 起止时间的描述
	SDFSItem sdfsItem;  // IPC 中 SD卡上的录像事件描述信息
}Imageindex_t;

/** @addtogroup grRecordPlay 
 *  @{
 */
 ///录像回放打开参数
struct RecordPlayOpenPara
{
	int  channel;
  int  protocol;
	int  ip;
  int  idxType; // index的类型
  index_t index;
  unsigned int beginTime;
  __int64 peroid;  
  int  byteRate;
};
///图片回放打开参数
struct ImagePlayOpenPara
{
	int  channel;
	int  protocol;
	int  ip;
	int  idxType; // index的类型
	Imageindex_t index;
	unsigned int beginTime;
	__int64 peroid;  
	int  byteRate;

};

///录像回放打开参数(NVR扩展)
struct RecordPlayOpenParaEx
{
	int				channel;
	int				protocol;
	unsigned int	isStreamConverted;	//0: 不转码 1: 转码，下列转码相关属性，只在转码时有效
	unsigned int	sourceResolution;	//下列BITMAPQCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) | 1080P(14)在当前版本中，只有720P和1080P两位可被配置
	unsigned char	destResolution;		//非BITMAPQCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) | 1080P(14)在当前版本中，只有CIF或者D1可以被配置
	unsigned char   destFrameRate;		//0: 维持原始帧率100: 只转I帧1-30: 在当前版本中，只有0(维持原始帧率)可以使用
	unsigned short	destBitrate;		//单位是kbps
	unsigned char	res;				//保留
	int				ip;
	int				idxType; // index的类型
	index_t			index;
	unsigned int	beginTime;
	__int64			peroid;
	int           byteRate;
};

/** @addtogroup grRecordDumpBscpSunflower        
*  @{
*/
/// 现场管理Open命令的输入参数
struct RecordDumpOpenIn_Sunflower_SD
{
	int channel;			/**< 通道号1-16 */
	int protocol;			/**< 1-TCP */
	unsigned int ip;	/**< ip地址，被动时为0 */
	int port;	/**< 端口号，默认3721，被动时为0, 主机字节序 */
	int idxType;      ///< 指示index字段的类型: 1, file, only ipc6 used, 2, event, ipc7 enent des info, 3, clip, time des
	int res;
	char index[64];
	unsigned __int64	offset;		/**< 录像段开始的偏移量 */
	unsigned __int64	length;		/**< 长度 */
	int			byterate;
	int			format;
};
/// 对讲管理Open命令的输出参数
struct RecordDumpOpenOut_Sunflower_SD
{
	int sessionId;
	int dumpId;
	int channel;
	int protocol;
	int ip;
	int port;
	int idxType;
	int res;
	char index[64];
	unsigned __int64 offset;
	unsigned __int64	length;
	int byteRate;
	int format;
};

struct RecordPlayParam
{
	int key;
	int value;
};
struct ImagePlayParam
{
	int key;
	int value;

};
/** @}*/	// end of addtogroup grRecordPlay

/** @addtogroup grSyslog 
 *  @{
 */
///日志打开参数
struct SyslogOpenOpts
{
	unsigned int startTime; //时间段的起始时间
	unsigned int endTime;		//时间段的结束时间
	char type;              /*< 日志类型: (0)所有( DVX_LOGTYPE_ALL)
										               (1)系统日志(DVX_LOGTYPE_SYSTEM) 
										               (2) 报警日志(DVX_LOGTYPE_ALARM)
																	 (3)管理日志(DVX_LOGTYPE_ADMIN) 
										               (4)操作日志(DVX_LOGTYPE_OPERATOR)
																	 (5) 视频日志(DVX_LOGTYPE_VEDIO)>
																	 (6)设备维保（上海深广）*/
	char level;             //级别
	unsigned char disk;     // BITMAP: 0,所有磁盘,BIT(1)A盘--BIT(8)H盘
	unsigned char disk2;    // BITMAP: BIT(1)I盘--BIT(8)P盘 disk和disk2都为0时表示所有磁盘
	char user[16];
};
#define   DVX_LOG_ORDER_DESC   (0)
#define   DVX_LOG_ORDER_ASC    (1)
#define   NVR_LOG_INFO_MAX_LENGTH 1024*4

enum
{
	DVX_LOGTYPE_ALL     = 0,
	DVX_LOGTYPE_SYSTEM  = 1,
	DVX_LOGTYPE_ALARM   = 2,
	DVX_LOGTYPE_ADMIN   = 3,
	DVX_LOGTYPE_OPERATOR= 4,
	DVX_LOGTYPE_VEDIO   = 5,
};

struct SysLog	 
{
	unsigned int time; //应用层不用填写----when
	char type;
	char level;
	char action;       //操作名称--how
	char result;       //操作结果
	int target;        //操作对象（通道号/磁盘号,可用bitmap--what
	char user[16];
	char msg[56];      //字符串描述
};
struct SysLogEx
{
	char magic[4];		//为固定值{‘L’, ‘O’, ‘G’, ‘\0’}，用来标记每一个SysLogEx的起始位置。
						//引入magic字段的作用是，一旦在offsets指向
	unsigned int time; //应用层不用填写----when
	char type;
	char level;
	char action;       //操作名称--how
	char result;       //操作结果
	int target;        //操作对象（通道号/磁盘号,可用bitmap--what
	char user[16];	   //！用户
	unsigned short length; //msg长度，建议4字节对齐
	unsigned char res[2]; //保留
	char msg[NVR_LOG_INFO_MAX_LENGTH]; //字符串描述，包含结束符’\0’
};
///清空日志给定条件
struct  SyslogPurgeOpts
{
	unsigned int startTime;
	unsigned int endTime;
	char type;
	char level;
  unsigned char disk;     // BITMAP: 0,所有磁盘,BIT(1)A盘--BIT(8)H盘
  char res;
};
//获取硬盘SMART日志的入参详细信息
struct SlFetchHDSMARTInPara
{
	char msg[48];//从(0x0000.aa13)System.Log.fetchEx命令中获取的日志信息
};
struct SlVmfsSmartAttr
{
	unsigned char	id;
	unsigned char	res[3];
	char			attrName[32];
	unsigned int	flag;
	unsigned char	value;
	unsigned char   worst;
	unsigned char	thresh;
	char			type;
	char			updated;
	char			whenFailed;
	char			failed;
	char			res2;
	unsigned long long		rawValue;
};
struct SlVmfsSmartErrorLog
{
	int errNo;
	int time;
	char errCode[12];
	int sectCount;
	unsigned long long lba;
	char res[8];
};
struct SlVmfsSmartData
{
	SlVmfsSmartAttr attr[60];
	SlVmfsSmartErrorLog errlog;
	char res[64];
};
struct SlFsSmartDetailInfo
{
	int time;
	int slot;
	char serial[32];
	char model[32];
	char firmwareVer[24];
	SlVmfsSmartData smartdata;
	char res[16];
};
 //获取硬盘SMART日志的出参详细信息
struct SlFetchHDSMARTOutPara
{
	SlFsSmartDetailInfo info;
};
///日志输出参数
struct SyslogListInfo
{
	int total;         //符合条件的总记录数
	int rowId;         //起始行编号
	int rowCount;      //本页的实际记录个数
	SysLog    SyslogList[50];
};
//日志输出参数（扩展命令）
struct SyslogListInfoEx
{
	int total;         //符合条件的总记录数
	int rowId;         //起始行编号
	int rowCount;      //本页实际记录个数(0-50)
	unsigned int offsets[50];//每条日志在SysLogList内存中的起始偏移位置
	SysLogEx SyslogList[50];
};

struct SyslogExportPara 
{
	time_t startTime;    //时间段的起始时间 
	time_t endTime;      //时间段的结束时间 
	char type;     
	char level;         //！级别 
  unsigned char disk;     // BITMAP: 0,所有磁盘,BIT(1)A盘--BIT(8)H盘
  char res;
};
struct SyslogExportInfo
{
	char file[32];
	int length;
	char data[MAX_FILE_READ];
};
/** @}*/	// end of addtogroup grSyslog

/** @addtogroup grDisk
 *  @{
 */
struct DiskStatus   
{ 
	char usage;                  /*<!使用方式：   NA   DVX_STORAGE_DISK_NOEXIST	
															               录像盘  DVX_STORAGE_DISK_USETYPE_RECORD
																					   冗余盘  DVX_STORAGE_DISK_USETYPE_REDUNDANCE 
																						 备份盘  DVX_STORAGE_DISK_USETYPE_BACKUP 
                                             未格式化DVX_STORAGE_DISK_USETYPE_UNFORMAT
                                             坏盘    DVX_STORAGE_DISK_USETYPE_BADDISK
                                             未配置  DVX_STORAGE_DISK_USETYPE_UNCONFIG
																						 */  
	char album;                  //所属磁盘组 </*1-8 为硬盘， 9为USB_DISK, 10为USB_DVD*/>
	char awake;                  //!唤醒状态(存于内存)： 休眠(DVX_STORAGE_DISK_STATE_SLEEP) |唤醒(DVX_STORAGE_DISK_STATE_AWAKEN) 
	char active;                 //是否为活动盘/写入盘(存于Meta和内存) 
	char imgPartitionPercents; //图片分区容量百分比(0-100)，仅对录像盘和未配置盘有效。
	char res[2]; //    
	char  layout;                // 磁 盘 分 区 方 式 :  |NONE   (DVX_STORAGE_DISKPART_TYPE_NONE) 
	                             //                      |VMFS   (DVX_STORAGE_DISKPART_TYPE_VMFS) 
	                             //                      |FDISK  (DVX_STORAGE_DISKPART_TYPE_FDISK) 
	                             //                      |PARTED (DVX_STORAGE_DISKPART_TYPE_PARTED)
	unsigned __int64 totalSpace;     //磁盘总容量(BYTE) 
	unsigned __int64 freeSpace;      //磁盘剩余容量(BYTE)                
	/**<注：1-8为硬盘，9为USB-Disk，10 为USB-DVD >**/
}; 
//NVR扩展新增图片盘描述
struct DiskStatusEx   
{ 
	char usage;                  /*<!使用方式：   NA   DVX_STORAGE_DISK_NOEXIST	
								 录像盘  DVX_STORAGE_DISK_USETYPE_RECORD
								 冗余盘  DVX_STORAGE_DISK_USETYPE_REDUNDANCE 
								 备份盘  DVX_STORAGE_DISK_USETYPE_BACKUP 
								 未格式化DVX_STORAGE_DISK_USETYPE_UNFORMAT
								 坏盘    DVX_STORAGE_DISK_USETYPE_BADDISK
								 未配置  DVX_STORAGE_DISK_USETYPE_UNCONFIG
								 */  
	char album;                  //所属磁盘组 </*1-8 为硬盘， 9为USB_DISK, 10为USB_DVD*/>
	char awake;                  //!唤醒状态(存于内存)： 休眠(DVX_STORAGE_DISK_STATE_SLEEP) |唤醒(DVX_STORAGE_DISK_STATE_AWAKEN) 
	char active;                 //是否为活动盘/写入盘(存于Meta和内存) YES(1)|NO(0)
	char imgPartitionPercents; //图片分区容量百分比(0-100)，仅对录像盘和未配置盘有效。
	char res[2]; //  
	char  layout;                // 磁 盘 分 区 方 式 :  |NONE   (DVX_STORAGE_DISKPART_TYPE_NONE) 
	//                      |VMFS   (DVX_STORAGE_DISKPART_TYPE_VMFS) 
	//                      |FDISK  (DVX_STORAGE_DISKPART_TYPE_FDISK) 
	//                      |PARTED (DVX_STORAGE_DISKPART_TYPE_PARTED)
	unsigned __int64 totalSpace;     //磁盘总容量(BYTE) 
	unsigned __int64 freeSpace;      //磁盘剩余容量(BYTE)                
	/**<注：1-8为硬盘，9为USB-Disk，10 为USB-DVD >**/
}; 
//磁盘用途
enum
{
	DVX_STORAGE_DISK_NOEXIST            = 0,
	DVX_STORAGE_DISK_USETYPE_RECORD     = 1,
	DVX_STORAGE_DISK_USETYPE_REDUNDANCE = 2,
	DVX_STORAGE_DISK_USETYPE_BACKUP     = 3,
  DVX_STORAGE_DISK_USETYPE_UNFORMAT   = 4,
  DVX_STORAGE_DISK_USETYPE_BADDISK    = 5,
  DVX_STORAGE_DISK_USETYPE_UNCONFIG   = -1,
};

//分区方式
enum
{
	DVX_STORAGE_DISKPART_TYPE_NONE   = 0,
	DVX_STORAGE_DISKPART_TYPE_VMFS   = 1,
	DVX_STORAGE_DISKPART_TYPE_FDISK  = 2,
	DVX_STORAGE_DISKPART_TYPE_PARTED = 3,
};

//唤醒状态
#define  DVX_STORAGE_DISK_STATE_SLEEP     (0)
#define  DVX_STORAGE_DISK_STATE_AWAKEN    (1)

// 磁盘存储总体策略
typedef struct  
{
  unsigned int policies;
}StorageCfg;

struct DiskStatusList 
{
	int count;
	DiskStatus diskList[10];
};

struct DiskFormatPara 
{
	unsigned int disks; // bitmap: bit1-8=disk1-8
	char partition;     // 磁盘分区号(0为整盘)
	char fsType;        // 文件系统VMFS(1)|FAT32(1)
	char res[2];
};

//格式化硬盘或分区(NVR扩展新增图片盘处理)
struct DiskFormatEx
{
	unsigned int disks; //bitmap，包含的磁盘映射表bit1-8=disk1-8
	char partition; //磁盘分区号(0为整盘)
	char fsType; //文件系统：VMFS(1)|FAT32(2)
	unsigned char imgPartitionPercents; //图片分区百分比，仅对硬盘生效
	char res;
};
//NVR扩展新增图片盘描述
struct DiskStatusListEx 
{
	int count;
	DiskStatusEx diskList[20];
};

//NVR扩展新增图片盘描述入参
struct DiskStatusListExIn 
{
  int res[2];
};

struct DiskPartition  
{ 
	unsigned __int64 totalSpace;      //磁盘总容量(BYTE) 
	unsigned __int64 freeSpace;       //磁盘剩余容量(BYTE) 
	char usage;                   //!使用方式：NA(DVX_STORAGE_DISK_NOEXIST):表示该盘不存在 
	char res[2];                  // 
	char fsType;                  //文件系统类型 	|NONE (DVX_STORAGE_FS_TYPE_NONE)
	                              //              |VMFS (DVX_STORAGE_FS_TYPE_VMFS)
	                              //              |VFAT (DVX_STORAGE_FS_TYPE_VFAT) 
}; 
//文件系统类型
enum
{
	DVX_STORAGE_FS_TYPE_NONE = 0,
	DVX_STORAGE_FS_TYPE_VMFS = 1,
	DVX_STORAGE_FS_TYPE_VFAT = 2,
};

struct DiskPartInfo
{ 
	unsigned __int64 totalSpace;       //磁盘总容量(BYTE) 
	unsigned __int64 freeSpace;        //磁盘剩余容量(BYTE) 
	char res[2];                       // 
	char  layout;                      // 磁 盘 分 区 方 式 :  |NONE   (DVX_STORAGE_DISKPART_TYPE_NONE) 
	                                   //                      |VMFS   (DVX_STORAGE_DISKPART_TYPE_VMFS) 
																		 //                      |FDISK  (DVX_STORAGE_DISKPART_TYPE_FDISK) 
																		 //                      |PARTED (DVX_STORAGE_DISKPART_TYPE_PARTED)
	char partitions;                   //磁盘分区总数 
	DiskPartition partitionList[32];   //分区表 
};

struct DiskStateInfo 
{
	char usage;                    /*<!使用方式：  NA   DVX_STORAGE_DISK_NOEXIST	
																              录像盘  DVX_STORAGE_DISK_USETYPE_RECORD
																							冗余盘  DVX_STORAGE_DISK_USETYPE_REDUNDANCE 
																							备份盘  DVX_STORAGE_DISK_USETYPE_BACKUP 
																								禁用  DVX_STORAGE_DISK_USETYPE_BAN
																 */  
	char album;                  //所属磁盘组 1-8为通用磁盘组、9为冗余组、10为备份组
	char  awake;                 //!唤醒状态(存于内存)： 休眠(DVX_STORAGE_DISK_STATE_SLEEP) |唤醒(DVX_STORAGE_DISK_STATE_AWAKEN) 
	char active;                 //是否为活动盘/写入盘(存于Meta和内存) 
	char res[3];                 // 
	char  layout;                // 磁 盘 分 区 方 式 :  |NONE   (DVX_STORAGE_DISKPART_TYPE_NONE) 
														   //                      |VMFS   (DVX_STORAGE_DISKPART_TYPE_VMFS) 
															 //                      |FDISK  (DVX_STORAGE_DISKPART_TYPE_FDISK) 
															 //                      |PARTED (DVX_STORAGE_DISKPART_TYPE_PARTED)
	unsigned __int64 totalSpace; //磁盘总容量(BYTE) 
	unsigned __int64 freeSpace;  //磁盘剩余容量(BYTE) 
	TimeRange  timeRange[16];    //每个通道的录像时间	跨度(起始时间为0为无录像，结束时间为 0 表示正在录像) 
};
//NVR扩展
struct DiskStateInfoEx
{

	char usage;                    /*<!使用方式：  NA   DVX_STORAGE_DISK_NOEXIST	
								   录像盘  DVX_STORAGE_DISK_USETYPE_RECORD
								   冗余盘  DVX_STORAGE_DISK_USETYPE_REDUNDANCE 
								   备份盘  DVX_STORAGE_DISK_USETYPE_BACKUP 
								   禁用  DVX_STORAGE_DISK_USETYPE_BAN
								   */  
	char album;                  //所属磁盘组 1-8为通用磁盘组、9为冗余组、10为备份组
	char  awake;                 //!唤醒状态(存于内存)： 休眠(DVX_STORAGE_DISK_STATE_SLEEP) |唤醒(DVX_STORAGE_DISK_STATE_AWAKEN) 
	char active;                 //是否为活动盘/写入盘(存于Meta和内存) 
	char res[3];                 // 
	char  layout;                // 磁 盘 分 区 方 式 :  |NONE   (DVX_STORAGE_DISKPART_TYPE_NONE) 
									//                      |VMFS   (DVX_STORAGE_DISKPART_TYPE_VMFS) 
									//                      |FDISK  (DVX_STORAGE_DISKPART_TYPE_FDISK) 
									//                      |PARTED (DVX_STORAGE_DISKPART_TYPE_PARTED)
	unsigned __int64 totalSpace; //磁盘总容量(BYTE) 
	unsigned __int64 freeSpace;  //磁盘剩余容量(BYTE) 
	TimeRange recTimeRange[64]; //每个通道的录像时间跨度(起始时间为０为无录像，结束时间为0表示正在录像)
	TimeRange imgTimeRange[64]; //每个通道的图片存储时间跨度(起始时间为０为无图片录像，结束时间为0表示正在图片录像)
};

struct DiskAlbum 
{
	unsigned int disks;        //bitmap，包含的磁盘映射表 bit1-8=disk1-8        
	char policies;             //盘满策略:DVX_STORAGE_ALBUMS_OVERWRITE | DVX_STORAGE_ALBUMS_ALERT
	char active; // -1~8：本盘组当前工作盘
	char res[2]; 
};
//扩展增加图片分区
struct DiskAlbumEx
{
	unsigned int disks;        //bitmap，包含的磁盘映射表 bit1-8=disk1-8        
	char policies;             //盘满策略:DVX_STORAGE_ALBUMS_OVERWRITE | DVX_STORAGE_ALBUMS_ALERT
	char active; // -1~8：本盘组当前工作盘
	char activePic; //-1~8: 本盘组当前图片工作盘：0:VMFS缺省,-1:无工作盘或重复,1-8:手工设置盘号
	char res[1]; 
};
#define  DVX_STORAGE_ALBUMS_OVERWRITE   (1)
#define  DVX_STORAGE_ALBUMS_ALERT       (2)
#define  NVR_MAX_CHANNEL_COUNT			32
#define BSRALGDECT_STUM_LINE_NUM			(4)		//绊线最大数



struct DiskAlbumPara 
{
	int count;                     //磁盘组个数
	DiskAlbum diskAlbumList[10];   //磁盘组包含磁盘的映射表 
};
//扩展增加图片分区
struct DiskAlbumParaEx
{
	int count;						//磁盘组个数
	DiskAlbumEx diskAlbumList[10];   //磁盘组包含磁盘的映射表 
};

struct DiskScheme
{ 
	unsigned int albums;          //bitmap，需要保存的磁盘组映射表                            //bit1-8=album1-8        
}; 

struct DiskSchemePara
{
	int count;                          //通道个数
	DiskScheme   diskSchemeList[16];    //通道-磁盘组的录像规划表 
	//每个元素为该通道需要存储的磁盘组bitmap
};
struct DiskSchemeParaEx
{
	int count;								 //通道个数
	DiskScheme   diskSchemeList[NVR_MAX_CHANNEL_COUNT];			//通道-磁盘组的录像规划表
											//每个元素为该通道需要存储的磁盘组
};

struct FormatStatus
{
  unsigned char status; // 格式化成功(0), 格式化失败(1), 正在格式化(2), 未指定为待格式化硬盘(3);
  unsigned char progress;//仅当status == 正在格式化(2)，本字段才有意义;[0,99]
  unsigned char res[2];
};

struct DiskFormatStatus
{
  unsigned int disks; //bitmap, 包含的磁盘映射表 bit1-8 = disk1-8， bit9 = USB 盘， 
                      //bit10 = 可格式化的CDRW/DVDRW
  FormatStatus status[32]; //后22个成员保留
};



/** @}*/	// end of addtogroup grDisk

/** @addtogroup grUart
 *  @{
 */
struct  SerialCfg
{ 
	unsigned int baudrate;     //bits/s 
	char databits;             //位数(8) 
	char stopbits;             //停止位数 
	char parity;               //！校验方式： 
	                           //! NONE (DVX_UART_VERIFY_TYPE_NONE) |EVEN (DVX_UART_VERIFY_TYPE_EVEN)
	                           //  ODD(DVX_UART_VERIFY_TYPE_ODD)|  MARK(DVX_UART_VERIFY_TYPE_MARK)
	                           //  SPACE(DVX_UART_VERIFY_TYPE_SPACE) 
	char flow;                 //流控: DVX_UART_FLOAT_CONTROL_NONE(0)|DVX_UART_FLOAT_CONTROL_XONOFF(1)   
};   
//校验方式
enum
{
	DVX_UART_VERIFY_TYPE_NONE    = 0,
	DVX_UART_VERIFY_TYPE_EVEN    = 1,
	DVX_UART_VERIFY_TYPE_ODD     = 2,
	DVX_UART_VERIFY_TYPE_MARK    = 3,
	DVX_UART_VERIFY_TYPE_SPACE   = 4,
};
enum
{
	DVX_UART_FLOAT_CONTROL_NONE  = 0,
	DVX_UART_FLOAT_CONTROL_XONOFF= 1,
};

enum
{
	DVX_UART_CAP_CARD = 1,
	DVX_UART_CAP_TRANS_TYPE = 2,
	DVX_UART_CAP_ATM_ID = 4,
	DVX_UART_CAP_TRANS_ID = 8,
	DVX_UART_CAP_AMOUNT = 16,
	DVX_UART_CAP_BALANCE = 32,
	DVX_UART_CAP_ATMTIME = 64,
	DVX_UART_CAP_OTHER = 128,
};

struct Cipher 
{ 
	char type;  	 /*  DVX_UART_CIPHER_TYPE_CONSOLE(1)
								 DVX_UART_CIPHER_TYPE_KB(2)
								 DVX_UART_CIPHER_TYPE_AGENT(3)
								 DVX_UART_CIPHER_TYPE_DOME(4)
                 DVX_UART_CIPHER_TYPE_SNOOP(5)
								 */ 
	char rxtx;     //可用收发: DVX_UART_CIPHER_RXTX_RX(1)|DVX_UART_CIPHER_RXTX_TX(2)|DVX_UART_CIPHER_RXTX_BOTH(3) 
	char links;   //  可使用的链路类型  //RS232(1)|RS485(2)|RJ45(4) 
	char capability; //bitmap:能力标识；不同类型译码器定义不同；
	char name[16]; //译码器名(协议名) 
}; 

struct UartCipher 
{ 
	char enabled;          //DVX_UART_ENABLED_YES(1)|DVX_UART_ENABLED_NO(0)   
	char res;              //   
	unsigned char addr;             // 
	char user;             //译码器使用者,云台对应的通道 
	Cipher cipher;         //  
	SerialCfg serialCfg; 
};
struct UarCipherEx
{
	char enabled; //YES(1)|NO(0)
	char type; //本地接收器(0) | 本地发送器(1) |远端接收器(10) | 远端发送器(11)
	unsigned char addr; //
	char res;
	unsigned int user; //译码器使用者,云台对应的通道
	Cipher cipher; //Cipher.list 中的成员
	SerialCfg serialCfg;
};
#define  DVX_UART_ENABLED_YES   (1)
#define  DVX_UART_ENABLED_NO    (0)
#define  NVR_ENCODE_MAX_COUNT    (40)

enum
{
  DVX_UART_DOCK_RS232 = 1,
  DVX_UART_DOCK_RS485_1 = 1,
  DVX_UART_DOCK_RS485_2 = 2,
};
struct UartPortCfg 
{
	char link;                   //链路类型: DVX_UART_LINK_TYPE_RS232(1)|DVX_UART_LINK_TYPE_RS485(2) |DVX_UART_LINK_TYPE_RJ45 (4) 
	char dock;                   //插口号(RS232:1，RS485:1-2)
	char res;                    // 
	unsigned char count;         ////译码器个数(0-21)
	UartCipher cipherList[21];   //[0]为接收器 [1-20]为发送器
};
struct UartPortCfgEx
{
	char link;                   //链路类型: DVX_UART_LINK_TYPE_RS232(1)|DVX_UART_LINK_TYPE_RS485(2) |DVX_UART_LINK_TYPE_RJ45 (4) 
	char dock;                   //插口号(RS232:1，RS485:1-2)
	char res[2];                    // 
	unsigned int count;         ////译码器个数(0-21)
	UarCipherEx cipherList[NVR_ENCODE_MAX_COUNT];
};
struct UartPortCfgEx_In
{
	char link; //1RS232;2 RS485
    char dock; //插口号(RS232:1 RS485:1-2)
    char type; //0: 本地485 1: 远端485  
    char res;	//字节对齐

};
//链路类型
enum
{
	DVX_UART_LINK_TYPE_RS232  = 1,
	DVX_UART_LINK_TYPE_RS485  = 2,
	DVX_UART_LINK_TYPE_RJ45   = 4,
};
enum
{
	NVR_UART_TYPE_LOACL = 0,
	NVR_UART_TYPE_IP = 1,
};

//译码方式
enum
{
	DVX_UART_CIPHER_TYPE_CONSOLE = 1,
	DVX_UART_CIPHER_TYPE_KB      = 2,
	DVX_UART_CIPHER_TYPE_AGENT   = 3,
	DVX_UART_CIPHER_TYPE_DOME = 4,
	DVX_UART_CIPHER_TYPE_SNOOP = 5,
	DVX_UART_CIPHER_TYPE_BUREAU = 6,
	DVX_UART_CIPHER_TYPE_JD2000 = 7,
	DVX_UART_CIPHER_TYPE_OSD = 8,
};

//译码方向
enum
{
	DVX_UART_CIPHER_RXTX_RX   = 1,
	DVX_UART_CIPHER_RXTX_TX   = 2,
	DVX_UART_CIPHER_RXTX_BOTH = 3,
};

struct UartCipherInfoList 
{
	char link;            //链路类型: DVX_UART_LINK_TYPE_RS232(1)|DVX_UART_LINK_TYPE_RS485(2) |DVX_UART_LINK_TYPE_RJ45 (4)
	char res[2];          // 
	unsigned char count;  //译码器个数(0-255) 
	Cipher cipherList[255]; 
};

struct UartSnoopCfg 
{
	char link;           //链路类型: DVX_UART_LINK_TYPE_RS232(1)|DVX_UART_LINK_TYPE_RS485(2) |DVX_UART_LINK_TYPE_RJ45 (4)
	char dock;           //串口编号(1-2) 
	unsigned short port; //端口(仅 link==RJ45有效) 
	unsigned int addr;   //地址(串口地址或 IP 地址 
	Cipher cipher;       //译码器名(协议名) 空白''表示无 
	char content;        //捕获内容类型: ATM(1) 
	char res;         // 
	unsigned char imprints;       //叠加:   
	                     //CARD (1)|TRANS_TYPE ( 2 )           
	                     //ATM_ID(4)|  TRANS_ID(8)|           
	                     //AMOUNT(16)  )|BALANCE(32)|                 
	                     //ATMTIME(64)|OTHER(128)  
	char subjects;
	unsigned short x;
	unsigned short y;
};
//叠加方式
enum
{
	DVX_UART_IMPRINTS_CARD         = (1),
	DVX_UART_IMPRINTS_TRANS_TYPE   = (2),
	DVX_UART_IMPRINTS_ATM_ID       = (4),
	DVX_UART_IMPRINTS_TRANS_ID     = (8),
	DVX_UART_IMPRINTS_AMOUNT       = (16),
	DVX_UART_IMPRINTS_BALANCE      = (32),
	DVX_UART_IMPRINTS_ATMTIME      = (64),
	DVX_UART_IMPRINTS_OTHER        = (128),
};

struct UartAgentCfg 
{
	char link;              //链路类型: DVX_UART_LINK_TYPE_RS232(1)|DVX_UART_LINK_TYPE_RS485(2) |DVX_UART_LINK_TYPE_RJ45 (4)
	char dock;              //串口编号(1-2) 
	char addr;              //串口地址   
	char res;               //   
	char cipher[16];        //译码器名(协议名)	//空白''表示无 
};
/** @}*/	// end of addtogroup grUart

/** @addtogroup grSecurity
*  @{
*/
struct SecuritySessionLogin 
{
	char user[32];       //用户名
	char password[32];   //明文口令的MD5结果
	unsigned int actor;  //!登陆方式	DVX_SECURITY_LOGIN_TYPE_GUI(1)
	                     //           DVX_SECURITY_LOGIN_TYPE_CLI(2)
	                     //           DVX_SECURITY_LOGIN_TYPE_CLIENT(4)
											 //           DVX_SECURITY_LOGIN_TYPE_WEBUI(8) 
};
//登陆方式
enum
{
	DVX_SECURITY_LOGIN_TYPE_GUI    = (1),
	DVX_SECURITY_LOGIN_TYPE_CLI    = (2),
	DVX_SECURITY_LOGIN_TYPE_CLIENT = (4),
	DVX_SECURITY_LOGIN_TYPE_WEBUI  = (8),
};

//会话属性
struct Session 
{
	unsigned int session;        //会话标识 
	char user[16];               //用户 
	char role[16];               //角色组 
	unsigned int ctime;          //创建时间 
	unsigned int atime;          //最近访问时间 
	unsigned int actor;          //行为类型 
	unsigned int clientAddr;     //客户端地址 
	unsigned int serverAddr;     //服务器地址 
	unsigned short clientPort;     //客户端端口 
	unsigned short serverPort;     //服务器端口
};

//会话列表
struct SecuritySessionList
{
	int count;
	Session  sessionList[10];
};

//会话列表拓展
struct SecuritySessionListEx
{
	int count;
	Session  sessionList[NVR_MAX_CHANNEL_COUNT];
};

//用户信息
struct SecurityUser
{
	char user[16];          //用户名 
	char password[32];      //明文口令的MD5结果 
	char role[16];          //所属角色组 
	unsigned int  actors;   //!登陆方式	DVX_SECURITY_LOGIN_TYPE_GUI(1)
		                      //           DVX_SECURITY_LOGIN_TYPE_CLI(2)
		                      //           DVX_SECURITY_LOGIN_TYPE_CLIENT(4)
											    //           DVX_SECURITY_LOGIN_TYPE_WEBUI(8) 
	char name[32];          //用户显示名 
	char email[32];         // 
	char memo[32];          // 
	/*<admin用户不可修改 role 如password为空则口令不变>*/
};

//用户信息列表
struct SecurityUserList 
{
	int count;
	SecurityUser userList[20];
};

//用户权限
struct Privilege 
{
	unsigned char perms;   //(bitmap)权限，X(1)|W(2)|R(
	char          res[2];              
	char          tgtType; // DVX_SECURITY_USER_TARGETTYPE_SYSTEM   (1) 
	                       // DVX_SECURITY_USER_TARGETTYPE_RECORD   (2)
												 // DVX_SECURITY_USER_TARGETTYPE_DOME     (3)
	                       // DVX_SECURITY_USER_TARGETTYPE_PLAYBACK (4)
	unsigned int  tgtIds;  //目标的标识 
	/* 
	tgtType取值： 
	priv[0]:SYSTEM(1)| 
	priv[1]:RECORD(2)| 
	priv[2]:DOME(3)| 
	priv[3]:PLAYBACK(4)| 

	当 tgtType=SYSTEM时，perms=2，tgtIds的bit1-9
	取值为以下值的bitmap: 
	SYS_SHUTDOWN(bit1)| 
	SYS_UPGRADE(bit2)|   
	SYS_LOG(bit3)|   
	SYS_ALARM(bit4)| 
	SYS_BACKUP(bit5)|     
	SYS_CONFIG(bit6)|     
	SYS_RESTORE(bit7)|     
	SYS_ DISK(bit8)|           
	SYS_USER (bit9)|     

	当 type=VIDEO|DOME|RECORD 时，perms=1, 
	tgtIds分别bit1-16 表示1-16 通道: NO(0)|YES(1)    */
};
//目标类型
enum
{
	DVX_SECURITY_USER_TARGETTYPE_SYSTEM   = (1),
	DVX_SECURITY_USER_TARGETTYPE_RECORD   = (2),
	DVX_SECURITY_USER_TARGETTYPE_DOME     = (3),
	DVX_SECURITY_USER_TARGETTYPE_PLAYBACK = (4),
    DVX_SECURITY_USER_TARGETTYPE_PREVIEW  = (5),
};

enum
{
  DVX_PRIV_SYS_INFO     = 0x0001,   // 系统信息
  DVX_PRIV_SYS_REBOOT   = 0x0002,   // 重启
  DVX_PRIV_SYS_SHUTDOWN = 0x0004,   // 关机
  DVX_PRIV_SYS_UPGRADE  = 0x0008,   // 升级
  DVX_PRIV_SYS_RESTORE  = 0x0010,   // 恢复出厂值
  DVX_PRIV_SYS_CONFIG   = 0x0020,   // 系统配置
  DVX_PRIV_RECORD_SCHEDULE = 0x0040,// 定时录像
  DVX_PRIV_RECORD_BACKUP= 0x0080,   // 录像备份
  DVX_PRIV_ALARM_ACK    = 0x0100,   // 报警清除
  DVX_PRIV_ALARM_CONFIG = 0x0200,   // 报警管理
  DVX_PRIV_EVENT_CONFIG = 0x0400,   // 事件管理
  DVX_PRIV_USER_CONFIG  = 0x0800,   // 用户管理
  DVX_PRIV_NETWORK_CONFIG = 0x00001000, //网络管理   ipc
  DVX_PRIV_CAMERA_CONFIG  = 0x00002000, //摄像头管理 ipc
  DVX_PRIV_DOME_CONFIG    = 0x00004000, //云台管理 ipc
  /*
  PRIVILEGE_SYS_SHUTDOWN = 0x0001,
  PRIVILEGE_SYS_UPGRADE	 = 0x0002,
  PRIVILEGE_SYS_LOG			 = 0x0004,
  PRIVILEGE_SYS_ALARM		 = 0x0008,
  PRIVILEGE_SYS_BACKUP	 = 0x0010,
  PRIVILEGE_SYS_CONFIG	 = 0x0020,
  PRIVILEGE_SYS_RESTORE	 = 0x0040,
  PRIVILEGE_SYS_DISK		 = 0x0080,
  PRIVILEGE_SYS_USER		 = 0x0100,
  */
};

//用户远程权限个数最大值
#define SECURITY_REMOTE_USER_PRIV_MAX  16

//用户本地权限信息
struct SecurityUserPrivilege 
{
	char user[16]; //用户名
	int count;
	Privilege   privList[4];
};

//用户远程权限信息
struct SecurityRmtUserPrivilege 
{
	char user[16]; //用户名
	int count;
	Privilege   privList[SECURITY_REMOTE_USER_PRIV_MAX];
};

//用户角色
struct SecurityRole 
{
	char role[16];  //角色组名 
	char rank;      //级别 
	char res[3];    
	char memo[32];  //备注 
	/**注： 当前角色不能增加删除，其角色名与rank列表如下
	role="super",rank=0; 
	role="admin",rank=1; 
	role="operator",rank=2; 
	role="user",rank=3 **/
};

//角色列表
struct SecurityRoleList
{
	int count;
	SecurityRole roleList[4];
};

struct SecurityRolePrivilege 
{
	char role[16]; //角色组名
	int count;     //个数
	Privilege privList[4];
};

//读取远程角色权限
struct SecurityRoleRmtPrivilege 
{
	char role[16]; //角色组名
	int count;     //个数
	Privilege privList[SECURITY_REMOTE_USER_PRIV_MAX];
};
/** @}*/	// end of addtogroup grSecurity

/** @addtogroup grNet
 *  @{
 */
struct NetLinkState 
{
	int          iface;       // DVX_IFACE_TYPE_LAN (1) | DVX_IFACE_TYPE_WAN (2)
	unsigned char phyAddr[8]; //物理地址(只读)
	int          up;          //DVX_IFACE_STATE_UP(1) | DVX_IFACE_STATE_DOWN(0)|DIALING(2)
	int          status;      //拨号/连接的详细结果//BUSY(1)|NA(2)|TIMEOUT(3)|AUTH(4)
	unsigned int ipAddr;      //IP地址(当前实际值)
	unsigned int netmask;     //子网掩码(当前实际值)
	unsigned int gateway;     //缺省网关(当前实际值)
	unsigned int rxPkts;      //接收数据包
	unsigned int txPkts;      //发送数据包
	unsigned int rxOctets;    //接收字节
	unsigned int txOctets;    //发送字节
};
#define  DVX_IFACE_TYPE_LAN      1
#define  DVX_IFACE_TYPE_WAN      2
#define  DVX_IFACE_TYPE_LAN2     12

#define  DVX_IFACE_STATE_UP      0
#define  DVX_IFACE_STATE_DOWN    1

//网络参数
struct NetLinkPara 
{
	int           iface;				// DVX_IFACE_TYPE_LAN (1) | DVX_IFACE_TYPE_WAN (2)
	unsigned char phyAddr[8];   //物理地址（MAC,只读）
	unsigned char speed;				//速度DVX_IFACE_SPEED_AUTO(0)|10M(1)|100M(2)|1000M(3)
	unsigned char duplex;				//双工DVX_IFACE_DUPLEX_AUTO(0)|HALF(1)|FULL(2)
	unsigned char multicast;		//DVX_IFACE_MUTICAST_ON (1) | OFF(0)
	unsigned char mode;		      //DVX_IFACE_MODETYPE_STATIC(1)| DHCP(2)| ADSL(3)
	unsigned int mtu;		      //MTU
	unsigned int  ipAddr;		    //ip地址
	unsigned int  netmask;		  //子网掩码
	unsigned int  gateway;		  //缺省网关
	char          res[2];		   
	unsigned char dnsflag; //name server 采用手动设置(0)，自动设置(1) 
	unsigned char ddns;			    // 0:DVX_IFACE_DDNS_OFF , 1:DVX_IFACE_DDNS_JWX  2:DVX_IFACE_DDNS_PEANUT
	unsigned int  nameServer1;  //主域名服务器
	unsigned int  nameServer2;  //主域名服务器
	unsigned int  adslDial;     //拨号方式：AUTO(1)|MANUAL(2) 
	unsigned int  adslIdle;     //空闲时间(秒): 0=一直在线， 
	char          adslService[32];
	char          adslUsername[32];
	char          adslPassword[16];
	char          ddnsDomain[32];
	char          ddnsUsername[32];
	char          ddnsPassword[16];
};

//DDNS服务支持列表结构
struct DdnsSvrList
{
  int count;  //ddns 协议支持个数(0-255), 0:  不支持;  
  int res; 
  int ddnsIdlist[64];   //ddns  服务ID取值如下： 1： GNWAY  金万维 2.  ORAY    花生壳 3.  WINCO 
};

//获取多网口工作模式
struct NetlinkMultiEthMode
{
	unsigned char mode; //不支持多网口(0)；负载均衡(1) ；主备(2)；独立配置(3)
	unsigned char res[63]; //保留

};
enum
{
	DVX_IFACE_DDNS_OFF      = 0,
  DVX_IFACE_DDNS_JWX      = 1,  //金万维
	DVX_IFACE_DDNS_PEANUT   = 2,  //花生壳
  DVX_IFACE_DDNS_WINCO   = 3,  //WINCO
};

enum
{
	DVX_IFACE_DUPLEX_AUTO   = 0,
	DVX_IFACE_DUPLEX_HALF   = 1,
	DVX_IFACE_DUPLEX_FULL   = 2,
};

enum
{
	DVX_IFACE_SPEED_AUTO    = 0,
	DVX_IFACE_SPEED_10M     = 1,
	DVX_IFACE_SPEED_100M    = 2,
	DVX_IFACE_SPEED_1000M   = 3,
};

#define  DVX_IFACE_MUTICAST_OFF 0
#define  DVX_IFACE_MUTICAST_ON  1

enum
{
	DVX_IFACE_MODETYPE_STATIC    = 1,
	DVX_IFACE_MODETYPE_DHCP      = 2,
	DVX_IFACE_MODETYPE_ADSL      = 3,
};

//网络测试
struct NetLinkTest 
{
	int  iface;   //DVX_IFACE_LINK_TEST_ALL(0)| LAN(1)|WAN(2)
	char host[32];//检测的目标主机名
	int  wait;    //等待超时时间(单位：秒):1-300
};
enum
{
	DVX_IFACE_LINK_TEST_ALL  = 0,
	DVX_IFACE_LINK_TEST_LAN  = 1,
	DVX_IFACE_LINK_TEST_WAN  = 2,
};

//服务相关
struct NetServerAddrPara 
{
	unsigned short cmdPort;   //命令端口（缺省为3721）
	unsigned short dataPort;  //数据端口，应为cmdPort-1
	unsigned short httpPort;  //webUI端口
	unsigned short mcastPort; //组播端口
	unsigned int   mcastAddr; //组播地址
	unsigned int   logServer; //日志服务器，0标示禁用
};

//报警服务器设置
struct NetAlertServer 
{
	unsigned int   addr;   //报警服务器地址，0标示未用
	unsigned short port;
	char           proto;  //DVX_IFACE_ALERT_UDP(1) | TCP(2)
	char           format; //DVX_IFACE_ALERT_FORMAT_BSTAR(0)
};
#define  DVX_IFACE_ALERT_UDP             1
#define  DVX_IFACE_ALERT_TCP             2

#define  DVX_IFACE_ALERT_FORMAT_BSTAR    0

struct NetAlertServerPara 
{
	NetAlertServer alertServerList[2];
};

//smtp参数
struct NetSmtpPara 
{
	char enabled;           //是否启用
	char res;
  char mailnum; 
  char mailInterv; 
	char smtpServer[32];    //SMTP服务器
	int  smtpPort;          //SMTP服务器端口（缺省为25）
	int  smtpAuth;          //认证方式DVX_IFACE_SMTPAUTH_NONE(0)|LOGIN(1)
	char smtpUsername[32]; //smtp服务器认证用户
	char smtpPassword[32]; //smtp服务器认证口令
	char sender[32];        //发送者邮件地址
	char recipients[64];    //缺省邮件接收地址列别\(以逗号分隔)
};
#define  DVX_IFACE_SMTPAUTH_NONE    0
#define  DVX_IFACE_SMTPAUTH_LOGIN   1

//smnp参数
struct NetSmnpPara 
{
	char enabled;
	char res[3];
	char community[16];
};

//dvr注册状态
struct NetRegistyState 
{
	short status; // DVX_IFACE_REGISTRY_STATE_WAITING (-2)|TRYING(-1)|OFFLINE(0)|ONLINE(1)
	short error;
	char  serverName[16];
};
enum
{
	DVX_IFACE_REGISTRY_STATE_WAITING   = (-2),
	DVX_IFACE_REGISTRY_STATE_TRING     = (-1),
	DVX_IFACE_REGISTRY_STATE_OFFLINE   = ( 0),
	DVX_IFACE_REGISTRY_STATE_ONLINE    = ( 1),
};

//网络注册参数
struct NetRegistryPara 
{
	char           enable;     //是否启用注册功能 NO(0)| YES(1)
	char           res[3];     
	unsigned int   serverAddr; //注册服务器ip地址
	unsigned short serverPort; //注册服务器端口，缺省为8002
	unsigned char  retries;    //连续失败或出错的最大重试次数，0为永久重试
	unsigned char  resx;
	unsigned int   serverKey;  //认证码， 缺省为123456
	int            registerStandby; // 服务器standby时间
};
/** @}*/	// end of addtogroup grNet


/** @addtogroup grAlert
 *  @{
 */
struct TimeSlice 
{ 
	unsigned char startHour;      //时间段起点的小时数(0-23) 
	unsigned char startMinute;    //时间段起点的分钟数(0-59) 
	unsigned char endHour;        //时间段终点的小时数(0-36) 
	unsigned char endMinute;      //时间段终点的分钟数(0-59) 
	char          enabled;        //DVX_TIMESLICE_ENABLED_OFF(0) | DVX_TIMESLICE_ENABLED_ON(1) 
	union 
	{
		char profile;
		char sensitivity;
		char res1;
	}u;
	char res[2]; 
}; 
//NVR扩展
struct TimeSliceEx 
{ 
	unsigned char startHour;      //时间段起点的小时数(0-23) 
	unsigned char startMinute;    //时间段起点的分钟数(0-59) 
	unsigned char endHour;        //时间段终点的小时数(0-36) 
	unsigned char endMinute;      //时间段终点的分钟数(0-59) 
	char		  streamRecEnabled; //OFF(0) | ON(1)
	char		  profile; //画质
	char		  picRecEnabled; //OFF(0) | ON(1)
	char		  res;
}; 
//时间段
struct Timetable 
{ 
	unsigned char days;                //==7:   
	unsigned char slices;              //==4   
	unsigned char res[2];         
	TimeSlice     timeSliceList[7][6];     //[0-6]星期日,一~六 
};
//时间段（NVR扩展）
struct TimetableEx 
{ 
	unsigned char days;                //==7:   
	unsigned char slices;              //==4   
	unsigned char res[2];         
	TimeSliceEx     timeSliceList[7][6];     //[0-6]星期日,一~六 
};
#define		DVX_TIMESLICE_ENABLED_ON	1
#define		DVX_TIMESLICE_ENABLED_OFF	0

typedef struct  
{
  char      enabled;   //布防
  char      infrared;  //1-启动，0-不启动
  char      res[2];        
  Timetable timetable; //[0-6]星期日,一~六 //每天 6个时段 
}AlarmZone;
//布防设置
struct AlertAlarmCfg 
{
  AlarmZone inputs[16];	
};

//报警输入端子列表
typedef AlarmZone AlarmZoneCfg[16];

#define		DVX_ALARM_ARM			1
#define		DVX_ALARM_DISARM	0
#define	    NVR_ALERT_MAX_NUM 64  //NVR报警最大端子个数
#define     NVR_ALERT_ACTION_MAX_NUM 10 //NVR最大联动个数
#define     NVR_ALERT_MAX_BUFF 1024*130
#define     NVR_ALERT_ACTION_DATA_MAX_LENGTH  500//action 携带的最大数据长度
//布防设置（NVR扩展）
struct AlertAlarmCfgEx 
{
	int inputCount;						//报警端子总个数
	AlarmZone inputs[NVR_ALERT_MAX_NUM];//报警端子的防区配置	
};

//报警输入配置
struct AlarmInputCfg
{ 
	char  enabled;         //保留 
	char  circuit;         //开闭路：DVX_ALARM_INPUT_OPEN(1)|DVX_ALARM_INPUT_CLOSE(2)
	char  zoneType;        //24小时(1)|即时(2)|延时(3)|旁路(4) 
	char  res[3];
	short delay;
}; 
//报警输入配置
struct AlarmInputCfgEx
{
	char enabled; //
	char circuit; //开闭路：OPEN(1)|CLOSE(2)
	char zoneType; //24 小时(1)|即时(2)|延时(3)|旁路(4)
	char location; //本地后板上(0) | 远端IPC 上(1)
	char channel; //通道号，仅对location == 1 有效
	char inputSeq; //远端channel 上的报警输入端子序号，仅对location == 1 有效
	short delay; //延时防区的延时长度(秒)
};
#define  DVX_ALARM_INPUT_OPEN    1
#define  DVX_ALARM_INPUT_CLOSE   2

//报警输入列表
struct AlarmInputList
{
	int            inputs; //防区bitmap:bit1-16 
	char res;
	char     toureEnabled;      //报警轮巡
	short tourInterval;         //轮训时间间隔(s)
	AlarmInputCfg  AlarmInputCfgList[16];   
};
//报警输入列表
struct AlarmInputListEx
{
	int count; //报警输入端子的总个数
	int inputs[NVR_ALERT_MAX_NUM]; //
	char res; //
	char toureEnabled; //报警轮巡
	short tourInterval; //轮巡时间间隔(秒)
	AlarmInputCfgEx alarmInputCfgList[NVR_ALERT_MAX_NUM];
};
//报警端子名称
struct AlarmNameIn
{
	int count;
	int inputs[NVR_ALERT_MAX_NUM];
};
struct AlarmNameOut
{
	int count;
	int inputs[NVR_ALERT_MAX_NUM];
	char nameArray[NVR_ALERT_MAX_NUM][NVR_ALERT_MAX_NUM];
};
//报警输出配置
struct AlarmOutputCfg 
{ 
	char      enabled;     //保留 
	char      circuit;     //开闭路：DVX_ALARM_INPUT_OPEN(1)|DVX_ALARM_INPUT_CLOSE(2) 
	short     duration;     //保留 
	Timetable timetable;   //[0-6]星期日,一~六 //每天 6个时段 
}; 
struct AlarmOutputCfgEx
{
	char location;			//本地后板上(0)|远程ipc上(1)
	char circuit;			//开闭路:OPEN(1)|CLOSE(2)
	char channel;			//通道号,仅对location == 1有效
	char ouputSeq;			//远端channel上的报警输出端子序号仅对local == 1有效
	short duration;			//延时(0-3600s)
	char res[2];			//
	Timetable timetable; //[0-6]星期日,一~六//每天6 个时段
};

//报警输出配置列表
struct AlarmOutputList 
{
	int             outputs;
	AlarmOutputCfg  AlarmOutputCfgList[16];
};
//报警输出配置列表
struct AlarmOutputListEx 
{
	int             count; //报警输出端子总个数
	int				outputs[NVR_ALERT_MAX_NUM];
	AlarmOutputCfgEx alarmOutputCfgList[NVR_ALERT_MAX_NUM];
};

//现场联动 
struct SceneAct 
{ 
	unsigned int triggers; //bit1-32:bitmap //DVX_SCENEACT_TRIGGER_SCREEN(1)|BUZZ(4)| //MAIL(8)|NET(16) 
	unsigned short duration;//持续时间(秒) 
	unsigned short res;
}; 
enum
{
	DVX_SCENEACT_TRIGGER_SCREEN		= 0x0001,
	DVX_SCENEACT_TRIGGER_BUZZ			= 0x0004,
	DVX_SCENEACT_TRIGGER_MAIL			= 0x0008,
	DVX_SCENEACT_TRIGGER_NET			= 0x0010,
	DVX_SCENEACT_TRIGGER_CARDNET			= 0x0020,
	DVX_SCENEACT_TRIGGER_SNAPSHOT     = 0x0040,
	DVX_SCENEACT_TRIGGER_UPLOAD_NET   = 0x0080
};

//视频预览联动(轮跳) 
struct PreviewAct 
{ 
	unsigned int channels; //bit1-32:bitmap 
	unsigned int res;      
}; 
//视频录像联动 
struct RecordActArg 
{ 
	unsigned char profile; //画质 
	unsigned char res[3];  
}; 

//录像联动
struct RecordAct 
{ 
	unsigned int channels; //bit1-32:bitmap 
	unsigned short duration;  //延录时长
	unsigned short res;
	RecordActArg args[16]; 
}; 
//录像联动（NVR扩展）
struct RecordActEx
{
	unsigned int channelTotal;
	unsigned int channels[NVR_ALERT_MAX_NUM]; //1：录像；0：不录像
	unsigned short duration; //延录时长(s)
	unsigned short res; //
    RecordActArg  args[NVR_ALERT_MAX_NUM];
};
//视频云台联动 
struct DomeActArg 
{ 
	char uses;      //!bitmap://DVX_DOMEACT_USE_PRESET(1)|PATROL(2)|TRACE(4)
	unsigned char preset;    //1-255 
	char patrol;    //1-16 
	char trace;     //0-16 
}; 
//视频云台联动(NVR扩展)
struct DomeActEx
{
	unsigned int channelTotal;
	unsigned int channels[NVR_ALERT_MAX_NUM] ; //1：联动云台；0：不联动云台
	char active; //YES(1)|NO(0)
	char res[3] ; //
	DomeActArg args[NVR_ALERT_MAX_NUM];
};
enum
{
	DVX_DOMEACT_USE_PRESET		= 0x01,
	DVX_DOMEACT_USE_PATROL		= 0x02,
	DVX_DOMEACT_USE_TRACE			= 0x04,
};

//云台联动
struct DomeAct 
{ 
	unsigned int channels;    //bit1-16 
	char active;   //YES OR NO
	char res[3];
	DomeActArg args[16]; 
}; 

//报警输出联动
struct AlarmOutputActArg 
{ 
	char res[8] ;     //秒  
}; 
//报警输出联动(NVR扩展)
struct AlarmOutputActEx
{
	unsigned int alarmOutTotal;
	unsigned int alarmOuts[NVR_ALERT_MAX_NUM]; //1：联动报警输出；0：不联动报警输出
	AlarmOutputActArg  args[NVR_ALERT_MAX_NUM] ;
};

//报警输出联动配置
struct AlarmOutputAct 
{ 
	unsigned int      outputs;     //bit1-32: bitmap 
	AlarmOutputActArg args[4];   
}; 
//图片录像联动
struct ImgRecActArg
{
	unsigned char resolution;
	//QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) | 1080P(14)
	unsigned char quality; //最差(1) | 标准(5) |最好(9)
	unsigned char frameRate; //1-5, 10x 表示1/x
	unsigned char res[5]; //保留
};

struct SDRecordAct
{
	char enabled; //YES(1) | NO(0)
	char res;
	USHORT duration; //延录时长(s)
	unsigned int maxDuration; //最大延录时间(S)，取值为0表示持续录像
};
struct Action 
{ 
	char enabled;
	char type; //!DVX_ALERT_ACTION_TYPE_SCENE(0)|PREVIEW(1)|RECORD(2)| 
	           //DOME(3)|ALARM(4) 
	char res[2]; 
	union 
	{ 
		struct SceneAct sceneAct; 
		struct PreviewAct previewAct; 
		struct RecordAct recordAct; 
		struct DomeAct domeAct; 
		struct AlarmOutputAct alarmOutputAct; 
	}u; 
}; 
struct PicUploadAct
{
	char enabled; //YES(1) | NO(0)
	char resolution; //D1(1), CIF(2)
	char res[2];
	unsigned int snapSecsBeforeAlarm; //警前抓图时间(S)
};

struct ImgRecAct 
{ 
  unsigned int channelTotal; 
  unsigned int channels[NVR_ALERT_MAX_NUM]; //1：执行图片录像；0：不执行图片录像 
  unsigned short duration;   //延录时长(s) 
  unsigned short res[3];  // 
}; 

struct PicUploadAlmAct 
{ 
  char enabled; //YES(1) | NO(0) 
  char res[7];  
}; 

struct ActionExtra
{
	char enabled; //YES(1)|NO(0)
	char type;
	//区间[0-5]保留，保证与0x00aa0301 命令保持前向兼容。新增的类型从6 开始。
		//PICTURE_UPLOAD(6)
	char res[2];
	union oneAction
	{
		struct SceneAct sceneAct; 
		struct PreviewAct previewAct; 
		struct RecordAct recordAct; 
		struct DomeAct domeAct; 
		struct AlarmOutputAct alarmOutputAct;
		struct SDRecordAct sDRecordAct;
		struct PicUploadAct picUploadAct;
	}u;
};
struct ActionEx
{
	char enabled;
	char type; //!DVX_ALERT_ACTION_TYPE_SCENE(0)|PREVIEW(1)|RECORD(2)| 
	//DOME(3)|ALARM(4)|SDCard(5)|PICTURE_UPLOAD(6)  
	char res[2];
	unsigned int dataLength;//action 携带数据的长度
	unsigned char data[NVR_ALERT_ACTION_DATA_MAX_LENGTH];
	// type / dataLength / data[ ]的对应关系如下
	// SCENE(0) ?? struct SceneAct
	// PREVIEW(1) ?? struct PreviewAct
	// RECORD(2) ?? struct RecordAct
	// DOME(3) ?? struct DomeAct
	// ALARM(4) ?? struct AlarmOutputAct
	// SDCard(5) ?? struct SDRecordAct
	// PICTURE_UPLOAD(6) ?? struct PicUploadAct
	// IMAGE_RECORD(7) 􀃆 struct ImgRecAct

};
struct Data_Ex
{
	union
	{
		struct SceneAct sceneAct; 
		struct PreviewAct previewAct; 
		struct RecordAct recordAct; 
		struct DomeAct domeAct; 
		struct AlarmOutputAct alarmOutputAct;
		struct SDRecordAct sdrecordact;
		struct PicUploadAct picuploadact;

	}u;
};
enum
{
	DVX_ALERT_ACTION_TYPE_SCENE			= 0,
	DVX_ALERT_ACTION_TYPE_PREVIEW		= 1,
	DVX_ALERT_ACTION_TYPE_RECORD		= 2,
	DVX_ALERT_ACTION_TYPE_DOME			= 3,
	DVX_ALERT_ACTION_TYPE_ALARM			= 4,
	DVX_ALERT_ACTION_TYPE_SDRECORD  = 5,
	DVX_ALERT_ACTION_TYPE_PICUPLOAD		= 6,
	DVX_ALERT_ACTION_TYPE_UPLOAD_NET = 7,
	DVX_ALERT_ACTION_TYPE_IMAGE_RECORD = 8,
	DVX_ALERT_ACTION_TYPE_PICUPLOAD_ALM = 9, //报警联动上传
  DVX_ALERT_ACTION_TYPE_IMAGE_UPLOAD = 10, //SD卡图片上传
};
#define  DVS_MAX_ACTION_COUNT 10
//报警联动配置
struct  ActionCfg
{
	int alertType;            //报警源类型:   
	unsigned int alertIds;    //报警源编号 bitmap(1-16)   
	char res[3];              //联动个数(==5) 
	char count;               //联动个数(==5) 
	Action actionList[16][5];                           
};
struct ActionCfgEx
{
	int alertType;            //报警源类型:   
	unsigned int alertCount;  //
	unsigned int alertIds[NVR_ALERT_MAX_NUM];
	unsigned int actionCount; //联动个数
	ActionEx actionList[NVR_ALERT_MAX_NUM][NVR_ALERT_ACTION_MAX_NUM];

};
struct EventFilter
{
	unsigned int filterIt; //0: 默认均不过滤，1：启用过滤；
	unsigned int alertIds; ///同0x00aa.8311
	char subIds; /// alertIds 为网络断开时subIds取值[0:Any, 1:eth0, 2:eth1]
	char res[7];
};
struct FilterCfg
{
	int alertType;//报警源类型:
	unsigned int count;// alert count
	EventFilter  filter[NVR_ALERT_MAX_NUM];
};
struct  UploadCfg
{
	unsigned int keepAliveInterval;
	char res[64];
} ;
struct ActionCfgExtra
{
	int alertType;            //报警源类型:   
	unsigned int alertIds;    //报警源编号 bitmap(1-16)   
	char res[3];             
	char count;               //联动个数(必须实现为变长协议)
	ActionExtra actionList[16][DVS_MAX_ACTION_COUNT];                

};

struct ActionIpc 
{ 
	char enabled;
	char type; //!DVX_ALERT_ACTION_TYPE_SCENE(0)|PREVIEW(1)|RECORD(2)| 
	//DOME(3)|ALARM(4) 
	char res[2]; 
	union 
	{ 
		struct SceneAct sceneAct; 
		struct PreviewAct previewAct; 
		struct RecordAct recordAct; 
		struct DomeAct domeAct; 
		struct AlarmOutputAct alarmOutputAct; 
		struct SDRecordAct sdRecordAct;
	}u; 
}; 

//报警联动配置
struct  ActionCfgIpc
{
	int alertType;            //报警源类型:   
	unsigned int alertIds;    //报警源编号 bitmap(1-16)   
	char res[3];              //联动个数(==5) 
	char count;               //联动个数(==5)
	ActionIpc actionList[16][6];                           
};

enum
{
	DVX_ALERTTYPE_INPUT			= 1,		// 报警端子报警
	DVX_ALERTTYPE_VMOTION		= 2,		// 移动侦测报警
	DVX_ALERTTYPE_VLOSS			= 3,		// 视频丢失报警
	DVX_ALERTTYPE_VBLOCK		= 4,		// 视频遮挡报警
	DVX_ALERTTYPE_ATM				= 5,		// 卡号
	DVX_ALERTTYPE_ALG       = 6,    // 智能
	DVX_ALERTTYPE_ERROR			= 10,		// 异常报警
	DVX_ALERTTYPE_AVD       = 11,   // 视频诊断
	DVX_ALERTTYPE_FACEDETECT       = 12,		// 人脸检测
	DVX_ALERTTYPE_MOTIONDETECT     = 13,   // 运动检测
};

/** @}*/	// end of addtogroup grAlert

struct SceneHidCfg
{
  char _locale;       // 界面语言：CN(1), EN(2)
  char _indicator;    // 通道状态标识：YES(1), NO(0) 
  char _guiOpaque;    // 菜单透明度(0-10, 0为全透明)
  char _guiIdleTime;  // 菜单空闲时间(秒)
  char _guiProtected; // 菜单口令保护YES(1), NO(0)
  char _keypadBeep;   // 按键声音YES(1), NO(0)
  char _mouseSensitivity; // 鼠标灵敏度
  char _mouseDoubleClick; // 鼠标双击
};

struct SceneDevNameOverlayCfg
{
  char enable; //是否叠加1 = 叠加, 0 = 不叠加
  char res[3];
  unsigned short x; //水平位置
  unsigned short y; //垂直位置
};

struct SenceDevChnnlOverlayCfg
{
  unsigned int channels; //有效通道(bit1-16=CH1-16)
  SceneDevNameOverlayCfg decChnnlOverlayCfg[16];
};
struct SenceDevChnnlOverlayCfgEx
{
	unsigned long long channels; //有效通道(bit1-16=CH1-16)
	SceneDevNameOverlayCfg decChnnlOverlayCfg[64];
};

struct ChnnlAVEncCap
{
  char videoCodec; //bitmap: mpeg4(1)|mjpeg(2)|h264(3)
  char audioCodec; //bitmap: mp2(1) |bit2 = G.72X(2), bit2= ADPCM(3)
  char res1[2];
  short avilibleResolution[8]; //最多8个码流的可选编码分辨率，主码流(0)，1-7分别代表第一至第七子码流
                            //bitmap:QCIF(1), CIF(2), HalfD1(3), D1(4), DCIF(5) 720I(11) 720P(12) 1080I(13) 1080P(14) 960H(15)
  char availNSDResolution[8];  //bit1:1280*960 ,bit2 :1600 *1200, bit3:2048* 1536,
  //bit4 :640*480, bit5 :1920*1024，
  //bit6 :800x600,bit7 :1280x1024, bit8 : 1024x768
  char availNSDResolution_02[4];  //bit1:320x180,bit2:320x240,bit3:640x360
  //bit4: 720x576, bit5:800x450

};

struct ChnnlAVCap
{
  unsigned int chnnl; //bitmap :有效通道号，bit1 = 1, bit16 = 16;
  ChnnlAVEncCap encCapList[16];
};
struct ChnnlAVCapEx
{
	unsigned long long chnnl;
	 ChnnlAVEncCap encCapList[64];
};

//恢复出厂设置模式
#define  DVX_RESTORE_FACTORY    0
/** @addtogroup grSystem
 *  @{
 */
struct SystemStateInfo
{
	unsigned int curTime;   // 系统当前时间
	int upTime;             //系统总运行时间
	int loads[3];           //系统5、10、15分钟内的平均负载
	int totalRAM;           //系统总内存(MB)
	int freeRAM;            //系统空闲内存(MB)
	int bufferRAM;          //用于缓存的内存(MB)
	int tatalSwap;          //系统总交换分区大小(MB)
	int freeSwap;           //系统空闲交换分区(MB)
	int procCount;          //进程数
};

//版本信息
struct SystemVersionInfo	 
{
	int product;            //产品开发编号
	char model[32];					//销售型号
	char version[32];				//录像机版本
	char serial[32];        //产品系列号
	unsigned char macid[8]; //机器标示 <前2字节为0， 后6各字节为MAC地址>
};

//迸发处理能力
struct SwLimit 
{
	unsigned short sessions;     // 最大并发登陆会话数，缺省为10
	unsigned short streams;      // 最大并发传输，缺省为16
	unsigned short netplays;     // 最大并发远程回放连接数 缺省值8
	unsigned short dumps;        // 最大并发下载链接，缺省8
	unsigned short speeches;     //最大并发语音数 缺省1
  unsigned short bandwith;  // 最大网络带宽（M）
  unsigned short chanNameOsdNum; //  最大通道名称叠加数量; 0~1:均标示 1个； 
	unsigned short max_frame_rate; // 最大帧率，用于支持50、60，
	unsigned short max_vcodec_frm ;   // 最大视频编码帧数（CIF） 0 :为无效值；
	unsigned short swSpecInfo;   //  默认为0， >1  , HwSpec中的	audioInputs，speechnum 要正常使用，目的是兼容错误的使用方式；
	unsigned short masknum;    // 视频遮盖数量，>0 有效，为0 时为	不使用；
  UCHAR    max_substream_frmrate; // 最大子码流帧率，0 为无效 (兼容性考虑)； 
  UCHAR    res0;   // 
  UINT     sampleResol;   //IPC 专用，采集分辨率 
  UCHAR    res[36];   // 
};

//硬件信息
struct HwSpec 
{
	char chips;              //MP处理器
	char videoInputs;        //通道数
	char videoOutputs; 
	char audioInputs; 
	char audioOutputs;
	char speechInputs;
	char speechOutputs;
  char alarmInputs;
	char alarmOutputs;	
	char netIfaces;          //网口数
	char rs232ports;
	char rs485ports;
	char usbports;
	char monitors;           //监视器输出个数
	char shelfs;             //总盘位
  char sensor; // IPC 专用// 0: No Sensor ; 1: 9P031 ; 2: 9M034 ; 3: IMX036;4 : AR0331 
                           //5:AR0130, 6: IMX122, 7:OV9712 , 8:IMX138, 9:IMX236 
	char audioIntype; //1：Line in; 2: mic in;3：Both
	char infrared; // 红外支持：1：yes，0：no
	char iface_no1000m;// 网卡是否不支持1000M，默认0:支持1000M，1：不支持1000M
	char with_iface2; //支持双网口, 0,不支持，1：支持
  char sdCard;      //是否支持sd卡，0 非法值，1 支持 ， 2 不支持
	char no_fan_alarm;   //  不支持风扇报警，0，正常1，不支持；
  char res[10];
};

//系统信息
struct SystemDescribleInfo 
{
	char platform;         //平台编号 //SUNFLOWER(1)|CHALLENGER(2)|LIMIT(3)|LC(4) LOTUS(5) PENNY (6) TULIP (7))
	char res[3];
  unsigned int features; //总体能力与功能指标(取值 bit1~ bit32)  bit1~bit7:  预留;  
                         //Bit8：宽动态  ；( IPC 专用)               //Bit9:  日夜转换；( IPC 专用) 
                         //Bit10:  背光补偿；( IPC 专用)             //Bit11：数字降噪；( IPC 专用) 
                         //Bit12：强光抑制；( IPC 专用)              //Bit13:支持BNC功能 
                         //Bit15：卡号;                              //Bit16：智能 ;
	                       //Bit17: SIP协议                            //Bit18：视频切片信息
                         //Bit19：支持IP 通道ROI; ( NVR 专用)        //Bit20：支持IP 通道抓图；(NVR 专用)
                         //Bit21：葡萄牙文；                         //Bit22：曲面校正；( IPC 专用)
                         //Bit23：去雾；( IPC 专用)                  //Bit24：图像旋转；( IPC 专用)
	                       //Bit25：图像诊断；（IPC 专用）             //Bit26: IPC 通道为主方式接入支持；（NVR 专用）
	                       //Bit27：Onvif over TCP ;                   //Bit28: 是否支持0通道(0是支持，1是不支持)
	                       //Bit29：0 菜单透明度，0：支持，1：不支持;(对IPC无意义)；
	HwSpec spec;
	SwLimit limit;
};
//产品序列号
struct SystemSerialGet
{
	char serial[26];			//产品序列号
	char res1[4];				//保留
	char version_type;			//版本类型，见下表格
	char res2;
};
#define  DVX_SUNFLOWER   (1)
#define  DVX_CHALLENGE   (2)

//系统标识
struct SystemIndentityPara 
{
	int code;            //设备编号
	char name[32];       //设备名称
	char contact[32];    //联系方式
	char location[32];   //设备地址
	char memo[32];       //备注
};

//系统时间
struct SystemTimeStyle	 
{
	char dateFormate[16];
	char timeFormate[16];
	/**< 日期和时间格式惨遭windows标准: YYYY- MM- DD HH :MM: SS 当前的日期间隔符智能是"-",
	时间分隔符智能是":">,日期可以设置为以下三种:YYYY-MM-DD ||MM-DD-YYYY || DD-MM-YYYY*/
	char timezone[2];    //-12~+12
	char daylight;    //夏令时 |NO   (DVX_DAYLIGHT_TIME_NO)
	                  //       |YES  (DVX_DAYLIGHT_TIME_YES)
	char ntpEnabled;  //NTP自动校时  |NO  (DVX_NTP_AUTO_NO)
	                  //             |YES (DVX_NTP_AUTO_YES)
	char ntpServer[32]; 
	unsigned int ntpInterval;
};
#define  DVX_DAYLIGHT_TIME_NO     (0)
#define  DVX_DAYLIGHT_TIME_YES    (1)

#define  DVX_NTP_AUTO_NO          (0)
#define  DVX_NTP_AUTO_YES         (1)

// 编解码能力
#define  DVX_VCAP_RESOLUTION_QCIF   0x0001
#define  DVX_VCAP_RESOLUTION_CIF    0x0002
#define  DVX_VCAP_RESOLUTION_2CIF   0x0004
#define  DVX_VCAP_RESOLUTION_D1     0x0008
#define  DVX_VCAP_RESOLUTION_DCIF   0x0010
#define  DVX_VCAP_RESOLUTION_CIF_R  0x0020
#define  DVX_VCAP_RESOLUTION_D1_R   0x0040
#define  DVX_VCAP_RESOLUTION_720I   0x0400
#define  DVX_VCAP_RESOLUTION_720P   0x0800
#define  DVX_VCAP_RESOLUTION_1080I  0x1000
#define  DVX_VCAP_RESOLUTION_1080P  0x2000
#define  DVX_VCAP_RESOLUTION_960H   0x4000
//NSD编解码能力
#define  DVX_VCAP_RESOLUTION_1280x960   0x0001
#define  DVX_VCAP_RESOLUTION_1600x1200  0x0002
#define  DVX_VCAP_RESOLUTION_2048x1536  0x0004
#define  DVX_VCAP_RESOLUTION_640x480    0x0008 
#define  DVX_VCAP_RESOLUTION_1920x1024  0x0010
#define  DVX_VCAP_RESOLUTION_800x600    0x0020
#define  DVX_VCAP_RESOLUTION_1280x1024  0x0040
#define  DVX_VCAP_RESOLUTION_1024x768   0x0080

#define  DVX_VCAP_RESOLUTION_320x180 0x0001
#define  DVX_VCAP_RESOLUTION_320x240 0x0002
#define  DVX_VCAP_RESOLUTION_640x360 0x0004
#define  DVX_VCAP_RESOLUTION_720x576 0x0008
#define  DVX_VCAP_RESOLUTION_800x450 0x0010

//最大支持的非标分辨率格式个数
#define  DVX_NSD_RESOLUTION_MAX_NUM  24

typedef struct  
{
  unsigned short stdCap;              // 缺省的总编码能力
  unsigned short maxChannels;         // 最大编码通道数
  unsigned short maxStreamNum;        // 最大支持的码流个数
  unsigned short maxCap;              // 
  unsigned short stdEncodersCaps[8];  // 所有主码流、子码流的缺省编码能力。
  unsigned short streamResolution[8]; // 按位处理：QCIF(1), CIF(2), halfD1(3), D1(4), DCIF(5)
  unsigned char  encType;             // 编码器类型, BIT(1)-MPEG4, BIT(3)-H264
  unsigned char  res[3];
}VEncCap;

typedef struct  
{
  unsigned short stdCap;              // 缺省的总编码能力
  unsigned short maxChannels;         // 最大编码通道数
  unsigned char  stdEncodersCaps[8];  // 所有主码流、子码流的缺省编码能力。
  unsigned int   encType;             // 编码器类型：
  unsigned char  res[4];
}AEncCap;

typedef struct  
{
  unsigned short stdCap;              // 缺省的总解码能力
  unsigned short maxChannels;         // 最大解码通道数
  unsigned short maxCap;              // 
  unsigned short resolution;          // 按位处理：QCIF(1), CIF(2), halfD1(3), D1(4), DCIF(5)
  unsigned char  encType;             // 解码器类型, BIT(1)-MPEG4, BIT(3)-H264
  unsigned char  res[3];
}VDecCap;

typedef struct  
{
  unsigned short stdCap;              // 缺省的总解码能力
  unsigned short maxChannels;         // 最大解码通道数
  unsigned int   encType;             // 编码器类型：
  unsigned char  res[4];
}ADecCap;

typedef struct  
{
  unsigned char  speechChannelNum;    // 对讲通道对数
  unsigned char  res[3];
  unsigned int   codecType;           // 解码器类型
}SpeechCap;

typedef struct  
{
  unsigned char  depth;               // BIT(1)-8bit, BIT(2)-16bit, BIT(3)-24bit, BIT(4)-32bit
  unsigned char  res;
  unsigned short resolution;          // BIT(1)-D1, BIT(2)-800X600
}OsdProperty;

typedef struct  
{
  unsigned char  OsdNum;              // OSD个数，最大8个
  unsigned char  res[3];
  OsdProperty    properties[8];
}OsdCap;

typedef struct  
{
  unsigned int   xResolution;         // 最大水平像素数
  unsigned int   yResolution;         // 最大垂直像素数
  unsigned char  maxImgPerSec;        // 每秒最大边拍张数
  unsigned char  res[3];
}ImageCap;

typedef struct  
{
	unsigned int   xResolution;         // 最大水平像素数
	unsigned int   yResolution;         // 最大垂直像素数
	unsigned char  maxImgPerSec;        // 每秒最大边拍张数
	unsigned char imgPlayCap; //0表示不支持，其它值表示图片播放的能力
	unsigned char res[2];
}ImageCapEx;
typedef struct  
{
  unsigned char  res[256];
}AiCap;

typedef struct  
{
  unsigned short capability;          // BIT(1)-VEnc, BIT(2)-VDEC, BIT(3)-AEnc, BIT(4)-ADec
  unsigned short VEncDecTotalCap;     // 总的视频编解码能力
  unsigned int   property;            // 
  unsigned short VEncDecRatio[2];
  
  VEncCap        venc;
  AEncCap        aenc;
  VDecCap        vdec;
  ADecCap        adec;
  SpeechCap      speech;
  OsdCap         osd;
  ImageCap       image;
  AiCap          ai;

}DevAvCap;
//NVR扩展新增图片能力描述
typedef struct  
{
	unsigned short capability;          // BIT(1)-VEnc, BIT(2)-VDEC, BIT(3)-AEnc, BIT(4)-ADec
	unsigned short VEncDecTotalCap;     // 总的视频编解码能力
	unsigned int   property;            // 
	unsigned short VEncDecRatio[2];

	VEncCap        venc;
	AEncCap        aenc;
	VDecCap        vdec;
	ADecCap        adec;
	SpeechCap      speech;
	OsdCap         osd;
	ImageCapEx       image;
	AiCap          ai;

}DevAvCapEx;
/** @}*/	// end of addtogroup grSystem

/** @addtogroup grAV
 *  @{
 */
struct AEncoder   
{ 
  char enabled;               //使能: YES(1)|NO(0) 
  char codec;                 //mp2(2)|g.726(26) 
  char sampleRate;            //khz 
  char stereotype;            //静音（0），左（1），右（2），双（3）   
  unsigned int bitrate;       //码率 kbits/s: 32|48|64 
};

//视频编码参数
struct VEncoder   
{ 
	char enabled;                   //使能: YES(1)|NO(0) 
	char codec;                     //mpeg4(1)|mjpeg(2)|h264(4) 
	char resolution;                //QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5) 
	char frameRate;                 //: 1-30, 10x=1/x 
	unsigned char iFrameInterval;   //1-200 
	char filter;                    //滤波等级: 0-7 
	char quantizer;                 //量化值:2-31 
	char bitrateMode;               //码率控制：CBR(1)|VBR(2)| ABR(3)
	unsigned int bitrate;           //码率:kbits/s:   
	char res[4];                    // 
}; 
//视频编码参数(NVR扩展在VEncoder中增加MJPEG编码能力表述)
struct VEncoderEx
{
  char enabled;                   //使能: YES(1)|NO(0) 
  char codec;                     //mpeg4(1)|mjpeg(2)|h264(4) 
  char resolution;                //QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5) 
  char frameRate;                 //: 1-30, 10x=1/x 
  unsigned char iFrameInterval;   //1-200 
  char filter;                    //滤波等级: 0-7 
  char quantizer;                 //量化值:2-31 
  char bitrateMode;               //码率控制：CBR(1)|VBR(2)| ABR(3)
  unsigned int bitrate;           //码率:kbits/s:   
  unsigned char mjpegResolution;
  //Disabled(0)|QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) | 1080P(14)
  unsigned char mjpegQuality; //最差(1) | 标准(5) | 最好(9)
  unsigned char mjpegFrameRate; //1-5或者 10x=1/x
  char   codecgrade;  //仅 codec  为 H264 时有效； //0:Invalid， 1： Baseline； 2： Main profile； 3： High profile
};
enum
{
	DVX_VEDIO_RESOLUTION_QCIF      = 1,
	DVX_VEDIO_RESOLUTION_CIF       = 2,
	DVX_VEDIO_RESOLUTION_HALFD1    = 3,
	DVX_VEDIO_RESOLUTION_D1        = 4,
	DVX_VEDIO_RESOLUTION_DCIF      = 5,
	DVX_VEDIO_RESOLUTION_CIF_R     = 6,
	DVX_VEDIO_RESOLUTION_D1_R      = 7,
	DVX_VIDEO_RESOLUTION_720I      = 11,
	DVX_VIDEO_RESOLUTION_720P      = 12,
	DVX_VIDEO_RESOLUTION_1080I     = 13,
	DVX_VIDEO_RESOLUTION_1080P     = 14,
	DVX_VIDEO_RESOLUTION_960H      = 15,
	DVX_VIDEO_RESOLUTION_720P_R    = 16,
	DVX_VIDEO_RESOLUTION_1080P_R   = 17,
	DVX_VIDEO_RESOLUTION_1280x960 = 40,
	DVX_VIDEO_RESOLUTION_1600x1200 = 41,
	DVX_VIDEO_RESOLUTION_1024x768 = 42,
	DVX_VIDEO_RESOLUTION_2048x1536 = 43,
	DVX_VIDEO_RESOLUTION_640x480 = 44,
	DVX_VIDEO_RESOLUTION_1920x1024 = 45,
	DVX_VIDEO_RESOLUTION_800x600 = 46, 
	DVX_VIDEO_RESOLUTION_1280x1024 = 47,
	DVX_VIDEO_RESOLUTION_320x180 = 48,
	DVX_VIDEO_RESOLUTION_320x240 = 49,
	DVX_VIDEO_RESOLUTION_640x360 = 50,
	DVX_VIDEO_RESOLUTION_720x576 = 51,
	DVX_VIDEO_RESOLUTION_800x450 =52,
};

//音视频编码参数
struct Encoder 
{ 
	char profile;            //画质编号(1-6) 
	char media;              //视频(1)|音频(2)|混合(3) 
	char res[2]; 
	VEncoder vencoder; 
	AEncoder aencoder; 
}; 
//音视频编码参数（NVR扩展在VEncoder中增加MJPEG编码能力表述）
struct EncoderEx 
{ 
	char profile;            //画质编号(1-6) 
	char media;              //视频(1)|音频(2)|混合(3) 
	char audioGain;          //音频增益，取值0~ 9(协议上错误)
	char audioInType ;/// 0：Line IN ; 1 :Mic IN
	VEncoderEx vencoder; 
	AEncoder aencoder; 
}; 

//音视频描述
struct AVDescribe 
{
	unsigned char vcodes;            //bit1=MP4,bit2=MJPEG,bit3=H264 
	unsigned char acodes;            //bit1=MP2,bit2=G.72x 
	unsigned char systems;           //bit=PAL,bit2=NTSC 
	unsigned char SDResolut;          //bit1=QCIF,bit2=CIF,bit3=halfD1,bit4=D1,bit5=DCIF,bit6=HD 
	//当bit6=HD被置位时，须参考HDResolution中的定义 
	unsigned char HDResolution;      //bit1=720I,bit2=720P,bit3=1080I,bit4=1080P 
	unsigned char NSDResolution;     //非标准分辨率 //bit1:1280*960 ,bit2 :1600 *1200, bit3:2048* 1536, bit4 :640*480  
	//bit5 :1920*1024, bit6 :800x600,bit7 :1280x1024 ,bit8 : 1024x768
	unsigned char NSDres02;             //bit1:320x180, bit2:320x240, bit3:640x360, bit4: 720x576, bit5:800x450,
	unsigned char bitstreams;        //bit1=MAIN,bit2=SUB1,bit2=SUB2…  最大支持8个码流
};

//音视频能力扩展
struct AVDescribeEx
{
	AVDescribe base;
	char res[4];
	char profilecap;/// bit1：Baseline；bit2：Main profile；bit3：High profile
	char res2[19];
};

//系统编码能力配置方案列表
#define  AV_CAPRECIPE_MAX_COUNT 32
#define  AV_CAPRECIPE_MAX_ITEM  64

struct RecipeItem
{
	unsigned char  resol ; // 分辨率,具体参照bsfp 协议
	unsigned char  resv1[3]; // 保留
	int            max_framerate ; //最大支持帧率
	unsigned char  availnum; //可适用通道数
	unsigned char  resv2[3];
	unsigned char  chanmaps[16]; //适用通道映射
	unsigned char  resv3[4];
};

struct CapRecipe
{
	int items ;// item 个数
	int res ; // 保留
	RecipeItem rcpitem[AV_CAPRECIPE_MAX_ITEM] ;
};

struct  AVCapRecipeList
{
	int count ; // 编码能力描述配方数
	int resv ;//保留
	CapRecipe recipe[AV_CAPRECIPE_MAX_COUNT];
};



//转码参数描述
struct AVXEncoderCfg
{
	unsigned char isSupportTranslateEncoding;
	//TRUE(1) | FALSE(0)。表示设备是否支持转码功能。FALSE时，下列字段无效。
	unsigned char isEnableTranslateEncoding;
	//enable(1) | disable(0)。表示设备是否使能了转码功能。Disable时，下列字段无效。
	unsigned char maxTranslateEncodingCapability;
	// 转码占用的最大编解码能力，以D1为单位
	// 目前单路1080P30转码到标清，占用8D1能力。
	// 目前单路720P30转码到标清，占用4D1能力。
	unsigned char res;
	unsigned int  sourceResolution;
	//下列BITMAP
	//QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) | 1080P(14)
	//	在当前版本中，只有720P和1080P两位可被配置
	unsigned int destResolution;
	//下列BITMAP
	//QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) | 1080P(14)
	//在当前版本中，只有CIF或者D1可以被配置
	char res2[244]; //保留
};

//通道叠加字符
struct AVInputCfg 
{ 
	char disabled;    //NO(0)|YES(1) 
	char res[3];     //保留 
	char name[64];   //通道名 
}; 

//视频通道参数获取入参
struct AVInputParaIn
{
  unsigned int chanmap;  //有效通道(bitmap) 
  unsigned int res[3]; 
};

//所有通道叠加字符
struct AVInputPara 
{
	unsigned int channels;        //通道(bitmap) 
	AVInputCfg   avInputCfgList[16]; 
};

//所有通道叠加字符，每个通道4个通道名称
struct AVInputParaEX 
{
  unsigned int chanmap;  //有效通道(bitmap) 
  unsigned int res[3]; 
  unsigned int   mxCount ;//  系统最大通道数 
  AVInputCfg   avInputCfgList[NVR_MAX_CHANNEL_COUNT][4];   ///  每个通道有 4 个通道名称信息；
};

//图象参数
struct AVPicture 
{ 
	unsigned char brightness;   //亮度(0-100)，-1 为忽略 
	unsigned char contrast;     //对比度(0-100)，-1为忽略 
	unsigned char saturation;   //饱和度(0-100)，-1为忽略 
	unsigned char hue;          //色度(0-100)，-1为忽略 
};

//图象参数扩展（使色度和锐度两个字段不再复用）
struct AVPictureEx
{
	char brightness; //亮度(0-100)，-1为忽略
	char contrast; //对比度(0-100)，-1为忽略
	char saturation; //饱和度(0-100)，-1为忽略
	char hue; //色度(0-100)，-1为忽略；
	char sharpness; //锐度(0-100)，-1为忽略；
	char res[3]; //保留
};

//单个通道图象参数配置
struct  AVPictureCfg
{
	AVPicture pics[5];           //每元素为下面一时段   
	TimeSlice timeSlices[5];     //每天 4个时段 
};
//单个通道图象参数配置(使色度和锐度两个字段不再复用)
struct  AVPictureCfgEx
{
	AVPictureEx pics[5];           //每元素为下面一时段   
	TimeSlice timeSlices[5];     //每天 4个时段 
};

//所有通道图象参数配置
struct  AVPicturePara
{
	unsigned int channels;      //通道(bitmap) 
	char enabled;               //固定为1
	char impromptu;             //是否为实时预览模式
	char res[2];
	AVPictureCfg avPictureCfgList[16]; 
};
//所有通道图象参数配置扩展（使色度和锐度两个字段不再复用）
struct  AVPictureParaEx
{
	unsigned int channels;      //通道(bitmap) 
	char enabled;               //固定为1
	char impromptu;             //是否为实时预览模式
	char res[2];
	AVPictureCfgEx avPictureCfgList[16]; 
};

//叠加字符位置等参数
struct AVImprint 
{ 
	char           enabled; //YES(1)|NO(0)
	char subjects; //!(bitmap)叠加的主体
	//PREVIEW(1)//STREAM(2)//BOTH(3)
	char res;
	char content;     //叠加的内容;TIME(1)|NAME(2)
	unsigned short x; //左上角水平象素位置 
	unsigned short y; //左上角垂直象素位置位置 按照 704x576分辨率的标准坐标  
}; 

// AVImprintfCfg
enum
{
  DVX_AV_IMPRINT_TIME   = 0,				//时间
  DVX_AV_IMPRINT_NAME   = 1,				//通道名称
	DVX_AV_IMPRINT_CARD_ID   = 2,			//卡号
	DVX_AV_IMPRINT_DEVICE_NAME   = 3,	//设备名称
};
typedef AVImprint AVImprintfCfg[4];
/*
注：每通道可有4个叠加内容，当前仅使用 2个，
规定： 
imprintCfgList[i][0]: 固定为时间，content=1 
imprintCfgList[i][1]: 固定为名称，content=2 
imprintCfgList[i][2]：保留，content=0 
imprintCfgList[i][3]：保留，content=0 
*/

#define  DVX_AV_IMPRINT_BLEND   1
#define  DVX_AV_IMPRINT_FILMY   2

enum
{
	DVX_AV_IMPRINT_TYPE_SYSTEM       = 1,
	DVX_AV_IMPRINT_TYPE_TEXT         = 2,
	DVX_AV_IMPRINT_TYPE_ICON         = 3,
	DVX_AV_IMPRINT_TYPE_FRAMEHEADER  = 4,
	DVX_AV_IMPRINT_TYPE_FRAMEBODY    = 5,
};

//dvr通道嵌印内容
struct AVInputImprintPara 
{
	unsigned int channels;            //通道(bitmap) 
	char enabled;
	char res[3];
	AVImprintfCfg  AVImprintList[16];  //每个通道信息嵌印内容(共 4个) 
};

struct ChanNamePrint
{ 
  char   use; //YES(1)|NO(0)，忽略 not use 的配置项
  char subjects; //!(bitmap)叠加的主体 //PREVIEW(1)| //STREAM(2)| //BOTH(3) 
  char    res[2] ; 
  unsigned short x;   //左上角水平象素位置 
  unsigned short y;   //左上角垂直象素位置位置 
};

struct ChanPrints
{ 
  char           enable ;   
  unsigned char  mask;//4个 chan  水印的有效 bitmap 
  char           res[2]; 
  ChanNamePrint  cprintInfo[4]; 
};

//dvr通道嵌印内容4通道名称设置
struct AVInputImprintParaEX
{
  unsigned int chanmap;  //有效通道(bitmap) 
  unsigned int res[3]; 
  unsigned int mxCount ;//  系统最大通道数 
  ChanPrints chanPrints[NVR_MAX_CHANNEL_COUNT] ; 
};

//视频遮挡网格
struct Mesh 
{ 
	unsigned char res;    
	unsigned char grain;             //颗粒度,固定为 16 
	unsigned char width;             //横向实际网格数 
	unsigned char height;            //纵向实际网格数 
	unsigned char grids[22][18];  	 //!为 22x18 的矩阵，可容纳 704x576 的32x32的宏块 
	//每个元素 对应一个 grain*grain 大小的宏块, YES(1)|NO(0)     
}; 

//视频遮挡参数
struct AVMaskCfg 
{ 
	char enabled;   
	char subject;    //!(bitmap)遮盖内容(方式) DVX_AVMASK_TYPE_PREVIEW(1)|//DVX_AVMASK_TYPE_STREAM(2)| //BOTH(3) 
	char res[2];     //保留 
	Mesh mesh; 
}; 
enum
{
	DVX_AVMASK_TYPE_PREVIEW  = 0x0001,
	DVX_AVMASK_TYPE_STREAM   = 0x0002,
	DVX_AVMASK_TYPE_BOTH     = (DVX_AVMASK_TYPE_PREVIEW | DVX_AVMASK_TYPE_STREAM),
};

//视频输入遮挡参数
struct  AVInputMaskPara 
{
	unsigned int channels;     //通道(bitmap) 
	char enabled;    
	char res[3];     
	AVMaskCfg AVMaskCfgList[16]; 
};
//视频嵌印( 水印) 的颜色参数
struct  AVInputColorCfg
{
	unsigned char transparence;//表示叠加透明度取值范围[0-99]，0 表示全透明
	unsigned char frontColorIndex;//字体前景色索引
	unsigned char backColorIndex;//字体背景色索引
	unsigned char res;//保留
	unsigned char customizedFrontColor[4];//下标[0] R 分量，下标[1] G 分量，下标[2] B 分量。下标[3] 保留
	//unsigned char customizedBackColor[4] ;//下标[0] R 分量，下标[1] G 分量，下标[2] B 分量。下标[3] 保留
};

//视频输出嵌印参数
struct  AVOutImprintPara
{
	unsigned int channels;              //通道(bitmap) 
	AVImprint  AVImprintList[16][4];  	//每个通道信息嵌印内容(共 4个) 
};

//编码参数
struct  EncoderPara
{
  unsigned int channels;     //通道(bitmap) 
  char bitstreams;           //主码流(DVX_ENCODER_MAINSTREAM)|子码流(DVX_ENCODER_SUBSTREAM) 
  char res[3]; 
  Encoder  encoderList[16]; // 
};
//编码参数（NVR扩展在VEncoder中增加MJPEG编码能力表述）
struct EncoderParaEx
{
	unsigned int channels;     //通道(bitmap) 
	char bitstreams;           //主码流(DVX_ENCODER_MAINSTREAM)|子码流(DVX_ENCODER_SUBSTREAM) 
	char jpegInfoIdentflag;//0 : mjpegResoInfo 标识分辨率,1: mjpegResoInfo 标识jpeg 与其他码流一致； 具体参见mjpegResoInfo 说明;
	char ver ;// 
            //0x02：支持按位操作 bitstreams  
            //              //即： 
            //     ver为 0， 1时 兼容老的版本； 
            //     主码流(0)|第一子码流(1)|  第二子码流(2)… …第
            //     七子码流(7) 
            //     针对高清 IPC，0表示 1080P码流，1 表示720P
            //     码流，2 表示D1 码流，3 表示CIF码流 
            //     ver为 2 : 开始支持按位操作 bitstreams 
            //     Bit(0)..Bit(N) 依次按主子，或第 N 码率排序，
            //     不按分辨率划分；支持同时请求或设置多个码流配置； 
	char res2; 
	EncoderEx  encoderList[16]; // 

};

struct ROICfg
{
	unsigned char ROILevel; //取值范围1-9
	unsigned char enable;   //1：使能，0：禁用 
	unsigned char res[2];//保留
	Mesh mesh; //窗格区域
};
//编码ROI参数
struct ROIEncoderpara
{
	unsigned int channels; //有效通道(bit1-16=CH1-16)
	ROICfg cfg[16]; //各通道的ROI配置
};
//0通道编码参数
struct ZeroCfg
{
	unsigned int resolution;// bitmap 当前仅支持D1、CIF //QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5)|720P(12) |1080P(14)
	unsigned int bitRate;
	char	 res[16];
};
enum
{
	DVX_ENCODER_MAINSTREAM  = (0),
	DVX_ENCODER_SUBSTREAM   = (1),
};

//运动检测配置
struct AVMotionDetectCfg
{ 
	char enabled;   
	char raises;      //bitmap触发方式: IMAGE(1)|ALARM(2)
	char tracks;      //bitmap 跟踪轨迹:    SPOT(1)|OBJECT(2) 
	char alarmInput;  // <V1.1.03> raises为YES时，表示报警端子号，0任意端子，(1-16)表示特定端子号
	Mesh mesh; 
	Timetable   timetable;   
}; 
enum
{
	DVX_AV_MOTION_DETECT_RAISES_IMAGE		= (1),
	DVX_AV_MOTION_DETECT_RAISES_ALARM		= (0),
};

enum
{
	DVX_AV_MOTION_DETECT_SPOT      = (1),
	DVX_AV_MOTION_DETECT_OBJECT    = (2),
};

//运动检测参数
struct AVDetectMotionPara 
{
	unsigned int channels;      //通道(bitmap) 
	char enabled;   
	char res[3];    
	AVMotionDetectCfg AVMotionDetectCfgList[16]; 
};

//见协议
struct AVBlockDetectCfg  
{ 
	char enabled;   
	char res;    
  short delay;            // 延迟时间
	Mesh mesh; 
	Timetable timetable;   //[0-6]星期日,一~六 每天 4个时段 
}; 

//见协议
struct AVDetectBlockPara 
{
	unsigned int channels;    //通道(bitmap) 
	char enabled;   
  unsigned char maxRegions; // 取值为0或1表示全屏遮挡，其它值表示最大遮挡区域个数
	char res[2];   
	AVBlockDetectCfg  AVBlockDetectCfgList[16]; 
};

//视频丢失检测配置
struct  AVLossDetectCfg
{
	char enabled;   
	char res[3];    //保留 
};

//视频丢失检测参数
struct  AVDectectLossPara
{
	unsigned int channels;    //通道(bitmap) 
	char enabled;   
	char res[3];  
	AVLossDetectCfg  AVLossDetectCfgList[16]; 
};
//读取音效参数
struct SceneSoundCfg
{
	char outputList[4];
	char res[3];
	char loopback;
};
//搜索数字通道信息
struct NvrSearchInfo
{
	unsigned int total; // 搜索到的所有数字通道总数

};
//搜索数字通道参数
//struct AVDigitalChannelPara
//{
	//NvrSearchInfo searchInfo;
//};
//通道信息
struct NvrChannelInfo
{
	unsigned int ipAddr; //IP 地址
	unsigned int subMask; //子网掩码
	unsigned int gateway; //网关
	unsigned char domainName[64];//主机名
	unsigned char phyAddr[8]; //MAC 地址
	unsigned char useIp; //使用IP
	unsigned char useDomainName; //使用域名
	unsigned short cmdPort; //命令端口
	unsigned short streamPort; //流端口
	unsigned short advanceType; //高级类型,用于区分统一厂商不兼容的类型
	unsigned char brand[64];//设备厂商
	unsigned char name[64];//设备名称
	unsigned char user[64]; //用户名
	unsigned char passwd[64]; //密码
	unsigned int channelAmount;
	// 该IP 地址上通道的数量,仅0x0003.070x 时使用
	unsigned int channelAvailable;
	// 该IP 地址上通道的数量( 按位),仅0x0003.070x 时使用
	char alarmMode;//报警模式： 1:主动initiative，2：被动:Passive，0：非法invalid 目前仅用于onvif 上；
	char streamin_mode; // 接入码流模式	// 默认是0：双码流，1：单码流；
  char primaryAsIpChan; //以 IP 通道为主
	char onvif_proto;	// 0: over UDP，1：over TCP，仅onvif 有效
  unsigned char srcdevType;   //远程设备类型 0：IPC，1：DVS，2.DVR，3：NVR 
  unsigned char srcdevchanId;  ///远程设备通道编号
	unsigned char res[2];
};
//通道搜索输出参数
struct NvrFetchSearchInfo
{
	unsigned int rowId; //起始行编号/
	unsigned int rowCount; //本页实际记录个数(<=20)
	NvrChannelInfo infos[20]; //通道信息

};
//设置设备网络参数
struct	NvrSetDeviceNet
{
	unsigned char mac[6]; //要设置的MAC 地址
	unsigned char recv[2]; //字节补齐
	unsigned long ipaddress; //IN_ADDR类型的网络字节序组播网IP
	unsigned long submask; //IN_ADDR 类型的网络字节序子网掩码
	unsigned long gateway; // IN_ADDR 类型的网关
	char username[20]; //用户名
	char password[20]; //用户密码
	unsigned short wPortWeb; //网页端口（数据端口）
	unsigned short wPortSer; //控制端口（按20130529新协议修改）
	unsigned char brand[32]; //设备厂商
	unsigned char name[32]; //设备名称
};
//增加数字通道
struct  NvrAddChannelParam
{
	unsigned int channel; //NVR 通道号dest
	unsigned int dvsChannel; //远程通道编号src
	NvrChannelInfo info; //信息in

};
//获取数字通道属性
struct NvrGetChannelProp
{
	unsigned int channel; //NVR 通道号
	NvrChannelInfo info; //无用
};
//修改数字通道属性
struct NvrModChannelProp
{
	unsigned int channel; //NVR 通道号
	NvrChannelInfo info; //信息in

};
//获取设备版本信息
struct NvrGetDeviceVersion
{
	unsigned int channel; //NVR 通道号
	unsigned char version[64]; //版本 没用
};
//设备列表
struct NvrDeviceInfo
{
	unsigned int    count;                      /**< 通道个数 */
	unsigned int    channel[16];   /**< NVR通道号列表 */
	NvrChannelInfo  info;                       /**< 信息out */
};
//获取设备列表
struct  NvrGetDeviceInfos
{
	unsigned int count; //设备数量
	NvrDeviceInfo infos[16]; //设备列表
};
//获取数字通道状态
struct NvrChannelState
{
	unsigned int channel; //NVR 通道号
	unsigned char onLine; //是否在线
	unsigned char connectNum;//连接数
	unsigned char res[2]; //保留字段

};
//获取通道列表，包括模拟和数字通道
struct NvrGetChannelInfos
{
	unsigned int count; //通道数量
	int channels[NVR_ALERT_MAX_NUM]; //对应的远程设备通道号（占位时>=0），-1为当前不占位
	int devChannels[NVR_ALERT_MAX_NUM]; //对应的远程设备通道号（占位时>=0），-1为当前不占位
	NvrChannelInfo infos[NVR_ALERT_MAX_NUM]; //通道列表
};
//获取已存在的通道号列表
struct NvrGetExistChannels
{
	unsigned int counts; /**< 通道数量 */
	unsigned int channels[NVR_ALERT_MAX_NUM]; /**< int掩码 0为可用 1为不可用 */ 
} ;
//获取模拟数字通道掩码
struct NvrGetAnalogChannels
{
	unsigned int counts; /**< 通道数量 */
	unsigned int channels[NVR_ALERT_MAX_NUM]; /**< int掩码 1为数字 0为模拟 */

};
//变换通道类型
struct NvrSetChannelMode
{
	unsigned int nModifyFlag;		// bit map , modify flag
	NvrGetAnalogChannels info;
};
//通道类型变换能力支持
struct NvrgetChannelModeCap
{
	unsigned int count; //通道数量
	unsigned int prop[NVR_ALERT_MAX_NUM] ; //0 不支持变换，1 支持模拟、数字变换
};
struct sysChanCap
{
	int SimulateCh; //模拟通道数
	int FigureCh;//数字通道数
};
//系统级通道变换能力组合
struct sysChanCapList
{
	int current; // 当前工作模式索引，从0~ count -1
	int count;/// 对应工作机型变换模式数量；
	sysChanCap cap[NVR_ALERT_MAX_NUM];
};

struct BrandInfo
{
	unsigned char brand[32];
	char res[28];
	USHORT cmdPort; //命令端口
	USHORT streamPort;// 流端口
	UCHAR user[32]; //用户名
	UCHAR passwd[32]; //密码
	UCHAR access_proto_name[32]; //接入协议名称,如bscp，onvif，sony-G5 等均可；
	char res1[64];
};
//支持厂家列表
struct SupBrandlist
{
	int count;
	BrandInfo brands[NVR_ALERT_MAX_NUM] ;
};

//上海深广基本配置信息
typedef struct
{
	char		    enable; /**<是否启用*/
	unsigned char   nHour; /**<时段：小时(0-23)*/
	unsigned char   nMinute; /**<时段：分钟(0-59)*/
	char			resolution; /**< CIF(0)|D1(1) */
	int				nChannelBit; /**<上传通道 (按位)*/
}SGDailyImageDetailSet;
/*@SGDailyImageSet 上海深广日常图片上传*/
struct SGDailyImageSet
{
	char enable;							/**<日常图像定时上传是否启用*/
	char num;								/**< 数量，目前支持2个*/
	char res[2];
	SGDailyImageDetailSet detailSet[8];    /**<日常图像时段详细设置*/
};

/** @SGAlarmSitConf 上海深广报警端子设置*/
struct SGAlarmSitConf
{
	char delay;          /** <延时时间 */
	char res[3];
	int nChannelBit;     /** <上传通道（按位） */
};
/** @SGAlarmCtrl 上海深广报警联动 */
struct SGAlarmCtrl{
	char enable;        /**< 是否启用*/
	char savePicTime;   /* 报警前图片需要保存时间 1-60(s)*/
	char interval;      /*警前图片保存时间内抓图的间隔1-5(s)*/
	char res;
	SGAlarmSitConf sit[16]; /*报警端子相关描述 */
};

struct SGAlarmCtrlEx{
	char enable;        /**< 是否启用*/
	char savePicTime;   /* 报警前图片需要保存时间 1-60(s)*/
	char interval;      /*警前图片保存时间内抓图的间隔1-5(s)*/
	char sitnum;
	SGAlarmSitConf sit[64]; /*报警端子相关描述 */
};

struct SGServerConf
{
	unsigned char centerAddr[32];  /**<监控中心地址可以是IP 地址字符串也可以是域名地址默 认 值 为 "sgdzpic.3322.org"*/
	unsigned short centerPort;     /**<监控中心端口默认端口(5901)*/
	unsigned short enableRunState; /**<运行状态*/
	SGAlarmCtrl alarmCtrl;         /**<报警联动上传图片*/
	SGDailyImageSet dailyImageSet;
};

struct SGServerConfEx
{
	unsigned char centerAddr[32];  /**<监控中心地址可以是IP 地址字符串也可以是域名地址默 认 值 为 "sgdzpic.3322.org"*/
	unsigned short centerPort;     /**<监控中心端口默认端口(5901)*/
	unsigned short enableRunState; /**<运行状态*/
	SGAlarmCtrlEx alarmCtrl;         /**<报警联动上传图片*/
	SGDailyImageSet dailyImageSet;
};
//获取上海深广AgentId
struct SGAgentId
{
	char corpCode[4]; /**< 公司代号*/
	char recorderSN[8]; /**<录像机序列号*/
};
struct LogUpFilter
{
	int filterIt; //0: 默认均不过滤，1：启用过滤；
	int logtype; //日志类型ID
};
//深广日志上传过滤器参数
#define  FILTER_MAX_NUM 64
struct LogUpLoad
{
	unsigned int count; // filter count
	LogUpFilter  filter[FILTER_MAX_NUM];
};

//获取网视星基本配置信息
struct cncPlatformConf
{
	char puId[64];                    /* 设备ID */
	char puName[64];                  /* 设备名 */
	char puPasswd[64];                /* 设备密码 */
	int csgPort;                      /* csg 端口号 */
	int mduPort;                      /* mdu 端口号 */
	char csgIp[32];                   /* csg ip 地址 */
	char mduIp[32];                   /* mdu ip 地址 */
	unsigned char enableFlag;         /*平台参数使能0:不启用; 1:启用 */
	unsigned char protocolType;       /* 视频流类型 1:tcp;	0:udp */
	unsigned char offRecord;          /*设备掉线录像 0:不启用; 1:启用. */
	unsigned char offUpload;          /*设备掉线录像上传 0:不启用; 1:启用. */
	unsigned char resv[4];
};
/** @}*/	// end of addtogroup grAV

/** @addtogroup grRecord
 *  @{
 */

//录像状态
struct AVRecordStatus 
{ 
	unsigned int status;        //!(bitmap)通道状态:空闲(0)|手工(1)|定时(2)|侦测(3)|报警(4) 
	char profile;       //画质 
	char disk;   //盘号(1-8) 
	char album;   //盘组(1-8) 
	char resolution;   //分辨率(同前) 
	char res[2];        // 
	short byteRate;   //平均码率(MB/h) 
	unsigned int startTime;      /*最早录像时间*/ 
	unsigned int endTime;        /*最晚录像时间*/ 
}; 

typedef enum
{
	CHANNEL_RECORD_IDLE  = 0,
	CHANNEL_RECORD_MANUAL  = 1,
	CHANNEL_RECORD_TIMING  = 2,
	CHANNEL_RECORD_DETECT  = 3,
	CHANNEL_RECORD_ALARM  = 4,
}AvRecordState;

//录像状态
struct AVRecordStatusList
{
	unsigned int   channels;         //通道(bitmap) 
	AVRecordStatus RecList[16];      //每个元素表示一通道 
};

//录像设置
struct AVRecordCfg 
{ 
	char enabled;                //YES(1)|NO(0) 
	char profile;                //缺省录像画质(1-6,Encoder.profile) 
	char resolution;             //DVX_VEDIO_RESOLUTION_QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5) 
	char preRecord;              //是否启用预录: NO(0)|YES(1) 
	int    preRecordPeriod;      //预录时间长度(秒): 10-300s 
	int res;    
};

struct AVRecordCfgList
{
	unsigned int    channels;    //通道(bitmap) 
	AVRecordCfg     avRecordCfg[16]; 
};

//定时录像
struct AVRecordPlan 
{ 
	char enabled;   
	char res[3];            //保留 
	Timetable timetable;    //[0-6]星期日,一~六 每天 6个时段 
}; 
//定时录像（NVR扩展）
struct AVRecordPlanEx 
{ 
	char enabled;   
	char res[3];            //保留 
	TimetableEx timetable;    //[0-6]星期日,一~六 每天 6个时段 
}; 
struct AVRecordPlanList 
{ 
	unsigned int   channels;        //通道(bitmap) 
	AVRecordPlan   avRecordPlan[16]; 
};
//NVR扩展
struct AVRecordPlanListEx 
{ 
	unsigned int   channels;        //通道(bitmap) 
	AVRecordPlanEx   avRecordPlan[16]; 
};

// DVX可选的码流列表
typedef struct  
{
	unsigned char  validCount;      // 有效码率个数，最大32
	unsigned char  res[2];
	unsigned char  need_nostd_ex;
	unsigned int   bitrates[32];    // kbps
	unsigned int D1Bits; //32 个码率中对D1 有效的bit位置1，无效置0
	unsigned int Cif2Bits;//32 个码率中对2CIF 有效的bit 位置1，无效置0
	unsigned int CifBits; //32 个码率中对CIF 有效的bit 位置1，无效置0
	unsigned int QcifBits; //32 个码率中对CIF 有效的bit 位置1，无效置0
	unsigned int P720Bits; //32 个码率中对720P 有效的bit位置1，无效置0
	unsigned int P1080Bits;//32 个码率中对1080P 有效的bit 位置1，无效置0
	unsigned int H960bits;//32 个码率中对960H 有效的bit 位置1，无效置0
	unsigned int resx[1];
}VideoBitrate;

typedef struct  
{
  unsigned char  validCount;      // 有效码率个数，最大32
  unsigned char  res[3];
  unsigned int   bitrates[32];    // kbps
  unsigned int   oggBits;
  unsigned int   mp2Bits;
  unsigned int   mp3Bits;
  unsigned int   accBits;
  unsigned int   adpcmBits;
  unsigned int   g711Bits;
  unsigned int   g719Bits;
  unsigned int   g726Bits;
  unsigned int   g729Bits;
  unsigned int   resx[4];
}AudioBitrate;

typedef struct  
{
  VideoBitrate  video[3];   // [0]-H264, [1]-MPEG4, [2]-MJPEG
  AudioBitrate  audio;  
}BitrateList;
//非标码流列表
struct NsdBitrateList
{
 unsigned int nr;
 unsigned int res[3]; // 保留
 unsigned int bitrate[DVX_NSD_RESOLUTION_MAX_NUM];
};
struct PicRecStatus
{
	unsigned int status; //!(bitmap)通道状态:空闲(0)|
	//手工(bit1)|定时(bit2)|侦测(bit3)|报警(bit4)
	char		 res1;
	char		 disk; //盘号(1-8)
	char		 album; //盘组(1-8)
	char		 resolution; //分辨率(同前)
	char		 res2[4]; //
	time_t		 startTime;/*最早抓图录像时间*/
	time_t		 endTime;/*最晚抓图录像时间*/

};
struct PicRecStatusSimple
{
	unsigned int status; //!(bitmap)通道状态:空闲(0)|
	//手工(bit1)|定时(bit2)|侦测(bit3)|报警(bit4)
	char res[3];
	char resolution; //分辨率(同前)
};
//通道图片录像状态(NVR扩展)
struct PicRecordstate
{
	unsigned int channels; //有效通道(bit1-16=CH1-16)
	PicRecStatus picRecStatusList[16]; //每个元素表示一通道
};
//通道图片录像状态(为了0x0003.1030 Socket返回时间长添加这条命令)
struct PicstateSimple
{
	unsigned int channels; //有效通道(bit1-16=CH1-16)
	PicRecStatusSimple picRecStatusList[16]; //每个元素表示一通道
};
struct PicRecordCfg
{
	char enabled; //YES(1)|NO(0)
	char res1;
	char resolution;////QCIF(1)CIF(2)|halfD1(3)|D1(4)|DCIF(5) | 720P(12) | 1080P(14)
	char preRecord; //是否启用预录: NO(0)|YES(1)
	int preRecordPeriod; //预录时间长度(秒): 10-300s
	int res2; //
};
//通道图片录像参数
struct AVPicRecordCfg
{
	unsigned int channels; //有效通道(bit1-16=CH1-16)
	PicRecordCfg picRecordCfg[16];
};
//手工启动图片录像
struct AVPicRecordStartPara
{
	unsigned int channels; //有效通道(bit1-16=CH1-16)
	char		 typeList[16]; //对应通道的类型表
	//手工(1)|定时(2)|侦测(3)|报警(4)|卡号
};
//启动定时图片录像
struct  AVPicRecordTimeStarPara
{
	unsigned int channels; //有效通道(bit1-16=CH1-16)
	char		 res[16];

};
//音视频编码语法
struct EncoderProfile 
{
	Encoder profileList[4][6];
};
/** @}*/	// end of addtogroup grRecord


/** @addtogroup grDome
 *  @{
 */

//云台配置
struct AVDomeCfg 
{ 
	unsigned int channels;          //通道(bitmap) 
	UartCipher    cipherList[16];   
}; 

//云台预置位
struct AVDomePresets
{
	unsigned int channels;      //通道(bitmap) 
	int count;                  //个数 
	char presets[256];          //!每个元素对应一个预置位 !下标等于预置位编号 
	//! OFF(0)|ON(1)     
};
//云台预置位(64路扩展)
struct AVDomePresetsEx
{
	unsigned long long channels;      //通道(bitmap) 
	int count;                  //个数 
	char presets[256];          //!每个元素对应一个预置位 !下标等于预置位编号 
	//! OFF(0)|ON(1)     
};
enum
{
	DVX_DOMEPRESET_OFF		= (0),
	DVX_DOMEPRESET_ON			= (1),
};

//云台路经
struct HopCfg
{
  unsigned short stay;       //驻留时间(s): 
  unsigned char speed;       //速度(1-5) 
  unsigned char hopIndex;    //驻留点编号
};

struct DomeRoute
{ 
  unsigned char enabled;     // YES(1); NO(0)
  unsigned char count;       // 驻留点个数，扩展最大个数为255个
  unsigned short res;        // 保留
  HopCfg        hops[255];   // 驻留点列表
}; 

//云台巡检
struct AVDomePatrol
{
	unsigned int channels;       //通道(bitmap) 
	int count;                   //路径个数 
	DomeRoute domeRouteList[16]; 
};
//云台巡检(64路扩展)
struct AVDomePatrolEx
{
	unsigned long long channels;       //通道(bitmap) 
	int count;                   //路径个数 
	DomeRoute domeRouteList[64]; 
};

// 云台轨迹
struct AVDomeTrailStatus
{
  unsigned int channels;      // 通道(bitmap)
  int count;                  // 轨迹个数, 不超过16
  unsigned char pathsEnabled[16]; // OFF(0) | ON(1)
};

// 云台轨迹(64路扩展)
struct AVDomeTrailStatusEx
{
	unsigned long long channels;      // 通道(bitmap)
	int count;                  // 轨迹个数, 不超过16
	unsigned char pathsEnabled[64]; // OFF(0) | ON(1)
};
// 云台扫描
struct AVDomeScanStatus
{
  unsigned int channels;      // 通道(bitmap)
  int count;                  // 个数，不超过16
  unsigned char pathsEnabled[16]; // OFF(0) | ON(1)
};
// 云台扫描(64了扩展)
struct AVDomeScanStatusEx
{
	unsigned long long channels;      // 通道(bitmap)
	int count;                  // 个数，不超过16
	unsigned char pathsEnabled[64]; // OFF(0) | ON(1)
};
/** @}*/	// end of addtogroup grDome

/** @addtogroup grSpeech
*  @{
*/
/// 对讲流打开参数
struct SpeechOpenPara
{
	int channel;		/**< 通道号，对应的音视频物理通道(0-16) */
	int transType;	/**< 传输协议，1=TCP,2=RTP,3=UDP */
	int transMode;	/**< 传输模式，1=主动模式，2=被动模式 */
	int ip;					/**< IP地址，被动时为0 */
	int port;				/**< 端口号，被动时为0(由服务器返回--固定3720) */
};

// 对讲流的配置参数
struct SpeechParameter
{
	int cmd;				/**< 命令 */
	int value;			/**< 命令值 */
};

/** @} */	// end of addtogroup grSpeech

/** @addtogroup grAlarm
*  @{
*/

/// 报警信息
struct DvxAlarmInfo
{
	unsigned char nProduct;		///< 设备的产品标识，说明见后
	unsigned int alarmEvent;
	int          chnnl;
	int			 lan;			//TuliPB多网卡Lan1:1 Lan2:2
	unsigned int srcIp;//网络字节序
	unsigned int identity;
	unsigned int alarmTime;
  unsigned int plen;
  long         flag;
  char          c_batch;      /* channel batch: 当上报通道数大于16 使用; 0:1~16,1:17~32 etc */
  unsigned long sequence;    ///< 系统从启动后发磅的累计报警计数
  char         payload[DVX_MAX_ALARM_PAYLOAD]; // 可变长附加信息，实际有效长度为plen
};

/// 报警格式
struct AlarmInfo5x
{
  ULONG nEvent;		/**< 报警事件 */
  ULONG nWhich;		/**< 通道号 */
  ULONG nData[3];	/**< 具体含义与event类别相关 */
  ULONG nSrcIP;		/**< 报警端IP */
  ULONG nSerial;	/**< 序列号(录象机网络编号) */
  ULONG nYear;		/**< 年 */
  ULONG nMonth;		/**< 月 */
  ULONG nDay;			/**< 日 */
  ULONG nHour;		/**< 时 */
  ULONG nMinute;	/**< 分 */
  ULONG nSecond;	/**< 秒 */
  ULONG nWeek;		/**< 周 */
};

/// 报警格式
struct AlarmInfo6x
{
  unsigned long nEvent;       ///< 报警事件
  unsigned long nWhich;       ///< 通道(zone or camera)
  char          nSlot;        ///< VSxxx(1604|1644|101)使用，表示报警源所辖录像机(1-16)编号，本机为0
  char          res[2];
  unsigned char nProduct;     ///< 设备的产品标识，说明见后
  unsigned char nMacId[8];    ///< 机器标识，前2字节为0，后6字节为第一块网卡的MAC地址
  unsigned long nIp;          ///< 本设备第一块网卡的IP地址
  unsigned long nIdentity;    ///< 系统从启动后发送的累计报警计数
  unsigned long nSequence;    ///< 系统从启动后发磅的累计报警计数
  unsigned int  nTime;        ///< 发生报警时的系统时间
  unsigned short nLength;     ///< 数据报总长度(除报头40字节)，0与472等效
  unsigned short plen;        ///< 负载信息实际长度：单位为字节
  char          payload[24];  ///< 可变长附加信息，实际有效长度为plen
};

typedef struct _m_udpLength
{
  unsigned short length;        /**< 数据报总长度(除报头40字节) ，0与472等效*/
  unsigned short plen;          /**< 负载信息实际长度：单位为字节*/

}UdpLength;

/// 报警格式
struct AlarmInfo7x
{
  unsigned long nEvent;       ///< 报警事件
  unsigned long nWhich;       ///< 通道(zone or camera)
  char          nSlot;        ///< VSxxx(1604|1644|101)使用，表示报警源所辖录像机(1-16)编号，本机为0
  char          flag;         ///BITMAP，BIT1: 0表示实时发生的报警，1表示断网期间发生的报警BIT2-8：保留
  char          c_batch;      /* channel batch: 当上报通道数大于16 使用; 0:1~16,1:17~32 etc */
  unsigned char nProduct;     ///< 设备的产品标识，说明见后
  unsigned char nMacId[8];    ///< 机器标识，前2字节为0，后6字节为第一块网卡的MAC地址
  unsigned long nIp;          ///< 本设备第一块网卡的IP地址
  unsigned long nIdentity;    ///< 系统从启动后发送的累计报警计数
  unsigned long nSequence;    ///< 系统从启动后发磅的累计报警计数
  unsigned int  nTime;        ///< 发生报警时的系统时间
  union
  {
    unsigned int    udpLength; //新的协议
    UdpLength       m_udpLength;
  };
  char          payload[472];  ///< 可变长附加信息，实际有效长度为plen
};

#if 0   // P440结构
///扩展报警格式
struct AlarmInfoEx
{
  unsigned long event;    /**< event type */
  unsigned long which;    /**< channel(zone or camera) */
  char  slot;             /**< 1604|1644使用 */
  char  res[2];           /**< 保留 */   
  char  product;          /**< 产品标识 */
  char macid[8];          /**< mac地址0 */
  unsigned long ip;       /**< 本设备地址，可为空 */
  unsigned long id;       /**< 自动注册服务器分配的设备id编号 */    
  unsigned long sequence; /**< 系统从启动后的累计报警计数 */
  unsigned int time;      /**< 时间 */

  unsigned int res1[5];   /**< 保留 */
};
#endif


typedef struct
{
  char magic[4]; //Vector头结构关键字，永远为’V’ ‘C’ ‘T’ ‘\0’
  unsigned int len; //表示后续携带的一个或者多个Vector的总长度，不包含本数据结构长度。
  unsigned short vectorCount; //后续携带的Vector个数
  unsigned char res[6]; //保留
}ALARM_INFO_VectorHeader;

typedef struct
{
  unsigned int vectorType; //图片上传(2)
  unsigned int len; //本vector的数据长度，取值为本结构体长度 + 变长图片内容长度
  char magic[4]; //图片分隔符，永远为’P’ ‘I’ ‘C’ ‘\0’
  unsigned int time; //抓图的时间
  char name[128]; //图片名称
  unsigned char format; //图片格式，JPEG(1), BMP(2), GIF(3), YUV422(4), YUV420(5)
  unsigned char resolution; //分辨率，见BSCP对分辨率的定义
	unsigned char sourceType; //抓图源类型：0：Event（如：警前/警后），1：persist_links 事件联动的持续抓图，如图片流；
  unsigned char res;
  unsigned char data[0]; //图片内容
}ALARM_INFO_Vector_OnePicture;

struct AlarmPicInfo
{
  unsigned int len; //data的数据长度
  unsigned int time; //抓图的时间
  char name[128]; //图片名称
  unsigned char format; //图片格式，JPEG(1), BMP(2), GIF(3), YUV422(4), YUV420(5)
  unsigned char resolution; //分辨率，见BSCP对分辨率的定义
  unsigned char res[2];
  unsigned char data[0]; //图片内容
};

struct TCP_ALARM_INFO
{
  unsigned long event; /* type */
  unsigned long which; /* channel(zone or camera) */
  char slot; /* VSxxx(1604|1644|104)使用，表示报警源所辖录像机(1-16)编号,本机为0 */
  char flag;
  char res;
  unsigned char product; /*设备的产品标识，说明见后*/
  unsigned char macid[8]; /*机器标识，前2字节为0，后6字节为第一块网卡的MAC地址*/
  unsigned long ip; /* 本设备第一块网卡的IP地址*/
  unsigned long identity; /* 设备标识与编号*/
  unsigned long sequence; /* 系统从启动后发送的累计报警计数*/
  unsigned int time; /* 发生报警时的系统时间*/
  union
  {
    unsigned int    tcpLength; //新的协议
    UdpLength       m_tcpLength;
  };
  /* 以上为头部信息，总长40字节 */
  char payload[0]; /* 可变长附加信息，实际有效长度为tcpLength */
} ;

// DvxAlarmInfo中的alarmEvent的取值
typedef enum
{
  NET_SYSTEM_STATUS           = 0x2000,
  NET_RECORD_STATUS           = 0x2001,
  NET_DEVICE_STATUS          = 0x2003, //IPC DVS 状态报警2010-11-24
  EALARM_EVENT_REPORT_IP      = 0x2112,
  EALARM_EVENT_OUT            = 0x2113,
  EALARM_EVENT_HDISK_ERR      = 0x2114,
  EALARM_EVENT_VIDEO_LOST     = 0x2115,
  EALARM_EVENT_EVERYTHING_OK  = 0x2116,
  EALARM_EVENT_VIDEO_RESTORE  = 0x2117,
  EALARM_EVENT_CONTROL_1604E  = 0x2118,
  EALARM_EVENT_CONTROL_4004   = 0x2119,
  EALARM_EVENT_CTRL_4004      = 0x211A,
  EALARM_EVENT_VIDEO_COVER    = 0x211B,
  EALARM_EVENT_MOTION_DETECT  = 0x211C,
  EALARM_EVENT_NET_BREAK      = 0x211D,
  EALARM_EVENT_FAN_BREAK      = 0x211E,
  EALARM_EVENT_TIME_ERROR     = 0x211F,
  EALARM_EVENT_CHANNEL_ERROR  = 0x2120,
  EALARM_EVENT_DISK_FULL      = 0x2121,
  EALARM_EVENT_INVALID_LINK   = 0x2122,
  EALARM_EVENT_CHANNEL_CHANGE = 0x2123,
  EALARM_EVENT_REQUEST_TALK   = 0x2124,
  EALARM_EVENT_CARDNO_ALM     = 0x2125,
  EALARM_EVENT_ALG_ALM        = 0x2126,
  EALARM_EVENT_DVS_DEAD_DVR   = 0x2127,
  SMART_BE_STOLEN = 0x2132,
  SMART_BE_LEAVED = 0x2133,
  SMART_ALERT_AREA = 0x2134,
  SMART_CORDON = 0x2135,
  SMART_PEOPLE_COUNT = 0x2143,
  SMART_CENTRY = 0x2145,
  SMART_CONDUCT = 0x2146,
  EALARM_EVENT_MAINBOARD_ERR  = 0x2150,
  EALARM_EVENT_TEMPLERATURE_ERR= 0x2151,
  EALARM_EVENT_ALARM_INPUT    = 0x2152,
  EALARM_ILLEGAL_LOCAL_ACCESS = 0x2153,
  EALARM_ILLEGAL_NETWORK_ACCESS= 0x2154,
	NET_SD_ERROR = 0X2155,
  NET_SD_FULL = 0X2156,
  NET_DISK_SECTOR_ERROR = 0X2157,
  SMART_ATM_PROTECT = 0x2201,
  SMART_PEOPLE_CLOSE = 0x2202,
  SMART_LINGER = 0x2203,
  NET_IMP_AVD_CLARITYABNML = 0X2210,
  NET_IMP_AVD_BRIGHTABNML = 0X2211,
  NET_IMP_AVD_NOISEABNML = 0X2212,
  NET_IMP_AVD_COLORABNML = 0X2213,
  NET_IMP_AVD_NOSIGNAL = 0X2214,
  NET_IMP_AVD_FREEZE = 0X2215,
  NET_IMP_AVD_PTZLOSECRL = 0X2216,
  NET_IMP_AVD_INTERFERE = 0X2217,
  NET_IMP_AVD_SCENECHG = 0X2218,
	NET_IMP_LENS_MOTION = 0X2230,   //镜头移位检测
  NET_IMP_VIR_FOCUS = 0x2231,  //清晰度异常
  SMART_HUMAN_FACE = 0x2232,    //智能人脸检测
  NET_IMP_LEN_TAMPER = 0x2235,   //镜头篡改检测
  EALARM_NET_DEV_DISABLE       = 0x3100,
}EAlarmEvent;

// 系统状态报告
struct DvxMsgSystemStatus
{
  unsigned int time;    // 系统当前时间
  int          uptime;  // 系统总运行时间(秒)
  int          loads[3];   // 系统1, 5, 15分钟内平均负载
  int          totalram;// 系统总内存(MB)
  int          freeram; // 系统空闲内存(MB)
  int          bufferram;// 用于缓存的内存(MB)
  int          totalswap;// 系统总交换分区大小(MB)
  int          freeswap; // 系统空闲交换分区(MB)
  int          procs;   // 进程数
};

// 通道录像状态报告
struct RecStatus
{
  unsigned int status;  // (bitmap)通道状态：空闲(0), 手工(bit1), 定时(bit2), 侦测(bit3), 报警(bit4)
  char         profile; // 画质
  char         disk;    // 盘号(1-8)
  char         album;   // 盘组(1-8)
  char         resolution;// 分辨率(同前)
  char         res[2];
  short        byteRate;  // 平均码率(MB/h)
  unsigned int startTime; // 最早录像时间
  unsigned int endTime;   // 最晚录像时间
};

struct DvxMsgRecord_Status 
{
  unsigned int channels;  // 通道总个数
  RecStatus    recStatusList[16];
};

/** @}*/

//下载文件
struct DumpEvent 
{
	__int64 id;
	__int64 location;
};

//下载时间片
struct  DumpClip 
{
	unsigned int startTime;
	unsigned int endTime;
};

//申请下载流返回参数
struct RecordDumpOpenPara
{
	int channel;		// 目前没用
  int idxType;    // 指示index字段的类型
  index_t index;
  __int64 offset;	// 录像段开始的偏移量
  __int64 length;	// 长度(字节)
  int byteRate;
  int format;			//1 = bsfp 序列，2 = avi,//目前只支持bsfp格式

	int type;
  BOOL    bSaveAI;
};
//申请图片下载流返回参数
struct ImageDumpOpenPara
{
	int channel;		// 目前没用
	int idxType;    // 指示index字段的类型
	Imageindex_t index;
	__int64 offset;	// 录像段开始的偏移量
	__int64 length;	// 长度(字节)
	int byteRate;
	int format;			//1 = bsfp 序列，2 = avi,//目前只支持bsfp格式

	int type;
	BOOL    bSaveAI;
};
//下载参数设置
struct RecordDumpParameter
{
	int key;
	int value;
};
//图片下载参数设置
struct ImageDumpParameter
{
	int key;
	int value;
};

//手动开始结束录像结构
struct RecordOptPara
{
	unsigned int channel;    //有效通道(bit1-16=CH1-16) 
	char typeList[16];			 //对应通道的类型表 //手工(1)|定时(2)|侦测(3)|报警(4)|卡号(5)
};

//手动开始结束录像结构(64路扩展)
struct RecordOptParaEx
{
	unsigned long long channel;    //有效通道(bit1-16=CH1-16) 
	char typeList[64];			 //对应通道的类型表 //手工(1)|定时(2)|侦测(3)|报警(4)|卡号(5)
};
//手动触发报警输出端子
struct ManualRaiseAlertOut
{
  int alertOutId; // 报警输出端子号，从1 开始计数
  int action; //启动报警输出(1)；停止报警输出(0)
};


/**********************************************************************************/
// 通过 通知窗口 向SDK使用者发送的消息参数
enum
{
  // Dvx
  DVX_NOTIFY_LPARAM_DVX_DISCONN     = 0x01,
  // Real
  DVX_NOTIFY_LPARAM_REAL_DISCONNECT = 0x10,
  // Dump
  DVX_NOFIFY_LPARAM_DUMP_DISCONN    = 0x20,
  DVX_NOTIFY_LPARAM_DUMP_END				= 0x21,
  // Record
  DVX_NOTIFY_LPARAM_RECORD_PLAYEND	= 0x30,
  // Local Play
	DVX_NOTIFY_LPARAM_PLAYEND					= 0x40,
};

/**********************************************************************************/
// 返回值定义
enum
{
	/// 1.对于没有实现的方法或属性设置返回值均为 -1
	DVX_ERR_NOIMPL					= (-1),
	/// 2.函数执行成功，返回值均为 0
	DVX_OK									= (0),
	/// 3.对于小于0x10000均为dvr错误码

	/// 5.本地错误码：从0x20000开始
	DVX_ERR_BASE						= 0x00020000,

	/// 5.1一般性错误
	DVX_ERR_ASSERT					= (DVX_ERR_BASE + 0x1),		///< 出现了绝不应该出现的情况，基本上是SDK的问题
	DVX_ERR_MALLOCMEMORY		= (DVX_ERR_BASE + 0x2),		///< 分配内存出错，系统错误
	DVX_ERR_CREATE_EVENT		= (DVX_ERR_BASE + 0x3),		///< 创建Event句柄出错，系统错误
	DVX_ERR_CREATE_THREAD		= (DVX_ERR_BASE + 0x4),		///< 创建线程出错，系统错误
	DVX_ERR_PARA						= (DVX_ERR_BASE + 0x5),		///< 参数错误
	DVX_ERR_SDK_NO_INIT			= (DVX_ERR_BASE + 0x6),		///< SDK没有初始化
	DVX_ERR_DVX_NO_LOGIN		= (DVX_ERR_BASE + 0x7),		///< 还没有登录
	DVX_ERR_DVX_INVALID_HANDLE	= (DVX_ERR_BASE + 0x8),	///< 无效的DvxHandle句柄
	DVX_ERR_COMMON					= (DVX_ERR_BASE + 0x9),		///< 通用错误

	/// 5.2网络错误
	DVX_ERR_ERR_TRANS_OPEN	= (DVX_ERR_BASE + 0x21),  ///<打开传输流错误
	DVX_ERR_NET_DISCONNECT	= (DVX_ERR_BASE + 0x22),  ///<网络断开
  DVX_ERR_HELLO           = (DVX_ERR_BASE + 0x23),  ///<网络断开

	/// 5.3报警错误
	DVX_ERR_ALARM_DISABLE		= (DVX_ERR_BASE + 0x101),	///< 报警功能没有打开
	DVX_ERR_ENABLE_ALARM		= (DVX_ERR_BASE + 0x102),	///< 启动报警功能时出错
	DVX_ERR_NOMORE_ALARM    = (DVX_ERR_BASE + 0x103),	///< 没有更多的报警信息了

	/// 5.4现场错误
	DVX_ERR_REAL_INVALID_HANDLE	= (DVX_ERR_BASE + 0x201),	///< 无效的现场句柄

	/// 5.5对讲错误
	DVX_ERR_SPEECH_INVALID_HANDLE = (DVX_ERR_BASE + 0x301),	///< 无效的对讲句柄

	/// 5.6 本地回放错误
	DVX_ERR_LOCALPLAY_INVALID_HANDLE = (DVX_ERR_BASE + 0x401),	///< 无效的本地回放句柄
	DVX_ERR_LOCALPLAY_INVALID_FNAME = (DVX_ERR_BASE + 0x402),	  ///< 无效的本地回放句柄
	DVX_ERR_LOCALPLAY_NO_OPEN = (DVX_ERR_BASE + 0x403),	        ///< 本地回放，还没有打开

	/// 5.7 
	DVX_ERR_CREATE_FILE			= (DVX_ERR_BASE + 0x501), ///<创建文件失败
	DVX_ERR_NET							= (DVX_ERR_BASE + 0x901), ///<网络错误
	DVX_BSCP_BUSY						= (DVX_ERR_BASE + 0x902), ///<命令通道忙
	DVX_BSCP_TIMEOUT				= (DVX_ERR_BASE + 0x903), ///<bscp命令执行超时
	DVX_BSCP_NETERR					= (DVX_ERR_BASE + 0x904), ///<bscp网络错误
	DVX_ERR_INIT						= (DVX_ERR_BASE + 0x905), ///<初始化错误
	DVX_ERR_NET_INIT				= (DVX_ERR_BASE + 0x906), ///<网络初始化错误
};

///////////声讯协议结构///////////
//当前注册状态
typedef struct tagNET_SEC_BUREAU_STATE
{
  SHORT status;		//当前注册状态，小于0为离线； WAITING(-2), TRYING(-1), OFFLINE(0), ONLINE(1)
  SHORT error;		//上次注册返回的错误码
  UINT  serverAddr;	//当前服务器地址
} BSRCLIENT_NET_SEC_BUREAU_STATE, *PBSRCLIENT_NET_SEC_BUREAU_STATE;

//注册服务器设置
typedef struct tagNET_SEC_BUREAU_CFG
{
  CHAR	enabled;	//NO(0) | YES(1) | WAKEN(2), 是否启用注册功能,缺省2 
  CHAR	dial;		//NONE(0)|PPPOE(1)|CDMA(2)
  CHAR	res[2];
  UINT	serverAddr1; //注册服务器IPAddr,缺省为0 
  UINT	serverAddr2; //注册服务器IPAddr,缺省为0
  USHORT	serverPort; //注册服务器端口
  USHORT	resx; 
}BSRCLIENT_NET_SEC_BUREAU_CFG, *PBSRCLIENT_NET_SEC_BUREAU_CFG;

//配置命令
typedef enum
{
	// 1.系统管理 
	CONFIG_SYS_STATE	= 1,	
	CONFIG_SYS_GETVERSION,
	CONFIG_SYS_DESCRIBE,
	CONFIG_SYS_GETMODULES,
	CONFIG_SYS_GETIPCDVSSTATUS,
	CONFIG_SYS_GETIDENTITY,
	CONFIG_SYS_SETIDENTITY,
	CONFIG_SYS_GETTIME,
	CONFIG_SYS_SETTIME,
	CONFIG_SYS_GETTIMESTYLE,
	CONFIG_SYS_SETTIMESTYLE,
	CONFIG_SYS_GETLOCALE,
	CONFIG_SYS_SETLOCALE,
	CONFIG_SYS_GET_IPC_STATUS,
	CONFIG_SYS_SET_IPC_STATUS,
	CONFIG_SYS_SHELL ,
	CONFIG_SYS_TOP ,
	CONFIG_SYS_REBOOT,
	CONFIG_SYS_HALT,
	CONFIG_SYS_EXPORT,
	CONFIG_SYS_IMPORT,
	CONFIG_SYS_RESTORE, //(in SysRestore*)
	CONFIG_SYS_UPGRADE,
	CONFIG_SYS_BURNSTATE,
	CONFIG_SYS_GETSTATUPLOADCFG,
	CONFIG_SYS_SETSTATUPLOADCFG,

	// 3.网络管理 
	CONFIG_NET_LINKSTATE,
	CONFIG_NET_LINKGET ,
	CONFIG_NET_LINKSET ,
	CONFIG_NET_LINKTEST ,
	CONFIG_NET_LINKSTART ,
	CONFIG_NET_LINKSHUT ,

	CONFIG_NET_SERVICEGET ,
	CONFIG_NET_SERVICESET,
	CONFIG_NET_SERVICE_GETALERT,
	CONFIG_NET_SERVICE_SETALERT,
	CONFIG_NET_SERVICE_GETSMTP,
	CONFIG_NET_SERVICE_SETSMTP,
	CONFIG_NET_SERVICE_GETSMNP,
	CONFIG_NET_SERVICE_SETSMNP,
	CONFIG_NET_SIP_BASICPARAM_GET,
	CONFIG_NET_SIP_BASICPARAM_SET,
	CONFIG_NET_SIP_CHANIDENTCODE_GET,
	CONFIG_NET_SIP_CHANIDENTCODE_SET,
	CONFIG_NET_SIP_ALARMINSITDENTCODE_GET,
	CONFIG_NET_SIP_ALARMINSITDENTCODE_SET,

	CONFIG_NET_REPORT_CFGGET,
	CONFIG_NET_REPORT_CFGSET,

	CONFIG_NET_REGISTRY_STATE,
	CONFIG_NET_REGISTRY_GET,
	CONFIG_NET_REGISTRY_SET,
	CONFIG_NET_REGISTRY_LOGON,
	CONFIG_NET_REGISTRY_LOGOFF,

  CONFIG_NET_ADDRFILTER_GETCFG,
  CONFIG_NET_ADDRFILTER_SETCFG,
  CONFIG_NET_LOG_GETCONNECTLOG,
  CONFIG_NET_LINK_GETMULTICASEADDR,
  CONFIG_NET_LINK_SETMULTICASEADDR,

	// 4.安全管理 
	CONFIG_SECURITY_SESSION_LIST, //(Get in: NULL out:SecurtySessionList*)
	CONFIG_SECURITY_SESSION_LOGIN ,
	CONFIG_SECURITY_SESSION_LOGOUT,
	CONFIG_SECURITY_USER_ADD ,  //(Set in:SecurityUser*)
	CONFIG_SECURITY_USER_EDIT ,
	CONFIG_SECURITY_USER_DEL,   //(Set in:SecurityUser*)
	CONFIG_SECURITY_USER_LIST, //(in: NULL  out SecurityUserList*)
	CONFIG_SECURITY_USER_PASSWD,
	CONFIG_SECURITY_USER_PRIV_GET , //(Get in:char* UserName out:SecurityUserPriv*)
	CONFIG_SECURITY_USER_PRIV_SET , //(Set in:SecurityUserPriv*)
	CONFIG_SECURITY_ROLE_LIST ,
	CONFIG_SECURITY_ROLE_PRIV_GET, 
	CONFIG_SECURITY_ROLE_PRIV_SET, 

	// 8.存储管理 
	CONFIG_DISK_LIST ,
	CONFIG_DISK_DESCRIBE,
	CONFIG_DISK_STATE,
	CONFIG_DISK_WAKEN,
	CONFIG_DISK_CFG_GET,
	CONFIG_DISK_CFG_SET,
	CONFIG_DISK_FORMAT ,
	CONFIG_DISK_ALBUM_GET ,
	CONFIG_DISK_ALBUM_SET,
	CONFIG_DISK_SCHEM_GET,
	CONFIG_DISK_SCHEM_SET,

	// 9.串口管理 
	CONFIG_UART_PORT_GET,
	CONFIG_UART_PORT_SET,
	CONFIG_UART_CIPHER_LIST,
	CONFIG_UART_CIPHER_INSTALL,
	CONFIG_UART_SNOOP_GET ,
	CONFIG_UART_SNOOP_SET,
	CONFIG_UART_AGENT_GET,
	CONFIG_UART_AGENT_SET,

	// 10.报警管理 
	CONFIG_ALERT_ALARM_STATE ,
	CONFIG_ALERT_ALARM_ARM,
	CONFIG_ALERT_ALARM_DISARM,
	CONFIG_ALERT_ALARM_BYPASS,
	CONFIG_ALERT_ALARM_RESET,
	CONFIG_ALERT_ALARM_PASSWD,
	CONFIG_ALERT_ALARM_CFG_GET ,
	CONFIG_ALERT_ALARM_CFG_SET,
	CONFIG_ALERT_ALARMIN_STATE ,
	CONFIG_ALERT_ALARMIN_CFG_GET,
	CONFIG_ALERT_ALARMIN_CFG_SET,
	CONFIG_ALERT_ALARMOUT_STATE ,
	CONFIG_ALERT_ALARMOUT_CFG_GET,
	CONFIG_ALERT_ALARMOUT_CFG_SET,
	CONFIG_ALERT_ALARMOUT_START,
	CONFIG_ALERT_ALARMOUT_STOP,
	CONFIG_ALERT_ACTION_CFG_GET ,
	CONFIG_ALERT_ACTION_CFG_SET,
	CONFIG_ALERT_ACTION_ACK,
	CONFIG_ALERT_ACTION_RAISE,
	CONFIG_EVENT_ACTION_CFG_GET,
	CONFIG_EVENT_ACTION_CFG_SET,
	//智能
	CONFIG_ALG_DETECT_CFG_GET,
	CONFIG_ALG_DETECT_CFG_SET,


	// 1.通道管理 
	CONFIG_AV_DESCRIBE ,
	CONFIG_AV_CFG_GET,
	CONFIG_AV_CFG_SET,
	CONFIG_AV_INPUT_CFG_GET ,
	CONFIG_AV_INPUT_CFG_SET,
	CONFIG_AV_INPUT_PICTURE_GET,
	CONFIG_AV_INPUT_PICTURE_SET,
	CONFIG_AV_INPUT_IMPRINT_GET,
	CONFIG_AV_INPUT_IMPRINT_SET,
	CONFIG_AV_INPUT_MASK_GET,
	CONFIG_AV_INPUT_MASK_SET,
	CONFIG_AV_OUT_IMPRINT_GET ,
	CONFIG_AV_OUT_IMPRINT_SET,
	CONFIG_AV_ENCODER_CFG_GET ,
	CONFIG_AV_ENCODER_CFG_SET,
	CONFIG_AV_DETECT_LOSS_GET ,
	CONFIG_AV_DETECT_LOSS_SET,
	CONFIG_AV_DETECT_MOTION_GET, 
	CONFIG_AV_DETECT_MOTION_SET,
	CONFIG_AV_DETECT_BLOCK_GET,
	CONFIG_AV_DETECT_BLOCK_SET,
	CONFIG_AV_INPUT_BASICPARAM_GET,
	CONFIG_AV_INPUT_BASICPARAM_SET,
	CONFIG_AV_INPUT_BASICPARAM_WDRPARAM_GET,
	CONFIG_AV_INPUT_BASICPARAM_WDRPARAM_SET,
//红外半球自检
	CONFIG_AV_INPUT_GETIPC_IRCUT_CTRLPARAM,
	CONFIG_AV_INPUT_SETIPC_IRCUT_CTRLPARAM,
	CONFIG_AV_INPUT_IPC_IRCUT_STATE_GET,
	CONFIG_HARD_TEST_INFRARED_SET,
	CONFIG_HARD_TEST_INFRARED_GET,

	// 2.录像控制 
	CONFIG_AVRECORD_STATE ,
	CONFIG_AVRECORD_PROFILE_GET,
	CONFIG_AVRECORD_PROFILE_SET,
	CONFIG_AVRECORD_CFG_GET,
	CONFIG_AVRECORD_CFG_SET,
	CONFIG_AVRECORD_SCHEDULE_GET,
	CONFIG_AVRECORD_SCHEDULE_SET,
	CONFIG_AVRECORD_START ,
	CONFIG_AVRECORD_STOP,

	// 3.云台控制 
	CONFIG_AVDOME_CFG_GET ,
	CONFIG_AVDOME_CFG_SET ,
	CONFIG_AVDOME_CONTROL,
	CONFIG_AVDOME_PRESETS_GET ,
	CONFIG_AVDOME_PRESETS_SET ,
	CONFIG_AVDOME_PATROL_GET,
	CONFIG_AVDOME_PATROL_SET,
	CONFIG_AVDOME_TRACE_GET,
	CONFIG_AVDOME_TRACE_SET,
	CONFIG_AVDOME_SCAN_GET,
	CONFIG_AVDOME_SCAN_SET,
	CONFIG_AVDOME_GET_STATUS,

	// 4.录像检索/备份/回放(
	// 远程检索 
	/// @bug 当前检索部分，是同时有DVX6 和 DVX7的协议实现
	CONFIG_SEARCHLIST ,
	CONFIG_SEARCHDES,
	CONFIG_SEARCHPLOT,
	CONFIG_SEARCHXLATE,

	CONFIG_QUERYOPEN  ,
	CONFIG_QUERYCLOSE  ,
	CONFIG_QUERYFETCH,
	CONFIG_QUERYOPEN_ATM ,
	CONFIG_QUERYNARROW ,
	CONFIG_QUERYPLOT,
	CONFIG_QUERYCALENDAR,
	CONFIG_QUERYDESCRIBE,
	CONFIG_QUERYXLATE,
	CONFIG_QUERYPLOT_ATM ,

	//backup
	CONFIG_BACKUP_SCHEDULE_GET ,
	CONFIG_BACKUP_SCHEDULE_SET ,

	CONFIG_UI_STYLE_SET,
	CONFIG_UI_STYLE_GET,

	CONFIG_DVX_CMD_MAX,

	//声讯配置
	CONFIG_SHENGXUN_STATE,
	CONFIG_SHENGXUN_BASE,
	CONFIG_SHENGXUN_LOGON,
	CONFIG_SHENGXUN_LOGOFF,
	CONFIG_SHENGXUN_GETCFG,
	CONFIG_SHENGXUN_SETCFG,
	//色度控制
	CONFIG_AV_INPUT_PICTURE_GETEX,
	CONFIG_AV_INPUT_PICTURE_SETEX,
}EdvxConfigCmd;


/**@ enum EUmError
* 用户和组管理错误信息
*/
typedef enum
{
	ERR_ADMIND_AUTH_PARAM_ERROR          =(0x0006),    /**<参数错误*/
	ERR_ADMIND_AUTH_USER_NOT_EXIST       =(0x0201),    /**<用户不存在*/
	ERR_ADMIND_AUTH_DUP_USERNAME         =(0x0202),    /**<用户重名*/
	ERR_ADMIND_AUTH_USER_UP_LIMIT        =(0x0203),    /**<用户达到上限*/
	ERR_ADMIND_AUTH_PASSWD_ERROR         =(0x0204),    /**<用户密码错误*/
	ERR_ADMIND_AUTH_GROUP_UP_LIMIT       =(0x0205),    /**<用户组达到上限*/
	ERR_ADMIND_AUTH_GROUP_NOT_EXIST      =(0x0206),    /**<用户组不存在*/
	ERR_ADMIND_AUTH_LOGIN_UP_LIMIT       =(0x0207),    /**<登录达到上限*/
	ERR_ADMIND_AUTH_CAN_NOT_DEL_ADMIN    =(0x0208),    /**<不能删除超级管理员*/   
	ERR_ADMIND_AUTH_CAN_NOT_MODIFY_ADMIN =(0x0209),    /**<不能修改超级管理员信息*/        
	ERR_ADMIND_AUTH_CAN_NOT_DEL_USER      =(0x020a),    /**<不能删除已登录用户*/    
	ERR_ADMIND_AUTH_USER_GROUP_SAME_NAME = (0x020b),    /**<用户名不能是用户组名*/
	ERR_ADMIND_AUTH_PRIV_SET_FAIL        =(0x020c),    /**<权限设置错误*/   
	ERR_ADMIND_AUTH_INVALID_PWD_LEN      =(0x020d),    /**<密码设置长度错误*/        
	ERR_ADMIND_AUTH_PWD_DIFF             =(0x020e),    /**<原密码错误*/     
} EUmError;

//ipcdvs状态上传参数
struct SystemIpcDvsStatus
{
	unsigned char cameraStatus; //当前镜头状态 1-正常 2-异常
	unsigned char onlineUsers;  //当前登录用户数
	unsigned char videoStreamCount; //当前视频连接数
	unsigned char SDActive;         //SD卡在位 YES（1）| SD卡不存在NO（0）
	unsigned short bitRate[8];      //码率，单位为kbps，最大支持到8个码流
	unsigned int   earlistRecordTime; //SD卡最早录像时间
	unsigned long long totalSizeOnSD;     //SD卡最大容量
	unsigned long long  leftSizeOnSD;      //SD卡剩余容量
	unsigned char  res[8];
};

struct TimeSliceReport 
{
	unsigned char startHour;      //时间段起点的小时数(0-23) 
	unsigned char startMinute;    //时间段起点的分钟数(0-59) 
	unsigned char startSecond;    //时间段终点的秒数(0-59) 
	char          enabled;        //DVX_TIMESLICE_ENABLED_OFF(0) | DVX_TIMESLICE_ENABLED_ON(1) 
};
struct TimetableReport 
{
	unsigned char days;                //==7:   
	unsigned char slices;              //==4   
	unsigned char res[2];         
	TimeSliceReport     timeSliceList[7][4];     //[0-6]星期日,一~六
};
struct StatusUpload 
{
	char            enabled;   //启用 
	char            res[3];        
	TimetableReport timetable; //[0-6]星期日,一~六 //每天 6个时段 
};

// 系统状态配置结构
struct SmSysStatusPara
{
	unsigned char enStartTime;   //开机时间
	unsigned char enOneLoad;     // 1分钟平均负载
	unsigned char enTwoLoad;     // 5分钟平均负载
	unsigned char enThreeLoad;   // 15 分钟平均负载
	unsigned char enCurrentTime; // 当前系统时间
	unsigned char enTotalRam;    //总内存
	unsigned char enFreeRam;     //剩余内存
	unsigned char enBufferRam;   //缓冲内存
	unsigned char enCameraStatus; //当前摄像机状态
	unsigned char enFrameRate;     //当前码率
	unsigned char enSdFreeSpace;    //sd卡剩余容量
	unsigned char enSdRecEarlyTime;  //最早录像时间
	unsigned char enLoginNum;        //登陆用户数
	unsigned char enVideoConnectNum;  //当前视频连接数
	unsigned char res[2];
};

struct StatusUploadCfg
{
	unsigned int statusUploadCfg; //按位表示系统状态上 
	//传中各项的Enable/Disable 状态。
	//1 为Enable，0 为Disable。
	unsigned int res[3];//保留
};

//编码输入参数
struct EncoderPara_in
{
  unsigned int channels;     //通道(bitmap) 
  char bitstreams;           //主码流(DVX_ENCODER_MAINSTREAM)|子码流(DVX_ENCODER_SUBSTREAM) 
  char res1;
  char ver;   // //0x02：支持按位操作 bitstreams  即： 
                  //     ver为 0， 1时 兼容老的版本； 
                  //     主码流(0)|第一子码流(1)|  第二子码流(2)… …第
                  //     七子码流(7) 
                  //     针对高清 IPC，0表示 1080P码流，1 表示720P
                  //     码流，2 表示D1 码流，3 表示CIF码流 
                  //     ver为 2 : 开始支持按位操作 bitstreams 
                  //     Bit(0)..Bit(N) 依次按主子，或第 N 码率排序，
                  //     不按分辨率划分；支持同时请求或设置多个码流
                  //     配置； 
  char res2; 
};

typedef struct
{
	UCHAR enable;
	//不启用(0)；启用(1)
	//启用后，日夜转换动作按照设定的切换时间执行，和图像亮度无关。
	UCHAR res; //保留
	UCHAR d2nHour; //昼转夜时间点小时
	UCHAR d2nMin; //昼转夜时间点分钟
	UCHAR d2nSec; //昼转夜时间点秒
	UCHAR n2dHour; //夜转昼时间点小时
	UCHAR n2dMin; //夜转昼时间点分钟
	UCHAR n2dSec; //夜转昼时间点秒
}dayNightSwitchTime;


//基本图像调整参数
typedef struct
{
	UCHAR mode;     /*自动曝光(0)；手动曝光(1)*/
	UCHAR targetLuminance; /*目标亮度*/
	UCHAR exposureTime;  /*曝光时间设置*/
	/*1 - 1/25(40ms) 、2 - 1/50(20ms)、3 -1/125(8ms)、4 - 1/250(4ms)、5 - 1/500(2ms),6 - 1/1000(1ms)*/
  UCHAR exposureValue; // EV曝光量 
	/**     一下曝光时间，单位均为微妙  ****/
	UINT minExposureTimeLow;        /*最小曝光时间最小值*/
	UINT minExposureTimeHigh;       /*最小曝光时间最大值*/
	UINT minExposureTimeCurrent;    /*最小曝光时间当前值*/
	UINT minExposureTimeStrep;  /*最小曝光时间调整步长*/
	UINT maxExposureTimeLow;        /*最大曝光时间最小值*/
	UINT maxExposureTimeHigh;       /*最大曝光时间最大值*/
	UINT maxExposureTimeCurrent;    /*最大曝光时间当前值*/
	UINT maxExposureTimeStrep;  /*最大曝光时间调整步长*/
	UINT exposureSmoothStepsLow;    /*曝光平滑步数最小值*/
	UINT exposureSmoothStepsHigh;/*曝光平滑步数最大值*/
	UINT exposureSmoothStepCurrent;/*曝光平滑步数当前值*/
	UINT exposureSmoothStepsStep;/*曝光平滑步数调整步长*/
} exposureParam;

/** 
* @struct BackLightCompensationParam 
* 背光补偿结构体 
*/ 
typedef struct 
{ 
	UCHAR enable;           /* 背光补偿功能开关,0为不启用，1 为启用 */ 
	UCHAR blcSth;  /* 背光补偿级别,[0,255] */ 
	UCHAR   res[2];     
}BackLightCompParam; 

/** 
* @struct StrongLightCtrlParam 
* 强光抑制结构体 
*/ 
typedef struct 
{ 
	UCHAR enable;    /* 强光抑制功能开关,0 为不启用，1 为启用 */ 
	UCHAR slcSth;  /* 强光抑制级别,[0,255] */ 
	UCHAR res[2];      
}StrongLightCtrlParam; 

/** 
* @struct DigitalNoiseFilterParam 
* 数字降噪的结构体  
*/ 
typedef struct 
{ 
	UCHAR enable;           /* 3D降噪功能开关,0为不启用，1 为启用 */ 
	UCHAR sfDnfSth;   /* 空域降噪级别,[0,255] */ 
	UCHAR tfDnfSth;   /* 时域降噪级别,[1,3] */ 
	UCHAR res;      
}DigitalNoiseFilterParam; 

 // 增益控制参数  
struct Agcontrol
{ 
  UCHAR agcmode;  //  自动，手动 
  UCHAR min;      //  最小增益 
  UCHAR max;      //  最大增益 
  UCHAR value;    //  手动时的增益 
};


//  白平衡控制参数
struct WBcontrol
{ 
  UCHAR whilebalanceMode; //自动(0)；SUNNY(1)；SHADOW(2)； INDOOR(3)；LAMP(4); // 
  UCHAR red_value;      //手动时的红增益 
  UCHAR blue_value;     //  手动时的蓝增益 
  UCHAR res; 
}; 

//  曝光区域 
struct ExpZone
{ 
  UINT expzone_mode; // 0.无效 1.自定义 2.“中心50%四周50%”3. 中心 75%四周25%  4.中心25%四周 75%  5.中心100% 6. 四周 100% 
  UINT x ; // x坐标 
  UINT y ; // y坐标 
  UINT width ;//  宽 
  UINT height ; //  高 
  UINT quota ; //  权值 
};

//日夜切换状态信息（17）
struct DayNightState
{ 
  UCHAR daynight; // 1：白天，2.晚上； 
  UCHAR res[7];
}; 

//基本图像调整参数
typedef union
{
	UINT mirrorMode;                /*关闭(0);水平翻转(1);垂直翻转(2);水平和垂直翻转(3);*/
	BackLightCompParam backLightComp;    //背光补偿  
	UINT flickerControl;            /*60Hz flicker(0); 50Hz flicker(1);*/
	UINT agcontrol;                // 自动增益控制开关;
  Agcontrol  agc;                //增益控制参数 
	UINT gammaCurve;               //Gamma 校正: his 默	认(0); 1.6(1); 1.8(2); 2.0(3); 2.2(4)
	UINT whiteBalance;              /*自动(0);  SUNNY(1);   SHADOW(2);INDOOR(3);LAMP(4)*/
	WBcontrol wbctrl;               //  白平衡控制参数
  UINT dayNightMode;              /* 自动(0);白天(1);黑夜(2)*/
	UINT irisHoldValue;                /* (AI控制)AI校正值，用于保存校正后的值 */
	UINT irisCloseDrive;               /* (AI校正)AI校正中关闭光圈的驱动值 */
	exposureParam exposure;     /*曝光参数*/
  ExpZone       expzone;// 曝光区域
	dayNightSwitchTime switchTime;  /*日夜转换切换时间点(7)*/
	StrongLightCtrlParam strongLightCtrl;  //强光抑制 
	DigitalNoiseFilterParam digitalNoise;  //3D 降噪  
  DayNightState dayNightState;   //日夜切换状态信息
	char data[64];                  //保留
} BasicParamValue;

//基本图像调整参数
typedef struct
{
  UCHAR type;                 /*镜像翻转(1);背光补偿(2);闪烁控制(3);白平衡模式(4);日夜模式(5);曝光参数(6)*/
                             //日夜转换切换时间点(7); 强光抑制(8);	数字降噪(9);自动增益控制(10);Gamma校正(11);AI校正(12);AI控制(13)
                             //;增益控制参数（14）;白平衡控制参数(15);曝光区域(16)；日夜切换状态信息（17）
	UCHAR effect;                   /*设置此参数后的影响。无影响(0);传输流中断(1);设备重启(2)*/
	UCHAR res[2];                   //保留
	BasicParamValue value;
}BasicParam;

//基本图像调整参数
typedef struct
{
	UINT count;                     /*有效参数个数*/
	BasicParam param[32];          /*最大32个参数*/
}PictureMakeParam;

typedef struct
{
	UCHAR mode;       //None(0) ； Low Global Enhancement(1) ；Medium Global Enhancement(2) ； High Global Enhancement(3) ；
	// Low Local Enhancement(4); Low Medium Enhancement(5); High Local Enhancement(6)
	UCHAR effec;    // 设置此参数后的影响。无影响(0)；传输流中断(1)；设备重启(2)；
	UCHAR digitWDR_mode; // 数字宽动态控制； 取值同上
  UCHAR type; //宽动态分档级别（由设备返回）//0 :为 type-1：时对应 Low， Medium， High （4,5,6）
               //1 :为 type-2：时对应5 档，mode取值 1~ 5 
  UCHAR disavleWDR;  // 0 :不关闭，1：关闭 
  UCHAR disableDRC;  //  数字宽动态0 :不关闭，1：关闭 
  UCHAR res0[2];
	UINT res1[3];
} WideDynamicRangeParam;

typedef union
{
	UINT ldc_ratio; 	//LDC 扭曲校正强度
	//UINT videoStabilize;	//图像稳定 OFF(0)；ON(1)
	UINT imageSenserMode;	// 图像传感器模式 BINNING(0) ；	SKIPPING(1)；WINDOW(2)
	//UINT antiFog; //去雾：OFF(0)；ON(1)
	UINT rotateValue;//图像旋转角度；	//0:0度，(1): 90 度，(2)：180 度；	(3):270 度；///仅支持720p 和1080p；
	char data[64]; //占位符，确保总长为	64
} AdvanceParamValue;

typedef struct
{
	UCHAR type;	                // 镜像扭曲校正(1);图像稳定(2);图像传感器模式(3);去雾(4);旋转(5)
	UCHAR effect;               // 设置此参数后的影响。无影响(0)；传输流中断(1)；设备重启(2)；
	UCHAR enable;               //1：使能，0:关闭
	UCHAR res;               //保留
	AdvanceParamValue value;
}AdvanceParam;

typedef struct
{
	UINT count; //有效参数个数
	AdvanceParam params[32]; //最大32 个参数
}ImgAdvanceParam;

//报警接收
typedef struct
{
	/*按位表示状态上传中各项Enable/錎isable状态
	*，1为enable，0 为disable
	*/
	UINT  stateUploadCfg;
	UINT  res[3];
	int  time;           /**< 系统当前时间 */
	int     uptime;         /**< 系统总运行时间(秒) */
	int     loads[3];       /**< 系统 5、10、15 分钟内平均负载 */
	int     totalram;       /**< 系统总内存(MB) */
	int     freeram;        /**< 系统空闲内存(MB) */
	int     bufferram;      /**< 系统用于缓存的内存(MB) */
	int     totalswap;      /**< 系统总交换分区大小(MB) */
	int     freeswap;       /**< 系统空闲交换分区(MB) */
	int     procs;          /**< 系统进程数 */
	UCHAR    cameraStauts;    /**< 当前镜头状态Normal(1),Abnormal(2) */
	UCHAR    onlineUsers;     /**< 当前登录用户数 */
	UCHAR    videoStreamCount;   /**< 当前视频连接数*/
	UCHAR    SDActive;   /**<  SD卡在位YES(1)|NO(2)*/
	USHORT   bitRate[MAX_BITRATE_NUM];  /*码率，单位为kbps,最大支持8个码流*/
	int   earlistRecordTime;      /*sd卡最早录像时间，仅当SDActive为YES有效*/
	unsigned long long   totalSizeOnSD;     /*SD总容量，单位byte，当sdactive为YES有效*/
	unsigned long long  leftSizeOnSD;   /*SD剩余容量，同上*/
	UCHAR    res2[8];
}SmGetIpcDvsStatusUpload;

/**@ enum ESDError
* SD卡错误信息
*/
typedef enum
{
	ERR_ADMIND_SD_NOCARD          =(0x000D),    /**<无SD卡设备*/
	ERR_ADMIND_SD_MALFUNCTION     =(0x000E),    /**<SD卡故障*/
	ERR_ADMIND_SD_FULL            =(0x000F),    /**<SD卡满*/
	ERR_ADMIND_SD_FORMAT          =(0x0010),    /**<SD卡格式化中*/
	ERR_ADMING_SD_CHECKING        =(0x0011),   /**<SD卡正在检测*/
} ESDError;

/** 恢复出厂值返回错误号 */
typedef enum 
{
	RESTORE_ERR_RECORD = (0x0001), /** 正在录像 */
	RESTORE_ERR_SPEECH = (0x0002), /** 正在对讲 */
	RESTORE_ERR_DOWNLOAD = (0x0003), /** 正在下载 */
  RESTORE_ERR_CAPTURE = (0x0004), /** 正在抓图 */
} RestoreError;

/** 格式化返回错误号 */
typedef enum 
{
	FORMAT_ERR_RECORD = (0x0001), /** 正在录像 */
	FORMAT_ERR_FORMAT = (0x0002), /** 正在格式化 */ 
	FORMAT_ERR_DOWNLOAD = (0x0003), /** 正在下载 */
  FORMAT_ERR_CAPTURE = (0x0004), /** 正在抓图 */
	FORMAT_ERR_NOSDCARD = (0x0005), /** 无SD卡 */
} FormatError;

/** 获取云台的状态 
status, BITMAP, 表示当前云台的状态
BIT1(巡航) 、BIT2(轨迹) 、BIT3(扫描) 、BIT4(水平旋转)、 BIT5(灯光)、 BIT6(雨刷)
*/
struct AVDomeGetStatus
{
	unsigned status; //状态位 
};

// 启动链接
struct NetLinkStartup 
{
	int iface; //ADSL(3)
};

// 关闭链接
struct NetLinkShutDown {
	int iface; //ADSL(3)
};


struct SystemRestoreParaIpc
{
	int mode;
	unsigned int exclusions;
};

struct ActionCfg_In_Ipc
{
	int alertType;            //报警源类型:   
	unsigned int alertIds;    //报警源编号bitmap(1-16)   
};

struct AVDomeControlIpc
{
	unsigned int channels;    //通道(bitmap)本处只能设置一个通道 
	short cmd;                //命令 
	short arg;                //参数 
};

struct AVParaIpc 
{
	char system;    //制式：PAL(1)|NTSC(2) 
  unsigned char highfrmratemode;//0,关闭，1：开启高频帧模式 
	char res[2]; 
};

struct UartParaIpc
{
	char link;     ////链路类型: RS232(1)|RS485(2)| RJ45(4)
	char dock;      // 可以为type
	char res2[2];
};

struct SecurityUserPasswdIpc 
{
	char user[16];  //用户名
	char oldPassword[32]; //旧口令的MD5结果
	char newPassword[32]; //新口令的MD5结果
};

struct CorrectDefectPixels
{
  int result; //0表示检测校正成功，其它值表示失败
  USHORT defectPixelsCount; //坏点个数
  char res[6];
};

struct Module
{ 
  unsigned char module; //模块编号 
  char res[3]; 
  unsigned char version[8]; //模块版本号 
  unsigned int buildTime; //模块编译日期 
}; 

struct SysModulePara
{
  char count;   //模块个数(0-32) 
  char res[2];    
  char rdver ; //用于结合大版本区分功能序列； 
  //产品开发设计过程版本号序列；0 和 1 预留给早期
  //版本，从2开始；（每个号对应到某个 bscp 版本，包
  //含一部分 bscp 功能集合） 
  Module moduleList[32];   // 
};

struct AlertUploadSetPara
{
  unsigned int  keepAliveInterval;  //报警发送端发送 keepAlive报文的最长间隔，单位为秒。缺省值为 60秒，取值 0 表示使用缺省值。 
  char res[64]; //保留 
};

//银瀑AVD配置(视频诊断)

struct AvdTimeSeg
{
	unsigned char start; //是否启动 0：不启动 1：启动
	unsigned char bHour; //开始时间的小时 0-23
	unsigned char eHour; //结束时间的小时 0-23
	unsigned char bMinute; //开始时间的分 0-59
	unsigned char eMinute; //结束时间的分 0-59
	unsigned char sensity; //灵敏度1-5； def: 3	
	unsigned char resv[2] ; // 保留
};
struct IrMode
{
	unsigned int trigMode ;// 0:外部，1：自动，1：default
	unsigned int balanceLevel ;//1~5,可见光~ 红外，3：default
};
struct AvdParaCom
{
	unsigned int avd_id ;//检测算法ID;
	unsigned int enable ;///是否使能
	AvdTimeSeg tmSeq[7][4]; /// 7 天4 个时段
	unsigned char res[4]; //
	unsigned char elapse ; // 持续时间
	unsigned char resv[3];
};
struct AVDParam
{
	unsigned int avd_num ; ///有效检测算法个数;
	IrMode mode ; //光照模式；
	AvdParaCom avdcfg[9];
};
struct AvdConfPara
{
	unsigned int count;//通道个数；IPC def==1,DVR/NVR= 实际通模拟道数
	AVDParam avdpara[NVR_ALERT_MAX_NUM];
};

struct VDCustom { 
  int delays; //延迟时间 
  int res; 
}; 

struct VDLinkPara
{
  char outputs; // bitmap:端子 1~8
  char netupload ; //1:enable, 0:disable
  char mail   ;//邮件，1:enable, 0:disable 
  char  mail_attachment_pic; //图片附件 1:enable0:disable N 
  char sdrecord; //SD联动录像，1:enable, 0:disable
  char picsnap; // 抓图开关 1:enable, 0:disable 
  char picusetype; // 抓图应用类型，1.SD卡存储，2.图片网络上传 
  char netupload_attachment_pic; // 图 片 附件1:enable,0:disableN
  unsigned short recdelay;//延录时间,单位sec
  char res[14];
};

struct VDParam
{
  int enable; //是否使能；0：disable，1：enable
  int VDType;//1: lensMotionDetected ；镜头移位检查;
  AvdTimeSeg time[7][6]; //检测时间段
  VDLinkPara linkpara ; // 联动参数
  VDCustom customs;   //诊断相关参数 
};
//视频诊断
struct VAConfPara
{
	unsigned int count;//VDType 个数
	VDParam para[NVR_ALERT_MAX_NUM];
};

struct BNCOutMode  
{ 
  char mode ; //def:  1:704x576（压缩）,0: Invalid ; 
              //1:704x576（压缩） ，2: 704x576（裁剪）; 2:960x576（裁剪）
  char resv[3] ; 
}; 

struct BNCModeCap
{
	unsigned int nr ; // 有效模式数;
	unsigned int mask; // bitmap: 位定义同上面(0x0003.0205)说明
	// 1:704x576（压缩），2: 704x576（裁剪） ; 3:960x576（裁剪）
};

struct DevBncPara
{
  unsigned int count ; //////IPC def == 1 
  BNCOutMode bncMode[NVR_MAX_CHANNEL_COUNT] ; 
};

struct IRCUTCtrlParam
{
	unsigned int min_sw_interval;//最小切换间隔
	unsigned int res[7];
};

struct IRCUTState
{
	unsigned int max_day_num;   //每日最大切换次数
	unsigned int total_num;     //当前总切换次数；
	unsigned int res[2];
};

struct HARDInfrared
{
	char Irmode;	// 0：非法值, 1：主动模式，2：被动模式
	char nswitch;  /// 1:0n,0:Off
	char res[2];
};

struct HARDSupportFunc
{
	char clock;//时钟
	char Reset;//复位键
	char buzzer;//蜂鸣器
	char res[29];
};

struct SIPBasicParam
{
	char sipSeverIP[32];          //sip 服务器IP
	unsigned int sipserverPort;   //sip 服务器端口
	unsigned int localPort;       //NVR 本地端口
	int regTime;                  //注册有效期
	int keepRegTime;              //保活时间
	unsigned int heartbeastTime;  //心跳发送间隔时间
	char serverIdent[32];         //注册id 服务器位编码
	char Password[32];            //鉴权时密码
	char serverDomainName[32];    //服务器域名
	char deviceIdent[32];         //设备位编码
	char devDomainName[32];       //设备域名
	char regTosvr; // 是否向服务器注册 1：是，0：否；
	char resv[7];
};

struct Identcode
{
	char code[32];
};

struct SIPChanIdent
{
	int count;
	Identcode chanIdent[NVR_ALERT_MAX_NUM];
};

struct SIPSitsIdent
{
	int count;
	Identcode sitsIdent[NVR_ALERT_MAX_NUM];
};

struct NetServiceTestIn
{
	char service; //服务类型名//SERVICE_ALERT(1)|SERVICE_SMTP(2)
	char res[3];
};

struct NetServiceTestOut
{
	char service; //服务类型名
	char result;  //测试结果: OK(0)|FAILURE(1)
	char res[2]; //
};

/** 测试命令参数 */
struct HardWareTestCMD
{
	int nMasterItem; /**< 主命令 */
	int nSubItem;    /**< 子命令 */
};


/** 测试结果 */
struct HardWareTestRet
{
	int nRet; /**< 测试结果 */
};

/** 老化检测命令 */
struct AgingTestCMD
{
	int nCmd;
};

/** 老化检测结果 */
struct AgingTestRet
{
	int nRet;
};

/** IR_CUT打开关闭检测命令 */
struct IRBeginEndTestCMD
{
	int nCmd;
};

/** IR_CUT打开关闭检测结果 */
struct IRBeginEndTestRet
{
	int nRet;
};

struct SliceDumpPara
{
	unsigned int chnnl;     //通道号
	unsigned int startTime; //检索开始时间
	unsigned int endTime;   //检索结束时间
	unsigned int gapTime;   //切片间隔

};

struct AddrItem
{ 
  unsigned int addr;    //IPV4 地址 
}; 

struct NET_ADDRFILTER_PARA
{
  unsigned char   filterType; //Disabled(0)，白名单(1)，黑名单(2)。目前只支持 Disabled 和白名单。
  unsigned char    res;  //保留 
  unsigned short   itemCount; //白名单或者黑名单条目数，最大不超过 200条 
  AddrItem   addrs[200]; //条目 
};

struct MulticastAddrParamOut
{
  unsigned short   channel;     //通道号(1-32) 
  unsigned char    streamIndex;  //该通道中的码流编号(1-8) 
  unsigned char    res1[5];     //保留 //channel 和 streamIndex 取值全为 0 时，表示全局使用此组播地址。目前只支持这种模式。 
  unsigned int     multicastAddr ; //需符合 IP地址中的组播地址段
  unsigned short   multicastPort; //组播端口 
  unsigned short   res2; 
};

struct MulticastAddrParamIn
{
  unsigned short  channel;       //通道号(1-32) 
  unsigned char   streamIndex;  //该通道中的码流编号(1-8)。channel 和 streamIndex 取值全为 0 时，表示全局使用此组播地址。目前只支持这种模式。 
  unsigned char   res1[5]; //保留 
};

//添加3D云台控制
struct PtzZoomArgs
{
  int chnnl;    //通道号， 可不填
  int res;
  int operType; // 0 = 放大， 1 = 缩小;

  //以下宽高及坐标点均是相对视频的宽高
  unsigned short rectW; //小矩形宽
  unsigned short rectH; //小矩形高

  unsigned short x;     //小矩形中心点横坐标
  unsigned short y;     //小矩形中心点纵坐标

  unsigned int width;   //视频宽
  unsigned int height;  //视频高

  unsigned int res1[3];

};

enum DEVICE_TYPE
{
	DEVICE_IPC = 0,
	DEVICE_NVR,
	DEVICE_FRONTPAD,
	DEVICE_TR01B,
};

//设备升级状态
struct UpgradeState
{
	int stage; // 1= translate file, 2 = burn flash
	int persent;//升级进度
};

struct  time_zone 
{ 
  UINT  time_begin; //   单位：秒 
  UINT  time_end;  //   单位：秒 
}; 

struct dayNightSwCtrl
{ 
  UINT  daynight_swmode ; // 1.彩色，2.黑白. 3 自动，4 定时，5.报警； 
  union 
  { 
    time_zone  trange; // 定时区域 
    UINT       trigger_dest ;// 报警触发的目标状态//  1.白天，2.晚上  
  }u;

  UINT  res[2]; 
};

//图像调整的场景 
struct  ImgScenceInfo{ 
  UINT   scenemode; // 1. inner 室外 2,outside室内 
  dayNightSwCtrl daynsw; 
};

struct PicTuneSceneList
{
  UINT   count;   // 可用总的图像场景数量 
  USHORT   cId ;  // 当前场景 
  UCHAR   res[6] ;  // 保留 
  ImgScenceInfo list[64]; 
};
//设置IPC辅助对焦
struct FocusAssist 
{ 
  int   sw ; // 0,off ,1 ON 
  int   res ; 
};
//获取IPC对焦状态
struct FocusStatus 
{ 
  int   sw ;//辅助对焦的开关
  unsigned int status;///对焦状态
}; 

#define DVX_UKEY_ET199_DATA_LEN   (64 * 1024)

struct UkeyAuthizeParam
{
  UINT    authLen;   // 附带的有效授权信息长度 
  UCHAR   auth[DVX_UKEY_ET199_DATA_LEN];   // 附带的授权信息 
};

struct ukeyHeader
{
  int mark;   /**< 标志固定为"BSCE" */
  unsigned char version;  /**< 版本号 */
  unsigned char ukeyType; /**< 1. 普通  5.管理 */
  unsigned char ads_mask;    /**< 附加信息掩码 */
  unsigned char res;  /**< 保留 */
  int wLen;   /**< header以外的数据长度 */
  int res2;
};

struct ukeyUserInfo
{
  int level;  /**< 用户级别 */
  int lcode;  /**< 所在区域 */
  char res[16];    /**< 预留可以保存组织机构代码 */
  unsigned char localPriv[8]; /**< 本地权限bitmap */
  unsigned char remotePriv[8]; /**< 远程权限bitmap */
};

struct ukeyDevInfo
{
  unsigned char codes[24]; /**< 归属地信息码 */
  /**
  * 设备授予权限
  * 当ukeyType=1时有效
  * 只有普通key可以授予设备权限, 管理key只能擦除设备权限
  */
  unsigned char localPriv[8]; /**< 本地权限bitmap */
  unsigned char remotePriv[8]; /**< 远程权限bitmap */
};

struct ukeyAdsHeader
{
  unsigned char count;    /**< 附加信息个数 */
  unsigned char size;     /**< 附加数据每个大小 */
  unsigned char type;     /**< 附加数据类型 */
  unsigned char res;      /**< 保留 */
};

struct IPCPreViewPara //IPC预览时的参数设置，仅对IPC有效, 自定义，非协议
{
	bool bImageEhnace;//图像增强
	bool bres[3];
	char channels;  //通道设置
	char subStream;  //码流选择
	char transProc;  //传输协议
	char res;
};

// 自动调焦 视频附加信息帧信息头
struct AFFrameHeader
{
	unsigned short   lefttop;    //左上区域清晰度
	unsigned short   leftbottom; //左下区域清晰度
	unsigned short   righttop;   //右上区域清晰度
	unsigned short   rightbottom;//右下区域清晰度
	unsigned short   total;     //整幅图像清晰度
	unsigned short   res[3]; 
};

#pragma pack( pop )

#endif	// end of USE_DVXSDK_TYPE_HEADER