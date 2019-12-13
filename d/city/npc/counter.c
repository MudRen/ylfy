// d/city/npc/counter 
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int ask_mask(string str);
int counter(string str);
string ask_rename();
void create()
{
	set_name(HIW"碎梦居士"NOR, ( { "suimeng jushi", "jushi","suimeng"}));
	set("title", HIY"大神"NOR);
	set("nickname", HIC"开天辟地"NOR);
	set("str", 37);
	set("gender", "男性");
	set("age", 23);
	set("per",30);
	set("long","传说中江湖中最有钱的人，谁也不知道他的钱都从哪儿来的，只知道江湖上很多人都在偷偷的摩拳擦掌地打听他的消息，却从来不愿意透露原因，甚至从来没有人承认自己见过他。\n");
	set("no_get",1);
	set("attitude", "friendly");
	set("max_qi",5555533333);
	set("combat_exp",500000000+random(300000000));
	set("xyzx_sys/level", 30000000);
	set("max_jing",5555533333);
	set("neili", 8000000000);
	set("max_neili", 800000000);
	set_skill("qimen-wuxing", 3500);
	set_skill("qufeng", 3500);
	set_skill("force", 3500);
	set_skill("king-of-dragon", 3500);
	set_skill("daya-jian", 3500);
	set_skill("dodge", 3500);
	set_skill("sword", 3500);
	set_skill("parry", 3500);
	set_skill("blade", 3500);
	set_skill("unarmed", 3500);
	set_skill("whip", 3500);
	set_skill("axe", 3500);
	set_skill("dragon", 3500);
	set_skill("magic-old", 3500);
	set_skill("spells", 3500);
	set_skill("magic", 3500);
	map_skill("sword", "daya-jian");
	map_skill("parry", "daya-jian");
	map_skill("force", "king-of-dragon");
	map_skill("dodge", "king-of-dragon");
	map_skill("unarmed", "dragon");
	map_skill("spells", "magic-old");
	set("inquiry", ([
                    "生日" : (: counter :),
					"重铸兵器":(:ask_rename:),
	                ]));

	setup();
	carry_object("/clone/weapon/fyue")->wield();
	carry_object("/clone/cloth/qiankun")->wear();
}

int counter(string str)
{
	int birthday,answer;
	object me;
	me = this_player();
	if(me->query("more_money")<3) command("say 这可是得罪东方MM的冒风险的事儿，阁下的“诚意”似乎不够吧。。。");
	else
	{
		me->add("more_money",-3);
		birthday=me->query("birthday");
		answer=birthday%90+10;
		message_vision("碎梦居士沉吟了一下，说：据说东方MM最近的幸运数字是"+answer+"了，八成没错。 \n" ,me);
		message_vision("只见碎梦居士凌空一指，手上已多了一打金票。 \n" ,me);
		command("bow");
		command("thanks");
	}
	return 1;
}
int ask_mask(string arg)
{
	object me,obj;
	object zi;
	me = this_player();
	zi=this_object();
	if(present("mian ju", me) || present("mian ju", environment()))
	{
		command("say 已经有了还想拿,你怎么如此贪得无厌呢?");
		return 1;
	}
	if (me->query("age",1) >=18)
	{
		command("say 老大不小的了,还只会饭来张口,衣来伸手,该学学独立生活了!");
		return 1;
	}
	else
	{
		message_vision(CYN "碎梦居士微笑着拿出个面具，送了给$N \n" NOR,me);
		obj=new("/clone/misc/mask");
		obj->move(me);
		command("love");
		return 1;
	}
}
void fight_ob(object ob)
{
	::fight_ob(ob);
	message_vision("$N摇了摇头，道：“愚不可及.....”说完伸手一指$n。\n",this_object(), ob);
	ob->unconcious();
}
int accept_fight(object who)
{
	command(":)");
	command("say 后生可谓！");
	return 0;
}
int accept_ansuan(object who)
{
//   return notify_fail("你刚想暗算，可是眼前一花，看不太清楚。\n");
	object me=this_player();
	message_vision("$N刚想暗算，可是眼前一花，看不太清楚。\n",this_object(), who);
	me->kill_ob(who);
	return 1;
}
string ask_rename()
{
	object ob=this_player();
    write("我这儿可以打造以下兵器：\n"+
          "     剑(jian)\n"+
          "     刀(dao)\n"+
          "     棍(gun)\n"+
          "     杖(staff)\n"+
		  "     斧(axe)\n"+
          "     鞭(whip)\n");       
    return "这位"+RANK_D->query_respect(ob)+"要造什么兵器？决定了告诉我(rename)。\n";
}
 void init()
{
        ::init();
        add_action("do_zhu","rename");
}
int do_zhu(string arg)
{
		object me;
		me = this_player();
		if(!me->query("weapon/make") )
			return notify_fail("你都没有造兵器，乱改什么！\n");
		if ( !me->query_temp("rename/碎梦居士", 1) )
	    {
		command("heihei");
		command("say 想重新打造武器，先去找个极品材料来，没有？别来烦我。");
		return 1;
	    }
		if( !arg )
			return notify_fail("碎梦居士认真的说：想好武器的名称及代号后在对我说。\n");
		message("vision",me->name()+"对碎梦居士轻声说了几句。\n",environment(me), ({me}) );
    switch (arg) {
      case "jian" :
        me->set("weapon/type","剑");
        me->set("weapon/id","my sword");
        message("vision","我已经把你的武器重铸为剑了，拿去吧!!"+me->name()+"!\n",me);
        break;
      case "dao" :
        me->set("weapon/type","刀");
        me->set("weapon/id","my blade");
        message("vision","我已经把你的武器重铸为刀了，拿去吧!!"+me->name()+"!\n",me);
        break;
      case "gun" :
        me->set("weapon/type","棍");
        me->set("weapon/id","my club");
        message("vision","我已经把你的武器重铸为棍了，拿去吧!!"+me->name()+"!\n",me);
        break;
      case "staff" :
        me->set("weapon/type","杖");
        me->set("weapon/id","my staff");
        message("vision","我已经把你的武器重铸为杖了，拿去吧!!"+me->name()+"!\n",me);
        break;
	  case "axe" :
        me->set("weapon/type","斧");
        me->set("weapon/id","my axe");
        message("vision","我已经把你的武器重铸为斧了，拿去吧!!"+me->name()+"!\n",me);
        break;
      case "whip" :
        me->set("weapon/type","鞭");
        me->set("weapon/id","my whip");
        message("vision","我已经把你的武器重铸为鞭了，拿去吧!!"+me->name()+"!\n",me);
        break;
      default :
        message_vision(HIC "碎梦居士一脸狐疑：什么兵器？\n" NOR,me);
        return notify_fail("碎梦居士仔细的说：此事不可儿戏，请慎重!!\n");
    }
    me->save();
	log_file("cmds/my_weapon", sprintf("%s(%s) 重铸了自练武器时间 on %s\n",me->query("name"),me->query("id"),CHINESE_D->chinese_time(5,ctime(time()))) );
    return 1;
}

int accept_object(object who, object ob)
{
	if ( ob->query("id")!="zuiyue xuanjing" )
	{
		command("say 这玩艺我可没啥兴趣！");
		return 0;
	}
	
	command("say 好东西，有了这个东西，我可以替你重新打造一次兵器！");
	who->set_temp("rename/碎梦居士", 1);
	return 1;
}