// Room: jianyu.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ܲ�͸���ʯ�ң�����û���κ��Ŵ���ֻ��͸�����ŵ�С
�׵�һ˿΢���Ĺ��ߣ����߽���ĵ�������һЩ���ݣ����������˺۵�
���������������ʱ����һ����ʹ��ĵ�����

LONG
        );
set("objects",([
__DIR__"npc/yu-zu":1,
]));
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jyentrance",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

