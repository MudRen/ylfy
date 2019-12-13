// Npc: xunluo.c

#include <ansi.h>

inherit NPC;

void create()
{
       set_name(CYN"����Ѳ��"NOR, ({
               "mingjiao xunluo",
               "xunluo",
       }));
       set("long",
               "����һλ���ⷢ�������Բ�����̽��ڣ�̫��Ѩ�߸߹���\n"
               "���ֳֹ�ͷ������һϮ���̷̽����ƺ����ճ�Ⱥ��\n"
       );


       set("gender", "����");
       set("attitude", "peaceful");
       set("class", "jiaozhong");

       set("age", 35);
       set("shen_type", 1);
       set("str", 30);
       set("int", 20);
       set("con", 25);
       set("cps", 25);
       set("max_qi", 500);
       set("max_jing", 300);
       set("neili", 1000);
       set("max_neili", 1000);
       set("jiali", 50);
       set("combat_exp", 200000);
       set("score", 1);

       set_skill("force", 100);
       set_skill("dodge", 80);
       set_skill("unarmed", 80);
       set_skill("parry", 80);
       set_skill("blade", 100);

       setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
       set("chat_chance", 30);
       set("chat_msg", ({
HIM"����Ѳ�ߵ������Ѿ��������������ˣ��Ž����Ƕ�������õģ�����ͷ��\n�����ĺ��˲����ˣ�\n"NOR,
HIM"����Ѳ�ߵ��������Ҵ�ţ�������к��������ڰ���ѵ��¹�������غϣ���\n"NOR,
HIM"����Ѳ�ߵ����������Ž������������屡���죬�书�������������ˣ�\nҲ���������쵱���������ӣ�\n"NOR,
HIM"����Ѳ��������⼸��ҹ̽������̳���˺ܶ࣬�������Ӳ���˯������ҹ�ﻹҪѲ�ߣ�\n"NOR,
                (: random_move :)
        }) );
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && !present("mingjiao lingpai", ob) 
        && ( (fam = ob->query("family")) && fam["family_name"] != "����" ) )
        {
                if( !ob->query_temp("warned") ) {
                        command("say ι��վס����");
                        command("say ��ҹ���������̸���´ο����������ģ�");
                        ob->set_temp("warned", 1);
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say �󵨿�ͽ�����Ҵ�������������Ұ������\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                }
        }
        if( environment(me)->query("no_out") )
            message_vision("$N����һ��̵˵������������������ܵÿ졣\n", this_object());
      me->set_leader(0);
        return 0;
}
