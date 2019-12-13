// ding.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "ding chunqiu", "ding" }));
    set("nickname", HIR "�����Ϲ�" NOR);
    set("long", 
        "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
        "��������������ò���棬�ɷ���ǡ�\n");
    set("gender", "����");
    set("age", 60);
//    set("attitude", "friendly")
    set("shen_type", -1);
    set("str", 60);
    set("no_get", 1);	
    set("int", 70);
    set("con", 60);
    set("dex", 200);
    
    set("max_qi", 2234000);
    set("max_jing", 1333000);
    set("neili", 3500000);
    set("max_neili", 500000);
    set("jiali", 13000);
    set("combat_exp", 10380000);
	set("xyzx_sys/level", 1500);
    set("score", 400000);
	
    set_skill("force", 2400);
    set_skill("huagong-dafa", 1520);
    set_skill("dodge", 2400);
    set_skill("zhaixinggong", 1420);
    set_skill("unarmed", 2420);
    set_skill("chousui-zhang", 1450);
    set_skill("parry", 2450);
    set_skill("staff", 2470);
    set_skill("tianshan-zhang", 1465);
    set_skill("literate", 1200);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "chousui-zhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("������", 1, "��ɽ��ʦ");
    set("class", "taoist");
    setup();
        carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        add_action("do_flatter", "flatter");
}
void attempt_apprentice(object me)
{
        if ((int)me->query("betrayer")) {
                command("say ��Խ����Խ�������Ե׵ġ�");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}
int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲������ɷ�����������������㣿");
        }
        return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
// �������ɣ�������أ��������Ž��ޱ�
