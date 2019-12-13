// /kungfu/class/xueshan/xuedao.c  Ѫ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ѫ������", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š�
LONG
        );
        set("title",HIR"Ѫ���ŵ��Ĵ�����"NOR);
        set("gender", "����");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000000);
        set("max_jing", 1000000);
        set("neili", 10000000);
        set("max_neili", 200000);
        set("jiali", 15000);
		set("xyzx_sys/level", 1500);
        set("combat_exp", 580000000);
        set("score", 180000);

        set_skill("lamaism", 1500);
        set_skill("literate", 2800);
        set_skill("force", 2800);
        set_skill("parry", 2500);
        set_skill("blade", 2200);
        set_skill("sword", 2300);
        set_skill("dodge", 2800);
        set_skill("longxiang", 1800);
        set_skill("shenkong-xing", 1800);
        set_skill("dashou-yin", 1800);
        set_skill("mingwang-jian", 1800);
        set_skill("xue-dao", 2000);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        set("chat_chance_combat", 20);  
        set("chat_msg_combat", ({
                (: command("unwield flood blade") :),
                (: command("wield flood blade") :),
        }) );

        create_family("ѩɽ��", 4, "����");
        set("class", "bonze");
set("chat_chance_combat", 300);				
set("chat_msg_combat", ({			
(: perform_action, "blade.shendao" :),			
(: perform_action, "blade.kuangdao" :),		
(: exert_function, "recover" :),			
}) );			
        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();
//    carry_object("/d/xueshan/npc/obj/xblade")->wield();	

        add_money("gold",2);
}



/*
void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="xuedao laozu")
        {
                      command("chat "+ob->query("name")+"! װʲô������ʿ���Ӵ��Ժ���Ͳ�Ҫ�ٵ�ѩɽ������! \n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","Ѫ����" + RED + "��ͽ" NOR);   
        }
}

*/
void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����")
        {
                command("say �Ҳ���Ůͽ�ܡ�\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "ѩɽ��")
        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��ŵ��ӣ�������ذɣ�\n");
                return;
        }
if ((int)ob->query("shen") > -10000000)
        {
                command("say ���ǲ����������������ɱ�˶����ᣡ\n");
                return;
        }
if ((int)ob->query_skill("longxiang", 1) < 500)
        {
                command("say ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

          ob->set("title","Ѫ�������Ŵ����");
}
