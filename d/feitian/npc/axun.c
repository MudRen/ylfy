// axun.c ��Ѭ
// ����(diabio)2003.3.21
#include <ansi.h>;
inherit NPC;
string ask_lianxi();
void create()
{
        set_name("���Ѭ", ({"shengu xun", "shengu"}));
        set("gender", "Ů��");
//        set("nickname", HIC"��Ż�����"NOR);
             	set("title", HIC"��Ż�������ʦ��"NOR);
        set("age", 20);
                 set("rank","ʮ��");
        set("long",
            "糴彣�ĵİ��˾������ˣ�Ϊ�˽��������������������\n"
            "��������Ż������Ĵ�ʦ�����ᳫ���ǲ����˵Ľ�����\n"
            "����ȥ���Եķǳ��������������������Ƿǳ��ֲ��ġ�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
              set("per", 28);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
        }));

        set("qi", 165000);
        set("max_qi", 165000);
        set("jing", 168000);
        set("max_jing", 168000);
        set("neili", 180000);
        set("max_neili", 180000);
        set("jiali", 1600);

        set("combat_exp", 700000000);
        set("score", 100000);

                set_skill("cuff",1500);
        set_skill("force", 1500);
        set_skill("shayi-xinfa", 1900); 
        set_skill("blade", 1800);
        set_skill("huoxinliu-jianfa",1900); 
        set_skill("dodge", 1500);
        set_skill("wuxing-dun", 1900);  
        set_skill("parry", 2500);
        set_skill("unarmed",1500);
        set_skill("shayi",1900);
        set_skill("aikido", 1800);    
        set_skill("literate",1800);

        map_skill("force", "shayi-xinfa");
        map_skill("blade", "huoxinliu-jianfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "feitian-yujianliu");
        map_skill("unarmed", "aikido");
        prepare_skill("unarmed", "aikido");
       /*set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);*/
        create_family("����������", 7, "��ʦ��");

        set("inquiry", ([
                "����" :  "��֪�������ڿɺã��Һ�ǣ������\n",
                            "����������" :  "��Ż�������߽���Ϊ��������ʹ�ù���Σ�ա�\n",
                "����" :  "ʹ�ó���̫�������գ�����������ϰ����Ҫ��\n",
                "��ϰ" :  (: ask_lianxi :),
        ]) );

        setup();

      carry_object(__DIR__"obj/hefu")->wear();
      carry_object(__DIR__"obj/shoes")->wear();
      carry_object("/d/feitian/obj/zhujian")->wield();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shayi-xinfa") > 100) {
                command("say " + RANK_D->query_respect(ob) +
                        "ɱ���ķ�����ɱ�⣬���ɱ�����֮��ֻ�»ᱻ�������ƣ�");
                return;
}
        command("say �ðɣ��Ҿ����������ͽ���ˣ�ϣ������֪�������������ˡ�");
        command("recruit " + ob->query("id"));
	ob->set("title",HIR"����Ż�������"HIW"��ʦ��"NOR);
            ob->set("class", "yujianliu");
}	

string ask_lianxi()
{
        object me=this_player();
        me->set_temp("tmark/��ϰ",1);
        return("̾�˿��������ð�������������ϰȥ�ɣ�Ҫ������ǳ�����Ҫ���ǻ�������\n");
}

