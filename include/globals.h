// globals.h
// this file will be automatically included by the driver
// for XKX mudlib, by Xiang

#include "ansi.h"

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#else
#define private protected
#define static nosave
#endif

//等级制相关宏定义
//--------------------------------------------------------
//每次提升的等级
#define LEVEL_UP_NUM 1
//等级提升所需经验
#define LEVUP_EXP 100000
//等级提升经验底线
#define LEVUP_EXP_START 21
//等级提升时增加的属性点
#define LEVUP_SHUXD_NUM_ONE 5
#define LEVUP_SHUXD_NUM_TWO 5
//等级提升时属性增加
#define LEVUP_SHUXING_NUM_ONE 0
#define LEVUP_SHUXING_NUM_TWO 0
// 每 X 级技能消耗一个技能点
#define MAX_SKILLS_ABOUT_DIAN 10
// 初始给予的属性点数
#define START_SET_SXD 100
//--------------------------------------------------------
//开放的经验倍数
#define XYZX_SYS_EXP_NUM 2
// 最大有效触发数目
#define CHUFA_CMD_SIZE 15
//开启坐标系统
#undef XYZX_SYS_JULI

// Important directories
#define INC_DIR     "/include/"
#define COMMAND_DIR "/cmds/"
#define CONFIG_DIR  "/adm/etc/"
#define DATA_DIR    "/data/"
#define BACKUP_DIR  "/backup/"
#define HELP_DIR    "/doc/"
#define LOG_DIR     "/log/"
#define DEBUG_DIR   "/debug/"
// 配置文件放置目录
#define DATA_CONFIG_DIR "/data/config/"
// Daemons
// 团队系统
#define TEAMD       "/adm/daemons/teamd"
// 新闻
#define NEWSD       "/adm/daemons/newsd"
// 数据库
#define DATABASE_D  "/adm/daemons/databased"
// 副本系统
#define VRM_SERVER  "/adm/daemons/vrm_server"
// 数据服务
#define DATAD       "/adm/daemons/datad"
#define AUTOSAVED   "/adm/daemons/autosaved"
#define BIGUAN_D    "/adm/daemons/biguand"
#define ALIAS_D     "/adm/daemons/aliasd"
#define BAN_D       "/adm/daemons/band"
#define BR_D        "/adm/daemons/brd"
#define BACKUP_D    "/adm/daemons/backupd"
#define CHANNEL_D   "/adm/daemons/channeld"
#define REMOVE_CMD  "/cmds/std/sleep.c"
#define STORY_DIR   "/adm/daemons/story/"
#define STORY_D     "/adm/daemons/storyd"
#define MSG_D       "/adm/daemons/msgd"
#define CHAR_D      "/adm/daemons/chard"
#define CHINESE_D   "/adm/daemons/chinesed"
#define COMBAT_D    "/adm/daemons/combatd"
#define COMMAND_D   "/adm/daemons/commandd"
#define EMOTE_D     "/adm/daemons/emoted"
#define FINGER_D    "/adm/daemons/fingerd"
#define FTP_D       "/adm/daemons/ftpd"
#define INQUIRY_D   "/adm/daemons/inquiryd"
#define LOGIN_D     "/adm/daemons/logind"
#define MONEY_D     "/adm/daemons/moneyd"
#define NATURE_D    "/adm/daemons/natured"
#define PIG_D       "/adm/daemons/pigd"
#define PROFILE_D   "/adm/daemons/profiled"
#define RANK_D      "/adm/daemons/rankd"
#define SECURITY_D  "/adm/daemons/securityd"
#define FILESERVER  "/adm/daemons/network/fileserver"
// #define SECURITY_D  "/adm/daemons/securd"
#define UPDATE_D    "/adm/daemons/updated"
#define VIRTUAL_D   "/adm/daemons/virtuald"
#define MONITOR_D   "/adm/daemons/monitord"
#define WEAPON_D    "/adm/daemons/weapond"
#define LANGUAGE_D  "/adm/daemons/languaged"
#define STATUS_D    "/adm/daemons/statud"
#define TASK_D      "/adm/daemons/questd"
#define CRON_D      "/adm/daemons/cron"
#define CONFIG_D    "/adm/daemons/configd"
#define VERSION_D   "/adm/daemons/versiond"
#define	MESSAGE_D	"/adm/daemons/network/messaged"
#define TEXT2PIC_D  "/adm/daemons/text2pic_d"
// Added for questing
// by Hop, 1997.05.16
#define QUEST_D(x)  ("/quest/qlist" + x)
// End of appendence
#define CLASS_D(x)  ("/kungfu/class/" + x)
#define SKILL_D(x)  ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
// Clonable/Non-inheritable Standard Objects
#define CORPSE_OB   "/clone/misc/corpse"
#define LOGIN_OB    "/clone/user/login"
#define MASTER_OB   "/adm/obj/master"
#define MAILBOX_OB  "/clone/misc/mailbox"
#define THGOLD_OB   "/clone/money/thousand-gold"
#define THCASH_OB   "/clone/money/thousand-cash"
#define GOLD_OB     "/clone/money/gold"
#define SILVER_OB   "/clone/money/silver"
#define COIN_OB     "/clone/money/coin"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define USER_OB     "/clone/user/user"
#define VOID_OB     "/clone/misc/void"
#define VOID_USER   "/clone/misc/void_user"
// Inheritable Standard Objects
#define BULLETIN_BOARD  "/inherit/misc/bbsd"
#define BULLETIN_BBSD   "/inherit/misc/bboard"
#define BULLETIN_JBOARD "/inherit/misc/jboard"
#define CHARACTER       "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP       "/inherit/misc/equip"
#define FORCE       "/inherit/skill/force"
#define HOCKSHOP    "/inherit/room/hockshop"
#define ITEM        "/inherit/item/item"
#define LIQUID      "/inherit/food/liquid"
#define MONEY       "/inherit/item/money"
#define NPC         "/inherit/char/npc"
#define PILL        "/inherit/medicine/pill"
#define POWDER      "/inherit/medicine/powder"
#define ROOM        "/inherit/room/room"
#define SKILL       "/inherit/skill/skill"
#define SELL_SALT   "/inherit/char/sell_salt"
#define NPC_SAVE	"/inherit/char/npcsave"
#define QUEST       "/inherit/quest"
#define SSERVER     "/inherit/sserver"

