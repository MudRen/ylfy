// xiaogang.c  ����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
//inherit F_DEALER;

void create()

{
        set_name("����", ({ "xiao gang", "gang" }));
        set("nickname", HIY "��" NOR);
        set("long",       "�����������������书��õ�һ������,����Լ30��������վ�����ﰲ������,���˾���ʮ�ֿ���\n"
                "��������Ļ���,��佻����ɵĻ�������,���µ���Ҳ��ȫ���͵����\n");
        set("gender", "����");
        set("age", 29);
        set("attitude", "peaceful");
        
        set("no_get",1);
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 100000);
        set("max_jing", 75000);
        set("neili", 700000);
        set("max_neili", 2000);
        set("jiali", 1000);
        set("combat_exp", 40000000);
        set("score", 30000);

        set_skill("force", 800);
        set_skill("unarmed",800);
        set_skill("dodge", 900);
        set_skill("parry",900);
        set_skill("sword", 900);
        set_skill("literate", 800);
        set_skill("strike",900);
        set_skill("huanhua-jian",800);
        set_skill("tiexian-quan",800);
        set_skill("guiyuan-dafa",800);
        set_skill("feihua-wuping",800);

         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");
         create_family("佻�����", 3, "����");
        set("chat_chance_combat", 40);
        setup();
          carry_object("/clone/weapon/changjian")->wield();
          carry_object("/d/huanhua/obj/ccloth")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() > 24) {
        message_vision(HIY"����������$N�ļ������ؿ���Ц��Ц!\n"NOR,ob);
              command("say �ðɣ��Ҿ����������ҵĵ����ˡ�");
                command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
                ob->set("title","佻����ɻ������");
        return ;
            }
       else
               message_vision(HIC"���ն���$N�����ϰ��죬̾�˿�����:��������������ʺ�ѧ�ҵĹ���!\n"NOR,ob);
               return ;
}