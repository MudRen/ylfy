inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���Ů", ({ "peijiunu" }) );
        set("gender", "Ů��" );
        set("title", HIG "������Ц" NOR);
        set("age", 18);
        set("long",
                "һ��������Ц�����Ů\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
"���Ů�䵽�����ԣ������𣬺ȣ�\n",
"���Ů�����еı̾Ƶ��������ϣ�Ȼ������ͷ����İ�����ɣ���\n",
        }) );
        set_skill("unarmed",5);
        set_skill("zhemei-shou",5);
        set_skill("dodge",5);
        set_skill("yueying-wubu",5);
        map_skill("dodge","yueying-wubu");        
        map_skill("unarmed","zhemei-shou");
        setup();
        carry_object(__DIR__"obj/halfcloth")->wear();
}

void init()
{
        ::init();
/*
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
*/
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
