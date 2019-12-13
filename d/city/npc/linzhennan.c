// linzhennan.c 林震南
// modified by Jay 4/7/96

#include <ansi.h>

inherit NPC;

string do_quest();
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
	set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
	set("gender", "男性");
	set("age", 45);
	set("long", "他就是「福威镖局」的总镖头－－林震南。\n");
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("max_neili", 500);
	set("max_qi", 150000);	
	set("max_jing", 150000);	
	set("jiali", 10);
	set_skill("force", 40);
	set("per",19);
	set("no_get",1);	
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set("inquiry", ([
		"向阳老宅" : "林震南说道：那是我从前在福建时住的家院，已经破败了。\n",
		"福威镖局" : (: ask_fuwei :),
		"远图公" : (: ask_yuantu :),
		"林远图" : "林震南大怒：小孩子这么没礼貌，直呼先人名讳！\n",
		"放弃" : "赔偿我10两黄金可以考虑考虑。\n",
		"辟邪剑法" : (: ask_pixie:),
		"铜钱" : (: ask_tong:),
		"铜板" : (: ask_tong:),
		"运镖":(:do_quest:),
		"镖": (:do_quest:),
		]) );
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/long_cloth")->wear();
}

int ask_fuwei()
{
	say("林震南炫耀地说：我们林家三代走镖，一来仗着先祖远图公当年闯下的威名，二\n"
		"来靠著我们林家家传的玩艺儿不算含糊，这才有今日的局面，成为大江以南首屈\n"
		"一指的大镖局。江湖上提到『福威镖局』四字，谁都要翘起大拇指，说一声：『\n"
		"好福气！好威风！』哈哈，哈哈！\n");
	this_player()->set_temp("marks/林1", 1);
	return 1;
}

int ask_yuantu()
{
	if ( (int)this_player()->query_temp("marks/林1") ) 
	{
		say("林震南磕一磕烟斗，说道：远图公是我的祖父，福威镖局是他一手创办的。当年\n"
			"祖父以七十二路辟邪剑法开创镖局，当真是打遍黑道无敌手。其时白道上英雄见\n"
			"他太过威风，也有去找他比试武艺的，青城派掌门余观主的师父长青子少年之时\n"
			"便在他辟邪剑法下输了几招。\n");
		this_player()->set_temp("marks/林2", 1);
		return 1;
	}
	else 
	{
		say("林震南说道：远图公是我的祖父。\n");
		return 1;
	}
}

int ask_pixie()
{
	int p1, p2, p3, p4;
	
	if ((int)this_player()->query("passwd")) 
	{
		say("林震南不悦地说道：我不是都告诉你了吗？我的剑法不及先祖。\n");
	}
	else if ( (int)this_player()->query_temp("marks/林2") ) 
	{
		say("林震南一惊，说道：你怎么知道的？噢，我刚才说露嘴了。嗨，在下的功夫外人\n"
			"不知底细，其实及不上先祖。。\n");
		write("林震南顿一顿，接着对你低声说：先祖去世前，曾给家父留下");
		p1=random(4)+1;
		p2=random(4)+1;
		p3=random(4)+1;
		p4=random(4)+1;
		this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
		write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
			"百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
		write("个\n铜钱，我一直未解其中奥秘。\n");
	}
	else 
	{
		message("vision",
			HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"
			NOR, environment(), this_object() );
		kill_ob(this_player());
	}

	this_player()->delete_temp("marks/林1");
	this_player()->delete_temp("marks/林2");
	return 1;
}

int ask_tong()
{
	int p, p1, p2, p3, p4;
	
	if ( !(p=(int)this_player()->query("passwd")) ) 
	{
		say("林震南一脸讥笑的样子，说：怎么混到这一步了到处要钱？\n");
	}
	else 
	{
		write("林震南低声说：先祖去世前，曾给家父留下");
		p1=(int)p/1000;
		p2=(int)(p-p1*1000)/100;
		p3=(int)(p-p1*1000-p2*100)/10;
		p4=(int)(p-p1*1000-p2*100-p3*10);
		write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
			"百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
		write("个\n铜钱，我一直未解其中奥秘。\n");
	}
	
	return 1;
}

string chinese_time(int t)
{
	int d, h, m, s;
	string time;

	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	h = t % 24;
	t /= 24;
	d = t;
	
	if ( d ) time = chinese_number(d) + "天";
	else time = "";
	if ( h ) time += chinese_number(h) + "小时";
	if ( m ) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	return time;
}

