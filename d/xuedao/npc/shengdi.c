
// /kungfu/class/xueshan/shengdi.c  ʤ��
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ʤ��", ({ "sheng di", "sheng", "di" }));
        set("long",@LONG
����һ�����ο��������ɮ�ˣ���ɫ��Į���书��ͬ������ߵ�һ�ˡ�
LONG
        );
        set("title",HIR"Ѫ���ŵ��������"NOR);
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
set("max_qi", 100000);
set("max_jing", 50000);
set("neili", 1000000);
set("max_neili", 1000);
set("jiali", 1250);
set("combat_exp", 120000000);
set("score", 50000);
set_skill("lamaism", 850);
set_skill("literate", 1000);
set_skill("force", 1000);
set_skill("parry", 1000);
set_skill("blade", 1300);
set_skill("dodge", 1000);	
set_skill("longxiang", 1000);
set_skill("shenkong-xing", 1000);
set_skill("hand", 1000);
set_skill("dashou-yin", 1000);
set_skill("xue-dao", 1300);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
map_skill("unarmed", "dashou-yin");	
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");

        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");
set("chat_chance_combat", 100);			
set("chat_msg_combat", ({		
(: perform_action, "blade.kuangdao" :),		
(: perform_action, "blade.shendao" :),		
(: exert_function, "recover" :),		
}) );		
        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

        add_money("gold",1);
}


/*
void init()
{
        object ob;
        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="sheng di")
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
        if (ob->query("shen") > -50000)
        {
                command("say �����һ�Ҫ�Ƚ�������ĺ�ɱ�ˡ�\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 45)
        {
                command("say ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", "Ѫ���ŵ���������");
}
