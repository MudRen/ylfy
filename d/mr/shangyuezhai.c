#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short","����ի");
         set("long",@long
����ի��ΪĽ�ݼ�ÿ������֮ҹ������ġ����渻���ûʣ��Ϲ�Ӧ�о�
�У��Ա���Ѿ���ź��ţ�ÿ������֮ʱ��һ����С�����������£�����
�µ�ͬʱ��Ҳ��������˴����ʹ�������������ã������������һ
�����ȡ�
long);
         set("exits",([
                "west" : __DIR__"neitang",
                "east" : __DIR__"c15-2",
                "south" : __DIR__"c15-5",
        ]));
        setup();
}

void init()
{
        add_action("do_wudao", "wudao");  
}

int do_wudao(string arg)
{
        object me=this_player();
        object weapon = me->query_temp("weapon");

         if (!weapon || weapon->query("skill_type") != "blade" )
                return notify_fail("�������޵�����ô����\n");

        if ((int)me->query_skill("blade", 1) >100 )
        return notify_fail("���Ѿ��߾�ȫ��ȥ�����������ľ�Ҫ�������޷���������Ļ��������ˣ�\n");
    
        me->receive_damage("jing", random(40));
        write("�������һ�������������������һЩ�йػ��������ľ�Ҫ֮���ڡ�\n");
         me->improve_skill("blade", me->query("int"));       
         return 1;
}                                     
