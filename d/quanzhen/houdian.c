// Room: houdian.c ���

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������ȫ��̵ĺ������й���ȫ��̴�����ʦ�����������񣬿�ǽ
���ż���̫ʦ�Σ����Ϸ��ż������ţ����󱲵���ߵ�ݡ�����������
�����ǵ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"disandian",
            "south" : __DIR__"sanqingdian",
            "west" : __DIR__"xilang3",
            "east" : __DIR__"donglang3",
            ]));
	
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}