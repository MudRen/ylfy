//����ɽ���ɡ�dhxy-evil 2000.7.5
//lilong���� 2002.01.12
inherit NPC;
#include <ansi.h>
int do_report();
void create()
{
        set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","��ɽ�������ŵ���");
        set("long", 
"����ң��Ľ��ݣ�����Ũü���ۣ������Ѱ���\n");
        set("gender", "����");
        set("age", 18);
	 set("class", "xiake");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("qi", 15000000);
        set("max_qi", 15000000);
        set("jing", 15000000);
        set("max_jing", 15000000);
        set("neili", 15000000);
        set("max_neili", 15000000);
        set("combat_exp", 2100000000);
        set("max_jingli", 15000000);
        set("jingli", 15000000);
         set("jiali",10000);
		set("no_suck", 1);
        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("unarmed", 1500);
         set_skill("fumozhang", 1500);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("canxin-jian", 1500);
        set_skill("shushan-force", 1500);
        set_skill("zuixian-steps",1500);
        set_skill("literate",1500);
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
        set("inquiry", ([
                "�ȳ�����"    : (: do_report :),
        ]));
        setup();
        create_family("��ɽ��", 3, "����");
         carry_object("/clone/cloth/dao-cloth")->wear();
         carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="��ɽ��" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
			else command("say ʦ�ü�Ц�ˡ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
			else command("say ʦ��̫�����ˡ�\n");
		}
		else 
		{
			command("consider");
			command("say ��������ĳ���ķ���,������Ϊͽ!\n");
			command("recruit " + ob->query("id") );
                     ob->set("shushan/xiangsi_perform",1);

		}
	}
            else
	{
		command("say ��������ĳ���ķ���,������Ϊͽ!\n");
		command("recruit " + ob->query("id") );
              ob->set("shushan/xiangsi_perform",1);

	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ������ң����");
              }
              return 0;
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "����ң˵������λ" + RANK_D->query_respect(ob) +
"���ܲ��ܰ��Ҿȳ�����������ؽ����������ˣ�\n");
}

int do_report()
{
 int i=random(3000000);
 object me = this_player();
 if(me->query("shushan/zhanyi")) { 
 me->set("zhanyi/zhenyaota",1);
 me->delete("shushan/zhanyi");
 me->add("combat_exp",50000+i);
 me->add("neili",1000);
 message("system",HIC"��"HIW"��������Ѷ"HIC"��"HIY+me->query("name")+HIG"�ȳ�[1;37m������[1;32m�����������ܵ�������[2;37;0m\n"NOR,users());    
 tell_object(me,"��Ӯ����50000��ľ����1000�������\n");
 me->save();
 } 
 else 
 {
 command("say лл�㣡�������鷳������");
 }
 return 1;
}



