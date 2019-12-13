// datusi.c

inherit NPC;

void create()
{
        set_name("����˾", ({ "da tusi", "tusi" }));
        set("age", 42);
        set("gender", "����");
        set("long", "����˾�ǰ��������ϣ��ǲ�ɽ����ϵ�ġ������ǳ��ķ�ͷ����ģ�
ÿ˵һ�仰��ÿ��һ����飬���������Ʊ����Ƕ�����Ĳ���һ����
�����Ųʳ�ͷ�����𣬽Ų���Ь��������Ų�ͬɫ�ʵı��ǡ�ֻ��
��������Ȼ�ظ߾��������������˿������\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("per", 18);
        set("dex", 36);
        set("combat_exp", 150000);
        set("shen_type", 1);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("force", 50);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);

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
