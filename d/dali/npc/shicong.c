// shicong.c

inherit NPC;

void create()
{
        set_name("�̴�", ({ "shi cong", "shi", "cong" }));
        set("age", 32);
        set("gender", "����");
        set("long", "��λ��Ҳ����������һ��̴򣬰ײ���ͷ������Ŀ��ȣ�һ˫
��׵Ĳ�Ь��������Ŀ������׼����ȥ�걸������һ��һ�ȵĴ�ᡣ\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("per", 20);
        set("dex", 16);
        set("combat_exp", 20000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 100);
        set_skill("parry", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        setup();
        carry_object(__DIR__"obj/lace")->wear();

}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
