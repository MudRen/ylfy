// sun.c ������
#include "/quest/quest.h"
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({"sun popo", "sun"}));
        set("gender", "Ů��");
        set("age", 55);
        set("long",
                "����һλ����������ţ���������΢΢һЦ��\n"
        );
        set("attitude", "friendly");

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 40);
        set("combat_exp", 150000);
        set("score", 0);

        set_skill("force", 80);
        set_skill("yunv-xinjing", 60);    
        set_skill("sword", 90);
        set_skill("yunv-jianfa", 80);     
        set_skill("dodge", 70);
        set_skill("yunv-shenfa", 70);   //��Ů��
        set_skill("parry", 60);
        set_skill("unarmed",80);
        set_skill("meinv-quanfa", 60);    //��Ůȭ��
        set_skill("literate",40);

        map_skill("force", "yunv-xinjing");
        map_skill("sword", "yunv-jianfa");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quanfa");
        map_skill("unarmed", "meinv-quanfa");

        create_family("��Ĺ��", 2, "����");
        set("inquiry", ([
                "С��Ů" :  "����������һ�ִ���ģ�����Сû�˸�ĸ�������ֶ�����ס�����Ĺ���..\n",
        ]) );

        set("env/wimpy", 50);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("clone/cloth/cloth")->wear();

}


