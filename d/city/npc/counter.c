// d/city/npc/counter 
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int ask_mask(string str);
int counter(string str);
string ask_rename();
void create()
{
	set_name(HIW"���ξ�ʿ"NOR, ( { "suimeng jushi", "jushi","suimeng"}));
	set("title", HIY"����"NOR);
	set("nickname", HIC"����ٵ�"NOR);
	set("str", 37);
	set("gender", "����");
	set("age", 23);
	set("per",30);
	set("long","��˵�н���������Ǯ���ˣ�˭Ҳ��֪������Ǯ�����Ķ����ģ�ֻ֪�������Ϻܶ��˶���͵͵��Ħȭ���Ƶش���������Ϣ��ȴ������Ը��͸¶ԭ����������û���˳����Լ���������\n");
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
                    "����" : (: counter :),
					"��������":(:ask_rename:),
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
	if(me->query("more_money")<3) command("say ����ǵ��ﶫ��MM��ð���յ��¶������µġ����⡱�ƺ������ɡ�����");
	else
	{
		me->add("more_money",-3);
		birthday=me->query("birthday");
		answer=birthday%90+10;
		message_vision("���ξ�ʿ������һ�£�˵����˵����MM���������������"+answer+"�ˣ��˳�û�� \n" ,me);
		message_vision("ֻ�����ξ�ʿ���һָ�������Ѷ���һ���Ʊ�� \n" ,me);
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
		command("say �Ѿ����˻�����,����ô���̰��������?");
		return 1;
	}
	if (me->query("age",1) >=18)
	{
		command("say �ϴ�С����,��ֻ�᷹���ſ�,��������,��ѧѧ����������!");
		return 1;
	}
	else
	{
		message_vision(CYN "���ξ�ʿ΢Ц���ó�����ߣ����˸�$N \n" NOR,me);
		obj=new("/clone/misc/mask");
		obj->move(me);
		command("love");
		return 1;
	}
}
void fight_ob(object ob)
{
	::fight_ob(ob);
	message_vision("$Nҡ��ҡͷ���������޲��ɼ�.....��˵������һָ$n��\n",this_object(), ob);
	ob->unconcious();
}
int accept_fight(object who)
{
	command(":)");
	command("say ������ν��");
	return 0;
}
int accept_ansuan(object who)
{
//   return notify_fail("����밵�㣬������ǰһ��������̫�����\n");
	object me=this_player();
	message_vision("$N���밵�㣬������ǰһ��������̫�����\n",this_object(), who);
	me->kill_ob(who);
	return 1;
}
string ask_rename()
{
	object ob=this_player();
    write("��������Դ������±�����\n"+
          "     ��(jian)\n"+
          "     ��(dao)\n"+
          "     ��(gun)\n"+
          "     ��(staff)\n"+
		  "     ��(axe)\n"+
          "     ��(whip)\n");       
    return "��λ"+RANK_D->query_respect(ob)+"Ҫ��ʲô�����������˸�����(rename)��\n";
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
			return notify_fail("�㶼û����������Ҹ�ʲô��\n");
		if ( !me->query_temp("rename/���ξ�ʿ", 1) )
	    {
		command("heihei");
		command("say �����´�����������ȥ�Ҹ���Ʒ��������û�У��������ҡ�");
		return 1;
	    }
		if( !arg )
			return notify_fail("���ξ�ʿ�����˵��������������Ƽ����ź��ڶ���˵��\n");
		message("vision",me->name()+"�����ξ�ʿ����˵�˼��䡣\n",environment(me), ({me}) );
    switch (arg) {
      case "jian" :
        me->set("weapon/type","��");
        me->set("weapon/id","my sword");
        message("vision","���Ѿ��������������Ϊ���ˣ���ȥ��!!"+me->name()+"!\n",me);
        break;
      case "dao" :
        me->set("weapon/type","��");
        me->set("weapon/id","my blade");
        message("vision","���Ѿ��������������Ϊ���ˣ���ȥ��!!"+me->name()+"!\n",me);
        break;
      case "gun" :
        me->set("weapon/type","��");
        me->set("weapon/id","my club");
        message("vision","���Ѿ��������������Ϊ���ˣ���ȥ��!!"+me->name()+"!\n",me);
        break;
      case "staff" :
        me->set("weapon/type","��");
        me->set("weapon/id","my staff");
        message("vision","���Ѿ��������������Ϊ���ˣ���ȥ��!!"+me->name()+"!\n",me);
        break;
	  case "axe" :
        me->set("weapon/type","��");
        me->set("weapon/id","my axe");
        message("vision","���Ѿ��������������Ϊ���ˣ���ȥ��!!"+me->name()+"!\n",me);
        break;
      case "whip" :
        me->set("weapon/type","��");
        me->set("weapon/id","my whip");
        message("vision","���Ѿ��������������Ϊ���ˣ���ȥ��!!"+me->name()+"!\n",me);
        break;
      default :
        message_vision(HIC "���ξ�ʿһ�����ɣ�ʲô������\n" NOR,me);
        return notify_fail("���ξ�ʿ��ϸ��˵�����²��ɶ�Ϸ��������!!\n");
    }
    me->save();
	log_file("cmds/my_weapon", sprintf("%s(%s) ��������������ʱ�� on %s\n",me->query("name"),me->query("id"),CHINESE_D->chinese_time(5,ctime(time()))) );
    return 1;
}

int accept_object(object who, object ob)
{
	if ( ob->query("id")!="zuiyue xuanjing" )
	{
		command("say �������ҿ�ûɶ��Ȥ��");
		return 0;
	}
	
	command("say �ö�������������������ҿ����������´���һ�α�����");
	who->set_temp("rename/���ξ�ʿ", 1);
	return 1;
}