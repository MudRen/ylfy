// Room: gudi.c


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
����һ�����ﻨ���������Դ����ͷС¹�ڰ���ú����峺
��Ȫˮ������ɽ�գ������İ����������۵ظ質����ֻ�����ڻ�
���з�����ȥ���������ڣ����м�ֻ��������������ֵؿ�����
��λ����֮�ͣ�����һֻ���Գ��֨֨���ض���У��ǻ�ӭ�أ�
���������أ�����������������(teng)��
LONG

        );
set("objects",([
__DIR__"npc/baiyuan" : 1,
]));
        set("no_clean_up", 0);
        set("item_desc", ([
                "teng": "����һ����ɽ�١�\n"
                ]) );

        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me=this_player();

        if( !arg || arg=="" ) {write("��Ҫ��ʲô��\n");return 1;}
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");

        if( arg=="teng" ) {
                write("��ץ��ɽ�٣�Ŭ��������ȥ....\n");
if((int)me->query_skill("dodge",1)>=40)
                {write("��ѽ��ѽ����ѽ��ѽ��������������ɽ����\n");
                me->move(__DIR__"shandao1");                
                 return 1;}
                write(HIR"ͻȻ�䣬��һ�����⣬�͵�����ȥ��\n"NOR);

                me->add("jing",-40);
                me->add("qi",-40);
                me->improve_skill("dodge", random(100));
                me->unconcious();

                return 1;

                 }
}

