#include <room.h>
inherit ROOM;
#include "/clone/item/liuxing.h"
void create()
{
    set("short", "�һ�ɽׯǰԺ");
    set("long", @LONG
��������վ��һ������Ժ���С�Ժ��ԭ������Ϊ���䳡�õġ����Դ�
�һ������ӱ���ҩʦ������⣬���Ѿ�û���ڴ����䡣�����Ǳ����ң�
�����ǳ��������Ͼ����һ�ɽׯ�����ˡ�
LONG
);
    set("exits", ([
    "north" : __DIR__"damen",
    "south" : __DIR__"dating",
    "east"  : __DIR__"bingqi",
    "west"  : __DIR__"chufang",
]));
    set("outdoors", "taohua");
    setup();
    replace_program(ROOM);
}
