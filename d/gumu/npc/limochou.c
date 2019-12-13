#include <ansi.h>


inherit NPC;

int do_look(string);
int ask_me();

void create()
{
        set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
        set("long", "�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
        set("nickname", HIB"��������"NOR);
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        create_family("��Ĺ��", 3, "����");
        set("age", 27); 
        set("per", 28);        set("attitude","heroism");
        set("str", 22);
        set("dex", 23);
        set("con", 20);
        set("int", 23);
		set("jiali",30);
        set("combat_exp", 1000000);
        set("max_qi", 2500);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);

        set("shen_type", -1);

        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("sword", 150);
        set_skill("throwing",100);
        set_skill("poison", 50);
        set_skill("meinv-quanfa", 150);
        set_skill("unarmed", 150);
        set_skill("meinv-quanfa", 150);       
        set_skill("yunv-shenfa", 150);
        set_skill("yunv-jianfa", 150);
        set_skill("yunv-xinjing", 150);
        map_skill("force", "yunv-xinjing");
        map_skill("dodge", "yunv-shenfa");
        map_skill("unarmed", "meinv-quanfa");
        map_skill("sword", "yunv-jianfa");
      //  prepare_skill("cuff", "meinv-quanfa");
        
        set("inquiry", ([
            "name" : "վԶ�㣡",
            "here" : "�Ҳ��Ǳ����ˣ���֪����",
            "��" : "����������������˼֮�ࡢ���֮�⣿",
            "½չԪ" : "�����Ǹ������С������ʲô��",
            "�����" : (: ask_me :),
            "С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
            "�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
            "��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
            "��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
            "��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
            "��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
            "��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
            "��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
            "��Ī���������Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������\n",
            "��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
        }) );

        carry_object("/d/gumu/obj/zhen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();

}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","hug");
        add_action("do_look","mo");
        add_action("do_look","18mo");
        add_action("do_look","kiss");
        add_action("do_look","lean");
        add_action("do_look","interest");
        add_action("do_look","flirt");
        add_action("do_look","pretty");
        add_action("do_look","love");

}

int ask_me()
{
        object me;
 
        me = this_player();
           message("vision",
   HIR "��Ī����Цһ���������������ȥ��������\n"
       "��Ī�����ɱ��" + me->name() +"��\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return 1;
}
  

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (id(target)) 
           if ((string)me->query("gender") == "����") {
                   message("vision",
   HIR "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
       "��Ī�����ɱ��" + me->name() +"��\n"
   NOR, environment(), this_object() );
        command("throw " + me->query("id"));
                   kill_ob(this_player());
           }
} 

void kill_ob(object me)
{     
      command("haha");
      command("throw " + me->query("id"));            
      ::kill_ob(me);

}
/*
void unconcious()
{
       message_vision("$N����һЦ��ת�����һö���룬������ͷ�쿴����׼Ӿ�����������������ɣ�֡�\n",this_object());        
       command("sneer");
       destruct(this_object());
}
*/