// #define USER-ROOM   "/inherit/room/user_room"
// User IDs
#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"
// Features
#define F_ACTION        "/feature/action.c"
#define F_ALIAS         "/feature/alias.c"
#define F_APPRENTICE    "/feature/apprentice.c"
#define F_ATTACK        "/feature/attack.c"
#define F_ATTRIBUTE     "/feature/attribute.c"
#define F_AUTOLOAD      "/feature/autoload.c"
#define F_CLEAN_UP      "/feature/clean_up.c"
#define F_COMMAND       "/feature/command.c"
#define F_CONDITION     "/feature/condition.c"
#define F_DAMAGE        "/feature/damage.c"
#define F_DBASE         "/feature/dbase.c"
#define F_DEALER        "/feature/dealer.c"
#define F_EDIT          "/feature/edit.c"
#define F_EQUIP         "/feature/equip.c"
#define F_FINANCE       "/feature/finance.c"
#define F_FOOD          "/feature/food.c"
#define F_LIQUID        "/feature/liquid.c"
#define F_MASTER        "/inherit/char/master.c"
#define F_MESSAGE       "/feature/message.c"
#define F_MORE          "/feature/more.c"
#define F_MOVE          "/feature/move.c"
#define F_NAME          "/feature/name.c"
#define F_SAVE          "/feature/save.c"
#define F_BACKUP        "/feature/backup.c"
#define F_SKILL         "/feature/skill.c"
#define F_TEAM          "/feature/team.c"
#define F_TREEMAP       "/feature/treemap.c"
#define F_VENDOR        "/feature/dealer.c"
#define F_SSERVER       "/feature/sserver.c"
#define F_UNIQUE        "/feature/unique.c"
#define F_BANKER        "/feature/banker.c"
#define F_IPSITE        "/feature/ipsite.c"
#define F_VIP           "/feature/vip.c"
#define F_MAGIC         "/feature/magic.c"
#define F_QUEST         "/feature/quest.c"
#define F_MAGIC_ATT     "/feature/magic.c"
#define F_QNSAVE        "/feature/qnsave.c"
#define F_UNANSI        "/feature/unansi.c"

//ASCII码字符表
#define F_ASCII         "/feature/ascii.c"
// 修炼系统
#define F_XIULIAN       "/feature/xiulian.c"
// 坐标系统
#define F_MAP_XY        "/feature/map_xy.c"
// 颜色转换
#define F_COLOR         "/feature/color.c"
// Tomud协议常用的一些函数
#define F_TOMUD         "/feature/tomud.c"
#define F_SKILL_OB      "/feature/skill_ob.c"
#define F_SHADOW        "/feature/shadow.c"
#define F_ITEM_MAKE     "/feature/item_make.c"
#define F_SUIT          "/feature/suit.c"           //套装

#define SKILL_MODEL_UNARMED    "/meskill/skill_model_unarmed.c"

#define SKILL_MODEL_WEAPON     "/meskill/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/meskill/skill_model_default.c"
#define F_VENDOR_SALE		   "/feature/vendor_sale.c"
// for gem system(by xbd)
#define F_GEMS			"/feature/gems.c"
#define S_WEAPON		"/inherit/gems/weapon.c"
#define S_ROBE		    "/inherit/gems/robe.c"
#define S_RING			"/inherit/gems/ring.c"

///////////////////////////////////////////////////////////////////////////
/* SYSTEM about by Wenwu */
// 这里定义BIG5用户的端口
#define BIG5_PORT 6666
/* 下面两个定义，决定系统采用哪种加密方式，你只能定义其中的一种或全都不定义
 * OLD_CRYPT   SUN加密
 * MD5_CRYPT   MD5加密
 * 都不定义    常用的普通加密 */
#undef OLD_CRYPT
#undef MD5_CRYPT
///////////////////////////////////////////////////////////////////////////

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it
// in effect.
#undef PROFILE_COMMANDS
