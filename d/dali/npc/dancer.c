inherit NPC;
#include <ansi.h>
void create()
{
        set_name("妙龄少女", ({ "dancer" }) );
        set("gender", "女性" );
        set("title", HIY "纱衣朦胧" NOR);
        set("age", 18);
        set("long",
                "一个纱衣朦胧，狂野性感的妙龄舞女\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 5);
        set("chat_msg", ({
"妙龄少女双手轻柔的摆动着．\n",
"妙龄少女全身象蛇般的扭动，看得你目光发呆．\n",
"妙龄少女腾空而起，凌空翻了几圈，你抹了抹嘴边的口水．\n",
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
