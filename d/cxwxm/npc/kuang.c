// kuang.c
// marry 8,19
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("������", ({ "lian gongkuang", "kuang", "lian" }) );
        set("gender", "����" );
        set("age", 20);
        set("long", "һ�������񣬳�������ѧ�����첻�Բ����ڴ�������\n");
        set("attitude", "heroism");

        set("str", 25);
        set("cor", 25);
        set("cps", 25);
        set("int", 25);
        set("no_xi", 1);
        set("max_qi", 300);
        set("eff_qi", 300);
        set("qi", 300);
        set("max_jing", 100);
    set("no_suck",1);
        set("jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("shen_type", 0);

        set("combat_exp", 50000);

        set_skill("force", 30); 
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);

        set("fight_times", 0);  
        create_family("����������", 4,"����");


        setup();
        carry_object("/d/cxwxm/obj/cloth2")->wear();
        
}

