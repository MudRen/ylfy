// xifang.c
#include <ansi.h>
inherit NPC;
void consider();
void create()
{
    set_name("����ʧ��", ({"xifang shibai", "xifang"}));
    set("nickname", HIY "�����޵�" NOR );
    set("gender", "Ů��");
    set("age", 42);
    set("long",
        "������������̽������ų����˿ɵУ������һ�ƺ�Ϊ������ʧ�ܡ���\n");
    set("attitude", "peaceful");
    set("str", 31);
    set("int", 10);
    set("con", 26);
    set("dex", 200);
    set("chat_chance", 1);
    set("chat_msg", ({
 "����ʧ��̾�˿����������� ���� �Ƕ���������˭ѽ�����Ƿ���������\n",
        }));
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("jingli", 1000);
    set("max_jingli", 1000);
    set("neili", 50000);
    set("max_neili", 5000);
    set("jiali", 20);
    set("combat_exp", 12500000);

    set_skill("force", 500);             // �����ڹ�
    set_skill("unarmed", 500);
    set_skill("throwing", 500);
    set_skill("mantianhuayu", 500);
    set_skill("tanzhi-shentong", 500);   // ��ָ��ͨ
    set_skill("dodge", 500);             // ��������
    set_skill("parry", 500);             // �����м�
    set_skill("sword", 500);             // ��������
    set_skill("pixie-jian", 450);        // PiXieJian
    set_skill("qimen-wuxing",400);       // ��������
    set_skill("literate",1000);           // ����ʶ��
    set_skill("kuihua-xinfa", 100);       // �����ķ�
    map_skill("force"  , "kuihua-xinfa");
    map_skill("throwing"  , "mantianhuayu");
    map_skill("sword", "pixie-jian");
    map_skill("unarmed" , "tanzhi-shentong");
    map_skill("dodge"  , "pixie-jian");
    map_skill("parry"  , "pixie-jian");
   set_temp("apply/shade_vision",1);
    create_family("�������", 2, "����");
    set("chat_msg_combat", ({
    (: exert_function, "protect" :),
    (: exert_function, "recover" :),
    }) );

    setup();
    carry_object(__DIR__"obj/zhen")->wield();
    carry_object(__DIR__"obj/kuihuazhen")->wield();
    carry_object(__DIR__"obj/hongchouxiaoshan")->wear();
}

