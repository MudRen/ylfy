// zhuge.c
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
        set_name("�����", ({ "zhuge" }) );
        set("gender", "����" );
        set("age", 35);
	 set("per", 30);
        set("long", "һλ�����ڽ��ɷ���ǵ���ʿ��\n");
        set("combat_exp", 1000000);
        set("attitude", "peaceful");
//      set("env/wimpy", 50);
	 set_skill("dodge", 180);
	 set_skill("unarmed",180);
	 set_skill("parry", 180);
	 set_skill("literate", 350);

  	set("chat_chance",10);
  	set("chat_msg",({
	WHT"�����̾����������֪���ģ����������о���γ��֮�ţ��κ�����֪������......��\n"NOR,

//        (:random_move:)
    	}));
        setup();
        add_money("gold", 10);
set("inquiry", ([
"name": "������������֮�ڶ�ʮ�������������Ҳ��\n",
"here": "���������ڣ������������֮��Ҳ��\n",
"�����": "��������ֱ�����������䣿\n",
"��������": "������֮����Ҳ���������ϻ�ƽ�����Ͻ���\n
�ʶ�������ȥ�Ͻ����������������һ��֮��",
"����": (: ask_me :),
"�һ���": (: ask_me :),
"����о�ɢ": (: ask_me :),
]) );
        carry_object("/clone/cloth/cloth")->wear();
}
int ask_me()
{
 //       mapping fam; 
        object ob;
//        if ((this_player()->query("shen")) < -1000)
//              return notify_fail("���ô...,���²�֪Ҳ��\n");
  
       command("say �置�һ��������ն��쳣��������������������֮������о�ɢ����������\n");
 command("say ���ҩҪ����Я������ĩ�������мǣ��мǣ�");
        ob = new(__DIR__"obj/xingjunsan");
        ob->move(this_player());
 //       return "��ȥ�ɡ�";
         return 1;
}
