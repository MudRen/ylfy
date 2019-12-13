#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({"geng wanzhong","geng"}));
        set("gender", "����");
        set("age", 20);
        set("long", 
               "���������ǵ��������ӹ����ӡ�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("max_qi", 1500);
        set("qi", 1500);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("shen_type", 0);
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
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 20) {
        command("say ����������,����ѧ����");
                return;
    }
        if( (string)ob->query("gender") != "����" ){
                 command("say ��λ"+RANK_D->query_respect(ob)+
"�Ҳ���Ůͽ��,�㻹��ȥ���һ�ʦ�ð�.");
                return;
    }

    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", "�����ǵ��ߴ�����"); 
}
