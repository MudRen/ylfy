
// /kungfu/class/xueshan/shanyong.c  ����
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "shan yong", "shan", "yong" }));
        set("long",@LONG
һ�����ֵ�����ɮ�ˣ����Ц�ݣ�ȴ����Ц��ص����¡�
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
set("max_qi", 80000);
set("max_jing", 40000);
set("neili", 800000);
        set("max_neili", 800);
set("jiali", 750);
set("combat_exp", 80000000);
        set("score", 20000);

set_skill("lamaism", 750);
set_skill("literate", 600);
set_skill("force", 900);
set_skill("parry", 600);
set_skill("blade", 1000);
set_skill("dodge", 800);
set_skill("longxiang", 650);
set_skill("shenkong-xing", 600);
set_skill("hand", 600);
set_skill("dashou-yin", 800);
set_skill("xue-dao", 1000);

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
}

/*
void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="shan yong")
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
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", "Ѫ���ŵ���������");
}
