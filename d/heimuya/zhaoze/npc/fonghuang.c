// fonghuang.c
inherit NPC;
inherit F_DEALER;
int ask_dao();
void create()
{
        set_name(MAG "�����" NOR, ({"lan fonghuang", "lan", "fonghuang" }));
        set("title", CYN "�嶾����" NOR);
        set("shen_type", 5);
        set("gender", "Ů��");
        set("per",28);
        set("long",
                "�������˳��嶾����������ˡ�\n");
        set("age", 22);
        set("attitude", "friendly");
        set("inquiry", ([
                "��ӯӯ" : "�����ҽ̵�ʥ�á�\n",
                "�����" : "�����������ҽ�ʥ�õ������ˣ�",
                  "ʥʹ" : (: ask_dao :),
              "��˹ʥʹ" : (: ask_dao :),
        ]));
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        set("chat_chance", 3);
        set("chat_msg", ({
        "��������������˵������֪��Щ��˹ʥʹ����û�У�����\n",
        "��������������˵����ʥ�����ڶ���֪��ô�ˣ�����\n",
        }) );

        setup();
         carry_object("/clone/cloth/hiw_cloth")->wear();
}

void init()
{
    object me;
    me = this_player();
    if ( present("card4",me) )
    if (userp(me)){
        message_vision("������ŵ���æ���£���$N�ߺ�: ��֪ʥʹ�ݵ�����ʧӭ�£�\n",me);
        return;
    }  
}

int accept_object(object who, object ob)
{
        if ( (string) ob->query("id") =="card4" ) {
                message_vision("������������ƿ��˿�����$N˵������֪ʥʹ�кηԸ���\n"+
                               "˵������ƻ���$N��\n", who);
                new("/d/heimuya/npc/obj/card4")->move(who); 
                who->set_temp("tmark/��", 1);       
                return 1;
        }
       return 0;   
}

int ask_dao()
{
      if ((int)this_player()->query_temp("tmark/��")) {
           command("whisper " +this_player()->query("id")+ " ������Ƹ����ߵ��ϴ���ɣ�\n");
           this_player()->set_temp("tmark/��", 0);
           this_player()->set_temp("tmark/��1", 1);
           return 1;
           }
       return 0;   
}

