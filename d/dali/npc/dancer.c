inherit NPC;
#include <ansi.h>
void create()
{
        set_name("������Ů", ({ "dancer" }) );
        set("gender", "Ů��" );
        set("title", HIY "ɴ������" NOR);
        set("age", 18);
        set("long",
                "һ��ɴ�����ʣ���Ұ�Ըе�������Ů\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 5);
        set("chat_msg", ({
"������Ů˫������İڶ��ţ�\n",
"������Ůȫ�����߰��Ť����������Ŀ�ⷢ����\n",
"������Ů�ڿն�����շ��˼�Ȧ����Ĩ��Ĩ��ߵĿ�ˮ��\n",
        }) );
        set_skill("unarmed",5);
        set_skill("yueying-wubu",5);
        set_skill("dodge",5);
        set_skill("liuyang-zhang",5);
        map_skill("dodge","yueying-wubu");        
        map_skill("unarmed","liuyang-zhang");
        setup();
        carry_object(__DIR__"obj/halfcloth")->wear();
}

/*
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
*/
