//����ɽ�ɡ�mhxy-yushu 2001/2
// lilong alter 2002.01.19
inherit NPC;
#include <ansi.h>
string expell_me(object me);
int ask_jiu();
void create()
{
       set_name("�ƽ���", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", HIC"���ʿ"NOR);   
       set("long", "һ��������š��ƽ��ɡ������ٲ���������������ɽ��֮�ϣ��������ڽ�ͷ����֮�С�\n");
       set("gender", "����");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("max_qi", 10000000);
       set("max_jing", 10000000);
       set("neili", 10000000);
	   set("jingli", 10000000);
       set("max_neili", 10000000);
        set("max_jingli", 10000000);
		set("combat_exp", 2100000000);
         set("jiali",30000);
		 set("no_suck", 1);
        set_skill("shushan-force", 1500);
      set_skill("yujianshu", 1500);
      set_skill("fumozhang", 1500); 
      set_skill("zuixian-steps", 1500);
       set_skill("sword", 1500);
       set_skill("unarmed", 1500);
       set_skill("dodge", 1500);
       set_skill("literate",1500);
       set_skill("force", 1500);
       set_skill("parry", 1500);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
       set("inquiry", ([
                  "��ɽ": (: expell_me :),
                 "leave": (: expell_me :),

       ]) );
       create_family("��ɽ��", 2, "����");
       setup();
      carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ɽ��") {
         if ((int)ob->query("combat_exp") < 8000000 ) {
  	command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ�����С�\n");
	return;
	}
       if( (int)ob->query_skill("force", 1) < 500 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�㿴��ĺ����������Ұ�ʦ? �㻹����׷�����������Ű�!\n");
	command("sigh");
	return;
	}
       command("haha");
       command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
       command("recruit " + ob->query("id") );
	return;
	}
       command("shake");
       command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ�ƽ��ɵ���");

               } 
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="��ɽ��") {
                me->set_temp("betray", 1);
                return ("�����Ҫ�뿪��?��Ҫ����һЩ����,���Ը��(agree)?");
        }
        return ("��֪��");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N�����Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shushan", 1);
		  this_player()->set("combat_exp", this_player()->query("combat_exp")/100*95);
                if( this_player()->query_skill("shushan-force") )
		  this_player()->delete_skill("shushan-force");
                command("say ����ȥ�ɣ�\n");
                return 1;
                }
        return 0;
}

int ask_jiu()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "��ɽ��")
    {
    command("say ���ֲ�����ɽ�ɵģ�˭���㣡");
    return 1;
    }
}