#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
void create()
{
        set_name("����", ( {"die qing","qing"} ) );
        set("long","����ɵ���ʮ�˴����ӡ�\n" );
        create_family("�����", 48 , "����");
        set("attitude", "peaceful");
        set("age", 35);
        set("gender", "Ů��");
        set("shen_type", 1);
        set("chat_chance", 1);
        set("no_drop",1);
        set("con", 30);
        set("dex", 30);
        set("int", 30);
        set("str", 30);
        set("per", 40);
        set("ker", 40);
        set("qi", 200000);
        set("max_qi", 200000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("jingli", 5000);
        set("max_jingli", 5000);
        set("neili", 150000);
        set("max_neili", 150000);
        set("jiali", 100);

        set("combat_exp", 100000000);

        set_skill("dodge", 350);
        set_skill("force", 340);
		set_skill("taoism", 300);
        set_skill("meinv-shenquan",300);
        set_skill("literate",300);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 400);
        set_skill("dieyi-jianfa", 380);
        set_skill("wudie-xinjing", 350);
        set_skill("wudie-bu", 390);
        map_skill("force", "wudie-xinjing");
        map_skill("dodge", "wudie-bu");
        map_skill("parry", "dieyi-jianfa");
        map_skill("sword", "dieyi-jianfa");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: command("perform wudie") :),
                (: command("exert duan") :),
        }) );


        setup();

        carry_object("d/wudie/obj/dieyi")->wear();
        carry_object("d/wudie/obj/jian")->wield();

}




