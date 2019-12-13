//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

inherit F_MASTER;
void create()
{
        set_name("����",({"bai wanjian","bai"}));
        set("nickname", HIC"��������"NOR);
        set("gender", "����");
        set("age", 30);
        set("long", 
               "������ѩɽ���������������������ڵĳ��ӣ���\n"
                "��ʦ�ֵܾ��ԡ��������У������־�Ȼ�е�����,\n"
                "�������֮��.�������������,�롮�������������\n"
                "��ϳơ�ѩɽ˫�ܡ���\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("per", 30);
        set("neili", 23000);
        set("max_neili", 23000);
        set("jing", 6000);
        set("max_jing", 6000);
        set("qi", 6000);
        set("max_qi", 6000);
        set("jiali", 80);
        set("combat_exp", 2500000);
        set("score", 50000);    
        set("shen_type", 1);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("force", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 120);

        set_skill("xueshan-jianfa", 200);	
        set_skill("bingxue-xinfa", 180);
        set_skill("snow-zhang", 200);
        set_skill("snowstep", 200);

        map_skill("sword", "xueshan-jianfa");	
        map_skill("parry", "xueshan-jianfa");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");
		set("inquiry", ([
            "������"   : "��ү�ӵ�̨�����е���!��",
            "��ү��"   : "����ݼ���ү���𣿵����չ����,����ҳ�ʦ��Ҫ������,���ܼ�������",
            "����"   :  "����ݼ���ү���𣿵����չ����,����ҳ�ʦ��Ҫ������,���ܼ�������",
            "����"   : "���������������ر�,ֻ��ƾ��,���ܽ��������",
        ]));
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.yanxue" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        create_family("������", 6, "����");
        setup();

        
        carry_object("/clone/money/gold.c");
        carry_object("/d/lingxiao/obj/baihongjian.c")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 28) {
        command("say ����������,���ܸ���ѧ����");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 60 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query_skill("xueshan-jianfa",1) < 80 ) { 
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
        }
    if ((int)ob->query_skill("sword",1) < 80 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    if ((int)ob->query("shen") < 20000 ) {
         command("say ѧ��������������������?"); 
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

