// shiqian
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ʯǧ", ({"shi qian", "qian", "shi gonggong"}));
        set("title", "�����ܹ�");
        set("long",
        "���Ƕ����ܹ�ʯǧ�������ϲ���֬�ۣ�һ����Ů�˵����ӡ���˵��ɱ����������������\n"
        );
        set("gender", "����");
        set("rank_info/respect", "����");
        set("attitude", "heroism");
        set("class", "eunach");
        set("age", 70);
        set("str", 105);
        set("int", 120);
        set("con", 120);
        set("dex", 100);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 50000);
        set("max_neili", 20000);
        set("jiali", 300);
        set("combat_exp", 16600000);
        set("score", 5000);
        set("apply/attack",  30);
        set("apply/defense", 30);
        set_skill("force", 550);
        set_skill("unarmed", 550);
        set_skill("sword", 550);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("pixie-jian", 550);
        map_skill("dodge", "pixie-jian");
        map_skill("sword", "pixie-jian");
        map_skill("parry", "pixie-jian");
        create_family("  ", 13, "  ");
        setup();

        set("chat_chance", 15);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/food/jiudai");
        carry_object("/d/city2/obj/yaofen");
        add_money("silver", 50);
}
void attempt_apprentice(object ob)
{   
     
     if ((int)ob->query_skill("pixie-jian", 1) < 300) 
           {
        command("say " + RANK_D->query_respect(ob) + "����������ƺ�......��");
        return;
       }
    command("recruit " + ob->query("id"));
        ob->set("title","һƷ��������");
   }