string do_quest()
{
	mapping target = ([
		"tang nan":         "当铺老板 唐楠",
		"yue buqun":        "华山派现任掌门「君子剑」岳不群",
		"post officer":     "驿长杜宽",
		"ping yizhi":       "药铺老板 平一指",
		"wu liuqi":          "天地会洪顺堂香主「铁丐」吴六奇",
		"tai jian":         "太监",
		"shi wei":          "侍卫",
		"mo yixin":         "药铺老板 莫一心",
		"xu zhu":           "灵鹫宫掌门人「梦郎」虚竹",
		"jian zhanglao":    "丐帮九袋长老「执法长老」简长老",
		"lu youjiao":		"丐帮九袋长老「掌棒龙头」鲁有脚",
		"yu lianzhou":      "武当派第二代弟子「武当二侠」俞莲舟",
		"song yuanqiao":    "武当派第二代弟子「武当首侠」宋远桥",
		"li lishi":         "李力世",
		"zhaixing zi":      "星宿派第二代弟子「星宿派大师兄」摘星子",
		//"zhang sanfeng":    "武当派开山祖师「邋遢真人」张三丰",
		"chen jin nan":     "云龙门开山祖师「英雄无敌」陈近南",
		"guan anji":        "茶馆老板「关夫子」关安基",
		"lazhang huofo":    "活佛 拉章活佛",
		"you xun":          "「滑不留手」游讯",
		"li mochou":        "「赤练仙子」李莫愁",
		"lao ban":          "「笑咪咪」茶馆老板",
		"yuan chanshi":     "昭觉寺主持 圆觉禅师",
		"jia laoliu":       "当铺老板 贾老六",
		"chen mapo":        "麻婆豆腐创始人「豆腐西施」陈麻婆",
		"xuan zhen":        "云龙门第二代弟子 玄真道长",
		"huang yaoshi":     "桃花岛开山祖师「东邪」黄药师",
		"hong antong":      "神龙教教主「永享仙福」洪安通",        
		"ouyang feng":      "老毒物「西毒」欧阳锋",
		"ding chunqiu":     "星宿派开山祖师「星宿老怪」丁春秋",
		"li defa":          "药铺老板 李得发",
		"ben yin":          "天龙寺主持 本因",
		"jiang baisheng":   "江百胜",
		"zhang wuji":       "明教教主 张无忌",
		"wei yixiao":       "明教青翼蝠王 韦一笑",
		"ouye zi":          "玄天派开山祖师「赤心剑胆」欧冶子",
		]);

	int ran, t, time;
	string *str;
	object ob, who, home;
	
	ob = this_object();
	
	if ( !home = find_object(ob->query("startroom")) )
		home = load_object(ob->query("startroom"));
	if ( environment(ob)!=home ) 
	{
		return("我现在正忙着呢！等我回去再说吧！");
	}
        
	who = this_player();

if ( who->query("xyzx_sys/level") >= 300 )
		return (HIR"你已经不能通过运镖来进行磨练了，可以去试试守城。\n"NOR);
	/*if ( (who->query("combat_exp")+who->query("xyzx_sys/levup_exp"))/LEVUP_EXP+who->query("xyzx_sys/level") < 2 )
		return (HIR"以你目前的修为还不能让我放心，你还是先去试试打鸟吧。\n"NOR);*/

	t = time()-who->query("biao_start");
	time = who->query("biao_time");
	
	if ( t <= time || who->query_temp("biaoyin_ob") ) 
		return  RANK_D->query_respect(who)+ "似乎还有任务在身吧？\n";
	if ( t > time && t < (time + 300) ) 
	{
		if( ob = present("biao yin", who) ) destruct(ob);
		who->set("biao_failed",1);
	}
	if ( t >= (time + 300) ) who->delete("biao_failed");
	if ( who->query("biao_failed") ) 
	{
		command("hehe " + who->query("id"));
		return this_player()->name() + "，你印堂发黑，流年失利，我看还是不适宜运镖了。\n";
	}
	
	t = ( 20 + random(20) ) * 10;
	str=keys(target);
	ran = random(sizeof(str));
	ob = new("/clone/misc/biaoyin");
	ob->set("target", str[ran]);
	who->set("biao_start", time());
	who->set("biao_time", t);
	who->set_temp("biaoyin_ob", ob); // 用来清除的
	ob->move(who);
	return (who->name()+"，你来得正好，我有一箱镖银送到" + target[str[ran]] + "的手里。\n"+"你还有" + chinese_time(t)+ "的时间。快快动身吧！\n");       
}


int accept_object(object me, object obj)
{
	object biaoyin;
	if ( obj->query("money_id") && obj->value() >= 100000 )
	{
		command("say 好吧！"+me->name()+"，上次的任务就算了！");
		me->delete("biao_start");
        me->delete("biao_time");
		if ( objectp(biaoyin=me->query_temp("biaoyin_ob")) )
		{
			biaoyin->remove_robber();
			destruct(biaoyin);
		}
		me->delete_temp("biaoyin_ob");
		return 1;
	}
	else
		command("say ...喂....喂...！"+me->name()+"，要真有心孝敬我老人家也该拿出点诚意来才行啊！");
	return 0;
}
