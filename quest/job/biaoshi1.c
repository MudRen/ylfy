#include <ansi.h>
inherit NPC;
void create()
{
      string weapon;        
        set_name("������ʦ", ({ "biaoshi"}));
        set("gender", "����");
        set("age", random(10) + 25);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "�����ھֵ���ʦ��\n");
        set("combat_exp", 1080000); 
        set("attitude", "friendly");
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuangfeng-jian", 80+random(180));
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 120);
        set_skill("zixia-shengong",100);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
                (: random_move :),
        }) );
 
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
//        map_skill("blade","fanliangyi-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 4700); 
        set("max_neili", 4700);
        set("jiali", 30);
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

