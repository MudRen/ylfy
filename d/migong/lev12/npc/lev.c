#include <ansi.h>
inherit NPC;

string *random_item = ({
	"/clone/map/weapon/axe",
	"/clone/map/weapon/blade",
	"/clone/map/weapon/club",
	"/clone/map/weapon/hammer",
	"/clone/map/weapon/spear",
	"/clone/map/weapon/staff",
	"/clone/map/weapon/whip",
	"/clone/map/weapon/sword",
	"/clone/map/armor/boot",
	"/clone/map/armor/cloth",
	"/clone/map/armor/hand",
	"/clone/map/armor/head",
	"/clone/map/armor/neck",
	"/clone/map/armor/ring",
	"/clone/map/armor/shield",
	"/clone/map/armor/surcoat",
	"/clone/map/armor/waist",
	"/clone/map/armor/wrists",
	"/clone/map/armor/armor",
	"/clone/map/armor/pants",
	});
	
string *random_item2 = ({
	"/clone/tzbox/qf-box",
	"/clone/tzbox/sx-box",
	"/clone/tzbox/jm-box",
	"/clone/map/obj/longwen-chijin",
	});
void create()
{
	int tsjndj, jcjndj, shuxing;
	string weapon = "null";
	jcjndj = 15000 + random(20000);
	tsjndj = 4000 + random(4000);
	shuxing = 50000 + random(50000);
	seteuid(getuid());
	set_name(HIM"蒙面人"NOR, ({"mengmian ren","meng mian"}) );
    set("title", HIC "武林败类" NOR);
    set("gender", "男性" );
    set("icon", "30005" );
    set("age", random(30)+20);
    set("long", "各大门派的叛徒，有着一身不凡的武艺，穷凶恶极手下罕有十合之将。\n");
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 50);
    set("con", 50);
    set("int", 50);
    set("dex", 50);
    set("max_qi", 100000000);	
	set("qi", 100000000);
    set("max_jing", 30000000);
	set("jing", 30000000);
    set("neili", 150000000);
    set("max_neili", 100000000);
	set("jingli", 100000);
    set("max_jingli", 100000);
	set("no_suck",1);
    set("jiali", 20000 + random(50000));
    set("env/wimpy", 5);
    set_temp("apply/attack",  100);
    set_temp("apply/defense", 100);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 10000+random(20000));
	set("xyzx_sys/fanying", shuxing);
	set("xyzx_sys/jingzhun", shuxing);
	set("xyzx_sys/minjie", shuxing);
	set("xyzx_sys/lingxing", shuxing);
    set_skill("force", jcjndj); 
    set_skill("parry", jcjndj);
    set_skill("dodge", jcjndj);
    set_skill("unarmed", jcjndj);
	set_skill("sword", jcjndj);
	set_skill("blade", jcjndj);
	set_skill("club", jcjndj);
	set_skill("axe", jcjndj);
	set_skill("throwing", jcjndj);
	set_skill("hammer", jcjndj);
	set_skill("staff", jcjndj);
	set_skill("whip", jcjndj);
    create_family("杀手盟", 3, "喽啰");
    set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
		}) );
    
	switch( random(54) ) {
	case 0:{ //无名剑法
	set_skill("douzhuan-xingyi", tsjndj);
    set_skill("guiyuan-tunafa", tsjndj);
    set_skill("tiezhang-zhangfa", tsjndj);
    set_skill("wuming-jianfa", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "guiyuan-tunafa");
    map_skill("unarmed","tiezhang-zhangfa");
    map_skill("parry", "douzhuan-xingyi");
    map_skill("sword", "wuming-jianfa");
    map_skill("dodge", "shaolin-shenfa");	
	weapon = "/clone/weapon/yuenv";	
	}
	break;	
	case 1:{ //太极剑法
	set_skill("taiji-shengong", tsjndj);
    set_skill("taiji-quan", tsjndj);
    set_skill("taiji-jian", tsjndj);
    set_skill("tiyunzong", tsjndj);
    map_skill("force", "taiji-shengong");
    map_skill("unarmed","taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    map_skill("dodge", "tiyunzong");
	weapon = "/clone/weapon/hanbing-jian";	
	}
	break;	
	case 2: {  //峨眉回风
	set_skill("linji-zhuang", tsjndj);
    set_skill("jinding-zhang", tsjndj);
    set_skill("huifeng-jian", tsjndj);
    set_skill("zhutian-bu", tsjndj);
    set_skill("yugalism", tsjndj);
    map_skill("dodge", "zhutian-bu");
    map_skill("parry", "huifeng-jian");
    map_skill("sword", "huifeng-jian");
    map_skill("force", "linji-zhuang");
    map_skill("unarmed","jinding-zhang");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
	case 3: { //云龙
	set_skill("yunlong-xinfa", tsjndj);
    set_skill("yunlong-shengong", tsjndj);
    set_skill("yunlong-jian", tsjndj);
    set_skill("yunlong-shenfa", tsjndj);
    map_skill("dodge", "yunlong-shenfa");
    map_skill("force", "yunlong-shengong");
    map_skill("unarmed", "houquan");
    map_skill("parry", "yunlong-jian");
    map_skill("sword", "yunlong-jian");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
	case 4: { //移花
	set_skill("jueqing-zhang", tsjndj);
	set_skill("mingyu-shengong", tsjndj);
	set_skill("yifeng-jian", tsjndj);
    set_skill("yihua-jiemu", tsjndj);
	map_skill("force", "mingyu-shengong");
	map_skill("unarmed", "jueqing-zhang");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "mingyu-shengong");
    map_skill("sword","yifeng-jian");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
	case 5:{ //白驼
	set_skill("hamagong", tsjndj);
    set_skill("chanchu-bufa", tsjndj);
    set_skill("training", tsjndj);
    set_skill("lingshe-zhangfa", tsjndj);
    map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "hamagong");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
	weapon = "/clone/weapon/gangzhang";
	}
	break;	
	case 6:{  //丐帮
	set_skill("xiaoyaoyou", tsjndj);
    set_skill("huntian-qigong", tsjndj);
    set_skill("xianglong-zhang", tsjndj);
    set_skill("dagou-bang", tsjndj);
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    map_skill("parry", "xianglong-zhang");
    map_skill("club", "dagou-bang");
	weapon = "/clone/weapon/tiegun";
	}
	break;	
	case 7:{  //一刀流
	set_skill("wuxing-dun", tsjndj);
    set_skill("shayi", tsjndj);
    set_skill("shayi-xinfa", tsjndj);
    set_skill("shiren-jianfa", tsjndj);
    set_skill("ninjitsu", tsjndj);
    set_skill("ittouryu", tsjndj);
    set_skill("enmeiryu", tsjndj);
    map_skill("blade", "ittouryu");
    map_skill("force", "shayi-xinfa");
    map_skill("dodge", "wuxing-dun");
    map_skill("parry", "shiren-jianfa");
    map_skill("unarmed", "enmeiryu");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
	case 8:{  //飞天御剑流
	set_skill("xuanhualiu-quanfa", tsjndj);
    set_skill("feitian-yujianliu", tsjndj);
    set_skill("wuxing-dun", tsjndj);
    set_skill("shayi-xinfa", tsjndj);
    set_skill("shayi", tsjndj);
    map_skill("force", "shayi-xinfa");
    map_skill("parry", "feitian-yujianliu");
    map_skill("blade", "feitian-yujianliu");
    map_skill("dodge", "wuxing-dun");
    map_skill("unarmed", "xuanhualiu-quanfa");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
	case 9:{ //玄铁剑法
	set_skill("yunv-shenfa", tsjndj);
    set_skill("xuantie-jianfa", tsjndj);
    set_skill("anranxiaohun-zhang", tsjndj);	
    set_skill("yunv-xinfa", tsjndj);     
    map_skill("force", "yunv-xinfa");        	
    map_skill("sword","xuantie-jianfa");
    map_skill("dodge", "yunv-shenfa");
    map_skill("parry", "xuantie-jianfa");        	
    map_skill("unarmed", "anranxiaohun-zhang"); 
	weapon = "/d/gumu/obj/xuantiejian";
	}
	break;	
	case 10:{ // 灵鹫宫
    set_skill("liuyang-zhang", tsjndj);
    set_skill("tianyu-qijian", tsjndj);
    set_skill("yueying-wubu", tsjndj);
    set_skill("bahuang-gong", tsjndj);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword","tianyu-qijian");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
	case 11:{ // 日月轮
    set_skill("longxiang", tsjndj);
    set_skill("shenkong-xing", tsjndj);
    set_skill("yujiamu-quan", tsjndj);
    set_skill("mizong-xinfa", tsjndj);
    set_skill("hammer", tsjndj);
    set_skill("riyue-lun", tsjndj);
    map_skill("force", "longxiang");
    map_skill("dodge", "shenkong-xing");
    map_skill("unarmed", "yujiamu-quan");
    map_skill("parry", "riyue-lun");
    map_skill("hammer", "riyue-lun");
	weapon = "/clone/weapon/hammer";
	}
	break;	
	case 12:{ // 明教
    set_skill("jiuyang-shengong", tsjndj);
    set_skill("qiankundanuoyi", tsjndj);
    set_skill("qishang-quan", tsjndj);
    set_skill("wuxue-shenfa", tsjndj);
    set_skill("shenghuo-ling", tsjndj);
	map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "wuxue-shenfa");
    map_skill("unarmed", "qishang-quan");
	map_skill("sword", "shenghuo-ling");
    map_skill("parry","qiankundanuoyi");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
	case 13:{ //玄天
    set_skill("qimen-wuxing", tsjndj);
    set_skill("yijing-force", tsjndj);
    set_skill("lingyunbu", tsjndj);
    set_skill("cuixin-zhang", tsjndj);
    set_skill("tianxin-blade", tsjndj);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
	case 14:{ //桃花
    set_skill("luoying-zhang", tsjndj);
    set_skill("yuxiao-jianfa", tsjndj);
	set_skill("bibo-shengong", tsjndj);
    set_skill("xuanfeng-tui", tsjndj);
	set_skill("anying-fuxiang", tsjndj);
    set_skill("qimen-wuxing", tsjndj);
    map_skill("force", "bibo-shengong");
    map_skill("unarmed", "xuanfeng-tui");
    map_skill("dodge", "anying-fuxiang");
    map_skill("parry", "luoying-shenjian");
    map_skill("sword", "yuxiao-jianfa");	
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 15:{ // 凌霄城
    set_skill("snow-zhang", tsjndj);
    set_skill("xueshan-jianfa", tsjndj);
	set_skill("snowstep", tsjndj);
    set_skill("bingxue-xinfa", tsjndj);	
    map_skill("force", "bingxue-xinfa");
    map_skill("unarmed", "snow-zhang");
    map_skill("dodge", "snowstep");
    map_skill("parry", "xueshan-jianfa");
    map_skill("sword", "xueshan-jianfa");	
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 16:{ //玉女剑法
	set_skill("yunv-shenfa", tsjndj);
    set_skill("yunv-jianfa", tsjndj);
    set_skill("meinv-quanfa", tsjndj);	
    set_skill("yunv-xinjing", tsjndj);     
    map_skill("force", "yunv-xinfa");        	
    map_skill("sword","yunv-jianfa");
    map_skill("dodge", "yunv-shenfa");
    map_skill("parry", "yunv-jianfa");        	
    map_skill("unarmed", "meinv-quanfa"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	case 17:{ //一阳指
	set_skill("shaolin-shenfa", tsjndj);
    set_skill("duanjia-sword", tsjndj);
    set_skill("yiyang-zhi", tsjndj);	
    set_skill("kumu-shengong", tsjndj);     
    map_skill("force", "kumu-shengong");        	
    map_skill("sword","duanjia-sword");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("parry", "duanjia-sword");        	
    map_skill("unarmed", "yiyang-zhi"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 18:{ //六脉
	set_skill("shaolin-shenfa", tsjndj);
    set_skill("duanjia-sword", tsjndj);
    set_skill("liumai-shenjian", tsjndj);	
    set_skill("kumu-shengong", tsjndj);     
    map_skill("force", "kumu-shengong");        	
    map_skill("sword","duanjia-sword");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("parry", "duanjia-sword");        	
    map_skill("unarmed", "liumai-shenjian"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 19:{ //蝶舞
	set_skill("wudie-bu", tsjndj);
    set_skill("dieyi-jianfa", tsjndj);
    set_skill("meinv-shenquan", tsjndj);	
    set_skill("wudie-xinjing", tsjndj);     
    map_skill("force", "wudie-xinjing");        	
    map_skill("sword","dieyi-jianfa");
    map_skill("dodge", "wudie-bu");
    map_skill("parry", "dieyi-jianfa");        	
    map_skill("unarmed", "meinv-shenquan"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 20:{ //白云庵
	set_skill("qiongya-bufa", tsjndj);
    set_skill("feixian-jian", tsjndj);
    set_skill("baihua-zhang", tsjndj);	
    set_skill("bitao-shengong", tsjndj);     
    map_skill("force", "bitao-shengong");        	
    map_skill("sword","feixian-jian");
    map_skill("dodge", "qiongya-bufa");
    map_skill("parry", "feixian-jian");        	
    map_skill("unarmed", "baihua-zhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 21:{ //痴心妄想门
	set_skill("shuiyue", tsjndj);
    set_skill("chixin-bianfa", tsjndj);
    set_skill("cxwx-quan", tsjndj);	
    set_skill("wangran-xinfa", tsjndj);     
    map_skill("force", "wangran-xinfa");
    map_skill("whip", "chixin-bianfa");
    map_skill("dodge", "shuiyue");
    map_skill("unarmed", "cxwx-quan");
    map_skill("parry", "chixin-bianfa");
	weapon = "/clone/weapon/changbian";
	}
	break;
    case 22:{ //痴心妄想门
	set_skill("shuiyue", tsjndj);
    set_skill("wangxiang-fufa", tsjndj);
    set_skill("cxwx-quan", tsjndj);	
    set_skill("wangran-xinfa", tsjndj);     
    map_skill("force", "wangran-xinfa");
    map_skill("axe", "wangxiang-fufa");
    map_skill("dodge", "shuiyue");
    map_skill("unarmed", "cxwx-quan");
    map_skill("parry", "wangxiang-fufa");
	weapon = "/clone/weapon/gangaxe";
	}
	break;	
    case 23:{ //胡家
    set_skill("hunyuan-yiqi", tsjndj);
    set_skill("shaolin-shenfa", tsjndj);
    set_skill("yizhi-chan", tsjndj);
    set_skill("hujia-dao", tsjndj);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("parry", "hujia-dao");
    map_skill("unarmed", "yizhi-chan");
    map_skill("blade", "hujia-dao");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
    case 24:{ //红花会
	set_skill("youlong-shenfa", tsjndj);
    set_skill("luohua-jian", tsjndj);
    set_skill("baihua-cuoquan", tsjndj);	
    set_skill("honghua-shengong", tsjndj);     
    map_skill("force", "honghua-shengong");        	
    map_skill("sword","luohua-jian");
    map_skill("dodge", "youlong-shenfa");
    map_skill("parry", "luohua-jian");        	
    map_skill("unarmed", "baihua-cuoquan"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 25:{ //浣花
	set_skill("feihua-wuping", tsjndj);
    set_skill("huanhua-jian", tsjndj);
    set_skill("tiexian-quan", tsjndj);	
    set_skill("guiyuan-dafa", tsjndj);     
    map_skill("force", "guiyuan-dafa");        	
    map_skill("sword","huanhua-jian");
    map_skill("dodge", "feihua-wuping");
    map_skill("parry", "huanhua-jian");        	
    map_skill("unarmed", "tiexian-quan"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 26:{ //华山
	set_skill("huashan-shenfa", tsjndj);
    set_skill("huashan-jianfa", tsjndj);
    set_skill("poyu-quan", tsjndj);	
    set_skill("zixia-shengong", tsjndj);     
    map_skill("force", "zixia-shengong");        	
    map_skill("sword","huashan-jianfa");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "huashan-jianfa");        	
    map_skill("unarmed", "poyu-quan"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 27:{ //华山
	set_skill("huashan-shenfa", tsjndj);
    set_skill("dugu-jiujian", tsjndj);
    set_skill("hunyuan-zhang", tsjndj);	
    set_skill("zixia-shengong", tsjndj);     
    map_skill("force", "zixia-shengong");        	
    map_skill("sword","dugu-jiujian");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "dugu-jiujian");        	
    map_skill("unarmed", "hunyuan-zhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 28:{ //昆仑
	set_skill("yaoming-dodge", tsjndj);
    set_skill("liangyi-jian", tsjndj);
    set_skill("kunlun-zhang", tsjndj);	
    set_skill("xuantian-wuji", tsjndj);     
    map_skill("force", "xuantian-wuji");        	
    map_skill("sword","liangyi-jian");
    map_skill("dodge", "yaoming-dodge");
    map_skill("parry", "liangyi-jian");        	
    map_skill("unarmed", "kunlun-zhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 29:{ //昆仑漫天
	set_skill("yaoming-dodge", tsjndj);
    set_skill("mantianhuayu", tsjndj);
    set_skill("kunlun-zhang", tsjndj);	
    set_skill("xuantian-wuji", tsjndj);     
    map_skill("force", "xuantian-wuji");        	
    map_skill("throwing","mantianhuayu");
    map_skill("dodge", "yaoming-dodge");
    map_skill("parry", "kunlun-zhang");        	
    map_skill("unarmed", "kunlun-zhang"); 
	add_money("zimuzhen",500);
	weapon = "/d/tangmen/obj/zimuzhen";
	}
	break;
    case 30:{ //慕容世家
	set_skill("yanling-shenfa", tsjndj);
    set_skill("murong-jianfa", tsjndj);
	set_skill("douzhuan-xingyi", tsjndj);
    set_skill("canhe-zhi", tsjndj);	
    set_skill("shenyuan-gong", tsjndj);     
    map_skill("force", "shenyuan-gong");        	
    map_skill("sword","murong-jianfa");
    map_skill("dodge", "yanling-shenfa");
    map_skill("parry", "douzhuan-xingyi");        	
    map_skill("unarmed", "canhe-zhi"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
	case 31:{ //慕容世家
	set_skill("yanling-shenfa", tsjndj);
    set_skill("murong-daofa", tsjndj);
	set_skill("douzhuan-xingyi", tsjndj);
    set_skill("xingyi-zhang", tsjndj);	
    set_skill("shenyuan-gong", tsjndj);     
    map_skill("force", "shenyuan-gong");        	
    map_skill("blade","murong-daofa");
    map_skill("dodge", "yanling-shenfa");
    map_skill("parry", "douzhuan-xingyi");        	
    map_skill("unarmed", "xingyi-zhang"); 
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
    case 32:{ //青城
	set_skill("wuxue-shenfa", tsjndj);
    set_skill("pixie-sword", tsjndj);	
    set_skill("kuihua-xinfa", tsjndj);     
    map_skill("force", "kuihua-xinfa");        	
    map_skill("sword","pixie-sword");
    map_skill("dodge", "wuxue-shenfa");
    map_skill("parry", "pixie-sword");        	
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 33:{ //全真
	set_skill("qixing-huanwei", tsjndj);
    set_skill("quanzhen-jianfa", tsjndj);
	set_skill("qixing-array", tsjndj);
    set_skill("kongming-quan", tsjndj);	
    set_skill("xiantian-qigong", tsjndj);     
    map_skill("force", "xiantian-qigong");        	
    map_skill("sword","quanzhen-jianfa");
    map_skill("dodge", "qixing-huanwei");
    map_skill("parry", "quanzhen-jianfa");        	
    map_skill("unarmed", "kongming-quan"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 34:{ //神龙
	set_skill("yixingbu", tsjndj);
    set_skill("shedao-qigong", tsjndj);
    set_skill("shenlong-bashi", tsjndj);	
    set_skill("shenlong-xinfa", tsjndj);     
    map_skill("force", "shenlong-xinfa");        	
    map_skill("sword","shedao-qigong");
    map_skill("dodge", "yixingbu");
    map_skill("parry", "shedao-qigong");        	
    map_skill("unarmed", "shenlong-bashi"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;	
    case 35:{ //蜀山
	set_skill("zuixian-steps", tsjndj);
    set_skill("canxin-jian", tsjndj);
    set_skill("fumozhang", tsjndj);	
    set_skill("shushan-force", tsjndj);     
    map_skill("force", "shushan-force");        	
    map_skill("sword","canxin-jian");
    map_skill("dodge", "zuixian-steps");
    map_skill("parry", "canxin-jian");        	
    map_skill("unarmed", "fumozhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 36:{ //蜀山
	set_skill("zuixian-steps", tsjndj);
    set_skill("yujianshu", tsjndj);
    set_skill("fumozhang", tsjndj);	
    set_skill("shushan-force", tsjndj);     
    map_skill("force", "shushan-force");        	
    map_skill("sword","yujianshu");
    map_skill("dodge", "zuixian-steps");
    map_skill("parry", "yujianshu");        	
    map_skill("unarmed", "fumozhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 37:{ //蜀山
	set_skill("zuixian-steps", tsjndj);
    set_skill("songhe-sword", tsjndj);
    set_skill("fumozhang", tsjndj);	
    set_skill("shushan-force", tsjndj);     
    map_skill("force", "shushan-force");        	
    map_skill("sword","songhe-sword");
    map_skill("dodge", "zuixian-steps");
    map_skill("parry", "songhe-sword");        	
    map_skill("unarmed", "fumozhang"); 
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 38:{ //杀手楼
	set_skill("bugui-bufa", tsjndj);
    set_skill("qishen-dao", tsjndj);
    set_skill("fanyun-zhang", tsjndj);	
    set_skill("wuji-shengong", tsjndj);     
    map_skill("force", "wuji-shengong");        	
    map_skill("blade","qishen-dao");
    map_skill("dodge", "bugui-bufa");
    map_skill("parry", "qishen-dao");        	
    map_skill("unarmed", "fanyun-zhang"); 
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;
    case 39:{ //嵩山
	set_skill("lingxu-bu", tsjndj);
    set_skill("songshan-jian", tsjndj);
    set_skill("songyang-zhang", tsjndj);	
    set_skill("hanbing-zhenqi", tsjndj);     
    map_skill("unarmed", "songyang-zhang");
	map_skill("sword", "songshan-jian");
	map_skill("parry", "songshan-jian");
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "hanbing-zhenqi");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 40:{ //通吃
	set_skill("piaomiao-shenfa", tsjndj);
    set_skill("langzi-sword", tsjndj);
    set_skill("dabei-zhang", tsjndj);	
    set_skill("damo-force", tsjndj);     
    map_skill("unarmed", "dabei-zhang");
	map_skill("sword", "langzi-sword");
	map_skill("parry", "langzi-sword");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "damo-force");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 41:{ //铁掌
	set_skill("shuishangpiao", tsjndj);
    set_skill("duanyun-fu", tsjndj);
    set_skill("tiezhang-zhangfa", tsjndj);	
    set_skill("guiyuan-tunafa", tsjndj);     
    map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("axe", "duanyun-fu");
	map_skill("parry", "duanyun-fu");
	map_skill("dodge", "shuishangpiao");
	map_skill("force", "guiyuan-tunafa");
	weapon = "/clone/weapon/gangaxe";
	}
	break;	
    case 42:{ //五毒
	set_skill("wudu-yanluobu", tsjndj);
    set_skill("wudu-goufa", tsjndj);
    set_skill("qianzhu-wandushou", tsjndj);	
    set_skill("wudu-shengong", tsjndj);     
    map_skill("unarmed", "qianzhu-wandushou");
	map_skill("sword", "wudu-goufa");
	map_skill("parry", "wudu-goufa");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("force", "wudu-shengong");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 43:{ //血刀
	set_skill("shenkong-xing", tsjndj);
    set_skill("mingwang-jian", tsjndj);
    set_skill("dashou-yin", tsjndj);	
    set_skill("longxiang", tsjndj);     
    map_skill("unarmed", "dashou-yin");
	map_skill("sword", "mingwang-jian");
	map_skill("parry", "mingwang-jian");
	map_skill("dodge", "shenkong-xing");
	map_skill("force", "longxiang");
	weapon = "/clone/weapon/hanbing-jian";
	}
	break;
    case 44:{ //血刀
	set_skill("shenkong-xing", tsjndj);
    set_skill("xue-dao", tsjndj);
    set_skill("dashou-yin", tsjndj);	
    set_skill("longxiang", tsjndj);     
    map_skill("unarmed", "dashou-yin");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("dodge", "shenkong-xing");
	map_skill("force", "longxiang");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
    case 45:{ //血河
	set_skill("youran-bu", tsjndj);
    set_skill("jieniu-dao", tsjndj);
    set_skill("feixue-quan", tsjndj);	
    set_skill("longxiang", tsjndj);     
    map_skill("unarmed", "feixue-quan");
	map_skill("blade", "jieniu-dao");
	map_skill("parry", "jieniu-dao");
	map_skill("dodge", "youran-bu");
	map_skill("force", "yiqiguan-riyue");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
    case 46:{ //血河
	set_skill("youran-bu", tsjndj);
    set_skill("tianhe-jian", tsjndj);
    set_skill("feixue-quan", tsjndj);	
    set_skill("longxiang", tsjndj);     
    map_skill("unarmed", "feixue-quan");
	map_skill("sword", "tianhe-jian");
	map_skill("parry", "tianhe-jian");
	map_skill("dodge", "youran-bu");
	map_skill("force", "yiqiguan-riyue");
	weapon = "/clone/weapon/hanbing-dao";
	}
	break;	
    case 47:{ //星宿
	set_skill("huagong-dafa", tsjndj);
    set_skill("zhaixinggong", tsjndj);
    set_skill("chousui-zhang", tsjndj);
    set_skill("tianshan-zhang", tsjndj);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "chousui-zhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
	weapon = "/clone/weapon/gangzhang";
	}
	break;
    case 48:{ //逍遥
	set_skill("beiming-shengong", tsjndj);
    set_skill("lingboweibu", tsjndj);
    set_skill("zhemei-shou", tsjndj);
    set_skill("ruyi-dao", tsjndj);
    map_skill("force", "beiming-shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("unarmed", "zhemei-shou");
    map_skill("parry", "ruyi-dao");
    map_skill("blade", "ruyi-dao");
	weapon = "/clone/weapon/gangzhang";
	}
	break;	
	case 49:{ //唐门
	set_skill("qiulinshiye", tsjndj);
    set_skill("zimu-zhen", tsjndj);
    set_skill("biye-wu", tsjndj);	
    set_skill("biyun-xinfa", tsjndj);     
    map_skill("force", "biyun-xinfa");        	
    map_skill("throwing","zimu-zhen");
    map_skill("dodge", "qiulinshiye");
    map_skill("parry", "biye-wu");        	
    map_skill("unarmed", "biye-wu"); 
	add_money("zimuzhen",500);
	weapon = "/d/tangmen/obj/zimuzhen";
	}
	break;
	case 50:{ //唐门
	set_skill("qiulinshiye", tsjndj);
    set_skill("liuxing-biao", tsjndj);
    set_skill("biye-wu", tsjndj);	
    set_skill("biyun-xinfa", tsjndj);     
    map_skill("force", "biyun-xinfa");        	
    map_skill("throwing","liuxing-biao");
    map_skill("dodge", "qiulinshiye");
    map_skill("parry", "biye-wu");        	
    map_skill("unarmed", "biye-wu"); 
	add_money("zimuzhen",500);
	weapon = "/d/tangmen/obj/zimuzhen";
	}
	break;
	case 51:{ //唐门
	set_skill("qiulinshiye", tsjndj);
    set_skill("zhuihun-biao", tsjndj);
    set_skill("biye-wu", tsjndj);	
    set_skill("biyun-xinfa", tsjndj);     
    map_skill("force", "biyun-xinfa");        	
    map_skill("throwing","zhuihun-biao");
    map_skill("dodge", "qiulinshiye");
    map_skill("parry", "biye-wu");        	
    map_skill("unarmed", "biye-wu"); 
	add_money("zimuzhen",500);
	weapon = "/d/tangmen/obj/zimuzhen";
	}
	case 52:{ //天魔宫
	set_skill("tianmo-jian", tsjndj);
    set_skill("tianmo-shengong", tsjndj); 
    set_skill("tianmo-zhang", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "tianmo-shengong");
    map_skill("unarmed","tianmo-zhang");
    map_skill("parry", "tianmo-jian");
    map_skill("sword", "tianmo-jian");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/hanbing-jian";	
	}
	break;	
	case 53: { //天魔宫
	set_skill("tianmo-dao", tsjndj);
    set_skill("tianmo-shengong", tsjndj); 
    set_skill("tianmo-quan", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "tianmo-shengong");
    map_skill("unarmed","tianmo-quan");
    map_skill("parry", "tianmo-dao");
    map_skill("blade", "tianmo-dao");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/hanbing-dao";	
	}
	break;
	}
	set("weapon", weapon);
	setup(); 
	if( weapon != "null" ) carry_object(weapon)->wield(); 
    carry_object("/clone/cloth/hanbing-jia")->wear();
    add_money("gold", random(500));
}

void init()
{
	object ob, me, get_ob;
	int level;
    
	me = this_object();
    ob = this_player();

	// 怪物必须是可以动作的，并只针对玩家
	if ( !objectp(ob) || !living(me) || !playerp(ob) ) return;
	// 见面就杀
	me->kill_ob(ob);
    command("follow "+ob->query("id"));
    // 只复制等级比自己高的玩家等级
	if ( ob->query("xyzx_sys/level") < me->query("xyzx_sys/level") ) return;
	// 获得玩家总等级
	level = ob->query("xyzx_sys/level");
	// 只复制最高等级玩家
	if ( me->query_temp("kill_ob_lvl") >= level ) return;
	// 防止重复复制同一人
	if ( objectp(get_ob=me->query_temp("fight_killer_id")) && get_ob==ob ) return;
	//__________________标记目前复制状况___________________
	me->set_temp("fight_killer_id", ob);
	me->set_temp("kill_ob_lvl", level);
	//______________________标记结束_______________________
	//__________________________等级相关参数拷贝_____________________________
	//me->set("xyzx_sys/level", ob->query("xyzx_sys/level")*11/10);

	//______________________________拷贝完成_________________________________
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room, name;
	int m;

	ob = this_object();

	if ( !objectp(env=environment(ob)) 
		|| !stringp(room=env->query("short")) ) 
	{
		::die();
		return;
	}

	if ( ob->query_temp("last_damage_from") )
	{
		me = ob->query_temp("last_damage_from");
		m = random(3000);
		
		if ( interactive(me) )
		{
			message_vision(HIG"\n你杀死了 "+ob->name(1)+HIG" ，奖励了 "HIM+(m*me->query_exp_times())+HIG" 点经验和 "HIY+(m/10)+HIG" 潜能。\n"NOR, me);
			//message("party", HIW"【"+room+"】"+HIG+me->name(1)+HIM" 杀死了 "+ob->name(1)+HIM" ，奖励了 "HIC+(me->query_exp_times()*m)+HIM" 点经验和 "HIY+(m/10)+HIM" 潜能。\n"NOR,users() );	
			me->add("combat_exp",m);
			me->add("potential",m / 10);
		}
	}
	
	if ( objectp(corpse = CHAR_D->make_corpse(ob, me)) )
		corpse->move(environment(ob));

	if ( objectp(me) && objectp(ob) && random(100) > 80 )
    {
        baoshi = new(random_item[random(sizeof(random_item))]);
		name = baoshi->name(1);		    
        baoshi->set("xyzx_item/pinji", 4);
        baoshi->set("name", YEL"★" + name);

        message("party", HIW"【"+room+"】"+HIM"听说 "HIG+me->name(1)+HIM" 在 "+ob->name(1)+HIM" 尸体上发现了"HIW+baoshi->name(1)+"("+baoshi->query("id")+")。\n"NOR,users() );    
        baoshi->move(corpse);
    }
    else if ( random(100) < 5 )
		    {
			baoshi = new(random_item2[random(sizeof(random_item2))]);
            message("party", HIW"【"+room+"】"+HIM"听说 "HIG+me->name(1)+HIM" 在 "+ob->name(1)+HIM" 尸体上发现了"HIW+baoshi->name(1)+"("+baoshi->query("id")+")。\n"NOR,users() );				
			baoshi->move(corpse);
		}
	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}