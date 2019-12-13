// dizi1.c ����
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���͵�����", ({ "di zi", "di", "zi" }));
        set("long", "������ʮ�����׳���������Բ���ǵ�������ԭ��ļ���ġ�\n");

        set("gender", "����");
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 200);
        set("int", 20);
        set("con", 20);
        set("dex", 200);

        set("qi", 50000);
        set("max_qi", 50000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 300000);
        set("max_neili", 3000);
        set("jiali", 300);

        set("combat_exp", 30000000);
        set("score", 10);
        set_skill("force", 700);
        set_skill("unarmed", 700);
        set_skill("dodge", 700);
        set_skill("parry", 700);
        set_skill("hand", 700);
        set_skill("staff", 500);

        create_family("���͵�", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        ob = this_player();
        if (interactive(ob) && !ob->is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object room;
        room = find_object("/d/xiakedao/dongmen");

        if( !ob || environment(ob) != environment()
                || environment() != room)
                return;
        switch( random(2) )
        {
                case 0:
                        say( "���͵�����˵������λ" + RANK_D->query_respect(ob)
                                 + "�����뵽ӭ������ЪЪ�Űɡ�\n");
                        break;
                case 1:
                        say( "���͵����ӹ���˵������λ" + RANK_D->query_respect(ob)
                                 + "���������ڵ����ء�\n");
                        break;
        }
}
