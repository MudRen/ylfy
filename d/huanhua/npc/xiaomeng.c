// xiaomeng.c  ����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()

{

        set_name("����", ({ "xiao meng", "meng" }));
        set("nickname", HIW "��" NOR);
        set("long", 
                "���Ǹ���Լ���������꣬һ�����,����һ�����͵ĸо���\n"
                "�������������,������佻����ɵı���������\n");
        set("gender", "����");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 50000);
        set("max_jing", 50000);
        set("neili", 200000);
        set("max_neili", 2000);

        set("jiali", 1000);
        set("combat_exp", 40000000);
        set("score", 30000);

        set_skill("force", 700);
        set_skill("unarmed",900);
        set_skill("dodge", 700);
        set_skill("parry",700);
        set_skill("sword", 700);
        set_skill("literate", 600);
        set_skill("strike",600);

        set_skill("huanhua-jian",900);
        set_skill("tiexian-quan",900);
        set_skill("guiyuan-dafa",700);
        set_skill("feihua-wuping",700);

         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");

        create_family("佻�����", 3, "����");
        set("chat_chance_combat", 40);
        set("no_get",1);
        setup();

          carry_object("/clone/weapon/changjian")->wield();
          carry_object("/d/huanhua/obj/ccloth")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_str() > 24) {
        message_vision(HIY"����������$N�ļ������ؿ���Ц��Ц!\n"NOR,ob);
             command("say �ðɣ��Ҿ����������ҵĵ����ˡ�");
               command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
                ob->set("title","佻������������");
        return ;
            }
       else
               message_vision(HIC"���Ͷ���$N�����ϰ��죬̾�˿�����:��������������ʺ�ѧ�ҵĹ���!\n"NOR,ob);
               return ;

}