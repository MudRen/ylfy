//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����",({"wen wanfu","wen"}));
        set("gender", "����");
        set("age", 20);
        set("long", 
               "���������ǵ��������������\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("qi", 1200);
        set("max_qi", 1200);

        set("combat_exp", 200000);
        set("shen_type", 1);
        set("score", 20000);
        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 80);

        set_skill("xueshan-jianfa", 120);	
        set_skill("bingxue-xinfa", 120);
        set_skill("snow-zhang", 120);
        set_skill("snowstep", 120);

        map_skill("sword", "xueshan-jianfa");	
        map_skill("parry", "xueshan-jianfa");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 6, "����");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
       
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
